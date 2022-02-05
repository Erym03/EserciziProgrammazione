#include <iostream>
#include <cstdlib> //Per il random
#include <cmath> //Per il log
#include <typeinfo>

using namespace std;

class A
{
protected:
	double *ptr;
	short len;

public:
	A(short n)
	{
		len = n;
		ptr = new double[len];

		for(int i = 0; i<len; i++)
		{
			ptr[i] = (double)rand() / (float)RAND_MAX;
		}
	}

	virtual double foo(short a) const = 0;

	//Osteram A
	virtual ostream& print(ostream& os)
	{
		cout << "arr = [";
		for(int i=0; i<len; i++)
		{
			cout << ptr[i] << " ";
		}
		cout << " ] ";
		return os;
	}
};

ostream & operator<<(ostream &os, A& a){
  return a.print(os); 
}

class B: public A
{
	double alpha;

	double extract(short s) const
	{
		return (ptr[s % len] + alpha) / 2;
	}

public:

	B(short m, double d) : A(m), alpha(d) {}

	double foo(short b) const
	{
		return log(1 + extract(b));
	}

	//Osteram B
	virtual ostream& print(ostream& os)
	{
		A::print(os);
		cout << "Alpha = " << alpha<<", ";
		cout << "Foo(5) = " << foo(5);

		return os;
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

	double foo(short r) const
	{
		return g(r * x);
	}

	T g(T k) const
	{
		return 3 * k;
	}

	//Osteram C
	virtual ostream& print(ostream& os)
	{
		A::print(os);
		cout << "X = " << x << ", ";
		cout << "Foo(5) " << foo(5) << ", ";
		cout << "g(5) = " << g(5);

		return os;
	}
};

int main() 
{

	srand(328832748);
	A *vett[30];


	for (int i = 0; i < 30; i++) {
		short n = 1 + rand() % 5;
		switch (rand() % 3) {
		case 0: vett[i] = new B(n, n / 100.0); break;
		case 1: vett[i] = new C<double>(n); break;
		case 2: vett[i] = new C<int>(n);
		}
	}

	double maxFoo = 0;
	double sumg = 0;

	for (int i = 0; i < 30; i++) 
	{
		cout << typeid(*vett[i]).name() <<" ) " << *vett[i] << endl;

		if (vett[i]->foo(5) > maxFoo)
		{
			maxFoo = vett[i]->foo(5);
		}

		if(typeid(*vett[i]) == typeid(C<double>))
		{
			sumg += (static_cast<C<double>*> (vett[i]))->g(5);
		}
	}

	cout << endl << "maxFoo = " << maxFoo << endl << endl;
	cout << endl << "sumg = " << sumg << endl << endl;




}