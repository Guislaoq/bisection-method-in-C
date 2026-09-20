#include <stdio.h>
#include "polinomio.h"

int main(){
    list* lista = create_list();
    extract_terms("520x^2-x^52", lista);
    print_list(lista);
    return 0;
}