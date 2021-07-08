#include <iostream>

using namespace std;

class Patrat{
    private:
        float a, b, c;

    public:
        Patrat() : a(0), b(0), c(0) {   }

        Patrat(float _a, float _b, float _c) : a(_a), b(_b), c(_c) {   }

        Patrat(const Patrat &patrat) : a(patrat.a), b(patrat.b), c(patrat.c) {   }

        void Edit() {
            cout << "Dati a, b, c: ";
            cin >> a >> b >> c;
        }

        void Print() {
            cout << a << "x^2 + (" << b << "x) + (" << c << ")" << endl;
        }

        Patrat operator+= (Patrat patrat) {
            a += patrat.a;
            b += patrat.b;
            c += patrat.c;

            return *this;
        }

        Patrat operator-- () {  //--patrat
            a--;
            b--;
            c--;
        }

        Patrat operator-- (int) {   //patrat--
            Patrat temp(*this);
            operator--();
            return temp;
        }

        Patrat operator= (const Patrat &patrat) {
            a = patrat.a;
            b = patrat.b;
            c = patrat.c;
        }

        friend bool operator==(Patrat patrat1, Patrat patrat2);
        friend Patrat operator/(Patrat patrat, float num);
        friend float operator/(float num, Patrat patrat);
};

bool operator==(Patrat patrat1, Patrat patrat2) {
    if (patrat1.a == patrat2.a && patrat1.b == patrat2.b && patrat1.c == patrat2.c) {
        return true;
    }

    return false;
}

Patrat operator/(Patrat patrat, float num) {
    Patrat result = patrat;
    result.a /= num;
    result.b /= num;
    result.c /= num;

    return result;
}

float operator/(float num, Patrat patrat) {
    return num / patrat.a;
}
