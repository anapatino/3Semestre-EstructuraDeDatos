#include <windows.h>                     
#include <iostream>                      
#include <conio.h>   
#include<string.h>                   
using namespace std;
 
 int gotoxy (USHORT x, USHORT y) {                                  
COORD cp = {x, y};                                                 
SetConsoleCursorPosition (GetStdHandle (STD_OUTPUT_HANDLE), cp);   
}
void PedirNodoUsuarioL1();
void PedirNodoUsuarioL2();
void MostraListaL1();
void MostraListaL2();
void CruzarListas();
/********* DECLARANDO LA ESTRUCTURA********************/
struct Nodo1{

 long Cedula;
 char Nombre[40];
 char Diagnostico[120] ;
Nodo1 * SIG;
};

Nodo1 *p, *q, *r, *cabeza; 

struct Nodo2{

 long Cedula;
 char Nombre[40];
 char Diagnostico[120] ;
Nodo2 * SIG;
};

Nodo2 *p2, *q2, *r2, *cabeza2; 

main(){
 	int SW;
 	char OP='S';
 	 while(OP=='S'){
 	  system("cls"); 	
      system("color 1F");
     
        gotoxy(49,4);cout << "M  E  N  U";
        gotoxy(40,6);cout <<"1.ADICIONAR DATOS LISTA L1";
        gotoxy(40,7);cout <<"2.ADICIONAR DATOS LISTA L2";
        gotoxy(40,8);cout <<"3.CONSULTA LISTA L1 " ;
        gotoxy(40,9);cout <<"4.CONSULTA LISTA L2 ";
        gotoxy(40,10);cout <<"5.CRUZAR LISTAS";
        gotoxy(40,11);cout <<"6.SALIR ";

      do{
         gotoxy(43,13);cout << "SELECCIONE UNA ALTERNATIVA  ";cin >> SW;
      } while (( SW < 1 ) || ( SW > 6 ) ) ;
        cin.sync();
     
	   switch(SW){
    	case 1:PedirNodoUsuarioL1() ;
    	        break;
    	case 2: PedirNodoUsuarioL2();
    	        break; 
        case 3:MostraListaL1();
    	        break;
        case 4:MostraListaL2();
    	        break;
		case 5:CruzarListas();
    	        break;	        
		case 6: OP='N';
    	        break;				       
	   }
	
	  }
 }
 
  /***************PEDIR DATOS A LA PRIMERA LISTA***/
 void PedirNodoUsuarioL1() {
 	char Seguir='S';
 	do{
 		Nodo1 *p=new(struct Nodo1);
 		
 		if(p==NULL){
 			gotoxy(25,20);cout<<"NO HAY MEMORIA DISPONIBLE";getch();
 	 	 	gotoxy(25,20);cout<<"                                     ";
		 }else{
		 	   system("cls"); 
		 	   gotoxy(45,6);cout<<"CAPTURA DE DATOS LISTA 1";
		       
		        gotoxy(40,10);cout<<"Cedula       :  ";cin>>p->Cedula;
		        cin.sync();
		        gotoxy(40,11);cout<<"Nombre       :  ";gets(p->Nombre);
		        gotoxy(40,12);cout<<"Diagnostico  :  ";gets(p->Diagnostico);
		    
		           /****BALANCEAMOS EL NODO***/
		          p->SIG = NULL;
		        if(cabeza == NULL)	 {
		 	     cabeza=p;
		        } else{
		        	   q=cabeza;
		            	while(q->SIG!=NULL){
		 		          q=q->SIG;
			            }
		    	       q->SIG=p;
	                }
	       }
		    	gotoxy(25,20);cout<<"                                     ";
        	    gotoxy(43,20);cout<<"SEGUIR AGREGANDO   S/N ->"; 
                Seguir = toupper(getche());
		   
	 }while(Seguir!='N');
 }
 
  /***************PEDIR DATOS A LA SEGUNDA LISTA***/
 void PedirNodoUsuarioL2() {
 	char Seguir='S';
 	do{
 		Nodo2 *p2=new(struct Nodo2);
 		
 		if(p2==NULL){
 			gotoxy(25,20);cout<<"NO HAY MEMORIA DISPONIBLE";getch();
 	 	 	gotoxy(25,20);cout<<"                                     ";
		 }else{
		 	   system("cls"); 
		 	   gotoxy(45,6);cout<<"CAPTURA DE DATOS LISTA 2";
		       
		        gotoxy(40,10);cout<<"Cedula       :  ";cin>>p2->Cedula;
		        cin.sync();
		        gotoxy(40,11);cout<<"Nombre       :  ";gets(p2->Nombre);
		        gotoxy(40,12);cout<<"Diagnostico  :  ";gets(p2->Diagnostico);
		    
		           /****BALANCEAMOS EL NODO***/
		          p2->SIG = NULL;
		        if(cabeza2 == NULL)	 {
		 	     cabeza2=p2;
		        } else{
		        	   q2=cabeza2;
		            	while(q2->SIG!=NULL){
		 		          q2=q2->SIG;
			            }
		    	       q2->SIG=p2;
	                }
	       }
		    	gotoxy(25,20);cout<<"                                     ";
        	    gotoxy(43,20);cout<<"SEGUIR AGREGANDO   S/N ->"; 
                Seguir = toupper(getche());
		   
	 }while(Seguir!='N');
 }
 
 /***********MOSTRAR PRIMER  NODO ***********/
 
  void MostraListaL1(){
  	int f;
  	f=12;
    Nodo1 *recorrer1=new(struct Nodo1);
         recorrer1=cabeza;
  	if(recorrer1==NULL){
  		gotoxy(30,20);cout<<"NO HAY MEMORIA DISPONIBLE";getch();
 	 	gotoxy(30,20);cout<<"                                     ";
	  }else{ 
	     	system("cls");
	        gotoxy(45,6);cout<<"REGISTROS INGRESADOS EN LA 1RA LISTA";
		   	gotoxy(40,10);cout<<"CEDULA          NOMBRE             DIAGNOSTICO";
		   
			 while(recorrer1!=NULL) {  
	                gotoxy(41,f);cout<<recorrer1->Cedula;
	                gotoxy(56,f);cout<<recorrer1->Nombre;
	                gotoxy(76,f);cout<<recorrer1->Diagnostico;
	                 f++;
	             	 recorrer1=recorrer1->SIG;
			   }
	      
	  }
  	 	gotoxy(38,f+4);cout<<"PULSE UNA TECLA PARA VOLVER AL MENU PRINCIPAL";getch();
  }
  
void MostraListaL2(){
  	int f=12;
    Nodo2 *recorrer2=new(struct Nodo2);
         recorrer2=cabeza2;
  	if(recorrer2==NULL){
  		gotoxy(30,20);cout<<"NO HAY MEMORIA DISPONIBLE";getch();
 	 	gotoxy(30,20);cout<<"                                     ";
	  }else{ 
	     
	     	system("cls");
	        gotoxy(45,6);cout<<"REGISTROS INGRESADOS EN LA 1RA LISTA";
		   	gotoxy(40,10);cout<<"CEDULA          NOMBRE             DIAGNOSTICO";
		   
			while(recorrer2!=NULL) {  
	                gotoxy(41,f);cout<<recorrer2->Cedula;
	                gotoxy(56,f);cout<<recorrer2->Nombre;
	                gotoxy(76,f);cout<<recorrer2->Diagnostico;
	                 f++;
	             	 recorrer2=recorrer2->SIG;
			   } 
	      
	  }
  	 	gotoxy(38,f+4);cout<<"PULSE UNA TECLA PARA VOLVER AL MENU PRINCIPAL";getch();
  }
  
void CruzarListas(){
  char Encontro='N';
  Nodo1 *recorrer1=new(struct Nodo1);
  Nodo2 *recorrer2=new(struct Nodo2);	
   if((cabeza == NULL) || (cabeza2 == NULL)){

   	cout<<"No hay nada que hacer (Y)"; system ("pause");
   } else{
   	         system("cls");
	        gotoxy(45,6);cout<<"CRUZE DE LISTAS ";
      recorrer1= cabeza;
      do{
        	recorrer2 = cabeza2;  Encontro = 'N';
         do{
               if(recorrer1->Cedula== recorrer2->Cedula ) {
                 Encontro = 'S';
               }else{
                  recorrer2 = recorrer2->SIG;
               }
          } while((recorrer2 != NULL) && (Encontro == 'N'));

      if(Encontro == 'S'){
  
       	strcat(recorrer1->Diagnostico,",");
       	strcat(recorrer1->Diagnostico," ");
       	strcat(recorrer1->Diagnostico,recorrer2->Diagnostico);
      }
     recorrer1 = recorrer1->SIG;
   }while(recorrer1 != NULL);
    
  }
  gotoxy(38,15);cout<<"PROCESO REALIZADO CON EXITO";getch();	
}

