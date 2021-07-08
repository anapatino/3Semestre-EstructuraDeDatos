#include<iostream>
#include<conio.h>
#include <windows.h>   
using namespace std;
//Funciones
int Menu();
void Empilar();
void MostrarPila();
char Desempilar();
bool Pila_Vacia();
bool Pila_Llena();char letra;
///////Estructura//////
struct pila{
	char info;
	pila *siguiente;
}*p,*tope;

 int gotoxy (USHORT x, USHORT y) {                                  
COORD cp = {x, y};                                                 
SetConsoleCursorPosition (GetStdHandle (STD_OUTPUT_HANDLE), cp);   
}


int main(){
 	int SW;
 	char OP='S';
 	while(OP=='S'){
 		
 	SW=Menu();
    switch(SW){
    	case 1:Empilar();
    	        break;
    	case 2:MostrarPila();
    	        break;
		case 3:;
    	        break;	
		case 4:Desempilar();
    	        break;
		case 5:OP='N';
    	        break;					        
	}
	
   }
}
int Menu(){
	int SW;
	system("cls"); 	
    system("color 1F");
        gotoxy(35,2);cout << "IMPLEMENTACION DE PILAS EN ESTRUCTURA";
        gotoxy(49,4);cout << "M  E  N  U";
        gotoxy(40,6);cout <<"1.ADICIONAR NRO A LA PILA";
        gotoxy(40,7);cout <<"2.CONSULTAR PILA";
        gotoxy(40,8);cout <<"3.BUSCAR NRO EN LA PILA ";//no lo he terminado tiene errores
        gotoxy(40,9);cout <<"4.BORRAR NRO EN LA PILA";
        gotoxy(40,10);cout<<"5.SALIR ";

      do{
         gotoxy(43,12);cout << "SELECCIONE UNA ALTERNATIVA  ";cin >> SW;
      } while (( SW < 1 ) || ( SW > 5 ) ) ;
      return SW;
}

void Empilar(){
	char rpt;
	pila *p = new(struct pila);
	pila *tope = new(struct pila);
	if(Pila_Llena()==true){
		cout<<"Stack Overflow";
	}else{
		  do{
		          system("cls"); 
		          gotoxy(49,4);cout <<"ADICIONAR CARACTERES EN LA PILA";
		          gotoxy(49,6);cout<<"INGRESE UN CARACTER->  ";
	           if(Pila_Vacia()==true){
	             	p->info=getche();
	             	p->siguiente=NULL;
			      
	        	}else{

			       pila *aux = new(struct pila);
			       aux->info=getche();
			       aux->siguiente=p;
			       p=aux;
			      
		        }
		        gotoxy(40,20);cout<<"Desea seguir ingresando Nro a la Pila (S/N)  ";
		        rpt=getch(); 
		      
		    }while((rpt == 's')||(rpt=='S'));
		
	}
}

bool Pila_Vacia(){
	if(tope==NULL){
		return true;
	}else{
		return false;
	}
}

bool Pila_Llena(){
   pila *p = new(struct pila);
	if(p!=NULL){
		return false;
	}else{
		return true;
	}
}

 void MostrarPila(){
 	pila *aux = new(struct pila);
	if(p ==NULL){
		cout<<"No Hay Datos";
	}else{
		aux=p;
		system("cls"); 
		gotoxy(45,4);cout <<"MOSTRAR NUMEROS EN LA PILA";
	    gotoxy(42,10);cout<<"PILA-> ";
		while(aux!=NULL){
		   
			cout<<aux->info<<"  ";
			aux=aux->siguiente;
		}
		getch();
	}
}

char Desempilar(){
	if(Pila_Vacia()==true){
		cout<<"Stack Underflow";
		
	}else{
		letra=tope->info;
		p=tope;
		tope=tope->siguiente;
		delete(p);
	}
	return letra;
	
		
}
