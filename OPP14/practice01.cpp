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

// ������ �ڵ�� ' x : 8' �� ��µȴ�. 
// template<>�� parameter�� num=5�� �־����� main()�Լ����� x=3�� ������ �־����Ƿ� 
// add_num(x)�Լ��� ȣ���ϸ� x+num�� 3+5�� ����� ��µȴ�.

// (�ǽ�1.1)�� ������� 5�� �������� add_num()�� ȣ�� �κ��� �����ϴ� ���̴�. 
// template<>�� num ���� 2���� �ٲٸ� x+num = 3+2 = 5�� ��µȴ�. 
// �� add_num<int, 2>(x)���� ȣ���ϸ� template�� int num ���ڰ� �ٲ�� �ȴ�.