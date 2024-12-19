#ifndef MANAGER_H_INCLUDED
#define MANAGER_H_INCLUDED

#include <iostream>
#include <string>
using namespace std;

#define firstM(LM) LM.firstM
#define lastM(LM) LM.lastM
#define infoM(M) M->infoM
#define nextM(M) M->nextM
#define prevM(M) M->prevM
#define firstProjek(M) M->firstProjek

#define infoP(P) P->infoP
#define nextP(P) P->nextP
#define prevP(P) P->prevP

struct Manager {
    string nama;
    int usia;
    string perusahaan;
};

struct Projek {
    string namaProjek;
    string deadline;
};

typedef struct ElemenManager *AdrManager;
typedef struct ElemenProyek *AdrProjek;

struct ElemenManager {
    AdrManager prevM;
    Manager infoM;
    AdrManager nextM;
    AdrProjek firstProjek;
};

struct ElemenProyek {
    AdrProjek prevP;
    Projek infoP;
    AdrProjek nextP;
};

struct ListManager {
    AdrManager firstM;
    AdrManager lastM;
};

void createListManager(ListManager &LM);
AdrManager createElemenManager(Manager infoM);
void insertManager(ListManager &LM, Manager infoM);
void showAllManagernProject(ListManager LM);
AdrManager searchManager(ListManager LM, string namaManager);

AdrProjek createElemenProjek(Projek infoP);
void addProjek(ListManager &LM, Projek infoP,AdrManager M);
void showAllProject(AdrManager M);


void deleteAllProject(AdrManager adrM);
void deleteManager(ListManager &LM, string namaManager);
void deleteSatuProject(ListManager &LM, string namaProject, string namaManager);
void countProyek(ListManager LM, string namaManager);
AdrProjek searchProject(AdrManager M, string namaProject);
void updateManager(ListManager &LM, string namaManager, string newNamaManager);
void updateDeadlineProject(ListManager &LM, string namaManager, string namaProject, string newDeadline);
void Menu();
#endif // MANAGER_H_INCLUDED
