#include <iostream>
#include "Komposer.h"
#include "Musik.h"
#include "main.h"

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
    Musik M5 = {"M005", "Agora", 2019};

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

int main()
{
    ListParent L;
    createListParent(L);

    DummyData(L);

    int option = -99;
    while (option != 0) {
        system("cls");
        cout << "============ MENU UTAMA ============" << endl;
        cout << "|| 1. Menu Admin                 ||" << endl;
        cout << "|| 2. Menu User (Studi Kasus)    ||" << endl;
        cout << "|| 0. Keluar                     ||" << endl;
        cout << "================================== " << endl;
        cout << "Pilih Opsi : ";
        cin >> option;

        switch(option) {
           case 1:
              menuAdmin(L);
              break;
           case 2:
              menuUser(L);
              break;
           case 0:
              cout << "Terima kasih telah menggunakan program." << endl;
              break;
           default:
              system("pause");
              break;
        }
    }
    return 0;
}
