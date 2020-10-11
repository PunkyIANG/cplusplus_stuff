#pragma once
#include <string>
#include <iostream>
#include "./abstractTrain.cpp"
#include "./smartEdit.cpp"

using namespace std;

class Train : public AbstractTrain
{
private:
    string destination;
    string departure_time;

protected:
    int locomotiveMass;

public:
    virtual void Print() const override
    {
        cout << "Tip tren: base" << endl;
        Train::PrintSpecific();
        cout << endl;
    }

    void PrintSpecific() const
    {
        cout << "Destinatia: " << destination << endl;
        cout << "Ora plecarii: " << departure_time << endl;
        cout << "Masa totala: " << GetTrainMass() << endl;
    }

    virtual void Edit() override
    {
        Train::EditSpecific();
    }

    void EditSpecific()
    {
        cout << "Destinatia (prev: " << destination << "): ";
        EditIfNotNull(destination);
        cout << "Ora plecarii (prev: " << departure_time << "): ";
        EditIfNotNull(departure_time);
        cout << "Masa locomotivei (prev: " << locomotiveMass << "): ";
        EditIfNotNull(locomotiveMass);
    }

    virtual int GetTrainMass() const
    {
        return GetSpecificMass();
    }

    int GetSpecificMass() const
    {
        return locomotiveMass;
    }

    std::string GetDestination() const
    {
        return destination;
    }

    Train() {
        destination = "Chisinau";
        departure_time = "15:00";
        locomotiveMass = 1500;
        cout << "Created base train" << endl;
    }

    ~Train() {
        cout << "Removed base train" << endl;
    }
};