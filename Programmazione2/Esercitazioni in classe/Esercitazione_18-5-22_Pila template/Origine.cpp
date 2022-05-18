#include <iostream>
using namespace std;

enum statoPila {vuota, nonVuota, piena};

template <typename T>
class Pila
{
	int lunghezza;
	T* contenuto;
	int cima;
	statoPila stato;

public:
	Pila(int l=10)
	{
		lunghezza = l;
		contenuto = new T[lunghezza];
		cima = -1;
		stato = vuota;
	}

	~Pila()
	{
		delete[] contenuto;
	}

	void push(T val)
	{
		if (stato != piena)
		{
			//Aggiungiamo il valore al successivo slot libero della pila
			cima++;
			contenuto[cima] = val;

			//Verifichiamo che la pila sia piena o vuota
			if(cima == lunghezza-1)
			{
				stato = piena;
			}
			else
			{
				stato = nonVuota;
			}
		}
		
	}

	T pop()
	{
		T elem;

		//Prendiamo il contenuto della cima della pila e diminuiamo la cima
		if (stato != vuota)
			elem = contenuto[cima--];
		else
		{
			cout << "Pila vuota" << endl;
		}

		//Verifichiamo se la pila si svuota o meno
		if(cima == -1)
		{
			stato = vuota;
		}
		else
		{
			stato = nonVuota;
		}

		return elem;
	}

	int numElementi()
	{
	
	}

	int getLunghezza() 
	{
		return lunghezza;
	}

	template <typename U>
	friend
	ostream& operator<<(ostream& out, const Pila<U>&p);

};

template <typename U>
ostream& operator<<(ostream & out, const Pila<U>&p)
{
	for(int i = p.cima; i>= 0; i--)
	{
		out << " [" << p.contenuto[i] << "] " << endl;
	}

	return out;
}

int main()
{
	Pila<int> stack(6);

	stack.push(1);
	stack.push(2);
	stack.push(3);

	cout << stack << endl;
}