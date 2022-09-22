/*
 Mroz Kamil

 Implementacja ADT set w jezyku C++ za pomoca dynamicznej listy ( wektora )
 */

#include<iostream>
#include <vector>
#include <algorithm>

using namespace std;

//set.h

class set {
    vector<int> vec;            //Wektor przyjmujacy elementy int

public:
    int getSize();                  //Rozmiar wektora
    void printSet();                //Wywietl zbior
    void insert(int x);             //Wstaw do zbioru
    void withdraw(int x);           //Usun element ze zbioru
    bool isInSet(int x);            //Czy element nalezy do zbioru
    //Przeciazanie operatorow
    set operator+(set& obj);        //Suma dwoch zbiorow
    set operator*(set& obj);        //Przeciecie dwoch zbiorow
    set operator-(set& obj);        //Roznica dwoch zbiorow
    bool operator==(set& obj);      //Identycznosc dwoch zbiorow
    bool operator<=(set& obj);      //Zawieranie sie w zbiorze

};

//Zwroc rozmiar wektora
int set::getSize() {
    return vec.size();
}

//Wyswietl zbior
void set::printSet() {
    cout << "{ ";
    //foreach po elementach wektora
    for (int element: vec) {
        cout << element << " , ";
    }
    cout << "}" << "\n";
}

//Wstaw element
void set::insert(int x) {
    //Jeli nie ma go w zbiorze
    if ( !isInSet(x) ){
        vec.push_back(x);       //Wstaw do wektora
    }
}

//Usuwanie elementu z wektora
void set::withdraw(int x) {
    //find z biblioteki algorithm, znajduje pierwsze wystapienie wartosci
    auto pozycja = find(vec.begin(), vec.end(), x);
    if(pozycja != vec.end()) {  //Jeli pozycja nie zwrocila iteratora koniec
        vec.erase(pozycja);     //Usun znaleziony element
    }
}

//Czy znajduje sie juz w zbiorze
bool set::isInSet(int x) {
    //foreach po elementach zbioru
    for (int element: vec) {
        if (element == x) {
            //cout << "Element zawiera sie w zbiorze" << "\n";
            return true;  //Jesli znaleziono
        }
    }
    //cout << "Element nie zawiera sie w zbiorze" << "\n";
    return false;  //Jesli nie znaleziono
}

//Suma dwoch zbiorow
set set::operator+(set& obj) {

    set suma;   //Zbior zsumowanych zbiorow

    //Petla po zbiorze "A"
    for (int element: vec) {
        suma.insert(element);       //Wstaw kazdy element do nowego zbioru
    }
    //Petla po zbiorze "B"
    for (int element: obj.vec) {
        suma.insert(element);       //Wstaw kazdy element do nowego zbioru
    }

    return suma;    //Zwroc ten zbior
}

//Przeciecie dwoch zbiorow
set set::operator*(set& obj) {

    set przeciecie;     //Zbior przeciecia zbiorow

    //Sprawdzamy ktory jest wiekszy, aby miec pewnosc ze przeszlismy po kazdym elemencie
    if (getSize() > obj.getSize()) {
        //Petla po kazdym elemencie wektora
        for (int element: vec) {
            if (isInSet(element) && obj.isInSet(element)) {     //Jesli element jest w obu zbiorach...
                przeciecie.insert(element);                     //..wstaw do nowego zbioru
            }
        }
    }
    else {
        //Petla po kazdym elemencie wektora
        for (int element: obj.vec) {
            if (isInSet(element) && obj.isInSet(element)) {     //Jesli element jest w obu zbiorach...
                przeciecie.insert(element);   //..wstaw do nowego zbioru
            }
        }
    }

    return przeciecie;      //Zwroc przeciecie zbiorow
}

//Roznica dwoch zbiorow
set set::operator-(set& obj) {

    set roznica;        //Zbior elementow roznicy zbiorow

    //Petla po kazdym elemencie wektora
    for (int element: vec) {
        if (isInSet(element) && !obj.isInSet(element)) {      //Jesli znajduje sie w pierwszym i nie znajduje sie w drugim....
            roznica.insert(element);     //....wstaw do nowego zbioru
        }
    }
    return roznica;     //Zwroc roznice zbiorow
}


//Identycznosc dwoch zbiorow
bool set::operator==(set &obj) {

    //sprawdzamy czy oba wektory sa identyczne
    if(vec == obj.vec) {
        //cout << "Zbiory sa identyczne" << "\n";
        return true;                            //Jesli tak zwraca prawde
    } else {
        //cout << "Zbiory nie sa identyczne" << "\n";
        return false;                           //Jesli nie, zwraca falsz
    }

}

//Zawieranie sie w zbiorze
bool set::operator<=(set &obj) {

    //Foreach po kazdym elemencie wektora
    for (int element: vec) {
        if ((isInSet(element) && !obj.isInSet(element))) {        //Jesli nie kazdy element zbioru pierwszego zawiera sie w drugim zbiorze..
            //cout << "Pierwszy zbior nie zawiera sie w drugim" << "\n";
            return false;           //...zwroc falsz
        }
    }
    //cout << "Pierwszy zbior zawiera sie w drugim" << "\n";
    return true;        //..inaczej true
}


//setListImplementation.cpp - tester

int main() {

    cout << "Hello World!\n";
    cout << boolalpha;

    set X = set();
    X.insert(2);
    X.insert(4);
    X.insert(5);
    X.insert(9);
    X.insert(6);
    X.insert(9);
    X.insert(7);

    X.printSet();
    cout << "set size: " << X.getSize()<<"\n";

    X.withdraw(4);
    X.printSet();
    cout << "set size: " << X.getSize()<<"\n";

    set Y = set();
    Y.insert(1); Y.insert(2); Y.insert(8); Y.insert(1000);

    cout << "\n\nSet X ";
    X.printSet();
    cout << "Set Y  ";
    Y.printSet();

    set Z = X + Y;
    cout << "suma X+Y   ";
    Z.printSet();

    set Z1 = X * Y;
    cout << "czesc wspolna X * Y   ";
    Z1.printSet();

    set Z2 = X - Y;
    cout << "roznica X - Y   ";
    Z2.printSet();

    cout << "\n\n\nTest porownywania/zawierania zbiorow\n";
    set C = set();
    C.insert(1); C.insert(2); C.insert(4);
    set D = set();
    D.insert(1); D.insert(2); D.insert(4); D.insert(7);

    cout << (bool)(C <= D) << "\n";
    cout << (bool)(D <= C) << "\n";
    cout << (bool)(C == C) << "\n";


    return 0;
}

