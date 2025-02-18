#pragma once

#include "1.h"

void write_to_file(const char *filename) {
    FILE *file = fopen(filename, "w+b");
    if (!file) {
        perror("Error");
        return;
    }

    printf("Press Enter on an empty line to finish:\n");

    while (1) {
        int num = check(INT_MIN, INT_MAX);
        if (num == INT_MIN) {
            break;
        }
        fwrite(&num, sizeof(int), 1, file);
    }

    fclose(file);
}

int finding_value(const char *filename, int value)
{
    FILE *file = fopen(filename, "rb");
    if (!file) {
        perror("Error");
        return 1;
    }
    rewind(file);
    int num, count = 0;
    while (fread(&num, sizeof(int), 1, file))
    {
        if (num == value)
        {
            count++;
        }
    }
    fclose(file);
    return count;
}

void number_replacement_by_the_maximum(const char *filename, int value)
{
    FILE *file = fopen(filename, "r+b");
    if (!file)
    {
        perror("Error");
        return;
    }
        rewind(file);
        int num, max = INT_MIN;

        while (fread(&num, sizeof(int), 1, file))
        {
            if (num > max)
            {
                max = num;
            }
        }

        rewind(file);
        long pos;
        while (fread(&num, sizeof(int), 1, file))
        {
            if (num == value)
            {
                pos = ftell(file) - sizeof(int);
                fseek(file, pos, SEEK_SET);
                fwrite(&max, sizeof(int), 1, file);
                fflush(file);
            }
        }
    fclose(file);
}

void sort(const char *filename) {
    FILE *file = fopen(filename, "r+b");
    if (!file) {
        perror("Error opening file");
        return;
    }

    fseek(file, 0, SEEK_END);
    long file_size = ftell(file);
    rewind(file);

    if (file_size == 0) {
        printf("File is empty.\n");
        fclose(file);
        return;
    }

    size_t num_elements = file_size / sizeof(int);

    for (size_t i = 0; i < num_elements; i++) {
        int current;
        fseek(file, i * sizeof(int), SEEK_SET);
        fread(&current, sizeof(int), 1, file);

        if (current % 2 == 1) {
            int max_odd = current;
            size_t max_index = i;

            for (size_t j = i + 1; j < num_elements; j++) {
                int next;
                fseek(file, j * sizeof(int), SEEK_SET);
                fread(&next, sizeof(int), 1, file);

                if (next % 2 == 1 && next > max_odd) {
                    max_odd = next;
                    max_index = j;
                }
            }

            if (max_index != i) {
                int temp;
                fseek(file, i * sizeof(int), SEEK_SET);
                fread(&temp, sizeof(int), 1, file);

                fseek(file, i * sizeof(int), SEEK_SET);
                fwrite(&max_odd, sizeof(int), 1, file);

                fseek(file, max_index * sizeof(int), SEEK_SET);
                fwrite(&temp, sizeof(int), 1, file);
            }
        }
    }

    fclose(file);

    printf("Sorting completed successfully.\n");
}

void read_from_file(const char *filename)
{
    FILE *file = fopen(filename, "rb");
    if (!file) {
        perror("Error");
        return;
    }
    int num;
    while (fread(&num, sizeof(int), 1, file))
    {
        printf("%d ", num);
    }
    printf("\n");
    fclose(file);
}
