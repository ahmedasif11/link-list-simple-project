#include <iostream>
using namespace std;

class Node
{
public:
	int data;
	Node* next;
};

Node* insertAtBeginning(Node* head, int newData)
{
	Node* newNode = new Node();
	newNode->data = newData;
	newNode->next = head;
	return newNode;
}

Node* insertAtEnd(Node* head, int newData)
{
	Node* newNode = new Node;
	newNode->data = newData;
	newNode->next = nullptr;

	if (head == nullptr)
	{
		return newNode;
	}

	Node* current = head;
	while (current->next != nullptr)
	{
		current = current->next;
	}

	current->next = newNode;

	return head;
}

Node* deleteNode(Node* head, int target)
{
	if (head == nullptr)
	{
		return nullptr;
	}

	if (head->data == target)
	{
		Node* temp = head;
		head = head->next;
		delete temp;
		return head;

	}

	Node* current = head;
	while (current->next != nullptr && current->next->data != target)
	{
		current = current->next;
	}

	if (current->next != nullptr)
	{
		Node* temp = current->next;
		current->next = current->next->next;
		delete temp;
	}

	return head;
}

bool search(Node* head, int target)
{
	Node* current = head;

	while (current != nullptr)
	{
		if (current->data == target)
		{
			return true;
		}
		current = current->next;
	}
	return false;
}

void viewList(Node* head)
{
	Node* current = head;
	while (current != nullptr)
	{
		cout << current->data << " ";
		current = current->next;
	}
	cout << endl;
}

int sumList(Node* head)
{
	Node* current = head;
	int sum = 0;
	while (current != nullptr)
	{
		sum += current->data;
		current = current->next;
	}
	return sum;
}

int main()
{
	Node* head = nullptr;
	int choice;
	int element;
	while (true) {
		cout << "1. Enter element at the beginning: " << endl
			<< "2. Enter element at the end: " << endl
			<< "3. Delete element: " << endl
			<< "4. For view list: " << endl
			<< "5. For sum of link list: " << endl
			<< "6 .For search for element: " << endl
			<< "7. Exit: " << endl;
		cin >> choice;

		if (choice == 1) {
			cout << "Enter the element to insert at the beginning: " << endl;
			cin >> element;
			head = insertAtBeginning(head, element);
		}

		else if (choice == 2) {
			cout << "Enter the element to insert at the end: " << endl;
			cin >> element;
			head = insertAtEnd(head, element);
		}

		else if (choice == 3) {
			cout << "Enter the element which you want to delete: " << endl;
			cin >> element;
			bool isPresent = search(head, element);
			if (isPresent == true) {
				head = deleteNode(head, element);
				cout << "Element deleted" << endl;
			}
			else {
				cout << "Entered element is not present is the list: " << endl;
			}
		}

		else if (choice == 4) {
			viewList(head);
		}

		else if (choice == 5)
		{
			int sum = sumList(head);
			cout << "The sum is: " << sum << endl;
		}

		else if (choice == 6)
		{
			cout << "Enter the element which you want to search: " << endl;
			cin >> element;
			bool isPresent = search(head, element);
			(isPresent == true) ? cout << "Element is present" << endl : cout << "Element is not present" << endl;
		}

		else
		{
			cout << "Thanks for using" << endl;
			return 0;
		}

	}
		return 0;
}
