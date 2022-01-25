#include <iostream>
#include <vector>
#include <algorithm>
#include <time.h> // 시간을 측정하기 위한
#include <iomanip>

using namespace std;

vector<string> types =
{
	"BRUTE FORCE",
	"BACKTRACKING",
	"MEMOIZATION",
	"TABULATION"
};

const int UNKNOWN = INT_MAX;

#define DEBUG 0
#if DEBUG
#define PRINT(x) cerr << x
#else
#define PRINT(x)
#endif

void GetTime(clock_t& timer, string type)
{
	// 현재 시간에서 timer를 빼서 경과 시간을 계산
	timer = clock() - timer;
	// 화면에 경과 시간 출력
	cout << type << "방법 경과 시간: ";
	cout << fixed << setprecision(5) << (float)timer / CLOCKS_PER_SEC << endl;

	timer = clock(); // timer를 현재 시간으로 초기화
}

//모든 부분집합을 만들어내는  -> 
void GetAllSubsets(vector<int> set, vector<int> subset, int index, vector<vector<vector<int>>>& allSubSets)
{
	if (index == set.size())
	{
		allSubSets[subset.size()].push_back(subset);
		return;
	}
	GetAllSubsets(set, subset, index + 1, allSubSets);

	subset.push_back(set[index]); 
	GetAllSubsets(set, subset, index + 1, allSubSets);
}

vector<vector<bool>> SubsetSum_Tabulation(vector<int>& set)
{
	int maxSum = 0;

	for (int i = 0; i < set.size(); i++)
	{
		maxSum += set[i];
	}

	vector<vector<bool>> DP(set.size() + 1, vector<bool>(maxSum + 1, 0));

	for (int i = 0; i < set.size(); i++)
	{
		DP[i][0] = true;
	}

	for (int i = 1; i <= set.size(); i++)
	{
		for (int sum = 1; sum <= maxSum; sum++)
		{
			if (sum < set[i - 1])
			{
				DP[i][sum] = DP[i - 1][sum];
			}
			else
			{
				DP[i][sum] = DP[i - 1][sum] || DP[i - 1][sum - set[i - 1]];
			}
		}
	}

	return DP;
}


bool SubsetSum_Memoization(vector<int>& set, int sum, int i, vector<vector<int>>& memo)
{
	if (sum == 0)
	{
		return true;
	}

	if (i == set.size() || set[i] > sum)
	{
		return false;
	}
	// 현재 상태가 캐시에 있는지 없는지 확인
	if (memo[i][sum] == UNKNOWN) // 쓰레기값인 MAX_INT가 들어감
	{
		// 현재 상태에 대한 솔루션을 구하여 캐시에 저장
		bool append = SubsetSum_Memoization(set, sum - set[i], i + 1, memo);
		bool ignore = SubsetSum_Memoization(set, sum, i + 1, memo);

		memo[i][sum] = append || ignore;
	}

	return memo[i][sum];
}



bool SubsetSum_Backtracking(vector<int>& set, int sum, int i)
{
	// 만약 현재 부분집합의 합이 target과 같다면
	if (sum == 0) // 뺀값이
	{
		return true;
	}
	// 만약 현재 부분집합의 합이 target보다 크거나, 집합의 끝에 도달한다면
	if (i == set.size() || set[i] > sum)
	{
		return false;
	}

	return SubsetSum_Backtracking(set, sum - set[i], i + 1) || SubsetSum_Backtracking(set,sum,i+1);


}


bool SubsetSum_BruteForce(vector<int> set, int target)
{
	vector<vector<vector<int>>> allSubsets(set.size() + 1); // 해당 부분집합은 공집합을 포함하기 때문에
	// 크기를 해당 갯수 +1로 미리 생성하고
	// 3차원 벡터로 구성

	GetAllSubsets(set, {}, 0, allSubsets);

	for (int size = 0; size <= set.size(); size++)
	{
		PRINT("부분집합의 원소 개수 : " << size << endl);

		for (auto subset : allSubsets[size])
		{
			PRINT("\t{ ");

			int sum = 0;
			for (auto number : subset)
			{
				sum += number;
				PRINT(number << " ");
			}
			PRINT("} = " << sum << endl);
			if (sum == target)
				return true;
		}
	}
	return false;
}

// 하향식 // Memoization 
int fibo1(int n, vector<int>& memo)
{
	if (n < 2)
		return n;

	if (memo[n] != -1)
		return memo[n];

	//이제 메모가 없다면
	int result = fibo1(n - 1,memo) + fibo1(n - 2,memo);
	memo[n] = result;
	return result;
}

// 상향식 // Tabulation
int fibo2(int n)
{
	if (n < 2)
		return n;

	vector<int> v(100, 0);
	v[1] = 1;
	for (int i = 2; i <= n; i++)
	{
		v[i] = v[i - 1] + v[i - 2];
	}

	return v[n];
}

//일종의 하향식 트리 전개방법
int fibo3(int n)
{
	if (n < 2)
		return n;
	return fibo3(n - 1) + fibo3(n - 2);
}

int main()
{                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                      
	vector<int> set = { 16,1058,22,13,46,55,3,92,47,7,
		98,367,807,106,333,85,577,9,3059 };
	int target = 6076; // 모든 원소의 합으 6800이므로 -> 모든 합보다 미세하게 작은 값이 주입될 경우 모든 경우를 다 탐색
	int tests = 4;

	sort(set.begin(), set.end()); // 먼저 오름차순으로 정렬
	
	int xx = 0;
	
	for (int i = 0; i < set.size(); i++)
		xx += set[i];

	cout << "집합의 모든 원소의 합 : " << xx << endl;

	bool found;

	for (int i = 0; i < tests; i++)
	{
		bool found;

		clock_t timer = clock();

		switch (i)
		{
		case 0:
		{
			found = SubsetSum_BruteForce(set, target);
			break;
		}
		case 1:
		{
			found = SubsetSum_Backtracking(set, target, 0);
			break;
		}
		case 2:
		{
			vector<vector<int>> memo(set.size(), vector<int>(7000, UNKNOWN));
			found = SubsetSum_Memoization(set, target, 0, memo);
			break;
		}
		case 3:
		{
			vector<vector<bool>> DP = SubsetSum_Tabulation(set);
			found = DP[set.size()][target];
			break;
		}
		}
		
		if (found)
		{
			cout << "원소 합이 " << target << "인 부분집합이 있습니다." << endl;
		}
		else
		{
			cout << "원소 합이 " << target << "인 부분집합이 없습니다." << endl;
		}

		GetTime(timer, types[i]);
		cout << endl;
	}
}


