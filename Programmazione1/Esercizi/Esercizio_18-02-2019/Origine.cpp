/*
Scrivere un metodo che prenda in input una matrice A di numeri interi e due double w e v, e restituisca il
valore booleano true se esiste almeno una colonna di A in cui la media dei suoi elementi `e compresa tra w e v. NB: Si assuma che w ≤ v.

Scrivere un metodo che prenda in input una matrice di puntatori a stringhe M e due numeri short senza
segno, k ed s, e restituisca il numero di colonne contenenti almeno k stringhe con un numero di lettere vocali
minore di s.
*/

#include <iostream>
#include <string.h>
using namespace std;

bool metodo(int **A, int n, int m, double w, double v)
{
	//Verifica per colonne
	for(int j = 0; j<m; j++)
	{
		double media = 0;
		for(int i=0; i<n; i++)
		{
			media = A[i][j];
		}

		media = media / n;
		if (media >= w && media <= v)
			return true;
	}

	return false;
}

int metodo2(string ***M, int n, int m, unsigned short k, unsigned short s)
{
	int conta = 0;
	string vocali = { "aeiou" };

	//Verifica per colonne
	for (int j = 0; j < m; j++)
	{
		int contaStringhe = 0;
		for(int i = 0; i < n; i++)
		{
			string stringa = *M[i][j];
			int lunghezza = stringa.length();

			for(k= 0; k<lunghezza; k++)
			{
				if(stringa[k] == 'a' || stringa[k] == 'e' || stringa[k] == 'i' || stringa[k] == 'o' || stringa[k] == 'u')
				{
					contaStringhe++;
				}
			}
		}
		if (contaStringhe < s)
			conta++;
	}
	if (conta >= k)
		return conta;

	return 0;
}

