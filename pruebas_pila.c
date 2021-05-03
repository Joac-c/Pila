#include "pila.h"
#include "testing.h"
#include "stdlib.h"
#include "stdio.h"

#define ITERACIONES 20


int valores[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23};

static void prueba_pila_vacia(void) {
    pila_t *pila = pila_crear();
    print_test("La pila se crea vacia", pila_esta_vacia(pila) == true );
    print_test("El tope de una pila vacia es nulo", pila_ver_tope(pila) == NULL);
    print_test("Borrar un elemento de la pila vacia devuelve NULL", pila_desapilar(pila) == NULL);
    pila_destruir(pila);
}


void apilar_varios(void* tda, bool funcion(pila_t*, void*), char* mensaje){
    int acciones = 2;
    bool seguimos = true;

    while (acciones < ITERACIONES && seguimos == true)
    {
        if(funcion(tda, &valores[acciones]) == true) acciones++;
        else seguimos = false;
    
    }
    print_test(mensaje,  (ITERACIONES == acciones));
    printf("Acciones totales = %d",  acciones);
    
}



void prueba_apilar_elementos(void){
    pila_t *pila = pila_crear();
    print_test("Apilo un elemento", pila_apilar(pila, &valores[0]) == true);
    print_test("El elemento apilado es el tope", pila_ver_tope(pila) == &valores[0]);
    print_test("Apilo otro elemento", pila_apilar(pila, &valores[1]) == true);
    print_test("El segundo elemento apilado es el tope", pila_ver_tope(pila) == &valores[1]);
    apilar_varios(pila, pila_apilar, "Se apilaron varios elementos exitosamente");
    pila_destruir(pila);

}

void desapilar_varios(void* tda, void* funcion(pila_t*), char* mensaje){
    int acciones = 2;
    bool seguimos = true;

    while (acciones < ITERACIONES - 1 && seguimos == true)
    {
        if(funcion(tda) == &valores[ITERACIONES - acciones]) acciones++;
        else seguimos = false;
    
    }
    print_test(mensaje,  (ITERACIONES -1  == acciones));
    printf("Acciones totales = %d",  acciones);
    
}

void prueba_desapilar_elementos(void){
    pila_t *pila = pila_crear();
    pila_apilar(pila, &valores[0]);
    pila_apilar(pila, &valores[1]);
    apilar_varios(pila, pila_apilar, "Se apilaron varios elementos exitosamente");
    print_test("Se desapilo un elemento exitosamente y el tope es correcto", pila_desapilar(pila) == &valores[ITERACIONES - 1]);
    desapilar_varios(pila, pila_desapilar, "se desapilan varios elementos y los topes son correctos");
    print_test("Se desapilo un elemento exitosamente y el tope es correcto", pila_desapilar(pila) == &valores[1]);
    apilar_varios(pila, pila_apilar, "Se apilaron varios elementos exitosamente");
    pila_destruir(pila);
}


void pruebas_pila_estudiante() {
    prueba_pila_vacia();
    prueba_apilar_elementos();
    prueba_desapilar_elementos();
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
