#include <iostream>
#include <ctime>

using namespace std;


class A 
{
protected:
	double* ptr;
	short len;

public:
	A(short n)
	{
		srand(time(0));
		len = n;
		ptr = new double[len];

		for(int i=0; i<len; i++)
		{
			ptr[i] = (short)rand() / (short)RAND_MAX;	
		}
	}

	virtual double foo(short a) const = 0;
};

class B: public A
{
	double alpha;

	double extract(short s) const
	{
		return (ptr[s % len] + alpha) / 2;
	}

public:
	B(short m, double d): A(m), alpha(d){}

	double foo(short b) const
	{
		return log(1 + extract(b));
	}

};

template <typename T>
class C: public A
{
	T x;
public:

	C(short n): A(n)
	{
		if(typeid(x) == typeid(short))
		{
			x = g(n);
		}
		else
		{
			x = log(1 + n);
		}
	}

	T g(T k) const
	{
		return 3 * k;
	}

	double foo(short r) const
	{
		return g(r * x);
	}
};


int main()
{

}