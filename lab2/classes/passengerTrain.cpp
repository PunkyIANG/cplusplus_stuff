#pragma once
#include "./train.cpp"

class PassengerTrain : public virtual Train
{
private:
    int massPerPassenger = 65;

protected:
    int passengerWagonCount;
    int passengersPerWagon;

public:
    virtual void Print() override
    {
        Train::PrintSpecific();
        PassengerTrain::PrintSpecific();
    }

    void PrintSpecific()
    {
        cout << "Nr. vagoane pentru pasageri: " << passengerWagonCount << endl;
        cout << "Nr. pasageri/vagon: " << passengersPerWagon << endl;
    }

    virtual void Edit() override
    {
        Train::EditSpecific();
        PassengerTrain::EditSpecific();
    }

    void EditSpecific()
    {
        cout << "Nr. vagoane pentru pasageri: ";
        EditIfNotNull(passengerWagonCount);
        cout << "Nr. pasageri/vagon: ";
        EditIfNotNull(passengersPerWagon);
    }

    int GetTrainMass() override
    {
        return PassengerTrain::GetSpecificMass() + Train::GetSpecificMass();
    }

    int GetSpecificMass()
    {
        return passengerWagonCount * passengersPerWagon * massPerPassenger;
    }

    PassengerTrain() = default;
};