#include <iostream>
#include <string>
using namespace std;

class CodaArray
{
private:
	int valori = 0;
	const int dim = 10;
	int coda[10] = { 0 };
	
	//I due indici che puntano alla testa e alla fine
	int testa = 0; int fine = -1;

public:

	void enqueue(int value)
	{
		//Se la coda non è piena
		if (valori < dim)
		{
			fine++;

			if(fine >= dim)
			{
				fine = fine % dim;
			}

			valori++;
			coda[fine] = value;
		}
		else
		{
			cerr << "Coda piena!" << endl;
		}
	}

	int dequeue()
	{
		if(valori > 0)
		{
			testa++;
			valori--;

			if (testa >= dim)
			{
				testa = testa % dim;
			}

			int ritorno = coda[testa - 1];
			coda[testa - 1] = 0;
			return ritorno;
		}
		else
		{
			cout << "Coda vuota!" << endl;
		}
		return 0;
		
	}

	void stampa()
	{
		cout << "Testa = " << testa << ", Fine = " << fine << endl;
		for(int i = 0; i < dim; i++)
		{
			cout << " [" << coda[i] << "] - ";
		}
		cout << endl;
	}

	/*
	* 
	void stampa2()
	{
		if (valori = 0)
			cout << "La lista è vuota!" << endl;
		else
		{
			for(int i = testa, int j = 0; i < valori; i++)
			{
				if(testa >= fine)
				{
					cout << coda[i + j] << " - ";
				}
			}
		}
	}
	
	*/
	

};

int main()
{

	CodaArray fila;

	while(true)
	{
		fila.stampa();

		cout << "Scegli: 1 = push; 2 = pop;"<<endl;

		int caso;
		cin >> caso;

		switch (caso)
		{
		case 1:
			cout << "Inserisci valore" << endl;
			int val;
			cin >> val;
			fila.enqueue(val);
			break;
		case 2:
			cout<<"Valore richiesto: "<<fila.dequeue()<<endl;
			break;
		}
	}
}