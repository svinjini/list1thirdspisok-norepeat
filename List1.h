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
		List(List ob);
		List(List&& ob);
		~List();
		void deleteNode;
		bool isSame(int x);
		List& operator +=(int x);
		friend std::ostream &operator <<(const std::ostream& out, List& ob);
		friend List& operator |(List& ob);
};
