#include <stdio.h>                       
#include <windows.h>                      
#include <iostream>  
#include<ctime>  
#include<stdlib.h>                  


using namespace std;                     

int gotoxy(USHORT x,USHORT y){                                  
COORD cp={x,y};                                                 
SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),cp);   // sentencia gotoxy
}

main(){
 system("cls");
 system("color F0");	
 srand(time(0));	
  float  NOTAS[20];
  int I=0,F,DEF=0,REG=0,BUE=0,EXC=0;
  gotoxy(23,4);cout<<"CALIFICACION ALEATORIA";
  for(I=0;I<20;I++){
  	NOTAS[I]=(float)(1+rand()%5);
  	
  	if(NOTAS[I]>=0 && NOTAS[I]<=1 ){
  		DEF++;
	  }else{
	  	  if(NOTAS[I]>=1,1 && NOTAS[I]<=3 ){
  	     	REG++;
	       } else{
	       	     if(NOTAS[I]>=3,1 && NOTAS[I]<=4 ){
  		           BUE++;
	              }else{
	              	   if(NOTAS[I]>=4,1 && NOTAS[I]<=5 ){
  	                	 EXC++;
	                    }
				  }
	              
		        }
	    }
	}  
  	
 F=6;
  for(I=0;I<20;I++){
  	gotoxy(25,F);cout<<"NOTA "<<I+1<<" -> "<<NOTAS[I]<<endl;
  	F++;
  	
   }
   
  gotoxy(24,28);cout<<"EST_DEFICIENTES  -> "<<DEF;
  gotoxy(24,29);cout<<"EST_REGULARES    -> "<<REG; 	
  gotoxy(24,30);cout<<"EST_BUENOS       -> "<<BUE;
  gotoxy(24,31);cout<<"EST_EXCELENTES   -> "<<EXC;
  
}
