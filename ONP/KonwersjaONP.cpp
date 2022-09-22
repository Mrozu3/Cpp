#include <iostream>

using namespace std;

//Definiujemy maksymalna dlugosc
const int maxlenght = 50;
//Definiujemy typy
typedef char elementtype;
typedef int position;

//Klasa Stos
class Stos
{
    char S[maxlenght]{};//Tablica o maksymalej dlugosci
    position Top; //szczyt stosu
public:
    Stos(); //Konstruktor
    elementtype TopElem();  //Jesli stost nie jest pusty zwracamy wartosc ze szczytu stosu
    void Push(elementtype x); //Sprawdamy czy jest mijesce w tablicy, jesli jest, wstawiamy element na szczyt stosu
    void Pop(); //Sprawdzamy czy stos nie jest pusty, jesli nie  jest, usuwamy element ze szczytu stosu
    bool Empty() const; //Sprawdzamy czy stos jest pusty
    void Makenull(); //Sprawiamy ze stos staje sie pusty
    void Show(); //Wyswietlamy caly stos
};

//Konstruktor ustawia Top na -1
Stos::Stos()
{
    Top=-1;
}

//Zwraca element na szczycie stosu
elementtype Stos::TopElem()
{
    //Jesli stos nie jest pusty
    if (Top>=0) {
        return S[Top];
    } else { return -1;}

}

//Dodaje nowy element na szczyt stosu
void Stos::Push(elementtype x)
{
    //jesli nie przekroczyl maksymalnego rozmiaru
    if (Top < maxlenght-1)
    {
        Top = Top + 1; //Zwiekszamy wartosc szczytu stosu
        S[Top]= x; //Dodajemy nowy element do tablicy

    }
}

//Usuwamy element ze szczytu stosu
void Stos::Pop()
{
    //Jesli stos nie jest pusty
    if (Top >= 0) {
        Top = Top -1; //Zmniejszamy szczyt o jeden
    }
}

//Sprawdzamy czy stos jest pusty
bool Stos::Empty() const
{
    return (Top==-1); //zwracamy 1 jesli jest i 0 jesli nie jest

}

//Usuwamy wszystkie elementy ze stosu
void Stos::Makenull()
{
    Top=-1; //Ustawiajac jego szczyt na -1
}

//Wyswietlamy wszytkie elementy stosu
void Stos::Show()
{
    std::cout<<"Dol"<<std::endl;

    //Iterujac po kolejnych elementach stosu az to szczytu
    for(int i = 0; i <= Top; i++) {
        std::cout<<S[i]<<std::endl; //Wyswietlamy kolejne elementy
    }

    std::cout<<"Gora"<<std::endl;

}

//Funkcja do zwracania wagi operatorów
int wagaoperatorw(char znakoperatora){
    //W przypadku jaki to operator, zwróć odpowiednią wartość
    switch(znakoperatora){
        case -1:  ;
        case '(': return -1;
        case '+': ;
        case '-': return 1;
        case '*': ;
        case '/': return 2;
        case '^': ;
        case '~': return 3;
    }
    return 0;
}

int main() {

    Stos Stos;  //Tworzymy obiekt

    cout << "Podaj wyrazenie do przekształcenia na ONP" << endl;
    string dzialanie;
    //Odczytywanie linii do zmiennej string
    getline(cin, dzialanie);

    cout << "Podane wyrażenie wygląda następująco: " << dzialanie << endl; // Wyświetlamy podane działanie
    cout << "W notacji ONP wygląda następująco: ";

    //Odczytuję tablicę znak po znaku
    for(int i=0; i < dzialanie.length(); i++){

        //Jeśli czytany znak to liczba
        if(dzialanie[i] != '+' && dzialanie[i] != '-' && dzialanie[i] != '*' && dzialanie[i] != '/' && dzialanie[i] != '^' && dzialanie[i] != '(' && dzialanie[i] != ')' && dzialanie[i] != ' ' && dzialanie[i] != '~') {
            cout << dzialanie[i] << " ";    //Wyświetl na wyjściu
        }
            //Inaczej jest operatorem lub nawiasem
        else{
            //W przypadku bycia operatorem + - * / ^
            if(dzialanie[i] == '+' || dzialanie[i] == '-' || dzialanie[i] == '*' || dzialanie[i] == '/' || dzialanie[i] == '^' || dzialanie[i] == '~'){

                //Sprawdzamy wagę operatora na szczytu stosu, jeśli dopóki wyższy niż operator który chcemy umieścić...
                while(wagaoperatorw(Stos.TopElem()) >= wagaoperatorw(dzialanie[i])) {
                    cout << (char)Stos.TopElem() << " ";    //..Ściągamy go ze stosu, czyli wypisujemy na wyjście
                    Stos.Pop();                             // i usuwamy ze stosu
                }
                Stos.Push(dzialanie[i]); //Wstawiamy na stos

                //Sprawdzamy wagę operatora na szczytu stosu, jeśli jest niższa niż operator który chcemy umieścić...
                while(wagaoperatorw(Stos.TopElem() < wagaoperatorw(dzialanie[i]))) {
                    Stos.Push(dzialanie[i]); //Wstawiamy nasz operator na stos
                }
            }
                //W przypadku bycia nawiasem
            else{
                if (dzialanie[i] == '(') {  //Nawias rozpoczynający
                    Stos.Push(dzialanie[i]);    //Wstaw na stos
                }
                if (dzialanie[i] == ')') {  //Nawias zamykający
                    while (Stos.TopElem() != '(') { //Dopóki nie dojdziesz do nawiasu otwierającego
                        cout << (char)Stos.TopElem() << " "; //..Ściągamy go ze stosu, czyli wypisujemy na wyjście
                        Stos.Pop(); // i usuwamy ze stosu
                    }
                    Stos.Pop(); //Potem, usuń nawias otwierający
                }
            }
        }

        if( dzialanie[i] == ' ') { }    //W przypadku spacji, pomijaj ją
    }

    //Gdy skończymy odczytywać wyrażenie, a stos nie jest pusty
    while(!Stos.Empty()) {
        cout << (char)Stos.TopElem() << " ";   //..Ściągamy go ze stosu, czyli wypisujemy na wyjście
        Stos.Pop(); // i usuwamy ze stosu
    }

    cout << endl; //Przenieś do następnej linii

    return 0;
}

