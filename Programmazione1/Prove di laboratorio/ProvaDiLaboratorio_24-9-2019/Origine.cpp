#include <iostream>
#include <string>

using namespace std;


/*
Data una matrice S di puntatori a stringhe, creare un metodo che ritorni la vocale più frequente nella matrice.
*/

bool metodo(int** K, int n, double w)
{
    //Assegnare valori massimo e minimo
    double minimo = (double)K[0][0];
    double massimo = (double)minimo;
    double rapporto;

    //Calcolare diagonale secondaria
    //Verifica per righe:
    for (int i = 0, j = (n - 1); i < n; i++, j--)
    {
        int val = (double)K[i][j];

        if (val < minimo)
            minimo = val;

        if (val > massimo)
            massimo = val;
    }

    rapporto = minimo / massimo;

    if (rapporto <= w)
        return true;

    return false;


}

bool metodoStringhe(string** A, int n, int m, unsigned short k, unsigned short s)
{
    //Verifica per righe
    for (int i = 0; i < n; i++)
    {
        int conta_colonne = 0;
        //Verifica per colonne
        for (int j = 0; j < m; j++)
        {
            int conta_lettere = 0;
            string stringa = A[i][j];

            //Verifica ogni lettera
            for (int l = 0; l < stringa.length(); l++)
            {

                if (stringa[l] >= 'A' && stringa[l] <= 'Z') //Se è maiuscola
                    conta_lettere++;
            }

            if (conta_lettere < s)
                conta_colonne++;

        }

        if (conta_colonne >= k)
            return true;
    }

    return false;
}

char metodo3(string*** S, int n, int m)
{
    char vocabolario[5] = { 'a', 'e', 'i', 'o','u' };
    int counter_vocale[5] = { 0, 0, 0, 0, 0 };
    int vocaleMax[2] = { 0, 0 };                        //0 = vocale; 1 = n°ricorsioni vocale

    //Verifica per righe
    for (int i = 0; i < n; i++)
    {
        //Verifica per colonne
        for (int j = 0; j < m; j++)
        {

            string stringa = *S[i][j];
            int lunghezzaS = stringa.length();

            //Verifica per ogni lettera della stringa
            for (int l = 0; l < lunghezzaS; l++)
            {
                //Verifica per ogni vocale
                for (int k = 0; k < 5; k++)
                {
                    //Se la stringa ha una vocale, aumentare il corrispettivo contatore
                    if (stringa[l] == vocabolario[k])
                        counter_vocale[k]++;
                }
            }

        }
    }

    //Conteggio vocaleMax
    for (int i = 0; i < 5; i++)
    {
        if (counter_vocale[i] > vocaleMax[1]) //Se la vocale è maggiore di vocaleMax
        {
            vocaleMax[0] = i;
            vocaleMax[1] = counter_vocale[i];
        }
    }

    return vocabolario[vocaleMax[0]];
}

string **metodo4(string**A, int n, int m, int k)
{
    char vocabolario[] = { 'j', 'k', 'w', 'x', 'y'};

    string** ritorno = A;

    //Verifica righe
    for(int j=0; j<n; j++)
    {
        //Verifica lettere
        for (int i = 0; i < 5; i++)
        {
            
            size_t found = ritorno[j][k].find(vocabolario[i]);
            
            //Cancella tutte le ricorsione della lettera nella stringa  
            while (found != string::npos)
            {
                cout << "Trovato " << vocabolario[i] << ": " << found << endl;
                ritorno[j][k].erase(found, 1);
                found = ritorno[j][k].find(vocabolario[i]);
            }
        }
    }

    return ritorno;
}


int main()
{
    /*
    int ** matrix = new int *[5];

    for(int i=0; i<5; i++)
    {
        matrix[i] = new int[5];

    }

    //Inserimento
    for(int i=0; i<5; i++)
    {
        for(int j=0; j<5; j++)
        {
            cout<<"Inderisci valore " << i<< " "<<j<<endl;
            cin>>matrix[i][j];
        }
    }

    //Stampa matrice
    for(int i=0; i<5; i++)
    {
        for(int j=0; j<5; j++)
        {
            cout<<matrix[i][j]<< " - ";
        }
        cout<<endl;
    }

    cout<<metodo(matrix, 5, 2.2)<<endl;
    */

    /*
    string*** matrix = new string ** [5];

    for (int i = 0; i < 5; i++)
    {
        matrix[i] = new string*[5];
        for (int j = 0; j < 5; j++)
        {
            matrix[i][j] = new string();
        }
    }
    
    

    //Inserimento
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            cout << "Inderisci valore " << i << " " << j << endl;
            cin >> *matrix[i][j];
        }
    }

    //Stampa matrice
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            cout << *matrix[i][j] << " - ";
        }
        cout << endl;
    }

    cout <<"La vocale più ricorrente: "<<metodo3(matrix, 5, 5)<< endl;
    */
    
    
    


    
    string** matrix = new string *[5];

    for (int i = 0; i < 5; i++)
    {
        matrix[i] = new string[5];

    }

    //Inserimento
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            cout << "Inderisci valore " << i << " " << j << endl;
            cin >> matrix[i][j];
        }
    }

    //Stampa matrice
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            cout << matrix[i][j] << " - ";
        }
        cout << endl;
    }

    matrix = metodo4(matrix, 5, 5, 3);

    cout << endl << endl << "Matrice dopo cancellazione" << endl << endl;

    /*
    string a = "ciao camico";
    char b[2] = { 'a', 'b' };
    if (a.find(b[0]) != string::npos)
        cout << "trovato";
    */
    

    
    //Stampa matrice
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            cout << matrix[i][j] << " - ";
        }
        cout << endl;
    }
    
    
    
    
    
}
