#include "1.h"

typedef struct mass {
    float mass;
} mass;

struct mass sum(struct mass* a, struct mass* b) {
    struct mass c = {a->mass + b->mass};
    return c;
}

void main()
{
    struct mass m = {2.3};
    struct mass n = {4};
    struct mass m2 = sum(&m, &n);
    printf("Sum is %f\n", m2.mass);
}