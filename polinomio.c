#include <stdio.h>
#include <string.h>
int main(){
    
    int sinais = 0;
    char polinomio[]= "520x^2-4x^5";
    int j = 0;

    for(int i = 1; i < strlen(polinomio); i++){
        if(polinomio[i] == '-' || polinomio[i] == '+'){
            sinais++;
        }
    }

    for(int i = 0; i < sinais + 1; i++){
        bool is_negative = false;
        int coeficiente = 1;
        int expoente = 1;

        if(polinomio[j] == '-' ){
            is_negative = true;
            j++;
        }else if(polinomio[j] == '+'){
            j++;
        }

        if(polinomio[j] >= '0' && polinomio[j] <= '9'){
            while(polinomio[j] >= '0' && polinomio[j] <= '9'){
                coeficiente = polinomio[j] - 48;
                j++;
            }
        }
        
        if(polinomio[j] == 'x'){
            j++;
        }

        if(polinomio[j] == '^'){
            j++;
            while(polinomio[j] >= '0' && polinomio[j] <= '9'){
                expoente = polinomio[j] - 48;
                j++;
            }
        }

        if(is_negative)
            coeficiente *= -1;

        printf("coeficiente: %d\n", coeficiente);
        printf("expoente: %d\n", expoente);

    }


    return 0;
}