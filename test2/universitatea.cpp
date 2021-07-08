#include <iostream>
#include <string>
using namespace std;

class Universitate {
    protected:
        string denumirea;
        string adresa;
    private:
        int anulFondarii;
        int nrFacultati;
    public:
        Universitate() {
            denumirea = "---";
            adresa = "---";
            anulFondarii = -1;
            nrFacultati = -1;
        }

        Universitate(string _denumirea, string _adresa, int _anulFondarii, int _nrFacultati) {
            denumirea = _denumirea;
            adresa = _adresa;
            anulFondarii = _anulFondarii;
            nrFacultati = _nrFacultati;
        }

        void Edit() {
            cout << "Dati denumirea: ";
            cin >> denumirea;
            cout << "Dati adresa: ";
            cin >> adresa;
            cout << "Dati anul fondarii: ";
            cin >> anulFondarii;
            cout << "Dati nr de facultati: ";
            cin >> nrFacultati;
        }

        void Print() {
            cout << "Denumirea: " << denumirea << endl;
            cout << "Adresa: " << adresa << endl;
            cout << "Anul fondarii: " << anulFondarii << endl;
            cout << "Nr de facultati: " << nrFacultati << endl;
        }
};

class USM : public Universitate {
    private:
        int nrStudenti;
        int nrProfesori;

    public:
        USM() : Universitate() {
            nrStudenti = -1;
            nrProfesori = -1;
        }

        USM(string _denumirea, string _adresa, int _anulFondarii, int _nrFacultati, int _nrStudenti, int _nrProfesori) :
            Universitate(_denumirea, _adresa, _anulFondarii, _nrFacultati) {
            nrStudenti = _nrStudenti;
            nrProfesori = _nrProfesori;
        }

        void Edit() {
            Universitate::Edit();
            cout << "Dati nr de studenti: ";
            cin >> nrStudenti;
            cout << "Dati nr de profesori: ";
            cin >> nrProfesori;
        }

        void Print() {
            Universitate::Print();
            cout << "Nr de studenti: " << nrStudenti << endl;
            cout << "Nr de profesori: " << nrProfesori << endl;
        }
};

class UTM : public Universitate {
    private:
        int nrStudenti;
        int nrProfesori;

    public:
        UTM() : Universitate() {
            nrStudenti = -1;
            nrProfesori = -1;
        }

        UTM(string _denumirea, string _adresa, int _anulFondarii, int _nrFacultati, int _nrStudenti, int _nrProfesori) : 
            Universitate(_denumirea, _adresa, _anulFondarii, _nrFacultati) {
            nrStudenti = _nrStudenti;
            nrProfesori = _nrProfesori;
        }

        void Edit() {
            Universitate::Edit();
            cout << "Dati nr de studenti: ";
            cin >> nrStudenti;
            cout << "Dati nr de profesori: ";
            cin >> nrProfesori;
        }

        void Print() {
            Universitate::Print();
            cout << "Nr de studenti: " << nrStudenti << endl;
            cout << "Nr de profesori: " << nrProfesori << endl;
        }
};

int main() {
    Universitate universitate1 = Universitate();
    Universitate universitate2 = Universitate("denumire", "adresa", 1980, 10);

    USM usm1 = USM();
    USM usm2 = USM("USM", "adresa_usm", 1946, 10, 1000, 100);

    UTM utm1 = UTM();
    UTM utm2 = UTM("UTM", "strada Stefan cel Mare ...", 1964, 10, 1000, 100);

    universitate1.Print();
    universitate2.Print();

    usm1.Print();
    usm2.Print();

    utm1.Print();
    utm2.Print();
}