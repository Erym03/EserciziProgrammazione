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
			ptr[i] = (double)rand() / (double)RAND_MAX;	
		}
	}

	virtual double foo(short a) const = 0;

	//Ostream A
	virtual ostream& print(ostream& os)
	{
		cout << "ptr = [";
		for(int i=0; i<len; i++)
		{
			cout << ptr[i] << " ";
		}
		cout << "] ";

		return os;
	}

	//Overloading []
	double& operator[](short a)
	{
		return ptr[a % len];
	}
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

	//Ostream B
	virtual ostream& print(ostream& os)
	{
		A::print(os);
		cout << ", alpha = " << alpha << ", foo(5) = " << foo(5) << endl;

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

	T g(T k) const
	{
		return 3 * k;
	}

	double foo(short r) const
	{
		return g(r * x);
	}

	//Ostream C
	virtual ostream& print(ostream& os)
	{
		A::print(os);
		cout << ", x = " << x << ", foo(5) = " << foo(5) << ", g(5) =" << g(5) << endl;

		return os;
	}
};

//Overloading <<
ostream& operator<<(ostream &os, A& a)
{
	return a.print(os);
}


int main()
{

	//Generazione 30 oggetti casuali
	srand(328832748);
	A *vett[30];

	double maxFoo = 0;
	double sumG = 0;
	
	for(int i =0; i<30; i++)
	{
		short n = 1 + rand() % 5;
		cout << n << endl;
		switch (rand()%3)
		{
		case 0:
			vett[i] = new B(n, n / 100.0); break;
		case 1:
			vett[i] = new C<double>(n); break;
		case 2:
			vett[i] = new C<int>(n); break;
		}
	}

	for(int i = 0; i<30; i++)
	{
		cout << i << " - " << typeid(*vett[i]).name() << ") " << *vett[i] << endl;

		//Se è di classe C<double>
		if(typeid(*vett[i]) == typeid(C<double>))
			sumG += static_cast<C<double>*> (vett[i])->g(5);

		//Se il valore è massimo di maxFoo
		if (vett[i]->foo(5) > maxFoo)
			maxFoo = vett[i]->foo(5);
	}

	cout << endl << "maxFoo = " << maxFoo << endl;
	cout << endl << "sumG = " << sumG << endl;
	cout << endl << "(*vett[9])[5] = " << (* vett[9])[1] << endl;

}