
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> maker(int least, int max)
{
    vector<int> answer;


    switch (max) // 
    {
    case 6:
        answer.push_back(1);
        break;
    case 5:
        answer.push_back(2);
        break;
    case 4:
        answer.push_back(3);
        break;
    case 3:
        answer.push_back(4);
        break;
    case 2:
        answer.push_back(5);
        break;
    default:
        answer.push_back(6);
        break;
    }

    switch (least) // 
    {
    case 6:
        answer.push_back(1);
        break;
    case 5:
        answer.push_back(2);
        break;
    case 4:
        answer.push_back(3);
        break;
    case 3:
        answer.push_back(4);
        break;
    case 2:
        answer.push_back(5);
        break;
    default:
        answer.push_back(6);
        break;
    }

    return answer;
}

vector<int> solution(vector<int> lottos, vector<int> win_nums) {
    vector<int> answer;
    vector<int> left;
    int zeroCount = 0;
    int least = 0;

    std::sort(lottos.begin(), lottos.end());
    std::sort(win_nums.begin(), win_nums.end()); // 미리 정렬

    for (int i = 0; i < win_nums.size(); i++)
    {
        for (int j = 0; j < lottos.size(); j++)
        {
            if (win_nums[i] == lottos[j])
            {
                least += 1;
                break;
            }
            if (j == lottos.size()-1)
                left.push_back(win_nums[i]);
        }
    }
    // left는 나머지 당첨 번호만 남음

    for (int i = 0; i < lottos.size(); i++)
    {
        if (lottos[i] != 0)
            break;
        else
            zeroCount += 1;
    }
    if (left.size() < zeroCount)
    {
        answer = maker(least, least + left.size());
    }
    else if (left.size() == zeroCount)
    {
        answer = maker(least, least + zeroCount);
    }
    else
    {
        answer = maker(least, least + zeroCount);
    }

    return answer;
}
int main()
{
    solution({ 44, 1, 0, 0, 31, 25 }, { 31, 10, 45, 1, 6, 19 });
}