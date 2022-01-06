/*
Scrivere un metodo che prenda in input una matrice P di puntatori a caratteri di dimensioni n × m, un array di short senza
segno S ed un array di interi senza segno W entrambi di eguale dimensione l. Il metodo dia in output uno array di stringhe di
dimensione l il cui elemento i−esimo sia una stringa di lunghezza pari al valore i-esimo del vettore W, ed inoltre sia formato da
caratteri selezionati casualmente dalla riga di indice S[i] mod n della matrice P. NB: si presti attenzione ad eventuali caratteri
mancanti nella matrice P!
*/


#include <iostream>
#include <string>
using namespace std;

string* funzione(char ***P, int n, int m, unsigned short *S, int *W, int l)
{
	string* arrayStringhe = new string[l]; //Dichiarazione array da restituire

	for(int i = 0; i<l; i++)
	{
		arrayStringhe[i] = "";
		int riga = S[i] % n;

		for(int j=0; j<i; j++)
		{
			int colonna = rand() % m;	//Numero casuale da 0 a m
			if(P[riga][colonna]) //Se il carattere non è nullo fa la somma
			{
				arrayStringhe[i] = arrayStringhe[i] + P[riga][colonna];
			}
			else //Altrimenti ritorna indietro
			{
				j--;
			}
			
		}
	}

	return arrayStringhe;
}