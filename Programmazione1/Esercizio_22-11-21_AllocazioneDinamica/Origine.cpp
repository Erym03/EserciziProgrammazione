#include <iostream>
using namespace std;

//-	-	-	-	-	-	-	-	CREAZIONE ARRAY DINAMICI	-	-	-	-	-	

//Funzione per la creazione di un array dinamico
// La funzione andrà chiamata: int* aa = funzione(2);
int* arrayDinamico(int K) //Chiede l'inserimento della dimensione dell'array
{
	int* arr = new int[K];
	return arr;

	//Per liberare lo spazio:
	//delete [] arr;
}

//Funzione per la creazione di un array dinamico con malloc e free
int* arrayDinamicoMalloc(int K) //Chiede l'inserimento della dimensione dell'array
{
	int* arr = (int*)malloc(sizeof(int) * K);	//Allocazione dinamica
	return arr;
	
	//Per liberare lo spazio:
	//free(arr);	//Come il delete

}

//Dichiarazione matrice dinamica
int** matriceDinamica(int righe, int colonne)
{
	int** matrix = new int* [righe]; //Dichiarazione array (solo righe)

	for (int i = 0; i < righe; i++)
	{
		matrix[i] = new int[colonne];
	}


	//Definizione elementi
	for (int i = 0; i < righe; i++)
	{
		for (int j = 0; j < colonne; j++)
		{
			matrix[i][j] = (i * colonne) + j + 1;
		}

	}

	return matrix;

}


//-	-	-	-	-	-	-	-	PASSAGGIO ARRAY DINAMICI	-	-	-	-	-	
// 
//Passaggio array
void riempiArray(int *v, int dimensione, int numero)
{
	for (int i = 0; i < dimensione; i++)
	{
		v[i] = numero; //Riempiamo l'array con il valore contenuto in numero
	}
}

//Forma alternativa equivalente
void riempiArray2(int v[], int dimensione, int numero)
{
	for (int i = 0; i < dimensione; i++)
	{
		v[i] = numero; //Riempiamo l'array con il valore contenuto in numero
	}
}

//Passaggio matrice
void riempiMatrice(int** v, int righe, int colonne, int numero)
{
	//Definizione elementi
	for (int i = 0; i < righe; i++)
	{
		for (int j = 0; j < colonne; j++)
		{
			v[i][j] = numero;
		}

	}
}

//Passaggio array a tre dimensioni...
void riempiArray3(int*** v, int righe, int colonne, int terzaDimensione, int numero)
{
	//Definizione elementi
	for (int i = 0; i < righe; i++)
	{
		for (int j = 0; j < colonne; j++)
		{
			for (int k = 0; k < terzaDimensione; k++)
			{
				v[i][j][k] = numero;
			}
		}

	}
}

int main()
{
	int x, y, valore; //Righe e colonne

	cout << "Inserisci righe e colonne array: " << endl;
	cin >> x;
	cin >> y;

	cout << "Con che valore riempire la matrice:" << endl;
	cin >> valore;

	//creazione matrice;
	int** matrice = matriceDinamica(x, y);
	riempiMatrice(matrice, x, y, valore);

	


	
	
	//Stampa righe e colonne
	for (int i = 0; i < x; i++)
	{
		for (int j = 0; j < y; j++)
		{
			cout << matrice[i][j] << "  ";
		}
		cout << endl;

	}
	
	
}

