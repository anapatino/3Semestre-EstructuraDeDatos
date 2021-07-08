Algoritmo TELEFONIA
	TOTAL<-0
	AUX<-0
	MIN<-0
	Escribir '         BIENVENIDO A SERVICIO DE TELEFONIA'
	Escribir '   INGRESE DURACION DE LA LLAMADA';Leer MIN
	Si (MIN<=3) Entonces
		TOTAL<-0.0685
	SiNo
		Si (MIN>3) Entonces
			AUX<-MIN-3
			TOTAL<-0.0685+(AUX*0.0240)
		Fin Si
	Fin Si
	Escribir '       TOTAL A PAGAR : ',TOTAL
	
FinAlgoritmo
