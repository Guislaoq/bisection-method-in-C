#include <stdio.h>
#include "bisection.h"

int main(){
    list* lista = create_list();
    char polynomial[100];
    double intervalo_a, intervalo_b;
    int n, epsilon;

    printf("Selecione uma opçao:\n");
    printf("1 - Utilizar o método da bisseçao\n");
    printf("2 - sair \n");
    scanf("%d", &n);

    switch (n)
    {
    case 1:
        printf("Escreva a função:\n");
        scanf("%s", polynomial);
        printf("Informe o intervalo a:\n");
        scanf("%lf", &intervalo_a);
        printf("Informe o intervalo b:\n");
        scanf("%lf", &intervalo_b);
        printf("Informa o epsilon:\n");
        scanf("%d", &epsilon);

        //extract_terms(polynomial, lista);
        //bisection(intervalo_a, intervalo_b, epsilon, lista);
        break;
    case 2:

        break;
    default:
        break;
    }



    extract_terms(polynomial, lista);
    print_list(lista);
    bisection(intervalo_a, intervalo_b, epsilon, lista);
    return 0;
}