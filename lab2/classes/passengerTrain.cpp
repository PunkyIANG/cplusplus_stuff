#pragma once
#include "./train.cpp"

class PassengerTrain : public virtual Train
{
private:
    int massPerPassenger = 70;

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
        cout << "Nr. vagoane pentru pasageri (prev: " << passengerWagonCount << "): ";
        EditIfNotNull(passengerWagonCount);
        cout << "Nr. pasageri/vagon (prev: " << passengersPerWagon << "): ";
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

    PassengerTrain()
    {
        passengerWagonCount = 3;
        passengersPerWagon = 20;
        cout << "Created passenger train" << endl;
    }
};