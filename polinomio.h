#ifndef POLINOMIO_H
#define POLINOMIO_H

typedef struct Node node;

typedef struct List list;

list* create_list();

bool list_append(list*, double, double);

void print_list(list*);

bool extract_terms(char*, list*);

#endif