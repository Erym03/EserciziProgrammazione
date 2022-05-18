#include <iostream>
using namespace std;

int main()
{
	int num = 12000;
	int *p;		//Dichiara p come puntatore a int
	p = &num;	//Assegna a p l'indirizzo di num
	//Le precedenti due righe possono essere anche scritte: int*p = &num;

	//Da notare la differenza tra l'indirizzo e il contenuto della cella puntata
	cout<<"Indirizzo di p: "<<p<<endl;
	cout<<"Contenuto dell'indirizzo puntato da p: "<<*p<<endl;
	*p = 10; 	//Modifica il dato puntato da p -- il risultato è lo stesso di scrivere: num = 10
	cout<<"Contenudo dell'indirizzo puntato da p dopo la modifica: "<<*p<<endl<<endl;

	//GLi array puntano sempre al primo elemento dell'array stesso
	int array[] = {1,2,3};
	cout<<"array = "<<array<<", *array = "<<*array<<", array[0] = "<<array[0]<<endl<<endl;

//-	-	-	-	-	-	ARRAY	-	-	-	-	-
	//Possiamo assegnare ai puntatori un array:
	int *ptr;
	int arr[] = {4,5,6};	//Gli array sono puntatori costatnti
	ptr = arr;		//ptr così punta alla prima cella dell'array
	cout<<"Valore contenuto in ptr[0] = "<<ptr[0]<<endl;
	cout<<"Valore contenuto in ptr[1] = "<<ptr[1]<<endl;
	cout<<"Valore contenuto in ptr[2] = "<<ptr[2]<<endl;
	cout<<"Valore di ptr = "<<ptr<<endl<<"valore di arr = "<<arr<<endl<<endl<<endl;	//Avranno lo stesso valore!!

	//Ecco un modo alternativo per accedere ai dati di un array
	cout<<"*arr = "<<*arr<<endl;
	cout<<"*(arr + 1) = "<<*(arr+1)<<endl;
	cout<<"*(arr + 2) = "<<*(arr+2)<<endl;
	//O anche:
	cout<<"*ptr = "<<*ptr<<endl;
	cout<<"*(ptr + 1) = "<<*(ptr + 1)<<endl;
	cout<<"*(ptr + 2) = "<<*(ptr + 2)<<endl<<endl;

	//Operatori applicati ai puntatori
	cout<<"*(++ptr)"<<*(++ptr)<<endl;
	cout<<"*(--ptr)"<<*(--ptr)<<endl;
	cout<<"*(ptr++)"<<*(ptr++)<<endl;

}
