#include <iostream>


struct Nodo1 {
    int numero;
    Nodo1 *siguiente;
    Nodo1 *anterior;
} *cabeza1, *ultimo1,*cabeza2, *ultimo2;

void agregar_nodo1(Nodo1 *p1);
void pedir_nodo1_usuario();
void agregar_nodo2(Nodo1 *p2);

void mostrar_lista2();
void mostrar_lista1();
bool esta_repetido(int numero);

void borrarUltimo();
void borrarNodo();
void borrarMitad(Nodo1 *borrar);
void copiarUnico();

int	main(int argc, char **argv)
{

    std::cout << "\n\nLlenar lista doble\n";
    for (int i = 0; i < 10; ++i) {
        pedir_nodo1_usuario();
    }

    std::cout << "\nLista doble" << std::endl;
    mostrar_lista1();

    std::cout << "\n\n\nLista con los dos";
    std::cout << "\n\nLista doble" << std::endl;
    mostrar_lista1();
    std::cout << "\nLista pares" << std::endl;
    mostrar_lista2();
    return 0;
}

void agregar_nodo1(Nodo1 *p1)
{
    p1->siguiente = NULL;
    
    if (cabeza1 == NULL)
    {
        cabeza1 = p1;
    }
    else
    {
        ultimo1->siguiente = p1;
    }
    ultimo1 = p1;
}

void agregar_nodo2(Nodo1 *p2,int numero)
{ 
  if(esta_repetido(numero)==false){
  	 

 
      Nodo1 *q2=new(struct Nodo1);

      /*******BALANCEAR *********/
  
	 p2->siguiente=NULL;p2->anterior=NULL;
	 
      /*******INSERTO EL NODO ORDENADAMENTE A LA LISTA *********/ 
   
    	if(cabeza2==NULL){
			cabeza2=p2;	ultimo2 =p2;
		 	        
    	}else {
			  if(p2->numero<=cabeza2->numero){
			  	   p2->siguiente=cabeza2;cabeza2->anterior =p2; cabeza2=p2;
			  	    	
		    	}else{
				      if(p2->numero>=ultimo2 ->numero){
					      ultimo2 ->siguiente=p2;p2->anterior =ultimo2 ;ultimo2 =p2;
				       }else{
						   q2=cabeza2;
						   	   while(p2->numero>=q2->numero){
						   	   	  q2=q2->siguiente;
							    }
								  p2->anterior =q2->anterior ;
								  q2->anterior ->siguiente=p2;
								  p2->siguiente=q2;
								  q2->anterior =p2;
					   }
				}
	 		    
	    }
   }		 	 
}

void pedir_nodo1_usuario()
{  
   int res;
    Nodo1 *p1 = new(struct Nodo1);
    Nodo1 *p2 = new(struct Nodo1);

    if (p1 == NULL)
    {
        std::cout << "No hay memoria en el sistema\n";
    }
    else
    {
        int numero;
        std::cout << "Ingrese un numero: ";
        std::cin >> numero;
        p1->numero = numero;
        p2->numero = numero;
        agregar_nodo1(p1);
        res=numero%2;
        if(res==0){
          agregar_nodo2(p2,numero);	
		}
    }
}

void mostrar_lista1()
{
    Nodo1 *recorrer1 = cabeza1;

    while (recorrer1 != NULL)
    {
        std::cout << recorrer1->numero << " -> ";
        recorrer1 = recorrer1->siguiente;
    }
    std::cout << "NULL\n";
}

void mostrar_lista2()
{
    Nodo1 *recorrer2 = cabeza2;

    std::cout << "NULL <- ";
    while (recorrer2 != NULL)
    {
        std::cout << recorrer2->numero << " <-> ";
        recorrer2 = recorrer2->siguiente;
    }
    std::cout << "NULL\n";
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

