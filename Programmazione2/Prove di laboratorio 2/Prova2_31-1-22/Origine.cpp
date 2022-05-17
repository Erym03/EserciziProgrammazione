#include <iostream>
#include <ctime>
#include <string>

using namespace std;

class A
{
	char* ptr;
	short len;

public:
	A(short m, char c)
	{
		len = m;
		ptr = new char[len];

		srand(time(0));

		for(int i=0; i<len; i++)
		{
			ptr[i] = rand() % ('a' - c + 1) + 'a';
		}
	}

	virtual string elab(short a, char c) = 0;

	short getLen()
	{
		return len;
	}

protected:
	char get(short i)
	{
		return ptr[i%len];
	}
};

class B: public A
{
	double x;
public:
	B(short m, double y, char c) : A(m, c), x(y) {};

	double foo(short s)
	{
		return sin(x + s) / log(x + s);
	}

	string elab(short a, char c)
	{
		string ritorno = "";

		for(int i=0; i<getLen(); i++)
		{
			int differenza = get(i) - abs(c);
			if(differenza <= a)
			{
				ritorno += get(i);
			}
		}

		return ritorno;
	}
};

template <typename T>
class C: public A
{
	T y;
public:
	C(short n, double k, char c): A(n, c)
	{
		if(typeid(T) == typeid(short))
		{
			y = 100 * (int)(k + 0.5);
		}
		else
		{
			y = k;		}
	}

	string elab(short a, char c)
	{
		string ritorno = "";

		if(getLen() >= a)
		{
			
		}
		else
		{
			for(int i=0; i< getLen(); i++)
			{
				ritorno += get(i);
			}
		}
	}

	double g(short w)
	{
		return sin(w + y);
	}
};

int main()
{

}