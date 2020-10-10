#pragma once
#include <string>
#include <iostream>
#include "./abstractTrain.cpp"
#include "./smartEdit.cpp"

using namespace std;

class Train : public AbstractTrain
{
private:
    string destinatia;
    string ora_plecarii;

protected:
    int locomotiveMass;

public:
    virtual void Print() const override
    {
        Train::PrintSpecific();
        cout << endl;
    }

    void PrintSpecific() const
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
        return destinatia;
    }
};