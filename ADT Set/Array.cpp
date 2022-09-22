/*
 Mroz Kamil

 Implementacja ADT set w jezyku C++ za pomoca tablicy o zadeklarowanej długości
 */
#include<iostream>

using namespace std;

//setArr.h

class setArr {
    int size;                                   //Rozmiar/ilosc elementow
    const int universeSize = 100;               //Maksymalny rozmiar
    bool* table;                                //tablica wskaznikow
    bool checkRangeCorrectness(int x) const;    //Czy dana liczba nie wychodzi poza mozliwa skale universeSize

public:
    setArr();                               //Konstruktor
    void insert(int x);                     //Wstaw do zbioru
    void withdraw(int x);                   //Usun element ze zbioru
    bool isInSet(int i);                    //Czy element nalezy do zbioru
    int getSize() const;                    //Rozmiar tablicy
    void clearSet();                        //Wyczysc zbior
    void printSet();                        //Wywietl zbior
    setArr operator+(setArr& object);       //Suma dwoch zbiorow
    setArr operator*(setArr& object);       //Przeciecie dwoch zbiorow
    setArr operator-(setArr& object);        //Roznica dwoch zbiorow
    bool operator==(setArr& object);         //Identycznosc dwoch zbiorow
    bool operator <= (setArr& object);        //Zawieranie sie w zbiorze
};

//Czy dana liczba nie wychodzi poza mozliwa skale universeSize
bool setArr::checkRangeCorrectness (int x) const {
    if (x >= universeSize) {
        cout << "Liczba " << x << " jest wieksza od dopuszczalnej maksymalnej wartosci" << '\n';        //Jesli podana liczba przewyzsza maksymalna wartosc
        return false;
    }
    return true;
}

//Tworzenie tablicy
setArr::setArr() {
    table = new bool[100];          //Tablica prawda/falsz rozmiaru 100
    size = 0;                       //rozmiar/ilosc elementow 0
    //Wypelniamy tablice o staly rozmiar uniwersum...
    for(int i = 0; i < universeSize; i++) {
        table[i] = false;           //... boleean false
    }

}

//Wstaw element
void setArr::insert(int x) {
    //Sprawdzamy czy liczba miesci sie w zakresie uniwersum
    if(checkRangeCorrectness(x)) {
        if(!table[x]) {             //Jeli nie znajduje sie juz w zbiorze
            table[x] = true;        //Ustaw element na true
            size++;                 //Zwieksz rozmiar/ilosc elementow
        }
    }
}

//Usuwanie elementu
void setArr::withdraw(int x) {
    //Sprawdzamy czy liczba miesci sie w zakresie uniwersum
    if(checkRangeCorrectness(x)) {
        if(table[x]) {            //Jeli znajduje sie w zbiorze
            table[x] = false;     //Ustaw element na false
            size--;               //Zmniejsz rozmiar/ilosc elementow
             }
        }
    }

//Czy znajduje sie juz w zbiorze
bool setArr::isInSet(int i) {
    //Sprawdzamy czy liczba miesci sie w zakresie uniwersum
    if(checkRangeCorrectness(i)) {
        if(table[i]) {      //Zwroci true lub false zaleznie od tego czy sie znajduje
            //cout << "Element zawiera sie w zbiorze" << "\n";
            return true;    //Jesli znaleziono
        }        else {
            //cout << "Element nie zawiera sie w zbiorze" << "\n";
            return false;   //Jesli nie znaleziono
        }
    }
    else { return false; }      //Zabezpieczenie przed wyjsciem poza zakres [100]
}

//Sprawdz ile elementow jest w zbiorze
int setArr::getSize() const {
    return size;
}

//Wyczysc zbior
void setArr::clearSet() {
    //Wypelniamy tablice o staly rozmiar uniwersum...
    for(int i = 0 ;i < universeSize; i++) {
        table[i] = false;        //... boleean false
    }
    size = 0;   //Ustaw rozmiar/ilosc elementow 0
}

//Wyswietl zbior
void setArr::printSet() {
    cout << "{ ";
    //Przeszukujemy tablice o staly rozmiar uniwersum...
    for (int i = 0; i < universeSize; i++) {
        if (table[i]) {             //Jesli true, element istnieje..
            cout << i << " , ";     //..wyswietl go
        }
    }
    cout << "}" << "\n";
}

//Suma dwoch zbiorow
setArr setArr::operator+(setArr& object){

    setArr suma;    //Zbior zsumowanych zbiorow

    //Iterujemy po tablicy o staly rozmiar uniwersum...
    for (int i = 0; i < universeSize; i++) {
        if(table[i] || object.table[i]) {       //Jeli znajduje sie w pierwszym lub drugim zbiorze
            suma.insert(i);                     //Wstaw do nowego zbioru
        }
    }
    return suma;        //Zwroc zbior
}

//Przeciecie dwoch zbiorow
setArr setArr::operator*(setArr& object){

    setArr przeciecie;      //Zbior przeciecia zbiorow
    //Iterujemy po tablicy o staly rozmiar uniwersum...
    for (int i = 0; i < universeSize; i++) {
        if(table[i] && object.table[i]) {       //Jesli znajduje sie w pierwszym i drugim zbiorze
            przeciecie.insert(i);               //Wstaw do nowego zbioru
        }
    }
    return przeciecie;      //Zwroc zbior
}

//Roznica dwoch zbiorow
setArr setArr::operator-(setArr& object){

    setArr roznica;     //Zbior roznicy dwoch zbiorow

    //Iterujemy po tablicy o staly rozmiar uniwersum...
    for (int i = 0; i < universeSize; i++) {
        if(table[i] && !object.table[i]) {      //Jesli znajduje sie w pierwszym i nie znajduje sie w drugim
            roznica.insert(i);                  //Wstaw do nowego zbioru
        }
    }
    return roznica;         //Zwroc zbior
}


//Identycznosc dwoch zbiorow
bool setArr::operator==(setArr& object){

    //Iterujemy po tablicy o staly rozmiar uniwersum...
    for(int i = 0; i < universeSize; i++) {
        if ((table[i] && !object.table[i]) || (!table[i] && object.table[i])) {     //Jesli znajduje sie w pierwszym i nie znajduje sie w drugim lub na odwrot, to nie sa identyczne
            //cout << "Zbiory nie sa identyczne" << "\n";
            return false;                            //Jesli nie, zwraca falsz
        }
    }
    //cout << "Zbiory sa identyczne" << "\n";
    return true;                                    //Jesli tak zwraca prawde
}

//Zawieranie sie w zbiorze
bool setArr::operator<=(setArr& object) {

    //Iterujemy po tablicy o staly rozmiar uniwersum...
    for(int i = 0; i < universeSize; i++) {
        if(table[i] && !object.table[i]) {          //Znajduje sie w pierwszym i nie znajduje sie w drugim, to pierwszy nie zawiera sie w drugim
            return false;       //Jesli nie, zwraca falsz
        }
    }
    return true;              //Jesli tak zwraca prawde
}

//CppSet.cpp - tester

int main()
{
    std::cout << "Set testy\n***********************\n";

    setArr X= setArr();
    std::cout << X.isInSet(10) <<"\n";
    X.insert(10);
    std::cout << X.isInSet(10) << "\n";

    X.insert(50); X.insert(11); X.insert(11); X.insert(2); X.insert(3);
    std::cout << "set size  "<<X.getSize();

    std::cout << "\nSet X    ";
    X.printSet();

    setArr Y = setArr();
    Y.insert(1); Y.insert(2); Y.insert(5);
    std::cout << "Set Y    ";
    Y.printSet();

    std::cout << "Sum of sets\n";
    setArr Z = X + Y;
    std::cout << "Set Z    ";
    Z.printSet();

    std::cout << "Intersection of sets\n";
    setArr Z1 = X * Y;
    std::cout << "Set Z1    ";
    Z1.printSet();

    std::cout << "Difference of sets\n";
    setArr Z2 = X - Y;
    std::cout << "Set Z2    ";
    Z2.printSet();

    std::cout << "\n\nTest dodania zbyt duzej liczby\n";
    X.insert(111);



    std::cout << "\n\n\nTest porownywania/zawierania zbiorow\n";
    setArr C = setArr();
    C.insert(1); C.insert(2); C.insert(4);
    setArr D = setArr();
    D.insert(1); D.insert(2); D.insert(4); D.insert(7);


    std::cout << (bool)(C <= D)<<"\n";
    std::cout << (bool)(D <= C)<<"\n";
    std::cout << (bool)(C == C) << "\n";
}
