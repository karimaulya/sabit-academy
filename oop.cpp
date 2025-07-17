#include <iostream>
using namespace std;

class Animal {
    public:
        string jenis;
        string suara;
        void suaraAnimal() {
            cout << jenis << " bersuara: " << suara << endl;
        }
};

int main() {
    Animal kucing;
    kucing.jenis = "Kucing";
    kucing.suara = "Meong";
    kucing.suaraAnimal();

    Animal anjing;
    anjing.jenis = "Anjing";
    anjing.suara = "Guk guk";
    anjing.suaraAnimal();

    cout << "Jenis: " << kucing.jenis << ", Suara: " << kucing.suara << endl;
    cout << "Jenis: " << anjing.jenis << ", Suara: " << anjing.suara << endl;

    return 0;
}