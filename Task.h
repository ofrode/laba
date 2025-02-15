#pragma once

#include "1.h"

void write_to_file(const char *filename) {
    FILE *file = fopen(filename, "w+b");
    if (!file) {
        perror("Error");
        return;
    }
    int num;
    printf("For end write -1):\n");
    while (scanf_s("%d", &num) && num != -1) {
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

void swap_numbers_in_file(FILE* file, int posA, int posB) {

    int numA, numB;

    fseek(file, posA * sizeof(int), SEEK_SET);
    fread(&numA, sizeof(int), 1, file);

    fseek(file, posB * sizeof(int), SEEK_SET);
    fread(&numB, sizeof(int), 1, file);

    fseek(file, posA * sizeof(int), SEEK_SET);
    fwrite(&numB, sizeof(int), 1, file);

    fseek(file, posB * sizeof(int), SEEK_SET);
    fwrite(&numA, sizeof(int), 1, file);

}

int get_file_size(FILE* file) {

    fseek(file, 0, SEEK_END);
    int size = ftell(file);
    rewind(file);
    return size;
}

void find_odd(FILE* file, int* a, int* b)
{
    int num;
    int pos = 0;

    while (fread(&num, sizeof(int), 1, file))
    {
        if (num % 2 != 0)
        {
            *a = num;
            *b = pos;
        }
        pos++;
    }
}



void sort(const char *filename) {
    FILE *file = fopen(filename, "r+b");
    if (!file) {
        perror("");
        return;
    }

    fseek(file, 0, SEEK_END);
    long file_size = ftell(file);
    rewind(file);

    if (file_size == 0) {
        printf("Error\n");
        fclose(file);
        return;
    }

    size_t num_elements = file_size / sizeof(int);

    for (size_t i = 0; i < num_elements; i++) {
        int min_odd = INT_MIN;
        size_t min_index = -1;


        for (size_t j = i; j < num_elements; j++) {
            int current;
            fseek(file, j * sizeof(int), SEEK_SET);
            fread(&current, sizeof(int), 1, file);

            if (current % 2 == 1 && current > min_odd) {
                min_odd = current;
                min_index = j;
            }
        }

        if (min_index != -1 && min_index != i) {
            int temp;
            fseek(file, i * sizeof(int), SEEK_SET);
            fread(&temp, sizeof(int), 1, file);

            if (temp % 2 == 1) {
                fseek(file, i * sizeof(int), SEEK_SET);
                fwrite(&min_odd, sizeof(int), 1, file);

                fseek(file, min_index * sizeof(int), SEEK_SET);
                fwrite(&temp, sizeof(int), 1, file);
            }
        }
    }
    fclose(file);
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
