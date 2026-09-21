#include <stdio.h>
#include "polinomio.h"

int main(){
    list* lista = create_list();
    extract_terms("x^3-x-2", lista);
    print_list(lista);
    bisection(1, 2, 10, lista);
    return 0;
}