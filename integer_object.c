#include <stdio.h>
#include <stdlib.h>

// An example of OOP in C using a struct with function pointers to simulate methods

typedef struct Integer {
    int number;
    void (*increment)(struct Integer *self);
    void (*decrement)(struct Integer *self);
    void (*add)(struct Integer *self, int num);
    void (*minus)(struct Integer *self, int num);
    int (*get)(struct Integer *self);
} Integer;

void Integer_increment(Integer *self) {
    self->number++;
}

void Integer_decrement(Integer *self) {
    self->number--;
}

void Integer_add(Integer *self, int num) {
    self->number += num;
}

void Integer_minus(Integer *self, int num) {
    self->number -= num;
}

int Integer_get(Integer *self) {
    return self->number;
}


Integer *Integer_construct(int number) {
    Integer *self = malloc(sizeof(Integer));

    self->number = number;
    self->increment = &Integer_increment;
    self->decrement = &Integer_decrement;
    self->add = &Integer_add;
    self->minus = &Integer_minus;
    self->get = &Integer_get;

    return self;
}


int main(void) {
    Integer *i = Integer_construct(1);

    i->increment(i);
    i->add(i, 30);
    i->minus(i, 5);
    i->decrement(i);

    printf("%i\n", i->get(i));
}