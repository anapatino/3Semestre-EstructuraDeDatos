#include<iostream>
#include<conio.h>
#include <windows.h>   
using namespace std;

 int gotoxy (USHORT x, USHORT y) {                                  
COORD cp = {x, y};                                                 
SetConsoleCursorPosition (GetStdHandle (STD_OUTPUT_HANDLE), cp);   
}
//Declaramos estructura
struct Nodo{
	int dato;
	Nodo *siguiente;
}*p,*cabeza;

//Prototipos de Función
void agregarPila(); 
void sacarPila();
int Menu();
void Sacar(Nodo *&p,int &dato);

int main(){
	int SW;
 	char OP='S';
 	while(OP=='S'){
 		
 	SW=Menu();
    switch(SW){
    	case 1:agregarPila();
    	        break;
    	case 2:sacarPila();
    	        break;
		case 3:OP='N';
    	        break;					        
	}
	
   }
}

int Menu(){
	int SW;
	system("cls"); 	
    system("color 1F");
        gotoxy(35,2);cout << "IMPLEMENTACION DE PILAS CON ESTRUCTURAS";
        gotoxy(49,4);cout << "M  E  N  U";
        gotoxy(40,6);cout <<"1.ADICIONAR NRO A LA PILA";
        gotoxy(40,7);cout <<"2.CONSULTAR PILA";
        //gotoxy(40,8);cout <<"3.BORRAR NRO EN LA PILA";
        gotoxy(40,8);cout<<"3.SALIR ";

      do{
         gotoxy(43,12);cout << "SELECCIONE UNA ALTERNATIVA  ";cin >> SW;
      } while (( SW < 1 ) || ( SW > 3 ) ) ;
      return SW;
}

////FUNCION PARA AGREGAR NRO A LA PILA/////

void agregarPila(){
	char rpt;	
	    Nodo *p= new Nodo();
		do{ //Pedimos todos los elementos de la pila
		  	system("cls"); 
			gotoxy(49,4);cout <<"ADICIONAR NUMEROS EN LA PILA";
		   gotoxy(49,6);cout<<"INGRESE NRO->  ";cin>> p->dato;
	       p->siguiente = cabeza;
	       cabeza=p;
		   gotoxy(40,20);cout<<"Desea seguir ingresando Nro a la Pila (S/N)  ";
		   rpt=getch();
	}while((rpt == 's')||(rpt=='S'));

}

/////FUNCION PARA MOSTRAR LA PILA////

void sacarPila(){
	
	system("cls"); 	
	int dato;
	gotoxy(45,4);cout <<"MOSTRAR NUMEROS EN LA PILA";
	gotoxy(42,10);cout<<"PILA-> ";
	while(p != NULL){
		Sacar(p,dato);

		if(p!= NULL){
			cout<<dato<<" , ";
		}
		else{
			cout<<dato<<".";
		}
	}
	
	
}

void Sacar(Nodo *&p,int &n){
	Nodo*aux=p;
	n=aux->dato;
	p=aux->siguiente;
	delete aux;
	
}

