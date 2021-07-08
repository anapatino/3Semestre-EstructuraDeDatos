/***************************************************************************
 *                                                                         *
 *   CREA UN ARBOL BINARIO GENERAL Y LO CONSULTA EN PREORDEN, ENORDEN,     *
 *   POSTORDEN Y ANCHURA.   PROBLEMA No 12 DEL TALLER No 4                 *             
 *                                                                         *
 *   AUTOR : CARLOS O?ATE GOMEZ     ASIGNATURA : ESTRUCTURA DE DATOS       *
 *   
 *                                                                         *
 ***************************************************************************/
 
#include <iostream>
#include <conio.h>
#include <windows.h>

using namespace std;                     

int gotoxy(USHORT x,USHORT y){                                
COORD cp={x,y};                                                
SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),cp);  
}
  

#define  TITULO   "ARBOL BINARIO GENERAL";
#define  TITULO1  "C A P T U R A";
#define  TITULO2  "C O N S U L T A";


 /********************  ESTRUCTURA  ******************/
 
 struct xxx{
	 int num;
	 xxx *sig;
	 xxx *ant;
	};
	
 struct arbol {
 	  int dato;
      arbol *izq;
      arbol *der;
     };

 xxx *cabeza=NULL,*fin=NULL;
 
 /********************  FUNCIONES  ******************/
 
 int MENU();
 void CAPTURA(arbol *r);
 void preOrden(arbol *r);
 void inOrden(arbol *r);
 void posOrden(arbol *r);
 void ANCHURA(arbol *R);

 
 int est[100],s=0;
 arbol  *COLA[50];
 
 /***************** PROGRAMA PRINCIPAL ***************/

  main()
      {
      arbol *a;
      char  OP = 'S';
      int ALTERNATIVA;
      while ( OP == 'S' ) 
            {
	        ALTERNATIVA = MENU();
	        switch (ALTERNATIVA) {
	     	   case	1 : a = new arbol;
				        CAPTURA(a);
		                break;
               case 2 : system("cls");
                        gotoxy(29,4); cout << TITULO;
                        gotoxy(31,5); cout << TITULO2

                        gotoxy(5,8);  cout <<"PRE-ORDEN : ";
                        preOrden(a);
                        
                        gotoxy(5,12); cout <<"EN-ORDEN  : ";
                        inOrden(a);
                        
                        gotoxy(5,16); cout <<"POST-ORDEN : ";
	                    posOrden(a);
	                    gotoxy(5,20); cout <<"ANCHURA   : ";
	                    ANCHURA(a);
	                    
	                    gotoxy(24,24); cout << "PULSE CUALQUIER TECLA PARA SALIR";
	                    getch();
                        break;
               case 3 : OP = 'N';
              }
           }
       }
       

/*********************** MENU *********************/

int MENU()
  {
  int OPCION ;
  system("cls");
  system("color F0");
  gotoxy(29,6) ; cout << TITULO;
  gotoxy(36,7) ; cout << "M E N U " ;
  gotoxy(29,11); cout << "1. CAPTURA";
  gotoxy(29,12); cout << "2. CONSULTAR TODO EL ARBOL";
  gotoxy(29,14); cout << "3. SALIR";
  do {
     gotoxy(22,17); cout << "SELECIONE UNA DE LAS ALTERNATIVAS : ";
     cin >> OPCION ;
  } while((OPCION < 1) || (OPCION > 3)) ;
  return OPCION ;
 }
 
 /************************ CAPTURA ***********************/
 
 void CAPTURA(arbol *r)
       {
       arbol *dir;
       char resp;
       xxx *p,*q,*aux;
       system("cls");
       gotoxy(29,5) ; cout << TITULO;
       gotoxy(33,6) ; cout << TITULO1;
       gotoxy(20,10); cout<<"  INTRODUZCA UN VALOR : ";
       cin>>r->dato;
       //LLENADO LISTA DOBLE ORDENADA
       aux=q=cabeza;
       p=new xxx;
       if  (p==NULL)
           {
	       gotoxy(20,24);cout <<"NO HAY ESPACIO DE MEMORIA";
	       getch();
	       }
         else
           {
	       p->num=r->dato;
	       p->ant=p->sig=NULL;
	       if  (cabeza==NULL)
	           cabeza = fin = p;
	         else
               {
	           while ((aux->sig!=NULL)&&(p->num>aux->num))
			     {
	             q = aux;
	             aux=aux->sig;
	             }
	           if ((aux==cabeza)&&(p->num<aux->num))
                  {
	              p->sig = aux;
	              q->ant = p;
	              cabeza = p;
	              }
	            else
	              if ((aux->sig==NULL)&&(p->num>aux->num))
                     {
		             aux->sig=p;
	                 p->ant=aux;
	                 fin=p;
	                 }
	               else  
                     {
	                 q->sig=p;
	                 p->sig=aux;
	                 p->ant=q;
	                 aux->ant=p;
	                 }
	           }
	       }
           s++;
           est[s]=r->dato;
           gotoxy(20,18);cout <<"DESEA COLGAR HIJO IZQUIERDO DE "<<r->dato<<" S/N : ";
           resp = getch();
           resp = toupper(resp);
 
           if  (resp == 'S') 
               {
               dir = new arbol;
               r->izq = dir;
               CAPTURA(r->izq);    // recursividad
               }
             else 
               r->izq = NULL;
           
           gotoxy(20,18); cout <<"DESEA COLGAR  HIJO DERECHO  DE "<<r->dato<<" S/N : ";
           resp = getch();
           resp = toupper(resp);

           if (resp == 'S') 
              {
              dir = new arbol;
              r->der = dir;
              CAPTURA(r->der);    // recursividad
              }
            else
              r->der = NULL;
   }


 /*************************** PREORDEN **********************/

 void preOrden(arbol *r)
    {
     if  (r!=NULL)
         {
         cout << r->dato << " ";
         preOrden(r->izq);
         preOrden(r->der);
        }
    }

 /************************** INORDEN  ***********************/

 void inOrden(arbol *r)
    {
     if   (r!=NULL)
          {
          inOrden(r->izq);
          cout << r->dato << " ";
          inOrden(r->der);
          }
   }

 /************************* POSORDEN ************************/

 void posOrden(arbol *r)
      {
      if  (r!=NULL)
          {
          posOrden(r->izq);
          posOrden(r->der);
          cout <<r->dato << " ";
          }
     }
     
     
  /******************	RECORRIDO ANCHURA ********************/

 void ANCHURA(arbol *R)
    {
    int I = 0;
    arbol *ACT = NULL;

    if (R != NULL)
       {
       COLA[I]=R, COLA[I+1] = NULL, I++ ;    /// ENCOLAR
       while ( COLA[0]!=NULL )
           {
           ACT = COLA[0];
           for (int J = 0; J < I; J++)
               COLA[J] = COLA[J+1];           /// DESENCOLAR
           I--;
           cout << ACT->dato << " ";
           if (ACT->izq != NULL)
              COLA[I] = ACT->izq, COLA[I+1] = NULL, I++ ;   /// ENCOLAR
           if (ACT->der != NULL)
    	      COLA[I] = ACT->der, COLA[I+1] = NULL, I++;   /// ENCOLAR
           }
       }
   }   
     

