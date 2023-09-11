#include <stdlib.h>
#include <stdio.h>
#include <sys/time.h>

void get_walltime(double* wcTime){
	struct timeval tp;
	gettimeofday(&tp,NULL);
	*wcTime = (tp.tv_sec + tp.tv_usec / 1000000.0);
}

int main(int argc, char* argv[]){
	int i, j, k, n;
	int **matrizA, **matrizB, **matrizC;
	double S1, E1;

	printf("Inserte el tama%co de las matrices cuadradas: ",164);
	scanf("%d", &n);
	fflush(stdin);

	//Inicializando matrices
	matrizA = (int **)malloc(n*sizeof(int *));
	matrizB = (int **)malloc(n*sizeof(int *));
	matrizC = (int **)malloc(n*sizeof(int *));
	for(i=0;i<n;i++)
		*(matrizA+i) = (int *)malloc(n*sizeof(int));
	for(i=0;i<n;i++)
		*(matrizB+i) = (int *)malloc(n*sizeof(int));
	for(i=0;i<n;i++)
		*(matrizC+i) = (int *)malloc(n*sizeof(int));

	//Llenando matrices
	for(i=0; i<n; ++i){
		for(j=0; j<n; ++j){
			matrizA[i][j] = rand() % 6;
		}
	}
	for(i=0; i<n; ++i){
		for(j=0; j<n; ++j){
			matrizB[i][j] = rand() % 6;
		}
	}
	for(i=0; i<n; ++i){
		for(j=0; j<n; ++j){
			matrizC[i][j] = rand() % 6;
		}
	}

	get_walltime(&S1);

	for(j=0; j<n; ++j){
		for(i=0; i<n; ++i){
			for(k=0; k<n; ++k){
				matrizC[i][j] += matrizA[i][k] * matrizB[k][j];
			}
		}
	}
	get_walltime(&E1);

	printf("Tiempo m%ctodo jik: %f s\n", 130, (E1-S1));
	return 0;
}