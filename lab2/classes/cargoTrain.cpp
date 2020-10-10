#pragma once
#include "./train.cpp"

class CargoTrain : public virtual Train
{
protected:
    int cargoWagonCount;
    int massPerCargoWagon;

public:
    virtual void Print() const override
    {
        Train::PrintSpecific();
        CargoTrain::PrintSpecific();
        cout << endl;
    }

    void PrintSpecific() const
    {
        cout << "Nr. vagoane cargo: " << cargoWagonCount << endl;
        cout << "Masa unui vagon cargo: " << massPerCargoWagon << endl;
    }

    virtual void Edit() override
    {
        Train::EditSpecific();
        CargoTrain::EditSpecific();
    }

    void EditSpecific()
    {
        cout << "Nr. vagoane cargo: ";
        EditIfNotNull(cargoWagonCount);
        cout << "Masa unui vagon cargo: ";
        EditIfNotNull(massPerCargoWagon);
    }

    int GetTrainMass() const override
    {
        return CargoTrain::GetSpecificMass() + Train::GetSpecificMass();
    }

    int GetSpecificMass() const
    {
        return cargoWagonCount * massPerCargoWagon;
    }
};