#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

int solution(string s) {
    int answer = 0;
    string append = "";
    int index = 0;
    
    map<string, int> match;
    map<string, string> match_s;

    match.insert(make_pair<string, int>("on", 3));
    match.insert(make_pair<string, int>("tw", 3));
    match.insert(make_pair<string, int>("th", 5));
    match.insert(make_pair<string, int>("fo", 4));
    match.insert(make_pair<string, int>("fi", 4));
    match.insert(make_pair<string, int>("si", 3));
    match.insert(make_pair<string, int>("se", 5));
    match.insert(make_pair<string, int>("ei", 5));
    match.insert(make_pair<string, int>("ni", 4));
    match.insert(make_pair<string, int>("ze", 4));

    match_s.insert(make_pair<string, string>("on", "1"));
    match_s.insert(make_pair<string, string>("tw", "2"));
    match_s.insert(make_pair<string, string>("th", "3"));
    match_s.insert(make_pair<string, string>("fo", "4"));
    match_s.insert(make_pair<string, string>("fi", "5"));
    match_s.insert(make_pair<string, string>("si", "6"));
    match_s.insert(make_pair<string, string>("se", "7"));
    match_s.insert(make_pair<string, string>("ei", "8"));
    match_s.insert(make_pair<string, string>("ni", "9"));
    match_s.insert(make_pair<string, string>("ze", "0"));

    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] >= 48 && s[i] <= 57)
        {
            //숫자라면 ->
            append += s[i]; 
            continue;
        }
        else
        {
            //문자라면 ->두개 추출
            append += match_s.at(s.substr(i, 2));
            i += match.at(s.substr(i, 2))-1; // 
            continue;
        }
    }
    answer = stoi(append);

    return answer;
}


int main()
{
    solution("2three45sixseven");
}

