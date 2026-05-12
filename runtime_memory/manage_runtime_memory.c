#include <stdio.h>
#include <string.h>
#include <stdlib.h>

unsigned char* load_into_memory() {
    FILE *memory_file = fopen("memory.bin", "rb");

    if (!memory_file) {
        perror("Cannot open the file");
        return NULL;
    }
    static unsigned char runtime_full_memory[80];

    unsigned char current_byte = 0;
    int i = 0;

    while (fread(&current_byte, 1, 1, memory_file) == 1) {
        runtime_full_memory[i] = current_byte;
        i++;
    }
    fclose(memory_file);

    return runtime_full_memory;
}


int* divide_int_memory(unsigned char *runtime_full_memory) {
    int *int_data = malloc(64);
    if (!int_data) {
        return NULL;
    }
    memcpy(int_data, &runtime_full_memory[0], sizeof(int) * 16);
    
    return int_data;
}

unsigned char* divide_char_memory(unsigned char *runtime_full_memory) {
    unsigned char *char_data = malloc(16);
    if (!char_data) {
        return NULL;
    }
    memcpy(char_data, &runtime_full_memory[64], 16);

    return char_data;
}

int update_memory(unsigned char *runtime_full_memory, int *int_bytes, unsigned char *char_bytes) {
    printf("Updating memory...\n");
    FILE *memory_file = fopen("memory.bin", "wb");
    if (!memory_file) {
        perror("Cannot open the file");
        return 1;
    }

    memcpy(runtime_full_memory, &int_bytes[0], sizeof(int) * 16);
    memcpy(runtime_full_memory + 64, &char_bytes[64], 16); // start to copy from index 64, otherwhise it will overwrite from 0 to 15

    // runtime_full_memory size = 80 bytes.
    fwrite(runtime_full_memory, sizeof(char), 80, memory_file);
    fclose(memory_file);

    return 0;
}