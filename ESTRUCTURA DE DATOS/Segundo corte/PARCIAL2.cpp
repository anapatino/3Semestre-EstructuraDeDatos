#include <iostream>
#include <conio.h>
#include <ctype.h>
#include <string.h>
#include <stdio.h>
#include <windows.h>   
                 
 using namespace std;
void PedirNodoUsuarioL1();
void AgregarNodo();
void RecorrerLista();
 void RecorrerLista2();
void BorrarVocal();
  
 int gotoxy (USHORT x, USHORT y) {                                  
COORD cp = {x, y};                                                 
SetConsoleCursorPosition (GetStdHandle (STD_OUTPUT_HANDLE), cp);   
}

/********* DECLARANDO LA ESTRUCTURA********************/

struct Nodo{

 char LETRA; 
 Nodo * SIG;
 Nodo * ANT;
} ;

/* Ahora declaramos las variables de tipo apuntador a esta estructura */
Nodo *p, *q, *cabeza,*FIN; 

struct Nodo2{

 char LETRA; 
 Nodo2 * SIG;
 Nodo2 * ANT;
} ;

Nodo2*p2, *q2, *cabeza2,*FIN2;

 
 main(){
 	int SW;
 	char OP='S';
 	 while(OP=='S'){
 	  system("cls"); 	
      system("color 1F");
     
        gotoxy(49,4);cout << "M  E  N  U";
        gotoxy(40,6);cout <<"1.ADICIONAR L1 ";
        gotoxy(40,7);cout <<"2.CONSULTAR LISTADO ";
        gotoxy(40,8);cout <<"3.BORRAR VOCALES EN L1";  
        gotoxy(40,9);cout <<"4.SALIR";  

      

      do{
         gotoxy(43,12);cout << "SELECCIONE UNA ALTERNATIVA  ";cin >> SW;
      } while (( SW < 1 ) || ( SW > 4 ) ) ;
        cin.sync();
     
	   switch(SW){
    	case 1: PedirNodoUsuarioL1();
    	        break;
    	case 2: RecorrerLista();
    	        break; 
        case 3:RecorrerLista2();
    	        break;
         case 4:OP='N';
    	        break;
					       
	   }
	
	  }
 }
 
  /*************AGREGAR DATOS LISTA DOBLE ********************/
 void PedirNodoUsuarioL1(){

 char Resp='S',letra	;
 	 while(Resp=='S'){
 	 	 Nodo2 *p2=new(struct Nodo2);
 	 	 if(p2==NULL){
 	 	 	gotoxy(25,20);cout<<"NO HAY MEMORIA DISPONIBLE";getch();
 	 	 	gotoxy(25,20);cout<<"                                     ";
		   }else {
		   	     system("cls"); 
		   	     gotoxy(45,6);cout<<"AGREGANDO DATOS LISTA 1";
		   	   
		   	     gotoxy(40,12);cout<<"LETRA : ";p2->LETRA=getche();
		   
		   	    
		   	     if(cabeza2==NULL){
		          cabeza2=p2; 
		          p2->ANT=cabeza2;
		          p2->SIG=cabeza2;
	            }else{
	            	p2->ANT=cabeza2->ANT;
	            	p2->ANT->SIG=p2;
	             	p2->SIG=cabeza2;
		            cabeza2->ANT=p2;
		           }

		   } 
		   do{
		    	gotoxy(25,20);cout<<"                                     ";
        	    gotoxy(43,20);cout<<"SEGUIR AGREGANDO   S/N ->"; 
			    Resp= getch();
                Resp = toupper(Resp);
		   }while((Resp!='S')&&(Resp!='N'));

 	
 }
  }
  /*************AGREGAR DATOS LISTA 1********************/
 void AgregarNodo(){
 	Nodo *p=new(struct Nodo);
      p->LETRA=p2->LETRA;
     if(cabeza==NULL){
		cabeza=p; 
		p->ANT=cabeza;
		p->SIG=cabeza;
	}else{
		p->ANT=cabeza->ANT;
		p->ANT->SIG=p;
		p->SIG=cabeza;
		cabeza->ANT=p;
		}
  }
 
  
  
/*************RECORRER LISTA CIRCULAR SIMPLE Y DOBLE ********************/
  void RecorrerLista(){
  p=cabeza; p2=cabeza2;
  	if(cabeza2==NULL){
  	   gotoxy(25,20);cout<<"NO HAY INFORMACION DE ESTUDIANTE EN LA LISTA";
  	   gotoxy(25,20);cout<<"                                                ";
	  }else{
	  	     system("cls"); 
	        
	          gotoxy(45,6);cout<<"LISTA CIRCULAR SIMPLE Y DOBLE ";
	
		   	  gotoxy(40,10);cout<<"LETRAS REGISTRADAS";
		   	   gotoxy(40,12);cout<<"L1 = ";
		
			 	do{
	          	   cout<<p2->LETRA;
	               cout<<"  ";
	             	p2=p2->SIG;
			 	} while(p2!=cabeza2);
			 	gotoxy(40,17);cout<<"L2 = ";
		   	if(p!=NULL){
	           do{
	               cout<<p->LETRA;
	               cout<<"  ";
	             	p=p->SIG;
			 	} while(p!=cabeza);
			   }		
			 	 
			
			
	       }
  	 gotoxy(38,20);cout<<"PULSE UNA TECLA PARA VOLVER AL MENU PRINCIPAL";getch();
  	
  }
  
  /*************RECORRER LISTA CIRCULAR SIMPLE Y DOBLE ********************/
  void RecorrerLista2(){

  	if(cabeza2==NULL){
  	   gotoxy(25,20);cout<<"NO HAY INFORMACION  EN LA LISTA";
  	   gotoxy(25,20);cout<<"                                                ";
	  }else{
	  	    
	         p2=cabeza2;
	
			 	do{

	               if((p2->LETRA=='A')||(p2->LETRA=='E')||(p2->LETRA=='I')||(p2->LETRA=='O')||(p2->LETRA=='U')||(p2->LETRA=='a')||(p2->LETRA=='e')||(p2->LETRA=='i')||(p2->LETRA=='o')||(p2->LETRA=='u')){
	               	 AgregarNodo();
	               	 BorrarVocal();
				    }
	             	p2=p2->SIG;
			 	} while(p2!=cabeza2);
			
	       }
  	 gotoxy(42,15);cout<<"BORRADO CON EXITO";getch();
  	
  }
    /*************BORRAR DATO*****************/
    void BorrarVocal(){
    	/**************BORRAR EL NODO CORRECTAMENTE***/
				 	 if((cabeza2->SIG==cabeza2)&&(p2==cabeza2)){
				 	 	//**NODO UNICO****/
				 	 
				 	 	delete(p2);
						  cabeza2=NULL;
					  }else{
					  	  if((cabeza2->SIG!=cabeza2)&&(p2==cabeza2)){
					  	  	//********BORRAR EL PRIMERO,NO UNICO******//
					  	  
					  	  	 cabeza2=cabeza2->SIG;
					  	  	  cabeza2->ANT=FIN2;
							 FIN2->SIG=cabeza2;
					  	  	 delete(p2);
								 p2=cabeza2;
							}else{
								if(p2==FIN2){/*/******BORRAR EL ULTIMO*********/
								  p2->ANT->SIG=cabeza2;
								   FIN2=FIN2->ANT;
								    cabeza2->ANT=FIN2; 
						         delete(p2);
						         
						        p2=cabeza2;
								}else{
									//*******BORRA UN CUALQUIERA DISTINTO AL PRIMERO Y AL ULTIMO****//
										p2->ANT->SIG=p2->SIG;
										 p2->SIG->ANT=p2->ANT;
						                delete(p2);
						                p2=cabeza2;
						
								}
							}
					  }
	} 
	

   
   
   
