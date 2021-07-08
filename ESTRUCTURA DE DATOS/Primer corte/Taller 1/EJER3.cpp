 
#include <stdio.h>                       
#include <windows.h>                      
#include <iostream>                      
#include <conio.h>                       
#include <ctype.h>
using namespace std;                     

int gotoxy(USHORT x,USHORT y){                                  
COORD cp={x,y};                                                 
SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),cp);   // sentencia gotoxy
}

main(){
	system("cls");
    system("color F0");
	int A[5],B[5], C[5],D[5],E[5];
	int I=0,CONT=0,K=0;
	 gotoxy(40,3);cout<<"S U M A   D E   V E C T O R E S";
	 gotoxy(37,7);cout<<"VECTOR  A ";
	 	
	for(I=0;I<5;I++){
     gotoxy(37,9); cout << "Introducir un valor en las posiciones " <<I+1<<" [   ]" ;
     gotoxy(79,9); cin>>A[I];
     E[I]=A[I];
	}
    gotoxy(37,7);cout<<"VECTOR  B ";	
	for(I=0;I<5;I++){
     gotoxy(37,9); cout << "Introducir un valor en las posiciones " <<I+1<<" [   ]" ;
     gotoxy(79,9); cin>>B[I];
	}	
	for(I=0;I<5;I++){
		C[I]=A[I]+B[I];
	}
	for(I=0;I<5;I++){
		for(K=0;K<5;K++){
	
		if (A[I]==B[K]){
	  	 D[CONT]=A[I];
	  	 CONT++;
	    }	
    	}
	}	
	
	
	/*********************IMPRIMIR DATOS*******/
	system("cls");
    gotoxy(40,3);cout<<"S U M A   D E   V E C T O R E S";
	gotoxy(35,7);cout<<"VECTOR  A = ";	
	for(I=0;I<5;I++){
     cout <<A[I]<<"   ";
    
	}
	gotoxy(35,10);cout<<"VECTOR  B = ";	
	for(I=0;I<5;I++){
     cout <<B[I]<<"   ";
	}
	
	gotoxy(35,13);cout<<"SUMATORIA = ";	
	for(I=0;I<5;I++){
     cout <<C[I]<<"   ";
     
	}
	
	gotoxy(35,16);cout<<"VECTOR D = ";	
	for(I=0;I<CONT;I++){
		 cout <<D[I]<<"   ";
          
   	} 
	    
    gotoxy(35,19);cout<<"VECTOR E = ";	
	for(I=4;I>=0;I--){
     cout <<E[I]<<"   ";
   	}  
	
	
	gotoxy(40,24); cout << "Pulse cualquier tecla para salir ";
       getch();
	
	
	
	
	
	
	
	
}
