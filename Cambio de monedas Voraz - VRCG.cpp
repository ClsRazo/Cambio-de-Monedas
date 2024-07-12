 //Villarreal Razo Carlos Gabriel 3CM5
#include <stdio.h>
#include <stdlib.h>

int * cambioMonedas(int *denominaciones, int cambio, int n);

void pedirDenominaciones(int *denominaciones, int n);
void mostrarDenominaciones(int *denominaciones, int n);
void mostrarResultado(int *c, int *denominaciones, int cambio, int n);

void burbuja(int *puntero, int cantidad);

int main(){
	int *denominaciones, *c;
	int cambio, n=0;
	printf("\t\t-----CAMBIO DE MONEDAS-----\n\n");
	printf("Introduce la cantidad a cambiar: ");
	scanf("%d",&cambio);
	printf("Introduce la cantidad la cantidad de denominaciones: ");
	scanf("%d",&n);

	printf("\n\t\t-----DENOMINACIONES-----\n\n");
	//Se crea el arreglo de denominaciones
	denominaciones=(int *)calloc(n,sizeof(int));
	pedirDenominaciones(denominaciones, n);
	mostrarDenominaciones(denominaciones, n);
	burbuja(denominaciones,n);

	printf("\n\n\t\t-----SOLUCION-----\n\n");	
	c=cambioMonedas(denominaciones,cambio,n);
	mostrarResultado(c,denominaciones,cambio,n);
	return 0;
}

int * cambioMonedas(int *denominaciones, int cambio, int n){
	int *c;
	int i=0;
	
	c=(int *)calloc(n,sizeof(int));

	while(i<n){
		while(cambio>=denominaciones[i]){
			c[i]++;
			cambio=cambio-denominaciones[i];
		}
		i++;
	}

	return c;
}

void pedirDenominaciones(int *denominaciones, int n){
	int i=0;

	while(i<n){
		printf("Introduce el valor %d: ",i+1);
		scanf("%d",&denominaciones[i]);
		i++;
	}
}

void mostrarDenominaciones(int *denominaciones, int n){
	int i=0;
	printf("\nLas denominaciones son:\n\n\t\t[");
	while(i<n){
		if(i==n-1){
			printf("%d]",denominaciones[i]);
		}else{
			printf("%d,",denominaciones[i]);
		}
		i++;
	}
}

void mostrarResultado(int *c, int *denominaciones, int cambio, int n){
	int i=0;
	printf("Para cambiar %d con algoritmo voraz y las denominaciones dadas se necesitan:\n\n",cambio);
	while(i<n){
		printf("\t\t%d monedas de %d\n",c[i],denominaciones[i]);
		i++;
	}
}

void burbuja(int *puntero, int cantidad){
	int aux, i=0, j=0;
	while(i<cantidad){
		for(j=0;j<cantidad-1;j++){
			if(*(puntero+j)<*(puntero+j+1)){
				aux=*(puntero+j);
				*(puntero+j)=*(puntero+j+1);
				*(puntero+j+1)=aux;
			}
		}
		i++;
	}
}