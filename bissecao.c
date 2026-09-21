#include <stdio.h>
#include <math.h>

double bissecao(double, double, int);
double f(double);

int main(){
    printf("%lf\n", powl(10, -3));
    bissecao(1, 2, 3);

    return 0;
}

double f(double x){
    return pow(x, 3) - x - 2;
}

double bissecao(double intervalo_a, double intervalo_b, int epsilon){
    double ponto_medio;
    double tolerance = pow(10, -epsilon);
    while (f(intervalo_a) * f(intervalo_b) < 0){
    
        ponto_medio = (intervalo_a + intervalo_b)/2;
        printf("DEBUG: ponto = %f, f(ponto) = %f, tolerancia = %f\n", ponto_medio, f(ponto_medio), tolerance);
        if(f(ponto_medio) == 0){
            printf("A raiz exata da funcao fica em: %f", ponto_medio);
            return 0;
        }

        if(f(intervalo_a) * f(ponto_medio) < 0){
            intervalo_b = ponto_medio;
        }else if(f(ponto_medio) * f(intervalo_b) <0){
            intervalo_a = ponto_medio;
        }
    }
    printf("Error");
}