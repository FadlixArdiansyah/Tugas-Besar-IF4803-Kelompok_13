#ifndef KOMPOSER_H_INCLUDED
#define KOMPOSER_H_INCLUDED
#include <iostream>
using namespace std;

typedef string infotypeP;
typedef struct elmParent *addressP;

struct elmParent {
    infotypeP infoK;
    addressP next;
    addressP nextChild;
};

struct ListParent {
    addressP first;
};

void createListParent(ListParent &L);
addressP createElemenParent(infotypeP x);
void insertFirstParent(ListParent &L, addressP p);
void insertLastParent(ListParent &L, addressP p);
void insertAfterParent(ListParent &L, addressP p, addressP prec);
void deleteFirstParent(ListParent &L, addressP &p);
void deleteLastParent(ListParent &L, addressP &p);
void deleteAfterParent(ListParent &L, addressP &p, addressP prec);
addressP findElemenParent(ListParent L, infotypeP x);
void viewParent(ListParent L);



#endif // KOMPOSER_H_INCLUDED
