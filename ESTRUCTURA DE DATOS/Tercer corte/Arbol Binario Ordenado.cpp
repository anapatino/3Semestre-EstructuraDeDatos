/***************************************************************************
 *                                                                         *
 *   CREAR UN ARBOL BINARIO ORDENADO Y CONSULTARLO EN PREORDEN, ENORDEN,   *
 *   POSTORDEN Y ANCHURA.   PROBLEMA No 5 DEL TALLER No 4                  *             
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

#define  TITULO   "ARBOL BINARIO ORDENADO";
#define  TITULO1  "CAPTURA";
#define  TITULO2  "CONSULTA";

/**************** DECLARACI?N DE LA ESTRUCTURA ***************/

struct NODO {
       int  INFO ;
       NODO *IZQ ;
       NODO *DER ;
       } ;
  
/*****************	DECLARACI?N DE FUNCIONES ***************/

 int MENU();     
 void CAPTURA() ;     
 void CONSULTA() ;
 void PREORDEN( NODO *R ) ;
 void ENORDEN( NODO *R ) ;
 void POSORDEN( NODO *R ) ;
 void ANCHURA(NODO *R);
 
 NODO *COLA[50];
 NODO *RAIZ ;
 
/******************	PROGRAMA PRINCIPAL ********************/    

 main()
   {
   RAIZ = NULL ;
   char  OP = 'S';
   int OPCION;
   while ( OP == 'S' ) 
       {
	   OPCION = MENU();
	   switch (OPCION) {
		   case	1 : CAPTURA();
		            break;
           case 2 : CONSULTA();
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
  
 void CAPTURA()
    {
	NODO *P, *X, *Y ;
	char OP = 'S';
    while (OP == 'S')
	    {
		system("cls");
		system("color F0");
	    gotoxy(29,6) ; cout << TITULO;
	    gotoxy(36,7) ; cout << TITULO1;
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
	      gotoxy(29,6) ; cout << TITULO;
	      gotoxy(36,7) ; cout << TITULO2;
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
	      gotoxy(29,6) ; cout << TITULO;
	      gotoxy(36,7) ; cout << TITULO2;
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



