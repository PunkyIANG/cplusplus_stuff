#include <string>
#include <iostream>
#include "./tren.cpp"
#include "./functions.cpp"

using namespace std;

enum SubProg
{
    _Stop = '0',
    _EditAll = '1',
    _PrintAll = '2',
    _SortByPassengers = '3',
    _PrintAbovePrice = '4',
    _AddNewElement = '5',
    _RemoveElemWithDestination = '6',
    _NoAction = '7'
};

int main()
{

    int n;
    std::cout << "Dati nr. trenurilor: "; //init
    std::cin >> n;
    Tren *elemente;
    elemente = new Tren[n];
    string dummy;

    bool continueLoop = true;

    while (continueLoop)
    {
        cout << endl;
        cout << (char) _Stop << ") Oprire program" << endl;
        cout << (char) _EditAll << ") Input tren" << endl;
        cout << (char) _PrintAll << ") Afisare tren" << endl;
        cout << (char) _SortByPassengers << ") Sort trenuri dupa pasageri" << endl;
        cout << (char) _PrintAbovePrice << ") Afisare trenuri cu pret > x" << endl;
        cout << (char) _AddNewElement << ") Adauga tren pe pos x" << endl;
        cout << (char) _RemoveElemWithDestination << ") Sterge trenurile" << endl;
        cout << "Optiunea: ";

        char option = '0';

        cin >> option;
        cout << endl;
        getline(cin, dummy); //dificultatile utilizarii cin si getline in acelasi script
                             //cin lasa caracterul \n in iostream, care e prins de urmatorul getline
                             //si returneaza un sir gol
                             //de aceea prindem caracterul \n intr-o variabila dummy

        switch (option)
        {
        case _Stop:
        {
            continueLoop = false;
            break;
        }

        case _EditAll:
        {
            EditAll(elemente, n);
            break;
        }

        case _PrintAll:
        {
            PrintAll(elemente, n);
            break;
        }

        case _SortByPassengers:
        {
            SortByPassengers(elemente, n);
            break;
        }

        case _PrintAbovePrice:
        {
            PrintAbovePrice(elemente, n);
            break;
        }

        case _AddNewElement:
        {
            AddNewElement(elemente, &n);
            break;
        }

        case _RemoveElemWithDestination:
        {
            RemoveElemWithDestination(elemente, &n);
            break;
        }

        default:
        {
            cout << "Optiune inexistenta" << endl;
        }
        }
    }

    return 0;
}

// int main() {
//     Tren tren;
//     char stuff;
//     cin >> stuff;
//     tren.Editare();

// }