#pragma once

#include "1.h"

int finding_value(FILE* file, int value)
{
    int num, count = 0;
    while (fread(&num, sizeof(int), 1, file)) {
        if (num == value) count++;
    }
    return count;
}

void number_replacement_by_the_maximum(FILE* file, int value)
{

    int num, max = INT_MIN;
    while (fread(&num, sizeof(int), 1, file)) {
        if (num > max) max = num;
    }

    rewind(file);
    while (fread(&num, sizeof(int), 1, file)) {
        if (num == value) {
            fseek(file, sizeof(int), SEEK_CUR);
            fwrite(&max, sizeof(int), 1, file);
        }
    }
}

void sort(FILE* file) {

    int num1, num2;
    int pos1, pos2;
    int swapped;

    do {
        swapped = 0;
        rewind(file);
        fread(&num1, sizeof(int), 1, file);
        pos1 = ftell(file);

        while (fread(&num2, sizeof(int), 1, file)) {
            pos2 = ftell(file);
            if (num1 % 2 != 0 && num2 % 2 != 0 && num1 < num2) {
                fseek(file, pos1 - sizeof(int), SEEK_SET);
                fwrite(&num2, sizeof(int), 1, file);
                fseek(file, pos2 - sizeof(int), SEEK_SET);
                fwrite(&num1, sizeof(int), 1, file);
                swapped = 1;
            }
            fseek(file, pos2 - sizeof(int), SEEK_SET);
            num1 = num2;
            pos1 = pos2;
        }
    } while (swapped);
}

void read_from_file(FILE* fp)
{
    rewind(fp);
    int num;
    while (fread(&num, sizeof(int), 1, fp)) {
        printf("%d ", num);
    }
    printf("\n");
}
