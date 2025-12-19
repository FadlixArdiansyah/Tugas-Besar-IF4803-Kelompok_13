#include <iostream>
#include "Komposer.h"
#include "Musik.h"
#include "main.h"

using namespace std;



int main()
{
    ListParent L;
    createListParent(L);



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
