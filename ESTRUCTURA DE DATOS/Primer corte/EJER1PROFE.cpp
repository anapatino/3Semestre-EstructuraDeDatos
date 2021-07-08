#include <iostream.h>
#include <conio.h>
#include <ctype.h>
#include <string.h>
#include <stdio.h>

int NEL, I;

long CODIGOS [20];     
char NOMBRES [20] [50];
float  P1 [20], P2 [20], EF [20], DEFI [20];

// declaracion de mis funciones
void  CAPTURAR_DATOS(), CAPTURAR_DATOS3(), INFORME(), PROCESAR_NOTAS(), MENU();
void MATRICULAR_TARDE();

using namespace std;

// Escribo cada una de mis funciones

void  MENU()
{
  int  OP;
  do
  {
      clrscr();
      cout << " 1.-  CAPTURA DATOS DE ESTUDIANTES  V1.0... \n";
      cout << " 2.-  CAPTURA DATOS DE ESTUDIANTES  V2.0... \n";
      cout << " 3.-  CAPTURA DATOS DE ESTUDIANTES  V3.0... \n";
      cout << " 4.-  INFORME DE  ESTUDIANTES  ... \n";
      cout << " 5.-  AGREGAR ESTUDIANTE A LA LISTA (sin duplicados)... \n";
      cout << " 6.-  PROCESAR NOTAS... \n";
      cout << " 7.-  CONSULTAR DATOS DE ESTUDIANTES V1.0 ... \n";
      cout << " 8.-  CONSULTAR DATOS DE ESTUDIANTES V2.0 ... \n";
      cout << " 9.-  BORRAR DATOS DE ESTUDIANTE V1.0... \n";
      cout << " 10.-  BORRAR DATOS DE ESTUDIANTE V2.0... \n";
      cout << " 11.-  ACTUALIZAR DATOS DE  ESTUDIANTES  ... \n";
      cout << " 12.-  MATRICULAR TARDE UN ESTUDIANTE  ... \n";
	  cout << " 13.-  FIN NDEL PROCESO \n\n\n";
      cout << " OPCION ?? >>> "; cin >> OP;

       switch(OP)
       {
        case 1: CAPTURAR_DATOS(); break;
        case 2: INFORME(); break;
        case 3: PROCESAR_NOTAS(); break;
        case 4: CAPTURAR_DATOS3(); break;
        //case 5: BORRAR (); break;
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



void  CAPTURAR_DATOS()
{

  cout << " Cuantos Alumnos ? "; cin >> NEL;
  if ( (NEL < 0) || (NEL > 20 ) )
  {
     cout << " ERROR, RECTIFIQUE EL NUMERO DE ELEMENTOS A INTRODUCIR ";
     getch();
  }
  else
  {
    for ( I=1; I<= NEL; I++)
    {
      cout << "  Digite C?digo del Alumno "; cin >> CODIGOS [I] ;
      cout << "  Digite Nombre del alumno "; gets( NOMBRES [I]);
      cout << "  PRIMER PARCIAL  ?        "; cin >> P1[I] ;
      cout << "  SEGUNDO PARCIAL ?        "; cin >> P2[I] ;
      cout << "  EXAMEN FINAL    ?        "; cin >> EF[I] ;
    }
   }
}


void  CAPTURAR_DATOS3 ()
{
  char MAS;
  NEL = 0 ;
   do
   {
      system "cls";
      NEL = NEL + 1;
      cout << " **** Captura de datos del Estudiante ***** \n\n" ;
      cout << "  Digite C?digo del Alumno "; cin >> CODIGOS [NEL] ;
      cout << "  Digite Nombre del alumno "; gets( NOMBRES [NEL]);
      cout << "  PRIMER PARCIAL     ?     "; cin >> P1[NEL] ;
      cout << "  SEGUNDO PARCIAL    ?     "; cin >> P2[NEL] ;
      cout << "  EXAMEN FINAL       ?     "; cin >> EF[NEL] ;

      cout << " Desea seguir Introduciendo Informaci?n de Alumnos ? ";
      MAS = toupper (getche());
   } while ( MAS ==  'S'   && NEL < 20);

   if ( NEL > 20)
   {
     cout << " ERROR, Ya los vectores est?n llenos, no caben mas elementos "; getch();
    }
    else
    {
       cout << " OK. Se capturaron los datos de los alumnos correctamente ?. "; getch();
    }

}  // FIN DE LA FUNCION CAPTURA3

void  INFORME()
{
   system "cls";
   for ( I=1; I<= NEL; I++)
   {
     cout << CODIGOS [I] << "   " << NOMBRES [I] << "  " << P1[I]  << "  " << P2[I] << "  " << EF[I] << " " << DEFI[I]<< "\n";
   }
   cout << "\n\n\n\n Pulse ENTER ... " ; getch();
}

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

void main()
{
  MENU ();
}



