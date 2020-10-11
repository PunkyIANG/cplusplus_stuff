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

Train* SwitchTrainType(Train *&train)
{
    int trainType = _NoChange;

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
        return train;
        break;
    }

    case _Train:
    {
        delete train;
        Train* result = new Train();
        return result;

        break;
    }

    case _PassengerTrain:
    {
        delete train;
        Train* result = new PassengerTrain();
        return result;

        break;
    }

    case _CargoTrain:
    {
        delete train;
        Train* result = new CargoTrain();
        return result;

        break;
    }

    case _MixedTrain:
    {
        delete train;
        Train* result = new MixedTrain();
        return result;

        break;
    }

    default:
    {
        cout << "Optiune inexistenta, continuam" << endl;
        return train;
    }
    }

    cout << "uh, this isn't supposed to happen" << endl;
    return train;
}

void EditAll(vector<Train *> &trains)
{
    for (auto train : trains)
    {
        train = SwitchTrainType(train);
        train->Edit();
    }
}

void PrintAll(const vector<Train *> trains)
{
    for (auto train : trains)
    {
        train->Print();
    }
}

bool CompareTrains(const Train *t1, const Train *t2)
{
    return (t1->GetTrainMass() < t2->GetTrainMass());
}

void SortByMass(vector<Train *> &trains)
{
    sort(trains.begin(), trains.end(), CompareTrains);
}

void PrintBelowMass(const vector<Train *> trains)
{
    int maxAllowedMass = 0;
    cout << "Dati masa maxima permisa: ";
    EditIfNotNull(maxAllowedMass);

    for (auto train : trains)
    {
        if (train->GetTrainMass() <= maxAllowedMass || maxAllowedMass == 0)
        {
            train->Print();
        }
    }
}

void AddAtPosition(vector<Train *> &trains)
{
    int newPos = trains.size();
    cout << "Dati pozitia elementului nou: ";
    EditIfNotNull(newPos);

    trains.insert(trains.begin() + newPos, new Train());
    trains[newPos] = SwitchTrainType(trains[newPos]);
    trains[newPos]->Edit();
}

void RemoveTrainWithDestination(vector<Train *> &trains)
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
