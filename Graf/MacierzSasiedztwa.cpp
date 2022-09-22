/* Mroz Kamil
        Graf za pomoca macierzy sasiedztwa
 */

#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <sstream>

using namespace std;
const int MAX = 100;    //Stala ktorej nie mozna przekroczyc

//Graf.h

class Graf
{
    //od razu musimy zadeklarować maksymalną ilość wierzchołków - tutaj 100;
    int matrix[MAX][MAX];                                               //Tworzymy macierz
    int numberOfVertices;               //Liczba wierzcholkow

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

private:
    void clear();                                                       //Czysci graf
};


//Okresla ile stworzy wierzcholkow
void Graf::createVertices(int ile) {
    if(ile < MAX) {             //czy nie przekracza dozwolonego rozmiaru
        numberOfVertices = ile;     //Przypisujemy tyle ile weszlo na wejsciu
    } else {
        throw out_of_range("Przekroczono maksymalna wartosc");      //Wyrzuc blad
    }
}

//Tworzy macierz o ustalony rozmiar
Graf::Graf() {
    for(int i = 0; i < numberOfVertices; i++ ) {
        for( int j = 0; j < numberOfVertices; i++) {
            matrix[i][j] = 0;                           //Wypelnij graf zerami do podanej wartosci
        }
    }
}

//Dodaje krawedz w macierzy pomiedzy wierzcholkami
void Graf::addEdge(int i_Vertex_Index_1, int i_Vertex_Index_2) {
    matrix[i_Vertex_Index_1][i_Vertex_Index_2] = 1;                 //macierz jest symetryczna
    matrix[i_Vertex_Index_2][i_Vertex_Index_1] = 1;                 //macierz jest symetryczna
}

//Usuwa krawedz w macierzy pomiedzy wierzcholkami
void Graf::removeEdge(int i_Vertex_Index_1, int i_Vertex_Index_2) {
    matrix[i_Vertex_Index_1][i_Vertex_Index_2] = 0;                 //macierz jest symetryczna
    matrix[i_Vertex_Index_2][i_Vertex_Index_1] = 0;                 //macierz jest symetryczna
}
//Sprawdza czy istnieje krawedz w macierzy pomiedzy wierzcholkami
int Graf::checkEdge(int i_Vertex_Index_1, int i_Vertex_Index_2) {
    if (matrix[i_Vertex_Index_1][i_Vertex_Index_2] == 1 || matrix[i_Vertex_Index_1][i_Vertex_Index_2] == 1 ) {      //Jesli jest 1 oznaczajaca ze istnieje krawedz miedzy wierzcholkami
        cout << "Istnieje krawedz miedzy wierzcholkami  ";
        return 1;                                           //Istnieje
    } else {
        cout << "Nie istnieje krawedz miedzy wierzcholkami  ";
        return 0;                                           //Nie istnieje
    }
}


//Sprawdza stopien macierzy
int Graf::vertexDegree(int idx) {

    int stopien = 0;
    for (int i = 0; i < numberOfVertices; i++) {                //Iterujemy do zadanej wielkosci dla macierzy
        if (matrix[idx][i] == 1 && matrix[i][idx] == 1) {            //Ile razy wystapi jedynka oznaczajaca jedna krawedz
            stopien++;                                          //Zwiekszaj
        }
    }
    cout << "Stopien wierzcholka  " << idx << " wynosi ";
    return stopien;
}

//Zwraca wektor z sasiednimi wierzcholkami
vector<int> Graf::getNeighbourIndices(int idx) {

    vector<int> sasiednie;                          //Stworz wektor dla sasiadujacych wierzcholkow
    for (int i = 0; i < numberOfVertices; i++ ) {    //Iterujemy do zadanej wielkosci dla macierzy
        if(matrix[idx][i] == 1){                //Za kazdym razem kiedy istnieje miedzy krawedz z danego wierzcholka
            sasiednie.push_back(i);             //Wstaw do wektora
        }
    }
    return sasiednie;       //Zwroc wektor
}

//Wypisuje sasiednie wierzcholki
void Graf::printNeighbourIndices(int idx) {
    cout << "Sasiedzi wierzcholka " << idx << ":  ";
    for(int i = 0; i < numberOfVertices; i++) {             //Iterujemy po zadanej wielkosci macierzy
        if(matrix[idx][i] == 1){                        //Jesli istnieje krawedz z danego wierzcholka do wierzcholka w iteracji
            cout << i << ", ";                          //Wypisz ten wierzcholek
        }
    }
    cout << "\n";
}

//Sprawdza liczbe krawedzi w grafie
int Graf::getNumberOfEdges() {
        int krawedzie = 0;                              //Zmienna przechowujaca liczbe krawedzi w grafie
        for(int i = 0; i < numberOfVertices; i++ ) {
            for( int j = 0; j <= i; j++) {              //Sprawdzamy tylko po jednej stronie "symeetrii"
                if(matrix[i][j] == 1)
                    krawedzie++;                        //Zwiekszamy liczbe krawedzi
                }
            }
        cout << "Liczba krawedzi wynosi ";
    return krawedzie;
}

//Odzczytuje z pliku
void Graf::readFromFile(string path) {
    for(int i = 0 ;i < numberOfVertices; i++){
        for(int j=0;j < numberOfVertices;j++){
            matrix[i][j] = 0;                   //Ustawiamy wszystko na zero
        }
    }

    ifstream plik;                              //Otwieramy strumien pliku
    int liczbaWierzcholkow;                     //pierwsza odczytana z pliku wartosc
    plik.open(path);                            //Otwieramy plik o podanej sciezce
    plik >> liczbaWierzcholkow;                 //Przypisujemy pierwsza linie
    createVertices(liczbaWierzcholkow);         //Na jej podstawie tworzymy graf o podanym rozmiarze

    int v1, v2;                         //Na krawedzie miedzy wierzcholkami
    while(plik >> v1){                  //Dopoki odczytuje
        plik >> v2;                     //Odczytuj
        addEdge(v1,v2);                 //Dodawaj
    }
    plik.close();                       //Zamykamy strumien
}

//Czysci krawedzie
void Graf::clear() {
    for(int i = 0; i < numberOfVertices; i++ ) {
        for( int j = 0; j < numberOfVertices; i++) {
            matrix[i][j] = 0;               //Ustawia wszystkie "krawedzie" powrotnie na 0
        }
    }
}


//GrafMacierz.cpp

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
    G->readFromFile("Graf.txt");
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





