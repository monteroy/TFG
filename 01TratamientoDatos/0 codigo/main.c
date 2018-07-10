#include <stdio.h>
#include <stdlib.h>

#define NOM_ARCHIVO "salidaJson.json"
#define NUM_TABLAS 5
#define ATRIBUTOS 8

struct atributo {
		int Edad,Estudios,Trabajo,claseSocial,Municipio,sexo,clase,cantidad;
};

int main(int argc, char *argv[]) {
	 
//1.- lectura de los datos
	//variables
	int contadorDatosIniciales=0, *datos_init= malloc(sizeof(int)), *datos_init_tmp;
	//apertura y comprobacion del archivo
	FILE *f = fopen(NOM_ARCHIVO, "r");//abrimos archivo como lectura
	if (f==NULL){
		perror ("Error al abrir fichero json");
		return -1;
	}
	//lectura y almacenamiento de los datos
    while (!feof(f)) {
    	fscanf(f, "%d;", &datos_init[contadorDatosIniciales]);//metemos los datos_init del archivo en un array
    	//printf ("%d,",datos_init[contadorDatosIniciales]); // comprobacion datos entrada
    	contadorDatosIniciales++;
    	datos_init_tmp = realloc (datos_init, (1+contadorDatosIniciales)*sizeof(int));//asignamos la memoria dinamicamente (la aumentamos)
    	if (datos_init_tmp==NULL){
    		free(datos_init_tmp);
    		exit(1);
    	}
    	datos_init =datos_init_tmp;
    	datos_init_tmp=NULL;
    }
//2.- a la salida de este bucle tenemos un array con los datos_init de enfermo si, no y total = suma de ambos
	//variables
	int auxContadorDatos=0, contadorDatos=0;
	//el total no interesa, lo eliminamos con el siguiente bucle
	for (auxContadorDatos=1;auxContadorDatos<contadorDatosIniciales+1;auxContadorDatos++){
		if (auxContadorDatos%3!=0){
   			datos_init[contadorDatos]= datos_init[auxContadorDatos-1];
   			//printf("%d %d \n",contadorDatos, datos_init[contadorDatos]);
   			contadorDatos++;
   		}
	}

//3.- se separan los datos en clase enfermo si y clase enfermo no
	//variables
	struct atributo atributos[contadorDatosIniciales]; //la estructura es mas grande aseguro que no hay problemas

	//inicializaciï¿½n de la estructura
	for (auxContadorDatos=0;auxContadorDatos<contadorDatos;auxContadorDatos++){
		atributos[auxContadorDatos].Edad= 0;
		atributos[auxContadorDatos].Estudios=0;
		atributos[auxContadorDatos].Trabajo=0;
		atributos[auxContadorDatos].claseSocial=0;
		atributos[auxContadorDatos].Municipio=0;
		atributos[auxContadorDatos].sexo =0;
		atributos[auxContadorDatos].clase =0;
		atributos[auxContadorDatos].cantidad=0;
	}
	//acumulador de filas para la matriz de salida
	int filas=0;
	//*****atributo edad hombres enfermos y sanos
int	edadHombreSi=10,edadHombreNo=10;
int sumaClaseSiEdadHombre=0,sumaClaseNoEdadHombre=0 ;
int auxClase=0, contadorWhile=0, filasTotal=0;

while (sumaClaseNoEdadHombre != datos_init[auxClase+1] || datos_init[auxClase+1] == 0){	
	if (auxClase%2 ==0 ){
		atributos[contadorWhile].Edad= edadHombreSi++;
		atributos[contadorWhile].Estudios=0;
		atributos[contadorWhile].Trabajo=0;
		atributos[contadorWhile].claseSocial=0;
		atributos[contadorWhile].Municipio=0;
		atributos[contadorWhile].sexo =100;
		atributos[contadorWhile].clase =1;
		atributos[contadorWhile].cantidad=datos_init[auxClase];
		sumaClaseSiEdadHombre += datos_init[auxClase];
		filas +=  datos_init[auxClase]/NUM_TABLAS;
		filasTotal+=datos_init[auxClase];
		contadorWhile++;				
	}else if (auxClase%2 !=0 ){
		atributos[contadorWhile].Edad= edadHombreNo++;
		atributos[contadorWhile].Estudios=0;
		atributos[contadorWhile].Trabajo=0;
		atributos[contadorWhile].claseSocial=0;
		atributos[contadorWhile].Municipio=0;
		atributos[contadorWhile].sexo =100;
		atributos[contadorWhile].clase =2;
		atributos[contadorWhile].cantidad=datos_init[auxClase];
		sumaClaseNoEdadHombre += datos_init[auxClase];
		filas +=  datos_init[auxClase]/NUM_TABLAS;
		filasTotal+=datos_init[auxClase];
		contadorWhile++;	
	}
	auxClase++;
}
//*****atributo edad mujeres enfermas y sanas
	int	edadMujerSi=10,edadMujerNo=10;
	int sumaClaseSiEdadMujer=0,sumaClaseNoEdadMujer=0 ;
	auxClase+=2;
while (sumaClaseNoEdadMujer != datos_init[auxClase+1] || datos_init[auxClase+1] == 0){	
	if (auxClase%2 ==0 ){
		atributos[contadorWhile].Edad= edadMujerSi++;
		atributos[contadorWhile].Estudios=0;
		atributos[contadorWhile].Trabajo=0;
		atributos[contadorWhile].claseSocial=0;
		atributos[contadorWhile].Municipio=0;
		atributos[contadorWhile].sexo =101;
		atributos[contadorWhile].clase =1;
		atributos[contadorWhile].cantidad=datos_init[auxClase];
		sumaClaseSiEdadMujer += datos_init[auxClase];
		filas +=  datos_init[auxClase]/NUM_TABLAS;
		filasTotal+=datos_init[auxClase];
		contadorWhile++;			
	}else if (auxClase%2 !=0 ){
		atributos[contadorWhile].Edad= edadMujerNo++;
		atributos[contadorWhile].Estudios=0;
		atributos[contadorWhile].Trabajo=0;
		atributos[contadorWhile].claseSocial=0;
		atributos[contadorWhile].Municipio=0;
		atributos[contadorWhile].sexo =101;
		atributos[contadorWhile].clase =2;
		atributos[contadorWhile].cantidad=datos_init[auxClase];
		sumaClaseNoEdadMujer += datos_init[auxClase];
		filas +=  datos_init[auxClase]/NUM_TABLAS;
		filasTotal+=datos_init[auxClase];
		contadorWhile++;	
	}
	auxClase++;
}	
	// contador para evitar las sumas de hombre y mujer
	int contadorAtributos=1;
	int auxContadorAtributos=0;
	for (auxContadorAtributos=0; auxContadorAtributos<2+((contadorWhile)/(contadorAtributos*2));auxContadorAtributos++){
		auxClase++;
	}
	
	
	//*****atributo estudios hombres enfermos y sanos
	int	estudiosHombreSi=20,estudiosHombreNo=20;
	int sumaClaseSiEstudiosHombre=0,sumaClaseNoEstudiosHombre=0 ;
	auxClase+=2;
while (sumaClaseNoEstudiosHombre != datos_init[auxClase+1]-1){	
	if (auxClase%2 ==0 ){
		atributos[contadorWhile].Edad= 0;
		atributos[contadorWhile].Estudios=estudiosHombreSi++;
		atributos[contadorWhile].Trabajo=0;
		atributos[contadorWhile].claseSocial=0;
		atributos[contadorWhile].Municipio=0;
		atributos[contadorWhile].sexo =100;
		atributos[contadorWhile].clase =1;
		atributos[contadorWhile].cantidad=datos_init[auxClase];
		sumaClaseSiEstudiosHombre += datos_init[auxClase];
		filas +=  datos_init[auxClase]/NUM_TABLAS;
		filasTotal+=datos_init[auxClase];
		contadorWhile++;				
	}else if (auxClase%2 !=0 ){
		atributos[contadorWhile].Edad= 0;
		atributos[contadorWhile].Estudios=estudiosHombreNo++;
		atributos[contadorWhile].Trabajo=0;
		atributos[contadorWhile].claseSocial=0;
		atributos[contadorWhile].Municipio=0;
		atributos[contadorWhile].sexo =100;
		atributos[contadorWhile].clase =2;
		atributos[contadorWhile].cantidad=datos_init[auxClase];
		sumaClaseNoEstudiosHombre += datos_init[auxClase];
		filas +=  datos_init[auxClase]/NUM_TABLAS;
		filasTotal+=datos_init[auxClase];
		contadorWhile++;
	}
	auxClase++;
}	
	//*****atributo estudios mujeres enfermas y sanas
	int	estudiosMujerSi=20,estudiosMujerNo=20;
	int sumaClaseSiEstudiosMujer=0,sumaClaseNoEstudiosMujer=0 ;
	auxClase+=2;
while (sumaClaseNoEstudiosMujer != datos_init[auxClase+1]){	
	if (auxClase%2 ==0 ){
		atributos[contadorWhile].Edad= 0;
		atributos[contadorWhile].Estudios=estudiosMujerSi++;
		atributos[contadorWhile].Trabajo=0;
		atributos[contadorWhile].claseSocial=0;
		atributos[contadorWhile].Municipio=0;
		atributos[contadorWhile].sexo =101;
		atributos[contadorWhile].clase =1;
		atributos[contadorWhile].cantidad=datos_init[auxClase];
		sumaClaseSiEstudiosMujer += datos_init[auxClase];
		filas +=  datos_init[auxClase]/NUM_TABLAS;
		filasTotal+=datos_init[auxClase];
		contadorWhile++;				
	}else if (auxClase%2 !=0 ){
		atributos[contadorWhile].Edad= 0;
		atributos[contadorWhile].Estudios=estudiosMujerNo++;
		atributos[contadorWhile].Trabajo=0;
		atributos[contadorWhile].claseSocial=0;
		atributos[contadorWhile].Municipio=0;
		atributos[contadorWhile].sexo =101;
		atributos[contadorWhile].clase =2;
		atributos[contadorWhile].cantidad=datos_init[auxClase];
		sumaClaseNoEstudiosMujer += datos_init[auxClase];
		filas +=  datos_init[auxClase]/NUM_TABLAS;
		filasTotal+=datos_init[auxClase];
		contadorWhile++;	
	}
	auxClase++;
}	
	// contador para evitar las sumas de hombre y mujer
	contadorAtributos++;
	for (auxContadorAtributos=0; auxContadorAtributos<((contadorWhile)/(contadorAtributos*2)-1);auxContadorAtributos++){
		auxClase++;
	}
	//*****atributo  clase social hombres enfermos y sanos
	int	claseSHombreSi=30,claseSHombreNo=30;
	int sumaClaseSiClaseSHombre=0,sumaClaseNoClaseSHombre=0 ;
	
while (sumaClaseNoClaseSHombre != datos_init[auxClase+1]+1){	
	if (auxClase%2 ==0 ){
		atributos[contadorWhile].Edad= 0;
		atributos[contadorWhile].Estudios=0;
		atributos[contadorWhile].Trabajo=0;
		atributos[contadorWhile].claseSocial=claseSHombreSi++;
		atributos[contadorWhile].Municipio=0;
		atributos[contadorWhile].sexo =100;
		atributos[contadorWhile].clase =1;
		atributos[contadorWhile].cantidad=datos_init[auxClase];
		sumaClaseSiClaseSHombre += datos_init[auxClase];
		filas +=  datos_init[auxClase]/NUM_TABLAS;
		filasTotal+=datos_init[auxClase];
		contadorWhile++;				
	}else if (auxClase%2 !=0 ){
		atributos[contadorWhile].Edad= 0;
		atributos[contadorWhile].Estudios=0;
		atributos[contadorWhile].Trabajo=0;
		atributos[contadorWhile].claseSocial=claseSHombreNo++;
		atributos[contadorWhile].Municipio=0;
		atributos[contadorWhile].sexo =100;
		atributos[contadorWhile].clase =2;
		atributos[contadorWhile].cantidad=datos_init[auxClase];
		sumaClaseNoClaseSHombre += datos_init[auxClase];
		filas +=  datos_init[auxClase]/NUM_TABLAS;
		filasTotal+=datos_init[auxClase];
		contadorWhile++;	
	}
	auxClase++;
}	
//*****atributo clase social mujeres enfermas y sanas
	int	claseSMujerSi=30,claseSMujerNo=30;
	int sumaClaseSiClaseSMujer=0,sumaClaseNoClaseSMujer=0 ;
	auxClase +=2;
while (sumaClaseNoClaseSMujer != datos_init[auxClase+1]){	
	if (auxClase%2 ==0 ){
		atributos[contadorWhile].Edad= 0;
		atributos[contadorWhile].Estudios=0;
		atributos[contadorWhile].Trabajo=0;
		atributos[contadorWhile].claseSocial=claseSMujerSi++;
		atributos[contadorWhile].Municipio=0;
		atributos[contadorWhile].sexo =101;
		atributos[contadorWhile].clase =1;
		atributos[contadorWhile].cantidad=datos_init[auxClase];
		sumaClaseSiClaseSMujer += datos_init[auxClase];
		filas +=  datos_init[auxClase]/NUM_TABLAS;
		filasTotal+=datos_init[auxClase];
		contadorWhile++;				
	}else if (auxClase%2 !=0 ){
		atributos[contadorWhile].Edad= 0;
		atributos[contadorWhile].Estudios=0;
		atributos[contadorWhile].Trabajo=0;
		atributos[contadorWhile].claseSocial=claseSMujerNo++;
		atributos[contadorWhile].Municipio=0;
		atributos[contadorWhile].sexo =101;
		atributos[contadorWhile].clase =2;
		atributos[contadorWhile].cantidad=datos_init[auxClase];
		sumaClaseNoClaseSMujer += datos_init[auxClase];
		filas +=  datos_init[auxClase]/NUM_TABLAS;
		filasTotal+=datos_init[auxClase];
		contadorWhile++;	
	}
	auxClase++;
}	

	// contador para evitar las sumas de hombre y mujer
	contadorAtributos++;
	for (auxContadorAtributos=0; auxContadorAtributos<4+((contadorWhile)/(contadorAtributos*2));auxContadorAtributos++){
		auxClase++;
	}

//*****atributo trabajo hombres enfermos y sanos
	int	trabajoHombreSi=40,trabajoHombreNo=40;
	int sumaClaseSiTrabajoHombre=0,sumaClaseNoTrabajoHombre=0 ;
	auxClase+=2;
while (sumaClaseNoTrabajoHombre != datos_init[auxClase+1]){	
	if (auxClase%2 ==0 ){
		atributos[contadorWhile].Edad= 0;
		atributos[contadorWhile].Estudios=0;
		atributos[contadorWhile].Trabajo=trabajoHombreSi++;
		atributos[contadorWhile].claseSocial=0;
		atributos[contadorWhile].Municipio=0;
		atributos[contadorWhile].sexo =100;
		atributos[contadorWhile].clase =1;
		atributos[contadorWhile].cantidad=datos_init[auxClase];
		sumaClaseSiTrabajoHombre += datos_init[auxClase];
		filas +=  datos_init[auxClase]/NUM_TABLAS;
		filasTotal+=datos_init[auxClase];
		contadorWhile++;				
	}else if (auxClase%2 !=0 ){
		atributos[contadorWhile].Edad= 0;
		atributos[contadorWhile].Estudios=0;
		atributos[contadorWhile].Trabajo=trabajoHombreNo++;
		atributos[contadorWhile].claseSocial=0;
		atributos[contadorWhile].Municipio=0;
		atributos[contadorWhile].sexo =100;
		atributos[contadorWhile].clase =2;
		atributos[contadorWhile].cantidad=datos_init[auxClase];
		sumaClaseNoTrabajoHombre += datos_init[auxClase];
		filas +=  datos_init[auxClase]/NUM_TABLAS;
		filasTotal+=datos_init[auxClase];
		contadorWhile++;	
	}
	auxClase++;
}	
//*****atributo trabajo mujeres enfermas y sanas
	int	trabajoMujerSi=40,trabajoMujerNo=40;
	int sumaClaseSiTrabajoMujer=0,sumaClaseNoTrabajoMujer=0 ;
	auxClase+=2;
while (sumaClaseNoTrabajoMujer != datos_init[auxClase+1]+1){	
	if (auxClase%2 ==0 ){
		atributos[contadorWhile].Edad= 0;
		atributos[contadorWhile].Estudios=0;
		atributos[contadorWhile].Trabajo=trabajoMujerSi++;
		atributos[contadorWhile].claseSocial=0;
		atributos[contadorWhile].Municipio=0;
		atributos[contadorWhile].sexo =101;
		atributos[contadorWhile].clase =1;
		atributos[contadorWhile].cantidad=datos_init[auxClase];
		sumaClaseSiTrabajoMujer += datos_init[auxClase];
		filas +=  datos_init[auxClase]/NUM_TABLAS;
		filasTotal+=datos_init[auxClase];
		contadorWhile++;				
	}else if (auxClase%2 !=0 ){
		atributos[contadorWhile].Edad= 0;
		atributos[contadorWhile].Estudios=0;
		atributos[contadorWhile].Trabajo=trabajoMujerNo++;
		atributos[contadorWhile].claseSocial=0;
		atributos[contadorWhile].Municipio=0;
		atributos[contadorWhile].sexo =101;
		atributos[contadorWhile].clase =2;
		atributos[contadorWhile].cantidad=datos_init[auxClase];
		sumaClaseNoTrabajoMujer += datos_init[auxClase];
		filas +=  datos_init[auxClase]/NUM_TABLAS;
		filasTotal+=datos_init[auxClase];
		contadorWhile++;
		contadorWhile++;	
	}
	auxClase++;
}	
	// contador para evitar las sumas de hombre y mujer
	contadorAtributos++;
	for (auxContadorAtributos=0; auxContadorAtributos<((contadorWhile)/(contadorAtributos*2)-2);auxContadorAtributos++){
		auxClase++;
	}
//*****atributo municipio hombres enfermos y sanos
	int	municipioHombreSi=50,municipioHombreNo=50;
	int sumaClaseSiMunicipioHombre=0,sumaClaseNoMunicipioHombre=0 ;

while (sumaClaseNoMunicipioHombre != datos_init[auxClase+1]+1){	
	if (auxClase%2 ==0 ){
		atributos[contadorWhile].Edad= 0;
		atributos[contadorWhile].Estudios=0;
		atributos[contadorWhile].Trabajo=0;
		atributos[contadorWhile].claseSocial=0;
		atributos[contadorWhile].Municipio=municipioHombreSi++;
		atributos[contadorWhile].sexo =100;
		atributos[contadorWhile].clase =1;
		atributos[contadorWhile].cantidad=datos_init[auxClase];
		sumaClaseSiMunicipioHombre += datos_init[auxClase];
		filas +=  datos_init[auxClase]/NUM_TABLAS;
		filasTotal+=datos_init[auxClase];
		contadorWhile++;				
	}else if (auxClase%2 !=0 ){
		atributos[contadorWhile].Edad= 0;
		atributos[contadorWhile].Estudios=0;
		atributos[contadorWhile].Trabajo=0;
		atributos[contadorWhile].claseSocial=0;
		atributos[contadorWhile].Municipio=municipioHombreNo;
		atributos[contadorWhile].sexo =100;
		atributos[contadorWhile].clase =2;
		atributos[contadorWhile].cantidad=datos_init[auxClase];
		sumaClaseNoMunicipioHombre += datos_init[auxClase];
		filas +=  datos_init[auxClase]/NUM_TABLAS;
		filasTotal+=datos_init[auxClase];
		contadorWhile++;	
	}
	auxClase++;
}	
//*****atributo municipio mujeres enfermas y sanas
	int	municipioMujerSi=50,municipioMujerNo=50;
	int sumaClaseSiMunicipioMujer=0,sumaClaseNoMunicipioMujer=0 ;
	auxClase+=2;
while (sumaClaseNoMunicipioMujer != datos_init[auxClase+1]){	
	if (auxClase%2 ==0 ){
		atributos[contadorWhile].Edad= 0;
		atributos[contadorWhile].Estudios=0;
		atributos[contadorWhile].Trabajo=0;
		atributos[contadorWhile].claseSocial=0;
		atributos[contadorWhile].Municipio=municipioMujerSi++;
		atributos[contadorWhile].sexo =101;
		atributos[contadorWhile].clase =1;
		atributos[contadorWhile].cantidad=datos_init[auxClase];
		sumaClaseSiMunicipioMujer += datos_init[auxClase];
		filas +=  datos_init[auxClase]/NUM_TABLAS;
		filasTotal+=datos_init[auxClase];
		contadorWhile++;				
	}else if (auxClase%2 !=0 ){
		atributos[contadorWhile].Edad= 0;
		atributos[contadorWhile].Estudios=0;
		atributos[contadorWhile].Trabajo=0;
		atributos[contadorWhile].claseSocial=0;
		atributos[contadorWhile].Municipio=municipioMujerNo++;
		atributos[contadorWhile].sexo =101;
		atributos[contadorWhile].clase =2;
		atributos[contadorWhile].cantidad=datos_init[auxClase];
		sumaClaseNoMunicipioMujer += datos_init[auxClase];
		filas +=  datos_init[auxClase]/NUM_TABLAS;
		filasTotal+=datos_init[auxClase];
		contadorWhile++;	
	}
	auxClase++;
}	



//4.- se pasan los datos a una matriz

int contadorFilasMatriz=0, contadorColumnasMatriz=0, contadorFilasMatrizAux=0;
int **matrizEntradaPerceptron = (int **) malloc (filasTotal/NUM_TABLAS*sizeof(int*));
	if (matrizEntradaPerceptron == NULL){ //evaluacion de condicion.
		printf("NO hay suficiente espacio en memoria para el puntero doble matriz"); //Mensaje
		return -1; //Cierra el programa con un error.
	}
	//se crea otro vector por cada fila con el tamanio de las columnas 
	for (contadorFilasMatriz=0; contadorFilasMatriz<filasTotal/NUM_TABLAS; contadorFilasMatriz++){
		matrizEntradaPerceptron[contadorFilasMatriz]=(int *)malloc(ATRIBUTOS*sizeof(int));//para cada fila se reserva el espacio de columnas
		if (matrizEntradaPerceptron [contadorFilasMatriz]== NULL){ //evaluacion de condicion
			printf("NO hay suficiente espacio en memoria en inicialiacion"); //Mensaje
			return -1; 				 //Cierra el programa con un error.
		}
	}
	//inicializacion de la matriz con filasTotal que es ligeramente mayor de lo necesario
	for (contadorFilasMatriz=0; contadorFilasMatriz< filas;contadorFilasMatriz++){
		for (contadorColumnasMatriz=0; contadorColumnasMatriz<ATRIBUTOS; contadorColumnasMatriz++){
			matrizEntradaPerceptron[contadorFilasMatriz][contadorColumnasMatriz]=0;
		}
	}

int contadorStruct=0, auxMatriz=0;;	
	
	for (contadorFilasMatriz=0; contadorFilasMatriz<filas;){
		
		for (contadorColumnasMatriz=0; contadorColumnasMatriz<ATRIBUTOS; ){
			switch(contadorColumnasMatriz){
				case 0: 
					matrizEntradaPerceptron[contadorFilasMatriz][contadorColumnasMatriz]= atributos[contadorStruct].Edad;
					contadorColumnasMatriz++;
					break;
				case 1: 
					if (atributos[contadorStruct].Edad==10 || atributos[contadorStruct].Edad==11){
						matrizEntradaPerceptron[contadorFilasMatriz][contadorColumnasMatriz]= 20;//los menores de 16 no tienen estudios acabados
					}else{
						matrizEntradaPerceptron[contadorFilasMatriz][contadorColumnasMatriz]= atributos[contadorStruct].Estudios;
					}
				
					contadorColumnasMatriz++;
					break;
				case 2: 
					matrizEntradaPerceptron[contadorFilasMatriz][contadorColumnasMatriz]= atributos[contadorStruct].claseSocial;
					contadorColumnasMatriz++;
					break;
				case 3: 
					if (atributos[contadorStruct].Edad==10 || atributos[contadorStruct].Edad==11||atributos[contadorStruct].Edad==17 ||atributos[contadorStruct].Edad==18){
						matrizEntradaPerceptron[contadorFilasMatriz][contadorColumnasMatriz]= 42;//los mayores de 65 estan inactivos y lo menores de 16 no pueden trabajar
					}else{
						matrizEntradaPerceptron[contadorFilasMatriz][contadorColumnasMatriz]= atributos[contadorStruct].Trabajo;
					}
					
					contadorColumnasMatriz++;
					break;
				case 4:
					matrizEntradaPerceptron[contadorFilasMatriz][contadorColumnasMatriz]= atributos[contadorStruct].Municipio;
					contadorColumnasMatriz++;
					break;
				case 5: 
					matrizEntradaPerceptron[contadorFilasMatriz][contadorColumnasMatriz]= atributos[contadorStruct].sexo;
					contadorColumnasMatriz++;
					break;
				case 6: 
					matrizEntradaPerceptron[contadorFilasMatriz][contadorColumnasMatriz]= atributos[contadorStruct].clase;
					contadorColumnasMatriz++;
					contadorFilasMatriz++;
					contadorStruct++;
					break;
				case 7: 
					
					if(atributos[contadorStruct-1].cantidad>0){
						
						auxMatriz=(atributos[contadorStruct-1].cantidad/NUM_TABLAS);
							for(contadorFilasMatrizAux=0; contadorFilasMatrizAux< auxMatriz-1;contadorFilasMatrizAux++){
								
								for (contadorColumnasMatriz=0; contadorColumnasMatriz<ATRIBUTOS-1; contadorColumnasMatriz++){//se copia el valor anterior
									matrizEntradaPerceptron[contadorFilasMatriz][contadorColumnasMatriz] = matrizEntradaPerceptron[contadorFilasMatriz-1][contadorColumnasMatriz];
							}	
								contadorFilasMatriz++;
							
							}
					}
							
					contadorColumnasMatriz++;
					break;
				default: 		
					break;
				}
		}


	}

	
	//5 salida a fichero de una matriz con los datos
	FILE * matriz, * matrizValidacion, * matrizTest;
	matriz = fopen ("matriz.txt", "w");
		fprintf(matriz, "%% ATRIBUTOS\n");
		fprintf(matriz, "%% EDAD; \n");
		fprintf(matriz, "%%		10= DE 0 A 4 AÑOS \n");
		fprintf(matriz, "%%		11= DE 5 A 15 AÑOS \n");
		fprintf(matriz, "%%		12= DE 16 A 24 AÑOS \n");
		fprintf(matriz, "%%		13= DE 25 A 34 AÑOS \n");
		fprintf(matriz, "%%		14= DE 35 A 44 AÑOS \n");
		fprintf(matriz, "%%		15= DE 45 A 54 AÑOS \n");
		fprintf(matriz, "%%		16= DE 55 A 64 AÑOS \n");
		fprintf(matriz, "%%		17= DE 65 A 74 AÑOS \n");
		fprintf(matriz, "%%		18= DE 75 Y MÁS AÑOS \n");
		fprintf(matriz, "%% ESTUDIOS; \n");
		fprintf(matriz, "%%  	20= SIN ESTUDIOS \n");
		fprintf(matriz, "%%		21= PRIMER CICLO \n");
		fprintf(matriz, "%%		22= SEGUNDO CICLO \n");
		fprintf(matriz, "%%		23= UNIV \n");
		fprintf(matriz, "%% CLASE SOCIAL; \n");
		fprintf(matriz, "%%		30= CLASE I \n");
		fprintf(matriz, "%%		31= CLASE II \n");
		fprintf(matriz, "%%		32= CLASE III \n");
		fprintf(matriz, "%%		33= CLASE Iva \n");
		fprintf(matriz, "%%		34= CLASEIvb \n");
		fprintf(matriz, "%%		35= CLASE V \n");
		fprintf(matriz, "%%		36= CLASE VI \n");
		fprintf(matriz, "%%		37= NO CONSTA \n");
		fprintf(matriz, "%% TRABAJO; \n");
		fprintf(matriz, "%%		40= OCUPADO \n");
		fprintf(matriz, "%%		41= PARADO \n");
		fprintf(matriz, "%%		42= INACTIVO \n");
		fprintf(matriz, "%% TAMAÑO POBLACION; \n");
		fprintf(matriz, "%%		30= MENOR O IGUAL A 2.000 HABITANTES \n");
		fprintf(matriz, "%%		31= 2.001 A 50.000 HABITANTES \n");
		fprintf(matriz, "%%		32= MÁS DE 50.000 HABITANTES \n");
		fprintf(matriz, "%%		32= MÁS DE 50.000 HABITANTES \n");
		fprintf(matriz, "%% SEXO; \n");
		fprintf(matriz, "%%		100= HOMBRE \n");
		fprintf(matriz, "%%		101= MUJER \n");
		fprintf(matriz, "%% CLASS \n");
		fprintf(matriz, "%% 		1=  HIPERTENSO \n");
		fprintf(matriz, "%% 		2=  NORMOTENSO \n");

		
		fprintf(matriz, "@relation hypertension \n");
		fprintf(matriz, "@attribute edad {10,11,12,13,14,15,16,17,18} \n");
		fprintf(matriz, "@attribute estudios {20,21,22,23} \n");
		fprintf(matriz, "@attribute claseSocial {30,31,32,33,34,35,36,37}\n");
		fprintf(matriz, "@attribute trabajo {40,41,42} \n");
		fprintf(matriz, "@attribute municipio {50,51,52} \n");
		fprintf(matriz, "@attribute sexo {100,101} \n");
		fprintf(matriz, "@attribute class {1,2} \n");
		fprintf(matriz, "@data \n");
	for (contadorFilasMatriz=0; contadorFilasMatriz<filas;contadorFilasMatriz++){		
		for (contadorColumnasMatriz=0; contadorColumnasMatriz<ATRIBUTOS-1; contadorColumnasMatriz++){
			if (matrizEntradaPerceptron[contadorFilasMatriz][contadorColumnasMatriz] == 0){
				fprintf(matriz, "? ");	
			}else{
				fprintf(matriz, "%d ",matrizEntradaPerceptron[contadorFilasMatriz][contadorColumnasMatriz] );	
			}
		}
		fprintf(matriz, "\n");
	}
	//6 Finalizacion del programa 
	//se libera la memoria dinamica de la matriz primero para las filas y luego se libera vector de vectores
	for (contadorFilasMatriz=0; contadorFilasMatriz<filas; contadorFilasMatriz++){
		free(  matrizEntradaPerceptron[contadorFilasMatriz]);		
	}
	free(matrizEntradaPerceptron);
	//se liberan el resto de los punteros
   	free(datos_init);
	free(datos_init_tmp);
	//se cierra los archivos
	fclose(matriz);
	fclose(f);

	return 0;
	
}




