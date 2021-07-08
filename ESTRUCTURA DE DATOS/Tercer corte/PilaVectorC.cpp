/**********************
 *                                                                 *  
 *  CREAR Y/O ADICIONAR, CONSULTAS, MODIFICAR Y ELIMINAR Y EN UNA  *
 *  PILA CON LISTAS LINEALES ESTATICAS - ARREGLOS                  *
 *                                                                 *
 *  AUTOR : CARLOS O?ATE GOMEZ       ESTRUCTURA DE DATOS           *      
 *                                                                 *      
 ***********************/
                     
#include <windows.h>                      
#include <iostream>                      
#include <conio.h>                       

using namespace std;                     

int gotoxy(USHORT x,USHORT y){                                  
COORD cp={x,y};                                                 
SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),cp);   // sentencia gotoxy
}

/******* DECLARACION DE CONSTANTES********/ 

#define  TITULO   "ESTRUCTURAS LINEALES : PILAS";
#define  TITULO1  "CAPTURA DE DATOS" ;
#define  TITULO2  "CONSULTA TOTAL REGISTRO POR PANTALLA" ;
#define  TITULO3  "CONSULTA TIPO LISTADO" 
#define  TITULO4  "ELIMINAR";
#define  TITULO5  "MODIFICAR";

/******* DECLARACION DE FUNCIONES *******/ 

int MENU();
void CAPTURA();
void CONSULTA_UNO_X_PANTALLA();
void CONSULTA_LISTADO();
void ELIMINAR();
void MODIFICAR(void);
void CAMBIAR(int K);
void DETALLE();

/******* DECLARACION DE LA ESTRUCTURA********/ 

struct CAMPOS {
   long CEDULA ;
   char NOMBRE[30];
   unsigned TEL;
   char SEXO;
   } ;
   
 /***** DECLARACION DEL ARREGLO DE REGISTROS******/ 
   
  CAMPOS PILA[50];
  int   TOPE = -1; 

/***** PROGRAMA PRINCIPAL *********/

 main()
    {
    char OP = 'S';
    int  OPCION ;
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
 // ******** MENU **********   
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
   gotoxy(29,15); cout << "5. MODIFICAR ";
   gotoxy(29,17); cout << "6. SALIR";
   do {
      gotoxy(26,19); cout << "SELECIONE UNA DE LAS ALTERNATIVAS : ";
      cin >> OP ;
      gotoxy(30,22); cout << "VALOR FUERA DE RANGO";
   } while((OP < 1) || (OP > 6)) ;
   gotoxy(30,22); cout << "                          ";
   return OP ;
   }   
    
/******* FUNCION CAPTURA *********/ 
    
  void CAPTURA()
    {
    char  OP = 'S';
    while ((OP == 'S') && ( TOPE < 50))
        {
        system("cls");
        gotoxy(26,6) ; cout << TITULO;
        gotoxy(32,8) ; cout << TITULO1;
        gotoxy(20,11); cout <<"CEDULA   : ";
        gotoxy(20,13); cout <<"NOMBRE   : ";
        gotoxy(20,15); cout <<"TELEFONO : ";  
        gotoxy(20,17) ;cout <<"SEXO     : ";
        TOPE = TOPE + 1 ;
        do {
		   gotoxy(31,11) ; cin >>PILA[TOPE].CEDULA ;
		   gotoxy(22,24); cout<< "Error .... valor fuera de rango ";
	    } while (( PILA[TOPE].CEDULA <= 0) || (PILA[TOPE].CEDULA > 2147483640));
        gotoxy(22,24); cout <<"                                   ";
        cin.sync();
	    gotoxy(31,13); gets( PILA[TOPE].NOMBRE);
	    do {
	       gotoxy(31,15); cin >> PILA[TOPE].TEL ;
	       gotoxy(22,24); cout << "Error .... valor fuera de rango ";
        } while(( PILA[TOPE].TEL < 0 ) || (PILA[TOPE].TEL > 4000000000)) ;
        gotoxy(22,24); cout << "                                 ";
        do {
           gotoxy(31,17); cout<< " " ;
           gotoxy(20,24); cout << " Digite : M-> Masculino o F -> Femenino " ;
           gotoxy(31,17); PILA[TOPE].SEXO = getche();
           PILA[TOPE].SEXO = toupper(PILA[TOPE].SEXO) ;
        } while ((PILA[TOPE].SEXO != 'M') && ( PILA[TOPE].SEXO != 'F'));
   	    gotoxy(20,24); cout <<"                                              ";
        do {
		   gotoxy(28,22); printf("DESEA CONTINUAR - S/N - ");
		   OP = getch();
		   OP = toupper(OP);
		} while ((OP != 'S' ) && ( OP != 'N'));
     }
   }
   
 /****** FUNCION CONSULTA_UNO_X_PANTALLA ********/ 
   
   void CONSULTA_UNO_X_PANTALLA()
      {
      int P = TOPE;
	  char OPCION = 'S' ;
	  if  (TOPE < 0)
		  {
		  gotoxy (20,24); cout << "No hay datos ";
		  OPCION = 'N'; getch();
		  }
		else
		  {
		  while ( (OPCION == 'S' ) &&( P >= 0 ))
		    {
		    system("cls");
            gotoxy(26,6);  cout << TITULO;
            gotoxy(22,8);  cout << TITULO2;
		    gotoxy(20,11); cout << "CEDULA   = " << PILA[P].CEDULA;
		    gotoxy(20,13); cout << "NOMBRE   = " << PILA[P].NOMBRE;
		    gotoxy(20,15); cout << "TELEFONO = " << PILA[P].TEL  ;
		    gotoxy(20,17); cout << "SEXO     = " << PILA[P].SEXO  ;
            P = P - 1;
		    do {
		       gotoxy(26,20); printf("DESEA CONTINUAR - S/N - ");
			   OPCION = getch();
			   OPCION = toupper(OPCION);
		    } while (( OPCION != 'S' ) && ( OPCION != 'N'));
		   }
	     }	
      }
  
 /******* FUNCION CONSULTA LISTADO ********/  
    
 void CONSULTA_LISTADO() 
     {
     int P, F ;
	 if  (TOPE < 0)
		 {
		 gotoxy (20,24); cout << "No hay Pila ";
         getch();
		 }
	   else
	     {
	     F = 10;
	     DETALLE();
	     for ( P = TOPE ; P >= 0 ; P-- )
	         {
	         gotoxy(12,F); cout << PILA[P].CEDULA;
	         gotoxy(24,F); cout << PILA[P].NOMBRE;
	         gotoxy(55,F); cout << PILA[P].TEL  ;
	         gotoxy(68,F); cout << PILA[P].SEXO  ;
	         if ( F <= 25 )
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
    
/******* FUNCION ELIMINAR *********/ 
  
  void ELIMINAR()
      {
      char OP = 'S' ;
      while ((OP == 'S' )) 
	       {
		   if  (TOPE < 0)
		       {
		       gotoxy (20,24); cout << "No hay Pila ";
		       OP = 'N'; getch();
		       }
		     else
		       {
		       system("cls");
               gotoxy(26,6);  cout << TITULO;
               gotoxy(35,8);  cout << TITULO4;
		       gotoxy(20,11); cout << "CEDULA   = " << PILA[TOPE].CEDULA ;
		       gotoxy(20,13); cout << "NOMBRE   = " << PILA[TOPE].NOMBRE;
		       gotoxy(20,15); cout << "TELEFONO = " << PILA[TOPE].TEL  ;
		       gotoxy(20,17); cout << "SEXO     = " << PILA[TOPE].SEXO  ;
		       TOPE = TOPE - 1 ;
		       gotoxy(45,11) ; cout << "Listo quedo Eliminado";      
		        do {
		           gotoxy(26,20); printf("DESEA CONTINUAR - S/N - ");
			       OP = getch();
			       OP = toupper(OP);
		        } while (( OP != 'S' ) && ( OP != 'N'));
		      }
		    }	
      }
      
 // ******* MODIFICAR ********     
      
 void MODIFICAR(void)
     {
     int P, SW ;
     char OPCION = 'S' ;
     long CED ;
     if  (TOPE < 0)
          {
          gotoxy (20,24); cout << "No hay Pila ";
          getch();
          }
        else
          {
          while (OPCION == 'S' )
             {
	    	 system("cls");
             gotoxy(29,5);  cout <<  TITULO ;
	         gotoxy(36,6);  cout <<  TITULO5 ;
	         gotoxy(20,11); cout << "CEDULA   : ";
	         cin.sync();
	         do {
	            gotoxy(31,11) ; cin >> CED ;
	            gotoxy(20,24); cout<< "Error .... valor fuera de rango ";
             } while (( CED < 0 ) || ( CED > 2147483640));
	         gotoxy(20,24); cout << "                                   ";
	         SW = 0;
	         for (P = TOPE ; TOPE >= 0 && SW == 0 ; P--)
	           if (CED == PILA[P].CEDULA )
     	          {
     	          SW = 1;
		          gotoxy(20,13); cout << "NOMBRE   = " << PILA[P].NOMBRE;
		          gotoxy(20,15); cout << "TELEFONO = " << PILA[P].TEL   ;
		          gotoxy(20,17); cout << "SEXO     = " << PILA[P].SEXO  ;
		          CAMBIAR(P);
	              gotoxy(50,11); cout << "REGISTRO MODIFICADO";
                  }
                if (SW == 0)
                   {
                   gotoxy(50,11) ; cout << "NO EXISTE REGISTRO" ;
                   }
                do {
                   gotoxy(28,24); printf("DESEA CONTINUAR - S/N - ");
                   OPCION = getch();
	               OPCION = toupper(OPCION);
	            } while (( OPCION != 'S' ) && ( OPCION != 'N'));
	         }
         }
   }  
    
 /************ CAMBIAR *************/ 
 
 void CAMBIAR(int K)
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
		        gotoxy(31,13); gets( PILA[K].NOMBRE);
                gotoxy(31,13); cout << strupr(PILA[K].NOMBRE);
	           	break;
		case 2: do {
			       gotoxy(31,15) ; cout <<"           " ;
			       gotoxy(31,15); cin >> PILA[K].TEL ;
                   gotoxy(20,24); cout<< "Error .... valor fuera de rango ";
                } while ( PILA[K].TEL < 0 );
                gotoxy(20,24); cout <<"                                   ";
		        break;
		case 3: do {
                   gotoxy(31,17) ; cout << "  ";
                   gotoxy(20,24); cout << " Digite : M-> Masculino o F -> Femenino " ;
                   gotoxy(31,17); PILA[K].SEXO = getche();
                   PILA[K].SEXO = toupper( PILA[K].SEXO) ;
                } while ((PILA[K].SEXO != 'M') && ( PILA[K].SEXO != 'F'));
		        gotoxy(20,24); cout << "                                           ";
				break;
		}
   gotoxy(20,21);cout<<"                                                                                     ";
  }	
    

/******* FUNCION DETALLE *********/
    
 
 void DETALLE()
   {
   system("cls");
   gotoxy(26,3) ; cout << TITULO;
   gotoxy(29,5) ; cout << TITULO3;
   gotoxy(12,8) ; printf("CEDULA      NOMBRE                         TELEFONO     SEXO ");
   }
