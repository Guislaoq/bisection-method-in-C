#include <stdio.h>
#include "polinomio.h"

int main(){
    list* lista = create_list();
    extract_terms("5x^2-4x^5", lista);
    print_list(lista);
    return 0;
}