#include <iostream>

using namespace std;

struct Node
{
public:
	int data;
	struct Node* next;
};

class linkedList
{
private:
	struct Node* head;
public:
	linkedList()
	{
		head = nullptr;
	}
	void insertAtLast(int data);
	void printAll();
	void printMiddle();
};
void linkedList::insertAtLast(int data)
{
	struct Node* newNode = new Node;
	newNode->data = data;
	newNode->next = nullptr;
	if (head == nullptr)
	{
		head = newNode;
	}
	else
	{
		struct Node* tail = head;
		while (tail->next != nullptr)
		{
			tail = tail->next;
		}
		tail->next = newNode;
	}
}

void linkedList::printAll()
{
	struct Node* tail = head;
	if (tail == nullptr)
	{
		cout << "No data in the list";
	}
	else
	{
		while (tail != nullptr)
		{
			cout << tail->data << "\n";
			tail = tail->next;
		}
	}
}

void linkedList::printMiddle()
{
	struct Node* tail, * middle;
	tail = head;
	if (tail == nullptr)
	{
		cout << "No data in the list!";
	}
	else
	{
		middle = tail;
		while (tail->next != nullptr)
		{
			tail = tail->next->next;
			middle = middle->next;
		}
		cout << "Middle:" << middle->data;
	}
}

int main()
{
	linkedList* list = new linkedList;
	list->insertAtLast(1);
	list->insertAtLast(2);
	list->insertAtLast(3);
	list->printAll();
	list->printMiddle();

	delete list;
	return 0;
}