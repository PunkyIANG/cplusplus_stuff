#include "./classes/mixedTrain.cpp"
#include "./functions.cpp"
#include "./classes/smartEdit.cpp"
#include <vector>
using namespace std;

int main() {
    Train *temp = new Train();
    temp->Edit();
    temp->Print();

    SwitchTrainType(temp);

    temp->Edit();
    temp->Print();
}