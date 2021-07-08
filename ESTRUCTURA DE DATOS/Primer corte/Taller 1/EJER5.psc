Algoritmo ESTRUCTURA_EJER5
	Dimension Nro_SERIE[100]
	Dimension EDAD[100]
	Dimension SEXO[100]
	Dimension PESO[100]
	Dimension HEMBRAS_ROBUSTAS[100]
	K<-0
	n<-0
	Q<-0
	Escribir "Ingrese los numeros de res";Leer Num
	Para I<-1 Hasta Num Con Paso 1 Hacer
		Escribir "NUMERO_SERIE: " I;Leer Nro_SERIE[I]
		Escribir "EDAD: "; Leer EDAD[I]
		Escribir "Digite el SEXO M <- MACHO / H <- HEMBRA " ;Leer SEXO[I]
		Escribir "PESO: "; Leer PESO[I]
	Fin Para
	K= 1
	Para I<-1 Hasta n Con Paso 1 Hacer
		Si ((PESO[I] > 40) Y (SEXO[I] = "H"))
			HEMBRAS_ROBUSTAS[K] = HEMBRAS_ROBUSTAS[I]
			Q = 1
			K= K+1
		FinSi
	Fin Para
	Escribir "NUMEROS DE LA SERIE HEMBRAS ROBUSTAS"
	Si ( Q= 1 )
		Para I<-1 Hasta K Con Paso 1 Hacer
			Escribir HEMBRAS_ROBUSTAS[I]
		Fin Para
	SiNo
		Escribir "NO HA INGRESADO RESES HEMBRAS ROBUSTAS"
	FinSi
FinAlgoritmo
