#include <iostream>
#include <functional>

int sum(int x, int y){
	return x+y;
}

class Add{
public:
	int operator() (int x, int y) const{
		return x+y;
	}
};

struct add_x {
	add_x(int val) : x(val) {}
	//add_x(int val) { x = val;}
	int operator()(int y) const {return x+y;}
	void operator << (int y) { x += y;}
	void operator >> (int y) { x += y;}
	void operator- (int y) { x += y;}


private:
	int x;
};

int main(){

	add_x add42(42);
	int i = add42(8);

	std::cout << i << std::endl;

	std::function<int(int,int)> func;

	func = sum;

	std::cout << func(5,7) << std::endl;

	std::function<double(double,double)> sum = [](double A, double B) -> double {return A+B;};

	std::cout << sum(4.6, 5.9) << std::endl;
}