/******************************************************************************

Definire più metodi per stampare i primi n numeri primi, e valutare il loro tempo di
esecuzione per valori di n crescenti.

*******************************************************************************/

#include <iostream>
#include <chrono>
#include <thread>

using namespace std;


//EX 1
void funzione1(int n)
{
    int contatore = 0;
    int numero = 2;

    //Fino a quando non abbiamo trovato i primi n numeri primi
    while (contatore < n)
    {
        bool isPrimo = true;
        for (int i = 2; i < numero; i++)
        {
            if (numero % i == 0) //Se non è divisibile solo per 1 o sé stesso
            {
                isPrimo = false;
            }

        }

        if (isPrimo)
        {
            contatore++;
            cout << numero << " è un numero primo!" << endl;
        }

        numero++;
    }
    this_thread::sleep_for(std::chrono::seconds(3));

}

void funzione2(int n)
{
    int contatore = 0;
    int numero = 1;

    //Fino a quando non abbiamo trovato i primi n numeri primi
    
    while (contatore < n)
    {
        cout << "-    -   -   -   -   -   -   -   -   -" << endl;
        cout << "         ELENCO NUMERI PRIMI" << endl;
        if (numero > 1)
        {
            bool isPrimo = true;
            int i = 2;
            while (i < numero)
            {
                if (numero % i == 0) //Se non è divisibile solo per 1 o sé stesso
                {
                    isPrimo = false;
                }
                i = i + 1;
            }

            if (isPrimo)
            {
                contatore++;
                cout << numero << " è un numero primo!" << endl;
            }


        }

        numero++;
    }
    cout << "         ELENCO NUMERI PRIMI" << endl;
    cout << "-    -   -   -   -   -   -   -   -   -" << endl;
    

}

int main()
{
    auto start = std::chrono::high_resolution_clock::now();
    //funzione1(10000);   //28 secondi
    funzione2(10000);   //39 secondi
    auto end = std::chrono::high_resolution_clock::now();
    auto int_s = std::chrono::duration_cast<std::chrono::seconds>(end - start);
    cout << "funcSleep() elapsed time is " << int_s.count() << " seconds )" << std::endl;
}
