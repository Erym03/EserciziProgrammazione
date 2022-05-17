/*
Scrivere un metodo che prenda come parametri formali una matrice A n×m di long ed un long x, e
restituisca in output l’indice della colonna di A con il maggior numero di occorrenze di x.
*/

#include <iostream>
using namespace std;

int metodo(long **A, int n, int m, long x)
{
	int max = 0; //Inizializziamo il valore massimo di occorrenze e l'indice a 0
	int indice = 0; 

	for(int i = 0; i<n; i++)
	{
		int conta = 0;

		for (int j = 0; j < m; j++)
		{
			if(A[i][j] == x)
			{
				conta++;
			}
		}

		if(conta > max)
		{
			max = conta;
			indice = i;
		}
	}

	return indice;
}

int main()
{
	//Creazione matrice dinamica
	int righe = 5;
	int colonne = 4;
	long** matrices = new long* [righe];

	for (int i = 0; i < righe; i++)
	{
		matrices[i] = new long[colonne];
	}

	//Riempi matrice
	for (int i = 0; i < righe; i++)
	{
		for (int j = 0; j < colonne; j++)
		{
			cout << "Inserisci valore " << i << " " << j << endl;
			cin >> matrices[i][j];
		}
	}

	//Visualizza matrice
	for (int i = 0; i < righe; i++)
	{
		for (int j = 0; j < colonne; j++)
		{
			cout << matrices[i][j] << " - ";
		}
		cout << endl;
	}

	cout << "La riga con il maggior numero di ricorsioni è la: " << metodo(matrices, righe, colonne, 5) + 1 << endl;

}