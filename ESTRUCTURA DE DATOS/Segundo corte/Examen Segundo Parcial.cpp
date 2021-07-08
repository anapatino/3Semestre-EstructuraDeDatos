#include <iostream>
#include <conio.h>
#include <ctype.h>
#include <string.h>
#include <stdio.h>
#include <windows.h>   

 

char SEGUIR,Encontro;
int CONT,IDE,dato;;

// declaracion de mis funciones
void  MENU(), REGISTRAR(), INFORME(),BORRAR(),INSERTAR(),CRUZAR();


using namespace std;
int gotoxy(USHORT x,USHORT y){                                  
COORD cp={x,y};                                                 
SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),cp);   // sentencia gotoxy
}

struct Nodo
{
	char LETRA;
	struct Nodo *SIG;
	struct Nodo *ANT;
};

struct Nodo *p,*q,*r,*cabeza, *fin;

struct Nodo2
{
	char VOCAL;
	struct Nodo2 *SIG;
	struct Nodo2 *ANT;
};

struct Nodo2 *p2,*q2,*r2,*cabeza2, *fin2;

 main()
{
  MENU ();
}

void  MENU()
{

  int OP;
  do
   {
	system("cls");
    system("color 70");
    gotoxy(33,7); cout << " CAPTURAR ARTICULOS";
    gotoxy(29,9); cout <<  " 1-  REGISTRAR LETRAS";
    gotoxy(29,10); cout << " 2-  INFORME ";
    gotoxy(29,11); cout << " 3-  INSERTAR";
    gotoxy(29,12); cout << " 4-  SALIR";
	 do  {
        gotoxy(29,23); cout << "SELECIONE UNA DE LAS ALTERNATIVAS : ";
        cin >> OP ;
        gotoxy(30,25); cout << "VALOR FUERA DE RANGO";
      }  while((OP < 1) || (OP > 4)) ;
       gotoxy(30,25); cout << "                          ";
	
	 switch(OP)
       {
        case 1: REGISTRAR(); break;
        case 2: INFORME();break;
        case 3: CRUZAR(); break;
		case 4: cout << " Pulse ENTER para terminar.....";    	getch();
        break;
        
        default:  cout << " \n\n\n ERROR EN OPCION ... "; 					getch();
       }
   }while( OP != 6);
}



void REGISTRAR()
{
	SEGUIR = 'N';
	do{
		p = new(struct Nodo);
		if(p==NULL)
		{
		  gotoxy(28,21); cout << " NO HAY ESPACIO EN MEMORIA "; getch();	
		}
		else
		{
		  system ("cls");
		  //Llena nodo
          gotoxy(33,9); cout << " UNIVERSIDAD POPULAR DEL CESAR";
          gotoxy(34,11); cout << " CAPTURA DE DATOS " ;
          cin.sync();
          gotoxy(28,14); cout << "  NOMBRE DE ARTICULO   : ";
          p->LETRA = toupper (getche());
          //Agrego Nodo
          if(cabeza==NULL)
          {
          	cabeza=p;
          	cabeza->SIG=cabeza;
          	cabeza->ANT=cabeza;
          	fin=p;
		  }
		  else
		  {
		  	fin->SIG=p;
		  	p->ANT=fin;
		  	p->SIG=cabeza;
		  	cabeza->ANT=p;
		  	fin=p;
		  }
		}
		gotoxy(28,19); cout << " DESEA SEGUIR INTRODUCCIENDO DATOS: S/N : ";
        SEGUIR = toupper (getche());
	}while(SEGUIR == 'S'); 
}

void INFORME()
{
   system ("cls");
   int F;
   F=9;
   p=cabeza;
   p2=cabeza2;
   if(p==NULL)
   {
    	gotoxy(13,10 ); cout << "NO HAY DATOS REGISTRADOS " ;
   }
   else
   {
   	   gotoxy(24,5); cout << " UNIVERSIDAD POPULAR DEL CESAR";
   	   gotoxy(13,7); cout<< "LISTA 1: ";
     do
       {
   	   
         cout<<  p->LETRA << " "; 
         p = p->SIG;
       }while(p!=cabeza);
       gotoxy(13,9); cout <<"LISTA 2: ";
       if(p2!=NULL)
       {
       	do
       { 
         cout<<  p2->VOCAL << " "; 
         p2 = p2->SIG;
       }while(p2!=cabeza2);
       	
	   }
   
   }
    gotoxy(13,F+3 ); cout << "Pulse ENTER para volver... " ; getch();
} 

void CRUZAR()
{	
   if(cabeza == NULL)
   {
   	cout<<"No hay nada que hacer (Y)"; system ("pause");
   }
   else
   {
   	p = cabeza;
   	do{
          if((p->LETRA == 'A') ||(p->LETRA == 'E') || (p->LETRA == 'I') || (p->LETRA == 'E') || (p->LETRA == 'U')) 
		     {
                  INSERTAR();
                  BORRAR();
             }
     p = p->SIG;
   }while(p!=cabeza);//fin while
    
  }//fin if
   cout<<"Proceso Realizado.....!!";	
}

void INSERTAR(){
	
	    p2 = new(struct Nodo2);
		if(p2==NULL)
		{
		  gotoxy(28,21); cout << " NO HAY ESPACIO EN MEMORIA "; getch();	
		}
		else
		{
          p2->VOCAL=p->LETRA;;
          //Agrego Nodo
          if(cabeza2==NULL)
          {
          	cabeza2=p2;
          	cabeza2->SIG=cabeza2;
          	cabeza2->ANT=cabeza2;
          	fin2=p2;
		  }
		  else
		  {
		  	fin2->SIG=p2;
		  	p2->ANT=fin2;
		  	p2->SIG=cabeza2;
		  	cabeza2->ANT=p2;
		  	fin2=p2;
		  }
		}
}


void BORRAR()
{
    	if((p==cabeza) && (cabeza->SIG==cabeza))
			{
				//Nodo unico
				delete(p);
				cabeza=NULL;
				
			}
			else
			{
				if((p == cabeza) && (cabeza->SIG != cabeza))
				{
				    //Borra el primero
			        cabeza=cabeza->SIG;
			    	fin->SIG=cabeza;
			    	cabeza->ANT=fin;
				    delete(p);
				    p=cabeza;
				   
				}
				else
				{
					if(p == fin)  //Borra el ultimo
					{
						p->ANT->SIG=cabeza;
						fin=fin->ANT;
						cabeza->ANT=fin;
						delete(p);
						p=cabeza;
				
					
					}
					else
					{
						//Borrar uno intermedio
						p->ANT->SIG=p->SIG;
						p->SIG->ANT=p->ANT;
						delete(p);
						p=cabeza;
				
						
					}
				}
			
			}

}
 










