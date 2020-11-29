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

// ������ template<T, ...Args>�� �Լ��� parameter�� 2�� �޴´�.
// ������ ��������� sum()�� ȣ���ϰ� �Ǹ� �������� ���ڸ� �ϳ��� �ް� �Ǵ� ��찡 �߻��ϴµ�
// �̶� ������ ������ �߻��Ѵ�.
// �̸� �ذ��ϱ� ���ؼ� parameter�� 1���� �޴� template�� �ϳ� �����Ͽ� �ش� ���ڸ� ��ȯ�ϵ��� �ۼ��ϸ�
// ����Լ��� ���������� ������ �� �ִ�.