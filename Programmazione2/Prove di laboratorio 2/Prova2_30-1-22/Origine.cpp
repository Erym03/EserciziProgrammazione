#include <iostream>
#include <string>
#include <ctime>
using namespace std;

class A
{
	char* s;
	short len;

public:
	A(short m)
	{
		len = m;
		s = new char[len];

		char vocabolario[26] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x','y', 'z'};

		for(int i=0; i<len; i++)
		{
			int val = rand() % 26;
			char carattere = vocabolario[val];

			s[i] = carattere;
		}
	}

	virtual double elab(short a) = 0;

	short getLen()
	{
		return len;
	}

	//ostream print A
	virtual ostream& print(ostream& os)
	{
		cout << "S = ";
		for(int i=0; i<len; i++)
		{
			cout << s[i];
		}
		cout << " ";
		return os;
	}

protected:
	char get(short i)
	{
		return s[i%len];
	}
};

class B : public A
{
	int p;

public:
	B(short m, int x) : A(m), p(x) {}

	double elab(short a)
	{
		char dizionario[5] = { 'a','e','i','o','u' };
		int V = 0;
		int C = 0;

		int lunghezza = getLen();

		for (int i = 0; i < lunghezza; i++)
		{
			bool isVocale = false;

			//Verifica vocali
			for (int j = 0; j < 5; j++)
			{
				if (get(i) == dizionario[j])
				{
					V++;
					isVocale = true;
				}

			}

			if (!isVocale)
				C++;
		}

		return V / (C + 1);

	}

	//ostream print B
	virtual ostream& print(ostream& os)
	{
		A::print(os);
		cout << "p = " << p;
		cout << " elab(0) = " << elab(0) << endl;

		return os;
	}

	B operator++ ()
	{
		//Quando incrementiamo con il prefisso ++ un oggetto B aumenterà di 1 la variabile int p
		p++;
		return *this; //OK, i tre numeri risulteranno incrementati, rest. una copia
	}

protected:

	bool test()
	{
		char dizionario[5] = { 'a','e','i','o','u' };

		for(int i = 0; i<4; i++)
		{
			for(int j=0; j<5; j++)
			{
				if (get(i) == dizionario[j])
					return true;
			}
		}

		return false;
	}

	
};

/*	OVERLOADING ++ E -- dato un oggetto Vettore3D

//1. Operatore unario PREFISSO implementato come MEMBRO
Vettore3D &Vettore3D::operator ++ ()
  {
	x++;
	y++;
	z++;
	return *this; //OK, i tre numeri risulteranno incrementati, rest. una copia
  }
*/

class C : public A
{
	char x;

public:

	C(short n, char c) : A(n), x(c) {};

	double elab(short r)
	{
		int counter = 0;

		for(int i=(r % getLen()); i<getLen(); i++)
		{
			if (get(i) >= 'x')
				counter++;
		}

		return counter;
	}

	string g(char c)
	{
		string ritorno = "";
		ritorno + ritorno + x + c;
		return ritorno;
	}

	//ostream print B
	virtual ostream& print(ostream& os)
	{
		A::print(os);
		cout << "x = " << x;
		cout << " elab(3) = " << elab(3) << endl;

		return os;
	}
};

/*

//2. Operatore unario POSTFISSO implementato come MEMBRO
Vettore3D Vettore3D::operator ++ (int) // int - parametro ``dummy'' si usa per distinguere le due versioni
  {
	Vettore3D aux = *this; //aux e' una copia
	x++; // incremento
	y++;
	z++;
	return aux; // x,y e z in aux sono invariati
  }

*/

//Overloading <<
ostream &operator<<(ostream& os, A& a)
{
	return a.print(os);
}

int main()
{
	
	A *vett[50];
	srand (111222333);
	for (int i = 0; i < 50; i++) {
		short n = 1 + rand() % 10;
		if(rand() % 2 == 0)
			vett[i] = new B(n, rand() % 10 + 1);
		else
			vett[i] = new C(n, (char)(rand() % ((int)'z' - (int)'a' + 1) + (int)'a'));
	}	

	
	//Visualizza tutti i valori
	for (int i = 0; i < 50; i++) {
		cout << *vett[i] << endl;
	}

	//Converte un oggetto di tipo A ad un tipo B per richiamare le funzioni di B
	static_cast<B*>(vett[0]++);
}



