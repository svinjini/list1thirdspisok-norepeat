#ifndef _HEADER_INCLUDED_
#include "List1.h"
#define _HEADER_INCLUDED_
List::List(){
		head=nullptr;
		tail=nullptr;
	}
List::List(const List& ob){
           Node* element=new Node();
	       Node* current=ob.head;
	       Node* temp;
	       element->value=current->value;
		   while(current!=ob.tail){
			        temp=new Node();
			        temp->value=current->value;
			        element->next=temp;
			        element=temp;
			        current=current->next;
			   }
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
bool proverka(List& ob){
		if(ob.head==nullptr){
				return false;
			}
		else{
				return true;
			}
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
List& operator |(List& ob, List& ob1){}
List& List::operator +=(int x){
		Node* temp;
		Node* current;
		if(head==nullptr){
				head->value=x;
				head->next=tail;
			}
		else{
			if(isSame(x)!=true){
				temp=head;
				head=new Node();
				head->value=x;
				head->next=temp;
				current=head;
				int k;
				while((current->next!=tail)&&(current->value>current->next->value)){
						k=current->next->value;
						current->next->value=current->value;
						current->value=k;
						current=current->next;
					}
			}
		}
	}
std::ostream & operator <<(std::ostream& out, List& ob){
		List::Node* temp=ob.head;
		while(temp!=ob.tail){
			out<<temp->value<<std::endl;
			temp=temp->next;
		}
		return out;
	}	
#endif
