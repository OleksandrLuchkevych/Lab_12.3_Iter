#include <iostream>

using namespace std;


typedef int Info;
struct Elem
{
	Elem* next,
		* prev;
	Info info;
};

Elem* first = NULL,
* last = NULL;

void Add(Elem*& first, Elem*& last, Info value)
{
	Elem* tmp = new Elem;
	tmp->info = value;
	tmp->next = NULL;
	if (last != NULL)
		last->next = tmp; 
	tmp->prev = last;
	last = tmp;
	if (first == NULL)
		first = tmp;
}

void PrintList(Elem*& first)
{
	Elem* current = first;
	while (current != NULL)
	{
		cout << current->info << " ";
		current = current->next;
	}
	cout << endl;
}

void Replace(Elem*& first)
{
	Elem* temp = NULL;
	Elem* tmp = first;

	while (tmp != NULL)
	{
		temp = tmp->prev;
		tmp->prev = tmp->next;
		tmp->next = temp;
		tmp = tmp->prev;
	}

	if (temp != NULL)
		first = temp->prev;

}

int main()
{
	Elem* first = NULL,
		* last = NULL;
	Add(first, last, 1);
	Add(first, last, 2);
	Add(first, last, 5);
	Add(first, last, 4);
	Add(first, last, 3);
	Add(first, last, 1);

	cout << "Initial list: ";
	PrintList(first);
	cout << endl;
	cout << "Replaced list: ";
	Replace(first);
	PrintList(first);

}
