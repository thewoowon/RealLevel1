#include <iostream>
#include <vector>

using namespace std;

const int UNKNOWN = -1;
const int MAX_SIZE = 100000;

vector<int> memo(MAX_SIZE, UNKNOWN);

int fibo(int n)
{
	if (n < 2)
		return n;
	if (memo[n] != UNKNOWN)
		return memo[n];

	int result = fibo(n - 1) + fibo(n - 2);
	memo[n] = result;
	return result;
}


int main()
{
    std::cout << "Hello World!\n";
}
