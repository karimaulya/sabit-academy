#include <iostream>
using namespace std;

int main () {
    int detik, menit, jam, parkir, totaldetik;
    string kendaraan;

    while(true) {

        cout << "masukkan jenis kendaraan (stop utk berenti): ";
        cin >> kendaraan;

        if (kendaraan == "stop") {
            break;
        }

        cout << "masukkan waktu detik: ";
        cin >> totaldetik;
    
        jam = totaldetik/3600;
        menit = (totaldetik%3600)/60;
        detik = (totaldetik%3600)%60;
    
        if (kendaraan == "mobil") {
            if (totaldetik <= 3600) {
                parkir = 1000;
            } else {
                parkir = 1000 + (jam*3000);
            
            }
    
        } else if (kendaraan == "motor") {
            if (totaldetik <= 3600) {
                parkir = 1000;
            } else {
                parkir = 1000 + (jam*2000);
            
            }

        } else if (kendaraan == "stop") {
            break;
        }

        cout << "jenis kendaraan: " << kendaraan << endl;
        cout << "waktu parkir: " << jam << " jam " << menit << " menit " << detik << " detik" << endl;
        cout << "total biaya parkir: " << parkir << endl;
    }

    return 0;
}