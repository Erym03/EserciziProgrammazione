/*
Scrivere un metodo che preveda un parametro formale array monodimensionale S di n puntatori a stringhe, ed una matrice C di caratteri
distinti ed uno short K, e restituisca un array di puntatori a stringhe in cui il generico elemento di indice i contiene un puntatore alle iesima
stringa in S solo se questa contiene almeno K caratteri in C, altrimenti nullptr
*/

#include <iostream>
#include <string>
using namespace std;
#define n 3
#define m 5

string **metodo(string*S[n], char C[n][m], short k)
{
	//Creiamo l'array di ritorno
	string** ritorno = S;

	//verifica array
	for(int i = 0; i<n; i++)
	{
		int counter = 0;
		string stringaConfronto = *ritorno[i];

		//Verifica per matrice C righe
		for(int j=0; j<n; j++)
		{
			for(int l=0; l<m; l++)
			{
				if (stringaConfronto.find(C[n][m]) != string::npos)
					counter++;
			}
		}

		if (counter < k)
			*ritorno[i] = nullptr;
	}

	return ritorno;

}

int main()
{

}