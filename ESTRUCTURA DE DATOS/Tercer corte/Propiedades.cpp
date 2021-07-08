/***************************************************************************
 *                                                                         *
 *   CREA UN ARBOL BINARIO ORDENADO, LO CONSULTA EN PREORDEN, ENORDEN,     *
 *   POSTORDEN, ANCHURA Y OBTIENE TODAS LAS PROPIEDADES.                   *
 *   PROBLEMA No 11 DEL TALLER No 4                                        *             
 *                                                                         *
 *   AUTOR : CARLOS O?ATE GOMEZ     ASIGNATURA : ESTRUCTURA DE DATOS       *
 *   
 *                                                                         *
 ***************************************************************************/
#include <iostream>
#include <conio.h>
#include <ctype.h>
#include <windows.h>

using namespace std;                     

int gotoxy(USHORT x,USHORT y){                                
COORD cp={x,y};                                                
SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),cp);  
}

#define  TITULO1  "ARBOL BINARIO ORDENADO";
#define  TITULO2  "CAPTURA";
#define  TITULO3  "CONSULTA";

/******************	DECLARACION DE ESTRUCTURA ********************/ 

struct NODO {
       int  INFO ;
       NODO *IZQ ;
       NODO *DER ;
       } ;
       
/******************** DECLARACI?N DE FUNCIONES ********************/        
  
 int MENU();     
 void CREAR() ;     
 void CONSULTA() ;
 void PREORDEN( NODO *R ) ;
 void ENORDEN( NODO *R ) ;
 void POSORDEN( NODO *R ) ;
 void ANCHURA(NODO *R);
 void NodosHijos(NODO *R);
 void NodosPadres(NODO *R);
 void NodosHojas(NODO *R);
 void NodosInterior(NODO *R);
 void NodosHermanos(NODO *R);
 void GradoNodo(NODO *R);
 void NivelNodos(NODO *R);
 void Propiedades();
 
 NODO *COLA[50];
 NODO *RAIZ ;
 int maximo, nivel, maximoNivel, peso;
 
/******************	PROGRAMA PRINCIPAL ********************/    

 main()
   {
   RAIZ = NULL ;
   nivel =0;
   maximoNivel=0;
   char  OP = 'S';
   int ALTERNATIVA;
   while ( OP == 'S' ) 
       {
	   ALTERNATIVA = MENU();
	   switch (ALTERNATIVA) {
		   case	1 : CREAR();
		            break;
           case 2 : CONSULTA();
                    break;
           case 3 : Propiedades();
                    break;        
           case 4 : OP = 'N';
           }
       }
   }

/*********************** MENU *********************/

int MENU()
  {
  peso=0;
  int OPCION ;
  system("cls");
  system("color F0");
  gotoxy(29,6) ; cout << TITULO1;
  gotoxy(36,7) ; cout << TITULO2 ;
  gotoxy(29,11); cout << "1. CAPTURA";
  gotoxy(29,12); cout << "2. CONSULTAR TODO EL ARBOL";
  gotoxy(29,13); cout << "3. PROPIEDADES DEL ARBOL";
  gotoxy(29,15); cout << "4. SALIR";
  do {
     gotoxy(22,17); cout << "SELECIONE UNA DE LAS ALTERNATIVAS : ";
     cin >> OPCION ;
  } while((OPCION < 1) || (OPCION > 4)) ;
  return OPCION ;
 }
  
/************************ CREAR ***********************/
  
 void CREAR()
    {
	NODO *P, *X, *Y ;
	char OP = 'S';
    while (OP == 'S')
	    {
		system("cls");
		system("color 3F");
	    gotoxy(29,6) ; cout << TITULO1;
	    gotoxy(36,7) ; cout << TITULO2;
	    gotoxy(20,12); cout << "VALOR  : ";
	    P = new NODO;
	    if (P == NULL)
	       {
		   gotoxy(25,22); cout << "NO HAY ESPACIO DE MEMORIA PARA ASIGNAR";
           OP = 'N';
		   }
	     else
	        {
		    do {
			   gotoxy(30,12) ;cin >> P -> INFO;
		       gotoxy(20,24) ; cout << "Valor Fuera de Rango";
		    } while ((P -> INFO < 0) || (P -> INFO > 32667));
		    gotoxy(20,24); cout << "                        ";
		    P -> IZQ = NULL;
		    P -> DER = NULL;
		    if (RAIZ == NULL)
		       RAIZ  = P;
		     else
		        {
			    Y = RAIZ ;
			    while ( Y != NULL) 
			        {
					X = Y ;
			        if ( P -> INFO <= X -> INFO)
			           Y =  Y -> IZQ ;
			         else
				       Y =  Y -> DER ;
			       }
		        if ( P -> INFO <= X->INFO )
		           X -> IZQ = P;
		          else
		           X -> DER = P;
			    }
		   do {
		      gotoxy(29,17); cout << "DESEA CONTINUAR S/N :  ";
		      OP = getche();
		      OP = toupper(OP);
		   } while ((OP == 'S' ) && (OP == 'N'));
          }
       }
   }
  
 /*********************** CONSULTA ***********************/
 
 void CONSULTA()
    {
	char OP = 'S' ;
	int TIPO ;
    if  (RAIZ == NULL)
	    {
	    gotoxy(31,22) ; cout << "NO EXISTE ARBOL";
        OP = 'N';
        }
    while ( OP == 'S')
          {
		  system("cls") ;
	      gotoxy(29,6) ; cout << TITULO1;
	      gotoxy(36,7) ; cout << TITULO3;
	      gotoxy(34,11); cout << "1. PREORDEN ";
	      gotoxy(34,12); cout << "2. ENORDEN " ;
	      gotoxy(34,13); cout << "3. POSORDEN ";
	      gotoxy(34,14); cout << "4. ANCHURA ";
	      gotoxy(34,16); cout << "5. SALIR ";
	      do {
		     gotoxy(22,19); cout << "SELECIONE UNA DE LAS ALTERNATIVAS ";
	         cin >> TIPO ;
	      } while ((TIPO < 1) || (TIPO > 5)) ;
	      system("cls") ;
	      gotoxy(29,6) ; cout << TITULO1;
	      gotoxy(36,7) ; cout << TITULO3;
	      switch ( TIPO ) {
		      case  1 : gotoxy(36,9); cout << "PREORDEN" ;
	                	gotoxy(5,12);
		                PREORDEN( RAIZ) ;
		                getch();
		                break;
	          case 2 :  gotoxy(36,9); cout << "ENORDEN" ;
                        gotoxy(5,12);
                        ENORDEN( RAIZ ) ;
                        getch() ;
                        break;
              case 3 :  gotoxy(36,9); cout << "POSORDEN";
                        gotoxy(5,12);
                        POSORDEN( RAIZ) ;
                        getch() ;
                        break;
              case 4 :  gotoxy(36,9); cout << "ANCHURA";
                        gotoxy(5,12);
                        ANCHURA( RAIZ) ;
                        getch() ;
                        break;          
              case 5 :  OP = 'N' ;
             }
          }
    } 
    
/******************	RECORRIDO PREORDEN ********************/

 void PREORDEN( NODO *R )
    {
	if  ( R != NULL )
        {
		cout << R -> INFO << "   ";
	    PREORDEN( R -> IZQ);
	    PREORDEN( R -> DER);
        }
    }
    
/******************	RECORRIDO ENORDEN ********************/

 void ENORDEN( NODO *R )
    {
	if  ( R != NULL )
	    {
		ENORDEN(R -> IZQ);
	    cout << R -> INFO << "    " ;
	    ENORDEN(R -> DER) ;
    	}
    }
    
/******************	RECORRIDO POSORDEN ********************/

 void POSORDEN( NODO *R )
    {
	if  ( R != NULL )
        {
	    POSORDEN(R -> IZQ);
	    POSORDEN(R -> DER);
	    cout <<  R -> INFO << "    ";
	    }
    }



/******************	RECORRIDO ANCHURA ********************/

void ANCHURA(NODO *R)
   {
   int I = 0;
   NODO *ACT = NULL;

   if (R != NULL)
      {
      COLA[I]=R, COLA[I+1] = NULL, I++ ;    /// ENCOLAR
      while ( COLA[0]!=NULL )
          {
          ACT = COLA[0];
          for (int J = 0; J < I; J++)
              COLA[J] = COLA[J+1];           /// DESENCOLAR
          I--;
          cout << ACT->INFO << "   ";
          if (ACT->IZQ != NULL)
	         COLA[I] = ACT->IZQ, COLA[I+1] = NULL, I++ ;   /// ENCOLAR
          if (ACT->DER != NULL)
	         COLA[I] = ACT->DER, COLA[I+1] = NULL, I++;   /// ENCOLAR
          }
      }
   }

/******************	PROPIEDADES ********************/

void Propiedades(){
	
	system("cls");
  	system("color F0");
  	gotoxy(30,4);cout << "P R O P I E D A D E S";
  	gotoxy(10,6) ;  cout <<"1. Nodo raiz       = ";
  	gotoxy(31,6) ;  cout <<RAIZ->INFO;
  	gotoxy(10,7) ;  cout <<"2. Nodos hijos     = ";
  	gotoxy(31,7) ;  NodosHijos(RAIZ);
	gotoxy(10,8) ;  cout <<"3. Nodos Padres    = ";
  	gotoxy(31,8) ;  NodosPadres(RAIZ);
  	gotoxy(10,9) ;  cout <<"4. Nodos Hermanos  = ";
  	gotoxy(31,9) ;  NodosHermanos(RAIZ);
  	gotoxy(10,10) ; cout <<"5. Nodos Hojas     = ";
  	gotoxy(31,10) ; NodosHojas(RAIZ);
  	gotoxy(10,11) ; cout <<"6. Nodos Interior  = ";
  	gotoxy(31,11) ; NodosInterior(RAIZ);
  	gotoxy(10,12) ; cout <<"7. Grado de un nodo= ";
  	gotoxy(31,12) ; GradoNodo(RAIZ);
  	gotoxy(10,14) ; cout <<"--Grado de un Arbol= ";
  	gotoxy(31,14) ; cout<<maximo;
  	gotoxy(10,15) ; cout <<"8. Nivel de un nodo= ";
  	gotoxy(31,15) ; NivelNodos(RAIZ);
  	gotoxy(10,17) ; cout <<"9. Altura del arbol= ";
  	gotoxy(31,17) ; cout<<maximoNivel; 
  	gotoxy(10,18) ; cout <<"10. Peso del arbol = ";
  	gotoxy(31,18) ; cout<<peso;
  	gotoxy(20,24); cout << "PULSE CUALQUIER TECLA Y REGRESA AL MENU";
  	getch();
}

void NodosHijos(NODO *R)
   {
   if ( R != NULL )
      {
      if (R != RAIZ)
	     {
	     cout << R -> INFO << " ";
		 }
	    NodosHijos(R -> IZQ);
	   	NodosHijos(R -> DER);
      }
   }

void NodosPadres(NODO *R)
   {
   if ( R != NULL )
      {
      NodosPadres(R -> IZQ);
	  NodosPadres(R -> DER);
      if ((R->IZQ || R->DER) != NULL)
	     {
	     cout << R -> INFO << " ";
		 }
      }
   }

void NodosHojas(NODO *R)
   {
   if ( R != NULL )
      {
      NodosHojas(R -> IZQ);
	  NodosHojas(R -> DER);
      if (R->IZQ == NULL)
	     {
    	 if (R->DER == NULL)
		    {
    		cout << R -> INFO << " ";
    		peso++;
			}
		 }			
	  }
   }

void NodosInterior(NODO *R)
   {
   if ( R != NULL )
      {
      NodosInterior(R -> IZQ);
	  NodosInterior(R -> DER);
      if ((R->IZQ || R->DER) != NULL)
	     {
	     if (R != RAIZ)
		    {
	    	cout << R -> INFO << " ";
			}
		 }
      }
   }

void NodosHermanos(NODO *R)
   {
   if ( R != NULL )
      {
      NodosHermanos(R -> IZQ);
	  NodosHermanos(R -> DER);
      if ((R->IZQ && R->DER) != NULL)
	     {
    	 cout<<"(";
	     cout << R->IZQ->INFO << " ";
	     cout << R->DER->INFO << " ";
	     cout<<")";
		 }
      }
   }

void GradoNodo(NODO *R)
   {
   int grado =0;
   maximo=0;
   if ( R != NULL )
      {
      GradoNodo(R -> IZQ);
	  GradoNodo(R -> DER);
	  if ((R->IZQ || R->DER) != NULL)
	     {
	     grado=1;
	     maximo=1;
		 }
      if (R->IZQ != NULL)
	     {
    	 if (R->DER != NULL)
    		grado=2;
	     maximo=2;
		 }
	  cout << "G(" << R -> INFO << ")="<<grado<<", ";			
      }
   }

void NivelNodos(NODO *R)
   {
   if ( R != NULL )
      {
      nivel++;
      cout <<"N(" << R -> INFO << ")= "<<nivel<<", ";
      NivelNodos(R -> IZQ);
      NivelNodos(R -> DER);
      if (maximoNivel<=nivel)
	     {
     	 maximoNivel=nivel;
		 }
      nivel--;
	  }
   }


