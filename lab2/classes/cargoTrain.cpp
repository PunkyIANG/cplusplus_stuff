#pragma once
#include "./train.cpp"

class CargoTrain : public virtual Train
{
protected:
    int cargoWagonCount;
    int massPerCargoWagon;

public:
    virtual void Print() override
    {
        Train::PrintSpecific();
        CargoTrain::PrintSpecific();
    }

    void PrintSpecific()
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

    int GetTrainMass() override
    {
        return CargoTrain::GetSpecificMass() + Train::GetSpecificMass();
    }

    int GetSpecificMass()
    {
        return cargoWagonCount * massPerCargoWagon;
    }
};