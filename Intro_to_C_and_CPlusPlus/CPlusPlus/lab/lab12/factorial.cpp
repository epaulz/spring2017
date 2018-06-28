#include <iostream>

int fact(int n){
	//base case
	if(n == 1){
		return 1;
	}

	//recursive case
	else{
		return n * fact(n-1);
	}
}

int main(){
	int usr_num;

	std::cout << "Enter a number: ";
	std::cin >> usr_num;

	int factorial = fact(usr_num);

	std::cout << "The factorial of " << usr_num << " is ";
	std::cout << factorial << "!\n";

	return 0;
}