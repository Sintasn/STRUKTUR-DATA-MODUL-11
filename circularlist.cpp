#include <iostream>
#include "circularlist.h"

void createList(List &L) {
    L.first = NULL;
}

address alokasi(infotype x) {
    address P = new Elmlist;
    P->info = x;
    P->next = P;
    P->prev = P;
    return P;
}

void dealokasi(address P) {
    delete P;
}

void insertFirst(List &L, address P) {
    if (L.first == NULL) {
        L.first = P;
    } else {
        address last = L.first->prev;
        P->next = L.first;
        P->prev = last;
        last->next = P;
        L.first->prev = P;
        L.first = P;
    }
}

void insertAfter(List &L, address Prec, address P) {
    if (Prec != NULL) {
        address Q = Prec->next;
        P->next = Q;
        P->prev = Prec;
        Prec->next = P;
        Q->prev = P;
    }
}

void insertLast(List &L, address P) {
    if (L.first == NULL) {
        L.first = P;
    } else {
        address last = L.first->prev;
        last->next = P;
        P->prev = last;
        P->next = L.first;
        L.first->prev = P;
    }
}

void deleteFirst(List &L, address &P) {
    if (L.first == NULL) {
        P = NULL;
    } else if (L.first->next == L.first) {
        P = L.first;
        L.first = NULL;
    } else {
        address last = L.first->prev;
        P = L.first;
        L.first = P->next;
        L.first->prev = last;
        last->next = L.first;
    }
}

void deleteAfter(List &L, address Prec, address &P) {
    P = Prec->next;
    address nextNode = P->next;
    Prec->next = nextNode;
    nextNode->prev = Prec;
}

void deleteLast(List &L, address &P) {
    if (L.first == NULL) {
        P = NULL;
        return;
    }

    address last = L.first->prev;
    if (last == L.first) {
        P = last;
        L.first = NULL;
    } else {
        address beforeLast = last->prev;
        P = last;
        beforeLast->next = L.first;
        L.first->prev = beforeLast;
    }
}

address findElm(List L, infotype x) {
    if (L.first == NULL) return NULL;

    address P = L.first;
    do {
        if (P->info.nim == x.nim)
            return P;
        P = P->next;
    } while (P != L.first);

    return NULL;
}

void printInfo(List L) {
    if (L.first == NULL) {
        cout << "List kosong\n";
        return;
    }

    address P = L.first;
    do {
        cout << "Nama : " << P->info.nama << endl;
        cout << "NIM  : " << P->info.nim << endl;
        cout << "JK   : " << P->info.jenis_kelamin << endl;
        cout << "IPK  : " << P->info.ipk << endl;
        cout << endl;
        P = P->next;
    } while (P != L.first);
}
