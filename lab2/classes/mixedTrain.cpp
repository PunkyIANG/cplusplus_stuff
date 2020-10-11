#pragma once
#include "./train.cpp"
#include "./cargoTrain.cpp"
#include "./passengerTrain.cpp"

class MixedTrain : public CargoTrain, public PassengerTrain
{
protected:
    string wagonLayout;

public:
    void Print() const override final
    {
        Train::PrintSpecific();
        CargoTrain::PrintSpecific();
        PassengerTrain::PrintSpecific();
        MixedTrain::PrintSpecific();
        cout << endl;
    }

    void PrintSpecific() const
    {
        cout << "Schema vagoanelor: " << wagonLayout << endl;
    }

    void Edit() override final
    {
        Train::EditSpecific();
        CargoTrain::EditSpecific();
        PassengerTrain::EditSpecific();
        MixedTrain::EditSpecific();
    }

    void EditSpecific()
    {
        cout << "Schema vagoanelor (prev: " << wagonLayout << "): ";
        EditIfNotNull(wagonLayout);
    }

    int GetTrainMass() const override final
    {
        return CargoTrain::GetSpecificMass() + PassengerTrain::GetSpecificMass() + Train::GetSpecificMass();
    }

    MixedTrain()
    {
        wagonLayout = "pppccc";
        cout << "Created mixed train" << endl;
    }
};