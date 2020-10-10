#pragma once
#include "./classes/mixedTrain.cpp"
#include "./classes/smartEdit.cpp"
#include <bits/stdc++.h>
#include <vector>
using namespace std;

enum TrainTypes
{
    _NoChange = 0,
    _Train = 1,
    _PassengerTrain = 2,
    _CargoTrain = 3,
    _MixedTrain = 4
};

void SwitchTrainType(Train *train)
{
    int trainType = _NoChange;
    Train *temp;
    cout << "Started cast" << endl;
    temp = train;

    //TODO: print some options over here
    cout << "Tipuri valabile: " << endl;
    cout << "0) Fara schimbari" << endl;
    cout << "1) Tren" << endl;
    cout << "2) Tren de pasageri" << endl;
    cout << "3) Tren cargo" << endl;
    cout << "4) Tren mixt" << endl;
    cout << "Optiunea: ";

    EditIfNotNull(trainType);

    switch (trainType)
    {
    case _NoChange:
    {
        break;
    }

    case _Train:
    {
        train = new Train();
        *train = dynamic_cast<Train &>(*temp);
        cout << "Converted to train" << endl;
        break;
    }

    case _PassengerTrain:
    {
        train = new PassengerTrain();
        *train = dynamic_cast<PassengerTrain &>(*temp);
        cout << "Converted to passenger train" << endl;
        break;
    }

    case _CargoTrain:
    {
        train = new CargoTrain();
        *train = dynamic_cast<CargoTrain &>(*temp);
        cout << "Converted to cargo train" << endl;
        break;
    }

    case _MixedTrain:
    {
        train = new MixedTrain();
        *train = dynamic_cast<MixedTrain &>(*temp);
        cout << "Converted to mixed train" << endl;
        break;
    }

    default:
    {
        cout << "Optiune inexistenta, continuam" << endl;
    }
    }

    delete temp;
}

void EditAll(vector<Train *> trains)
{
    SwitchTrainType(trains[0]);
}

void PrintAll(const vector<Train *> trains)
{
    for (auto &train : trains)
    {
        train->Print();
    }
}

bool CompareTrains(const Train *t1, const Train *t2)
{
    return (t1->GetTrainMass() < t2->GetTrainMass());
}

void SortByMass(vector<Train *> trains)
{
    sort(trains.begin(), trains.end(), CompareTrains);
}

void PrintBelowMass(const vector<Train *> trains)
{
    int maxAllowedMass = 0;

    cout << "Dati masa maxima permisa: ";
    EditIfNotNull(maxAllowedMass);

    for (auto &train : trains)
    {
        if (train->GetTrainMass() <= maxAllowedMass || maxAllowedMass == 0)
        {
            train->Print();
        }
    }
}

void EditAtPosition(vector<Train *> trains)
{
}

void RemoveTrainWithDestination(vector<Train *> trains)
{
    string destinationToRemove = "";
    cout << "Dati destinatia de sters: ";
    EditIfNotNull(destinationToRemove);

    for (int i = 0; i < trains.size(); i++)
    {
        if (trains[i]->GetDestination() == destinationToRemove)
        {
            trains.erase(trains.begin() + i);
            i--;
        }
    }
}
