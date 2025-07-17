#include <iostream>
using namespace std;

class Parkiran {
    public:
    string kendaraan;
    int totaldetik;
    int jam, menit, detik, parkir;

    void hitungParkir() {
        jam = totaldetik / 3600;
        menit = (totaldetik % 3600) / 60;
        detik = (totaldetik % 3600) % 60;

        if (kendaraan == "mobil") {
            if (totaldetik <= 3600) {
                parkir = 1000;
            } else {
                parkir = 1000 + (jam * 3000);
            }
        } else if (kendaraan == "motor") {
            if (totaldetik <= 3600) {
                parkir = 1000;
            } else {
                parkir = 1000 + (jam * 2000);
            }
        } else {
            cout << "Kendaraan tidak dikenal" << endl;
            parkir = 0;
        }
    }
};

int main() {
    Parkiran jkendaraan;
    while (true) {
        cout << "Masukkan jenis kendaraan (mobil/motor/stop utk berenti):";
        cin >> jkendaraan.kendaraan;
        if (jkendaraan.kendaraan == "stop") {
            break;
        }
        cout << "Masukkan waktu parkir dalam detik: ";
        cin >> jkendaraan.totaldetik;
        jkendaraan.hitungParkir();
        cout << "Jenis kendaraan: " << jkendaraan.kendaraan << endl;
        cout << "Waktu parkir: " << jkendaraan.jam << " jam " << jkendaraan.menit << " menit " << jkendaraan.detik << " detik" << endl;
        cout << "Total biaya parkir: " << jkendaraan.parkir << endl;
    }
    return 0;
}

