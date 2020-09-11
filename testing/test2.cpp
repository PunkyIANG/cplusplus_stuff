#include <iostream>

using namespace std;

int main() {
    int arr[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    int n = 10;

    for (int i = 0; i < n; i++)
        if (arr[i] == 9) {
            for (int j = 1; j < n - 1; j++) {
                arr[j] = arr[j + 1];
            }
            n--;
        }


    return 0;
}