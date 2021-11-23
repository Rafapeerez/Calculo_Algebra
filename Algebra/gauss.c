#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void main(){
	printf("Este programa aplica el metodo de GAUSS-SEIDEL para sistema de ecuaciones del tipo Ax = b.\n"); //Presentacion
	printf("\n");

	back2 :// Marcador que utilizaremos en caso de error.

	printf("Introduzca la dimension de la matriz. La matriz tiene que ser cuadrada por definicion: \n");
	int n=0,i=0,j=0;// La variable n es el orden de la matriz, i y j son variables auxiliares para los bucles.

	scanf("%d", &n); //Introducimos el orden de la matriz
	float coeficientes[n][n], independientes[n], x[n], resultado[n]; // Declaramos las variables de las matrices de coeficientes independientes, dependientes, la condicion inicial y el resultado.
	int option;

	for(j=0 ; j<n; j++){ // Ponemos la condición inicial como un vector 0,0,0...
		x[j]=0;
	}

	printf("\n");

	//La función siguiente pide los valores de la matriz de los coeficientes dependientes al usuario y la imprime.
	printf("Introduzca los coeficientes dependientes en orden (x,y,...): \n");
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

	//Esta matriz pide e imprime los valores de la matriz de los coeficientes independientes.
	printf("Introduzca los coeficientes independientes: \n");
	for(i=0; i<n; i++){
		printf("b[%d]=",i);
		scanf("%f", &independientes[i]);
	}

	// Lo imprmimos como una matriz columna.
	printf("Su matriz queda de la siguiente manera: \n");	
	for(i=0; i<n; i++){
	 	printf("|");
	 	printf(" %.2f ", independientes[i]);
	 	printf(" | \n");
	}

	//Comprobamos que la matriz es diagonalmente dominante para poder aplicar el metodo Jacobi
	int suma, cont=0, diagonal=0;
	for(i=0; i<n; i++){
		suma=0;
		for(j=0; j<n; j++){
			if(i==j){ /*Los elementos de la diagonal los guardamos en la variable para compararlo para ver si el sistema es diagonalemte 
						dominante*/
				diagonal=fabs(coeficientes[i][j]); // En la variable diagonal, guardamos el valor absoluto de los coeficientes de la diagonal
			}
			else{
				suma=fabs(suma+coeficientes[i][j]); // En la variable suma se guarda la suma de los valores absolutos de de los coeficientes que no son de la diagonal
			}
		}
		if(diagonal>suma){
			cont++; // Si el valor de la variable diagonal es mayor que la variable suma por cada fila, se le suma 1 a la variable cont.
		}
	}

	if(cont==n){
		printf("Matriz diagonalmente dominante, procedemos a aplicar el metodo....\n");

		back1 : // Ponemos otro marcador para repetir el metodo si es necesario. 

		for(i=0 ; i<n; i++){ //Incializamos el resultado a 0 para evitar valores basura.
			resultado[i]=0;
		}

		//METODO DE GAUSS-SEIDEL
		for(i=0; i<n; i++){
			for(j=0; j<n; j++){
				if(i!=j){
					resultado[i]=resultado[i]+((coeficientes[i][j])*x[j]); // El resultado será los coeficientes que posteriormente cambiamos de signo por la condicion inicial que se va actualizando
				}
			}
			x[i]=(-resultado[i]+independientes[i])/coeficientes[i][i]; // En este proceso ya tenemos el resultado final, le cambiamos de signo a lo que tenemos en la variable resultado debido a que antes no se lo hemos cambiado, le 
																	   // sumamos los coeficientes indepemdientes y eso lo dividimos entre los coeficientes de la diagonal.
																	   // Como observamos el resultado no se guarda en otra variable diferente y ultilizamos la misma debido a que tenemos que utilizar los resultados que acabamos de calcular.
		}

		printf("La solucion es: \n");
		for(i=0; i<n; i++){
			printf("x(%d): %f \n", i, x[i]); // Imprimimos el vector de resultados.
		}

		printf("\n");

		printf("Quieres volver a repetir el metodo para la mayor precision del resultado?\n");
		printf("(SI)--->1 \n(NO)--->2 \n");
		scanf("%d", &option); //El usuario selecciona la opcion que desee
		switch(option){
			case 1 : goto back1; //Si la opcion es 1 volverá a la linea 79 de codigo que es donde está nuestro marcador.
			case 2 : printf("Proceso terminado. \n"); //Si el usuario no quiere hacer más iteraciones pulsará 2 y finalizará.
		}
	}

	else{ //Si la matriz no es diagonable, es decir, si el contador no es igual al numero de ecuaciones, no se hará el programa y se va al marcador para repetetirlo otra vez.
		int opcion2=0;
		printf("ERROR: Para aplicar el metodo es necesario que la matriz de coeficientes sea diagonalmente dominante.\n");
		printf("\n");
		printf("Quieres intentarlo otra vez?\n");
		printf("(SI)--->1 \n(NO)--->2 \n");
		scanf("%d", &opcion2); //El usuario selecciona la opcion que desea
		switch(opcion2){
			case 1 :goto back2; //Si se selecciona el 1 se vuelve a la linea 9 y se vuelve a repetir todo.
			case 2 : printf("Proceso finalizado.\n"); // Si se selecciona el 2, se termina el proceso.
		}	
		printf("\n");
	}
}

