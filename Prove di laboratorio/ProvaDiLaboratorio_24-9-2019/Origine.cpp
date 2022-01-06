/*
Scrivere un metodo che prenda in input un parametro formale matrice K di double di dimensioni n × m e
due interi a e b, e restituisca un array A di short di dimensione m, in cui l’elemento A[i] `e calcolato come
il numero di elementi della colonna i−esima di K tali che, approssimati all’intero pi`u vicino, siano compresi
tra a e b (inclusi). NB: si assuma a < b.

Scrivere un metodo che prenda in input una matrice di stringhe S di dimensioni n × m, uno short k, ed una
stringa w. Il metodo restituisca il valore booleano true se esiste almeno una riga in P tale che la stringa w
sia sottostringa di un numero di stringhe della riga stessa che sia minore o uguale a k.
*/

#include <iostream>
#include <string.h>
using namespace std;

short *metodo(double ** K, int n, int m, int a, int b)
{
	short* array = new short[m];
	for (int i = 0; i < m; i++)
	{
		array[i] = 0;
	}

	//Verifica per colonne
	for (int j = 0; j < m; j++)
	{
		for(int i = 0; i<n; i++)
		{
			int compara = K[i][j] + 0.5;
			if(compara >= a && compara <=b)
			{
				array[j]++;
			}
		}
	}
	return array;
}

bool metodo2(string **S, int n, int m, short k, string w)
{
	//Verifica per righe
	for (int i = 0; i < n; i++)
	{
		int counter = 0;
		for (int j = 0; j < m; j++)
		{
			string compara = S[i][j];
			if(compara.find(w) != string :: npos)
			{
				counter++;
			}
		}
		if(counter <= k)
		{
			return true;
		}
	}

	return false;
}

int main()
{
	/*
	* //Esercizio 1
	int dim = 5;
	double** matrix = new double* [dim];

	for (int i = 0; i < dim; i++)
	{
		matrix[i] = new double[dim];
	}

	//Riempi matrice
	for (int i = 0; i < dim; i++)
	{
		for (int j = 0; j < dim; j++)
		{
			cout << "Inserisci valore " << i << " " << j << endl;
			cin >> matrix[i][j];
		}
	}

	//Visualizza matrice
	for (int i = 0; i < dim; i++)
	{
		for (int j = 0; j < dim; j++)
		{
			cout << matrix[i][j] << " - ";
		}
		cout << endl;
	}

	short* metodo1 = metodo(matrix, dim, dim, 2, 5);
	cout << endl;

	for (int i = 0; i < dim; i++)
	{
		cout << metodo1[i] << endl;
	}
	
	*/

	//Esercizio 1
	int dim = 5;
	string** matrix = new string * [dim];

	for (int i = 0; i < dim; i++)
	{
		matrix[i] = new string[dim];
	}

	//Riempi matrice
	for (int i = 0; i < dim; i++)
	{
		for (int j = 0; j < dim; j++)
		{
			cout << "Inserisci valore " << i << " " << j << endl;
			cin >> matrix[i][j];
		}
	}

	//Visualizza matrice
	for (int i = 0; i < dim; i++)
	{
		for (int j = 0; j < dim; j++)
		{
			cout << matrix[i][j] << " - ";
		}
		cout << endl;
	}

	
	cout << metodo2(matrix, dim, dim, 3, "ciao");
	
	

}