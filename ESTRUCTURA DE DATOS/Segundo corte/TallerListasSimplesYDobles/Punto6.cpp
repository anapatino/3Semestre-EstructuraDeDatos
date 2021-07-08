#include <iostream>
#include<string.h>  
#include <conio.h>  

struct Nodo1 {
	int codigo;
    char accion[30];
    Nodo1 *siguiente;
} *cabeza1, *ultimo1,*borrar,*cabeza2, *ultimo2;


void agregar_nodo1(Nodo1 *p1);
void pedir_nodo1_usuario();
void pedir_nodo2_usuario();
void agregar_nodo2(Nodo1 *p2);

void mostrar_lista2();
void mostrar_lista1();
bool esta_repetido(char nombre[30]);
void borrarCabeza();
void borrarUltimo();
void borrarNodo(Nodo1 *borrar);
void borrarMitad(Nodo1 *borrar);
void copiarUnico();

int	main(int argc, char **argv)
{

    std::cout << "\n\nLlenar lista 1\n";
    for (int i = 0; i < 3; ++i) {
        pedir_nodo1_usuario();
    }
      std::cout << "\n\nLlenar lista 2\n";
    for (int i = 0; i < 3; ++i) {
        pedir_nodo2_usuario();
    }

    std::cout << "\nListas de datos registrados" << std::endl;
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
        char accion[30];
        std::cout << "Ingrese un accion: ";
         std::cin.getline(accion,30);
    
        strcpy(p1->accion,accion);
        
        agregar_nodo1(p1);
    }
}
void pedir_nodo2_usuario(){ 
 
    Nodo1 *p2 = new(struct Nodo1);

    if (p2 == NULL){
        std::cout << "No hay memoria en el sistema\n";
    }
    else{
        char accion[30];
        std::cout << "Ingrese un accion: ";
         std:: cin.getline(accion,30);
        strcpy(p2->accion,accion);
        agregar_nodo2(p2);
    }
}
void mostrar_lista1(){

    Nodo1 *recorrer1 = cabeza1;

    while (recorrer1 != NULL)
    {
        std::cout << recorrer1->accion<< " -> ";
        recorrer1 = recorrer1->siguiente;
    }
    std::cout << "NULL\n";
}

void mostrar_lista2(){

    Nodo1 *recorrer2 = cabeza2;

    while (recorrer2 != NULL)
    {
        std::cout << recorrer2->accion << " -> ";
        recorrer2 = recorrer2->siguiente;
    }
    std::cout << "NULL\n";
}
void copiarUnico(){

    Nodo1 *recorrer1 = cabeza1;

    while (recorrer1 != NULL)
    {
        Nodo1 *siguiente = recorrer1->siguiente;

        if (esta_repetido(recorrer1->accion)==true){
        
            borrarNodo(recorrer1);
        }
        
        recorrer1 = siguiente;
    }
}
bool esta_repetido(char nombre[30]){ 
int i,cont=0;
    Nodo1 *recorrer2 = cabeza2;
    
    while (recorrer2 != NULL)
    {
        for(int i=0;i<30;i++) {
           for(int i=0;i<30;i++) {
           switch (nombre[i]){
            case 'A':  cont++;
                       break;
            case 'R':  cont++;
                       break;
            case 'a':  cont++;
                       break;
			case 'r':  cont++;
                       break;		              
					              
		   }
          if(cont!=0)  {
          	return true;
		  }
       }
            
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

    while(recorrer1->siguiente->siguiente != NULL && recorrer1->siguiente-> accion!= borrar->accion)
    {
        recorrer1 = recorrer1->siguiente;
    }

    if (recorrer1->siguiente->accion== borrar->accion)
    {
        Nodo1 *nodoBorrar = recorrer1->siguiente;
        recorrer1->siguiente = nodoBorrar->siguiente;
        nodoBorrar->siguiente = NULL;
        delete(nodoBorrar);
    }
}
