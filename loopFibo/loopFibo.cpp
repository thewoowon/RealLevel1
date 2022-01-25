#include <iostream>

int fibo(int n)
{
    int fibo[100000]; // 충분히 큰 배열
    fibo[0] = 0; // 초기화
    fibo[1] = 1; // 초기화
    for (int i = 2; i <= n; i++)
    {
        fibo[i] = fibo[i - 1] + fibo[i - 2];
    }

    return fibo[n];
}

int main()
{
    for (int i = 0; i < 11; i++)
    {
        std::cout << fibo(i) << std::endl;
    }
}
