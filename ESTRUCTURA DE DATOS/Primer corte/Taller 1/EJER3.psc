Algoritmo ESTRUCTURA_EJER2
	Definir I,CONT,K ,NUM como entero

	Escribir "    CALIFICACION ALEATORIA"
	Escribir " Ingresa Nro hasta donde desea llegar->";Leer NUM
	Dimension A(NUM),B(NUM),C(NUM),D(NUM),E(NUM);
	
	Para I<-1 Hasta NUM Con Paso 1 Hacer
		Escribir "    VECTOR A [" ,I,"] ->";Leer A(I)
		E(I)<-A(I)
	Fin Para
	Para I<-1 Hasta NUM Con Paso 1 Hacer
		Escribir "    VECTOR B [" ,I,"] ->";Leer B(I)
	Fin Para
	
	Para I<-1 Hasta NUM Con Paso 1 Hacer
		C(I)<-A(I)+B(I)
	Fin Para
	Para I<-1 Hasta NUM Con Paso 1 Hacer
	    Para K<-1 Hasta NUM Con Paso 1 Hacer
			Si (A(I)==B(I)) Entonces
				D(CONT)<-A(I)
				CONT<-CONT+1
			Fin Si
		Fin Para
	Fin Para
	////////IMPRIMR////////////////////
	Escribir "    S U M A   D E   V E C T O R E S"
	Escribir "    VECTOR A "
	Para I<-1 Hasta NUM Con Paso 1 Hacer
		Escribir A(I) ,"  "Sin Saltar;
	Fin Para
	Escribir " "
	Escribir "    VECTOR B "
	Para I<-1 Hasta NUM Con Paso 1 Hacer
		Escribir B(I) ,"  "Sin Saltar;
	Fin Para
	Escribir " "
	Escribir "    SUMATORIA "
	Para I<-1 Hasta NUM Con Paso 1 Hacer
		Escribir C(I) ,"  "Sin Saltar;
	Fin Para
	Escribir " "
	Escribir "    VECTOR E "
	Para I<-NUM Hasta 1 Con Paso -1 Hacer
		Escribir E(I) ,"  "Sin Saltar;
	Fin Para
	Escribir " "
	Escribir "    VECTOR D "
	Para I<-1 Hasta CONT Con Paso 1 Hacer
		Escribir D(I) ,"  ";
	Fin Para
	
FinAlgoritmo
