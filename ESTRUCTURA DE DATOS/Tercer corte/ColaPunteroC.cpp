/**********************
 *                                                              *
 *   CREAR, ADICIONAR, CONSULTAS, MODIFICAR Y ELIMINAR EN UNA   *
 *   COLA, USANDO UNA LISTA SIMPLEMENTE ENLAZADA                *
 *                                                              *
 *   AUTOR : CARLOS O?ATE GOMEZ       ESTRUCTURA DE DATOS       *
 *                                                              *
 **********************/
#include <iostream>
#include <conio.h>
#include <windows.h>

#define  TITULO   "ESTRUCTURAS LINEALES : COLAS";
#define  TITULO1  "CAPTURA" ;
#define  TITULO2  "CONSULTA TOTAL REGISTRO POR PANTALLA" ;
#define  TITULO3  "CONSULTA TOTAL TIPO LISTADO" ;
#define  TITULO4  "CONSULTA SELECTIVA" ;
#define  TITULO5  "ELIMINAR";
#define  TITULO6  "MODIFICAR";

using namespace std;

int gotoxy(USHORT x,USHORT y){                                  
COORD cp={x,y};                                                 
SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),cp);   
}

struct COLA {
       long   CEDULA ;
       char   NOMBRE[30];
       unsigned  TEL;
       char     SEXO;
       COLA *SIG;
       };

int MENU();
void  CAPTURA();
void  CONSULTA_UNO_X_PANTALLA();
void  CONSULTA_LISTADO();
void  CONSULTA_SELECTIVA();
void  ELIMINAR();
void  MODIFICAR();
void  CAMBIAR(COLA *K);
void  DETALLE();

 COLA  *FRENTE, *FINAL ;

 // ******  PRORAMA PRINCIPAL ********

main()
     {
     char OP = 'S';
     int  OPCION ;
     FRENTE = NULL ;
     while ( OP == 'S')
        {
         OPCION = MENU();
         switch (OPCION) {
             case 1 : CAPTURA();
		              break;
             case 2 : CONSULTA_UNO_X_PANTALLA();
		              break;
		     case 3 : CONSULTA_LISTADO();
		              break;         
		     case 4 : CONSULTA_SELECTIVA();
		              break;         
             case 5 : ELIMINAR();
	                  break;
	         case 6 : MODIFICAR();
		              break;
		     case 7 : OP = 'N';
            }
        }
    }

//****** FUNCION MENU *********

int MENU()
  {
  int OP ;
  system("cls");
  system("color F1");
  gotoxy(26,6) ; cout << TITULO;
  gotoxy(37,8) ; cout << "M E N U";
  gotoxy(27,11); cout << "1. CAPTURA" ;
  gotoxy(27,12); cout << "2. CONSULTA TOTAL REGISTRO POR PANTALLA";
  gotoxy(27,13); cout << "3. CONSULTA TOTAL TIPO LISTADO";
  gotoxy(27,14); cout << "4. CONSULTA SELECTIVA";
  gotoxy(27,15); cout << "5. ELIMINAR ";
  gotoxy(27,16); cout << "6. MODIFICAR";
  gotoxy(27,18); cout << "7. SALIR";
  do {
       gotoxy(22,21); cout << "SELECIONE UNA DE LAS ALTERNATIVAS : ";
       cin >> OP ;
       gotoxy(30,24); cout << "VALOR FUERA DE RANGO";
   } while((OP < 1) || (OP > 7)) ;
   gotoxy(30,22); cout << "                          ";
   return OP ;
  }

// ********  FUNCION CREAR Y/O ADICIONAR *******

void CAPTURA()
  {
  COLA *P ;
  char OP = 'S';
  while (OP == 'S')
    {
    system("cls");
    gotoxy(26,5) ; cout << TITULO;
    gotoxy(36,7) ; cout << TITULO1;
    gotoxy(20,11); cout <<"CEDULA   : ";
    gotoxy(20,13); cout <<"NOMBRE   : ";
    gotoxy(20,15); cout <<"TELEFONO : ";
    gotoxy(20,17); cout <<"SEXO     : ";
    P = new COLA;
    if ( P == NULL )
       {
       gotoxy(22,24); cout << "NO HAY ESPACIO DE MEMORIA PARA ASIGNAR";
       getch(); OP = 'N';
       }
     else
       {
       do {
	      gotoxy(31,11); cin >> P->CEDULA ;
	      gotoxy(22,24); cout << "VALOR FUERA DE RANGO";
       } while((P->CEDULA < 0) || (P->CEDULA > 2147483647)) ;
       gotoxy(22,24); cout << "                      ";
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
       P->SIG = NULL ;
 	   if (FRENTE == NULL)
	      FRENTE =  P ;
	    else
	      FINAL->SIG = P;
       FINAL = P;
       do {
	      gotoxy(26,20); cout <<"DESEA CONTINUAR S/N : ";
	      OP = getch();
	      OP = toupper(OP);
       } while((OP != 'S') && (OP != 'N'));
      }
    }
 }
 
 // ******** CONSULTA TOTAL REGISTRO POR PANTALLA ********

void CONSULTA_UNO_X_PANTALLA()
  {
  char OP = 'S' ;
  COLA *P = FRENTE;
  if (FRENTE == NULL)
     {
     gotoxy(22,24); cout << " NO EXISTE COLA";
     OP = 'N'; getch();
     }
  gotoxy(22,24) ; cout << "                  ";
  while (( P != NULL) && (OP == 'S'))
      {
      system("cls") ;
      gotoxy(26,5) ; cout << TITULO;
      gotoxy(22,7) ; cout << TITULO2;
      gotoxy(20,11); cout <<"CEDULA   : " << P->CEDULA;
      gotoxy(20,13); cout <<"NOMBRE   : " << P->NOMBRE;
      gotoxy(20,15); cout <<"TELEFONO : " << P->TEL;
      gotoxy(20,17); cout <<"SEXO     : " << P->SEXO;
      P = P->SIG ;
      do {
         gotoxy(26,20); cout <<"DESEA CONTINUAR S/N : ";
         OP = getch();
         OP = toupper(OP);
      } while((OP != 'S') && (OP != 'N'));
     }
  }

// ******** CONSULTA TOTAL TIPO LISTADO *******

void CONSULTA_LISTADO()
     { 
     COLA *P =  FRENTE;
     int F ;
     if (FRENTE == NULL)
        {
        gotoxy(22,24); cout << " NO EXISTE COLA";
        getch();
        }
      else
        {
        system("cls") ;
        gotoxy(26,3) ; cout << TITULO;
        gotoxy(27,5) ; cout << TITULO3;
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
   

// ********* CONSULTA SELECTIVA ***********

 void CONSULTA_SELECTIVA()
  {
  char OP = 'S' ;
  long CED ;
  int SW ;
  COLA *P = FRENTE;
  if ( FRENTE == NULL)
     {
     gotoxy(22,24); cout << " NO EXISTE LISTA";
     OP = 'N'; getch();
     }
    else
      {
      while ( OP == 'S')
        {
	    P = FRENTE;
	    system("cls");
	    gotoxy(26,5) ; cout << TITULO;
	    gotoxy(31,7) ; cout << TITULO4;
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
	         gotoxy(20,13); cout <<"NOMBRE   : " << P->NOMBRE;
             gotoxy(20,15); cout <<"NOTA     : " << P->TEL;
             gotoxy(20,17); cout <<"SEXO     : " << P->SEXO;
             }
	      else
	         P  = P->SIG ;
	      }
	      if (SW == 0)
	         {
	         gotoxy(45,11); cout << "ELEMENTO NO ENCONTRADO";
	         }
	      do {
	         gotoxy(26,20); cout <<"DESEA CONTINUAR S/N : ";
	         OP = getche();
	         OP = toupper(OP);
	      } while((OP != 'S') && (OP != 'N'));
	     }
      }
  }


// ********* FUNCION ELIMINAR ***********

void  ELIMINAR()
     {
     COLA  *P  ;
     char  OP = 'S';
     while  (OP == 'S')
         {
         if  ( FRENTE == NULL)
             {
	         gotoxy(22,24); cout << " NO EXISTE COLA";
	         OP = 'N' ; getch() ;
	         }
           else
	         {
	         P = FRENTE;
	         system("cls");
	         gotoxy(26,5) ; cout << TITULO;
	         gotoxy(36,7) ; cout << TITULO5;
	         gotoxy(20,11); cout <<"CEDULA   : " << P->CEDULA ;
	         gotoxy(20,13); cout <<"NOMBRE   : " << P->NOMBRE;
	         gotoxy(20,15); cout <<"TELEFONO : " << P->TEL;
	         gotoxy(20,17); cout <<"SEXO     : " << P->SEXO;
             gotoxy(45,11); cout <<"Listo quedo Eliminado"; ;
	         FRENTE = FRENTE -> SIG ;
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
  COLA *P = FRENTE;
  if (FRENTE == NULL)
     {
     gotoxy(22,24); cout << " NO EXISTE LISTA";
     OP = 'N'; getch();
     }
    else
     {
     while ( OP == 'S')
       {
	   P = FRENTE;
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
  
 void CAMBIAR( COLA *K)
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
    gotoxy(12,8) ; printf("CEDULA      NOMBRE                         TELEFONO     SEXO ");
   }
