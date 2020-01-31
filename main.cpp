#include <iostream>
#include "List1.h"

int main(){
	List listok;
	listok+=5;
	listok+=1;
	listok+=10;
	std::cout<<listok<<std::endl;
	List copy ;
	copy=listok;
	List copy1(listok);
	std::cout << copy << std::endl;
	std::cout << copy1 << std::endl;
	return 0;
}
