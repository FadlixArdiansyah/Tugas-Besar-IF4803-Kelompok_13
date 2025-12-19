#include "main.h"
#include "Komposer.h"
#include "Musik.h"
#include <iostream>

using namespace std;



void menuAdmin(ListParent &L){
    int option=-99;
    while (option != 0) {
        system("cls");
        cout << "============ Menu Admin ============ " << endl;
        cout << "|| 1. Kelola Komposer (Parent)  ||" << endl;
        cout << "|| 2. Kelola Musik (Child)      ||" << endl;
        cout << "|| 3. Relasi Musik ke Komposer  ||" << endl;
        cout << "|| 0. Kembali ke Menu Utama     ||" << endl;
        cout << "================================== " << endl;
        cout << "Pilih Opsi : ";
        cin >> option;

        switch(option) {
           case 1:
               menuParent(L);
               break;
           case 2:
               menuChild(L);
               break;
           case 3:
           {
               system("cls");
               cout << "--- RELASI MUSIK KE KOMPOSER ---" << endl;
               cout << "List Komposer:" << endl;
               viewParent(L);

               cout << "\nMasukkan ID Komposer Target: ";
               string idKomposerTarget;
               cin >> idKomposerTarget;

               Musik M;
               cout << "\n--- Input Data Musik Baru ---" << endl;
               cout << "ID Musik : ";
               cin >> M.ID;


               cout << "Judul Musik : ";
               cin >> M.Judul;

               cout << "Tahun Rilis : ";
               cin >> M.tahunRilis;

               addressC C = createElementChild(M);


               insertNewChildToParent(L, idKomposerTarget, C);

               system("pause");
               break;
           }
           case 0:
               return;
           default:
               cout << "Opsi tidak valid." << endl;
               break;
        }
    }
}


void menuParent(ListParent &L){
    int option=-99;
    while (option != 0) {
        system("cls");
        cout << "========== Menu Kelola Komposer ==========" << endl;
        cout << "|| 1. Tambah Awal Komposer          ||" << endl;
        cout << "|| 2. Tambah Akhir Komposer         ||" << endl;
        cout << "|| 3. Tambah Setelah Komposer       ||" << endl;
        cout << "|| 4. Hapus Awal Komposer           ||" << endl;
        cout << "|| 5. Hapus Akhir Komposer          ||" << endl;
        cout << "|| 6. Hapus Setelah Komposer        ||" << endl;
        cout << "|| 7. Tampilkan Semua Komposer      ||" << endl;
        cout << "|| 8. Cari Komposer                 ||" << endl;
        cout << "|| 0. Kembali ke Menu Admin         ||" << endl;
        cout << "========================================" << endl;
        cout << "Pilih Opsi : ";
        cin >> option;

        addressP P, prec;
        string idPrec, idFind;


        switch(option) {
           case 1:
           {
               Komposer K;

               cout << "\n--- Input Data Komposer Baru ---" << endl;
               cout << "ID Komposer : ";
               cin >> K.ID;

               cout << "Nama Komposer : ";
               cin >> K.nama;

               P = createElementParent(K);
               insertFirstParent(L, P);
               cout << "Komposer berhasil ditambahkan di awal." << endl;
               break;
           }
           case 2:
           {
               Komposer K;

               cout << "\n--- Input Data Komposer Baru ---" << endl;
               cout << "ID Komposer : ";
               cin >> K.ID;

               cout << "Nama Komposer : ";
               cin >> K.nama;

               P = createElementParent(K);
               insertLastParent(L, P);
               cout << "Komposer berhasil ditambahkan di akhir." << endl;
               break;
           }
           case 3:
           {
               Komposer K;

               cout << "Masukkan ID Komposer PRECEDENT: ";
               cin >> idPrec;
               prec = findElementParent(L, idPrec);

               if (prec != nullptr) {

                   cout << "\n--- Input Data Komposer Baru ---" << endl;
                   cout << "ID Komposer : ";
                   cin >> K.ID;

                   cout << "Nama Komposer : ";
                   cin >> K.nama;

                   P = createElementParent(K);
                   insertAfterParent(L, prec, P);
                   cout << "Komposer berhasil ditambahkan setelah " << prec->infoK.nama << endl;
               } else {
                   cout << "Komposer tidak ditemukan." << endl;
               }
               break;
           }
           case 4:
               deleteFirstParent(L, P);
               if (P != nullptr) {
                   cout << "Komposer " << P->infoK.nama << " berhasil dihapus dari awal." << endl;

               } else {
                   cout << "List Komposer kosong." << endl;
               }
               break;
           case 5:
               deleteLastParent(L, P);
               if (P != nullptr) {
                   cout << "Komposer " << P->infoK.nama << " berhasil dihapus dari akhir." << endl;
               } else {
                   cout << "List Komposer kosong." << endl;
               }
               break;
           case 6:
           {
               cout << "Masukkan ID Komposer: ";
               cin >> idPrec;
               prec = findElementParent(L, idPrec);
               if (prec != nullptr && prec->next != nullptr) {
                   deleteAfterParent(L, prec, P);
                   cout << "Komposer " << P->infoK.nama << " berhasil dihapus setelah " << prec->infoK.nama << endl;
               } else {
                   cout << "Komposer tidak ditemukan atau tidak memiliki next." << endl;
               }
               break;
           }
           case 7:
               cout << "\n--- DAFTAR SEMUA KOMPOSER ---" << endl;
               viewParent(L);
               break;
           case 8:
           {
               cout << "Masukkan ID Komposer yang dicari: ";
               cin >> idFind;
               P = findElementParent(L, idFind);
               if (P != nullptr) {
                   cout << "\n--- KOMPOSER DITEMUKAN ---" << endl;
                   cout << "ID: " << P->infoK.ID << " | Nama: " << P->infoK.nama << endl;
               } else {
                   cout << "Komposer dengan ID " << idFind << " tidak ditemukan." << endl;
               }
               break;
           }
           case 0:
               return;
           default:
               cout << "Opsi tidak valid." << endl;
               break;
        }
        system("pause");
    }
}


void menuChild(ListParent &L){
    int option=-99;
    while (option != 0) {
        system("cls");
        cout << "========== Menu Kelola Musik ==========" << endl;
        cout << "|| 1. Tampilkan Musik dari Komposer ||" << endl;
        cout << "|| 2. Hapus Musik (Child) Terakhir  ||" << endl;
        cout << "|| 3. Hapus Musik (Child) Setelah   ||" << endl;
        cout << "|| 4. Cari Musik (Child)            ||" << endl;
        cout << "|| 0. Kembali ke Menu Admin         ||" << endl;
        cout << "========================================" << endl;
        cout << "Pilih Opsi : ";
        cin >> option;

        addressP P;
        addressC C, precC;
        string idKomposer, idMusik;

        switch(option) {
           case 1:
               cout << "Masukkan ID Komposer untuk melihat musiknya: ";
               cin >> idKomposer;
               P = findElementParent(L, idKomposer);
               if (P != nullptr) {
                   cout << "\n--- DAFTAR MUSIK OLEH " << P->infoK.nama << " ---" << endl;
                   viewChild(P->firstChild);
               } else {
                   cout << "Komposer tidak ditemukan." << endl;
               }
               break;
           case 2:
               cout << "Masukkan ID Komposer: ";
               cin >> idKomposer;
               P = findElementParent(L, idKomposer);
               if (P != nullptr) {
                   deleteLastChild(P->firstChild, C);
                   if (C != nullptr) {
                       cout << "Musik '" << C->info.Judul << "' berhasil dihapus dari " << P->infoK.nama << endl;
                   } else {
                       cout << "List Musik Komposer kosong." << endl;
                   }
               } else {
                   cout << "Komposer tidak ditemukan." << endl;
               }
               break;
           case 3:
           {
               cout << "Masukkan ID Komposer: ";
               cin >> idKomposer;
               P = findElementParent(L, idKomposer);
               if (P != nullptr && P->firstChild != nullptr) {
                   cout << "Masukkan ID Musik: ";
                   cin >> idMusik;
                   precC = findElementChild(P->firstChild, idMusik);
                   if (precC != nullptr && precC->next != nullptr) {
                      deleteAfterChild(precC, C);
                      cout << "Musik '" << C->info.Judul << "' berhasil dihapus setelah " << precC->info.Judul << endl;
                   } else {
                       cout << "Musik tidak ditemukan atau tidak memiliki next." << endl;
                   }
               } else {
                   cout << "Komposer tidak ditemukan atau list musik kosong." << endl;
               }
               break;
           }
           case 4:
           {
               cout << "Masukkan ID Komposer: ";
               cin >> idKomposer;
               P = findElementParent(L, idKomposer);
               if (P != nullptr) {
                   cout << "Masukkan ID Musik yang dicari: ";
                   cin >> idMusik;
                   C = findElementChild(P->firstChild, idMusik);
                   if (C != nullptr) {
                       cout << "\n--- MUSIK DITEMUKAN ---" << endl;
                       cout << "Judul: " << C->info.Judul << ", Dibuat Oleh: " << P->infoK.nama << endl;
                   } else {
                       cout << "Musik dengan ID " << idMusik << " tidak ditemukan pada Komposer ini." << endl;
                   }
               } else {
                   cout << "Komposer tidak ditemukan." << endl;
               }
               break;
           }
           case 0:
               return;
           default:
               cout << "Opsi tidak valid." << endl;
               break;
        }
        system("pause");
    }
}
