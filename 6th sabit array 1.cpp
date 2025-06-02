#include <iostream>
using namespace std;

int main() {
    int A[5] = {0, 1, 2, 3, 4};
    bool sama = true;

    for (int i = 0; i < 5; i++) {
        if (A[i] != A[0]) {
            sama = false;
            break;
        }
    }

    if(sama) {
        cout << "semua elemen sama" << endl;
    } else {
        cout << "ada elemen yang berbeda" << endl;
    }

    return 0;
}