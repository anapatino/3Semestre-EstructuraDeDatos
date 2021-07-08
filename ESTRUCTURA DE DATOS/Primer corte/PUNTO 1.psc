Algoritmo ELICTRICARIBE
	NOM<-' '
	DIRE<-' '
	T_CLIENTE<-0
	VALOR_FAC<-0
	KWH<-0
	Escribir '         BIENVENIDO A ELECTRICARIBE'
	Escribir '   INGRESE SUS DATOS'
	Escribir '  NOMBRE: ';Leer NOM
	Escribir '  DIRECCION: ';Leer DIRE
	Escribir '  Nro KWH : ';Leer KWH
	Escribir '  TIPO_CLIENTE: '
	Escribir '0 <- particular   1 <-empresa   ';Leer T_CLIENTE
	Si (T_CLIENTE=0) Entonces
		VALOR_FAC=VALOR_FAC+200
		Si (KWH>=0) Y (KWH<=20) Entonces
			VALOR_FAC=VALOR_FAC+10
		SiNo
			Si (KWH>=21) Y (KWH<=50) Entonces
				VALOR_FAC=VALOR_FAC+15
			SiNo
				Si (KWH>=51) Y (KWH<=100) Entonces
					VALOR_FAC=VALOR_FAC+25
				SiNo
					Si (KWH>=100) Entonces
						VALOR_FAC=VALOR_FAC+30
					Fin Si
				Fin Si
			Fin Si
		Fin Si
	SiNo
		Si (T_CLIENTE=1) Entonces
			VALOR_FAC=VALOR_FAC+500
			Si (KWH>=0) Y (KWH<=20) Entonces
				VALOR_FAC=VALOR_FAC+10
			SiNo
				Si (KWH>=21) Y (KWH<=50) Entonces
					VALOR_FAC=VALOR_FAC+20
				SiNo
					Si (KWH>=51) Y (KWH<=100) Entonces
						VALOR_FAC=VALOR_FAC+30
					SiNo
						Si (KWH>=100) Entonces
							VALOR_FAC=VALOR_FAC+50
						Fin Si
					Fin Si
				Fin Si
			Fin Si
		SiNo	
			Escribir ' Nro tipo cliente ingresado invalido'
		Fin Si
	Fin Si
	Si (T_CLIENTE=0)y(T_CLIENTE=1) Entonces
		Escribir '       F A C T U R A   P O R  C L I E N T E'
		Escribir '   NOMBRE       : ',NOM
		Escribir '   DIRECCION    : ',DIRE
		Escribir '   TIPO_CLIENTE : ', T_CLIENTE
		Escribir '   Nro KWH      : ', KWH
		Escribir '         VALOR A PAGAR : ',VALOR_FAC
	SiNo
		Escribir '        SU FACTURA NO HA SIDO PROCESADA'
	Fin Si

FinAlgoritmo
