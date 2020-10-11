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
        cout << "Nr. vagoane cargo (prev: " << cargoWagonCount << "): ";
        EditIfNotNull(cargoWagonCount);
        cout << "Masa unui vagon cargo (prev: " << massPerCargoWagon << "): ";
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

    CargoTrain()
    {
        cargoWagonCount = 3;
        massPerCargoWagon = 2000;
        cout << "Created cargo train" << endl;
    }
};