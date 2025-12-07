#include "Musik"
#include <iostream>

void createListChild(addressP p){
    P =nullptr;
}
void insertFirstChild(addressC &first, addressC C){
  if (first == nullptr) {
        first = C;
    } else {
        addressC last = first;
        while (last->next != nullptr) {
            last = last->next;
        }
        last->next = C;
        C->prev = last;
    }
}

void insertAfterChild(addressC prec, addressC C){
  if (prec != nullptr) {
        C->next = prec->next;
        prec->next = C;
    }
}

void deleteFirstChild(addressC &first, addressC &C){
  if (first == nullptr) {
        C = nullptr;
    } else {
        C = first;
        first = first->next;
        C->next = nullptr;
    }
}

void viewChild(addressC first) {
  addressC P = first;
    if (P == nullptr) {
        cout << "List Musik kosong.\n";
    } else {
        while (P != nullptr) {
            cout << "ID Musik      : " << P->info.ID << endl;
            cout << "Judul         : " << P->info.Judul << endl;
            cout << "Tahun Rilis   : " << P->info.tahunRilis << endl;
            cout << "---------------------------\n";
            P = P->next;
        }
    }
}
