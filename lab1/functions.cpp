#include <string>
#include <iostream>

using namespace std;

string dummy;

void EditAll(Tren elemente[], int n)
{
    for (int i = 0; i < n; i++)
    {
        elemente[i].Editare();
    }
}

void PrintAll(Tren elemente[], int n)
{
    for (int i = 0; i < n; i++)
    {
        elemente[i].Afisare();
    }
}

void SortByPassengers(Tren elemente[], int n)
{
    for (int i = 0; i < n - 1; i++)
        for (int j = i + 1; j < n; j++)
            if (elemente[i].GetPasageri() < elemente[j].GetPasageri())
            {
                Tren temp = elemente[i];
                elemente[i] = elemente[j];
                elemente[j] = temp;
            }
}

void PrintAbovePrice(Tren elemente[], int n)
{
    int pretMinim;
    cout << "Dati pretul minim: ";
    cin >> pretMinim;
    getline(cin, dummy);

    for (int i = 0; i < n; i++)
    {
        if (elemente[i].GetPret() > pretMinim)
        {
            elemente[i].Afisare();
        }
    }
}

void AddNewElement(Tren elemente[], int &n)
{
    int pos;
    cout << "Dati pozitia elem nou: ";
    cin >> pos;
    getline(cin, dummy);
    Tren *temp = new Tren[n + 1];
    
    for (int i = 0; i <= n; i++)
    {
        if (i < pos)
        {
            temp[i] = elemente[i];
        }
        else if (i == pos)
        {
            temp[i].Editare();
            
        }
        else if (i > pos)
        {
            temp[i] = elemente[i - 1];
        }
    }

    n++;


    delete[] elemente;
    elemente = temp;
}

void RemoveElemWithDestination(Tren elemente[], int &n)
{
    string target;
    cout << "Dati destinatia de stergere: ";
    cin >> target;
    getline(cin, dummy);
    int count = 0;

    for (int i = 0; i < n; i++)
    {
        if (elemente[i].GetDestination() == target)
        {
            for (int j = i; j < n - 1; j++)
            {
                elemente[j] = elemente[j + 1];
            }
            n--;
            count++;
        }
    }

    cout << "Au fost sterse " << count << " elemente";
}