// Bikram Kohli (bsk4uaa)
// List.cpp

#include <iostream>
#include "List.h"
using namespace std;

List::List() {
	head = new ListNode();
	tail = new ListNode();
	count = 0;
	head -> next = tail;
	tail -> previous = head;
}

// Copy constructor
// Called when the code looks something like List list2 = list1;
// (In other words, it is called when you are trying to construct a **new** list from an existing one)
List::List(const List& source) {
    head=new ListNode();
    tail=new ListNode();
    head->next=tail;
    tail->previous=head;
    count=0;
    // Make a deep copy of the list
    ListItr iter(source.head->next);
    while (!iter.isPastEnd()) {
        insertAtTail(iter.retrieve());
        iter.moveForward();
    }
}

List::~List() {
    makeEmpty();    // gets rid of all listnodes besides head and tail
    delete head;
    delete tail;


}

// Copy assignment operator
// Called when the code looks something like list2 = list1;
// (In other words, it is called when you are trying to set an **existing** list equal to another one)
List& List::operator=(const List& source) {
    cout << "test 0";
    if (this == &source) {
        // The two are the same list; no need to do anything
        return *this;
    } else {
        cout << "test";
        // Clear out anything this list contained
        // before copying over the items from the other list
        makeEmpty();

        // Make a deep copy of the list
        ListItr iter(source.head->next);
        while (!iter.isPastEnd()) {
            insertAtTail(iter.retrieve());
            iter.moveForward();
        }
    }
    return *this;
}

bool List::isEmpty() const{
	return count == 0;
}

void List::makeEmpty() {
    while(count != 0) 
    {
        remove(first().retrieve());
    }
}

ListItr List::first() {
	return ListItr(head -> next);
}

ListItr List::last() {
	return ListItr(tail -> previous);
}

void List::insertAfter(int x, ListItr position) {
    ListNode* ln = new ListNode(x);
    ListNode* temp = position.current -> next;

    ln -> previous = position.current;
    ln -> next = temp;

    position.current -> next = ln;
    temp -> previous = ln;

    count++;
}

void List::insertBefore(int x, ListItr position) {
    ListNode* ln = new ListNode(x);
    ListNode* temp = position.current -> previous;

    ln -> previous = temp;
    ln -> next = position.current;

    position.current -> previous = ln;
    temp -> next = ln;

    count++;
}

void List::insertAtTail(int x) {
	ListNode* ln = new ListNode(x);
	ListNode* temp = tail -> previous;
	ln -> previous = temp;
	ln -> next = tail;
	tail -> previous = ln;
	temp -> next = ln;

	count++;
}

ListItr List::find(int x) {
    ListItr* li = new ListItr(head -> next);
    while (li -> current -> value != x && !li -> isPastEnd()) {
        li -> moveForward();
    }

    return *li;
}

void List::remove(int x) {
    ListItr* li = new ListItr(head -> next);
    while (li -> current -> value != x && !li -> isPastEnd()) {
        li -> moveForward();
    }

    if(li -> current != tail) {
        ListNode* temp1 = li -> current -> previous;
        ListNode* temp2 = li -> current -> next;

        temp1 -> next = temp2;
        temp2 -> previous = temp1;

        count--;
    }
    delete li;
}

void List::removeAtTail(int x) {
    ListItr* li = new ListItr(tail -> previous);
    while (li -> current -> value != x && !li -> isPastBeginning()) {
        li -> moveBackward();
    }

    if (li -> current != head) {
        ListNode* temp1 = li -> current -> previous;
        ListNode* temp2 = li -> current -> next;

        temp1 -> next = temp2;
        temp2 -> previous = temp1;

        count--;
    }
}

int List::size() const {
	return count;
}

void printList(List& source, bool forward) {
	if (forward) {
        ListItr* li = new ListItr(source.first());

		while (li -> retrieve()) {
			cout << li -> retrieve() << " ";
			li -> moveForward();
		}
        delete li;
	}

    else {
        ListItr* li = new ListItr(source.last());

        while (li -> retrieve()) {
            cout << li -> retrieve() << " ";
            li -> moveBackward();
        }
        delete li;
    }
}
