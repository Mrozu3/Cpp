/* Mroz Kamil

    Zaimplementowanie kolejki priorytetowej na bazie kopca binarnego.

 */

#include<iostream>

using namespace std;

//KopiecBinarny.h pokazany na zajeciach
class KopiecBinarny {

private:
    int const maxSize = 1000;           //Maksymalny rozmiar tablic/kopca
    int* table;                         //Tablica
    int aktSize= 0;                    //Aktualny rozmiar tablicy/ilosc elementow w kopcu

    void poprawWDol(int poz, int lastpoz);      //tworzy stos od podanego indeksu w dol
    void swap(int*, int*);                       //Swap

public:
    KopiecBinarny();
    void insertElement(int x);        //Wstawianie elementu do kopca
    int removeRootElement();          //Usuwanie elementu z kopca
    void wypiszTable();               //Wypisuje tablice
    int getAktSize();                 //Sprawdz aktualna wielkosc tablicy
    bool sprawdzPoprawnosc();                     //Check czy kopiec dziala
};

//Swap do zamiany
void KopiecBinarny::swap(int *elementA, int *elementB){
    int temp = *elementA;
    *elementA = *elementB;
    *elementB = temp;
}

//Tworzymy kopiec binarny o ustalonej wielkosci
KopiecBinarny::KopiecBinarny(){
    table = new int[maxSize];
    aktSize = 0;
}

//Naprawianie kopca
void KopiecBinarny::poprawWDol(int poz, int lastpoz) {
    int najwiekszy = poz;       //Najwiekszy priorytet kopca
    int lewy = 2*poz+1;         //Bierzemy lewe dziecko wezla
    int prawy = 2*poz+2;        //Bierzemy prawe dziecko wezla

    if (lewy < lastpoz && table[lewy] > table[najwiekszy]) {            //sprawdzamy dla lewego dziecka
        najwiekszy = lewy;
    }
    if (prawy < lastpoz && table[prawy] > table[najwiekszy]) {          //sprawdzamy dla prawego dziecka
        najwiekszy = prawy;
    }
    if (najwiekszy != poz) {
        swap(&table[poz], &table[najwiekszy]);          //zamieniamy
        poprawWDol(najwiekszy, lastpoz);
    }
}

//Wstawia nowy element do Kopca
void KopiecBinarny::insertElement(int x) {

    //Sprawdzamy dopuszczalny rozmiar
    if(aktSize == maxSize-1) {
        throw::out_of_range("Przekroczono dopuszczalna liczbe elementow");
    }

    int dziecko = getAktSize();      //Bierzemy pierwszy pusty indeks
    aktSize++;                  //Zwiekszamy aktualny rozmiar tablicy/ilosc elementow w kopcu
    int rodzic = (dziecko-1)/2;     //Odnajdujemy rodzica dla nowo wstawionego elementu

    while((dziecko > 0) && (table[rodzic] < x)) {           //Sprawdzamy warunek kopca
        swap(&table[dziecko], &table[rodzic]);                     //Jesli rodzic jest mniejszy od wstawianego elementu, to go zamieniamy, rodzic staje sie dzieckiem
        dziecko = rodzic;                                   //Przenosimy sie do nowego dziecka
        rodzic = (dziecko -1)/2;                             //Ponownie odnajdujemy rodzica dla nowego dziecka
    }
    table[dziecko] = x;                     //Wstawiamy x

}

//Wyciagamy najwiekszy priorytet
int KopiecBinarny::removeRootElement() {
    //Sprawdzamy czy kopiec nie jest pusty
    if( aktSize == 0){
        throw out_of_range("Kopiec jest pusty");
    }

    int ostatni = table[0];                     //Ostatni element kopca
    table[0] = table[getAktSize()-1];           //Nadpisujemy element
    aktSize--;                                  //Zmniejszamy kopiec usuwajac ostatni element
    poprawWDol(0,getAktSize());     //Poprawiamy
    return ostatni;                             //zwracamy usuniety element

}

//Wypisuje Tablice
void KopiecBinarny::wypiszTable() {
    //Iterujemy po tablicy
    for(int i = 0; i < aktSize; i++) {
        cout << table[i] << " - ";
    }
    cout << "\n";
}

//Zwroc aktualny rozmiar tablicy/elementow w kopcu
int KopiecBinarny::getAktSize() {
        return aktSize;
}

//Sprawdzamy poprawnosc kopca
bool KopiecBinarny::sprawdzPoprawnosc() {
    //Iteracja po tablicy
    for(int i = aktSize-1; i > 0; i--) {
        if(table[i]>table[(i-1)/2]) {       //sprawdzamy czy dziecko jest wieksze od rodzica
            return false;               //Jesli tak, wyrzuc blad
        }
    }
    return true;    //Jesli nie, wszystko dziala!
}

//Kopiec.cpp - tester
int main() {

    KopiecBinarny Kopiec;

    Kopiec.getAktSize();
    Kopiec.insertElement(2);
    Kopiec.wypiszTable();
    Kopiec.insertElement(5);
    Kopiec.wypiszTable();
    Kopiec.insertElement(3);
    Kopiec.wypiszTable();
    Kopiec.insertElement(1);
    Kopiec.wypiszTable();
    Kopiec.insertElement(7);
    Kopiec.wypiszTable();
    Kopiec.insertElement(4);
    Kopiec.wypiszTable();
    Kopiec.getAktSize();

    //Sprawdzamy poprawnosc kopca
    if(Kopiec.sprawdzPoprawnosc()) {
        cout << "Dziala \n";
    } else { cout << "Nie dziala \n"; }

    //Usuwanie Top elementow o najwyzszym priorytecie
    while( Kopiec.getAktSize() > 0) {
        cout << "Sciagniety Priorytet: " << Kopiec.removeRootElement() << "\n";
        Kopiec.wypiszTable();
    }

}
