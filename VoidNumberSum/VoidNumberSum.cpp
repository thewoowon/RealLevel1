﻿#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;


int solution(vector<int> numbers) {
    int answer = 45;

    for (int i = 0; i < numbers.size(); i++)
    {
        answer -= numbers[i];
    }

    return answer;
}
int main()
{
    solution({ 5,8,4,0,6,7,9 });
}

