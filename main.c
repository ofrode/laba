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
        printf("Task - (1 - 4)\nRead file - 5\nEnd - 0: ");
        task = check(0, 5);
        switch (task) {
            case 1:
                write_to_file(name);
                break;
            case 2:
                value = check(MIN, MAX);
                amount_value = finding_value(name, value);
                printf("%d\n", amount_value);
                break;
            case 3:
                value = check(MIN, MAX);
                number_replacement_by_the_maximum(name, value);
                break;
            case 4:
                sort(name);
                break;
            case 5:
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