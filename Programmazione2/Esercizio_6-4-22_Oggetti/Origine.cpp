#include <iostream>
using namespace std;

//Esempio classe senza costruttore (variabili public)
class SenzaCostruttore
{
public:
	float f;
	char c;
	int i;

	void printAll()
	{
		cout << f << " '" << c << "' " << i << endl;
	}
};


class A
{
public:
	int uno = 1;

	A()
	{
	}

	A(int one, int two)
	{
		uno = one;
		due = two;
	}

	A(int one, int two, int three) : tre(three)
	{
		uno = one;
		due = two;
		//tre = three; //ERRORE
	}

	void changeValue(int variable, int value)
	{
		if (variable == 1)
			uno = value;
		else if(variable == 2)
			due = value;
	}

	void printAll()
	{
		cout <<uno << " " << due << " " << tre << endl;
	}

private:
	int due;
	int const tre = 6;
};

int main()
{
	cout << "-		-		CLASSE1" << endl;
	//Esempio creazione classe senza costruttore
	SenzaCostruttore classe1 {4.5, 'a', 12};
	classe1.printAll();
	

	cout << "-		-		CLASSA" << endl;
	//Classe con costruttore vuoto
	A classA;
	classA.uno = 11;
	classA.changeValue(2, 24);
	classA.printAll();
	
	
	cout << "-		-		CLASSA2" << endl;
	//Classe con costruttore in cui passiamo solo 2 valori
	A classA2 (5, 12);
	classA2.printAll();


	cout << "-		-		CLASSA3" << endl;
	//Classe con costruttore in cui passiamo solo 2 valori
	A classA3(213, 5, 12);
	classA3.printAll();
}