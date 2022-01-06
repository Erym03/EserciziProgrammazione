/*
Scrivere un metodo che prenda in input una matrice P di puntatori a caratteri di dimensioni n × m, un array di short senza
segno S ed un array di interi senza segno W entrambi di eguale dimensione l. Il metodo dia in output uno array di stringhe di
dimensione l il cui elemento i−esimo sia una stringa di lunghezza pari al valore i-esimo del vettore W, ed inoltre sia formato da
caratteri selezionati casualmente dalla riga di indice S[i] mod n della matrice P. NB: si presti attenzione ad eventuali caratteri
mancanti nella matrice P!
*/

#include <iostream>
using namespace std;

char** metodo(char***M, int n, int m, unsigned short *S, unsigned short *W, int l)
{
	char** ret = new char* [l];

	for(unsigned int i = 0; i<l; i++)
	{
		ret[i] = new char[W[i]];
	}

	//Creazione dei dati
	for(unsigned int i = 0; i<l; i++)
	{
		int riga = S[i] % n;
		int j = 0;

		while(j<W[i])
		{
			int z = rand() % m;
			if (M[riga][z])
			{
				ret[i][j] = *M[riga][z];
				j++;
			}//End if
		}//End while
	}//End for (creazione dei dati)


	return ret;
}