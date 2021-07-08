/***********************
 *                                                                 *  
 *  CREAR Y/O ADICIONAR, CONSULTAS, MODIFICAR Y ELIMINAR EN        *
 *  UNA PILA, CON LISTAS ENLAZADA                                  *
 *                                                                 *
 *  AUTOR : CARLOS O?ATE GOMEZ       ESTRUCTURA DE DATOS           *      
 *                                                                 *      
 ***********************/
#include <iostream>
#include <conio.h>
#include <windows.h>

using namespace std;

int gotoxy(USHORT x,USHORT y){                                  
COORD cp={x,y};                                                 
SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),cp);   
}

#define  TITULO   "ESTRUCTURAS LINEALES : PILAS";
#define  TITULO1  "CAPTURA DE DATOS" ;
#define  TITULO2  "CONSULTA TOTAL REGISTRO POR PANTALLA" ;
#define  TITULO3  "CONSULTAL TIPO LISTADO" 
#define  TITULO4  "ELIMINAR";
#define  TITULO6  "MODIFICAR";

struct PILA {
       long   CEDULA ;
       char   NOMBRE[30];
       unsigned TEL;
       char     SEXO;
       PILA *SIG;
       };

int MENU();
void CAPTURA();
void CONSULTA_UNO_X_PANTALLA();
void CONSULTA_LISTADO();
void ELIMINAR();
void  MODIFICAR();
void  CAMBIAR( PILA *K);
void DETALLE();

PILA  *TOPE ;

/***** PROGRAMA PRINCIPAL *********/

 main()
    {
    char OP = 'S';
    int  OPCION ;
    TOPE  = NULL ;
    while ( OP == 'S')
        {
        OPCION = MENU();
        switch   (OPCION)  {
            case 1 : CAPTURA();
                     break;
            case 2 : CONSULTA_UNO_X_PANTALLA();
                	 break;
            case 3 : CONSULTA_LISTADO();
                	 break;    	 
            case 4 : ELIMINAR();
                     break;
            case 5 : MODIFICAR();
		             break;
		    case 6 : OP = 'N';
           };
       }
    }

 int MENU()
   {
   int OP ;
   system("cls");
   system("color F1");
   gotoxy(26,6) ; cout << TITULO;
   gotoxy(36,8) ; cout << "M E N U";
   gotoxy(29,11); cout << "1. CAPTURA" ;
   gotoxy(29,12); cout << "2. CONSULTA TOTAL REGISTRO POR PANTALLA";
   gotoxy(29,13); cout << "3. CONSULTA TOTAL TIPO LISTADO";
   gotoxy(29,14); cout << "4. ELIMINAR ";
   gotoxy(29,15); cout << "5. MODIFICAR";
   gotoxy(29,17); cout << "6. SALIR";
   do  {
        gotoxy(26,20); cout << "SELECIONE UNA DE LAS ALTERNATIVAS : ";
        cin >> OP ;
        gotoxy(30,22); cout << "VALOR FUERA DE RANGO";
   }  while((OP < 1) || (OP > 6)) ;
   gotoxy(30,22); cout << "                          ";
   return OP ;
   }

 void CAPTURA()
    {
    PILA  *P ;
    char  OP = 'S';
    while  (OP == 'S')
        {
        system("cls");
        gotoxy(26,6) ; cout << TITULO;
        gotoxy(32,8) ; cout << TITULO1;
        gotoxy(20,11); cout <<"CEDULA   : ";
        gotoxy(20,13); cout <<"NOMBRE   : ";
        gotoxy(20,15); cout <<"TELEFONO : ";
        gotoxy(20,17); cout <<"SEXO     : ";
        P = new  PILA;
       if  ( P == NULL )
           {
           gotoxy(25,22); cout << "NO HAY ESPACIO DE MEMORIA PARA ASIGNAR";
           getch(); OP = 'N';
           }
         else
           {
           do  {
	           gotoxy(31,11); cin >> P->CEDULA ;
	           gotoxy(22,24); cout << "VALOR FUERA DE RANGO";
           }  while((P->CEDULA < 0) || (P->CEDULA > 999999999)) ;
           gotoxy(22,24); cout << "                        ";
           cin.sync();
           gotoxy(31,13); gets(P->NOMBRE);
           do {
	          gotoxy(31,15); cin >> P->TEL ;
	          gotoxy(22,24); cout << "VALOR FUERA DE RANGO";
           } while((P->TEL < 0) || (P->TEL > 4000000000)) ;
           gotoxy(22,24); cout << "                       ";
           do {
              gotoxy(31,17); cout<< " " ;
              gotoxy(20,24); cout << " Digite : M-> Masculino o F -> Femenino " ;
              gotoxy(31,17); cin >> P ->SEXO ;
              P -> SEXO = toupper( P->SEXO) ;
           } while (( P->SEXO != 'M') && ( P->SEXO != 'F'));
   	       gotoxy(20,24); cout <<"                                              ";
           if  (TOPE  == NULL)
	           P -> SIG  =  NULL ;
	         else
	           P -> SIG = TOPE;
           TOPE  =  P;
           do  {
	           gotoxy(29,20); cout <<"DESEA CONTINUAR S/N : ";
	           OP = getche();
	           OP = toupper(OP);
           }    while((OP != 'S') && (OP != 'N'));
          }
       }
   }


 void  CONSULTA_UNO_X_PANTALLA()
     {
     char  OP = 'S' ;
     PILA  *P = TOPE;
     if  ( TOPE == NULL)
         {
         gotoxy(22,24); cout << " NO EXISTE PILA";
         OP = 'N'; getch();
         }
     gotoxy(22,24) ; cout << "                      ";
     while  ((  P != NULL) && (OP == 'S'))
         {
         system("cls") ;
         gotoxy(26,6) ; cout << TITULO;
         gotoxy(22,8) ; cout << TITULO2;
         gotoxy(20,11); cout <<"CEDULA   : " << P->CEDULA;
         gotoxy(20,13); cout <<"NOMBRE   : " << P->NOMBRE;
         gotoxy(20,15); cout <<"TELEFONO : " << P->TEL;
         gotoxy(20,17); cout <<"SEXO     : " << P->SEXO;
         P = P-> SIG ;
         do  {
             gotoxy(29,20); cout <<"DESEA CONTINUAR S/N : ";
             OP = getche();
             OP = toupper(OP);
         }  while((OP != 'S') && (OP != 'N'));
       }
    }
    

 void CONSULTA_LISTADO()
    {
    PILA *P = TOPE;
    int F ;
    if (TOPE == NULL)
        {
        gotoxy(22,24); cout << " NO EXISTE PILA";
        getch();
        }
      else
        {
        F = 10;
	    DETALLE();
		while ( P != NULL)         
		      {
		      gotoxy(12,F); cout << P -> CEDULA;
		      gotoxy(24,F); cout << P -> NOMBRE;
		      gotoxy(55,F); cout << P -> TEL ;
		      gotoxy(68,F); cout << P -> SEXO ;
		      P = P -> SIG ;
		      if  ( F <= 24 )
		          F++ ;
		        else
		          {
		          gotoxy(21,F+=3); cout << "Pulse Cualquier tecla para Continuar";
		          getch();
		          F = 10 ;
		          DETALLE();
		          }
		      }
		gotoxy(21,F+=3); cout << "Pulse Cualquier tecla para Continuar";
		getch();
	    }	
   }
  
 void  ELIMINAR()
     {
     PILA  *P  ;
     char  OP = 'S';
     while  (OP == 'S')
         {
         if  ( TOPE == NULL)
             {
	         gotoxy(22,24); cout << " NO EXISTE PILA";
	         OP = 'N' ; getch() ;
	         }
           else
	         {
	         P = TOPE;
	         system("cls");
	         gotoxy(26,6) ; cout << TITULO;
	         gotoxy(35,8) ; cout << TITULO4;
	         gotoxy(20,11); cout << "CEDULA   : " << P->CEDULA ;
	         gotoxy(20,13); cout << "NOMBRE   : " << P->NOMBRE;
	         gotoxy(20,15); cout << "TELEFONO : " << P->TEL;
	         gotoxy(20,17); cout << "SEXO     : " << P->SEXO;
             gotoxy(45,11); cout <<"Listo quedo Eliminado";
	         TOPE = TOPE -> SIG ;
	         delete(P);
	         do  {
	             gotoxy(26,20); cout <<"DESEA CONTINUAR S/N : ";
	             OP = getche();
	             OP = toupper(OP);
	         }  while((OP != 'S') && (OP != 'N'));
           }
        }
    }

// ******** FUNCION MODIFICAR *******
 
void MODIFICAR()
  {
  char OP = 'S' ;
  long CED ;
  int SW ;
  PILA *P = TOPE;
  if ( TOPE == NULL)
     {
     gotoxy(22,24); cout << " NO EXISTE PILA";
     OP = 'N'; getch();
     }
    else
     {
     while ( OP == 'S')
       {
	   P = TOPE;
	   system("cls");
	   gotoxy(26,5) ; cout << TITULO;
	   gotoxy(31,7) ; cout << TITULO3;
	   gotoxy(20,11); cout << "CEDULA   : ";
	   do {
	      gotoxy(31,11); cin >> CED ;
	      gotoxy(22,24); cout << "VALOR FUERA DE RANGO";
	   } while((CED < 0) || (CED > 999999999)) ;
	   gotoxy(22,24); cout << "                        ";
	   SW = 0;
	   while ((P != NULL) && (SW == 0))
	      {
	      if ( CED == P->CEDULA)
	         {
	         SW = 1;
	         gotoxy(20,11); cout <<"CEDULA   : " << P->CEDULA;
             gotoxy(20,13); cout <<"NOMBRE   : " << P->NOMBRE;
             gotoxy(20,15); cout <<"TELEFONO : " << P->TEL;
             gotoxy(20,17); cout <<"SEXO     : " << P->SEXO;
             CAMBIAR(P);
             gotoxy(50,11); cout << "REGISTRO MODIFICADO";
             }
	       else
	         P  = P->SIG ;
	      }
	      if  (SW == 0)
	          {
	          gotoxy(50,11); cout << "ELEMENTO NO ENCONTRADO";
	          }
	      do {
	         gotoxy(29,20); cout <<"DESEA CONTINUAR S/N : ";
	         OP = getche();
	         OP = toupper(OP);
	      } while((OP != 'S') && (OP != 'N'));
	     }
      }
  }
  
 // ********* FUNCION CAMBIAR ********
  
 void CAMBIAR( PILA *K)
    {
   	int OP = 1,F = 13;
	char TECLA;
	gotoxy(20,21);cout<<"UTILICE : Flechas Abajo y Arriba Para Desplazarse, ENTER para seleccionar y Terminar";
	do {
	   gotoxy(31,F); TECLA = getch();
	   if ( kbhit()) 
	      {	
		  TECLA = getch();
		  if (TECLA == 80)    // Baja
		     {
		     OP++;
		     F+=2;
		     }
		  if (TECLA == 72)   // Sube
			 {
			 OP--;
		     F-=2;
		     }
		  if ((OP > 3) ||  (OP < 1))
			 {
			 OP = 1;
		     F = 13;
			} 
		  }
	} while ((TECLA == 80) ||(TECLA == 72)) ; 
		
	switch (OP){ 
	    case 1: cin.sync();
		        gotoxy(31,13); cout << "                                ";
		        gotoxy(31,13); gets( K ->NOMBRE);
                gotoxy(31,13); cout << strupr( K -> NOMBRE);
	           	break;
		case 2: do {
			       gotoxy(31,15) ; cout <<"           " ;
			       gotoxy(31,15); cin >> K -> TEL ;
                   gotoxy(20,24); cout<< "Error .... valor fuera de rango ";
                } while ( K -> TEL < 0 );
                gotoxy(20,24); cout <<"                                   ";
		        break;
		case 3: do {
                   gotoxy(31,17) ; cout << "  ";
                   gotoxy(20,24); cout << " Digite : M-> Masculino o F -> Femenino " ;
                   gotoxy(31,17); cin >> K -> SEXO;
                   K -> SEXO = toupper ( K -> SEXO) ;
                } while (( K -> SEXO != 'M') && ( K -> SEXO != 'F'));
		        gotoxy(20,24); cout << "                                           ";
				break;
		}
   gotoxy(20,21);cout<<"                                                                                     ";
  }	
 
// ********* FUNCION DETALLE ********

void DETALLE()
   {
   system("cls") ;
   gotoxy(26,3) ; cout << TITULO;
   gotoxy(29,5) ; cout << TITULO3;
   gotoxy(12,8) ; printf("CEDULA      NOMBRE                         TELEFONO     SEXO ");
   }
