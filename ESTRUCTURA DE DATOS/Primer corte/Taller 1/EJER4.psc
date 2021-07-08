Algoritmo ESTRUCTURA_EJER4
	OP<-0;
	Dimension  A[100],B[100],C[100],CC[100];
	Repetir
        // mostrar menu
        Limpiar Pantalla
        Escribir "    CAPTURA DE VECTORES ALEATORIOS"
	    Escribir "                              "
        Escribir "    1. LLENAR VECTOR A (ALEATORIO)"
        Escribir "    2. LLENAR VECTOR B (ALEATORIO)"
        Escribir "    3. SUMA DE AMBOS VECTORES"
        Escribir "    4. RESTA DE AMBOS VECTORES"
	   Escribir "    5. MOSTRAS VECTORES (A,B,C)"
	   Escribir "    6. SALIR"

        Escribir "       Elija una opción (1-6): "Sin Saltar
        Leer OPI

        Segun OPI Hacer
            1:    Escribir"           "
                  Escribir "LLENAR VECTOR A (ALEATORIO)"
				 Escribir " Ingresa Nro hasta donde desea llegar->";Leer NUM
				Para I<-1 Hasta NUM Con Paso 1 Hacer
					A(I)=azar(100)
				Fin Para
            2:     Escribir"           "
				Escribir "LLENAR VECTOR B (ALEATORIO)"
				Escribir " Ingresa Nro hasta donde desea llegar->";Leer NUM
				Para I<-1 Hasta NUM Con Paso 1 Hacer
					B(I)=azar(100)
				Fin Para
            3:
                Para I<-1 Hasta NUM Con Paso 1 Hacer
					C(I)<-A(I)+B(I)
				Fin Para
            4:
				Para I<-1 Hasta NUM Con Paso 1 Hacer
					CC(I)<-A(I)-B(I)
				Fin Para
				
		   5:	
			   Limpiar Pantalla
			   Escribir"           "
			   Escribir "        MOSTRAR VECTORES(A,B,C)"
			   Escribir "   1.  VECTOR A (ALEATORIO)"
			   Escribir "   2.  VECTOR B (ALEATORIO)"
			   Escribir "   3.  SUMA DE VECTORES"
			   Escribir "   4.  RESTA DE VECTORES"
			   Escribir "   5. SALIR"
			   
			   Escribir "Elija una opción (1-5): "
			   Leer OP
			   Si  (OP==1)Entonces
				   Escribir"           "
				   Escribir "    VECTOR A "
				   Para I<-1 Hasta NUM Con Paso 1 Hacer
					   Escribir A(I) ,"  "Sin Saltar;
				   Fin Para
				   Escribir " "
			   SiNo
				   Si  (OP==2)Entonces
					   Escribir " "
					   Escribir "    VECTOR B "
					   Para I<-1 Hasta NUM Con Paso 1 Hacer
						   Escribir B(I) ,"  "Sin Saltar;
					   Fin Para
					   Escribir " "
				   SiNo
					   Si  (OP==3)Entonces
						   Escribir " "
						   Escribir "    SUMATORIA "
						   Para I<-1 Hasta NUM Con Paso 1 Hacer
							   Escribir C(I) ,"  "Sin Saltar;
						   Fin Para
						   Escribir " "
					   SiNo
						   Si  (OP==4)Entonces
							   Escribir " "
							   Escribir "    RESTA "
							   Para I<-1 Hasta NUM Con Paso 1 Hacer
								   Escribir CC(I) ,"  "Sin Saltar;
							   Fin Para
							   Escribir"           "
							   
						   Fin Si
					   Fin Si
				   Fin Si
			   Fin Si
				
            6:
                Escribir "EL PROGRAMA HA TERMINADO"
				Escribir " "
            De otro modo:
                Escribir "OPCION NO VALIDA"
				Escribir " "
        FinSegun
        Escribir "Presione enter para continuar"
		Escribir " "
        Esperar Tecla
    Hasta Que OP=6
	
FinAlgoritmo
