#include <iostream>
#include <conio.h>
#include <ctype.h>
#include <string.h>
#include <stdio.h>
#include <windows.h> 

int NEL, I;

long CODIGOS [20];     
char NOMBRES [20] [50];
float  P1 [20], P2 [20], EF [20], DEFI [20];

// declaracion de mis funciones
void  CAPTURAR_DATOS(), CAPTURAR_DATOS2(), CAPTURAR_DATOS3(), INFORME(),AGREGAR(), PROCESAR_NOTAS(), MENU();
void MATRICULAR_TARDE();

using namespace std;
int gotoxy(USHORT x,USHORT y){                                  
COORD cp={x,y};                                                 
SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),cp);   
}


/********************** DECLARACION DE FUNCIONES ********************/

#define  TITULO  "	R E G I S T R O   DE  D A T O S";
#define  TITULO1 "CAPTURA DATOS DE ESTUDIANTES  V1.0" ;
#define  TITULO2 "CAPTURA DATOS DE ESTUDIANTES  V2.0" ;
#define  TITULO3 "CAPTURA DATOS DE ESTUDIANTES  V3.0";
#define  TITULO4 "INFORME DEL ESTUDIANTE";
#define  TITULO5 "AGREGAR ESTUDIANTE A LA LISTA (SIN DUPLICADOS)";
#define  TITULO6 "MODIFICAR";

/************************ MENU**********************/

void  MENU(){

  int  OP;
  do  {
       system("cls") ;
       system("color F0");
       gotoxy(30,5);cout << TITULO;
       gotoxy(28,8);cout  << " 1.-  CAPTURA DATOS DE ESTUDIANTES  V1.0... \n";
       gotoxy(28,9);cout  << " 2.-   CAPTURA DATOS DE ESTUDIANTES  V2.0... \n";
       gotoxy(28,10);cout << " 3.-  CAPTURA DATOS DE ESTUDIANTES  V3.0... \n";
       gotoxy(28,11);cout << " 4.-  INFORME DE  ESTUDIANTES  ... \n";
       gotoxy(28,12);cout << " 5.-  AGREGAR ESTUDIANTE A LA LISTA (sin duplicados)... \n";
       gotoxy(28,13);cout << " 6.-  PROCESAR NOTAS... \n";
       gotoxy(28,14);cout << " 7.-  CONSULTAR DATOS DE ESTUDIANTES V1.0 ... \n";
       gotoxy(28,15);cout << " 8.-  CONSULTAR DATOS DE ESTUDIANTES V2.0 ... \n";
       gotoxy(28,16);cout << " 9.-  BORRAR DATOS DE ESTUDIANTE V1.0... \n";
       gotoxy(28,17);cout << " 10.- BORRAR DATOS DE ESTUDIANTE V2.0... \n";
       gotoxy(28,18);cout << " 11.- ACTUALIZAR DATOS DE  ESTUDIANTES  ... \n";
       gotoxy(28,19);cout << " 12.- MATRICULAR TARDE UN ESTUDIANTE  ... \n";
	   gotoxy(28,20);cout << " 13.- FIN NDEL PROCESO \n\n\n";
       do  {  
           gotoxy(40,23); cout << "DIGITE SU OPCION: "; cin >> OP;
       } while ( (OP<1) ||(OP>13) );

       switch(OP)  {
     
        case 1: CAPTURAR_DATOS(); break;
        case 2: CAPTURAR_DATOS2(); break;
        case 3: CAPTURAR_DATOS3(); break;//PROCESAR_NOTAS(); break;
        case 4: INFORME(); break;
        case 5: AGREGAR(); break;//BORRAR (); break;
        case 6: CAPTURAR_DATOS(); break;
        case 7: INFORME(); break;
        case 8: PROCESAR_NOTAS(); break;
        case 9: CAPTURAR_DATOS3(); break;
        //case 10: BORRAR (); break;
        //case 11: BORRAR (); break;
        case 12: MATRICULAR_TARDE (); break;
        case 13: cout << " Pulse ENTER para terminar.....";       			getch();
        break;
        
        default:  cout << " \n\n\n ERROR EN OPCION ... "; 					getch();
       }
   } while ( OP != 13);
}

/************************ CAPTURAR DATOS V1 **********************/

void  CAPTURAR_DATOS(){
      system("cls") ;
      system("color F0");
      gotoxy(30,5);cout << TITULO;
      gotoxy(28,9);cout << "INGRESE Nro ESTUDIANTES-> "; cin >> NEL;
   if ( (NEL < 0) || (NEL > 20 ) )  {

      gotoxy(28,11);cout << " ERROR, RECTIFIQUE EL NUMERO DE ELEMENTOS A INTRODUCIR "; getch();
   
    } else{
 
    for ( I=1; I<= NEL; I++) {
       gotoxy(35,12);cout << "CODIGO       : "; cin >> CODIGOS [I] ;
       	cin.sync();
       gotoxy(35,14);cout << "NOMBRE       : "; gets( NOMBRES [I]);
       	cin.sync();
       gotoxy(35,16);cout << "1er PARCIAL  : "; cin >> P1[I] ;
       gotoxy(35,18);cout << "2do PARCIAL  : "; cin >> P2[I] ;
       gotoxy(35,20);cout << "EXAMEN FINAL : "; cin >> EF[I] ;
    }
   }
}
/************************ CAPTURAR DATOS V2 **********************/
void  CAPTURAR_DATOS2(){
	
	int CONT=0;
	char OPCION;
      system("cls") ;
      system("color F0");
      gotoxy(30,5);cout << TITULO2;
     OPCION = 'S' ;
    
      while(OPCION=='S'){
      gotoxy(28,9);cout << "INGRESE Nro ESTUDIANTES-> "; cin >> NEL;
    for ( I=1; I<= NEL; I++) {
       gotoxy(35,12);cout << "CODIGO       : "; cin >> CODIGOS [I] ;
       	cin.sync();
       gotoxy(35,14);cout << "NOMBRE       : "; gets( NOMBRES [I]);
       	cin.sync();
       gotoxy(35,16);cout << "1er PARCIAL  : "; cin >> P1[I] ;
       gotoxy(35,18);cout << "2do PARCIAL  : "; cin >> P2[I] ;
       gotoxy(35,20);cout << "EXAMEN FINAL : "; cin >> EF[I] ;
    }
 
    do {
         gotoxy(28,22); cout << "DESEA CONTINUAR - S/N - ";
		 OPCION = getch();
		 OPCION = toupper(OPCION);
    } while (( OPCION != 'S' ) && ( OPCION != 'N'));
    gotoxy(28,22); cout <<"                                     ";
     }     
 }
 /************************ CAPTURAR DATOS V3**********************/  

void  CAPTURAR_DATOS3 (){

  char MAS;
  NEL = 0 ;
   do {
      system ("cls");
      NEL++;
      gotoxy(30,5);cout << TITULO3;
      gotoxy(35,12);cout <<"CODIGO             : "; cin >> CODIGOS [NEL] ;
      	cin.sync();
      gotoxy(35,14);cout <<"NOMBRE             : "; gets( NOMBRES [NEL]);
      	cin.sync();
      gotoxy(35,16);cout <<"PRIMER PARCIAL    : "; cin >> P1[NEL] ;
      gotoxy(35,18);cout <<"SEGUNDO PARCIAL   : "; cin >> P2[NEL] ;
      gotoxy(35,20);cout <<"EXAMEN FINAL      : "; cin >> EF[NEL] ;

      gotoxy(38,23);cout <<"DESEA SEGUIR INGRESANDO DATOS->"; MAS = toupper (getche());
     
   } while ((MAS ==  'S')&&(NEL < 20));

   if ( NEL > 20)  {
 
      gotoxy(40,28);cout << " ERROR,VECTORES LLENOS "; getch();
    }else  {
      gotoxy(40,28); cout <<"LOS DATOS FUERON ALMACENDOS CORRECTAMENTE"; getch();
    }

}  

/************************ INFORME DE ESTUDIANTES **********************/
void  INFORME(){
 int F;
   system ("cls");
    gotoxy(39,3);cout << TITULO4;
     gotoxy(18,7);cout <<"CODIGO          NOMBRE              1er PARCIAL     2do PARCIAL   EX.FINAL    DEF";
    F = 9;
   for ( I=1; I<= NEL; I++)  {
   	
     gotoxy(20,F);cout << CODIGOS [I];
     gotoxy(31,F);cout << NOMBRES [I];
     gotoxy(57,F);cout <<P1[I] ;
     gotoxy(74,F);cout <<P2[I] ;
     gotoxy(87,F);cout <<EF[I] ;
     gotoxy(97,F);cout << DEFI[I];
     F++;
   }
    gotoxy(39,F+4);cout << "PULSE UNA TECLA PARA SALIR" ; getch();
}
/************************ AGREGAR ESTUDIANTES A LA LISTA **********************/

 void AGREGAR() {
 char MAS ='S';
   long CODI;     
   float  N1 , N2, NF;
   int T = 0,E = 0;
   while (MAS =='S' && NEL < 20)
   {
   system ("cls");
      
      gotoxy(33,9); cout << " UNIVERSIDAD POPULAR DEL CESAR";
      gotoxy(34,11); cout << " CAPTURA DE DATOS ESTUDIANTES" ;
      if(NEL<20)
	  {
	    gotoxy(28,13); cout << "  CODIGO DE ALUMNO : "; cin >> CODI;
	    for (I = 1; I<=NEL; I++){
	      if(CODI == CODIGOS[NEL])
	       { 
				T=1 ;
	       }
		}
		if(T == 0){	
		  CODIGOS[NEL+1] = CODI;
		  cin.sync();
          gotoxy(28,14); cout << "  NOMBRE DE ALUMNO : "; gets( NOMBRES [NEL+1]);
          gotoxy(28,15); cout << "  PRIMER PARCIAL   : "; cin >> P1[NEL+1] ;
          gotoxy(28,16); cout << "  SEGUNDO PARCIAL  : "; cin >> P2[NEL+1] ;
          gotoxy(28,17); cout << "  EXAMEN FINAL     : "; cin >> EF[NEL+1] ;
		  NEL = NEL+1;		
		}
		else
		{
		  gotoxy(28,17); cout << "VALOR YA INGRESADO";
		  getch();
		  break;	
		}
	
	 }
	  else{
	  	
	  	gotoxy(28,15); cout<< "ESTAN LLENOS LOS VECTORES, NO ADMITE MAS VALORES";
	 	
	     }   
	  gotoxy(28,19); cout << " DESEA SEGUIR INTRODUCCIENDO DATOS: S/N : ";
      MAS = toupper (getche());     
   } 

}	  
 
	  






/************************ **********************/
void  PROCESAR_NOTAS()
{
   for ( I=1; I<= NEL; I++)
    {
      DEFI[I] = (0.30 * P1[I]) + (0.30 * P2[I]) + (0.40 * EF[I]) ;
    }
}



void MATRICULAR_TARDE()
{
  /* SOLICITA UN CODIGO DE ESTUDIANTE, LO BUSCA EN EL ARRAY, SI LO ENCUENTRA ENTONCES LO RECHAZA.
     PERO SI NO LO ENCUENTRA ENTONCES PREGUNTA "en que posicion del array quiere meterlo?"
     VERIFICA LUEGO SI ESA POSICION EST? LIBRE.
	 SI LO EST? ENTONCES LO INSERTA.
	 PERO SI NO EST? DESOCUPADA ESA POSICION DONDE EL USUARIO QUIERE INSERTARLO ENTONCES 
         VERIFICA SI PUEDE DESPLAZAR HACIA ABAJO O HACIA ARRIBA LOS ELEMENTOS, PARA HABILITAR
	 ESE LUGAR PARA EL NUEVO CODIGO, Y SI ES ASI, LO INSERTA...........
   */	
	
}

// ahora la funcion PRINCIPAL

int main(){

  MENU ();
}


