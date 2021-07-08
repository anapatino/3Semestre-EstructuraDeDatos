

#include <windows.h>                    
#include <iostream>                     
#include <conio.h>                      

using namespace std;                     

int gotoxy(USHORT x,USHORT y){                                
COORD cp={x,y};                                               
SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),cp); 
}

void TITULOS();
int MENU();

main() {
	


  int I,F, K,W, AUX, SW, TIPO ;
  char  OP = 'S',OPCION = 'S';
  int VECTOR[5], N = 0;
  long CODIGO[5],COD,codigo;
  char NOMBRE[5][20],NOM[20];
  char DIRECTOR[5][20],DIRE[20];
  char AUTOR1[5][20],AUT1[20];
  char AUTOR2[5][20],AUT2[20];
  while  ( OP == 'S' )    {

    TITULOS();
    TIPO = MENU();
    switch ( TIPO ) {
     
       case 1 :
       	         OPCION = 'S';
                while ((OPCION == 'S' ) && ( I < 5)){
	               system("cls");
	                TITULOS();
	               gotoxy(27,5) ; cout << "REGISTRO DE DATOS";  
                   gotoxy(20,10); cout<< "CODIGO           : ";
                   gotoxy(20,11); cout<< "NOM_TRABAJO      : " ;
                   gotoxy(20,12); cout<< "AUTOR1           : " ;
                   gotoxy(20,13); cout<< "AUTOR2           : " ;
                   gotoxy(20,14); cout<< "DIRECTOR         : " ;
                   gotoxy(20,15); cout<< "NUM PAGINAS      : " ;
               
	                do {
			           gotoxy(40,10); cin >> CODIGO[I] ;
	                } while (CODIGO[I] < 0 );
	                
	                 cin.sync();
	                gotoxy(40,11);cout<<"                  ";
                     gotoxy(40,11); gets(NOMBRE[I]);
                    gotoxy(40,12);cout<<"                  ";
	                 gotoxy(40,12); gets(AUTOR1[I]);
	                gotoxy(40,13);cout<<"                  ";
	                 gotoxy(40,13); gets(AUTOR2[I]);
	                gotoxy(40,14);cout<<"                  ";
	                 gotoxy(40,14); gets(DIRECTOR[I]);
	                 cin.sync();
	                gotoxy(15,19); cout << "Digite valor entre 0 - 1000  PAG";
	                do {
	                   gotoxy(40,15);cout<<"                  ";
			           gotoxy(40,15); cin >> VECTOR[I] ;
	                   gotoxy(15,19); cout << "ERROR ....Digite valor entre 0 - 1000 ";
	                } while ((VECTOR[I] < 0 ) || (VECTOR[I] > 1000));
	                gotoxy(15,19); cout << "                                        ";
	              I++;
	           
	              do {
		               gotoxy(28,24); printf("DESEA CONTINUAR - S/N - ");
			           OPCION = getch();
			           OPCION = toupper(OPCION);
		             } while (( OPCION != 'S' ) && ( OPCION != 'N'));  
	                
	        }    
	            break;        
       case 2 : if ( I == 0)      {
	         
	               gotoxy (20,24); cout << " No existen elementos en la Listas";
	               getch();
			       }
				 else	   {
			
				   TITULOS();
				       F = 11 ;
					// **** RUTINA DE ORDENAMIENTO - METODO LINEAL ****  
						               
                    for ( K= 0 ; K < I-1 ; K++ ){
                    	
				
                        for ( int S = K + 1 ; S < I ; S++ ){
                        	
					
	                        if (VECTOR[K] > VECTOR[S]) {
		                      
		                       	 /*********PAGINA**********/
		                       AUX = VECTOR[K] ;
		                       VECTOR[K] = VECTOR[S] ;
		                       VECTOR[S] = AUX;
		                       /*********CODIGO**********/
		                       COD = CODIGO[K] ;
		                       CODIGO[K] = CODIGO[S] ;
		                       CODIGO[S] = COD;
		                        /*********NOMBRE**********/
		                       strcpy(NOM,NOMBRE[K]);
		                       strcpy(NOMBRE[K],NOMBRE[S]);
		                       strcpy(NOMBRE[S],NOM);
		                        /*********AUTOR1**********/
		                       strcpy(AUT1,AUTOR1[K]);
		                       strcpy(AUTOR1[K],AUTOR1[S]);
		                       strcpy(AUTOR1[S],AUT1);
		                       /*********AUTOR2**********/
		                       strcpy(AUT2,AUTOR2[K]);
		                       strcpy(AUTOR2[K],AUTOR2[S]);
		                       strcpy(AUTOR2[S],AUT2);
		                        /*********DIRECTOR**********/
		                       strcpy(DIRE,DIRECTOR[K]);
		                       strcpy(DIRECTOR[K],DIRECTOR[S]);
		                       strcpy(DIRECTOR[S],DIRE);
		                    
		                     }  
		              	}       
		                       
				   }
					// **** RUTINA DE IMPRIMIR REGISTRO ORDENADO ****	
					   
	
			    	 gotoxy(5,9); cout << "CODIGO      NOMBRE-TRABAJO              AUTOR1          AUTOR2           DIRECTOR            PAG ";
		           
                    for ( int J = 0 ; J < I ; J++ ){
	                  gotoxy(5,F); cout << CODIGO[J];
	                  gotoxy(18,F); cout << NOMBRE[J];
		              gotoxy(43,F); cout << AUTOR1[J];
		              gotoxy(59,F); cout << AUTOR2[J];
	                  gotoxy(76,F); cout << DIRECTOR[J];
	                  gotoxy(97,F); cout << VECTOR[J];
					  
				  if  ( F <= 24 )
                      F++ ;
                   else   {
                   gotoxy(21,F+=3); cout << "Pulse Cualquier tecla para Continuar";
                    getch();
                   F = 11 ;
                   gotoxy(5,9); cout << "CODIGO      NOMBRE-TRABAJO              AUTOR1          AUTOR2           DIRECTOR            PAG ";
                 }
                     
                } 
                getch();
                  }
	            break ;
       case 3: 
	     
		         if  ( I == 0 )  {
		     
		          gotoxy (20,24); cout << "No hay datos ";
		           getch();
		       }  else  {
		   
		          system("cls");
		          gotoxy(26,4);  cout << "ELIMINAR DATOS DE UN TRABAJO";
                  gotoxy(25,6); cout << "CODIGO_TRABAJO    : ";
                 do {
                     cin>>codigo;
	              } while (codigo < 0 );
	                SW = 0 ;
	                for (K = 0 ; K < I && SW == 0; K ++ )
	                  if  (codigo == CODIGO[K])  {
     	                gotoxy(5,9); cout << "CODIGO      NOMBRE-TRABAJO              AUTOR1          AUTOR2           DIRECTOR            PAG ";
		                gotoxy(5,11); cout << CODIGO[K];
	                    gotoxy(18,11); cout << NOMBRE[K];
		                gotoxy(43,11); cout << AUTOR1[K];
		                gotoxy(59,11); cout << AUTOR2[K];
	                    gotoxy(76,11); cout << DIRECTOR[K];
	                    gotoxy(97,11); cout << VECTOR[K];
		                 SW = 1;
		                    for ( W = K ; W < I ; W++ )  {
				           
					     	  CODIGO[W]= CODIGO[W + 1];	
		           	          strcpy( NOMBRE[W],NOMBRE[W+ 1]);
		           	          VECTOR[W]=VECTOR [W+ 1];
		           	          strcpy( AUTOR1[W],AUTOR1[W+ 1]);
		           	          strcpy( AUTOR2[W],AUTOR2[W+ 1]);
		           	          strcpy( DIRECTOR[W],DIRECTOR[W+ 1]);
				         	}
					          I = I - 1 ; 
				     	     gotoxy(20,22); cout << "OK, Registro Eliminado en la Lista";  
		                }
                if  (SW == 0)    {
                
                    gotoxy(50,13) ; cout << "NO EXISTE REGISTRO" ;  
                    }
              
		      }
	            getch();  
               break;
      	
	   case 4: OP = 'N' ;
	            break ;
      
    }
  }
}
void   TITULOS()   {

   system("cls");
   system("color 1F");
   gotoxy(22,6) ; cout <<"CREAR, ORDENAR E IMPRIMIR UN REGISTRO";

   }
   
int MENU()   {

   	int TIPO;
   	gotoxy(26,10); cout << "1 - ASIGNAR VALORES AL VECTOR" ;
    gotoxy(26,11); cout << "2 - IMPRIMIR LISTA REGISTROS ORDENADOS";
    gotoxy(26,12); cout << "3 - BORRAR PROPUESTA DE GRADO";
   gotoxy(26,13); cout << "4 - SALIR DEL PROGRAMA";
    do {
       gotoxy(24,16); cout << "Seleccine una alternativa :  ";
       cin>> TIPO;
    } while ((TIPO < 1 ) || (TIPO > 4));
    return TIPO;
   }
