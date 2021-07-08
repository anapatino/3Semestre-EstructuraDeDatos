#include <windows.h>                     
#include <iostream>                      
#include <conio.h>   
#include<string.h>                   
 using namespace std;
 
void AgregarNodo();
void RecorrerLista();
void ConsultarDato();
void BorrarDato();
  
 int gotoxy (USHORT x, USHORT y) {                                  
COORD cp = {x, y};                                                 
SetConsoleCursorPosition (GetStdHandle (STD_OUTPUT_HANDLE), cp);   
}

/********* DECLARANDO LA ESTRUCTURA********************/
struct Nodo{

 long CEDULA;
 char NOMBRE[40];
 Nodo * SIG;
};
/* Ahora declaramos las variables de tipo apuntador a esta estructura */
Nodo *p, *q, *cabeza,*FIN; 
 
 main(){
 	int SW;
 	char OP='S';
 	 while(OP=='S'){
 	  system("cls"); 	
      system("color 1F");
     
        gotoxy(49,4);cout << "M  E  N  U";
        gotoxy(40,6);cout <<"1.ADICIONAR ";
        gotoxy(40,7);cout <<"2.CONSULTA LISTADO ";
        gotoxy(40,8);cout <<"3.CONSULTA  POR  CEDULA ";
        gotoxy(40,9);cout <<"4.BORRAR  ";
        gotoxy(40,10);cout <<"5.SALIR ";

      do{
         gotoxy(43,12);cout << "SELECCIONE UNA ALTERNATIVA  ";cin >> SW;
      } while (( SW < 1 ) || ( SW > 5 ) ) ;
        cin.sync();
     
	   switch(SW){
    	case 1: AgregarNodo() ;
    	        break;
    	case 2: RecorrerLista();
    	        break; 
        case 3: ConsultarDato();
    	        break;
		case 4: BorrarDato();
    	        break;
		case 5: OP='N';
    	        break;				       
	   }
	
	  }
 }
 /*************AGREGAR DATOS********************/
 void AgregarNodo(){

 char Resp='S'	;
 	 while(Resp=='S'){
 	 	 p=new(struct Nodo);
 	 	 if(p==NULL){
 	 	 	gotoxy(25,20);cout<<"NO HAY MEMORIA DISPONIBLE";getch();
 	 	 	gotoxy(25,20);cout<<"                                     ";
		   }else {
		   	     system("cls"); 
		   	     gotoxy(45,6);cout<<"AGREGANDO DATOS AL NODO";
		   	     gotoxy(40,10);cout<<"Nro CEDULA : ";cin>>p->CEDULA;
		   	     cin.sync();
		   	     gotoxy(40,12);cout<<"NOMBRE EST : ";gets(p->NOMBRE);
		   	      cin.sync();
		   	     /**********AGREGAR NODO A LA LISTA CIRCULAR***/
		   	     
		   	     if(cabeza==NULL){
		   	     	cabeza=p; cabeza->SIG=cabeza;
		   	     	FIN=p;
					}else{
						FIN->SIG=p;
						p->SIG=cabeza;
						FIN=p;
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
  /*************RECORRESR LISTA********************/
  void RecorrerLista(){
  	int f;
  	if(cabeza==NULL){
  	   gotoxy(25,20);cout<<"NO HAY INFORMACION DE ESTUDIANTE EN LA LISTA";
  	   gotoxy(25,20);cout<<"                                                ";
	  }else{
	  	     system("cls"); 
	          p=cabeza;
	          f=12;
	          gotoxy(45,6);cout<<"LISTA DE ESTUDIANTES REGISTRADOS";
		   	  gotoxy(40,10);cout<<"Nro CEDULA                NOMBRE ESTUDIANTE";
	           do{
	          	gotoxy(42,f);cout<<p->CEDULA;
	          	gotoxy(67,f);cout<<p->NOMBRE;
	          	f++;
	          	p=p->SIG;
			 	} while(p!=cabeza);
	      	 gotoxy(38,20);cout<<"PULSE UNA TECLA PARA VOLVER AL MENU PRINCIPAL";getch();
	       }
  	
  	
  }
  
   /*************CONSULTAR DATO********************/
   void ConsultarDato(){
   	long dato;
   	char Encontro;
   	if(cabeza==NULL){
   		gotoxy(25,20);cout<<"NO HAY INFORMACION DE ESTUDIANTE EN LA LISTA";
  	    gotoxy(25,20);cout<<"                                                ";
	   }else{
	   	       system("cls");  
	  	     gotoxy(45,6); cout<<" C O N S U L T A R   D A T O ";
	  	     gotoxy(43,8);cout<<"IDENTIFICACION   :  "; cin>>dato;
	  	     p=cabeza; Encontro='N'; 
	  	     do{ 
	  	         
	  	     	if(p->CEDULA==dato){
	  	     		 Encontro='S';

				   }else{
				   	 p=p->SIG;
				   }
			   }while((Encontro!='S')&&(p!=cabeza));
	  	       if(Encontro=='S')   {
	  	       	    gotoxy(40,10);cout<<"Nro CEDULA                NOMBRE ESTUDIANTE";
	  	     	    gotoxy(42,12);cout<<p->CEDULA;
	  	     		gotoxy(68,12);cout<<p->NOMBRE;
	  	     		gotoxy(38,20);cout<<"PULSE UNA TECLA PARA VOLVER AL MENU PRINCIPAL";getch();
				 }else{
				 	 gotoxy(38,20);cout<<"NO SE ENCUENTRA REGISTRADO";getch();
				 }
	  	          
	  	          
	   }
   }
    /*************BORRAR DATO********************/
    void BorrarDato(){
    	long dato;
    	char Encontro;
    	
     if(cabeza==NULL)	{
     	gotoxy(25,20);cout<<"NO HAY INFORMACION DE ESTUDIANTE EN LA LISTA";
  	    gotoxy(25,20);cout<<"                                                ";
	 }else{
	   	     system("cls");  
	  	     gotoxy(45,6); cout<<"B O R R A R   D A T O ";
	  	     gotoxy(43,8);cout<<"IDENTIFICACION   :  "; cin>>dato;
	  	     p=cabeza; Encontro='N'; 
	  	      do{ 
	  	         
	  	     	if(p->CEDULA==dato){
	  	     		 Encontro='S';

				   }else{
				   	 p=p->SIG;
				   }
			   }while((Encontro!='S')&&(p!=cabeza));
			   
			   if(Encontro=='N'){
	  	       	    gotoxy(38,20);cout<<"NO SE ENCUENTRA REGISTRADO";getch(); 
				 }else{ 
				        gotoxy(40,10);cout<<"Nro CEDULA                NOMBRE ESTUDIANTE";
	  	     	        gotoxy(42,12);cout<<p->CEDULA;
	  	     		    gotoxy(68,12);cout<<p->NOMBRE;
	  	     		    gotoxy(50,16);cout<<"DATO ELIMINADO";
	  	     		    gotoxy(38,20);cout<<"PULSE UNA TECLA PARA VOLVER AL MENU PRINCIPAL";getch();
				 	   
				 	 
				 	/**************BORRAR EL NODO CORRECTAMENTE***/
				 	 if((cabeza->SIG==cabeza)&&(p==cabeza)){
				 	 	/***NODO UNICO****/
				 	 	delete(p);cabeza=NULL;
					  }else{
					  	  if((cabeza->SIG!=cabeza)&&(p==cabeza)){
					  	  	/********BORRAR EL PRIMERO,NO UNICO******/
					  	  	 cabeza=cabeza->SIG;FIN->SIG=cabeza;
					  	  	 delete(p);
							}else{
								if(p==FIN){/*******BORRAR EL ULTIMO*********/
								  q=cabeza;
								  while(q->SIG!=p){
								  	q=q->SIG;
								  }
								  q->SIG=cabeza; delete(p);FIN=q;
									
								}else{
									/*******BORRA UN CUALQUIERA DISTINTO AL PRIMERO Y AL ULTIMO****/
									q=cabeza;
									while(q->SIG!=p){
										q=q->SIG;
									}
									q->SIG=p->SIG;delete(p);
								}
							}
					  }
				 	
				 }
	  	     
	 }
	 
	}
	
   
   
   
