#include<iostream>
#include<conio.h>
#include <windows.h>   
using namespace std;
//Funciones
int Menu();
bool PilaLlena();
void Empilar ();
void MostrarPila();
bool PilaVacia();
void Desempilar();
void BuscarNPila();
int PILA[20],TOPE;

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
		case 3:BuscarNPila();
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
        gotoxy(35,2);cout << "IMPLEMENTACION DE PILAS EN VECTORES";
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

////////////EMPILAR///////////////////

void Empilar (){
	char res;
	int dato;
 	  if(PilaLlena()==true){
 		cout<<"Stack Overflow";
 		
	   }else{
	       
	   	     do{  
				   	system("cls"); 
				   	gotoxy(49,4);cout <<"ADICIONAR NUMEROS EN LA PILA";
         	      	gotoxy(49,6);cout<<"INGRESE NRO->  ";cin>>dato;
          	        TOPE++;
	   	            PILA[TOPE]=dato;
    	            gotoxy(40,20);cout<<"Desea seguir ingresando Nro a la Pila (S/N)  ";res=getch();
	            }while((res=='S')||(res=='s'));
	   	     gotoxy(38,20);cout<<"PULSE UNA TECLA PARA VOLVER AL MENU PRINCIPAL";getch();
	        }
	 
 }
 
 ////////FUNCION PARA MOSTRAR PILA//////
  void MostrarPila(){
 	if(PilaVacia()==true){
 		gotoxy(42,10);cout<<"PILA VACIA";
 		
	 }else{
	 	    system("cls"); 	
	       	gotoxy(45,4);cout <<"MOSTRAR NUMEROS EN LA PILA";
	       	gotoxy(42,10);cout<<"PILA-> ";
	 	     for(int i=TOPE;i>0;i--){
	 	      	 cout<<PILA[i]<<"  ";
		       }
	   gotoxy(38,20);cout<<"PULSE UNA TECLA PARA VOLVER AL MENU PRINCIPAL";getch();
	 }
 }
 ////////FUNCION PARA BUSCAR NUMERO EN UNA PILA//////
  void BuscarNPila(){
  	int num,pos;
  	char Encontro;
 	if(PilaVacia()==true){
 		gotoxy(42,10);cout<<"PILA VACIA";
 		
	 }else{
	 	    system("cls"); 	
	       	gotoxy(45,4);cout <<"BUSCAR NUMERO EN LA PILA";
	       	gotoxy(42,8);cout<<"NUMERO QUE DESEA BUSCAR-> ";cin>>num;
	 	     for(int i=TOPE;i>0;i--){
	 	      	 if(PILA[i]==num){
	 	      	    	Encontro='S';
			    	}else{
			    		Encontro='N';
					}
			    	
		       }
		    if(Encontro=='S')   {
		    	gotoxy(42,10);cout<<"NUMERO  "<<num<<"  ENCONTRADO  ";	
			}else{
				gotoxy(42,10);cout<<"NO FUE ENCONTRADO EN LA PILA";
			}
		       
	   gotoxy(38,20);cout<<"PULSE UNA TECLA PARA VOLVER AL MENU PRINCIPAL";getch();
	 }
 }
 
 
///////FUNCION PARA DESEMPILAR///////
void Desempilar(){
	int num=0;
	char res;
 	if(PilaVacia()==true){
 		cout<<"Stack underflow";
	 }else{
	 	    system("cls"); 	
	       	gotoxy(40,4);cout <<"DESEMPILAR NUMEROS EN LA PILA";
	 	  do{ 
	 	        gotoxy(40,12);cout<<"                                              ";
				gotoxy(49,6);cout<<"                                   ";
	 	        num=PILA[TOPE];
	 	        TOPE--;
		        gotoxy(45,8);cout<<"Nro Desempilado-> "<<num;
         	    gotoxy(40,14);cout<<"Desea sacar otro un Nro de la Pila (S/N) ";res=getch();
         	}while((res=='S')||(res=='s'));
	  gotoxy(38,20);cout<<"PULSE UNA TECLA PARA VOLVER AL MENU PRINCIPAL";getch();
	 }
 }
 
 //////////////VALIDACIONES////////////
 bool PilaLlena(){
 	if(TOPE<20){
 		return false;
	 }else{
	 	return true;
	 }
 }
 
  bool PilaVacia(){
 	if (TOPE==0){
 		return true;
	 }else{
	 	return false;
	 }
 }
