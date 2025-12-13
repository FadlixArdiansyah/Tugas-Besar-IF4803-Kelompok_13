#ifndef MUSIK_H_INCLUDED
#define MUSIK_H_INCLUDED
#include <iostream>

using namespace std;

typedef struct Musik {
    string ID;
    string Judul;
    int tahunRilis;
};

typedef Musik infotypeC;
typedef struct elmChild *addressC;

struct elmChild {
    infotypeC info;
    addressC next;
    addressC prev;
};

void createListChild(addressC first);
addressC createElementChild(infotypeC X);
void insertFirstChild(addressC &first, addressC C);
void insertLastChild(addressC &first, addressC C);
void insertAfterChild(addressC prec, addressC C);
void deleteFirstChild(addressC &first, addressC &C);
void deleteLastChild(addressC &first, addressC &C);
void deleteAfterChild(addressC prec, addressC &C);
addressC findElementChild(addressC first, string ID_Musik);
void viewChild(addressC first);

#endif // MUSIK_H_INCLUDED

