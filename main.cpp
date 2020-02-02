#include <iostream>
#include "List1.h"

int main(){
	List first;
	first+=5;
	first+=1;
	first+=10;
	std::cout<<first<<std::endl;
	List copy ;
	copy=first;
	List copy1(first);
	std::cout << copy << std::endl;
	std::cout << copy1 << std::endl;
	List second;
	second+=6;
	second+=5;
	second+=12;
	std::cout<<second<<std::endl;
	List third;
	third=(second|first);
	std::cout<<third<<std::endl;
	return 0;
}
