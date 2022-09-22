#include <iostream>


const int maxlength = 50;   //maksymalna dlugosc
typedef int elementtype;    //definiujemy czym bedzie elementype
typedef int position;       //definiujemy czym bedzie position

class Kolejka
{
protected:
    elementtype Queue[maxlength];   //Tablica o maksymalnej dlugosci
    position Front; // Indeks elementu czołowego
    position Rear; // Indeks ostatniego elementu
public:
    Kolejka(){};        //Konstruktor kolejki
    ~Kolejka(){};       //Dekonstruktor
    int AddOne(int i);
    void Init();            //Inicjujemy kolejke
    void Enqueue(elementtype x);    //wstawia element do kolejki (wstawia na koniec)
    void Dequeue();                 // Usunięcie elementu z kolejki ( z poczatku kolejki )
    elementtype FrontElem();        // Zwróć pierwszy element z kolejki
    void Makenull();                //Przywracam kolejke do stanu inicjalizacji
    bool Empty();                   // Sprawdź, czy kolejka jest pusta
};

// Zainicjuj kolejkę
void Kolejka::Init() {
    Front = 0;          //Inicjuje zmienna front na 0
    Rear = maxlength - 1; //Inicjuje zmienna Rear na maksymalna dlugosc

}

//Zwieksz o 1
int Kolejka::AddOne(int i){
    return ((i + 1) % maxlength);   //jako modulo z maksymalnej dlugosci

}

// Zwróć pierwszy element z kolejki.
elementtype Kolejka::FrontElem(){
    if (!Empty()) //jesli kolejka nie jest pusta
        return Queue[Front]; //zwracam element pierwszy z kolei
}

// wstawia element do kolejki (wstawia na koniec).
void Kolejka::Enqueue(elementtype x){
    if (AddOne(AddOne(Rear)) != Front) // sprawdzam czy kolejka nie jest pelna
    {
        Rear = AddOne(Rear);    // aktualizuje pole REAR tak by wskazywalo na piersza wolna komorke (zamiast na pierwszy element)
        Queue[Rear] = x;        // wstawiam element
    }
}

// Usunięcie elementu z kolejki ( z poczatku kolejki )
void Kolejka::Dequeue(){
    if (!Empty()) //jesli kolejka nie jest pusta
    {
        Front = AddOne(Front); // aktualizuje pole FRONT (czyli wyrzucam to co jest na poczatku kolejki i wstawiam tam element nastepny w kolejnosci)

    }
}


// Sprawdź, czy kolejka jest pusta
bool Kolejka::Empty(){
    return (AddOne(Rear) == Front); //zwraca wartość true, gdy kolejka jest pusta, zwraca wartość false, gdy nie jest pusta
}

//Przywracam kolejke do stanu inicjalizacji
void Kolejka::Makenull(){
    Front = 0;              //Inicjuje zmienna font na 0
    Rear = maxlength - 1;   //Inicjuje zmienna Rear na maksymalna dlugosc
}

int main(){
    Kolejka *kolejka = new Kolejka();

    //Iniciujemy kolejke
    kolejka->Init();

    std::cout << "Empty() ";
    if (kolejka->Empty()) { std::cout << "Kolejka jest pusta" << std::endl; } else { std::cout << "Kolejka nie jest pusta" << std::endl;}

    std::cout << "Enqueue()" << std::endl;
    kolejka->Enqueue(5);

    std::cout << "Empty() ";
    if (kolejka->Empty()) { std::cout << "Kolejka jest pusta" << std::endl; } else { std::cout << "Kolejka nie jest pusta" << std::endl;}

    std::cout << "FrontElem(): ";
    std::cout << kolejka->FrontElem() << std::endl;

    std::cout << "Dequeue()" << std::endl;
    kolejka->Dequeue();

    std::cout << "Empty() ";
    if (kolejka->Empty()) { std::cout << "Kolejka jest pusta" << std::endl; } else { std::cout << "Kolejka nie jest pusta" << std::endl;}

    std::cout << "Enqueue()" << std::endl;
    kolejka->Enqueue(4);
    std::cout << "Enqueue()" << std::endl;
    kolejka->Enqueue(3);
    std::cout << "Enqueue()" << std::endl;
    kolejka->Enqueue(2);

    std::cout << "FrontElem(): ";
    std::cout << kolejka->FrontElem() << std::endl;

    std::cout << "Enqueue()" << std::endl;
    kolejka->Enqueue(1);

    std::cout << "FrontElem(): ";
    std::cout << kolejka->FrontElem() << std::endl;

    std::cout << "Dequeue()" << std::endl;
    kolejka->Dequeue();

    std::cout << "FrontElem(): ";
    std::cout << kolejka->FrontElem() << std::endl;

    std::cout << "Enqueue()"<< std::endl;
    kolejka->Enqueue(6);

    std::cout << "FrontElem(): ";
    std::cout << kolejka->FrontElem() << std::endl;

    std::cout << "Dequeue()" << std::endl;
    kolejka->Dequeue();
    std::cout << "Dequeue()" << std::endl;
    kolejka->Dequeue();

    std::cout << "FrontElem(): ";
    std::cout << kolejka->FrontElem() << std::endl;

    std::cout << "MakeNull()" << std::endl;
    kolejka->Makenull();

    std::cout << "Empty() " << std::endl;
    if (kolejka->Empty()) { std::cout << "Kolejka jest pusta" << std::endl; } else { std::cout << "Kolejka nie jest pusta" << std::endl; }

}