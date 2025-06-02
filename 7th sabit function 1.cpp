#include <iostream>
using namespace std;

void jumlahGenapPertama(int N) {
    int jumlah = 0;
    int count = 0;
    int i = 0;
    cout << "Bilangan genap pertama: ";
    while (count < N) {
        if (i % 2 == 0) {
            cout << i << " ";
            jumlah += i;
            count++;
        }
        i++;
    }
    cout << endl;
    cout << "Jumlah " << N << " bilangan genap pertama: " << jumlah << endl;
}

int main() {
    int N;
    cout << "Masukkan banyaknya bilangan genap pertama: ";
    cin >> N;
    jumlahGenapPertama(N);
    return 0;
}