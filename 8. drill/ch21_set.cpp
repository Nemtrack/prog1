#include <iostream>
#include <stdexcept>
#include <string>
#include <vector>
#include <set>

struct Fruit{
	std::string name;
	int quantity;
	double unit_price;

	Fruit(const std::string& n, int q = 0, double p = 0.0): name{n}, quantity{q}, unit_price{p}{}
};

struct Fruit_cmp_ptr{
	bool operator()(const Fruit* a, const Fruit* b){
		//lexikografikus sorbarendezés (abc)
		return a-> name < b->name;
		//return a -> quantity < b->quantity;
	}
};

int main()
try{
	std::vector<Fruit> vf{
		Fruit{"Plum", 3},
		Fruit{"Grape", 32},
		Fruit{"Banana", 11},
		Fruit{"Apple", 98},
		Fruit{"Orange", 75},
		Fruit{"Cherry", 47},
		Fruit{"Plum", 33},
		Fruit{"Kiwi", 29}
	};

	std::cout << "Vector values:" << std::endl;
	for(const auto& f : vf){
		std::cout << f.name << std::endl;
	}
	std::cout << std::endl;

	std::set<Fruit*, Fruit_cmp_ptr> sf;
	for(auto& f : vf){
		sf.insert(&f);
	}

	std::cout << "Set values:" << std::endl;
	for(const auto& f : sf){
		std::cout << f->name << std::endl;
	}
	std::cout << std::endl;

} catch(std::exception& e){
	std::cerr << e.what() << '\n';
	return 1;
} catch(...){
	std::cerr << "Unknown exception!" << '\n';
	return 2;
}
