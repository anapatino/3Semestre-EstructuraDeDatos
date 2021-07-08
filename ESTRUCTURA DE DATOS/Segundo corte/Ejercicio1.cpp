/*ESCRIBA UN ALGORITMO QUE PERMITA AGREGAR HISTORIAS CLINICAS A UNA LISTA ENLAZADA SIMPLE DE PACIENTES,VALIDAR CUANDO EL PACIENTE YA TIENE
 HISTORIA EN LA EPS Y EN ESE CASO PERMITA SUMAR EL DIAGNOSTICO NUEVO AL QUE YA TRAIA ESE PACIENTE*/
 
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
struct Nodo{

 long IDENT;
 char NOMBRE[40];
 int EST;
 float TARIFA ;
 char DIAG[120] ;
Nodo * SIG;
};
/* Ahora declaramos las variables de tipo apuntador a esta estructura */
Nodo *p, *q, *r, *cabeza; 
main(){
char Encontro,Seguir='S',OP='S',diag[20],opcion;
int SW,Cont,Pos;
long dato,ident;
   while(OP=='S'){
   	  system("cls"); 	
      system("color F1");
     
        gotoxy(29,4);cout << "M E N U"<<endl;
        gotoxy(26,6);cout << "1.ADICIONAR PACIENTE";
        gotoxy(20,8);cout <<"2.CONSULTA HISTORIA DEL PACIENTES ";
        gotoxy(20,10);cout <<"3.RETIRAR HISTORIA DE PACIENTE  ";
      /*cout <<"4.INFORME DE PACIENTE "<<endl;
      cout <<"5.RETIRAR HISTORIA DE PACIENTE "<<endl;*/
       gotoxy(20,12);cout <<"4.SALIR ";

     
    
      do{
         gotoxy(20,14);cout << "SELECCIONE UNA ALTERNATIVA  ";cin >> SW;
      } while (( SW < 1 ) || ( SW > 4 ) ) ;
        cin.sync();
    switch(SW){
      	 	  
	  case 1 : Seguir='S';
	  	        while(Seguir=='S'){
   	          /* Pido un nodo */
             p=new(struct Nodo);
              if( p == NULL){
             	   gotoxy(20,18);cout<<"NO HAY MEMORIA DISPONIBLE EN EL SISTEMA"; 
	          }else
	               { 
				     system("cls"); 
	  	            /*LLENAMOS EL NODO*/
	  	           
                      gotoxy(20,10);cout<<"Nro IDENTIDAD  :  "; cin>>ident;
                        cin.sync();
                     gotoxy(20,11);cout<<"NOMBRE         :  "; gets(p->NOMBRE) ;
                        cin.sync();
                    do{
                    	gotoxy(34,12); cout<< "    " ;
                        gotoxy(20,12);cout<<"ESTRATO     : " ; cin>> p->EST;
						gotoxy(20,20); cout << " Ingrese valor numerico 0- 6 ";	
					}while(( p->EST< 0) || (p->EST > 6));
                       gotoxy(20,20); cout <<"                                                                          ";
                        cin.sync();
                       gotoxy(20,13);cout<<"DIAGNOSTICO  :  "; gets(diag) ;
                          cin.sync();
                          
                        if(p->IDENT==ident){
                          	strcpy(p->DIAG,diag);
						  }else{
						  	p->IDENT=ident;
						  	strcpy(p->DIAG,diag);
						  }
                     /* Calculo de Tarifa*/ 
                     if(p->EST<=2){
           	          p->TARIFA = 1000 ;
		              } 
		               else{
		   	                 if(p->EST==3){
		   	                 	p->TARIFA=1500 ;
					         }	else{
			                     	p->TARIFA=10000 ;
				                  	}
		        }
                   /* Balanceamos el nodo ...*/
                    p->SIG=NULL;
                   /* es el primer nodo de la lista ??? */   
                   if(cabeza==NULL){
            	        cabeza=p;
		             }else{
		   	           /* recorremos la lista desde la cabeza hasta el ultimo nodo */
                       /* para añadir al final el nuevo alumno a la lista */ 
                          r=cabeza;
                          while(r->SIG !=NULL){
                           	r=r->SIG; 
				         }
				        /* ahora el apuntador r apunta al ultimo nodo de la lista */
                         /* entonces añado el nuevo nodo después del ultimo */
                         r->SIG=p;
		   }
	    }
	     do{ 
	         gotoxy(25,20);cout<<"                                     ";
        	 gotoxy(25,20);cout<<"SEGUIR AGREGANDO PACIENTE  S/N "; 
			  Seguir= getch();
              Seguir = toupper(Seguir);
	      }while((Seguir!='N')&&(Seguir!='S'));
	       gotoxy(25,20);cout<<"                                     ";
          }
	  	       break;
	  case 2 :
	  	      Seguir='S';
	  	      while(Seguir=='S'){
	  	      	 system("cls");  
	  	      	  gotoxy(26,6); cout<<"CONSULTAR HISTORIAL DEL PACIENTE";
	  	          gotoxy(26,8);cout<<"IDENTIFICACION   :  "; cin>>dato;
	  	          p=cabeza; Encontro='N'; Cont=0 ;
                  
                  while((Encontro=='N') && (p!=NULL) ){
                  	Cont++;
                  	if(p->IDENT == dato){
                  		Encontro ='S'; Pos=p->IDENT;
					  } else{
					  	  p= p->SIG ; 
					  }
					
                  	 if(Encontro == 'S'){

                        gotoxy(20,12);cout<<"NOMBRE         :  "<<p->NOMBRE ;
                        gotoxy(20,14);cout<<"ESTRATO     : "<< p->EST;
                        gotoxy(20,13);cout<<"DIAGNOSTICO  :  "<<p->DIAG;
					   }else{
					   	    cout<<"El Paciente consultado NO esta en la lista ";
					   }
					      
				  }
	  	        cout <<" "<<endl;
	  	       	cout<<"Desea consultar Otro Paciente [S/N]"<<endl ; Seguir= getch();
                 Seguir = toupper(Seguir);
                
				}
	
	           break;
	  case 3:  
	           Seguir='S';
	  	      while(Seguir=='S'){
	  	        	cout <<"                        "<<endl;
	  	          cout<<"CEDULA QUE DESEA RETIRAR->"; cin>>dato;
	  	        if(cabeza==NULL){
	  	        	cout <<"LA LISTA ESTA VACIA"<<endl;
				  }else{
				    	p=cabeza;Encontro='N';
				    	while((Encontro=='N' )&&(p!=NULL)){
				    	   Cont++;
				  	      if(p->IDENT==dato){
				  	          Encontro='S';
				  	          cout<<""<<endl;
				  	          cout<<"Encontrado el Paciente en la posición"<< Cont<<endl;
                              cout<<" Documento de Identidad :"<<p->IDENT<<endl;
                              cout<<"Nombre :"<<p->NOMBRE<<endl;
                              cout<<"Estrato  "<< p->EST<<endl;
                              cout<<"Diagnóstico :"<<p->DIAG<<endl;
                              cout<<""<<endl;
					      }else{
					   	     p=p->SIG;
					       }
				     	}  
					     if(Encontro=='N')	{
					  	        cout<<" No esta ese dato en la lista …"<<endl;
					     }else{
					     	  cout<<""<<endl;
				  	        
                              cout<<" Documento de Identidad :"<<p->IDENT<<endl;
                              cout<<"Nombre :"<<p->NOMBRE<<endl;
                              cout<<"Estrato  "<< p->EST<<endl;
                              cout<<"Diagnóstico :"<<p->DIAG<<endl;
                              cout<<""<<endl;
                              do{
                              	cout<<"DESEA BORRAR ESTE REGISTRO [S/N]  ";opcion= getch();
                                   opcion = toupper(opcion);
							   }while((opcion!='N')&&(opcion!='S'));
							   
					  	     if(opcion=='S'){
					  	       	/*Entonces ubicamos OTRO apuntador ANTES de P */
                                 q=cabeza;
                                  while(q->SIG!=p ){
                                   q=q->SIG;
                                  }
                                    /* Ya Q está apuntando a un nodo ANTES de P, entonces
                                   “Desengancho” el nodo al cual apunta P */
                                  q->SIG=p->SIG;
                                   /* Y ahora “Libero” el nodo al cual apunta P */
                                  delete(p);
                                  /* Está en el PRIMER nodo???? */
                                  if(p==cabeza){
					  	  	          	cabeza=cabeza->SIG;
					  	  	  	        delete(p);
                                  
					  	          }	
							}	  
					  }
					
				  }
	  	        cout<<"Desea Borrar otro valor  S/N"; Seguir= getch();
                 Seguir = toupper(Seguir);
				}    
	           break;    
	  case 4:  OP='N';
   }
  
  }
}














