// Implementacja Stosu na liscie tablicowej Mroz Kamil


#include <iostream>

//Definiujemy maksymalna dlugosc
const int maxlenght = 20;
//Definiujemy typy
typedef int elementtype;
typedef int position;

//Klasa Stos
class Stos
{
    int S[maxlenght]{};//Tablica o maksymalej dlugosci
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

int main() {

    //Tworzymy obiekt
    Stos stos;

    if(stos.Empty()) { std::cout<<"Stos jest pusty"<<std::endl; } else { std::cout<<"Stos nie jest pusty"<<std::endl; }
    stos.Push(5);
    std::cout<<"Top element: "<<stos.TopElem()<<std::endl;
    if(stos.Empty()) { std::cout<<"Stos jest pusty"<<std::endl; } else { std::cout<<"Stos nie jest pusty"<<std::endl; }
    stos.Pop();
    if(stos.Empty()) { std::cout<<"Stos jest pusty"<<std::endl; } else { std::cout<<"Stos nie jest pusty"<<std::endl; }
    stos.Push(2);
    stos.Push(3);
    std::cout<<"Top element: "<<stos.TopElem()<<std::endl;
    stos.Makenull();
    if(stos.Empty()) { std::cout<<"Stos jest pusty"<<std::endl; } else { std::cout<<"Stos nie jest pusty"<<std::endl; }

    stos.Push(1);
    std::cout<<"Top element: "<<stos.TopElem()<<std::endl;
    stos.Push(2);
    stos.Push(3);
    std::cout<<"Top element: "<<stos.TopElem()<<std::endl;
    stos.Pop();
    std::cout<<"Top element: "<<stos.TopElem()<<std::endl;
    stos.Push(3);
    stos.Show();
    std::cout<<"Top element: "<<stos.TopElem()<<std::endl;


    return 0;

}
