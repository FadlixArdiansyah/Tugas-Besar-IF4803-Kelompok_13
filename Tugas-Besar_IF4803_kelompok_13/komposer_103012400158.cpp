#include "Komposer.h"
#include "Musik.h"
#include <iostream>

addressP createElementParent(infotypeP X){
    addressP p = new elmParent;
    p->infoK = X;
    p->next = nullptr;
    p->firstChild = nullptr;
    return p;
}

void insertLastParent(ListParent &L, addressP P){
    if (L.first == nullptr){
        L.first = P;
    } else {
        addressP q = L.first;
        while (q->next != nullptr){
            q = q->next;
        }
        q->next = P;
    }
}

void deleteLastParent(ListParent &L, addressP &P){
    addressP q = L.first;
    if (L.first == nullptr){
        P = nullptr;
    } else if (q->next == nullptr){
        P = L.first;
        L.first = nullptr;
    } else {
        while (q->next->next != nullptr){
            q = q->next;
        }
        P = q->next;
        q->next = nullptr;
    }
}

addressP findElementParent(ListParent L, string ID_Komposer){
    addressP p = L.first;
    while (p != nullptr){
        if (p->infoK.ID == ID_Komposer){
            return p;
        }
        p = p->next;
    }
    return nullptr;
}

void insertNewChildToParent(ListParent &L, string ID, addressC C){
    addressP p = findElementParent(L, ID);
    if (p != nullptr){
        insertLastChild(p->firstChild, C);
        cout << "Musik: " << C->info.Judul << " Berhasil ditambah Ke komposer " << p->infoK.nama << "'." << endl;
    } else {
        cout << "Komposer dengan ID " << ID << " Tidak ditemukan." << endl;
    }
}

void findMostProductiveParent(ListParent L){
     if (L.first == nullptr){
        cout << "List Kosong " << endl;
    }

    addressP p = L.first;
    int max_Count = -1;
    string productive = "";

    while (p != nullptr){
        int Count = 0;
        addressC C = p->firstChild;
        while (C != nullptr){
            Count++;
            C = C->next;
        }
        if (Count > max_Count) {
            max_Count = Count;
            C = C->next;
        }
        p = p->next;
    }
    if (max_Count > 0){
        cout << "Komposer paling produktif: "<< productive << endl;
        cout << "Jumlah Musik: "<< max_Count << endl;
    } else {
        cout << "Komposer tidak memiliki musik." << endl;
    }
}

void searchMusicByYear(ListParent L, int TahunRilis){
    if (L.first == nullptr){
        cout << "List Kosong." << endl;
    }

    bool found = false;
    addressP p = L.first;
    while (p != nullptr){
        addressC c = p->firstChild;
        while (c != nullptr){
            if (c->info.tahunRilis == TahunRilis){
                cout << "Judul: " << c->info.Judul << ", Dibuat Oleh: " << p->infoK.nama << endl;
                found = true;
            }
            c = c->next;
        }
        p = p->next;
    }
}
