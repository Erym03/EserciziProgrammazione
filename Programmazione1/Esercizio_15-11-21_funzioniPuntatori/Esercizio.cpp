#include <iostream>
using namespace std;

//Funzioni
void novanta(int x) 		//Gli passiamo la variabile x
{
	x = 90;		//x equivale a...
}

void novantaPointer(int *x)	//Gli passiamo l'indirizzo di x
{
	*x = 90;	//Il valore puntato da x equivale a...
}

//Main
int main()
{
	int a = 10;

	novanta(a);			//Richiama la funzione passandogli il parametro a
	cout<<"a = "<<a<<endl<<endl;

	novantaPointer(&a);		//Richiama la funzione passandogli l'indirizzo di a 
	cout<<"a = "<<a<<endl;
}
