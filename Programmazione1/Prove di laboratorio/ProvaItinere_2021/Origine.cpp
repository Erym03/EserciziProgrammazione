/*
Scrivere un metodo in linguaggio C++ che prende in input una matrice di puntatori a interi di dimensioni N x M,
un double z ed uno short k (si assuma che k < N).     
Il metodo restituisca il numero di colonne che contengono almeno k elementi contigui la cui media aritmetica risulti minore di z.
*/

#include <iostream>
using namespace std;

int funzione(int ***Matrice, int N, int M, double z, short k)
{
	int contatore = 0;
	
	//Verifica per colonne
	for(int j = 0; j<M; j++)
	{
		cout << endl;
		cout<<"-	-	-Colonne = " << j << endl;
		
		//Verifica per righe
		for(int i = 0; i<(N-k); i++)
		{
			cout << "N-K-1 = " << N-1 << endl;
			cout << "Righe = " << i <<endl;
			bool mediaMinore = false;
			
			//Verifica da almeno k elementi fino al massimo
			for(int u = k; u<N; u++)
			{
				cout << "U = " << u << endl;
				double sommaMedia = 0;
				int contaSomma = 0;
				
				

				for (int l = 0; l < u; l++)
				{
					sommaMedia += (*Matrice[i + l][j]);
					contaSomma++;
				}
				cout << "SommaMedia = " << sommaMedia << endl;
				sommaMedia = sommaMedia / (contaSomma * 1.0);
				cout << "Media = " << sommaMedia << endl;

				//Se è minore di z esce dal for e somma 1 al contatore
				if (sommaMedia < z)
				{
					cout << "Esce dal for. Media = "<<sommaMedia<<endl;
					contatore++;
					mediaMinore = true;
					break;
				}
			}

			//Se trova un elemento va alla colonna successiva
			if (mediaMinore)
				break;
		}
	}

	return contatore;
}



int main() {
	int ***Matrics = new int** [4];
	int input = 0;
	for (int i = 0; i < 4; i++) {
		Matrics[i] = new int*[3];
		for (int j = 0; j < 3; j++) {
			cout << "Inserisci un valore per la posizione [" << i << "][" << j << "]: ";
			cin >> input;
			Matrics[i][j] = new int(input);
		}
	}

	cout << "Il numero di colonne che contengono almeno 2 elementi contigui \
    \nla cui media aritmetica risulti minore di 5.5 e' " << funzione(Matrics, 4, 3, 5.5, 2) << endl;
}
