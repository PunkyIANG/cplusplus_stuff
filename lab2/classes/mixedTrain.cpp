#pragma once
#include "./train.cpp"
#include "./cargoTrain.cpp"
#include "./passengerTrain.cpp"

class MixedTrain : public CargoTrain, public PassengerTrain
{
protected:
    string wagonLayout;

public:
    void Print() override
    {
        Train::PrintSpecific();
        CargoTrain::PrintSpecific();
        PassengerTrain::PrintSpecific();
        MixedTrain::PrintSpecific();
    }

    void PrintSpecific()
    {
        cout << "Schema vagoanelor: " << wagonLayout << endl;
    }

    void Edit() override
    {
        Train::EditSpecific();
        CargoTrain::EditSpecific();
        PassengerTrain::EditSpecific();
        MixedTrain::EditSpecific();
    }

    void EditSpecific()
    {
        cout << "Schema vagoanelor: ";
        EditIfNotNull(wagonLayout);
    }

    int GetTrainMass() override final
    {
        return CargoTrain::GetSpecificMass() + PassengerTrain::GetSpecificMass() + Train::GetSpecificMass();
    }
};