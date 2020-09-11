#include <string>
#include <iostream>

using namespace std;

class Student {
    private:
        int id;
        string name;
    
    public:
        Student() {
            id = 0;
            name = "---";
        };

        Student(int _id, string _name) {
            id = _id;
            name = _name;
        }

        ~Student();
        void Afisare();
};

Student::~Student(){
    cout << "Apel destructor clasa student";
}

void Student::Afisare(){
    cout << "(" << id << ", " << name << ")" << endl;
}

int main() {
    Student s;
    s.Afisare();

    return 0;
}