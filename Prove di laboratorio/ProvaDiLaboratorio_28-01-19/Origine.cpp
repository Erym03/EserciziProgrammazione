/*
Scrivere un metodo che prenda in input una matrice quadrata A di numeri interi ed un double w, e restituisca
il valore booleano true se il rapporto tra il minimo ed il massimo valore della diagonale secondaria di A `e
minore o uguale a w.
*/

#include <iostream>
using namespace std;

bool metodo(int **A, int dimensione, double w)
{
	//Dichiariamo le variabili massimo e minimo
	int massimo = A[0][0];
	int minimo = A[0][0];

	//Verificare per tutta la diagonale secondaria
	for(int i=(dimensione-1); i>=0; i--)
	{
		//Verificare massimo
		if(A[i][i]>massimo)
		{
			massimo = A[i][i];
		}

		//Verificare minimo
		if (A[i][i] < minimo)
		{
			minimo = A[i][i];
		}

	}

	//Verificare rapporto tra minimo e massimo
	if((minimo/massimo) <= w)
	{
		cout << "Min/Max = " << minimo / massimo << endl;
		return true;
	}

	return false;
}

int main()
{
	int dim = 5;
	int valore; 

	//Creazione matrice quadrata
	int** matrix = new int* [dim];

	//Definizione colonne
	for (int i = 0; i < dim; i++)
	{
		matrix[i] = new int[dim];
	}

	//Riempiamo array
	for (int i = 0; i < dim; i++)
	{
		for (int j = 0; j < dim; j++)
		{
			cout << "Inserisci valore " << i + 1 << " " << j + 1 << endl;
			cin >> valore;
			matrix[i][j] = valore;
		}
	}

	//Visualizziamo array
	for (int i = 0; i < dim; i++)
	{
		for (int j = 0; j < dim; j++)
		{
			cout << matrix[i][j] << " - ";
		}
		cout << endl;
	}

	cout << "Il rapporto tra massimo e il minimo valore della diagonale è minore o uguale a 5: " << metodo(matrix, dim, 5);
}