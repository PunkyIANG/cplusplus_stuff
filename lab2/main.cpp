#include "./classes/mixedTrain.cpp"
#include "./functions.cpp"
#include "./classes/smartEdit.cpp"
#include <vector>
using namespace std;

enum SubProg
{
    _Stop = 0,
    _EditAll = 1,
    _PrintAll = 2,
    _SortByMass = 3,
    _PrintBelowMass = 4,
    _AddAtPosition = 5,
    _RemoveTrainWithDestination = 6,
    _NoAction = 7
};

int main()
{
    vector<Train *> trains;
    int n = 3;  //default value
    cout << "Dati nr. trenurilor: "; //init
    EditIfNotNull(n);

    for (int i = 0; i < n; i++)
    {
        trains.push_back(new Train);
    }

    cout << "Initialized " << n << " default trains" << endl
         << endl;

    bool continueLoop = true;

    while (continueLoop)
    {
        cout << _Stop << ") Oprire program" << endl;
        cout << _EditAll << ") Input tren" << endl;
        cout << _PrintAll << ") Afisare tren" << endl;
        cout << _SortByMass << ") Sort trenuri dupa masa" << endl;
        cout << _PrintBelowMass << ") Afisare trenuri cu masa < x" << endl;
        cout << _AddAtPosition << ") Adauga tren pe pos x" << endl;
        cout << _RemoveTrainWithDestination << ") Sterge trenurile" << endl;
        cout << "Optiunea: ";

        int option = _NoAction;

        EditIfNotNull(option);

        switch (option)
        {
        case _Stop:
        {
            continueLoop = false;
            break;
        }

        case _EditAll:
        {
            EditAll(trains);
            break;
        }

        case _PrintAll:
        {
            PrintAll(trains);
            break;
        }

        case _SortByMass:
        {
            SortByMass(trains);
            break;
        }

        case _PrintBelowMass:
        {
            PrintBelowMass(trains);
            break;
        }

        case _AddAtPosition:
        {
            AddAtPosition(trains);
            break;
        }

        case _RemoveTrainWithDestination:
        {
            RemoveTrainWithDestination(trains);
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