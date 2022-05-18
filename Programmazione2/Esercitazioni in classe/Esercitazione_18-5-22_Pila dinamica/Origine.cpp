#include <iostream>
using namespace std;

class Nodo
{
public:
	int valore;
	Nodo* succ;
};

class Stack
{
	Nodo* top;

public:
	//Costruttore
	Stack()
	{
		top = nullptr;
	}

	~Stack()
	{
		while (top!=nullptr)
		{
			Nodo* tmp = top;
			top = top->succ;
			delete tmp;
		}
	}

	void push(int n)
	{
		Nodo* ptr = new Nodo;
		ptr->valore = n;
		ptr->succ = top;
		top = ptr;
	}

	int pop()
	{
		Nodo* tmp = top;			//Variabile temporanea
		int val = top->valore;		//Prende il valore dall'elemento in cima alla pila
		top = top->succ;			//Top punterà al secondo valore in cima alla pila
		delete tmp;					//Eliminiamo il primo valore
		return val;					//Ritorniamo il valore ottenuto
	}

	int peek()
	{
		return top->valore;		//Ritorna il valore dall'elemento in cima alla pila
	}

	friend
		ostream& operator<<(ostream& out, const Stack& s);
	

	
};
ostream& operator<<(ostream& out, const Stack& s)
{
	Nodo* tmp = s.top; //Il nodo tmp scorrerà da top fino alla fine della pila

	out << "	PILA	" << endl;

	while (tmp != nullptr)
	{
		out << " |" << tmp->valore << "| " << endl;
		tmp = tmp->succ;
	}

	return out;
}

int main()
{
	Stack pila;

	pila.push(10);
	pila.push(1);
	pila.push(2);
	pila.push(34);
	pila.push(23);
	pila.push(9);

	pila.pop();

	cout << pila << endl;
}