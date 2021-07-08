#include <windows.h>                     
#include <iostream>                      
#include <conio.h>   
#include<string.h>  
                
 using namespace std;
 
 int gotoxy (USHORT x, USHORT y) {                                  
COORD cp = {x, y};                                                 
SetConsoleCursorPosition (GetStdHandle (STD_OUTPUT_HANDLE), cp);   
}

/********* DECLARANDO LA ESTRUCTURA********************/
struct Nodo1{

 char NOM[40]; 
 Nodo1 * SIG;
 Nodo1 * ANT;
} *cabeza,*FIN,*p;

struct Nodo2{

 char NOM[40]; 
 Nodo2 * SIG;
 Nodo2 * ANT;
} *cabeza2,*FIN2,*p2;


void PedirNodoUsuarioL1();
void Agregar_NodoL1(char nombre[30]) ;
void Agregar_NodoL2(char nombre[30]) ;
void MostraListaDoble();
void BorrarListaDoble();
bool ConsultarDato(char nombre[30]);
void MostraListaDoble2();
void RecuperarDato();
bool ConsultarDatoPapelera(char nombre[30]);



 main(){
 	int SW;
 	char OP='S';
 	 while(OP=='S'){
 	  system("cls"); 	
      system("color 1F");
     
        gotoxy(49,4);cout << "M  E  N  U";
        gotoxy(40,6);cout <<"1.ADICIONAR ";
        gotoxy(40,7);cout <<"2.CONSULTA LISTADO ";
        gotoxy(40,8);cout <<"3.BORRAR  ";
        gotoxy(40,9);cout <<"4.PAPELERA";
        gotoxy(40,10);cout <<"5.RECUPERAR ";
        gotoxy(40,11);cout <<"6.SALIR ";
        

      do{
         gotoxy(43,12);cout << "SELECCIONE UNA ALTERNATIVA  ";cin >> SW;
      } while (( SW < 1 ) || ( SW > 6 ) ) ;
        cin.sync();
     
	   switch(SW){
    	case 1: PedirNodoUsuarioL1();
    	        break;
    	case 2: MostraListaDoble();
    	        break; 
        case 3: BorrarListaDoble();
    	        break;
    	case 4: MostraListaDoble2();
    	        break;
		case 5:RecuperarDato();
    	        break;           
		case 6: OP='N';
    	        break;				       
	   }
	
	  }
 }
 
 /***************PEDIR DATOS AL USUARIO***********/
 void PedirNodoUsuarioL1() {
 	char Seguir='S',nombre[30];
 	do{
 		Nodo1 *p=new(struct Nodo1);
 		if(p==NULL){
 			gotoxy(25,20);cout<<"NO HAY MEMORIA DISPONIBLE";getch();
 	 	 	gotoxy(25,20);cout<<"                                     ";
		 }else{
		 	 system("cls"); 
		 	 /*********LLENO EL NODO************/
		 	 gotoxy(45,6);cout<<"AGREGANDO DATOS AL NODO DOBLE";
		     gotoxy(40,10);cout<<"NOMBRE      : ";gets(nombre);
		      Agregar_NodoL1(nombre);
		    }
		 
 		 do{
		    	gotoxy(25,20);cout<<"                                     ";
        	    gotoxy(43,20);cout<<"SEGUIR AGREGANDO   S/N ->"; 
			    Seguir= getch();
                Seguir = toupper(Seguir);
		   }while((Seguir!='S')&&(Seguir!='N'));
 		

	 }while(Seguir!='N'); 
	
 }
 
 /***************AGREGAR PRIMER NODO DOBLE***********/
 
 void Agregar_NodoL1(char nombre[30]) {
  Nodo1 *p=new(struct Nodo1);
  Nodo1 *q=new(struct Nodo1);
  strcpy (p->NOM,nombre) ;	
 /*******BALANCEAR *********/
 p->SIG=NULL;p->ANT=NULL;
/*******AGREGO EL NODO A LA LISTA *********/ 
  if(cabeza==NULL)  {
    cabeza=p;
   } else {
	   q=cabeza;
    	while(q->SIG!=NULL)	{
		  q=q->SIG;
    	}
	  q->SIG=p;
      p->ANT=q;
	}
 	 	 
}



/***************AGREGAR SEGUNDO  NODO DOBLE***********/
 void Agregar_NodoL2(char nombre[30]) {
 Nodo2 *p2=new(struct Nodo2);
  strcpy (p2->NOM,nombre) ;
 /*******BALANCEAR *********/
 p2->SIG=NULL;p2->ANT=NULL;
/*******AGREGO EL NODO A LA LISTA *********/ 
 if(cabeza2==NULL){
	 cabeza2=p2;FIN2=p2;
 }else {
		FIN2->SIG=p2;
		p2->ANT=FIN2;
	    FIN2=p2;
	   }
		 	 
}	 
 		
  /***********MOSTRAR  NODO LISTA DOBLE***********/
  void MostraListaDoble(){
  	int f;
  	Nodo1 *recorrer1=new(struct Nodo1);
  	recorrer1=cabeza;
  	if(recorrer1==NULL){
  		gotoxy(25,20);cout<<"NO HAY MEMORIA DISPONIBLE";getch();
 	 	gotoxy(25,20);cout<<"                                     ";
	  }else{ 
	     
	     	system("cls");
	          f=12;
	        gotoxy(45,6);cout<<"LISTA DE REGISTRADOS";
		   	gotoxy(40,10);cout<<" NOMBRES";
		   	do{
	          	gotoxy(42,f);cout<<	recorrer1->NOM;
	          	f++;
	          	recorrer1=recorrer1->SIG;
			 	} while(recorrer1!=NULL);
	   	gotoxy(38,20);cout<<"PULSE UNA TECLA PARA VOLVER AL MENU PRINCIPAL";getch();   
	  }
  	 
  }
  
   /*****************BORRAR ELEMENTO***********/
  void BorrarListaDoble(){
    bool Encontro;
   	char nombre[40];
    if(cabeza==NULL){
    	   gotoxy(30,20);cout<<"NO EXISTE ELEMENTOS";getch();
 	 	   gotoxy(30,20);cout<<"                                     ";	
		}else{
			   system("cls");
		       gotoxy(45,6);cout<<"BORRE DE DATOS";
               gotoxy(43,8);cout<<"NOMBRE  :  "; gets(nombre);
               Encontro=ConsultarDato(nombre);
               if (Encontro==true)   {
                  gotoxy(45,12);cout<<"ELIMINADO CON EXITO";
               }else{
               	   gotoxy(43,12);cout<<"NO EXISTE ELEMENTO ";
			   }
    
			 }	
	    
	gotoxy(38,20);cout<<"PULSE UNA TECLA PARA VOLVER AL MENU PRINCIPAL";getch();	
	
}

    /****CONSULTAR DATO*********/

bool ConsultarDato(char nombre[30]){
   	char Encontro;
       p=cabeza;Encontro='N';

	do{
	  	if(strcmp (p->NOM,nombre)== 0){
	    	Encontro='S';
	
		}else{
			 p=p->SIG;
			}
	  }while((Encontro!='S')&&(p!=cabeza));
	  
	     if(Encontro=='S'){
                 Agregar_NodoL2(nombre);	
			 /**************BORRAR EL NODO CORRECTAMENTE***/
	  	     	if((p==cabeza)&&(cabeza->ANT==NULL)&&(cabeza->SIG==NULL)){
				 	    /***NODO UNICO****/
				 	 	delete(p);cabeza=NULL;
				}else{
					  	if((cabeza->SIG!=cabeza)&&(p==cabeza)){
					  	    /********BORRAR EL PRIMERO,NO UNICO******/
					  	  	    cabeza=cabeza->SIG;cabeza->ANT=NULL;
					  	  	    delete(p);
						}else{
								if(p->SIG==NULL){/*******BORRAR EL ULTIMO*********/
								     p->ANT->SIG=NULL;
								    delete(p);
									
								}else{
								       /*******BORRA UN CUALQUIERA DISTINTO AL PRIMERO Y AL ULTIMO****/
									      p->ANT->SIG=p->SIG;
									      p->SIG->ANT=p->ANT;
									      delete(p); 
								}
							}
					  }
	  	     		    
	  	     	    
	  	     	 return true;	    
		}else{
			 return false;
		}
	              
   }
   
/***********MOSTRAR  NODO2 LISTA DOBLE***********/
  void MostraListaDoble2(){
  	int f;
  	Nodo2 *recorrer1=new(struct Nodo2);
  	recorrer1=cabeza2;
  	if(recorrer1==NULL){
  		gotoxy(25,20);cout<<"NO EXISTEN ELEMENTOS";getch();
 	 	gotoxy(25,20);cout<<"                                     ";
	  }else{ 
	     
	     	system("cls");
	          f=12;
	        gotoxy(45,6);cout<<"LISTA DE  NOMBRES BORRADOS";
		   	gotoxy(40,10);cout<<" NOMBRES";
		   	do{
	          	gotoxy(42,f);cout<<	recorrer1->NOM;
	          	f++;
	          	recorrer1=recorrer1->SIG;
			 	} while(recorrer1!=NULL);
	   	gotoxy(38,20);cout<<"PULSE UNA TECLA PARA VOLVER AL MENU PRINCIPAL";getch();   
	  }
  	 
  }
  /*********RECUPERAR DATO*******/

  void RecuperarDato(){
    bool Encontro;
   	char nombre[40];
    if(cabeza2==NULL){
    	   gotoxy(30,20);cout<<"NO EXISTE ELEMENTOS";getch();
 	 	   gotoxy(30,20);cout<<"                                     ";	
		}else{
			   system("cls");
		       gotoxy(45,6);cout<<"RECUPERAR DATOS DE LA PAPELERA";
               gotoxy(43,8);cout<<"NOMBRE  :  "; gets(nombre);
               Encontro=ConsultarDatoPapelera(nombre);
               if (Encontro==true)   {
                  gotoxy(45,12);cout<<"DATO RECUPERADO CON EXITO";
               }else{
               	   gotoxy(43,12);cout<<"NO EXISTE ELEMENTO EN LA PAPELERA";
			   }
    
			 }	
	    
	gotoxy(38,20);cout<<"PULSE UNA TECLA PARA VOLVER AL MENU PRINCIPAL";getch();	
	
}
/****CONSULTAR DATO DE LA PAPELERA*********/

bool ConsultarDatoPapelera(char nombre[30]){
   	char Encontro;
    	Nodo2 *q=new(struct Nodo2);
       p2=cabeza2;Encontro='N';

	do{
	  	if(strcmp (p2->NOM,nombre)== 0){
	    	Encontro='S';
	    	q=p2;
	
		}else{
			 p2=p2->SIG;
			}
	  }while((Encontro!='S')&&(p2!=cabeza2));
	  
	     if(Encontro=='S'){
	     
                Agregar_NodoL1(nombre);
			 /**************BORRAR EL NODO CORRECTAMENTE***/
	  	     	if((p2==cabeza2)&&(cabeza2->ANT==NULL)&&(cabeza2->SIG==NULL)){
				 	    /***NODO UNICO****/
				 	 	delete(p2);cabeza2=NULL;
				}else{
					  	if((cabeza2->SIG!=cabeza2)&&(p2==cabeza2)){
					  	    /********BORRAR EL PRIMERO,NO UNICO******/
					  	  	    cabeza2=cabeza2->SIG;cabeza2->ANT=NULL;
					  	  	    delete(p2);
						}else{
								if(p2->SIG==NULL){/*******BORRAR EL ULTIMO*********/
								     p2->ANT->SIG=NULL;
								    delete(p2);
									
								}else{
								       /*******BORRA UN CUALQUIERA DISTINTO AL PRIMERO Y AL ULTIMO****/
									      p2->ANT->SIG=p2->SIG;
									      p2->SIG->ANT=p2->ANT;
									      delete(p2); 
								}
							}
					  }
	  	     		    
	  	     	    
	  	     	 return true;	    
		}else{
			 return false;
		}
	              
   } 
  
  	
