#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "polinomio.h"

struct Node{
    double coefficient;
    double exponent;
    struct Node* next;
};

typedef struct List{
    node* begin;
    int size;
}list;

list* create_list(){
    list* l = (list*) malloc(sizeof(list));
    l->begin = NULL;
    l->size = 0;
    return l;
}

bool list_append(list* l, double coeff, double expo){
    node* new_node = (node*) malloc(sizeof(node));
    if(new_node){
        new_node->coefficient = coeff;
        new_node->exponent = expo;
        new_node->next = NULL;
    }else{
        return false;
    }

    if(l->begin == NULL){
        l->begin = new_node;
    }else{
        node* current = l->begin;
        while(current->next != NULL){
            current = current->next;
        }

        current->next = new_node;
    }
    l->size++;
    return true;      
}

void print_list(list* l){
    if(l->begin != NULL){
        node* current = l->begin;
        while(current != NULL){
            printf("coefficient: %f\n exponent: %f\n", current->coefficient, current->exponent);
            current = current->next;
        }
    }
}

bool extract_terms(char* polynomial, list* l){
    int terms = 0;
    int j = 0;

    for(int i = 1; i < strlen(polynomial); i++){
        if(polynomial[i] == '-' || polynomial[i] == '+'){
            terms++;
        }
    }

    for(int i = 0; i < terms + 1; i++){
        bool is_negative = false;
        int coefficient = 1;
        int exponent = 1;

        if(polynomial[j] == '-' ){
            is_negative = true;
            j++;
        }else if(polynomial[j] == '+'){
            j++;
        }

        if(polynomial[j] >= '0' && polynomial[j] <= '9'){
            while(polynomial[j] >= '0' && polynomial[j] <= '9'){
                coefficient = polynomial[j] - 48;
                j++;
            }
        }
        
        if(polynomial[j] == 'x'){
            j++;
        }

        if(polynomial[j] == '^'){
            j++;
            while(polynomial[j] >= '0' && polynomial[j] <= '9'){
                exponent = polynomial[j] - 48;
                j++;
            }
        }

        if(is_negative)
            coefficient *= -1; 

        list_append(l, coefficient, exponent);

    }
}