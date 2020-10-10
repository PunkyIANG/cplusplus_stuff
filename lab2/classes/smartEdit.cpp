#pragma once
#include <iostream>

using namespace std;

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
