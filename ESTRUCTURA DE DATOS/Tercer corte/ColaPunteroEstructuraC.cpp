/**********************
 *                                                                 *  
 *  CREAR Y/O ADICIONAR, CONSULTAS, ELIMINAR Y MODIFICAR EN UNA    *
 *  COLA CON LISTAS LINEALES ESTATICAS - ARREGLOS                  *
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
SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),cp);   
}

/***** DECLARACION DE CONSTANTES ******/ 

#define  TITULO   "ESTRUCTURAS LINEALES : COLAS";
#define  TITULO1  "CAPTURA" ;
#define  TITULO2  "CONSULTA TOTAL REGISTRO POR PANTALLA" ;
#define  TITULO3  "CONSULTA TOTAL TIPO LISTADO" ;
#define  TITULO4  "CONSULTA SELECTIVA" ;
#define  TITULO5  "ELIMINAR";
#define  TITULO6  "MODIFICAR";

/****** DECLARACION DE FUNCIONES *******/ 

int MENU();
void CAPTURA();
void CONSULTA_UNO_X_PANTALLA();
void CONSULTA_LISTADO();
void CONSULTA_SELECTIVA();
void ELIMINAR();
void MODIFICAR(void);
void CAMBIAR(int K);
void DETALLE();

/****** DECLARACION DE ESTRUCTURA *******/ 

struct CAMPOS {
   long CEDULA ;
   char NOMBRE[30];
   unsigned TEL;
   char SEXO;
   }  ;
   
 /***** DECLARACION DEL ARREGLO DE REGISTRO *****/ 
  
  CAMPOS COLA[50];
  int   FRENTE , FINAL = -1; 

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
            case 4 : CONSULTA_SELECTIVA();
                     break;
            case 5 : ELIMINAR();
                     break;
            case 6 : MODIFICAR();
                     break;
            case 7 : OP = 'N';
           };
       }
    }
    
 /******* FUNCION MENU ********/ 
    
 int MENU()
   {
   int OP ;
   system("cls");
   system("color F1");
   gotoxy(26,6) ; cout << TITULO;
   gotoxy(36,8) ; cout << "M E N U";
   gotoxy(27,11); cout << "1. CAPTURA DE DATOS" ;
   gotoxy(27,12); cout << "2. CONSULTA  TOTAL REGISTRO POR PANTALLA";
   gotoxy(27,13); cout << "3. CONSULTA  TOTAL TIPO LISTADO";
   gotoxy(27,14); cout << "4. CONSULTA SELECTIVA";
   gotoxy(27,15); cout << "5. ELIMINAR ";
   gotoxy(27,16); cout << "6. MODIFICAR ";
   gotoxy(27,18); cout << "7. SALIR";
   do  {
        gotoxy(26,20); cout << "SELECIONE UNA DE LAS ALTERNATIVAS : ";
        cin >> OP ;
        gotoxy(22,24); cout << "VALOR FUERA DE RANGO";
   }  while((OP < 1) || (OP > 7)) ;
   gotoxy(22,24); cout << "                          ";
   return OP ;
   }   
   
/******* FUNCION CAPTURA *********/  
    
 void CAPTURA()
    {
    char  OP = 'S';
    while ((OP == 'S') && ( FINAL < 50))
        {
        system("cls");
        gotoxy(26,6) ; cout << TITULO;
        gotoxy(36,8) ; cout << TITULO1;
        gotoxy(20,11); cout <<"CEDULA   : ";
        gotoxy(20,13); cout <<"NOMBRE   : ";
        gotoxy(20,15); cout <<"TELEFONO : ";  
        gotoxy(20,17) ;cout <<"SEXO     : ";
        FINAL = FINAL +1 ;
        do {
		   gotoxy(31,11) ; cin >> COLA[FINAL].CEDULA;
		   gotoxy(22,24); cout<< "Error .... valor fuera de rango ";
	    } while (( COLA[FINAL].CEDULA <= 0) || (COLA[FINAL].CEDULA > 2147483640));
        gotoxy(22,24); cout <<"                                   ";
        cin.sync();
	    gotoxy(31,13); gets( COLA[FINAL].NOMBRE);
	    do {
	       gotoxy(31,15) ; cin >> COLA[FINAL].TEL;
	       gotoxy(22,24); cout<< "Error .... valor fuera de rango ";
	    } while (( COLA[FINAL].TEL < 0) || (COLA[FINAL].TEL > 4000000000));
	    gotoxy(22,24); cout <<"                                   ";
	    do {
           gotoxy(31,17); cout<< " " ;
           gotoxy(20,24); cout << " Digite : M-> Masculino o F -> Femenino " ;
           gotoxy(31,17); COLA[FINAL].SEXO = getche();
           COLA[FINAL].SEXO = toupper(COLA[FINAL].SEXO) ;
        } while ((COLA[FINAL].SEXO != 'M') && ( COLA[FINAL].SEXO != 'F'));
   	    gotoxy(20,24); cout <<"                                              ";
        do {
		   gotoxy(28,22); printf("DESEA CONTINUAR - S/N - ");
		   OP = getch();
		   OP = toupper(OP);
		} while ((OP != 'S' ) && ( OP != 'N'));
     }
   }
 
 //****** CONSULTA TOTAL REGISTRO POR PANTALLA*******
 
 void CONSULTA_UNO_X_PANTALLA()
    {
    char OP = 'S' ;
    if  (FINAL < 0)
	    {
	    gotoxy (20,24); cout << "No hay datos ";
	    OP = 'N'; getch();
	    }
	  else
	     {
	     for ( FRENTE = 0 ; FRENTE <= FINAL && OP == 'S'; FRENTE++ )
	         {
	         system("cls");
             gotoxy(26,6) ; cout << TITULO;
             gotoxy(22,8) ; cout << TITULO2;
             gotoxy(20,11); cout <<"CEDULA : " << COLA[FRENTE].CEDULA;
             gotoxy(20,13); cout <<"NOMBRE : " << COLA[FRENTE].NOMBRE;
             gotoxy(20,15); cout <<"NOTA   : " << COLA[FRENTE].TEL; 
			 gotoxy(20,17); cout <<"SEXO   : " << COLA[FRENTE].SEXO  ;
	         do {
                gotoxy(26,20); cout <<"DESEA CONTINUAR S/N : ";
                OP = getch();
                OP = toupper(OP);
             } while((OP != 'S') && (OP != 'N'));
            }
         }
   }
 
  
 //******* CONSULTA TOTAL TIPO LISTADO *********
 
  void CONSULTA_LISTADO() 
     {
     int  F ;
	 if  (FINAL < 0)
		 {
		 gotoxy (20,24); cout << "No hay datos ";
		 getch();
		 }
	   else
	     {
	     F = 10;
	     DETALLE();
	     for ( FRENTE = 0 ; FRENTE <= FINAL ; FRENTE++ )
	         {
	         gotoxy(12,F); cout << COLA[FRENTE].CEDULA;
	         gotoxy(24,F); cout << COLA[FRENTE].NOMBRE;
	         gotoxy(55,F); cout << COLA[FRENTE].TEL  ;
	         gotoxy(68,F); cout << COLA[FRENTE].SEXO  ;
	         if ( F <= 24 )
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
    
 /******* FUNCION CONSULTA SELECTIVA *******/ 
    
  void CONSULTA_SELECTIVA()
      {
	  long CED;	
	  int SW;
      char OPCION = 'S' ;
	  if  (FINAL < 0)
		  {
		  gotoxy (22,24); cout << "No hay datos ";
		  OPCION = 'N'; getch();
		  }
		else
		  {
		  while (OPCION == 'S' )
		        {
		        system("cls");
                gotoxy(26,6);  cout << TITULO;
                gotoxy(31,8);  cout << TITULO4
		        gotoxy(20,11); cout << "CEDULA   : ";
		        do {
		           gotoxy(31,11) ; cin >> CED ;
		           gotoxy(22,24); cout<< "Error .... valor fuera de rango ";
		        } while (CED < 0 );
		        gotoxy(22,24); cout <<"                                   ";
		        SW = 0;
		        for (FRENTE = 0 ; FRENTE <= FINAL && SW == 0;  FRENTE++ )
		            if (CED == COLA[FRENTE].CEDULA )
		               {
		               gotoxy(20,13); cout << "NOMBRE   = " << COLA[FRENTE].NOMBRE;
		               gotoxy(20,15); cout << "TELEFONO = " << COLA[FRENTE].TEL  ;
		               gotoxy(20,17); cout << "SEXO     = " << COLA[FRENTE].SEXO  ;
		               
                       SW = 1;
		               }
		        if  (SW == 0)
		            {
		            gotoxy(45,11) ; cout << "NO EXISTE REGISTRO" ;
		            }
		        do {
		           gotoxy(26,20); printf("DESEA CONTINUAR - S/N - ");
			       OPCION = getch();
			       OPCION = toupper(OPCION);
		        } while (( OPCION != 'S' ) && ( OPCION != 'N'));
		       }
		 }	
   }
   
 /******* FUNCION ELIMINAR *********/ 
   
  void ELIMINAR()
      {
      char OP = 'S' ;
      while ((OP == 'S' ))   
	       {
		   if  (FINAL < 0)
		       {
		       gotoxy (20,24); cout << "No hay datos ";
		       OP = 'N'; getch();
		       }
		     else
		       {
		       system("cls");
		       FRENTE = 0;
               gotoxy(26,6);  cout << TITULO;
               gotoxy(36,8);  cout << TITULO5;
		       gotoxy(25,11); cout << "CEDULA   = " << COLA[FRENTE].CEDULA ;
		       gotoxy(25,13); cout << "NOMBRE   = " << COLA[FRENTE].NOMBRE;
		       gotoxy(25,15); cout << "TELEFONO = " << COLA[FRENTE].TEL  ;
		       gotoxy(25,17); cout << "SEXO     = " << COLA[FRENTE].SEXO  ;
		       for (FRENTE = 0; FRENTE < FINAL; FRENTE++ )
		           {
		            COLA[FRENTE].CEDULA = COLA[FRENTE + 1].CEDULA;	
		           	strcpy( COLA[FRENTE].NOMBRE, COLA[FRENTE + 1].NOMBRE);
		           	COLA[FRENTE].TEL  = COLA[FRENTE + 1].TEL;
		           	COLA[FRENTE].SEXO = COLA[FRENTE + 1].SEXO;
		           }
               FINAL = FINAL - 1 ;
		       gotoxy(45,11) ; cout << "Listo quedo Eliminado";      
		        do {
		           gotoxy(26,20); printf("DESEA CONTINUAR - S/N - ");
			       OP = getch();
			       OP = toupper(OP);
		        } while (( OP != 'S' ) && ( OP != 'N'));
		      }
		    }	
      }
      
 /******* FUNCION MODIFICAR *********/ 
  
 void MODIFICAR(void)
     {
     int SW ;
     char OPCION = 'S' ;
     long CED ;
     if  (FINAL == 0)
          {
          gotoxy (20,24); cout << "No hay datos ";
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
	            gotoxy(20,24) ; cout<< "Error .... valor fuera de rango ";
             } while (( CED < 0 ) || ( CED > 2147483640));
	         gotoxy(20,24); cout << "                                   ";
	         SW = 0;
	         for (FRENTE = 0 ; FRENTE < FINAL && SW == 0 ; FRENTE ++ )
	           if (CED == COLA[FRENTE].CEDULA )
     	          {
     	          SW = 1;
		          gotoxy(20,13); cout << "NOMBRE   = " << COLA[FRENTE].NOMBRE;
		          gotoxy(20,15); cout << "TELEFONO = " << COLA[FRENTE].TEL   ;
		          gotoxy(20,17); cout << "SEXO     = " << COLA[FRENTE].SEXO  ;
		          CAMBIAR(FRENTE);
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
    
 /********* CAMBIAR *********/ 
 
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
		        gotoxy(31,13); gets( COLA[K].NOMBRE);
                //gotoxy(31,13); strcpy( EMPLEADO[K].NOMBRE , VALCADENA(31,13,30));
                gotoxy(31,13); cout << strupr(COLA[K].NOMBRE);
	           	break;
		case 2: do {
			       gotoxy(31,15) ; cout <<"           " ;
			       gotoxy(31,15); cin >> COLA[K].TEL ;
                   gotoxy(20,24); cout<< "Error .... valor fuera de rango ";
                } while ( COLA[K].TEL < 0 );
                gotoxy(20,24); cout <<"                                   ";
		        break;
		case 3: do {
                   gotoxy(31,17) ; cout << "  ";
                   gotoxy(20,24); cout << " Digite : M-> Masculino o F -> Femenino " ;
                   gotoxy(31,17); COLA[K].SEXO = getche();
                   COLA[K].SEXO = toupper(COLA[K].SEXO) ;
                } while ((COLA[K].SEXO != 'M') && ( COLA[K].SEXO != 'F'));
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
   gotoxy(27,5) ; cout << TITULO3;
   gotoxy(12,8) ; printf("CEDULA      NOMBRE                         TELEFONO     SEXO ");
   }
