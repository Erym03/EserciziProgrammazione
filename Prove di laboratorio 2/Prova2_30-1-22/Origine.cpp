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
		srand(time(0));

		for(int i=0; i<len; i++)
		{
			int val = rand() % 26;
			char carattere = vocabolario[val];

			s[len] = carattere;
		}
	}

	virtual double elab(short a) = 0;

	short getLen()
	{
		return len;
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
};

int main()
{

}