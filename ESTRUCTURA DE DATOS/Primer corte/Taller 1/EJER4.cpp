#include <stdio.h>                       
#include <windows.h>                      
#include <iostream>                      
#include <conio.h>                       
#include <ctype.h>
#include<ctime>  
#include<stdlib.h>  

using namespace std;                     

int gotoxy(USHORT x,USHORT y){                                  
COORD cp={x,y};                                                 
SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),cp);   
}

#define  TITULO  "CAPTURA DE VECTORES ALEATORIOS";
#define  TITULO1 "C A P T U R A   D E   V E C T O R   A " ;
#define  TITULO2 "C A P T U R A   D E   V E C T O R   B" ;
#define  TITULO3 "SUMA DE VECTORES A Y B" ;
#define  TITULO4 "RESTA DE VECTORES A Y B";
#define  TITULO5 "MOSTRAR DATOS DE VECTORES ";
int MENU();
void VECTOR1();
void VECTOR2();
void SUMA();
void RESTA();
void MOSTRAR();
int A[100],B[100],C[100],CC[100],NUM;
/*************** PROGRAMA PRINCIPAL ***********************/

 main() {
   
    char CO = 'S';
    int  OP ;
    int I;
    while ( CO == 'S'){
  
        OP = MENU();
        switch   (OP)  {
            case 1 : VECTOR1();
                     break;
            case 2 : VECTOR2();
                	 break;
            case 3 : SUMA();
                     break;
            case 4 : RESTA();
                     break;
            case 5 : MOSTRAR();
                     break;
            case 6 : CO = 'N';
           };
       }
    }
    
/************************ M E N U ***********************/
    
 int MENU(){

   int OP ;
   system("cls");
   system("color F0");
   gotoxy(40,3) ; cout << TITULO;
   gotoxy(29,6); cout << "1. LLENAR VECTOR A DE FORMA ALEATORIA" ;
   gotoxy(29,8); cout << "2. LLENAR VECTOR B DE FORMA ALEATORIA";
   gotoxy(29,10); cout << "3. SUMA DE AMBOS VECTORES";
   gotoxy(29,12); cout << "4. RESTA DE AMBOS VECTORES";
   gotoxy(29,14); cout << "5. MOSTRAS VECTORES (A,B,C)";
   gotoxy(29,16); cout << "6. SALIR";
   do  {
        gotoxy(35,19); cout << "SELECIONE UNA DE LAS ALTERNATIVAS : ";
        cin >> OP ;
   }  while((OP < 1) || (OP > 6)) ;
   gotoxy(30,22); cout << "                          ";
   return OP ;
   }   
 /************************ VECTOR A ***********************/   
 void VECTOR1(){
 	system("cls");
    system("color F0");
	srand(time(0));
	int I=0; 
	gotoxy(40,3) ; cout << TITULO1;
	if((A[I]==0)&&(B[I]==0)){
	 gotoxy(37,7);cout<<"Introducir un valor del VECTOR A  [   ]";
	 gotoxy(73,7); cin>>NUM;
	} 	
	 for(I=0;I<NUM;I++){
	 	A[I]=(-100+rand()%100);
	 }
	gotoxy(35,9);cout<<"VECTOR  A = ";
    for(I=0;I<NUM;I++){ 
    cout <<A[I]<<"   ";	
	}
    gotoxy(40,21); cout << "Pulse cualquier tecla para salir ";
    getch();
 }
 /************************ VECTOR B ***********************/   
 void VECTOR2(){
 	system("cls");
    system("color F0");
	srand(time(0));
	int I=0; 
	gotoxy(40,3) ; cout << TITULO2;
	if((A[I]==0)&&(B[I]==0)){

	 gotoxy(37,7);cout<<"Introducir un valor del VECTOR B  [   ]";
	 gotoxy(73,7); cin>>NUM;
	}	
	 for(I=0;I<NUM;I++){
	 	B[I]=(-100+rand()%100);
	 }
     gotoxy(35,9);cout<<"VECTOR  B = ";	
	 for(I=0;I<NUM;I++){
        cout <<B[I]<<"   ";
      }
    gotoxy(40,21); cout << "Pulse cualquier tecla para salir ";
    getch();
  	
 }
 
 /************************ SUMATORIA***********************/   
 void SUMA(){
 	system("cls");
    system("color F0");
    gotoxy(40,3) ; cout << TITULO3;
    int I=0;
 	for(I=0;I<NUM;I++){
		C[I]=A[I]+B[I];
	}
	gotoxy(35,9);cout<<"SUMATORIA = ";	
	  for(I=0;I<NUM;I++){
      cout <<C[I]<<"   "; 
	 }
	gotoxy(40,21); cout << "Pulse cualquier tecla para salir ";
    getch();
 }
  /************************ RESTA***********************/   
 void RESTA(){
 	system("cls");
    system("color F0");
        gotoxy(40,3) ; cout << TITULO4;
    int I=0;
 	for(I=0;I<NUM;I++){
		CC[I]=B[I]-A[I];
	}
	gotoxy(35,9);cout<<"RESTA = ";	
	   for(I=0;I<NUM;I++){
		cout <<CC[I]<<"   ";    
   	  } 
   	gotoxy(40,21); cout << "Pulse cualquier tecla para salir ";
    getch();
	
 }
 /************************ MOSTRAR DATOS ***********************/   
 void MOSTRAR(){
 	system("cls");
 	system("color F0");
 	int SELE,I;
    gotoxy(40,3) ; cout << TITULO5;
   gotoxy(29,8); cout << "1. MOSTRAR VECTOR A" ;
   gotoxy(29,10); cout << "2. MOSTRAR VECTOR B";
   gotoxy(29,12); cout << "3. SUMATORIA DE LOS VECTORES";
   gotoxy(29,14); cout << "4. RESTA DE LOS VECTORES";

   do  {
        gotoxy(30,16); cout << "SELECIONE UNA DE LAS ALTERNATIVAS : ";
        cin >> SELE ;
        gotoxy(30,22); cout << "VALOR FUERA DE RANGO";
   }  while((SELE < 1) || (SELE > 4)) ;
   gotoxy(30,22); cout << "                          ";
  system("cls");
    switch   (SELE)  {
            case 1 : VECTOR1();
					 break;		   
            case 2 : VECTOR2();
			         break;
            case 3 : SUMA();
			     	 break;
            case 4 : RESTA();
			         break;
	
          
      };
	
 }
