#include <iostream>
#include <stdexcept>
#include <list>
#include <array>
#include <string>
#include <vector>

using namespace std;

template <typename C>
void print(const C& c){
	for (auto& i : c) {
    	std::cout << i << " ";
}
	std::cout << std::endl;
}

template <typename C>
void inc(C& c, int n){
	for(auto& i : c){
		i += n;
	}
}

template<typename Iter1, typename Iter2>
// requires Input_iterator<Iter1>() && Output_iterator<Iter2>()
Iter2 copy(Iter1 f1, Iter1 e1, Iter2 f2){
	for(Iter1 p = f1; p!= e1; ++p){
		*f2++=*p;
	}
	return f2;
}

int main()
try {
	constexpr int size = 10;

	int arr[size];
	for (int i = 0; i < size; ++i) arr[i] = i;

	std::array<int, size> ai;
	std::copy(arr, arr+size, ai.begin());

	std::vector<int> vi(size);
	std::copy(arr, arr+size, vi.begin());

	std::list<int> li(size);
	std::copy(arr, arr+size, li.begin());

	std::array<int, size> ai2 = ai;
	std::vector<int> vi2 = vi;
	std::list<int> li2 = li;

	print(ai2);
	print(vi2);
	print(li2);

	inc(ai2, 2);
	inc(vi2, 3);
	inc(li2, 5);

	print(ai2);
	print(vi2);
	print(li2);

	copy(ai2.begin(), ai2.end(), vi2.begin());
	copy(li2.begin(), li2.end(), ai2.begin());

	print(ai2);
	print(vi2);
	print(li2);

	std::find(ai2.begin(), ai2.end(), 3);

}
catch(std::exception& e){
	std::cerr << "Exception: " << e.what() << '\n';
	return 1;
}
catch(...){
	std::cerr << "Unknown exception\n";
	return 2;
}