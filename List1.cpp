#ifndef _HEADER_INCLUDED_
#include "List.h"
#define _HEADER_INCLUDED_
List::List(){
		head=nullptr;
		tail=nullptr;
	}
List::List(List& ob){
		   
	}
List::List(List&& ob){
	   
	}
List::~List(){
		Node* temp=head->next;
		while(temp!=tail){
			    head->next=temp->next;
				deleteNode(temp);
				temp=head->next;
			}
			deleteNode(head);
	}
void List::deleteNode(Node* a){
	    delete a;
	}
bool List::isSame(int x){
	Node* temp=head;
		while(temp!=tail){
				if(temp->value=x){
						return true;
						break;
					}
				temp=temp->next;
			}
		return false;
	}
List& List::operator +=(int x){
		Node* temp;
		if(head==nullptr){
				head->value=x;
				head->next=tail;
			}
		else{
			if(isSame(x)!=true){
				temp=tail;
				tail=new Node();
				temp->value=x;
				temp->next=tail;
			}
		}
	}		
#endif
