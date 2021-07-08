Algoritmo PARCIAL1
	Dimension GalonesVendidos[3,6], PROMEDIO[3];
	Dimension propietario[3],nombre[3] ,venta[3];
	PRO<-""
	NOM<-""
	VEN<-0
	I<-0
	posicion<-0
	MayorPro<-0
	ACUMULADOR<-0
	pos1<-0
	pos2<-0
	pos3<-0
	pos4<-0
	pos5<-0
	pos6<-0
	L<-0
	S<-0
	K<-0
	J<-0


	Para I<-1 Hasta 3 Con Paso 1 Hacer
		Escribir "-----------REGISTRO Nro ",I," ------------"
		Escribir "PROPIETARIO:"
		Leer propietario[I]
		Escribir "NOMBRE SERVICENTRO:"
		Leer nombre[I]
		Escribir "VENTA TOTAL SEMESTRAL:"
		Leer venta[I]
		Para L<-1 Hasta 6 Con paso 1 Hacer
			Escribir "Nro PROPIETARIO  ",I,"  Galones_Vendidos_MES ",L ," ->" 
			Leer GalonesVendidos[I,L]
			
			
		FinPara
	Fin Para

	
	////////////ORDENAMIENTO  CON METODO SELECCION////////////////////////
	
	Para K<-1 Hasta 3-1 Con Paso 1 Hacer
		
		Para S<-K+1 Hasta 3 Con Paso 1 Hacer
			
			Si (venta[K] > venta[S]) Entonces
				////// VENTA////////////
				VENT<-venta[K]
				venta[K]<-venta[S]
				venta[S]<-VENT
				////// PROPIETARIO///////////
				PRO<-propietario[K]
				propietario[K]<-propietario[S]
				propietario[S]<-PRO
				////// NOMBRE//////////
				NOM<-nombre[K]
				nombre[K]<-nombre[S]
				nombre[S]<-NOM
				//////////// GALONES CONSUMIDOS AL MES/////////
				pos1<-GalonesVendidos[K,1]
				GalonesVendidos[K,1]<-GalonesVendidos[S,1]
				GalonesVendidos[S,1]<-pos1
				
				pos2<-GalonesVendidos[K,2]
				GalonesVendidos[K,2]<-GalonesVendidos[S,2]
				GalonesVendidos[S,2]<-pos2
				
				pos3<-GalonesVendidos[K,3]
				GalonesVendidos[K,3]<-GalonesVendidos[S,3]
				GalonesVendidos[S,3]<-pos3
				
				pos4<-GalonesVendidos[K,4]
				GalonesVendidos[K,4]<-GalonesVendidos[S,4]
				GalonesVendidos[S,4]<-pos4
				
				pos5<-GalonesVendidos[K,5]
				GalonesVendidos[K,5]<-GalonesVendidos[S,5]
				GalonesVendidos[S,5]<-pos5
				
				pos6<-GalonesVendidos[K,6]
				GalonesVendidos[K,6]<-GalonesVendidos[S,6]
				GalonesVendidos[S,6]<-pos6
			Fin Si
			
		Fin Para
		
	Fin Para
	
	////////////////////////////imprimir lista ordenada///////////////
	Escribir "----------------------------------------------"
	Escribir "           REGISTRO ORDENADO                              "
	Para I<-1 Hasta 3 Con Paso 1 Hacer
		Escribir " ----------------------------------------- "
		Escribir "            REGISTRO Nro ",I,"            "
		Escribir "    PROPIETARIO: " Sin Saltar
		Escribir propietario[I]
		Escribir "   NOMBRE SERVICENTRO: " Sin Saltar
		Escribir nombre[I]
		Escribir "   VENTA TOTAL SEMESTRAL: " Sin Saltar
		Escribir venta[I]
			Para L<-1 Hasta 6 Con paso 1 Hacer
				Escribir "    Galones_Vendidos_MES ",L ,"-> " Sin Saltar
				Escribir GalonesVendidos[I,L]
			FinPara
	Fin Para
	
	///////////////////////////sacar promedio ///////////////
	
	Para I<-1 Hasta 3 Con Paso 1 Hacer
		
		Para L<-1 Hasta 6 Con Paso 1 Hacer
			ACUMULADOR<-ACUMULADOR+GalonesVendidos[I,L]
			PROMEDIO[I]<-ACUMULADOR/6;
		Fin Para
	
	Fin Para
	///////////////////////////ENCONTRAR EL MAYOR PROMEDIO ///////////////
	MayorPro<-PROMEDIO[1]
	Para I<-1 Hasta 3 Con Paso 1 Hacer
		Si(PROMEDIO[I]>MayorPro) Entonces
			MayorPro<-PROMEDIO[I]
			posicion<-I
		Fin Si
	Fin Para
	
	Para I<-1 Hasta 3 Con Paso 1 Hacer
		Si(I==posicion) Entonces
			Escribir "                  "
			Escribir "     ----------------------------------------- "
			Escribir "     EL PROMEDIO DE GALONES MAYOR VENDIDOS FUE POR-> "
			Escribir "        PROPIETARIO: " Sin Saltar
			Escribir propietario[I]
			Escribir "        NOMBRE SERVICENTRO: " Sin Saltar
			Escribir nombre[I]
			
		Fin Si
	Fin Para
FinAlgoritmo
