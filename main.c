#include "1.h"
#include "Task.h"

enum{
    MIN = INT_MIN,
    MAX = INT_MAX
};

int main() {
    FILE *fp;
    char name[256];
    fgets(name, 256, stdin);
    name[strcspn(name, "\n")] = '\0';

    if ((fp = fopen(name, "w+b")) == NULL) {
        perror("Error");
        return 1;
    }

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
                amount = check(1, MAX);
                for (int i = 0; i < amount; i++) {
                    number = check(MIN, MAX);
                    fwrite(&number, sizeof(int), 1, fp);
                }
                break;
            case 2:
                value = check(MIN, MAX);
                amount_value = finding_value(fp, value);
                printf("%d\n", amount_value);
                break;
            case 3:
                value = check(MIN, MAX);
                number_replacement_by_the_maximum(fp, value);
                break;
            case 4:
                sort(fp);
                break;
            case 5:
                read_from_file(fp);
                break;
            case 0:
                fclose(fp);
                return 0;
            default:
                printf("Error\n");
        }
    }
}