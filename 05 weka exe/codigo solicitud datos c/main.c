#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	int edad=0, estudios=0, claseSocial=0, trabajo=0, tamMunicipio=0, sexo=0;
	printf ("PASO 1 introduzca su edad segun la siguiente tabla\n");
	printf (" 10= DE 0 A 4 ANIOS \n 11= DE 5 A 15 ANIOS \n 12= DE 16 A 24 ANIOS \n 13= DE 25 A 34 ANIOS \n 14= DE 35 A 44 ANIOS \n 15= DE 45 A 54 ANIOS \n 16= DE 55 A 64 ANIOS \n 17= DE 65 A 74 ANIOS\n 18= DE 75 Y MAS ANIOS\n");
	scanf ("%d", &edad );
	
	if (edad < 10 || edad >18){
		printf("error");
		return -1;
	}
	printf ("PASO 2 introduzca su nivel de estudios segun la siguiente tabla\n");
	printf (" 20= SIN ESTUDIOS \n 21= PRIMER CICLO \n 22= SEGUNDO CICLO \n 23= UNIV \n");
	scanf ("%d", &estudios );
	if (estudios < 20 || estudios >23){
		printf("error");
		return -1;
	}
	printf ("PASO 3 introduzca su nivel social segun la siguiente tabla\n");
	printf ("30= CLASE I. DIRECTIVOS DE LA ADMINISTRACIÓN PUBLICA Y DE EMPRESAS DE 10 O MAS ASALARIADOS. PROFESIONES ASOCIADAS A TITULACIONES DE 2 Y 3 CICLO \n");
	printf ("31= CLASE II.  DIRECTIVOS DE EMPRESAS DE MENOS DE 10 ASALARIADOS. PROFESIONES ASOCIADAS A UNA TITULACIÓN DE 1ER CICLO UNIVERSITARIO. TECNICOS SUPERIORES. ARTISTAS Y DEPORTISTAS  \n");
	printf ("32= CLASE III. EMPLEADOS DE TIPO ADMINISTRATIVO Y PROFESIONALES DE APOYO A LA GESTION ADMINISTRATIVA Y FINANCIERA. TRABAJADORES DE LOS SERVICIOS PERSONALES Y DE SEGURIDAD. TRABAJADORES POR CUENTA PROPIA. SUPERVISORES DE TRABAJADORES MANUALES\n");
	printf ("33= CLASE Iva. TRABAJADORES MANUALES CUALIFICADOS \n");
	printf ("34= CLASEIvb. TRABAJADORES MANUALES SEMICUALIFICADOS \n");
	printf ("35= CLASE V. TRABAJADORES NO CUALIFICADOS  \n");
	printf ("36= CLASE VI. OTROS  \n");
	printf ("37= CLASE VII. NO CONSTA  \n");
	scanf ("%d", &claseSocial );
	if (claseSocial < 30 || claseSocial >37){
		printf("error");
		return -1;
	}
	
	printf ("PASO 4 introduzca su situacion laboral segun la siguiente tabla\n");
	printf (" 40= OCUPADO \n 41= PARADO \n 42= INACTIVO \n");	
	 	scanf ("%d", &trabajo );
	if (trabajo < 40 || trabajo >42){
		printf("error");
		return -1;
	}

	printf ("PASO 5 introduzca el numero de habitantes de la poblacion que reside segun la siguiente tabla\n");
	printf (" 50= MENOR O IGUAL A 2.000 HABITANTES \n 51= 2.001 A 50.000 HABITANTES \n 52= MAS DE 50.000 HABITANTES \n");	
	 	scanf ("%d", &tamMunicipio );
	if (tamMunicipio < 50 || tamMunicipio >52){
		printf("error");
		return -1;
	}
	printf ("PASO 6 introduzca su sexo segun la siguiente tabla\n");
	printf (" 100= HOMBRE \n 101= MUJER \n");	
	 	scanf ("%d", &sexo );
	if (sexo < 100 || tamMunicipio >101){
		printf("error");
		return -1;
	}
	
	FILE * persona;
	persona = fopen ("persona.arff", "w");
		fprintf(persona, "%% ATRIBUTOS\n");
		fprintf(persona, "%% EDAD; \n");
		fprintf(persona, "%%		10= DE 0 A 4 AÑOS \n");
		fprintf(persona, "%%		11= DE 5 A 15 AÑOS \n");
		fprintf(persona, "%%		12= DE 16 A 24 AÑOS \n");
		fprintf(persona, "%%		13= DE 25 A 34 AÑOS \n");
		fprintf(persona, "%%		14= DE 35 A 44 AÑOS \n");
		fprintf(persona, "%%		15= DE 45 A 54 AÑOS \n");
		fprintf(persona, "%%		16= DE 55 A 64 AÑOS \n");
		fprintf(persona, "%%		17= DE 65 A 74 AÑOS \n");
		fprintf(persona, "%%		18= DE 75 Y MÁS AÑOS \n");
		fprintf(persona, "%% ESTUDIOS; \n");
		fprintf(persona, "%%  	20= SIN ESTUDIOS \n");
		fprintf(persona, "%%		21= PRIMER CICLO \n");
		fprintf(persona, "%%		22= SEGUNDO CICLO \n");
		fprintf(persona, "%%		23= UNIV \n");
		fprintf(persona, "%% CLASE SOCIAL; \n");
		fprintf(persona, "%%		30= CLASE I \n");
		fprintf(persona, "%%		31= CLASE II \n");
		fprintf(persona, "%%		32= CLASE III \n");
		fprintf(persona, "%%		33= CLASE Iva \n");
		fprintf(persona, "%%		34= CLASEIvb \n");
		fprintf(persona, "%%		35= CLASE V \n");
		fprintf(persona, "%%		36= CLASE VI \n");
		fprintf(persona, "%%		37= NO CONSTA \n");
		fprintf(persona, "%% TRABAJO; \n");
		fprintf(persona, "%%		40= OCUPADO \n");
		fprintf(persona, "%%		41= PARADO \n");
		fprintf(persona, "%%		42= INACTIVO \n");
		fprintf(persona, "%% TAMAÑO POBLACION; \n");
		fprintf(persona, "%%		30= MENOR O IGUAL A 2.000 HABITANTES \n");
		fprintf(persona, "%%		31= 2.001 A 50.000 HABITANTES \n");
		fprintf(persona, "%%		32= MÁS DE 50.000 HABITANTES \n");
		fprintf(persona, "%%		32= MÁS DE 50.000 HABITANTES \n");
		fprintf(persona, "%% SEXO; \n");
		fprintf(persona, "%%		100= HOMBRE \n");
		fprintf(persona, "%%		101= MUJER \n");
		fprintf(persona, "%% CLASS \n");
		fprintf(persona, "%% 		1=  HIPERTENSO \n");
		fprintf(persona, "%% 		2=  NORMOTENSO \n");

		
		fprintf(persona, "@relation hypertension \n");
		fprintf(persona, "@attribute edad {10, 11, 12, 1,3 14, 15, 16, 17, 18} \n");
		fprintf(persona, "@attribute estudios {20, 21, 22, 23} \n");
		fprintf(persona, "@attribute claseSocial {30, 31, 32, 33, 34, 35, 36, 37}\n");
		fprintf(persona, "@attribute trabajo {40, 41, 42} \n");
		fprintf(persona, "@attribute municipio {50, 51, 52} \n");
		fprintf(persona, "@attribute sexo {100, 101} \n");
		fprintf(persona, "@attribute class {1, 2} \n");
		fprintf(persona, "@data \n");
		fprintf(persona, "%d %d %d %d %d %d ? \n",edad, estudios, claseSocial, trabajo, tamMunicipio, sexo );
		
		
		fclose(persona);

		
	return 0;
}
