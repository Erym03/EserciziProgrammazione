#include <iostream>
using namespace std;


//Funzione per la creazione di un array dinamico
int* funzione(int K) //Chiede l'inserimento della dimensione dell'array
{
	int* arr = new int[K];
	for (int i = 0; i < K; i++)
	{
		arr[i] = 10;
	}
	return arr;
}

int main()
{
	/*
	//-	-	-	-	-	-	array dinamico	-	-	-	-	
	int* arrays;
	int dimensione;

	cout << "Inserisci dimensione array quadrata : ";
	cin >> dimensione;

	arrays = new int[dimensione];

	for(int i = 0; i<dimensione; i++)
	{
		arrays[i] = 5;
		
		
	}

	for (int k = 0; k < dimensione; k++)
	{
		cout << matrices[k];
	}
	
	*/

	//Chiamata funzione array dinamico
	int *aa = funzione(2);
	cout << aa[1];



	//-	-	-	-	-	-	array dinamico con malloc e free
	int* arr2 = (int*) malloc(sizeof(int) * 2);	//Allocazione dinamica

	free(arr2);	//Come il delete



	//-	-	-	-	-	-	Matrice dinamica
	int righe, colonne;
	cout << "Inserisci dimensione matrice (righe e colonne) : ";
	cin >> righe;
	cin >> colonne;

	int** arr3 = new int* [righe]; //Dichiarazione array (solo righe)

	for (int i = 0; i < righe; i++)
	{
		arr3[i] = new int[colonne];
	}


	//Definizione elementi
	for(int i=0; i<righe; i++)
	{
		for (int j = 0; j < colonne; j++)
		{
			arr3[i][j] = (i * colonne) + j + 1;
		}
		
	}

	//Stampa righe e colonne
	for (int i = 0; i < righe; i++)
	{
		for (int j = 0; j < colonne; j++)
		{
			cout << arr3[i][j] << "  ";
		}
		cout << endl;

	}

	
}

