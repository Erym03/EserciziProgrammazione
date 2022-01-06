/*
Scrivere un metodo che prenda in input una matrice quadrata M di short e restituisca il valore booleano true se M `e una matrice
triangolare inferiore o superiore.
*/

#include <iostream>
using namespace std;

bool metodo(short** matrice, int dimensione)
{
	//Si parte dal presupposto che la matrice sia triangolare
	bool isTriangularS = true; 
	bool isTriangularD = true;

	for(int i = 0; i<dimensione; i++) //Questo for passa per la diagonale
	{
		//Si controlla sopra la diagonale
		for(int j=i+1; j<dimensione; j++)
		{
			if(matrice[i][j] != 0)
			{
				isTriangularS = false;
			}
		}
	
		//Si controlla sotto la diagonale
		for (int j = i-1; j > 0; j--)
		{
			if (matrice[i][j] != 0)
			{
				isTriangularD = false;
			}
		}
	}
	if(isTriangularD || isTriangularS) //Se è triangolare superiore o inferiore 
	{
		return true;
	}

	return false;
}

int main()
{
	//Creazione matrice dinamica
	int dim = 5;
	short** matrices = new short*[dim];

	for(int i=0; i<dim; i++)
	{
		matrices[i] = new short[dim];
	}

	//Riempi matrice
	for (int i = 0; i < dim; i++)
	{
		for (int j = 0; j < dim; j++)
		{
			cout << "Inserisci valore " << i << " " << j << endl;
			cin>>matrices[i][j];
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

	cout << "E' triangolare: " << metodo(matrices, dim);
}