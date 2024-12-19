#include <iostream>
#include "manager.h"

using namespace std;

int main() {
    ListManager LM;
    Manager InfoM;
    Projek infoP;
    int n, choose;
    string namaManager, namaProject, newDeadline, newNama;

    createListManager(LM);

    char pilihan = 'y';
    while (pilihan != 'n') {
        Menu();
        cout << "Masukan Pilihan Anda: ";
        cin >> choose;
        cin.ignore(); // To clear the newline character from the input buffer
        cout << endl;

        if (choose == 1) {
            cout << "Masukan banyak manager yang hendak dimasukan: ";
            cin >> n;
            cin.ignore();

            for (int i = 1; i <= n; i++) {
                cout << "Masukan nama manager: ";
                getline(cin, InfoM.nama);

                cout << "Masukan usia manager: ";
                cin >> InfoM.usia;
                cin.ignore();

                cout << "Masukan perusahaan asal manager: ";
                getline(cin, InfoM.perusahaan);

                insertManager(LM, InfoM);
                cout << endl;
            }
            cout << "Berhasil Ditambahkan." << endl;

        } else if (choose == 2) {
            showAllManagernProject(LM);

        } else if (choose == 3) {
            cout << "Masukan nama Manager: ";
            getline(cin, namaManager);
            deleteManager(LM, namaManager);

        } else if (choose == 4) {
            cout << "Masukan nama Manager: ";
            getline(cin, namaManager);
            AdrManager M = searchManager(LM, namaManager);
            if (M != NULL) {
                cout << "Manager Ditemukan: " << namaManager << endl;
            } else {
                cout << "Manager Tidak Ditemukan." << endl;
            }

        } else if (choose == 5) {
            cout << "Masukan nama Manager: ";
            getline(cin, namaManager);
            AdrManager M = searchManager(LM, namaManager);
            if (M == NULL) {
                cout << "Manager Tidak Ada: " << namaManager << endl;
            } else {
                cout << "Masukan banyak project yang hendak dimasukan: ";
                cin >> n;
                cin.ignore();
                for (int i = 1; i <= n; i++) {
                    cout << "Masukan nama project: ";
                    getline(cin, infoP.namaProjek);

                    cout << "Masukan deadline project: ";
                    getline(cin, infoP.deadline);

                    addProjek(LM, infoP, M);
                }
                cout << "Project Berhasil Ditambahkan." << endl;
            }

        } else if (choose == 6) {
            cout << "Masukan nama Manager: ";
            getline(cin, namaManager);
            cout << "Masukan nama Project: ";
            getline(cin, namaProject);
            cout << "Masukan Deadline Baru: ";
            getline(cin, newDeadline);
            updateDeadlineProject(LM, namaManager, namaProject, newDeadline);

        } else if (choose == 7) {
            cout << "Masukan nama Manager Lama: ";
            getline(cin, namaManager);
            cout << "Masukan nama Manager Baru: ";
            getline(cin, newNama);
            updateManager(LM, namaManager, newNama);

        } else if (choose == 8) {
            cout << "Masukan nama Manager: ";
            getline(cin, namaManager);
            cout << "Masukan nama Project: ";
            getline(cin, namaProject);
            AdrManager M = searchManager(LM, namaManager);
            if (M == NULL) {
                cout << "Manager Tidak Ditemukan." << endl;
            } else {
                AdrProjek P = searchProject(M, namaProject);
                if (P == NULL) {
                    cout << "Project Tidak Ditemukan." << endl;
                } else {
                    cout << "Project " << namaProject << " ditemukan." << endl;
                }
            }

        } else if (choose == 9) {
            cout << "Masukan nama Manager: ";
            getline(cin, namaManager);
            cout << "Masukan nama Project: ";
            getline(cin, namaProject);
            deleteSatuProject(LM, namaProject, namaManager);

        } else if (choose == 10) {
            cout << "Masukan nama Manager: ";
            getline(cin, namaManager);
            countProyek(LM, namaManager);

        } else {
            cout << "Pilihan tidak valid!" << endl;
        }

        cout << "\nApakah Hendak Kembali Ke Menu Utama (y/n)? ";
        cin >> pilihan;
        cin.ignore();
        cout << endl;
    }

    return 0;
}
