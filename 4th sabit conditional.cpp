#include <iostream>
using namespace std;

int main () {
    int detik, menit, jam, parkir, totaldetik;

        cout << "masukkan waktu detik: ";
        cin >> totaldetik;
    
        jam = totaldetik/3600;
        menit = (totaldetik%3600)/60;
        detik = (totaldetik%3600)%60;
    
        if (totaldetik <= 3600) {
            parkir = 1000;
        } else {
            parkir = 1000 + (jam*2000);
        }

        cout << "waktu parkir: " << jam << " jam " << menit << " menit " << detik << " detik" << endl;
        cout << "total biaya parkir: " << parkir << endl;
        return 0;
    }