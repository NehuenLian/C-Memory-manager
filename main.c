#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "user_interaction/user_interaction.h"
#include "runtime_memory/manage_runtime_memory.h"
#include "data_manipulation/data_access.h"

// Memory startup if not exists
int startup_memory() {

    FILE *memory_file = fopen("memory.bin", "wb");
    if (!memory_file) {
        perror("Cannot open the file");
        return -1;
    }

    enum size {SIZE=16}; // 16 bytes
    // struct that will represent all memory structure
    typedef struct Memory {
        int *stored_ints;
        char *stored_chars;
    } Mem;

    // define 2 memory type structures
    Mem mem;
    mem.stored_ints = malloc(SIZE * 4);
    if (!mem.stored_ints) {
        printf("Couldn't assign memory for ints.\n");
        return -1;
    }

    mem.stored_chars = malloc(SIZE);
    if (!mem.stored_chars) {
        printf("Couldn't assign memory for chars.\n");
        return -1;
    }

    memset(mem.stored_ints, 0, SIZE * 4); 
    memset(mem.stored_chars, 'A', 16);

    // store bytes in the .bin file
    fwrite(mem.stored_ints, sizeof(int), 16, memory_file);
    fwrite(mem.stored_chars, sizeof(char), 16, memory_file);

    fclose(memory_file);

    free(mem.stored_ints);
    free(mem.stored_chars);
    mem.stored_ints = NULL;
    mem.stored_chars = NULL;

    return 0;
}
// ---------------------------------------


// Debugging
int read_binary() {
    FILE *memory_file = fopen("memory.bin", "rb");

    if (!memory_file) {
        perror("Cannot open the file");
        return -1;
    }

    unsigned char byte = 0;
    int bytes_count = 0;
    while(fread(&byte, 1, 1, memory_file) == 1) {
        printf("%d\n", byte);
        bytes_count++;
    }
    printf("Total bytes count: %d\n", bytes_count);
    fclose(memory_file);

    return 0;
}
// ---------------------------------------


int main() {

    FILE *memory_file = fopen("memory.bin", "r");

    if (!memory_file) {
        startup_memory();
    }
    fclose(memory_file);

    char task = define_task();
    char type = define_datatype();
    unsigned char *runtime_full_memory = load_into_memory();

    // separate full memory by type
    int *int_bytes = divide_int_memory(runtime_full_memory);
    unsigned char *char_bytes = divide_char_memory(runtime_full_memory);

    if (task == 'r' && type == 'i') {
        read_int(int_bytes);

    } else if (task == 'r' && type == 'c') {
        read_char(char_bytes);

    } else if (task == 'w' && type == 'i') {
        modify_int(int_bytes);
        update_memory(runtime_full_memory, int_bytes, char_bytes);
        
    } else if (task == 'w' && type == 'c') {
        modify_char(char_bytes);
        update_memory(runtime_full_memory, int_bytes, char_bytes);
    }
    free(int_bytes);
    free(char_bytes);

    return 0;
}
