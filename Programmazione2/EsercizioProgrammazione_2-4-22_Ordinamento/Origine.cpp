#include <iostream>
using namespace std;

//-	-	-	-	-	BUBBLE SORT
void bubbleSort(int array[], int dimensione)
{
	bool changing = false;
	int provvisorio;

	do
	{
		changing = false;
		for (int i = 0; i < (dimensione - 1); i++)
		{
			if (array[i] > array[i + 1]) //Se trova un valore maggiore del successivo procede con lo scambio
			{
				changing = true;
				provvisorio = array[i];
				array[i] = array[i+1];
				array[i + 1] = provvisorio;
			}
		}
	} while (changing);
	
	cout << "BUBBLE SORT:" << endl;
	for(int i = 0; i< dimensione; i++)
	{
		cout << array[i] << " - ";
	}
	cout << endl;
}

//-	-	-	-	-	QUICK SORT
int partition(int array[], int p, int r) //P primo elemento dell'array e r elemento finale array
{
	int pivot = array[p]; //Usiamo il primo elemento dell'array come pivot
	int i = p; //i scorrerà da sinistra a destra per trovare elementi più grandi del pivot
	int j = r - 1; //i scorrerà da sinistra a destra per trovare elementi più piccoli del pivot

	while (i < j)
	{
		while (array[j] > pivot) //Continua a scorrere fino a quando non vengono trovati elementi piccoli del pivot
		{
			j = j - 1;
		}

		while (array[i] < pivot) //Continua a scorrere fino a quando non vengono trovati elementi più grandi del pivot
		{
			i = i + 1;
		}

		if (i < j) //Se la posizione di i è ancora minore di quella di j si scambiano
		{
			int scambio = array[i];
			array[i] = array[j];
			array[j] = scambio;
		}
	}


	return j; //Ritorna la posizione di j per capire come il vettore è stato riorganizzato
}

void quickSort(int array[], int p, int r)
{
	if(p < r)
	{
		//Utilizzando il partition ordiniamo l'array in base al pivot e prendiamo la posizione per la suddivisone dei vettori
		int q = partition(array, p, r); 

		//Facciamo la stessa operazione per i sottovettori ottenuti tramite il partition
		quickSort(array, p, q);
		quickSort(array, q + 1, r);
	}

	cout << "partition:" << endl;
	for (int a = 0; a < r; a++)
	{
		cout << array[a] << " - ";
	}
	cout << endl;
}



int main()
{
	int arr1[10] = { 10, 8, 3, 15, 7, 9, 13, 4, 11, 6};
	int arr2[10] = { 10, 8, 3, 15, 7, 9, 13, 4, 11, 6 };

	//Bubblesort
	bubbleSort(arr1, 10);
	cout << endl;

	//partition
	quickSort(arr2, 0, 10);
	cout << endl;


}