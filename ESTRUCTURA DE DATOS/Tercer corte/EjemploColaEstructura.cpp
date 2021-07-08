#include<iostream>
#include<conio.h>
#include <windows.h>   
#include <cstdlib>
using namespace std;

 int gotoxy (USHORT x, USHORT y) {                                  
COORD cp = {x, y};                                                 
SetConsoleCursorPosition (GetStdHandle (STD_OUTPUT_HANDLE), cp);   
}
//Declaramos estructura
struct COLA{
	int Id;
	Time H_llega;
	COLA *siguiente;
	COLA *anterior;
}*p,*frente,*fin,*q;

//Prototipos de Función
bool Cola_llena();
bool Cola_vacia();
int Menu();


int main(){
 	int SW;
 	char OP='S';
 	while(OP=='S'){
 		
 	SW=Menu();
    switch(SW){
    	case 1:
    	        break;
    	case 2:
    	        break;
		case 3:
    	        break;	
		case 4:
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
        gotoxy(35,2);cout << "IMPLEMENTACION DE COLAS CON PUNTEROS";
        gotoxy(49,4);cout << "M  E  N  U";
        gotoxy(40,6);cout <<"1.ADICIONAR A LA COLA";
        gotoxy(40,7);cout <<"2.CONSULTAR COLA";
        //gotoxy(40,8);cout <<"3.BUSCAR NRO EN LA COLA ";no lo he terminado tiene errores
        gotoxy(40,8);cout <<"3.BORRAR COLA";
        gotoxy(40,10);cout<<"4.SALIR ";

      do{
         gotoxy(43,12);cout << "SELECCIONE UNA ALTERNATIVA  ";cin >> SW;
      } while (( SW < 1 ) || ( SW > 4 ) ) ;
      return SW;
}

////////COLA LLENA///////
bool Cola_llena(){
	COLA *p= new COLA();
  if(p==NULL)	{
  	 return true;
  }else{
  	 return false;
  }
}
////////COLA VACIA//////
bool Cola_vacia(){
	COLA *frente= new COLA();
  if(frente==NULL)	{
  	 return true;
  }else{
  	 return false;
  }
}
////LLENAR COLA///////
MeterEnLaCola(){
	int NCLL,x;
	bool Encontro;
	if(Cola_llena()==true){
		cout<<"No mas Clientes";
	}else{
		COLA *q= new COLA();
		COLA *cabeza= new COLA();
		q=NULL;
		do{
			
			x=rand(30);
			if(q==NULL){
				q=x;
				cabeza=q;
			}else{
				if(q==cabeza){
					Encontro=true;
				}else{
			     	while(q!=cabeza){
					    if(x==q->Id){
					    	Encontro=true;
					    }else{
					        Encontro=false;	
					     }
				      q=q->siguiente;	
			     	}
				}
			}
			
		}while(Encontro==false);
		p->Id=x; 
		p->H_llega=;
		p->siguiente=NULL;
		p->anterior=NULL;
		if(Cola_vacia()==true){
			frente=p;NCLL++;
		}else{
			/////v despues del  ultimo////
			NCLL++;
		}
	}
}

////VACIAR LA COLA/////









