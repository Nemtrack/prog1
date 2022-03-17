#include <iostream>
#include <cmath>

int absolute(int val){
	std::cout << "parameter value: " << val << std::endl; //side-effect
	return abs(val);
}

int main(){

	std::cout << "Absolute value of 0.025: " << abs(0.025) << std::endl;
	std::cout << "Absolute value of 0.025: " << absolute(25) << std::endl;

}