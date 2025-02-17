#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <math.h>
#include <time.h>
#include <malloc.h>
#include <limits.h>
#include <locale.h>
#include <string.h>

int p_1(char *input)
{
    if (input[0] == '-') {
        for (int i = 1; input[i] != '\n'; i++)
        {
            if (input[i] < '0' || input[i] > '9')
            {
                return 0;
            }
        }
    }
    else {
        for (int i = 0; input[i] != '\n'; i++)
        {
            if (input[i] < '0' || input[i] > '9')
            {
                return 0;
            }
        }
    }
    return 1;
}

int p_2(char* input, int* integer)
{
    int temp;
    if (p_1(input) && sscanf_s(input, "%d", &temp) == 1)
    {
        *integer = temp;
        return 1;
    }
    else
    {
        return 0;
    }
}

int p() {
    char in[20];
    int Int = 0;
    while (1) {

        fgets(in, sizeof(in), stdin);

        if (p_2(in, &Int) == 1) {

            break;
        }
        else
        {
            printf("\n");
        }

    }
    return Int;
}

int check(int a, int b) {
    int c;
    while (1) {
        c = p();
        if (c >= INT_MIN && c <= INT_MAX) {
            if (c >= a && c <= b) {
                break;
            }
            else {
                printf("\n");
            }
        }
        else
        {
            printf("\n");
        }
    }
    return c;
}
