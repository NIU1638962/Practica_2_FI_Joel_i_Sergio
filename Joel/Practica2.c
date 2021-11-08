#include <stdio.h>
#include <stdlib.h>
#define N 3
int Mat1 [N][N];
int Mat2 [N][N];
int Vect1 [N];
int Vect2 [N];

void initMat(){
	int i, j;
	srand(8824553);
	for( i=0; i < N; i++ ) {
		for( j = 0; j < N; j++ ){
			Mat1[i][j] = rand()%100;
			Mat2[i][j] = rand()%100;
		}
	}
	for( i=0; i < N; i++ ){
		Vect1[i] = rand()%100;
		Vect2[i] = rand()%100;
	}
}

void Saxpy(int VectorX[N], int VectorY[N], int beta, int VectorZ[N]) {
	for (int i=0; i<N; i++) {
		VectorZ[i]=((VectorX[i]*beta)+VectorY[i]);
	}	
}

void sumElement(int Matriu[N][N], int VectorResultat[N]) {
	int suma;
	for (int index=0; index<N; index++) {
		suma=0;
		for (int j=0; j<N; j++) {
			suma+=Matriu[j][index];
		}
		VectorResultat[index]=suma;
	}
}

int PermutaF(int Matriu[N][N],int fila1, int fila2) {
	if (fila1>=N||fila2>=N) {
		return 0;
	}
	else {
		int VectorTemporal[N];
		for (int i=0; i<N; i++) {
			VectorTemporal[i]=Matriu[fila1][i];
		}
		for (int i=0; i<N; i++) {
			Matriu[fila1][i]=Matriu[fila2][i];
		}
		for (int i=0; i<N; i++) {
			Matriu[fila2][i]=VectorTemporal[i];
		}
		return 1;
	} 
}

int main() {
	int fet;
	initMat();
	for (int j=0; j<N; j++) {
		for (int i=0; i<N; i++) {
			printf ("%d ",Mat1[j][i]);
		}
		printf ("\n");
	}
	fet=PermutaF (Mat1, 0, 1);
	if (fet) {
		printf("True\n");
	}
	else {
		if (!fet) {
			printf("False\n");
		}
	}
	for (int j=0; j<N; j++) {
		for (int i=0; i<N; i++) {
			printf ("%d ",Mat1[j][i]);
		}
		printf ("\n");
	}
}
