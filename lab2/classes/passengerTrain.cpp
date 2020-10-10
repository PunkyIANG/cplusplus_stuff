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
    virtual void Print() const override
    {
        Train::PrintSpecific();
        PassengerTrain::PrintSpecific();
        cout << endl;
    }

    void PrintSpecific() const
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

    int GetTrainMass() const override
    {
        return PassengerTrain::GetSpecificMass() + Train::GetSpecificMass();
    }

    int GetSpecificMass() const
    {
        return passengerWagonCount * passengersPerWagon * massPerPassenger;
    }

    PassengerTrain() = default;
};