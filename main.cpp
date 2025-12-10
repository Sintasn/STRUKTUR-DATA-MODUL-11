#include <iostream>
#include "multilist.h"
#include "multilist.cpp"
using namespace std;

int main() {
    listinduk L;
    CreateList(L);

    cout << " INSERT INDUK " << endl;
    insertLast(L, alokasi(10));
    insertLast(L, alokasi(20));
    insertLast(L, alokasi(30));

    cout << "\n INSERT ANAK PADA INDUK " << endl;
    address induk20 = findElm(L, 20);

    insertLastAnak(induk20->lanak, alokasiAnak(101));
    insertLastAnak(induk20->lanak, alokasiAnak(102));
    insertLastAnak(induk20->lanak, alokasiAnak(103));

    cout << "\n INSERT ANAK PADA INDUK " << endl;
    address induk10 = findElm(L, 10);

    insertLastAnak(induk10->lanak, alokasiAnak(201));
    insertLastAnak(induk10->lanak, alokasiAnak(202));

    cout << "\n DATA MULTILIST " << endl;
    printInfo(L);

    cout << "\n DELETE INDUK " << endl;
    delP(L, 20);

    printInfo(L);

    return 0;
}