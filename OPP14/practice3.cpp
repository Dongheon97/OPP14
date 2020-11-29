#include <iostream>
#include <algorithm>
#include <forward_list>
#include <functional>

template<typename ForwardIterator, typename Compare>
void bubble_sort(ForwardIterator first, ForwardIterator last, Compare comp) {
	for (auto sorted = first; first != last; last = sorted) {
		sorted = first;
		for (auto cur = first, prev = first; ++cur != last; ++prev) {
			if (comp(*cur, *prev)) {
				std::iter_swap(cur, prev);
				sorted = cur;
			}
		}
	}
}

struct CompLess {	// Functor class
	bool operator()(int x, int y)  {
		return x < y;
	}
};

struct CompGreater {	// Functor class
	bool operator()(int x, int y)  {
		return x > y;
	}
};


int main() {
	std::forward_list<int>	values{ 7,0,6,1,5,2,4,3 };

	std::cout << "오름차순 정렬" << std::endl;
	CompLess compLess;	// Functor 생성
	bubble_sort(values.begin(), values.end(), compLess);
	//결과 프린트
	for (auto it = values.begin(); it != values.end(); ++it) {
		std::cout << ' ' << *it;
	}
	std::cout << std::endl;

	std::cout << "내림차순 정렬" << std::endl;
	CompGreater compGreater;	// Functor 생성
	bubble_sort(values.begin(), values.end(), compGreater);
	//결과 프린트
	for (auto it = values.begin(); it != values.end(); ++it) {
		std::cout << ' ' << *it;
	}
	std::cout << std::endl;

	getchar();
}

// Functor 인 CompGreater와 CompLess를 구현했다.
// Functor 는 형태가 클래스와 비슷하다. 따라서 class를 구현하는 것처럼 작성했다.
// operator() 내부를 다르게 작성했다. 
// CompLess에서는 cur<pre가 되어야 하므로 x<y일 때 true를 반환하도록 했으며,
// CompGreater에서는 그와 반대로 작성했다.
