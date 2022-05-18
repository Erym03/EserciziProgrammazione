#include <iostream>
using namespace std;

//La classe per il singolo nodo della lista
class Nodo
{
public:
	int valore;
	Nodo* succ; //Una variabile puntatore a nodo che contiene l'indirizzo del nodo successivo

	//Il costruttore che inizializza il valore
	Nodo(int x): valore (x){}
};

//La classe per l'intera lista
class Lista
{
	Nodo* testa; //La testa della lista
public:

	//Costruttore
	Lista()
	{
		testa = nullptr; //La testa inizialmente non punta ad alcun nodo successivo
	}

	void inserisci(int val)
	{
		Nodo* nuovo = new Nodo(val);	//Creiamo un puntatore che punta ad un nuovo nodo con il valore desiderato

		if(testa == nullptr)	//Se la lista è vuota
		{
			//Il nuovo nodo viene aggiunto dopo la testa
			nuovo->succ = nullptr;	//nuovo non punta a niente (coda)
			testa = nuovo;			//testa ora punta a nuovo
		}
		else
		{
			//Il nuovo nodo verrà inserito al primo posto della lista
			nuovo->succ = testa;
			testa = nuovo;
		}
	}

	void rimuovi(int val)
	{
		Nodo* temp = testa;			//Creiamo una variabile temporanea che verrà usata per scorrere la lista partendo dalla testa
		cout << temp->valore << endl;
		Nodo* find = ricerca(val);

		if(find != nullptr) 
		{
			if(temp->valore == find->valore) //Se è il primo valore dopo HEAD
			{
				if (find->succ == nullptr) //Se è l'unico elemento viene fatto puntare alla coda (nullptr)
					testa = nullptr; //Non possibile usare temp
				else
				{
					cout << temp->valore << endl;
					testa = find->succ;
				}
			}
			else
			{
				//Fino a quando non trova find
				while (temp->succ->valore != find->valore)
				{
					cout << "Valore attuale = " << temp->valore << endl;
					temp = temp->succ; //Scorriamo al prossimo valore
				}

				if (find->succ == nullptr) //Se è l'ultimo viene fatto puntare alla coda (nullptr)
					temp->succ = nullptr;
				else
				{
					cout << "Valore attualer = " << temp->valore << endl;
					temp->succ = find->succ;
					//Eliminazione find
					cout << "Valore rimosso!" << endl << endl;
				}
			}
		}
		else
		{
			cout << "Valore non trovato!" << endl;
		}
		
	}

	Nodo* ricerca(int val)
	{
		Nodo* temp = testa;		//Creiamo una variabile temporanea che verrà usata per scorrere la lista partendo dalla testa
		//Fino a quando non trova il valore desiderato nella lista
		while (temp->valore != val)
		{
			//La variabile temporanea punterà al prossimo valore della lista
			temp = temp->succ;
		}

		return temp;
	}

	friend
	ostream& operator<<(ostream& out, const Lista& ls)
	{
		Nodo* temp = ls.testa;		//Creiamo una variabile temporanea che verrà usata per scorrere la lista partendo dalla testa

		out << " |HEAD|  --> ";
		while (temp != nullptr)	//Fino a quando non arriviamo alla coda
		{
			out << " |" << temp->valore << "| " << " --> ";
			temp = temp->succ;
		}

		out << "NULL" << endl;
		return out;

	}


};

int main()
{
	Lista list;

	int scelta;
	int valore = 0;
	do 
	{
		cout << "Scegli:" << endl;
		cout << "0: Esci" << endl;
		cout << "1: Visualizza" << endl;
		cout << "2: Inserisci" << endl;
		cout << "3: Rimuovi" << endl;

		cin >> scelta;

		switch (scelta)
		{
		case 0:
			break;
		case 1:
			cout << list << endl;
			break;
		case 2:
			cout << "Inserisci valore: ";
			cin >> valore;
			list.inserisci(valore);
			break;
		case 3:
			cout << "Inserisci valore: ";
			cin >> valore;
			list.rimuovi(valore);
			cout << list << endl;
			break;
		}
		

	} while (scelta != 0);
}