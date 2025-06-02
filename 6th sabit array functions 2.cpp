#include <iostream>
using namespace std;

int main() {
    int m = 3, n = 4;
    int maks, min, cari;
    bool found = false;
    int A[3][4] = {
        {5, 2, 7, 1},
        {8, 3, 6, 4},
        {9, 0, 2, 5}
    };
    maks = A[0][0];
    min = A[0][0];
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (A[i][j] > maks) maks = A[i][j];
            if (A[i][j] < min) min = A[i][j];
        }
    }
    cout << "Elemen terbesar: " << maks << endl;
    cout << "Elemen terkecil: " << min << endl;

    cout << "Masukkan elemen yang dicari: ";
    cin >> cari;

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (A[i][j] == cari) {
                found = true;
                break;
            }
        }
        if (found) break;
    }
    if (found) {
        cout << "Nilai " << cari << " ditemukan di matriks." << endl;
    } else {
        cout << "Nilai " << cari << " tidak ditemukan di matriks." << endl;
    }

    return 0;
}
