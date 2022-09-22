#include <iostream>

using namespace std;

//Definiujemy maksymalna dlugosc
const int maxlenght = 50;
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

int main(){

    Stos stos;            //Tworzymy obiekt
    string dzialanie;     //String do którego będziemy odczytywali działanie na wejściu

    cout<< "Podaj działanie w notacji ONP" << endl;
    //Odczytywanie linii do zmiennej string
    getline(cin, dzialanie);

    cout << "Dane działanie wygląda następująco: " << dzialanie << endl; // Wyświetlamy podane działanie

    //Odczytuję tablicę znak po znaku
    for(int i=0; i < dzialanie.length(); i++){
        //jeśli czytany znak to liczba
        if(dzialanie[i] != '+' && dzialanie[i] != '-' && dzialanie[i] != '*' && dzialanie[i] != '/' && dzialanie[i] != '^' && dzialanie[i] != '(' && dzialanie[i] != ')' && dzialanie[i] != ' ' && dzialanie[i] != '~' ) {
            stos.Push(dzialanie[i] - '0'); // wrzucam go na stos
        }
            //Jeśli to nie liczba
        else {
            //Zależnie jakim operatorem jest czytany znak
            switch(dzialanie[i]){
                //W przypadku plusa, pobierz dwie poprzednie liczby ze stosu i je dodaj
                case '+': {
                    int skladnikA = stos.TopElem(); //Pobierz ze stosu element na samej górze
                    stos.Pop(); //Usuń go ze stosu

                    int skladnikB = stos.TopElem(); //Pobierz ze stosu element na samej górze
                    stos.Pop(); //Usuń go ze stosu

                    int wynik = skladnikA + skladnikB;  //Oblicz wynik
                    stos.Push(wynik);  //Wstaw go na stos

                    break;
                }
                    //W przypadku minusa, pobierz dwie poprzednie liczby ze stosu i je odejmij w odpowiedniej kolejności ( tą niżej na stosie od tej wyżej)
                case '-': {
                    int skladnikA = stos.TopElem(); //Pobierz ze stosu element na samej górze
                    stos.Pop(); //Usuń go ze stosu

                    int skladnikB = stos.TopElem(); //Pobierz ze stosu element na samej górze
                    stos.Pop(); //Usuń go ze stosu

                    int wynik = skladnikB - skladnikA; //Oblicz wynik
                    stos.Push(wynik); //Wstaw go na stos

                    break;
                }
                    //W przypadku mnożenia, pobierz dwie poprzednie liczby ze stosu i je pomnóż
                case '*': {
                    int skladnikA = stos.TopElem(); //Pobierz ze stosu element na samej górze
                    stos.Pop(); //Usuń go ze stosu

                    int skladnikB = stos.TopElem(); //Pobierz ze stosu element na samej górze
                    stos.Pop(); //Usuń go ze stosu

                    int wynik = skladnikA * skladnikB; //Oblicz wynik
                    stos.Push(wynik); //Wstaw go na stos

                    break;
                }
                    //W przypadku dziela, pobierz dwie poprzednie liczby ze stosu i je podziel w odpowiedniej kolejności ( tą niżej na stosie przez tą wyżej )
                case '/': {
                    int skladnikA = stos.TopElem(); //Pobierz ze stosu element na samej górze
                    stos.Pop(); //Usuń go ze stosu

                    int skladnikB = stos.TopElem(); //Pobierz ze stosu element na samej górze
                    stos.Pop(); //Usuń go ze stosu

                    int wynik = skladnikB / skladnikA; //Oblicz wynik
                    stos.Push(wynik);//Wstaw go na stos

                    break;
                }
                    //W przypadku potęgi, pobierz dwie poprzednie liczby ze stosu i podnieś do potęgi tą niżej na stosie
                case '^': {
                    int potega = stos.TopElem(); //Pobierz ze stosu element na samej górze
                    stos.Pop(); //Usuń go ze stosu

                    int podstawa = stos.TopElem(); //Pobierz ze stosu element na samej górze
                    stos.Pop(); //Usuń go ze stosu

                    int wynik = 1;  //Zmienna na wynik
                    while( potega > 0) { //Dopóki potega będzie większa od 0
                        wynik = wynik * podstawa; //rekurencyjnie wymnażaj
                        potega --; //odejmuj potęgę
                    }
                    stos.Push(wynik);//Wstaw go na stos

                    break;
                }

                case '~': {
                    int unarna = stos.TopElem(); //Pobierz ze stosu element na samej górze
                    stos.Pop(); //Usuń go ze stosu

                    int wynik = unarna * (-1);
                    stos.Push(wynik);//Wstaw go na stos

                    break;
                }

                    //Pomijaj wszystkie nieprzewidziane znaki
                default:
                    break;

            }
        }
    }
    cout << "Wynik równania wynosi " << stos.TopElem() << endl; //Wyświetl ostateczny wynik

    return 0;
}

