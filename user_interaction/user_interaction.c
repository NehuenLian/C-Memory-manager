#include <stdio.h>

char define_task() {
    char choosed_task;    
    int flag = 1;

    while (flag == 1) {
        printf("Define the task type you want to do --\nw: Write\nr: Read.\n");
        scanf(" %c", &choosed_task);

        if (choosed_task == 'w' || choosed_task == 'r') {
            flag = 0;
        } else {
            printf("The task choosed doesn't exist.\n");
            flag = 1; // flag set to 1 again so the sentinel loop stills running
        }
    }

    return choosed_task;
}

char define_datatype() {
    char choosed_type = 0;
    int flag = 1;

    while (flag == 1) {
        printf("Define datatype you want to access --\ni: int\nc: char\n");
        scanf(" %c",  &choosed_type);

        if (choosed_type == 'i' || choosed_type == 'c') {
            flag = 0;
        } else {
            printf("The task choosed doesn't exist.\n");
            flag = 1; // flag set to 1 again so the sentinel loop stills running
        }
    }

    return choosed_type;
}