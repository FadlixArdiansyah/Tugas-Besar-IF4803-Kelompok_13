#ifndef MUSIK_H_INCLUDED
#define MUSIK_H_INCLUDED
#include <iostream>
#include "Komposer.h"

using namespace std;

typedef struct Musik {
    string ID;
    string Judul;
    int tahunRilis;
}

typedef string infotypeC;
typedef struct elmChild *addressC;

struct elmParent {
    infotypeC info;
    addressC next;
    addressC prev;
};

void createListChild(addressP p);
addressC createElementChild(InfoChild X);
void insertFirstChild(addressC &first, addressC C);
void insertLastChild(addressC &first, addressC C);
void insertAfterChild(addressC prec, addressC C);
void deleteFirstChild(addressC &first, addressC &C);
void deleteLastChild(addressC &first, addressC &C);
void deleteAfterChild(addressC prec, addressC &C);
addressC findElementChild(addressC first, string ID_Musik);
void viewChild(addressC first);

#endif // MUSIK_H_INCLUDED

