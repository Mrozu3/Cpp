#include <iostream>
#include <cstdio>
 
 //Definicje typow danych do listy jednokieruunkowej
typedef int elementtype;
struct celltype {

elementtype element;
celltype * next;

};

typedef celltype * position;
class Lista
{

protected:
position l; // wskaźnik do głowy listy

public:
Lista(); //konstruktor
~Lista(); //destruktor

void Insert(elementtype x, position p); //wstaw x na pozycję p na liście L
void Delete(position p);                //usuwa element na pozycji p z listy
elementtype Retrieve(position p);       //zwraca element występujący w L na pozycji p. 
position Locate(elementtype x);        //Zwraca pozycję pierwszego wystąpienia elementu x w liście L.
position First();                      //zwraca pozycję pierwszego elementu w L.
position Next(position p);             //zwraca pozycję następną w stosunku do p w L. 
position Previous(position p);         //zwraca pozycję następną w stosunku do p w L
position END();                         //Zwraca ostatni element listy
position MakeNull();                    //Czyni listę pustą i zwraca pozycję END(L).

};
 
//Tworzy glowe
Lista::Lista()
{
l = new celltype(); //przydziela pamiec obiektowi
l->next = NULL; //Wskazuje na NULL
}

//Czyni liste pusta 
Lista:: ~Lista() {} 

//Wstawia x na pozycje p na liscie L
void Lista:: Insert(elementtype x, position p){
position tmp = p->next; // zeby nie utracic elementu ktory wjest na pozycji p zapamietujemy jego adres
p->next = new celltype; // tworzymy nowy rekord do ktorego wstawimy wartosc x
p->next->element = x; // wstawiamy wartosc x do nowo utworzonego rekordu
p->next->next = tmp; //w polu next wstawiamy wskaznik do elementu wskazywanego przez tmp
}
 
//usuniecie elementu z pozycji p czyli usuniecie rekodu na ktory wskazuje p->next 
void Lista::Delete(position p)
{
position tmp = p->next; // zapamietujemy zeby nie utracic elementu ktory wystepuje na liscie na pozycji p
p->next = p->next->next; //  niech p->next wskazuje na rekord nastepny po tym ktory chcemy usunac
delete tmp; //Usuwamy wskazany rekorc
}
 
//Zwraca element na pozycji p 
elementtype Lista::Retrieve(position p)
{

//Jesli isnieje taki element
if (p->next != NULL) { 
return p->next->element;
}

}

//Zwraca pozycje elementu x w liscie czyli taka wartosc p, ze p->next->element=x
position Lista::Locate(elementtype x)
{
position tmp = l; //zapamietujemy poczatkowy element
while (tmp->next != NULL) //dopoki tmp nie wskazuje na ostatni element listy
{
if (tmp->next->element == x) { return tmp; } //Znalezlismy element wiec go zwracamy
tmp = tmp->next; //Przeskakujemy na nastepny rekord
}
return tmp; // zwracamy jesli wskazano ostatni element listy
 
}
 
//Zwraca pozycje pierwszego elementu w L
position Lista::First()
{
return l;
}

//Zwraca pozycje nastepnego elementu w stosunku do p
position Lista::Next(position p)
{
return p->next;
}

 //Zwraca poprzedni element  w stosunku do p
position Lista::Previous(position p)
{
position tmp = l;  //zapamietujemy poczatkowy element
while (tmp->next != p) // dopoki nasz element jest rozny od p
{
tmp = tmp->next; //przypisuj poprzedzajacy go element
}
return tmp; //Inaczej zwroc jedyny mozliwy element
 
 
}
 
//Nieefektywne poszukiwanie ostatniego elementu 
position Lista::END()
{
position p = l;  //zapamietujemy poczatkowy element   
while (p->next != NULL){  //dopoki P nie jest ostatnim elementem
p = p->next;     //zapisujemy obecny p
}
return p; // zwracamy zapisany ostatni element 
}

//Czyni liste pusta, zwaraca pozycje END(l)
position Lista::MakeNull()
{
if ((l!=NULL) && (l->next!=NULL)) //Dopoki pierwszy i poprzedzajacy nie sa puste
    {  
        while (l->next!=NULL) //Dopoki nastepny nie jest pusty
        { 
        position temp=l->next; //zapisujemy nastepny element
        l->next=temp->next; //przechodzimy do nastepnego elementu po poprzednim
        delete temp;    //usuwamy zapisany nastepny element
        }
    }
}

//Wyswietlanie listy
void print_list(Lista l){
position i = l.First();
while (i != l.END()) //Dopoki nie dotarlismy do konca listy 
{
std::cout << l.Retrieve(i) << std::endl; //Wyswietlaj elementy
//printf(" %d,", l.Retrieve(i));
i = l.Next(i); //I jest nasatepnym elementem
}
printf("\n");
 
}
 
//Glowna funkcja z testami
int main()
{
Lista l;

l.Insert(5,l.First());
std::cout << "wypisz pierwszy element" <<std::endl;
std::cout << l.Retrieve(l.First())<<std::endl;
l.Insert(2, l.First());
std::cout << "wypisz pierwszy element" <<std::endl;
std::cout <<  l.Retrieve(l.First())<<std::endl;
std::cout << "wypisz drugi element" <<std::endl;
std::cout <<  l.Retrieve(l.Next(l.First()))<<std::endl;
l.Insert(1, l.Next(l.First()));
std::cout << "wypisz pierwszy element" <<std::endl;
std::cout <<  l.Retrieve(l.First())<<std::endl;
std::cout << "wypisz drugi element" <<std::endl;
std::cout <<  l.Retrieve(l.Next(l.First()))<<std::endl;
std::cout << "wypisz trzeci element" <<std::endl;
std::cout <<  l.Retrieve(l.Next(l.Next(l.First())))<<std::endl;
std::cout << "Wypisujemy element przed-przedostatni" <<std::endl;
std::cout <<  l.Retrieve(l.Previous(l.Previous(l.END()))) <<std::endl;

std::cout << "\nWypisuje cala liste" <<std::endl;
print_list(l);

std::cout << "Procedura czyszczenia listy" <<std::endl;
l.MakeNull();

std::cout << "Wypisuje cala liste" <<std::endl;
print_list(l);


} 


int temp = p->element;
position temp2 = p->next->next;
p->next->next = new celltype;
p->next->next->element = temp;
p->next->next->next = temp2;
