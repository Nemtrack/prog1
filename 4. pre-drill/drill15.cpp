#include <iostream>

/*
		[] lambda introducer
		() argument list
		{} function body

		[] captures nothing
		[&]captures all by reference
		[=]captures all by value
		[&A, =B] A by reference, B by value
		[=, &A] A by reference, all other by value


*/
int main(){
	[](){
			std::cout << "Hello C++ lambda" << std::endl;
	}

	();

	auto sum = [](double A, double B) {return A + B;};

	auto add = sum;

	std::cout << add(3.25, 5.65) << std::endl;

	auto add2 = [](double A, double B) -> double{return A+B;};
	std::cout << add2(3.25, 5.65) << std::endl;

	double pi = 3.1416;

	auto func = [&pi](double inc){
		std::cout << "The value of pi is " << pi+inc << std::endl;
		pi+=inc;
	};

	func(2);
	std::cout << "The value of pi is " << pi << std::endl;

	auto gene_lambda = [](auto arg) {return arg+arg;};

	std::cout << gene_lambda(5) << std::endl;
	std::cout << gene_lambda(3.1416) << std::endl;

}