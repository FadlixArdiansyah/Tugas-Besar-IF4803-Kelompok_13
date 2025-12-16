#ifndef KOMPOSER_H_INCLUDED
#define KOMPOSER_H_INCLUDED
#include <iostream>
#include "Musik.h"

using namespace std;

typedef struct Komposer {
    string ID;
    string nama;
};

typedef struct Komposer infotypeP;
typedef struct elmParent *addressP;
typedef struct elmChild *addressC;

struct elmParent {
    infotypeP infoK;
    addressP next;
    addressC firstChild;
};

struct ListParent {
    addressP first;
};

void createListParent(ListParent &L);
addressP createElementParent(infotypeP X);
void insertFirstParent(ListParent &L, addressP P);
void insertLastParent(ListParent &L, addressP P);
void insertAfterParent(ListParent &L, addressP prec, addressP P);
void deleteFirstParent(ListParent &L, addressP &P);
void deleteLastParent(ListParent &L, addressP &P);
void deleteAfterParent(ListParent &L, addressP prec, addressP &P);
addressP findElementParent(ListParent L, string ID_Komposer);
void viewParent(ListParent L);
void insertNewChildToParent(ListParent &L, string ID_Komposer, addressC C);
void findMostProductiveParent(ListParent L);
void searchMusicByYear(ListParent L, int TahunRilis);
void findLeastProductiveParent(ListParent L);

#endif // KOMPOSER_H_INCLUDED
