#ifndef _HEADER_INCLUDED_
#include "List1.h"
#define _HEADER_INCLUDED_

#include <iostream>

List::List() {
	head = nullptr;
	tail = nullptr;
	count = 0;
	std::cout << "ctor" << std::endl;
}
List::List(const List& obj) {
	head = new Node();
	head->value = obj.head->value;
	Node* currentObjElement;
	currentObjElement = obj.head->next;
	Node* currentElement;
	currentElement = head;
	while (currentObjElement != NULL)
	{
		Node* Element = new Node();
		Element->value = currentObjElement->value;
		currentElement->next = Element;
		currentElement = currentElement->next;
		currentObjElement = currentObjElement->next;
	}
	count = obj.count;
}
List::List(List&& ob) {

}
List& List::getCopy(const List& obj) {
	deleteList();
	if (obj.head == NULL)
		return *this;
	head = new Node();
	head->value = obj.head->value;
	Node* currentObjElement;
	currentObjElement = obj.head->next;
	Node* currentElement;
	currentElement = head;
	while (currentObjElement != NULL)
	{
		Node* Element = new Node();
		Element->value = currentObjElement->value;
		currentElement->next = Element;
		currentElement = currentElement->next;
		currentObjElement = currentObjElement->next;
	}
	count = obj.count;
	return *this;
}
List& List::operator =(List& obj) {
	deleteList();
	if (obj.head == NULL)
		return *this;
	head = new Node();
	head->value = obj.head->value;
	Node* currentObjElement;
	currentObjElement = obj.head->next;
	Node* currentElement;
	currentElement = head;
	while (currentObjElement != NULL)
	{
		Node* Element = new Node();
		Element->value = currentObjElement->value;
		currentElement->next = Element;
		currentElement = currentElement->next;
		currentObjElement = currentObjElement->next;
	}
	count = obj.count;
	return *this;
}
List::~List() {
	deleteList();
}
int& List::operator [](int index) {
	Node* current = head;
	if (index>count) {
		std::cout << "ERROR" << std::endl;
		exit(0);
	}
	for (int i = 0; i<index; ++i) {
		current = current->next;
	}
	return current->value;
}
bool proverka(List& ob) {
	if (ob.head == nullptr) {
		return false;
	}
	else {
		return true;
	}
}
void List::deleteList() {
	Node* temp;
	while (head != NULL) {
		temp = head->next;
		deleteNode(head);
		head = temp;
	}
	count = 0;
}
void List::deleteNode(Node* a) {
	delete a;
}
bool List::isSame(int x) {
	Node* temp = head;
	while (temp->next!=tail) {
		if (temp->value == x) {
			return true;
			break;
		}
		temp = temp->next;
	}
	return false;
}
List& operator |(List& ob, List& ob1) {
	int x;
	int k;
	List::Node* temp;
	List *listok = new List();
	List::Node* current = ob.head;
	List::Node* current1;
	listok->head = new List::Node();
	listok->tail = new List::Node();
	listok->head->value = current->value;
	listok->head->next = listok->tail;
	listok->count++;
	current = current->next;
	while (current !=ob.tail) {
		k = current->value;
		if (listok->isSame(k) != true) {
			temp = listok->head;
			listok->head = new List::Node();
			listok->head->next = temp;
			listok->head->value = current->value;
			current1 = listok->head;
			while ((current1->next!=listok->tail) && (current1->value>current1->next->value)) {
				x = current1->next->value;
				current1->next->value = current1->value;
				current1->value = x;
				current1 = current1->next;
			}
			listok->count++;
		}
		current = current->next;
	}
	current = ob1.head;
	while (current != ob1.tail) {
		k = current->value;
		if (listok->isSame(k) != true) {
			temp = listok->head;
			listok->head = new List::Node();
			listok->head->next = temp;
			listok->head->value = current->value;
			current1 = listok->head;
			while ((current1->next != listok->tail) && (current1->value>current1->next->value)) {
				x = current1->next->value;
				current1->next->value = current1->value;
				current1->value = x;
				current1 = current1->next;
			}
			listok->count++;
		}
		current = current->next;
	}
	return *listok;
}
List& List::operator +=(int x) {
	Node* temp;
	int k;
	Node* current;
	if (head==nullptr) {
		head = new Node();
		tail = new Node();
		head->value = x;
		head->next = tail;
		count++;
	}
	else {
		if (isSame(x) != true) {
			temp = head;
			head = new Node();
			head->value = x;
			head->next = temp;
			current = head;
			count++;
			while ((current->next != tail) && (current->value>current->next->value)) {
				k = current->next->value;
				current->next->value = current->value;
				current->value = k;
				current = current->next;
			}
		}
	}
	return *this;
}
std::ostream & operator <<(std::ostream& out, List& ob) {
	List::Node* temp = ob.head;
	for (int i = 0; i < ob.count; ++i) {
		out << temp->value << std::endl;
		temp = temp->next;
	}
	return out;
}
#endif
