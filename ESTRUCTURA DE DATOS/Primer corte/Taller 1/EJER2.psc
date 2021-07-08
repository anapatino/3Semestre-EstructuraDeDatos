Algoritmo ESTRUCTURA_EJER1
	Definir NUM,I,F,DEF,REG,BUE,EXC como entero
	Dimension NOTAS(20);
	Escribir "    CALIFICACION ALEATORIA"
	Para I<-1 Hasta 20 Con Paso 1 Hacer
		NOTAS(I)=azar(5)
		Si NOTAS(I)>=0 Y NOTAS(I)<=1 Entonces
			DEF<-DEF+1
		SiNo
			Si NOTAS(I)>=1 Y NOTAS(I)<=3 Entonces
				REG<-REG+1
			SiNo
				Si NOTAS(I)>=3 Y NOTAS(I)<=4 Entonces
					BUE<-BUE+1
				SiNo
					Si NOTAS(I)>=4 Y NOTAS(I)<=5 Entonces
						DEF<-DEF+1
					Fin Si
				Fin Si
			Fin Si
		Fin Si
	Fin Para
	
	Para K<-1 Hasta 20 Con Paso 1 Hacer
		Escribir "  ",K," .NOTA-> ",NOTAS(K)
	Fin Para
	
	Escribir "  EST_DEFICIENTES  -> ",DEF;
	Escribir "  EST_REGULARES    -> ",REG; 	
     Escribir "  EST_BUENOS       -> ",BUE;
     Escribir "  EST_EXCELENTES   -> ",EXC;

FinAlgoritmo
