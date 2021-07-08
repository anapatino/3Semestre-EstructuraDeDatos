 
#include <stdio.h>                       
#include <windows.h>                      
#include <iostream>                      
#include <conio.h>                       
#include <ctype.h>
#include<ctime>  
#include<stdlib.h>  
#include <cstring>

using namespace std;                     

int gotoxy(USHORT x,USHORT y){                                  
COORD cp={x,y};                                                 
SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),cp);   // sentencia gotoxy
}

#define  TITULO  "FRIGORIFICO DE CARNES DE RES CAMAGUEY";
#define  TITULO1 "CAPTURA DE DATOS " ;
#define  TITULO2 "CONSULTA TIPO LISTADO DE TODAS LAS RESES" ;
#define  TITULO3 "CONSULTA DE RESES HEMBRAS OBESAS" ;

int MENU();
void CREAR();
void CONSULTA_RESES();
void CONSULTA_HEMBRAS();

struct CAMPOS {
   char SERIE[30];
   int EDAD;
   char SEXO;
   int PESO;
   }  ;
  
  CAMPOS FRIGORIFICO[100];
  CAMPOS HEMBRAS[100];
  int   I = 0; 


/*************** PROGRAMA PRINCIPAL ***********************/

 main()   {
 
    char CONTROL = 'S';
    int  OPCION ;
    while ( CONTROL == 'S')     {
   
        OPCION = MENU();
        switch   (OPCION)  {
            case 1 : CREAR();
                     break;
            case 2 : CONSULTA_RESES();
                	 break;
            case 3 : CONSULTA_HEMBRAS();
                     break;
            case 4 : CONTROL = 'N';
           
       };
    }
 }
    
/************************ M E N U ***********************/
    
 int MENU()  {
 
   int OP ;
   system("cls");
   system("color F0");
   gotoxy(40,6) ; cout << TITULO;
   gotoxy(30,9); cout << "1. INGRESAR DATOS DE LAS RESES" ;
   gotoxy(30,12); cout << "2. MOSTRAR REGISTRO DE TODAS LAS RESES";
   gotoxy(30,15); cout << "3. MOSTRAR RESES HEMBRAS OBESAS";
   gotoxy(30,18); cout << "4. SALIR ";
   do  {
        gotoxy(35,21); cout << "SELECIONE UNA DE LAS ALTERNATIVAS : ";
        cin >> OP ;
   }  while((OP < 1) || (OP > 5)) ;
   gotoxy(30,22); cout << "                          ";
   return OP ;
   }   
   
   /*******************  C R E A R **********************/
    
  void CREAR(){
    srand(time(0));

    char  OP = 'S';
    while ((OP == 'S') && ( I < 100))   {
         int EDA=0;
        system("cls");
        gotoxy(40,5)  ;cout << TITULO;
        gotoxy(45,7)  ;cout << TITULO1;
        gotoxy(30,11) ;cout << "SERIE    : ";
        gotoxy(30,13) ;cout << "EDAD     : ";
        gotoxy(30,15) ;cout << "SEXO     : ";
        gotoxy(30,17) ;cout << "PESO     : ";
          cin.sync();
        gotoxy(41,11); gets( FRIGORIFICO[I].SERIE);
        gotoxy(41,11); cout << strupr(FRIGORIFICO[I].SERIE);
         cin.sync();
          do {
          	
           	 EDA=(1+rand()%10);
             gotoxy(41,13); cout<<EDA;
        } while ( (EDA < 0 )||(EDA > 10 ));
        FRIGORIFICO[I].EDAD=EDA;
          cin.sync();
         do {
           gotoxy(41,17); cout<< " " ;
           gotoxy(35,20); cout << " INGRESE : M-> Macho       H -> Hembra " ;
           gotoxy(41,15); FRIGORIFICO[I].SEXO = getche();
           FRIGORIFICO[I].SEXO = toupper(FRIGORIFICO[I].SEXO) ;
        } while ((FRIGORIFICO[I].SEXO != 'M') && ( FRIGORIFICO[I].SEXO != 'H'));
   	    gotoxy(35,20); cout <<"                                              ";
   	    cin.sync();
        do {
           gotoxy(41,17) ; cin >> FRIGORIFICO[I].PESO ;
           gotoxy(35,20); cout<< "Error .... valor fuera de rango ";
        } while ( FRIGORIFICO[I].PESO < 0 );
        gotoxy(35,20); cout <<"                                   ";
        
        if((FRIGORIFICO[I].SEXO == 'H')&&(FRIGORIFICO[I].PESO >40)){
        	HEMBRAS[I].SEXO=FRIGORIFICO[I].SEXO;
        	HEMBRAS[I].PESO=FRIGORIFICO[I].PESO;
        	HEMBRAS[I].EDAD=FRIGORIFICO[I].EDAD;
        	strcpy(HEMBRAS[I].SERIE,FRIGORIFICO[I].SERIE);
		}
        
        I = I + 1;
        do {
           gotoxy(35,24); printf("DESEA CONTINUAR - S/N - ");
           OP= getch();
           OP = toupper(OP);
        } while ((OP != 'S' ) && ( OP!= 'N'));
      }
   }
   
   /*************** CONSULTA TIPO LISTADO ***********************/
 
 
 
 void CONSULTA_RESES() {
 
     int  F, K ;
     if  (I == 0)   {
         gotoxy (40,24); cout << "NO SE HAN INGRESADO DATOS ";
         getch();
           }else{
        system("cls");
        system("color F0");
         F = 11;
         gotoxy(40,5)  ;cout << TITULO;
         gotoxy(35,7)  ;cout << TITULO2;
         gotoxy(22,9) ; printf("  SERIE           EDAD          PESO    SEXO ");
         for ( K = 0 ; K < I ; K++ ) {
             gotoxy(22,F); cout << FRIGORIFICO[K].SERIE;
             gotoxy(41,F); cout << FRIGORIFICO[K].EDAD;
             gotoxy(55,F); cout << FRIGORIFICO[K].PESO  ;
             gotoxy(64,F); cout << FRIGORIFICO[K].SEXO  ;
             if  ( F <= 24 )
                 F++ ;
               else
                 {
                 gotoxy(21,F+=3); cout << "Pulse Cualquier tecla para Continuar";
                 getch();
                 F = 11 ;
                gotoxy(40,5)  ;cout << TITULO;
                gotoxy(35,7)  ;cout << TITULO2;
                gotoxy(22,9) ; printf("  SERIE           EDAD          PESO    SEXO ");
                 }
             }
	         gotoxy(35,F+=3); cout << "Pulse Cualquier tecla para Continuar";
             getch();
	    }
}
 /*************** CONSULTA RESES HEMBRAS ROBUSTAS ***********************/
 
 
 
 void CONSULTA_HEMBRAS()     {
 
     int  F, K ,SW;
     if  (I == 0)   {
         gotoxy (40,24); cout << "NO SE HAN INGRESADO DATOS ";
         getch();
     
           }else     {
           	system("cls");
           system("color F0");
            F = 11;
           gotoxy(40,5)  ;cout << TITULO;
           gotoxy(43,7)  ;cout << TITULO3;
            SW = 0;  
	            for (K = 0 ; K < I  ; K ++ ){
	            	if((HEMBRAS[K].EDAD!=0)&&(HEMBRAS[K].PESO!=0)){
			         gotoxy(22,9) ; printf("  SERIE           EDAD          PESO    SEXO ");
		             gotoxy(22,F); cout << HEMBRAS[K].SERIE;
                     gotoxy(41,F); cout << HEMBRAS[K].EDAD;
                     gotoxy(55,F); cout << HEMBRAS[K].PESO  ;
                     gotoxy(64,F); cout <<HEMBRAS[K].SEXO  ;
                     F++;  SW= 1;  
		           	}    
		                 
               	}    
                if (SW == 0)  {
                   
                   gotoxy(41,F+=3) ; cout << "NO HAY REGISTROS DE HEMBRAS OBESAS" ;
                   }
        
	         gotoxy(39,F+=6); cout << "Pulse Cualquier tecla para Continuar";
             getch();
	   }
	  }
