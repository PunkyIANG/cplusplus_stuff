#include <string>
#include <iostream>

using namespace std;

struct Stud {
    int id;
    string name;
    float med;
};

int main() {
    struct Stud s,st[10];
    cout << s.id << " " << s.name << " " << s.med << endl;
    cout << st[0].id << " " << st[0].name << " " << st[0].med << endl;
}