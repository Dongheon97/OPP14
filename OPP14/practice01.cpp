#include <iostream>

template<typename T, int num=5>
T add_num(T t) {
	return t + num;
}

int main() {
	int x = 3;
	
	std::cout << "x : " << add_num<int, 2>(x) << std::endl;
	return 0;
}

// 원래의 코드는 ' x : 8' 이 출력된다. 
// template<>에 parameter로 num=5가 주어지고 main()함수에서 x=3인 변수가 주어지므로 
// add_num(x)함수를 호출하면 x+num인 3+5의 결과가 출력된다.

// (실습1.1)은 결과값이 5가 나오도록 add_num()의 호출 부분을 수정하는 것이다. 
// template<>의 num 값을 2으로 바꾸면 x+num = 3+2 = 5가 출력된다. 
// 즉 add_num<int, 2>(x)으로 호출하면 template의 int num 인자가 바뀌게 된다.