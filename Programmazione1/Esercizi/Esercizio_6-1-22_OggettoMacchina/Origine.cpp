#include <iostream>
#include <string.h>
#include "Macchina.h"

int main()
{
	Macchina Camaro = { "Chevrolet Camaro", "AXC 35F", 50, "Giallo", 500.0f, 1000, 500.0f, 7.5};

	cout << "Il conducente sale nell'auto. Scegli cosa vuoi fare:" << endl;
	cout << "1: Mostra opzioni" << endl;
	cout << "2: Accendi l'auto" << endl;
	cout << "3: Spegni auto" << endl;
	cout << "4: Muoviti" << endl;
	cout << "5: Fai rifornimento" << endl;
	cout << "6: esci" << endl;

	int scelta;
	

	do
	{
		cin >> scelta;
		
		switch (scelta)
		{
		case 1:
			cout << "1: Mostra opzioni" << endl;
			cout << "2: Accendi l'auto" << endl;
			cout << "3: Spegni auto" << endl;
			cout << "4: Muoviti" << endl;
			cout << "5: Fai rifornimento" << endl;
			cout << "6: esci" << endl;
			break;
		case 2:
			Camaro.accenditi();
			break;
		case 3:
			Camaro.spegniti();
			break;
		case 4:
			Camaro.muoviti();
			break;
		case 5:
			Camaro.rifornimento();
			break;
		case 6:
			break;
		}
	}while (scelta < 6);
	

}