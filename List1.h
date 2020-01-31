#include <iostream>


class List{
	public:
		struct Node{
				Node* next;
				int value;
				Node(){
						next=nullptr;
						value=0;
					}
		};
		Node* head;
		Node* tail;
		List();
		List(const List& ob);
		List(List&& ob);
		~List();
		friend bool proverka(List& ob);
		void deleteNode(Node* a);
		bool isSame(int x);
		List& operator +=(int x);
		friend std::ostream &operator <<(std::ostream& out, List& ob);
		friend List& operator |(List& ob, List& ob1);
};
