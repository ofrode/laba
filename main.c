#include "Task.h"

enum {
    MIN = INT_MIN,
    MAX = INT_MAX
};

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    char *filename = argv[1];
    int task;
    int value;
    int amount_value;

    while (1) {
        printf("Menu:\nTask 1 - 4:\nRead file 5\nEnd my mega super puper respect project - 0: ");
        task = check(0, 5);
        switch (task)
        {
            case 1:
                puts("Task 1");
                write_to_file(filename);
                puts("End task without errors");
                break;
            case 2:
                puts("Task 2");
                puts("Input value");
                value = check(MIN, MAX);
                amount_value = finding_value(filename, value);
                printf("How many %d in file %d\n", value, amount_value);
                puts("End task without errors");
                break;
            case 3:
                puts("Task 3");
                puts("Input value");
                value = check(MIN, MAX);
                number_replacement_by_the_maximum(filename, value);
                puts("End task without errors");
                break;
            case 4:
                puts("Task 4");
                sort(filename);
                puts("End task without errors");
                break;
            case 5:
                puts("Read file");
                read_from_file(filename);
                break;
            case 0:
                return 0;
            default:
                puts("Error");
        }
    }
}