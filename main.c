#include <stdio.h>
#include "bisection.h"

int main(){
    list* lista = create_list();
    char polynomial[100];
    double intervalo_a, intervalo_b;
    int n, epsilon;

    do{

        printf("\n|----------------MENU----------------|\n");
        printf("|1 - Utilizar o metodo da bissecao   |\n");
        printf("|2 - sair                            |\n");
        printf("|____________________________________|\n");
        printf("Selecione uma opcao:\n");
        scanf("%d", &n);

            switch (n)
        {
        case 1:

            printf("\nDigite a funcao continua f(x) sem espacos (ex: x^3-x-2 ou 2x^4+3x^2-1):\n");
            scanf("%s", polynomial);
            printf("\nInforme o intervalo a e b separado por espaco (ex: '1 2' ou  '5 10'):\n");
            scanf("%lf %lf", &intervalo_a, &intervalo_b);
            printf("\nInforma o epsilon:\n");
            scanf("%d", &epsilon);
            extract_terms(polynomial, lista);
            bisection(intervalo_a, intervalo_b, epsilon, lista);
            break;

        case 2:

            printf("Programa encerrado");
            break;

        default:
            break;
        }

    }while (n != 2);
    

    return 0;
}