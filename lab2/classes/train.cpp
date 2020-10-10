#pragma once
#include <string>
#include <iostream>
#include "./abstractTrain.cpp"

using namespace std;

class Train : public AbstractTrain
{
private:
    string destinatia;
    string ora_plecarii;

protected:
    int locomotiveMass;

    void EditIfNotNull(string &data)
    {
        string temp;
        getline(cin, temp); //folosim getline in loc de cin ca sa putem primi un string gol ca input (basically null)

        if (temp != "")
        { //daca stringul temp este gol, atunci valoarea initiala nu se schimba
            data = temp;
        }
        cout << endl;
    }

    void EditIfNotNull(int &data)
    {
        string temp;
        getline(cin, temp);

        if (temp != "")
        {
            try
            {
                data = stoi(temp); //convertim in int
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
    virtual void Print() override
    {
        Train::PrintSpecific();
    }

    void PrintSpecific()
    {
        cout << "Destinatia: " << destinatia << endl;
        cout << "Ora plecarii: " << ora_plecarii << endl;
        cout << "Masa totala: " << GetTrainMass() << endl;
    }

    virtual void Edit() override
    {
        Train::EditSpecific();
    }

    void EditSpecific()
    {
        cout << "Destinatia: ";
        EditIfNotNull(destinatia);
        cout << "Ora plecarii: ";
        EditIfNotNull(ora_plecarii);
        cout << "Masa locomotivei: ";
        EditIfNotNull(locomotiveMass);
    }

    virtual int GetTrainMass()
    {
        return GetSpecificMass();
    }

    int GetSpecificMass()
    {
        return locomotiveMass;
    }
};