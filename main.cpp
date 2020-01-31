#include <iostream>
#include "List1.h"

int main(){
	List listok;
	listok+=5;
	listok+=1;
	listok+=10;
	std::cout<<listok<<std::endl;
	List obj(listok);
	std::cout<<obj<<std::endl;
	return 0;
}
