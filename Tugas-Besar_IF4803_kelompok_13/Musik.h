#ifndef MUSIK_H_INCLUDED
#define MUSIK_H_INCLUDED

using namespace std;

typedef string infotypeC;

typedef struct elmChild *addressC;

struct elmParent {
    infotypeC info;
    addressC next;
    addressC prev;
};

void createListChild(addressP p);
addressC createElemenChild(infotypeC x);
void insertFirstChild(addressP p, addressC c);
void insertLastChild(addressP p, addressC c);
void insertAfterChild(addressC prec, addressC c);
void deleteFirstChild(addressP p, addressC &c);
void deleteLastChild(addressP p, addressC c);
void deleteAfterChild(addressC prec, addressC c);
addressC findElemenChild(addressP p, infotypeC x);
void viewChild(addressP p)

#endif // MUSIK_H_INCLUDED

