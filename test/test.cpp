#include <iostream>
#include <string.h>

using namespace std;

int main()
{
    char den[40] = "stuff";
    char other[40];
    strcpy(other, den);
    cout << other;
}

class Latura
{
private:
    double lungime_latura;

public:
    Latura()
    {
        lungime_latura = 8.5;
    }
};

class Triunghi : public Latura
{
private:
    double Unghi_Maxim;

public:
    Triunghi()
    {
        Unghi_Maxim = 120;
    }
};

class Prizma_triunghiulara : public Triunghi
{
private:
    double Inaltime;

public:
    Prizma_triunghiulara()
    {
        Inaltime = 10;
    }
};

class Piramida_triunghiulara : public Triunghi
{
private:
    double Inaltime;

public:
    Piramida_triunghiulara()
    {
        Inaltime = 7.5;
    }
};
