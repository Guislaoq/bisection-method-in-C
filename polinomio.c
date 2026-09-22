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
        double exponent = 0;

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
            exponent = 1;
            j++;
        }

        if(polynomial[j] == '^'){
            j++;
            while(polynomial[j] >= '0' && polynomial[j] <= '9'){
                list_append(exponent_list, 0, polynomial[j] - 48);
                j++;
            }
        } 

        if(coefficient_list->begin != NULL){
            coefficient = 0;
            int max_exponente_10 = coefficient_list->size-1;
            node* current = coefficient_list->begin;
            while(current != NULL){
                coefficient += current->coefficient * pow(10, max_exponente_10);
                max_exponente_10--;
                current = current->next;
            }
            list_destroy(coefficient_list);
        }
            

        if(exponent_list->begin != NULL){
            exponent = 0;
            int max_exponente_10 = exponent_list->size-1;
            node* current = exponent_list->begin;
            while(current != NULL){
                exponent += current->exponent * pow(10, max_exponente_10);
                max_exponente_10--;
                current = current->next;
            }
            list_destroy(exponent_list);
        }

        if(is_negative)
            coefficient *= -1;

        list_append(l, coefficient, exponent);

        }

}

double continuous_function(list* polynomial, double x){
    double result = 0;
    node* current = polynomial->begin;
    while(current != NULL){
        result += current->coefficient * pow(x, current->exponent);
        current = current->next;
    }
    free(current);
    return result; 
}

double bisection(double intervalo_a, double intervalo_b, int epsilon, list* polynomial){
    double ponto_medio;
    double tolerance = pow(10, -epsilon);
    while (1){
    
        ponto_medio = (intervalo_a + intervalo_b)/2;
        printf("DEBUG: ponto = %.15lf, f(ponto) = %.15lf, tolerancia = %.15lf\n", ponto_medio, continuous_function(polynomial, ponto_medio), tolerance);
        if(fabs(continuous_function(polynomial, ponto_medio)) < tolerance){
            if(continuous_function(polynomial, ponto_medio) == 0){
                printf("A raiz exata da funcao fica em: %.15lf", ponto_medio);
                return 0;
            }
            printf("A raiz aproximada eh: %15.lf", ponto_medio);
            return 0;
        }

        if(continuous_function(polynomial, intervalo_a) * continuous_function(polynomial, ponto_medio) < 0){
            intervalo_b = ponto_medio;
        }else if(continuous_function(polynomial, ponto_medio) * continuous_function(polynomial, intervalo_b) <0){
            intervalo_a = ponto_medio;
        }
    }
    printf("Error");
}
    
