#include "1.h"
#include "Task.h"

enum {
    MIN = INT_MIN,
    MAX = INT_MAX
};

int main() {
    char name[256];
    fgets(name, 256, stdin);
    name[strcspn(name, "\n")] = '\0';

    int task;
    int value;
    unsigned int amount;
    int amount_value;
    int number;
    while (1) {
        printf("Menu:\nTask 1 - 4:\nRead file 5\nEnd my mega super puper respect project");
        task = check(0, 5);
        switch (task) {
            case 1:
                puts("Task 1");
                write_to_file(name);
                puts("End task without errors");
                break;
            case 2:
                puts("Task 2");
                puts("Input value");
                value = check(MIN, MAX);
                amount_value = finding_value(name, value);
                printf("How many %d in file %d\n", value, amount_value);
                puts("End task without errors");
                break;
            case 3:
                puts("Task 3");
                puts("Input value");
                value = check(MIN, MAX);
                number_replacement_by_the_maximum(name, value);
                puts("End task without errors");
                break;
            case 4:
                puts("Task 4");
                sort(name);
                puts("End task without errors");
                break;
            case 5:
                puts("Read file");
                read_from_file(name);
                break;
            case 0:
                fclose(name);
                return 0;
            default:
                printf("Error\n");
        }
    }
}