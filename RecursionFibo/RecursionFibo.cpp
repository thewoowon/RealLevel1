#include <iostream>

// 일반적인 재귀로 구현하는 피노나치수는 -> 시간 복잡도가 2의 지수승이다 -> n의 크기에 따라 지수적으로 증가하기 때문에
// 효율이 좋지 못하다.


int fibo(int n)
{
	if (n == 0)
	{
		return 0;
	}
	else if (n == 1)
	{
		return 1;
	}
	else
	{
		return fibo(n - 1) + fibo(n - 2);
	}
}

int main()
{
	for (int i = 0; i < 11; i++)
	{
		std::cout << fibo(i) << std::endl;
	}
}
