/* Mroz Kamil
        Graf za pomoca listy sasiedztwa
 */

#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <sstream>
#include <algorithm>

using namespace std;
const int MAX = 2000;       //Stala ktorej nie mozna przekroczyc

//Graf.h
class Graf
{
    vector<int> vertexList[MAX]; //tablica wektorow
    int numberOfVertices;        //Liczba wierzcholkow
public:
    Graf();
    void createVertices(int ile);                                       //Okresla ile stworzy wierzchoklow
    void addEdge(int i_Vertex_Index_1, int i_Vertex_Index_2);           //Dodaje krawedz miedzy wierzcholkami
    void removeEdge(int i_Vertex_Index_1, int i_Vertex_Index_2);        //Usuwa krawedz miedzy wierzcholkami
    int checkEdge(int i_Vertex_Index_1, int i_Vertex_Index_2);          //Czy istnieje wierzcholek
    int vertexDegree(int idx);                                          //Stopien wierzcholka
    vector<int> getNeighbourIndices(int idx);                           //Zapisuje siasiednie wierzcholki w wektorze
    void printNeighbourIndices(int idx);                                //Wypisuje siasiadow podanego wierzcholka
    int getNumberOfEdges();                                             //Wypisz liczbe wierzcholkow
    void readFromFile(string path);                                     //Czytanie z pliku
};

//Konstruktor grafu
Graf::Graf() {
    numberOfVertices = MAX; //W razie niepodania rozmiaru grafu, wybiera najwiekszy
}

//Okresla ile stworzy wierzchoklow
void Graf::createVertices(int ile) {
    if(ile < MAX) {             //Jesli nie przekroczy maksymalnego rozmiaru
        numberOfVertices = ile;     //Przypisujemy tyle ile weszlo na wejsciu
    } else {
        throw out_of_range("Przekroczono maksymalna wartosc");
    }
}


//Dodaje krawedz miedzy wierzcholkami
void Graf::addEdge(int i_Vertex_Index_1, int i_Vertex_Index_2){
    vertexList[i_Vertex_Index_1].push_back(i_Vertex_Index_2);               //Dodaje krawedz z wierzcholka a do b
    vertexList[i_Vertex_Index_2].push_back(i_Vertex_Index_1);               //Dodaje krawedz z wierzcholka b do a
}

//Usuwa krawedz miedzy wierzcholkami
void Graf::removeEdge(int i_Vertex_Index_1, int i_Vertex_Index_2) {
    //find z biblioteki algorithm, znajduje pierwsze wystapienie wartosci
    auto pozycjaA = find(vertexList[i_Vertex_Index_1].begin(),vertexList[i_Vertex_Index_1].end(),i_Vertex_Index_2);
    vertexList[i_Vertex_Index_1].erase(pozycjaA);       //Usuwa krawedz

    //find z biblioteki algorithm, znajduje pierwsze wystapienie wartosci
    auto pozycjaB = find(vertexList[i_Vertex_Index_2].begin(),vertexList[i_Vertex_Index_2].end(),i_Vertex_Index_1);
    vertexList[i_Vertex_Index_2].erase(pozycjaB);       //Usuwa krawedz
}

//Sprawdza czy istnieje krawedz miedzy wierzcholkami
int Graf::checkEdge(int i_Vertex_Index_1, int i_Vertex_Index_2) {
    for (int i = 0; i < vertexList[i_Vertex_Index_1].size(); i++) {         //iteruje po rozmiarze
        if (vertexList[i_Vertex_Index_1].at(i) == i_Vertex_Index_2) {       //jesli znalezlismy krawedz miedzy poszukiwanymi wierzcholkami w tablicy
            cout << "Istnieje krawedz miedzy wierzcholkami  ";
            return 1;
        }
    }
    cout << "Nie istnieje krawedz miedzy wierzcholkami  ";
    return 0;
}

//Stopien wierzcholka
int Graf::vertexDegree(int idx) {
    cout << "Stopien wierzcholka  " << idx << " wynosi ";
    return vertexList[idx].size();      //stopniem wierzcholka jest ilosc przechowywanych wierzchokow siasiednich czyli rozmiar wektora
}

//Zwraca siasiednie wierzcholki
vector<int> Graf::getNeighbourIndices(int idx) {
    return vertexList[idx];                             //Zwraca wektor
}

//Zwraca siasiednie wierzcholki
void Graf::printNeighbourIndices(int idx) {
    cout << "Sasiedzi wierzcholka " << idx << ":  ";
    for (int sasiad: vertexList[idx]) {             //iteruje po wektorze
        cout << sasiad << ", ";             //wypisuje po kolei jego zawartosc czyli wierzchoki polaczone z nim krawedziami
    }
    cout << "\n";
}

//Zwraca ilosc krawedzi
int Graf::getNumberOfEdges() {
    int krawedzie = 0;                  //Zmienna na krawedzie
    for (int i = 0; i < numberOfVertices; i++) {                //Iterujemy podanej mozliwej wielkosci
        krawedzie = krawedzie + vertexList[i].size();           //dodajemy dlugosc wektora majacego ilosc krawedzi dla kazdego wierzcholka
    }
    cout << "\nLiczba krawedzi wynosi ";
    return krawedzie/2;         //Dzielimy na dwa, bo kazdy wierzcholek majacy sasiada jest liczony w obu jako krawedz
}


//Odczytywanie z pliku
void Graf::readFromFile(string path) {

    ifstream plik;                              //Otwieramy strumien pliku
    int liczbaWierzcholkow;                     //pierwsza odczytana z pliku wartosc
    plik.open(path);                             //Otwieramy plik o podanej sciezce
    plik >> liczbaWierzcholkow;                 //Przypisujemy pierwsza linie
    createVertices(liczbaWierzcholkow);         //Na jej podstawie tworzymy graf o podanym rozmiarze

    int v1, v2;                         //Na krawedzie miedzy wierzcholkami
    while(plik >> v1){                  //Dopoki odczytuje
        plik >> v2;                     //Odczytuj
        addEdge(v1,v2);                 //Dodawaj
    }
    
    plik.close();                       //Zamykamy strumien
}

//GrafListaSasiedztwa.cpp

void test1()
{
    Graf* G = new Graf();
    G->createVertices(10);
    G->addEdge(1, 2);
    G->addEdge(2, 3);
    G->addEdge(1, 5);
    std::cout << G->vertexDegree(1)<<"\n";
    std::cout << G->vertexDegree(8) << "\n";
    G->printNeighbourIndices(1);
    std::cout << G->getNumberOfEdges() << "\n";
    std::cout << G->checkEdge(1, 2)<<"\n";
    G->removeEdge(1, 2);
    std::cout << G->getNumberOfEdges() << "\n";
    G->printNeighbourIndices(1);
    std::cout << G->checkEdge(1, 2) << "\n\n";
}


void test2()
{
    Graf* G = new Graf();
    G->readFromFile("Graf1.txt");
    std::cout << G->vertexDegree(1)<<"\n";
    std::cout << G->vertexDegree(8) << "\n";
    G->printNeighbourIndices(1);
    std::cout << G->getNumberOfEdges() << "\n";
}

int main()
{
    test1();
    test2();
}
