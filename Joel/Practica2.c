//*Sergio_Martínez_Pérez_(1633728)_Joel_Tapia_Salvador_(1638962)_Pràctica_2_FI_ED*//
#include <stdio.h>
#include <stdlib.h>
#define N 512
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

void mulMat (int Mat1[N][N], int Mat2[N][N], int tempM1M2[N][N]){
    
    for (int b = 0; b<N; b++){
        for (int i = 0; i<N; i++){
            int suma = 0;
            for (int j = 0; j<N; j++){

            suma += Mat1[i][j]*Mat2[j][b];
            }
            
            tempM1M2[i][b] = suma;
        }
    }
}

void transMat(int tempM1M2[N][N],int tempTransM1M2[N][N]){
    
    for (int i = 0; i<N; i++){
        for (int j = 0; j<N; j++){
            tempTransM1M2[j][i]=tempM1M2[i][j];
        }
    }
    
}

int sumDiagonal(int tempTransM1M2[N][N]){
    int suma=0;
    for (int i = 0; i<N; i++){
        suma += tempTransM1M2[i][i];
    }        
    return suma;
}


int main() {
	initMat();
	int tempM1M2[N][N];
	mulMat(Mat1, Mat2, tempM1M2);
	for (int j = 10; j < 20; j++){
		printf("%d ", tempM1M2[10][j]);
	}
	printf("\n\n");
	int tempV1V2 [N];
	Saxpy(Vect1, Vect2, 4, tempV1V2);
	for (int i=100; i<120; i++) {
		printf ("%d ", tempV1V2[i]);
	}
	printf ("\n\n");
	int tempTransM1M2[N][N];
   	transMat(tempM1M2,tempTransM1M2);
   	for (int i = 10; i < 20; i++){
		printf("%d ", tempTransM1M2[i][10]);
		printf("\n");
  	}
  	printf("\n");
	int realitzat;
	realitzat=PermutaF(Mat1, 5, 10);
	printf ("%d\n", realitzat);
	realitzat=PermutaF(Mat2, 100, 512);
	printf ("%d\n", realitzat);
	printf ("\n");
	printf("%d\n\n",sumDiagonal(tempTransM1M2));
	int tempC [N];
	sumElement(tempM1M2,tempC);
	for (int i=400; i<420; i++) {
		printf ("%d ", tempC[i]);
	}
	printf ("\n\n");
	
}
