/* Zadanie 1 Mroz Kamil

Zaimplementuj podstawowe operacje na liście
w reprezentacji tablicowej (plik ListaTablicowa.cpp)
Przetestuj korzystając z testu w pliku ListaTest.cpp ( test z ListyTest.cpp wstawiony na dole kodu aby mozna bylo odpalic z jednego pliku)

g++ -c ListaTablicowa.cpp
g++ -o ListaTablicowa ListaTablicowa.o

*/

//potrzebne bibiloteki
#include<iostream>

//Nadajemy nazwe istniejacemu typowi
typedef int elementtype, position;
//Dlugosc listy
const int maxlength =  10;
//Zmienna zasugerowana do funkcji Retrieve z zakresu ktory raczej u nas nie wystapi
const long int min = -100000;
 
//Definiujemy strukture
struct List
{
	elementtype elements[maxlength];
	int last;           //indeks ostatniego elementu listy
};


//zwraca pozycję elementu pierwszego ( idneks 0 )
position First(List l) 
{
    return 0;
}

//zwraca pozycję za ostatnim elementem (czyli last+1)
position END(List l)
{ 
    return l.last + 1;         
}


//zwraca indeks następnego elementu po p (czyli p+1):
position Next(position p,List l)
{
    //jeśli nie istnieje element następny lub wychodzi poza zakres ( ponizej 0), to zwróć -1
    if( p < 0  || p > l.last  ) {
        return -1;                          
    } else { 
        //jeśli istnieje element następny, to zwróć jego indeks
        return p+1;                                                   
    }
}


//zwraca indeks poprzedniego elementu w stosunku do p (czyli p-1)
position Previous(position p,List l) 
{
    //jesli element wychodzi poza wielkosc i zakres listy zwroc -1
    if( p < 0 || p > END(l) ) {
        return -1;
    } else {
        //jeśli istnieje element poprzedni, to zwróć jego indeks
        return p-1;
    }
}



//zwraca pozycje x w l, gdy nie ma x w l zwraca end(l)
position Locate(elementtype x, List l) 
{ //przeszukujemy l
     for ( int i = 0; i<END(l); i++) {
          { if( l.elements[i] == x) return i; }//Jesli znajdziemy x
        }  
         return END(l);  //Zwracamy pozycje za ostatnim elementem gdy x nie wystepuje w tablicy
     
}


// zwraca element znajdujący się w liście na pozycji p(w komórce p), jeśli pozycja p jest poprawna
elementtype Retrieve(position p, List l) 
{
        //jesli element wychodzi poza wielkosc i zakres listy zwroc -1
    if( p < 0 || p > l.last ) {
         return min;
    } else  {
        return l.elements[p];
    }
}


//wstawia x do komórki o numerze p ( o ile się da)
bool Insert(int x, position p, List &l)
{
    //Jesli element wychodzi poza wielkosc i zakres ( ponizej 0 ) listy zwroc falsz
    if( p < 0 || p > END(l)) { return false; } //Jesli sie nie powiodlo 
    //Jesli komorka jest na koncu tablicy
    if( p == END(l)) { 
        l.elements[p] = x; //wstawiamy element na ostatnie miejsce w tablicy
        l.last = l.last+1; //zwiekszamy indeks ostatniego miejsca w tablicy
        return true;        //Jesli sie powiodlo
        }
    //Jesli komorka nie jest osatnim elementem
    if( p < END(l) ) {
            //Przemieszczamy elementy w tablicy aby komorka p byla pusta
            for( position k = END(l); k > p; k-- ) {
                l.elements[k] = l.elements[k-1];
            }
            
            l.elements[p] = x;          //Wstawiamy x do komorki p
            l.last = l.last + 1;       //Zwiekszamy last
            return true;                 //Jesli sie powiodlo
        }
        return false;      //Jesli sie nie powiodlo 
}


//usuwa element z komórki o numerze p:
bool Delete(position p, List &l)
{
    //Czy komorka jest poprawna
    if( p < 0 || p > END(l)) { return false; } //Jesli sie nie powiodlo 

    //Dopoki komorka p jest mniejsza od osatniej pozycji -1
    while (p<END(l) - 1) {
        l.elements[p] = l.elements[p+1]; //przesuwamy elementy usuwajac tym samym jeden przez nas wybrany
        p++; // zwiekszamy p 
    }
    l.last--;  // zmniejszamy indeks ostatniego elementu
}

//Czyni liste pusta
position MakeNull(List &l) {

//Nasz ostatni element to -1, lista nie ma indeksow
l.last = -1; 

}

//ListaTest.cpp
void print(List l)
{
	position i=First(l);
	while (i!=END(l))
	{
		printf ("  %d,", Retrieve(i,l));
		i=Next(i,l);
	}
	printf("\n");

}

int main() {
List l;
l.last=-1;
Insert(100,First(l),l);
print (l);

for (int i=0; i<3;i++)
Insert(i,First(l),l);
print (l);

Insert (20,Previous(END(l),l) ,l);
print(l);
Delete( Locate(20,l),l);
print(l);
Insert(5,Previous(Locate(2,l),l),l);
print(l);
MakeNull(l); //Dodany test MakeNull
print(l);
}