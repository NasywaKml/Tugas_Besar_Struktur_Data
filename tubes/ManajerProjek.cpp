#include "manager.h"
#include <iostream>

using namespace std;

void createListManager(ListManager &LM) {
/*I.S. masukan berupa List kosong
F.S. Berupa List yang telah memilki First dan Last*/
    firstM(LM) = NULL;
    lastM(LM) = NULL;
}

AdrManager createElemenManager(Manager infoM) {
/*I.S. Masukan berupa tipe bentukan struct manager
F.S. Keluaran berupa address dari elemen yang telah dibuat*/
    AdrManager newElemen = new ElemenManager;
    infoM(newElemen) = infoM;
    nextM(newElemen) = NULL;
    prevM(newElemen) = NULL;
    firstProjek(newElemen) = NULL;
    return newElemen;
}

void insertManager(ListManager &LM, Manager infoM) {
/*I.S. Masukan Berupa List yang mungkin masih kosong dan satu tipe bentukan Manager
F.S. Keluaran Berupa List manager yang telah dimasukan elemenlist*/
    AdrManager adrM = createElemenManager(infoM);
    if (firstM(LM) == NULL) {
        firstM(LM) = adrM;
        lastM(LM) = adrM;
    } else {
        nextM(lastM(LM)) = adrM;
        prevM(adrM) = lastM(LM);
        lastM(LM) = adrM;
    }
}

void showAllManagernProject(ListManager LM) {
/*I.S. Masukan berupa sebuah list yang mungkin kosong
F.S. Menampilkan semua elemen list dari parent/ manager dan list child/project*/
    AdrManager p = firstM(LM);
    int i = 0;
    if (p == NULL) {
        cout << "Manager Tidak Ada." << endl;
        return;
    }
    while (p != NULL) {
        i++;
        cout << i << ". Nama Manager: " << infoM(p).nama
             << " , Usia: " << infoM(p).usia
             << " , Perusahaan: " << infoM(p).perusahaan << endl;
        cout << "  Projects: " << endl;
        showAllProject(p);
        cout << "------------------" << endl;
        p = nextM(p);
    }
}



AdrManager searchManager(ListManager LM, string namaManager) {
/*I.S. Masukan berupa sebuah list yang mungkin kosong dan sebuah string nama manager yang hendak di cari addressnya
F.S. Keluaran berupa mengembalikan address dari nama manager yang dicari di dalam list*/
    AdrManager adr = firstM(LM);
    while (adr != NULL) {
        if (infoM(adr).nama == namaManager) {
            return adr;
        }
        adr = nextM(adr);
    }
    return NULL;
}

AdrProjek createElemenProjek(Projek infoP){
/*I.S. Masukan berupa sebuah tipe bentukan struct Project
F.S. Keluaran berupa address dari elemen yang berisi tipe bentukan dari masukan*/
    AdrProjek newProjek = new ElemenProyek;
    infoP(newProjek) = infoP;
    nextP(newProjek) = NULL;
    prevP(newProjek) = NULL;
    return newProjek;
}

void addProjek(ListManager &LM, Projek infoP,AdrManager M) {
/*I.S. Masukan berupa sebuah list yang mungkin kosong, sebuah tipe bentukan Project, dan address dari elemen manager
F.S.Keluaran berupa Elemen Manager telah memilki child project yang berisi dari tipe bentukan Project*/
    AdrProjek P = createElemenProjek(infoP);

    if (firstProjek(M) == NULL) {
        firstProjek(M) = P;
    } else {
        nextP(P) = firstProjek(M);
        prevP(firstProjek(M)) = P;
        firstProjek(M) = P;
    }
}

void showAllProject(AdrManager M) {
/*I.S. Masukan berupa alamat elemen manager yang mungkin tidak memiliki child/ project
F.S. Keluaran berupa menampilkan semua project yang ada di elemen manager*/
    AdrProjek p = firstProjek(M);
    if (p == NULL) {
        cout << "  Tidak ada Project." << endl;
        return;
    }
    while (p != NULL) {
        cout << "    - Nama Project: " << infoP(p).namaProjek
             << ", Deadline: " << infoP(p).deadline << endl;
        p = nextP(p);
    }
}

void deleteAllProject(AdrManager adrM) {
/*I.S Masukan berupa sebuah alamat elemen manager (parent)
F.S Keluaran berupa project (child) dari alamat managaer telah terhapus semua*/
    AdrProjek q = firstProjek(adrM);
    while (q != NULL) {
        AdrProjek temp = q;
        q = nextP(q);
        delete temp;
    }
    firstProjek(adrM) = NULL;
}

void deleteManager(ListManager &LM, string namaManager) {
/*I.S Masukan berupa List (parent) yang mungkin kosong dan sebuah string dari nama manager
F.S. Keluaran berupa Elemen yang memiliki nama manager yang sama terhapus dari list beserta project (child) nya*/
    AdrManager M = searchManager(LM, namaManager);
    if (M == NULL) {
        cout << "Manager Tidak Ditemukan." << endl;
        return;
    } else{
        deleteAllProject(M);

        if (M == firstM(LM)) {
            firstM(LM) = nextM(M);
            if (firstM(LM)) {
                prevM(firstM(LM)) = NULL;
            }
        } else if (M == lastM(LM)) {
            lastM(LM) = prevM(M);
            nextM(lastM(LM)) = NULL;
        } else {
            nextM(prevM(M)) = nextM(M);
            prevM(nextM(M)) = prevM(M);
        }
        delete M;
        cout<<"Manager Berhasil Dihapus."<<endl;
    }

}

void deleteSatuProject(ListManager &LM, string namaProject, string namaManager) {

    AdrManager Manager = searchManager(LM, namaManager);
    if (Manager == NULL) {
        cout << "Manager Tidak Ditemukan." << endl;
        return;
    }
    AdrProjek P = searchProject(Manager, namaProject);
    if (P == NULL) {
        cout << "Project Tidak Ditemukan." << endl;
        return;
    }
    if (P == firstProjek(Manager)) {
        firstProjek(Manager) = nextP(P);
        if (firstProjek(Manager)) {
            prevP(firstProjek(Manager)) = NULL;
        }
    } else if (nextP(P) == NULL) {
        nextP(prevP(P)) = NULL;
    } else {
        nextP(prevP(P)) = nextP(P);
        prevP(nextP(P)) = prevP(P);
    }
    delete P;
    cout<<"Project Berhasi Dihapus"<<endl;
}

void countProyek(ListManager LM, string namaManager) {
    int i = 0;
    AdrManager M = searchManager(LM, namaManager);
    if (M == NULL) {
        cout << "Manager Tidak Ditemukan." << endl;
        return;
    }
    AdrProjek P = firstProjek(M);
    while (P != NULL) {
        i++;
        P = nextP(P);
    }
    cout << "Manager " << namaManager << " mengerjakan proyek sebanyak: " << i << endl;
}

AdrProjek searchProject(AdrManager M, string namaProject) {
    AdrProjek P = firstProjek(M);
    while (P != NULL) {
        if (infoP(P).namaProjek == namaProject) {
            return P;
        }
        P = nextP(P);
    }
    return NULL;
}

void updateManager(ListManager &LM, string namaManager, string newNamaManager) {
    AdrManager M = searchManager(LM, namaManager);
    if (M != NULL) {
        infoM(M).nama = newNamaManager;
        cout<<"Nama Manager Berhasil diubah"<<endl;
    } else {
        cout << "Manager Tidak Ditemukan." << endl;
    }
}

void updateDeadlineProject(ListManager &LM, string namaManager, string namaProject, string newDeadline) {
    AdrManager M = searchManager(LM, namaManager);
    if (M == NULL) {
        cout << "Manager Tidak Ditemukan." << endl;
        return;
    }
    AdrProjek P = searchProject(M, namaProject);
    if (P == NULL) {
        cout << "Project Tidak Ditemukan." << endl;
        return;
    }
    infoP(P).deadline = newDeadline;
    cout<<"Deadline berasil diubah"<<endl;
}

void Menu(){
    cout<<"------------------------Menu----------------------"<<endl;
    cout<<"1. Insert Data Manager (parent)"<<endl;
    cout<<"2. Show All Data Manager (parent)"<<endl;
    cout<<"3. Hapus Data Manager (parent) dan Project (child)"<<endl;
    cout<<"4. Search Data Manager (parent)"<<endl;
    cout<<"5. Insert Data Project (child)"<<endl;
    cout<<"6. Update Deadline Project (ubah data child)"<<endl;
    cout<<"7. Update Nama Manager (ubah data parent)"<<endl;
    cout<<"8. Search Project dari Nama Manager"<<endl;
    cout<<"9. Hapus data Project dari Nama Manager"<<endl;
    cout<<"10. Hitung Total Project Manager"<<endl;
    cout<<"---------------------------------------------------"<<endl;
}
