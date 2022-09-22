#include "ListaTablicowa.cpp"
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
printf("Wstawiam 1 element listy\n");
Insert(100,First(l),l);
print (l);

printf("Wstawiam 3 elementy listy na poczatek\n");
for (int i=0; i<3;i++)
Insert(i,First(l),l);
print (l);

printf("Wstawiam 1 elementy do listy jako przedostatni element\n");
Insert (20,Previous(END(l),l) ,l);
print(l);

printf("Usuwam element zlokalizowany\n");
Delete( Locate(20,l),l);
print(l);

printf("Czyszcze liste\n");
MakeNull(l);
print(l);

}
