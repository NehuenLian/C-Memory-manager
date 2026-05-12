#include <stdio.h>

// Read data
void read_int(int *int_bytes) {
    size_t index = 0;

    printf("Select index you want to read for int:\n");
    scanf("%d", &index);

    if (index <= 15) {
        printf("Your data: %d.\n", int_bytes[index]);
    } else {
        printf("Out of index.\n");
    }
}

void read_char(unsigned char *char_bytes) {
    size_t index = 0;
    printf("Select index you want to read for char:\n");
    scanf("%d", &index);

    if (index <= 15) {
        printf("Your data: %d.\n", char_bytes[index]);
    } else {
        printf("Out of index.\n");
    }
}
// ---------------------------------------


// Modify data
void modify_int(int *int_bytes) {
    size_t index = 0;
    printf("Select index you want to modify for int:\n");
    scanf("%d", &index);

    if (index <= 15) {
        int new_value = 0;
        printf("Actual value: %d\n", int_bytes[index]);
        printf("Select new value:\n");
        scanf("%d", &new_value);
        int_bytes[index] = new_value;
    } else {
        printf("Out of index.\n");
    }
}

void modify_char(unsigned char *char_bytes) {
    size_t index = 0;
    printf("Select index you want to modify for char:\n");
    scanf("%d", &index);

    if (index <= 15) {
        int new_value = 0;
        printf("Actual value: %d\n", char_bytes[index]);
        printf("Select new value:\n");
        scanf("%d", &new_value);
        char_bytes[index] = new_value;
    } else {
        printf("Out of index.\n");
    }
}