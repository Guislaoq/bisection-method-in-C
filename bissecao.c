#include <stdio.h>
#include <math.h>

double bissecao(double, double);
double f(double);

int main(){

    bissecao(1, 2);

    return 0;
}

double f(double x){
    return pow(x, 3) - x - 2;
}

double bissecao(double intervalo_a, double intervalo_b){
    double ponto_medio;
    while (f(intervalo_a) * f(intervalo_b) < 0){
    
        ponto_medio = (intervalo_a + intervalo_b)/2;
        if(f(ponto_medio) == 0){
            printf("A raiz exata da funcao fica em: %lf", ponto_medio);
            return 0;
        }

        if(f(intervalo_a) * f(ponto_medio) < 0){
            intervalo_a = intervalo_a;
            intervalo_b = ponto_medio;
        }else if(f(ponto_medio) * f(intervalo_b) <0){
            intervalo_a = ponto_medio;
            intervalo_b = intervalo_b;
        }
    }
    printf("Error");
}