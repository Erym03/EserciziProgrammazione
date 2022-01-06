/*
Scrivere un metodo che prenda in input un parametro formale matrice quadrata Q di interi ed un double w,
e restituisca un valore booleano true se esiste almeno una colonna della matrice Q tale che il rapporto tra
la somma degli elementi della colonna stessa e la somma degli elementi della diagonale secondaria di Q sia
maggiore di w.


Scrivere un metodo che prenda in input una matrice di puntatori a stringhe P di dimensioni n×m, due short
a e b, ed una stringa s. Il metodo restituisca il valore booleano true se esiste almeno una colonna in P tale
che la stringa s sia sottostringa di un numero compreso tra a e b (inclusi) di stringhe della colonna stessa.
PS: Si assuma 0 < a ≤ b < n,
*/

#include <iostream>
#include <string.h>
using namespace std;

bool metodo(int **Q, int dimensione, double w)
{
	int diagonaleSecondaria = 0;
	//Calcolo somma elementi diagonale secondaria
	for(int i=0; i<dimensione; i++)
	{
		int j = dimensione - 1 - i;
		diagonaleSecondaria = diagonaleSecondaria + Q[i][j];
	}

	//Verifica per ogni colonna
	for(int j = 0; j<dimensione; j++)
	{
		//Sommare le righe di ogni colonna
		int somma = 0;
		for(int i = 0; i<dimensione; i++)
		{
			somma += Q[i][j];
		}

		if((somma/diagonaleSecondaria)>w)
		{
			return true;
		}
	}
	return false;
}


bool metodo2(string*** P, int n, int m, short a, short b, string s)
{
	//Verificare per colonne
	for(int j = 0; j < m; j++)
	{
		int nSottostringhe = 0;
		for(int i = 0; i<n; i++)
		{
			string stringa = *P[i][j];
			if(stringa.find(s) != string::npos)
			{
				nSottostringhe++;
			}
		}



		if (nSottostringhe >= a && nSottostringhe <= b)
		{
			return true;
		}
	}

	return false;
}

int main()
{
	/*
		//Parte 1
	//Creazione matrice quadrata
	int dim = 5;
	int** matrix = new int* [dim];

	for(int i = 0; i<dim; i++)
	{
		matrix[i] = new int[dim];
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

	cout<<metodo(matrix, dim, 1);
	*/
}
