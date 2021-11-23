#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void main(){
	printf("Este programa aplica el metodo de las potencias para la resolucion del autovalor dominante.\n"); //Presentacion
	printf("\n");


	printf("Introduzca la dimension de la matriz. La matriz tiene que ser cuadrada por definicion: \n");
	int n=0,i=0,j=0;// La variable n es el orden de la matriz, i y j son variables auxiliares para los bucles.

	scanf("%d", &n); //Introducimos el orden de la matriz
	float coeficientes[n][n], inicial[n], vector_iteraciones[n], resultado; //Aqui declaramos las matrices, vectores y el resultado que mecesitamos para resolver el autovalor dominante.

	printf("\n");

	// El siguiente paso pide los valores de la matriz al usuario y la imprime termino a termino.
	printf("Introduzca la matriz que desea: \n");
	for(i=0; i<n;i++){
		for(j=0; j<n; j++){
			printf("A[%d][%d]=",i,j);
			scanf("%f", &coeficientes[i][j]);
		}
	}

	// Aquí imprimimos en el terminal la matriz entera en forma de matriz cuadrada para poder verla.
	printf("Su matriz queda de la siguiente manera: \n");	
	for(i=0; i<n; i++){
	 	printf("|");
	 	for(j=0; j<n; j++){
	 		printf(" %.2f ", coeficientes[i][j]);
	 	}
	 	printf(" | \n");
	}

	printf("\n");	

	// A continuacion, pedimos el vector inicial que utilizaremos en el inicio y lo imprime.
	printf("Introduzca la condicion inicial en orden (x,y,...): \n");
	for(i=0; i<n;i++){
		printf("X[%d]=",i);
		scanf("%f", &inicial[i]);
	}

	// Lo imprmimos como una matriz columna.
	printf("Su matriz queda de la siguiente manera: \n");	
	for(i=0; i<n; i++){
	 	printf("|");
	 	printf(" %.2f ", inicial[i]);
	 	printf(" | \n");
	}

	printf("Procedemos a aplicar el metodo....\n");

	back1 : // Marcador al que volveremos si queremos repetir el proceso para aproximar mejor el resultado.


	for(i=0; i<n;i++){
		vector_iteraciones[i]=0; //Igualamos el vector (matriz columna) que nos va a dar del resultado de multiplicar una matriz de orden n por una matriz columna a 0 para evitar valores basura.
		for(j=0; j<n; j++){
			vector_iteraciones[i]=vector_iteraciones[i]+coeficientes[i][j]*inicial[j]; // Este paso es lo que viene siendo el metodo, en vector_iteraciones vamos a ir guardando el vector que nos va a ir saliendo cada iteración, por lo que será 
       	}                                                                              // lo que haya en ese vector mas el producto de nuestra matriz nxn con la matriz columna de condición inicial en el primero de los casos. Despues, este vector inicial																			
 	}                                                                                  // se va actualizando por el reciente calculado entomces el producto en este segundo caso seria la matriz nxn por el vector calculado en la primera iteracion. Asi sucesivamente.



	if(inicial[0]!=0){ //Si el denominador es distinto de 0 para que no haya problemas a la hora de hacer el calculo:
		resultado=vector_iteraciones[0]/inicial[0]; // El resultado de la n-ésima aproximación será el primer término del vector recien calculado entre el primer término del vector anterior. 
	}
	printf("El resultado de la iteracion: %f \n", resultado); // Damos la solución por pantalla

	for(i=0; i<n; i++){
		inicial[i]=vector_iteraciones[i]; // Actualizamos el vector por el anterior calculado para repetir el proceso.
	}

	printf("Quieres volver a repetir el metodo para la mayor precision del resultado?\n");
	printf("(SI)--->1 \n(NO)--->2 \n");
	scanf("%d", &option); //El usuario selecciona la opcion que desee
	switch(option){
		case 1 : goto back1; //Si la opcion es 1, volverá a la linea 56 de codigo que es donde está nuestro marcador y se volvera a hacer el metodo.
		case 2 : printf("Proceso terminado. \n"); //Si el usuario no quiere hacer más iteraciones pulsará 2 y finalizará.
	}
}

