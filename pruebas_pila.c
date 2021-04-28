#include "pila.h"
#include "testing.h"
#include "stdlib.h"

#define ITERACIONES 20


const int* valores = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23};

static void prueba_pila_vacia(void) {
    pila_t *pila = pila_crear();
    print_test("La pila se crea vacia", pila_esta_vacia(pila) == true );
    print_test("El tope de una pila vacia es nulo", pila_ver_tope(pila) == NULL);
    print_test("Borrar un elemento de la pila vacia devuelve NULL", pila_desapilar(pila) == NULL);
    pila_destruir(pila);
}


void iterador_prueba_verdadera(void* tda, void* funcion(void*), char* accion){
    int acciones = 0;
    bool seguimos = true;
    while (acciones < ITERACIONES && seguimos == true)
    {
        if(*(unsigned char*)funcion(tda) == true) acciones++;
        else seguimos = false;
    
    }
    print_test(("Se %s todos los elementos", accion),  (ITERACIONES  == acciones));
    printf(("se %s elementos\n\n", accion),  acciones);

}



void prueba_apilar_elementos(void){
    pila_t *pila = pila_crear();
    print_test("Apilo un elemento", pila_apilar(pila, valores[0]) == true);
    iterador_prueba_verdadera(pila, pila_apilar, "apilaron");

}


void pruebas_pila_estudiante() {
    prueba_pila_vacia();
    // ...
}


/*
 * Función main() que llama a la función de pruebas.
 */

#ifndef CORRECTOR  // Para que no dé conflicto con el main() del corrector.

int main(void) {
    pruebas_pila_estudiante();
    return failure_count() > 0;  // Indica si falló alguna prueba.
}

#endif
