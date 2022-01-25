#include <iostream>
#include <vector>

using namespace std;

const int UNKNOWN = -1;
const int MAX_SIZE = 100000;

vector<int> v(100000, UNKNOWN);

//메모이제이션을 통한 동적분할기법 적용
int fibo(int n)
{
    if (n < 2)
        return n;

    if (v[n] != UNKNOWN)
        return v[n];

    int result = fibo(n - 1) + fibo(n - 2); 
    v[n] = result;
    return result;

}


int main()
{
    for (int i = 0; i < 11; i++)
    {
        cout << fibo(i) << endl;
    }
}
