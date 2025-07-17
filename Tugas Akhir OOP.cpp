#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
using namespace std;

class Pasien {
    public:
    string nama, nik;
    int umur;
    char jk;

    void inputBiodata() {
        cout << "Nama: ";
        getline(cin, nama);
        cout << "NIK: ";
        getline(cin, nik);
        cout << "Umur: ";
        cin >> umur;
        cin.ignore();
        cout << "Jenis Kelamin (L/P): ";
        cin >> jk;
        cin.ignore();
    }

    void tampilBiodata() {
        cout << "BIODATA PASIEN" << endl;
        cout << "Nama: " << nama << endl;
        cout << "NIK: " << nik << endl;
        cout << "Umur: " << umur << endl;
        cout << "Jenis Kelamin: " << (jk == 'L'|| jk == 'l' ? "Laki-laki" : "Perempuan") << endl;
    }
};

class RekamMedis {
    public:
    Pasien pasien;
    string diagnosis, tindakan;

    RekamMedis(Pasien p, string d, string t) {
        pasien = p;
        diagnosis = d;
        tindakan = t;
    }
    void tampilRekamMedis() {
        cout << "=============REKAM MEDIS============" << endl;
        pasien.tampilBiodata();
        cout << "Diagnosis: " << diagnosis << endl;
        cout << "Tindakan: " << tindakan << endl;
    }
    void simpankeCSV(ofstream& file) const {
        file << pasien.nama << "," << pasien.nik << "," << pasien.umur << "," << pasien.jk << "," << diagnosis << "," << tindakan << endl;
    }
};

class Database {
    private:
    vector<RekamMedis> dataRekamMedis;
    public:
    void tambahRekamMedis(RekamMedis rm) {
        dataRekamMedis.push_back(rm);
    }
    void simpankeCSV(string filename) {
        ofstream file(filename);
        if (!file.is_open()) {
            cout << "Gagal membuka file untuk menyimpan data." << endl;
            return;
        }
        file << "Nama,NIK,Umur,Jenis Kelamin,Diagnosis,Tindakan\n"; 
        for (const auto& rm : dataRekamMedis) {
            rm.simpankeCSV(file);
        }
        file.close();
        cout << "Data berhasil disimpan ke " << filename << endl;
    }
    void cariRekamMedis(string nama, string nik) {
        for (auto& rm : dataRekamMedis) {
            if (rm.pasien.nama == nama && rm.pasien.nik == nik) {
                rm.tampilRekamMedis();
                return;
            }
        }
        cout << "Data tidak ditemukan." << endl;
    }
    void hapusRekamMedis(string nama, string nik) {
        for (auto it = dataRekamMedis.begin(); it != dataRekamMedis.end(); ++it) {
            if (it->pasien.nama == nama && it->pasien.nik == nik) {
                dataRekamMedis.erase(it);
                cout << "Data berhasil dihapus." << endl;
                return;
            }
        }
        cout << "Data tidak ditemukan." << endl;
    }
    void bacaDariCSV(string filename) {
        ifstream file(filename);
        if (!file.is_open()) {
        return;
        }
        string line;
        getline(file, line); 
        while (getline(file, line)) {
            stringstream ss(line);
            string nama, nik, umurStr, jkStr, diagnosis, tindakan;
            getline(ss, nama, ',');
            getline(ss, nik, ',');
            getline(ss, umurStr, ',');
            getline(ss, jkStr, ',');
            getline(ss, diagnosis, ',');
            getline(ss, tindakan);

            Pasien p;
            p.nama = nama;
            p.nik = nik;
            p.umur = stoi(umurStr);
            p.jk = jkStr.empty() ? ' ' : jkStr[0];
            RekamMedis rm(p, diagnosis, tindakan);
            dataRekamMedis.push_back(rm);
        }
        file.close();
    }

};

class Diagnosis {
    public:
    static RekamMedis jalankan(Pasien pasien) {
        string diagnosis, tindakan;
        char jawab;
        
        cout << "Apakah terdapat ruam pada kulit? ";
        cin >> jawab;
        if (jawab == 'Y' || jawab == 'y') {
            cout << "Apakah terdapat muntah, penurunan kesadaran, dan atau nyeri kepala? ";
            cin >> jawab;
            if (jawab == 'Y' || jawab == 'y') {
                diagnosis = "Toxic Shock Syndrome";
                tindakan = "Segera bawa ke Instalasi Gawat Darurat (IGD) rumah sakit terdekat";
            } else if (jawab == 'T' || jawab == 't') {
                cout << "Apakah terdapat ruam berbentuk bintik atau berukuran kecil? ";
                cin >> jawab;
                if (jawab == 'Y' || jawab == 'y') {
                    diagnosis = "Demam Berdarah";
                    tindakan = "Berobat ke fasilitas kesehatan tingkat pertama (FKTP) terdekat.";
                } else if (jawab == 'T' || jawab == 't') {
                    cout << "Apakah terdapat ruam berisi cairan? ";
                    cin >> jawab;
                    if (jawab == 'Y' || jawab == 'y') {
                        cout << "Apakah ruam muncul setelah demam turun? ";
                        cin >> jawab;
                        if (jawab == 'Y' || jawab == 'y') {
                            cout << "Apakah ruam muncul di tangan, kaki, dan mulut? ";
                            cin >> jawab;
                            if (jawab == 'Y' || jawab == 'y') {
                                diagnosis = "Hand Foot and Mouth Disease (HFMD)";
                                tindakan = "Berobat ke fasilitas kesehatan tingkat pertama (FKTP) terdekat.";
                            } else if (jawab == 'T' || jawab == 't') {
                                diagnosis = "Cacar air atau Varisela";
                                tindakan = "Berobat ke fasilitas kesehatan tingkat pertama (FKTP) terdekat.";
                            }
                        } else if (jawab == 'T' || jawab == 't') {
                            cout << "Apakah ruam terasa terbakar, dan berada di sekitar mulut atau genital? ";
                            cin >> jawab;
                            if (jawab == 'Y' || jawab == 'y') {                    
                                diagnosis = "Herpes Simpleks Virus (HSV)";
                                tindakan = "Berobat ke fasilitas kesehatan tingkat pertama (FKTP) terdekat.";
                            } else if (jawab == 'T' || jawab == 't') {
                                diagnosis = "Kawasaki Disease";
                                tindakan = "Segera berobat ke dokter spesialis penyakit dalam";
                            }
                        }
                    } else if (jawab == 'T' || jawab == 't') {
                        cout << "Apakah ruam muncul setelah demam turun? ";
                        cin >> jawab;
                        if (jawab == 'Y' || jawab == 'y') {
                            cout << "Apakah kulit terasa kasar seperti pasir dan lidah seperti stoberi? ";
                            cin >> jawab;
                            if (jawab == 'Y' || jawab == 'y') {                   
                                diagnosis = "Scarlet Fever";
                                tindakan = "Berobat ke fasilitas kesehatan tingkat pertama (FKTP) terdekat.";
                            } else if (jawab == 'T' || jawab == 't') {                  
                                diagnosis = "Roseola Infantum";
                                tindakan = "Berobat ke fasilitas kesehatan tingkat pertama (FKTP) terdekat.";
                            }
                        } else if (jawab == 'T' || jawab == 't') {
                            cout << "Apakah terdapat 3C (Cough, Coryza, Conjunctivitis), batuk, pilek, dan mata merah? ";
                            cin >> jawab;
                            if (jawab == 'Y' || jawab == 'y') {                   
                                diagnosis = "Campak";
                                tindakan = "Berobat ke fasilitas kesehatan tingkat pertama (FKTP) terdekat.";
                            } else if (jawab == 'T' || jawab == 't') {
                                cout << "Apakah terdapat benjolan di belakang telinga? ";
                                cin >> jawab;
                                if (jawab == 'Y' || jawab == 'y') {
                                    diagnosis = "Rubella";
                                    tindakan = "Berobat ke fasilitas kesehatan tingkat pertama (FKTP) terdekat.";
                                } else if (jawab == 'T' || jawab == 't') {                        
                                    diagnosis = "Erythema Infectiosum";
                                    tindakan = "Berobat ke fasilitas kesehatan tingkat pertama (FKTP) terdekat.";
                                }
                            }
                        }
                    }
                }
            }
        } else if (jawab == 'T' || jawab == 't') {
            cout << "Apakah demam kurang dari seminggu? ";
            cin >> jawab;
            if (jawab == 'Y' || jawab == 'y') {
                cout << "Apakah demam terus menerus sepanjang hari? ";
                cin >> jawab;
                if (jawab == 'Y' || jawab == 'y') {
                    cout << "Apakah terdapat nyeri kepala, penurunan kesadaran dan atau kejang? ";
                    cin >> jawab;
                    if (jawab == 'Y' || jawab == 'y') {        
                        diagnosis = "Meningitis";
                        tindakan = "Segera bawa ke Instalasi Gawat Darurat (IGD) rumah sakit terdekat";
                    } else if (jawab == 'T' || jawab == 't') {
                        cout << "Apakah terdapat gangguan pendengaran, keseimbangan dan atau cairan dari lubang telinga? ";
                        cin >> jawab;
                        if (jawab == 'Y' || jawab == 'y') {    
                            diagnosis = "Otitis";
                            tindakan = "Berobat ke fasilitas kesehatan tingkat pertama (FKTP) terdekat.";
                            } else if (jawab == 'T' || jawab == 't') {
                                cout << "Apakah terdapat batuk, pilek, nyeri menelan, dan atau nyeri dahi dan pipi? ";
                                cin >> jawab;
                                if (jawab == 'Y' || jawab == 'y') {
                                    diagnosis = "Infeksi Saluran Pernapasan Atas (ISPA)";
                                    tindakan = "Berobat ke fasilitas kesehatan tingkat pertama (FKTP) terdekat.";
                                } else if (jawab == 'T' || jawab == 't') {
                                    cout << "Apakah terdapat diare, susah BAB, dan atau mual muntah? ";
                                    cin >> jawab;
                                    if (jawab == 'Y' || jawab == 'y') {
                                        cout << "Apakah pasien lemas, tidak mau minum, dan atau penurunan kesadaran? ";
                                        cin >> jawab;
                                        if (jawab == 'Y' || jawab == 'y') {
                                            diagnosis = "Infeksi saluran pencernaan, dengan dehidrasi berat";
                                            tindakan = "Segera bawa ke Instalasi Gawat Darurat (IGD) rumah sakit terdekat";
                                        } else if (jawab == 'T' || jawab == 't') {
                                            diagnosis = "Infeksi saluran pencernaan, tanpa dehidrasi berat";
                                            tindakan = "Berobat ke fasilitas kesehatan tingkat pertama (FKTP) terdekat.";
                                        }
                                    } else if (jawab == 'T' || jawab == 't') {
                                        cout << "Apakah BAK terasa nyeri, lebih sedikit, berdarah, dan atau terdapat nyeri perut bagian bawah? ";
                                        cin >> jawab;
                                        if (jawab == 'Y' || jawab == 'y') {
                                            diagnosis = "Infeksi Saluran Kemih (ISK)";
                                            tindakan = "Berobat ke fasilitas kesehatan tingkat pertama (FKTP) terdekat.";
                                        } else if (jawab == 'T' || jawab == 't') {
                                            cout << "Apakah terdapat nyeri kepala, nyeri belakang mata, nyeri otot, dan atau nyeri sendi? ";
                                            cin >> jawab;
                                            if (jawab == 'Y' || jawab == 'y') {
                                                cout << "Dari 1 - 10 skala nyeri di atas 6? ";
                                                cin >> jawab;
                                                if (jawab == 'Y' || jawab == 'y') {
                                                    diagnosis = "Chikungunya";
                                                    tindakan = "Berobat ke fasilitas kesehatan tingkat pertama (FKTP) terdekat.";
                                                } else if (jawab == 'T' || jawab == 't') {
                                                    cout << "Apakah terdapat nyeri perut, muntah terus menerus, sesak, dan atau pendarahan? ";
                                                    cin >> jawab;
                                                    if (jawab == 'Y' || jawab == 'y') {
                                                        diagnosis = "Demam Berdarah dengan tanda bahaya";
                                                        tindakan = "Segera bawa ke Instalasi Gawat Darurat (IGD) rumah sakit terdekat";
                                                    } else if (jawab == 'T' || jawab == 't') {
                                                        diagnosis = "Demam Berdarah tanpa tanda bahaya";
                                                        tindakan = "Berobat ke fasilitas kesehatan tingkat pertama (FKTP) terdekat.";
                                                    }
                                                }
                                            } else if (jawab == 'T' || jawab == 't') {
                                                cout << "Apakah terdapat kuning pada mata atau kulit? ";
                                                cin >> jawab;
                                                if (jawab == 'Y' || jawab == 'y') {
                                                    cout << "Pernah kontak dengan banjir, air yang terinfeksi, atau urine binatang? ";
                                                    cin >> jawab;
                                                    if (jawab == 'Y' || jawab == 'y') {
                                                        diagnosis = "Leptospirosis";
                                                        tindakan = "Segera bawa ke fasilitas kesehatan tingkat pertama (FKTP) terdekat.";
                                                    } else if (jawab == 'T' || jawab == 't') {
                                                        diagnosis = "Cari penyebab infeksi lain. Kemungkinan keganasan atau autoimun";
                                                        tindakan = "Segera berobat ke dokter spesialis penyakit dalam";
                                                    }
                                                } else if (jawab == 'T' || jawab == 't') {
                                                    diagnosis = "Kemungkinan infeksi virus";
                                                    tindakan = "Istirahat yang cukup, minum air putih yang cukup, dan makan makanan bergizi.";
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    } else if (jawab == 'T' || jawab == 't') {
                        cout << "Apakah ada riwayat traveling ke tempat endemik seperti wilayah timur Indonesia? ";
                        cin >> jawab;
                        if (jawab == 'Y' || jawab =='y') {
                            diagnosis = "Malaria";
                            tindakan = "Segera bawa ke fasilitas kesehatan tingkat pertama (FKTP) terdekat.";
                        } else if (jawab == 'T' || jawab == 't') {
                            diagnosis = "Pantau gejala lainnya. Kemungkinan demam tifoid minggu pertama";
                            tindakan = "Berobat ke fasilitas kesehatan tingkat pertama (FKTP) terdekat.";
                        }
                    }
                } else if (jawab == 'T' || jawab == 't') {
                    cout << "Apakah terdapat mual, muntah, nyeri perut, susah BAB, dan atau diare? ";
                    cin >> jawab;
                    if (jawab == 'Y' || jawab =='y') {
                        diagnosis = "Demam tifoid minggu kedua";
                        tindakan = "Berobat ke fasilitas kesehatan tingkat pertama (FKTP) terdekat.";
                    } else if (jawab == 'T' || jawab == 't') {
                        cout << "Apakah batuk lebih dari dua minggu dan atau kontak dengan orang yang memiliki riwayat Tuberculosis (TB)? ";
                        cin >> jawab;
                        if (jawab == 'Y' || jawab =='y') {
                            diagnosis = "Tuberculosis (TB)";
                            tindakan = "Berobat ke fasilitas kesehatan tingkat pertama (FKTP) terdekat.";
                        } else if (jawab == 'T' || jawab == 't') {
                            cout << "Apakah terdapat nyeri menelan? ";
                            cin >> jawab;
                            if (jawab == 'Y' || jawab =='y') {
                                diagnosis = "Tonsilitis";
                                tindakan = "Berobat ke fasilitas kesehatan tingkat pertama (FKTP) terdekat.";
                            } else if (jawab == 'T' || jawab == 't') {
                                cout << "Apakah terdapat cairan keluar dari telinga? ";
                                cin >> jawab;
                                if (jawab == 'Y' || jawab =='y') {           
                                    diagnosis = "Otitis media kronis";
                                    tindakan = "Berobat ke dokter spesialis THT (Telinga, Hidung, Tenggorokan).";
                                } else if (jawab == 'T' || jawab == 't') {
                                    cout << "Apakah terdapat gerakan tidak wajar (sydenham chorea), nyeri sendi, dan atau ruam pada kulit? ";
                                    cin >> jawab;
                                    if (jawab == 'Y' || jawab =='y') {                  
                                        diagnosis = "Demam rematik akut";
                                        tindakan = "Segera berobat ke dokter spesialis penyakit dalam";
                                    } else if (jawab == 'T' || jawab == 't') {
                                        cout << "Apakah terdapat penurunan berat badan drastis, lemas dan atau pucat? ";
                                        cin >> jawab;
                                        if (jawab == 'Y' || jawab =='y') {                          
                                            diagnosis = "Keganasan (kanker)";
                                            tindakan = "Segera berobat ke dokter spesialis penyakit dalam";
                                        } else if (jawab == 'T' || jawab == 't') {                            
                                            diagnosis = "Autoimun";
                                            tindakan = "Segera berobat ke dokter spesialis penyakit dalam";
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        return RekamMedis(pasien, diagnosis, tindakan);
    }
};

class Aplikasi {
private:
    Database db;
public:
    Aplikasi() {
        db.bacaDariCSV("rekam_medis.csv");
    }
    void menuUtama() {
        char pilihan;
        do {
            cout << "================MENU UTAMA================" << endl;
            cout << "1. Diagnosis Pasien " << endl;
            cout << "2. Cari Rekam Medis Pasien" << endl;
            cout << "3. Hapus Rekam Medis Pasien" << endl;
            cout << "----------------------------------------" << endl; 
            cout << "Pilih menu (1/2/3): ";
            cin >> pilihan;
            cin.ignore(); 

            if(pilihan == '1') {
                Pasien p;
                p.inputBiodata();
                cout << "----------------------------------------" << endl; 
                RekamMedis rm = Diagnosis::jalankan(p);
                rm.tampilRekamMedis();
                cout << "----------------------------------------" << endl; 
                db.tambahRekamMedis(rm);
                db.simpankeCSV("rekam_medis.csv");
            } else if (pilihan == '2') {
                string nama, nik;
                cout << "Nama: "; 
                getline(cin, nama);
                cout << "NIK: ";
                getline(cin, nik);
                cout << "----------------------------------------" << endl; 
                db.cariRekamMedis(nama, nik);
                cout << "----------------------------------------" << endl; 
            } else if (pilihan == '3') {
                string nama, nik;
                cout << "Nama: ";  
                getline(cin, nama);
                cout << "NIK: ";
                getline(cin, nik);
                db.hapusRekamMedis(nama, nik);
                db.simpankeCSV("rekam_medis.csv");
                cout << "----------------------------------------" << endl; 
            } else {
                cout << "Menu tidak valid" << endl;
                cout << "----------------------------------------" << endl; 
            }
            cout << "Kembali ke menu utama? (Y/T): ";
            cin >> pilihan;
        } while (pilihan == 'Y' || pilihan == 'y');
        cout << "----------------------------------------" << endl; 
        cout << "Terima kasih telah menggunakan aplikasi ini!" << endl;
    }
};

int main() {
    Aplikasi app;
    app.menuUtama();
    return 0;
}
