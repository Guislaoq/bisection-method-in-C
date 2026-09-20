#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
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

void list_destroy(list* l){
    node* current = l->begin;
    node* next;

    while(current != NULL){
        next = current->next;
        free(current);
        current = next;
    }
}

void print_list(list* l){
    if(l->begin != NULL){
        printf("Number of terms in the polynomial: %d\n", l->size);
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
        list* coefficient_list = create_list();
        list* exponent_list = create_list();
        double coefficient = 1;
        double exponent = 1;

        if(polynomial[j] == '-' ){
            is_negative = true;
            j++;
        }else if(polynomial[j] == '+'){
            j++;
        }

        if(polynomial[j] >= '0' && polynomial[j] <= '9'){
            while(polynomial[j] >= '0' && polynomial[j] <= '9'){
                list_append(coefficient_list, polynomial[j] - 48, 0); 
                j++;
            }
        }
        
        if(polynomial[j] == 'x'){
            j++;
        }

        if(polynomial[j] == '^'){
            j++;
            while(polynomial[j] >= '0' && polynomial[j] <= '9'){
                list_append(exponent_list, 0, polynomial[j] - 48);
                j++;
            }
        }

        if(is_negative)
            coefficient *= -1; 

        if(coefficient_list != NULL){
            coefficient = 0;
            int max_exponente_10 = coefficient_list->size-1;
            node* current = coefficient_list->begin;
            while(current != NULL){
                coefficient += current->coefficient * pow(10, max_exponente_10);
                max_exponente_10--;
                current = current->next;
            }
        }

        if(exponent_list != NULL){
            exponent = 0;
            int max_exponente_10 = exponent_list->size-1;
            node* current = exponent_list->begin;
            while(current != NULL){
                exponent += current->exponent * pow(10, max_exponente_10);
                max_exponente_10--;
                current = current->next;
            }
        }

        list_append(l, coefficient, exponent);

    }
}