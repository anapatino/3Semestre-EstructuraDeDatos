Algoritmo Serie_Fibonacci
		ANTER<-0
		DESP<-1
		SIGU<-0
		K<-0
		N<-0
		SUM<-0
		Escribir '         BIENVENIDO A LA SERIE FIBONACCI'
		Escribir '   INGRESE HASTA DONDE LLEGAR';Leer N;
		N<-N-2
		Escribir ANTER
		Escribir DESP
		Para K<-1 Hasta N Con Paso 1 Hacer
			SIGU<-ANTER+ DESP
			SUM<-SUM+SIGU
			Escribir SIGU
			ANTER<-DESP
			DESP<-SIGU
		Fin Para
		Escribir '       SUMATORIA : ',SUM
FinAlgoritmo


