/*Escriba una solución al problema consistente en RETIRAR de una ListaEnlazada
Simple cuya cabeza es cab1, todos aquellos elementos que se encuentren en OTRA
lista cuya cabeza es cab2. Considere que ambas listas contienen únicamente datos
numéricosenteros en cada nodo.*/

#include <iostream>

struct Nodo1 {
    int numero;
    Nodo1 *siguiente;
} *cabeza1, *ultimo1,*borrar,*cabeza2, *ultimo2;


void agregar_nodo1(Nodo1 *p1);
void pedir_nodo1_usuario();
void pedir_nodo2_usuario();
void agregar_nodo2(Nodo1 *p2);

void mostrar_lista2();
void mostrar_lista1();
bool esta_repetido(int numero);
void borrarCabeza();
void borrarUltimo();
void borrarNodo(Nodo1 *borrar);
void borrarMitad(Nodo1 *borrar);
void copiarUnico();

int	main(int argc, char **argv)
{

    std::cout << "\n\nLlenar lista 1\n";
    for (int i = 0; i < 5; ++i) {
        pedir_nodo1_usuario();
    }
      std::cout << "\n\nLlenar lista 2\n";
    for (int i = 0; i < 5; ++i) {
        pedir_nodo2_usuario();
    }

    std::cout << "\nListas de numeros registrados" << std::endl;
    mostrar_lista1();
    mostrar_lista2();
    copiarUnico();
    std::cout << "\n\n\nLista actualizada";
    std::cout << "\n\nLista L1" << std::endl;
    mostrar_lista1();
    std::cout << "\nLista L2" << std::endl;
    mostrar_lista2();
    return 0;
}

void agregar_nodo1(Nodo1 *p1){

    p1->siguiente = NULL;
    
    if (cabeza1 == NULL) {
   
        cabeza1 = p1;
    }
    else  {
  
        ultimo1->siguiente = p1;
    }
    ultimo1 = p1;
}
void agregar_nodo2(Nodo1 *p2){

    p2->siguiente = NULL;
    
    if (cabeza2== NULL)
    {
        cabeza2 = p2;
    }
    else
    {
        ultimo2->siguiente = p2;
    }
    ultimo2 = p2;
}


void pedir_nodo1_usuario(){ 
 
    Nodo1 *p1 = new(struct Nodo1);

    if (p1 == NULL){
        std::cout << "No hay memoria en el sistema\n";
    }
    else{
        int numero;
        std::cout << "Ingrese un numero: ";
        std::cin >> numero;
        p1->numero = numero;
        agregar_nodo1(p1);
    }
}
void pedir_nodo2_usuario(){ 
 
    Nodo1 *p2 = new(struct Nodo1);

    if (p2 == NULL){
        std::cout << "No hay memoria en el sistema\n";
    }
    else{
        int numero;
        std::cout << "Ingrese un numero: ";
        std::cin >> numero;
        p2->numero = numero;
        agregar_nodo2(p2);
    }
}
void mostrar_lista1(){

    Nodo1 *recorrer1 = cabeza1;

    while (recorrer1 != NULL)
    {
        std::cout << recorrer1->numero << " -> ";
        recorrer1 = recorrer1->siguiente;
    }
    std::cout << "NULL\n";
}

void mostrar_lista2(){

    Nodo1 *recorrer2 = cabeza2;

    std::cout << "NULL <- ";
    while (recorrer2 != NULL)
    {
        std::cout << recorrer2->numero << " <-> ";
        recorrer2 = recorrer2->siguiente;
    }
    std::cout << "NULL\n";
}
void copiarUnico(){

    Nodo1 *recorrer1 = cabeza1;

    while (recorrer1 != NULL)
    {
        Nodo1 *siguiente = recorrer1->siguiente;

        if (esta_repetido(recorrer1->numero)==true){
        
            borrarNodo(recorrer1);
        }
        
        recorrer1 = siguiente;
    }
}
bool esta_repetido(int numero)
{
    Nodo1 *recorrer2 = cabeza2;
    
    while (recorrer2 != NULL)
    {
        if (recorrer2->numero == numero)
        {
            return true;
        }
        recorrer2 = recorrer2->siguiente;
    }

    return false;
}
void borrarNodo(Nodo1 *borrar)
{
    if (cabeza1 != NULL)
    {
        if (borrar == cabeza1)
        {
            borrarCabeza();
        }
        else if (borrar == ultimo1)
        {
            borrarUltimo();
        }
        else
        {
            borrarMitad(borrar);
        }
    }
    
}

void borrarCabeza()
{
    Nodo1 *nodoBorrar = cabeza1;
    cabeza1 = cabeza1->siguiente;
    delete(nodoBorrar);
}

void borrarUltimo()
{
    Nodo1 *recorrer1;


    recorrer1 = cabeza1;

    while(recorrer1->siguiente->siguiente != NULL)
    {
        recorrer1 = recorrer1->siguiente;
    }

    Nodo1 *nodoBorrar = ultimo1;
    ultimo1 = recorrer1;
    ultimo1->siguiente = NULL;
    nodoBorrar->siguiente = NULL;
    delete(nodoBorrar);
}

void borrarMitad(Nodo1 *borrar)
{
    Nodo1 *recorrer1;


    recorrer1 = cabeza1;

    while(recorrer1->siguiente->siguiente != NULL && recorrer1->siguiente-> numero != borrar->numero)
    {
        recorrer1 = recorrer1->siguiente;
    }

    if (recorrer1->siguiente->numero == borrar->numero)
    {
        Nodo1 *nodoBorrar = recorrer1->siguiente;
        recorrer1->siguiente = nodoBorrar->siguiente;
        nodoBorrar->siguiente = NULL;
        delete(nodoBorrar);
    }
}
