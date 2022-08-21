#include <stdio.h>
#include <stdlib.h>

typedef struct Integer_Struct* Integer;

struct Integer_Struct{
    int number;
    void (*increment)(const void* self);
    void (*decrement)(const void* self);
    void (*add)(const void* self, int num);
    void (*minus)(const void* self, int num);
    int (*get)(const void* self);
};

void Integer_increment(const void* self) {
    ((Integer)self)->number++;
}

void Integer_decrement(const void* self) {
    ((Integer)self)->number--;
}

void Integer_add(const void* self, int num) {
    ((Integer)self)->number += num;
}

void Integer_minus(const void* self, int num) {
    ((Integer)self)->number -= num;
}

int Integer_get(const void* self) {
    return ((Integer)self)->number;
}

Integer Integer_construct(int number) {
    Integer self = (Integer)malloc(sizeof(struct Integer_Struct));

    self->number = number;
    self->increment = &Integer_increment;
    self->decrement = &Integer_decrement;
    self->add = &Integer_add;
    self->minus = &Integer_minus;
    self->get = &Integer_get;

    return self;
}


int main(void) {
    Integer i = Integer_construct(1);

    i->increment(i);
    i->add(i, 30);
    i->minus(i, 5);
    i->decrement(i);

    printf("%i\n", i->get(i));
    free(i);
}