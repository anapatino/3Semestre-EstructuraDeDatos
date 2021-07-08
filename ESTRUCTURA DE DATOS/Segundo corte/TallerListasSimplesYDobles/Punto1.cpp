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

 int NUM;
 Nodo1 * SIG;

}*cabeza1,*FIN1,*borrar;



struct Nodo2{

 int NUM;
 Nodo2 * SIG;
 Nodo2 * ANT;
} *cabeza2,*FIN2;

void Agregar_NodoL1( Nodo1 *p1) ;
void Agregar_NodoL2(Nodo2 *p2) ;
void PedirNodoUsuarioL1();
void PedirNodoUsuarioL2();
void MostraListaL1();
void MostraListaL2();
int ConsultarDato(int dato);
void borrarCabeza();
void borrarUltimo();
void borrarNodo();
void borrarMitad(Nodo1 *borrar);
void copiarUnico();



main(){
 	int SW;
 	char OP='S';
 	 while(OP=='S'){
 	  system("cls"); 	
      system("color 1F");
     
        gotoxy(49,4);cout << "M  E  N  U";
        gotoxy(40,6);cout <<"1.ADICIONAR DATOS LISTA L1 ";
        gotoxy(40,7);cout <<"2.ADICIONAR DATOS LISTA L2(ORDENADAMENTE)";
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
		case 5:copiarUnico();
    	        break;	        
		case 6: OP='N';
    	        break;				       
	   }
	
	  }
 }
 /***************PEDIR DATOS AL USUARIO NODO DOBLE***/
 void PedirNodoUsuarioL2() {
 	char Seguir='S';
 	int cont=0,res=0;
    int dato=0;
    
 	do{
 		Nodo2 *p1=new(struct Nodo2);
 		
 		if(p1==NULL){
 			gotoxy(25,20);cout<<"NO HAY MEMORIA DISPONIBLE";getch();
 	 	 	gotoxy(25,20);cout<<"                                     ";
		 }else{
		 	   system("cls"); 
		 	   gotoxy(45,6);cout<<"CAPTURA DE DATOS PARA EL NODO DOBLE ";
		        cont++;
		        gotoxy(40,10);cout<<"NUMERO [   ]  -> ";gotoxy(49,10);cout<<cont;
		        
		     do{
	             gotoxy(58,10);cout<<"                                                              ";
			     gotoxy(58,10);cin>>dato;
		         res=ConsultarDato(dato);
		   	   }while(res==1) ;
				p1->NUM=dato;	
	
		        Agregar_NodoL2(p1);
	       }
		    	gotoxy(25,20);cout<<"                                     ";
        	    gotoxy(43,20);cout<<"SEGUIR AGREGANDO   S/N ->"; 
                Seguir = toupper(getche());
		   
	 }while(Seguir!='N');
 }
 /***************AGREGAR  NODO DOBLE***********/
 void Agregar_NodoL2(Nodo2 *p2) {
 	Nodo2 *q2=new(struct Nodo2);

  /*******BALANCEAR *********/
  
	 p2->SIG=NULL;p2->ANT=NULL;
	 
   /*******INSERTO EL NODO ORDENADAMENTE A LA LISTA *********/ 
   
	if(cabeza2==NULL){
			cabeza2=p2;	FIN2=p2;
		 	        
	}else {
			if(p2->NUM>=cabeza2->NUM){
			  	   p2->SIG=cabeza2;cabeza2->ANT=p2; cabeza2=p2;
			  	    	
			}else{
				 if(p2->NUM<=FIN2->NUM){
					 FIN2->SIG=p2;p2->ANT=FIN2; FIN2=p2;
				  }else{
						 q2=cabeza2;
						   	 while(p2->NUM<=q2->NUM){
						   	   	 q2=q2->SIG;
							   }
								  p2->ANT=q2->ANT;
								  q2->ANT->SIG=p2;
								  p2->SIG=q2;
								  q2->ANT=p2;
					   }
				}
	 		    
	    }
		 	 
		 	 
}
		 
 /*************BUSQUEDA DE NRO REPETIDOS********************/
   int ConsultarDato(int dato){
   	char Encontro;
   	int res=0;
   	    Nodo2 *recorrer2=new(struct Nodo2);

  if(cabeza2!=NULL){
      recorrer2=cabeza2;
	  Encontro='N'; 
	  	     
	  do{
	    	if(recorrer2->NUM==dato){
	  	     	Encontro='S';
                     
			}else{  
					recorrer2=recorrer2->SIG;
				}
	        } while((Encontro!='S')&&(recorrer2!=NULL));
	        
	  	       if(Encontro=='S')   {
	  	       	     gotoxy(58,10) ;cout<<"                      ";
		           
		             res=1;
				}
	  }			 
	  	             
	  return res;	          
	   
   }
 
 /***************PEDIR DATOS AL USUARIO (NODO SIMPLE)***********/
 void PedirNodoUsuarioL1() {
 	char Seguir='S';
 	int cont=0;
 	do{
 	     Nodo1 *p1=new(struct Nodo1);
 		if(p1==NULL){
 			gotoxy(25,20);cout<<"NO HAY MEMORIA DISPONIBLE";getch();
 	 	 	gotoxy(25,20);cout<<"                                     ";
		 }else{
		 	 system("cls"); 
		 	 cont++;
	
		 	 gotoxy(45,6);cout<<"AGREGANDO DATOS AL NODO SIMPLE";
		     gotoxy(40,10);cout<<"NUMERO [   ]  -> ";gotoxy(49,10);cout<<cont;
			 gotoxy(58,10);cin>>p1->NUM;
		   	  cin.sync();
		     Agregar_NodoL1(p1);
		 
		    }
		 
 		 do{
		    	gotoxy(25,20);cout<<"                                     ";
        	    gotoxy(43,20);cout<<"SEGUIR AGREGANDO   S/N ->"; 
			    Seguir= getch();
                Seguir = toupper(Seguir);
		   }while((Seguir!='S')&&(Seguir!='N'));
 		

	 }while(Seguir!='N');
 }
 /***************AGREGAR  NODO SIMPLE***********/
 void Agregar_NodoL1(Nodo1 *p1) {

    /*******BALANCEAR *********/
	p1->SIG=NULL;
    /*******AGREGO EL NODO A LA LISTA *********/ 
	 if(cabeza1==NULL){
		 	cabeza1=p1;
	   }else {
		        FIN1->SIG=p1;
			  }
	 FIN1=p1;

 }
 
 /***********MOSTRAR PRIMER  NODO ***********/
 
  void MostraListaL1(){
        Nodo1 *recorrer1=new(struct Nodo1);
         recorrer1=cabeza1;
  	if(recorrer1==NULL){
  		gotoxy(30,20);cout<<"NO HAY MEMORIA DISPONIBLE";getch();
 	 	gotoxy(30,20);cout<<"                                     ";
	  }else{ 
	     
	     	system("cls");
	        gotoxy(45,6);cout<<"LISTA SIMPLE DE NUMEROS REGISTRADOS";
		   	gotoxy(40,10);cout<<"L1  =  ";
		   
			 do{  
	                cout<<recorrer1->NUM<<"  ";
	             	 recorrer1=recorrer1->SIG;
			   } while(recorrer1!=NULL);
	      
	  }
  	 	gotoxy(38,20);cout<<"PULSE UNA TECLA PARA VOLVER AL MENU PRINCIPAL";getch();
  }
  /***********MOSTRAR SEGUNDO NODO ***********/
  void MostraListaL2(){
        Nodo2 *recorrer2=new(struct Nodo2);
         recorrer2=cabeza2;   
  	if(recorrer2==NULL){
  		gotoxy(30,20);cout<<"NO HAY MEMORIA DISPONIBLE";getch();
 	 	gotoxy(30,20);cout<<"                                     ";
	  }else{ 
	     
	     	system("cls");
	        gotoxy(45,6);cout<<"LISTA DOBLE ENLAZADA DE NUMEROS REGISTRADOS";
            gotoxy(40,10);cout<<"L2  =  ";
		   	do{
	             cout<<recorrer2->NUM<<"  ";
	          	recorrer2=recorrer2->SIG;
			 	} while(recorrer2!=NULL);
	      
	  }
  	 	gotoxy(38,20);cout<<"PULSE UNA TECLA PARA VOLVER AL MENU PRINCIPAL";getch();
  }
    /***********BORRAR NODO ***********/
    void borrarNodo(Nodo1 *borrar){

   	char Encontro;
    if(cabeza1==NULL){
    	   gotoxy(30,20);cout<<"NO HAY MEMORIA DISPONIBLE";getch();
 	 	   gotoxy(30,20);cout<<"                                     ";	
		}else{
			   system("cls");
		        gotoxy(45,6);cout<<"CRUZE DE LISTAS";
		        gotoxy(45,12);cout<<"REALIZADO CON EXITO";
	           if (borrar == cabeza1)  {
                    borrarCabeza();
                }  else{
                	      if (borrar == FIN1) {
                              borrarUltimo();
                            }else {
                                   borrarMitad(borrar);
                                  }
				      }
			 }	
	    
	      
	gotoxy(38,20);cout<<"PULSE UNA TECLA PARA VOLVER AL MENU PRINCIPAL";getch();	

		
  	} 
	///BORRAR CABEZA////////
	void borrarCabeza(){
	   Nodo1 *nodoBorrar= cabeza1;
    cabeza1 = cabeza1->SIG;
    delete(nodoBorrar);
}

////////BORRAR ULTIMO//////

void borrarUltimo(){
    Nodo1 *recorrer1=new(struct Nodo1);
    recorrer1 = cabeza1;

    while(recorrer1->SIG->SIG!= NULL) {
   
        recorrer1 = recorrer1->SIG;
    }

    Nodo1 *nodoBorrar = FIN1;
    FIN1 = recorrer1;
    FIN1->SIG= NULL;
    nodoBorrar->SIG = NULL;
    delete(nodoBorrar);
}
//BORRAR NODO EN LA MITAD///
void borrarMitad(Nodo1 *borrar){

    Nodo1 *recorrer1=new(struct Nodo1);;
    recorrer1 = cabeza1;

    while(recorrer1->SIG->SIG!= NULL && recorrer1->SIG->NUM != borrar->NUM)  {
  
        recorrer1 = recorrer1->SIG;
    }

    if (recorrer1->SIG->NUM == borrar->NUM) {
   
        Nodo1 *nodoBorrar = recorrer1->SIG;
        recorrer1->SIG = nodoBorrar->SIG;
        nodoBorrar->SIG = NULL;
        delete(nodoBorrar);
    }
}
////////COPIAR NRO NO REPETIDO//////////
void copiarUnico(){

	   Nodo1 *recorrer1=cabeza1;

    while (recorrer1 != NULL)  {
  
        Nodo1 *siguiente = recorrer1->SIG;

        if ( ConsultarDato(recorrer1->NUM))  {
            borrarNodo(recorrer1);
        }
        else {
    
            Nodo2 *p1 = new(struct Nodo2);
            p1->NUM= recorrer1->NUM;
            Agregar_NodoL2(p1);
        }
        recorrer1 = siguiente;
    }
}	
	 
