#include <iostream>
#include <string>

template<typename T>
auto sum(T x) {
	return x;
}

template<typename T, typename...Args>
auto sum(T x, Args...args) {
	return x + sum(args...);
}

int main() {
	auto x = sum<double>(42.5, 10, 11.1f);
	std::cout << x;

	getchar();
}

// 기존의 template<T, ...Args>의 함수는 parameter를 2개 받는다.
// 하지만 재귀적으로 sum()을 호출하게 되면 마지막에 인자를 하나만 받게 되는 경우가 발생하는데
// 이때 컴파일 오류가 발생한다.
// 이를 해결하기 위해서 parameter를 1개만 받는 template를 하나 생성하여 해당 인자를 반환하도록 작성하면
// 재귀함수를 정상적으로 실행할 수 있다.