#include "Musik.h"
#include <iostream>

addressC createElementChild(infotypeC X){
    addressC c = new elmChild;
    c->info = X;
    c->next = nullptr;
    c->prev = nullptr;
    return c;
}

void insertLastChild(addressC &first, addressC C){
    if (first == NULL) {
        first = C;
    } else {
        addressC last = first;
        while (last->next != NULL) {
            last = last->next;
        }
        last->next = C;
        C->prev = last;
    }
}

void deleteLastChild(addressC &first, addressC &C){
    if (first == nullptr){
        cout << "Tidak ada child yang dapat di hapus" << endl;
    } else if (first->next == nullptr){
        C = first;
        first = nullptr
    } else {
        C = first;
        while (C->next != nullptr){
            C = C->next;
        }
        C->prev->next = nullptr;
        C->prev = nullptr
    }
}

void deleteAfterChild(addressC prec, addressC &C){
    C = prec->next;
    prec->next = C->next;
    C-next-prev = prec;
    C->next = nullptr;
    C->next = nullptr;

}

addressC findElementChild(addressC first, string ID_Musik){
    addressC c = first;
    while (c = nullptr){
        if (c->info.ID == ID_Musik){
            return c;
        }
        c = c->next;
    }
    return nullptr;
}
