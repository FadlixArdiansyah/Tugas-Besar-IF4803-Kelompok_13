#include "main.h"
#include "Komposer.h"
#include <iostream>


using namespace std;

void menuUser(ListParent &L){
    int option=-99;
    while (option != 0) {
        system("cls");
        cout << "=================== Menu Studi Kasus ===================== " << endl;
        cout << "|| 1. Cari Komposer Paling Produktif                     ||" << endl;
        cout << "|| 2. Cari Musik Berdasarkan Tahun                       ||" << endl;
        cout << "|| 3. Cari Komposer yang Memiliki Musik paling Sedikit   ||" << endl;
        cout << "|| 0. Kembali ke Menu Utama                              ||" << endl;
        cout << "===========================================================" << endl;
        cout << "Pilih Opsi : ";
        cin >> option;

        int tahunRilis;

        switch(option) {
           case 1:
              system("cls");
              cout << "--- KOMPOSER PALING PRODUKTIF ---" << endl;
              findMostProductiveParent(L);
              break;
           case 2:
              system("cls");
              cout << "--- CARI MUSIK BERDASARKAN TAHUN RILIS ---" << endl;
              cout << "Masukkan Tahun Rilis yang dicari: ";
              cin >> tahunRilis;
              searchMusicByYear(L, tahunRilis);
              break;
            case 3:
              system("cls");
              cout << "--- KOMPOSER PALING SEDIKIT MEMILIKI MUSIK ---" << endl;
              findLeastProductiveParent(L);
              break;
           case 0:
              return;
           default:
              cout << "Opsi tidak valid." << endl;
              break;
        }
        system("pause");
    }
}
