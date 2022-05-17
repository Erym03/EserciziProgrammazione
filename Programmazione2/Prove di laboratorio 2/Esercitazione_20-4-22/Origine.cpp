#include <iostream>
#include <string>
#include <fstream>
#include <time.h>
using namespace std;


class utente
{
private:
	int id;
	string cognome;
	string nome;
	double popolarita;

public:

	utente()
	{
		id = 0;
		cognome = "";
		nome = "";
		popolarita = 0;
	}

	//Viene passata in input la stringa e lui la riordina
	void setValue(string riga)
	{
		//Trova la posizione del ";"
		int pos = riga.find(";");
		id = stoi(riga.substr(0, pos));

		riga = riga.substr(pos + 1, riga.length());
		pos = riga.find(";");
		cognome = riga.substr(0, pos);

		riga = riga.substr(pos + 1, riga.length());
		pos = riga.find(";");
		nome = riga.substr(0, pos);

		riga = riga.substr(pos + 1, riga.length());
		pos = riga.find(";");
		popolarita = stod(riga.substr(0, pos));

	}

	void print()
	{
		cout << "id: " << id<<", ";
		cout << "cognome: " << cognome << ", ";
		cout << "nome: " << nome << ", ";
		cout << "popolarita': " << popolarita << endl;;
	}

	double getPop()
	{
		return popolarita;
	}
};

//-	-	-	-	-	BUBBLE SORT
void bubbleSort(utente array[], int dimensione)
{
	bool changing = false;
	utente provvisorio;

	do
	{
		changing = false;
		for (int i = 0; i < (dimensione - 1); i++)
		{
			if (array[i].getPop() > array[i + 1].getPop()) //Se trova un valore maggiore del successivo procede con lo scambio
			{
				changing = true;
				provvisorio = array[i];
				array[i] = array[i + 1];
				array[i + 1] = provvisorio;
			}
		}
	} while (changing);

	cout << "BUBBLE SORT:" << endl;
	for (int i = 0; i < dimensione; i++)
	{
		array[i].print();
	}
}

//-	-	-	-	-	QUICK SORT
int partition(utente array[], int p, int r) //P primo elemento dell'array e r elemento finale array
{
	double pivot = array[p].getPop(); //Usiamo il primo elemento dell'array come pivot
	int i = p; //i scorrerà da sinistra a destra per trovare elementi più grandi del pivot
	int j = r - 1; //i scorrerà da sinistra a destra per trovare elementi più piccoli del pivot

	while (i < j)
	{
		while (array[j].getPop() > pivot) //Continua a scorrere fino a quando non vengono trovati elementi piccoli del pivot
		{
			j = j - 1;
		}

		while (array[i].getPop() < pivot) //Continua a scorrere fino a quando non vengono trovati elementi più grandi del pivot
		{
			i = i + 1;
		}

		if (i < j) //Se la posizione di i è ancora minore di quella di j si scambiano
		{
			utente scambio = array[i];
			array[i] = array[j];
			array[j] = scambio;
		}
	}


	return j; //Ritorna la posizione di j per capire come il vettore è stato riorganizzato
}

void quickSort(utente array[], int p, int r)
{
	if (p < r)
	{
		//Utilizzando il partition ordiniamo l'array in base al pivot e prendiamo la posizione per la suddivisone dei vettori
		int q = partition(array, p, r);

		//Facciamo la stessa operazione per i sottovettori ottenuti tramite il partition
		quickSort(array, p, q);
		quickSort(array, q + 1, r);
	}
}


int main()
{

	int lunghezza = 0;
	cout << "Quanti elementi della lista vuoi visualizzare?" << endl;
	cin >> lunghezza;
	string stringa;
	utente utenti1[2000];
	utente utenti2[2000];

	//Prende il file
	ifstream documento("utenti.txt");

	//Stampa tutti i valori del file
	for(int i = 0; i<lunghezza; i++)
	{
		//Prende una linea della stringa e la 
		getline(documento, stringa);
		//cout << stringa << endl;

		//Compila il campo di ogni utente
		utenti1[i].setValue(stringa);
		//utenti1[i].print();
		utenti2[i].setValue(stringa);
	}

	int selezione = 1;
	cout << "Scegli l'algoritmo:" << endl;
	cout << "1: bubblesort" << endl;
	cout << "2: quicksort" << endl;
	cin >> selezione;

	if(selezione == 1)
	{
		//Effettua il bubblesort per ordinare gli elementi
		cout << endl;
		cout << "-	-	-	-	-	-	BUBBLESORT	-	-	-	-	-	-	" << endl;
		clock_t start1 = clock();

		bubbleSort(utenti1, lunghezza);

		clock_t end1 = clock();
		printf("Tempo di esecuzione del bubblesort =  %f secondi \n", ((double)(end1 - start1)) / CLOCKS_PER_SEC);

	}
	else if(selezione == 2)
	{
		cout << "-	-	-	-	-	-	QUICKSORT	-	-	-	-	-	-	" << endl;
		clock_t start2 = clock();
		quickSort(utenti2, 0, lunghezza);
		for (int a = 0; a < lunghezza; a++)
		{
			utenti2[a].print();
		}
		clock_t end2 = clock();

		printf("Tempo di esecuzione del quicksort =  %f secondi \n", ((double)(end2 - start2)) / CLOCKS_PER_SEC);

	}
	

	

	
}