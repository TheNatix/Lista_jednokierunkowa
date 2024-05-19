#include <iostream>

using namespace std;

struct element { //Struktura elementu z ktorego sklada sie nasza lista
	int data;
	struct element* nextElement;
};

void pushFront(element** head, int number) //Dodanie elementu na przod naszej listu przez przpisanie do next element head i pozniej go zastapienie
{
	element* currentElement = new element;
	currentElement->data = number;
	currentElement->nextElement = (*head);
	*head = currentElement;
}

void pushBack(element** head, int number) { //Dodanie elementu na koniec listy w zaleznosci czy head jest pusty jesli nie to przechodzimy do czasu az next element jest nullem
	if (*head == NULL) {
		*head = new element;
		(*head)->data = number;
		(*head)->nextElement = NULL;
	}
	else
	{
		element* currentElement = *head;
		while (currentElement->nextElement!=NULL)
		{
			currentElement = currentElement->nextElement;
		}
		currentElement->nextElement = new element;
		currentElement->nextElement->data = number;
		currentElement->nextElement->nextElement = NULL;
	}
}

void showList(element* head) { //Tak jak poywej przechodzimy az next element jest nullem i wyswietlamy data jaka jest w tym miejscu listy
	cout << endl;
	if (head == NULL) cout << "Lista jest pusta\n";
	else
	{
		element* currentElement = head;
		do
		{
			cout << currentElement->data << " ";
			currentElement = currentElement->nextElement;
		} while (currentElement!=NULL);
		cout << endl << endl;;
	}
}

int listSize(element* head) { //Jak wyzej tylko nie wysieltlamy a liczymy ilosc elementow w naszej liscie
	int counter = 0;
	if (head == NULL) return 0;
	else
	{
		element* currentElement = head;
		do
		{
			counter++;
			currentElement = currentElement->nextElement;
		} while (currentElement != NULL);
		cout << endl;
	}
	return counter;
}

void pushByIndex(element** head, int number, int index) { //przechodzimyy przez petle az bedziemy na elemencie index - 1 i wstawiamy pomiedzy elementy i nadpisujemy wskazniki
	if (index == 0) pushFront(head, number);
	else
	{
		if (index == listSize(*head)) pushBack(head, number);
		else
		{
			element* currentElement = *head;
			element* tmp;
			int i = 0;
			while (currentElement->nextElement != NULL && i < index - 1)
			{
				currentElement = currentElement->nextElement;
				i++;
			}
			tmp = currentElement->nextElement;
			currentElement->nextElement = new element;
			currentElement->nextElement->data = number;
			currentElement->nextElement->nextElement = tmp;
		}
	}
}

void popFront(element** head) { // pobiera next element z heada usuwa go i ustawia next elemenent jako head
	element* tmp = NULL;
	if (*head != NULL) {
		tmp = (*head)->nextElement;
		delete* head;
		*head = tmp;
	}
}

void popBack(element** head) { //petla przechodzi przez az next element-> next element jest null wtedy go usuwa i ustawia next element na null
	if (*head!=NULL)
	{
		if ((*head)->nextElement == NULL) *head = NULL;
		else
		{
			element* currentElement = *head;
			while (currentElement->nextElement->nextElement != NULL)
			{
				currentElement = currentElement->nextElement;
			}delete currentElement->nextElement;
			currentElement->nextElement = NULL;
		}
	}
}

void popByIndex(element** head, int index) { // petla przechodzi do moementu index - 1 i wtedy nadpisuje dla elemenu przed zeby wskazywal na nastepny po tym elemencie ktory usuwamy 
	if (index == 0)
	{
		popFront(head);
	}
	else
	{
		element* currentElement = *head;
		element* tmp;
		int i = 0;
		while (currentElement->nextElement != NULL && i < index - 1) {
			currentElement = currentElement->nextElement;
			i++;
		}
		tmp = currentElement->nextElement;
		currentElement->nextElement = tmp->nextElement;
		delete tmp;
	}
}

int main() {
	element* head = NULL;
	int wybor, number, index;

	while (true) {
		cout << "Elements in list:";
		showList(head);
		cout << endl;
		cout << "1. Push an item to the head of the list.\n";
		cout << "2. Push an item to the tail of the list.\n";
		cout << "3. Push an item to the specific index of the list.\n";
		cout << "4. Pop an item from the head of the list.\n";
		cout << "5. Pop an item from the tail of the list.\n";
		cout << "6. Pop an item from the specific index of the list.\n";
		cout << "0. Close the program.\n";
		cin >> wybor;
		switch (wybor)
		{
		case 1:
			cout << "Number : ";
			cin >> number;
			pushFront(&head, number);
			break;
		case 2:
			cout << "Number : ";
			cin >> number;
			pushBack(&head, number);
			break;
		case 3:
			cout << "Number : ";
			cin >> number;
			cout << "Index : ";
			cin >> index;
			pushByIndex(&head, number,index);
			break;
		case 4:
			popFront(&head);
			break;
		case 5:
			popBack(&head);
			break;
		case 6:
			cout << "Index : ";
			cin >> index;
			popByIndex(&head, index);
			break;
		case 0:
			return 0;
			break;
		default:
			break;
		}
		cout << endl;
	}
	return 0;
}