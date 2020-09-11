#include <string>
#include <iostream>

using namespace std;

class Tren
{
private:
    int nr_pasageri;
    int pretul_biletului;
    string destinatia;
    string ora_plecarii;


    void EditIfNotNull(string *data)
    {
        string temp;
        getline(cin, temp); //folosim getline in loc de cin ca sa putem primi un string gol ca input (basically null)

        if (temp != "")
        { //daca stringul temp este gol, atunci valoarea initiala nu se schimba
            *data = temp;
        }
        cout << endl;
    }

    void EditIfNotNull(int *data)
    {
        string temp;
        getline(cin, temp);

        if (temp != "")
        {
            try
            {
                *data = stoi(temp); //convertim in int
            }
            catch (invalid_argument const &e)
            {
                cout << "Bad input: std::invalid_argument thrown" << '\n'; //erori in caz de input incorect
            }
            catch (out_of_range const &e)
            {
                cout << "Integer overflow: std::out_of_range thrown" << '\n'; //valoarea initiala nu este afectata in caz de eroare
            }
        }

        cout << endl;
    }

public:
    Tren()
    {
        destinatia = "---";
        ora_plecarii = "--:--";
        nr_pasageri = -1; // logic valorile date de obicei nu pot avea valori -1
        pretul_biletului = -1;
    }

    Tren(string _destinatia, string _ora_plecarii, int _nr_pasageri, int _pretul_biletului)
    {
        destinatia = _destinatia;
        ora_plecarii = _ora_plecarii;
        nr_pasageri = _nr_pasageri;
        pretul_biletului = _pretul_biletului;
    }

    ~Tren()
    {
        cout << "Tren cu dest " << destinatia << " cu ora plec. " << ora_plecarii << " a fost sters" << endl;
    }

    void Editare()
    {
        cout << "Transmiteti un string gol ca sa nu schimbati valoarea curenta" << endl;

        cout << "Dati destinatia noua (prev: " << destinatia << "): ";
        EditIfNotNull(&destinatia);

        cout << "Dati ora plecarii noua (prev: " << ora_plecarii << "): ";
        EditIfNotNull(&ora_plecarii);

        cout << "Dati nr nou de pasageri (prev: " << nr_pasageri << "): ";
        EditIfNotNull(&nr_pasageri);

        cout << "Dati pretul nou a biletului (prev: " << pretul_biletului << "): ";
        EditIfNotNull(&pretul_biletului);
    }

    void Afisare()
    {
        cout << "Trenul spre " << destinatia << " porneste la ora " << ora_plecarii
                  << " cu " << nr_pasageri << " pasageri. Un bilet costa " << pretul_biletului << " lei." << endl
                  << endl;
    }

    int GetPret()
    {
        return pretul_biletului;
    }

    int GetPasageri()
    {
        return nr_pasageri;
    }

    std::string GetDestination()
    {
        return destinatia;
    }
};