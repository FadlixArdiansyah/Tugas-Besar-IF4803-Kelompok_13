#include "main.h"
#include "Komposer.h"
#include <iostream>


using namespace std;

void DummyData(ListParent &L) {
    cout << "Menginisialisasi Data Dummy..." << endl;

    Komposer K1 = {"K001", "Wisnu"};
    addressP P1 = createElementParent(K1);
    insertFirstParent(L, P1);

    Komposer K2 = {"K002", "Jayjax"};
    addressP P2 = createElementParent(K2);
    insertLastParent(L, P2);

    Komposer K3 = {"K003", "Rhoma"};
    addressP P3 = createElementParent(K3);
    insertLastParent(L, P3);

    Komposer K4 = {"K004", "Kendrick Lamar"};
    addressP P4 = createElementParent(K4);
    insertLastParent(L, P4);

    Musik M1 = {"M001", "Yummy", 2022};
    Musik M2 = {"M002", "Cartel", 2011};
    Musik M3 = {"M003", "Sahara", 2012};

    insertNewChildToParent(L, "K001", createElementChild(M1));
    insertNewChildToParent(L, "K001", createElementChild(M2));
    insertNewChildToParent(L, "K001", createElementChild(M3));

    Musik M4 = {"M004", "FOMO", 2025};
    Musik M5 = {"M005", "Agora", 2017};

    insertNewChildToParent(L, "K002", createElementChild(M4));
    insertNewChildToParent(L, "K002", createElementChild(M5));

    Musik M6 = {"M006", "Gala Gala", 2021};

    insertNewChildToParent(L, "K003", createElementChild(M6));

    Musik M7 = {"M007", "HUMBLE", 2017};
    Musik M8 = {"M008", "Not Like Us", 2024};
    Musik M9 = {"M009", "Luther", 2023};
    Musik M10 = {"M010", "LOVE", 2017};

    insertNewChildToParent(L, "K004", createElementChild(M7));
    insertNewChildToParent(L, "K004", createElementChild(M8));
    insertNewChildToParent(L, "K004", createElementChild(M9));
    insertNewChildToParent(L, "K004", createElementChild(M10));

    cout << "Inisialisasi Selesai. " << endl;

}

void menuUser(ListParent &L){
    int option=-99;
    if (L.first == nullptr){
        DummyData(L);
    }
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
