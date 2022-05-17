/*
Scrivere un metodo che prenda in input una matrice di double D ed un intero a, e restituisca il valore booleano true se esiste
almeno una colonna in D nella quale la somma di una qualsiasi coppia di elementi adiacenti, approssimata all’intero pi`u vicino,
sia uguale ad a.

Scrivere un metodo che prenda in input una matrice quadrata Q di stringhe e restituisca il valore booleano true se la stringa piu
lunga della diagonale principale di Q contiene un numero di vocali minore della stringa pi`u corta della diagonale stessa. NB: Si
assuma che le stringhe della diagonale principale abbiano lunghezze differenti e sempre maggiori di zero.

*/

#include <iostream>
#include <string.h>
using namespace std;

bool metodo1(double **D, int r, int c, int a)
{
	//Verifica per colonne
	for(int j=0; j<c; j++)
	{
		for(int i=0; i<r; i++)
		{
			int compare = 0;

			if(i!=0)
			{
				compare = D[i][j] + D[i - 1][j] + 0.5;
				if (compare == a)
				{
					cout << D[i][j] << " + " << D[i - 1][j] << " = " << compare << endl; 
					return true;
				}
			}
			else if (i != (r-1))
			{
				compare = D[i][j] + D[i + 1][j] + 0.5;
				if (compare == a)
				{
					cout << D[i][j] << " + " << D[i + 1][j] << " = " << compare << endl; 
					return true;
				}
			}
		}
	}

	return false;
}

bool metodo2(string **Q, int l)
{
	string minore = Q[0][0];
	int vocaliMin = 0;
	string maggiore = Q[0][0];
	int vocaliMax = 0;

	//Diagonale
	for(int i = 1; i<l; i++)
	{
		string matrice = Q[0][0];
		int matriceL = matrice.length();

		if (minore.length() > Q[i][i].length()) minore = Q[i][i];
		if (maggiore.length() < Q[i][i].length()) maggiore = Q[i][i];
	}

	//Controllo vocali
	for(int i = 0; i<minore.length(); i++)
	{
		if (minore[i] == 'a' || minore[i] == 'e' || minore[i] == 'i' || minore[i] == 'o' || minore[i] == 'u') vocaliMin++;
	}

	for (int i = 0; i < maggiore.length(); i++)
	{
		if (maggiore[i] == 'a' || maggiore[i] == 'e' || maggiore[i] == 'i' || maggiore[i] == 'o' || maggiore[i] == 'u') vocaliMax++;
	}

	if (vocaliMax < vocaliMin) return true;

	cout << "vocalimax = " << vocaliMax << endl;
	cout << "vocalimin = " << vocaliMin << endl;
	return false;

}

int main()
{
	/*
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

	cout << metodo1(matrix, dim, dim, 5);
	
	*/
	
	int dim = 5;
	string** matrices = new string* [dim];

	for (int i = 0; i < dim; i++)
	{
		matrices[i] = new string[dim];
	}

	//Riempi matrice
	for (int i = 0; i < dim; i++)
	{
		for (int j = 0; j < dim; j++)
		{
			cout << "Inserisci valore " << i << " " << j << endl;
			cin >> matrices[i][j];
		}
	}

	//Visualizza matrice
	for (int i = 0; i < dim; i++)
	{
		for (int j = 0; j < dim; j++)
		{
			cout << matrices[i][j] << " - ";
		}
		cout << endl;
	}

	cout << metodo2(matrices, dim);
}