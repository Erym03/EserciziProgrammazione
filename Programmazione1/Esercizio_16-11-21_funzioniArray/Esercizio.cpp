#include <iostream>
#include <iomanip>
using namespace std;

//Variabili globali
#define N 10
#define M 5

//Funzioni
//	-	-	-	-	ARRAY MONODIRESIONALI	-	-	-
void f1(int *array)	//Una funzione che riempie l'array
{
	for(int i = 0; i<10; i++)
	{
		array[i] = i + 5;
	}
}

void f1b(int array[])	//Un modo alternativo per passare un array monodirezionale ad una funzione
{
	for(int i = 0; i<10; i++)
	{
		array[i] = i + 5;
	}

}

int f2(int *array, int numero) //Una funzione che ritorna il contenuto di una cella di un array
{
	return array[numero];
}

//	-	-	-	ARRAY BIDIMENSIONALI	-	-	-
void f3(int array[][M])
{
	for(int i=0; i<10; i++)
	{
		for(int j=0; j<5; j++)
		{
			array[i][j] = 20;
		}
	}

}

//Main
int main()
{
	int a[N]; 	//Dichiariamo un array di 10 elementi
	//f1(a);	//Riempiamo l'array
	f1b(a);		//Rempiamo l'array con la funzione alternativa. Il risultato sarà lo stesso

	cout<<"Posizione dell'array 0 = "<<f2(a,0)<<endl;
	cout<<"Posizione dell'array 3 = "<<f2(a, 3)<<endl<<endl;

	int a2[N][M];	//Dichiariamo una matrice di dimensione NxM
	f3(a2);		//Riempiamo l'array
	cout<<"Posizione matrice [2][2] = "<<a2[2][2]<<endl;
}
