#include <iostream>
using namespace std;

/*
Scrivere un metodo che prenda in input una matrice A di numeri interi e due double w e v, e restituisca il
valore booleano true se esiste almeno una colonna di A in cui la media dei suoi elementi `e compresa tra w e v. NB: Si assuma che w ≤ v.
*/

bool metodo(int** matrice, int r, int c, double w, double v)
{
	//Verifica per colonne
	for(int j = 0; j < c; j++)
	{
		int media = 0;
		//Per ogni riga della colonna
		for(int i = 0; i<r; i++)
		{
			media = media + matrice[i][j];
		}
		
		media = media / r; //Dividiamo la media per il numero di righe

		if(media >= w && media <= v)
		{
			return true;
		}
	}
	return false;


}

int main()
{
	//Creazione matrice dinamica
	int righe = 4;
	int colonne = 4;
	int** matrix = new int*[righe];
	int v; //Valore per riempire

	//Definizione colonne
	for (int i = 0; i < righe; i++)
	{
		matrix[i] = new int[colonne];
	}

	//Riempiamo array
	for (int i = 0; i < righe; i++)
	{
		for (int j = 0; j < colonne; j++)
		{
			cout << "Inserisci valore " << i+1 << " " << j+1 << endl;
			cin >> v;
			matrix[i][j] = v;
		}
	}

	//Visualizziamo array
	for (int i = 0; i < righe; i++)
	{
		for (int j = 0; j < colonne; j++)
		{
			cout<<matrix[i][j]<<" - ";
		}
		cout << endl;
	}

	cout<<metodo(matrix, righe, colonne, 5, 10);


}