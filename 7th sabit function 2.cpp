#include <iostream>
using namespace std;

void durasi(int totaldetik1, int totaldetik2) {
    int selisih = totaldetik2 - totaldetik1;
    if (selisih < 0) selisih = -selisih; 

    int hh = selisih / 3600;
    int mm = (selisih % 3600) / 60;
    int ss = (selisih % 3600) % 60;
    cout << "durasi antara waktu pertama dan kedua: " << hh << " jam " << mm << " menit " << ss << " detik" << endl;
}

int main() {
    struct waktu {
        int hh, hh2;
        int mm, mm2;
        int ss, ss2;
    };
    int totaldetik1, totaldetik2;   
    waktu w;
    cout << "waktu pertama" << endl;
    cout << "masukkan jam: ";
    cin >> w.hh;
    cout << "masukkan menit: ";
    cin >> w.mm; 
    cout << "masukkan detik: ";
    cin >> w.ss;
    cout << w.hh << ":" << w.mm << ":" << w.ss << endl;
    totaldetik1 = w.hh * 3600 + w.mm * 60 + w.ss;

    cout << "waktu kedua" << endl;
    cout << "masukkan jam: ";  
    cin >> w.hh2;
    cout << "masukkan menit: ";
    cin >> w.mm2;
    cout << "masukkan detik: ";
    cin >> w.ss2;
    cout << w.hh2 << ":" << w.mm2 << ":" << w.ss2 << endl;
    totaldetik2 = w.hh2 * 3600 + w.mm2 * 60 + w.ss2; 
    durasi(totaldetik1, totaldetik2);
    return 0;
}