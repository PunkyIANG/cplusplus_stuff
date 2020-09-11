#include <string>
#include <iostream>

class Tren
{
private:
    int nr_pasageri;
    int pretul_biletului;
    std::string destinatia;
    std::string ora_plecarii;


    void EditIfNotNull(std::string *data)
    {
        std::string temp;
        std::getline(std::cin, temp); //folosim getline in loc de cin ca sa putem primi un string gol ca input (basically null)

        if (temp != "")
        { //daca stringul temp este gol, atunci valoarea initiala nu se schimba
            *data = temp;
        }
        std::cout << std::endl;
    }

    void EditIfNotNull(int *data)
    {
        std::string temp;
        std::getline(std::cin, temp);

        if (temp != "")
        {
            try
            {
                *data = stoi(temp); //convertim in int
            }
            catch (std::invalid_argument const &e)
            {
                std::cout << "Bad input: std::invalid_argument thrown" << '\n'; //erori in caz de input incorect
            }
            catch (std::out_of_range const &e)
            {
                std::cout << "Integer overflow: std::out_of_range thrown" << '\n'; //valoarea initiala nu este afectata in caz de eroare
            }
        }

        std::cout << std::endl;
    }

public:
    Tren()
    {
        destinatia = "---";
        ora_plecarii = "--:--";
        nr_pasageri = -1; // logic valorile date de obicei nu pot avea valori -1
        pretul_biletului = -1;
    }

    Tren(std::string _destinatia, std::string _ora_plecarii, int _nr_pasageri, int _pretul_biletului)
    {
        destinatia = _destinatia;
        ora_plecarii = _ora_plecarii;
        nr_pasageri = _nr_pasageri;
        pretul_biletului = _pretul_biletului;
    }

    ~Tren()
    {
        std::cout << "Tren cu dest " << destinatia << " cu ora plec. " << ora_plecarii << " a fost sters";
    }

    void Editare()
    {
        std::cout << "Transmiteti un string gol ca sa nu schimbati valoarea curenta" << std::endl;

        std::cout << "Dati destinatia noua (prev: " << destinatia << "): ";
        EditIfNotNull(&destinatia);

        std::cout << "Dati ora plecarii noua (prev: " << ora_plecarii << "): ";
        EditIfNotNull(&ora_plecarii);

        std::cout << "Dati nr nou de pasageri (prev: " << nr_pasageri << "): ";
        EditIfNotNull(&nr_pasageri);

        std::cout << "Dati pretul nou a biletului (prev: " << pretul_biletului << "): ";
        EditIfNotNull(&pretul_biletului);
    }

    void Afisare()
    {
        std::cout << "Trenul spre " << destinatia << " porneste la ora " << ora_plecarii
                  << " cu " << nr_pasageri << " pasageri. Un bilet costa " << pretul_biletului << " lei." << std::endl
                  << std::endl;
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