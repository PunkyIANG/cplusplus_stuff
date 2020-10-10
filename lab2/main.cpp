#include "./classes/mixedTrain.cpp"
#include "./functions.cpp"
#include <vector>
using namespace std;

enum SubProg
{
    _Stop = '0',
    _EditAll = '1',
    _PrintAll = '2',
    _SortByMass = '3',
    _PrintAbovePrice = '4',
    _AddNewElement = '5',
    _RemoveElemWithDestination = '6',
    _NoAction = '7'
};

int main()
{
    vector<Train *> trains;

    Train *testSample = new Train();
    testSample->Edit();
    testSample->Print();

    SwitchTrainType(testSample);

    testSample->Print();
}