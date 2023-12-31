﻿// QuestionInterview150s.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
// https://leetcode.com/problem-list/top-interview-questions/
//

#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <map>

#include <algorithm>
#include <iomanip>
#include <queue>
#include <stack>
#include <string>

using namespace std;

struct City {
    string name;
    double population;
};
// compare City by population
bool cmpfnc(const City& a, const City& b) {
    return a.population < b.population;
}

void custom_priority_queue() {
    vector<City> vCity = { {"city 1", 140000}, {"city 2", 100000},{"city 3", 700000},{"city 4", 500000} };
    //lambda expression
    priority_queue<City, vector<City>, decltype(&cmpfnc) > custom_queue(cmpfnc);
    for (auto &c : vCity) {
        custom_queue.push(c);
    }
    auto bc = custom_queue.top();
    custom_queue.pop();// remove biggest and rearrange
    double bg = bc.population;
}

void testvecmap() {
    vector<City> vCity = { {"city 1", 140000}, {"city 2", 100000},{"city 3", 700000},{"city 4", 500000} };
    //lambda expression
    sort(vCity.begin(), vCity.end(), [](const City& a, const City& b) {return a.population < b.population; });
    for (auto c : vCity) {
        cout << "City name: " << c.name << " population: " << c.population << endl;
    }
}

class CountObject {
    static int count; //declare share data
public:
    CountObject() {
        count++;
    }
    //static method, can be used without instantiating an object of the CountObject class
    static int getCount() {
        return count;
    }
};
//need to define and initilize value
int CountObject::count = 0;

bool jump(vector<int>& nums, int pos) {
    if (pos == nums.size() - 1) return true;
    if (nums[pos] + pos >= nums.size() - 1) return true;
    if (nums[pos] == 0) return false;
    for (int i = 1; i <= nums[pos]; i++) {
        bool ret = jump(nums, pos + i);
        if (ret) return ret;
    }
    return false;
}
bool canJump(vector<int>& nums) {
    bool ret = jump(nums, 0);
    return ret;
}

int mySqrt(int x) {
    long long s, end, mid;
    s = 0;
    end = x;
    long long ret =0;
    long long tem;
    while (s <= end) {
        mid = (s + end) / 2;
        tem = mid * mid;
        if (tem == x) return mid;
        if (tem < x) {
            ret = mid;
            s = mid + 1;
        }
        else
            end = mid - 1;
    }
    return (int)ret;
}

//======


void testm() {
    unsigned int a = 2;
    unsigned int b = 1;
    int ret = a ^ b;
    return;
}

//========

int main()
{
   // custom_priority_queue();
    unordered_map<char, int> umci = { {'I', 1}, {'V',5},{'X',10}};
  //  vector<vector<char>> board = { {'O','O','O'} ,{'O','O','O'},{'O','O','O'}};
    vector<vector<int>> Vec = { {1,0}, {2,0},{3,1},{3,2} };
    string str = "3+2*4";
    int n1 = INT_MAX;
    testm();
    
    char c = 'a';
    char v = c + 1;

   
    
    //testvecmap();
    return 0;
}

// 프로그램 실행: <Ctrl+F5> 또는 [디버그] > [디버깅하지 않고 시작] 메뉴
// 프로그램 디버그: <F5> 키 또는 [디버그] > [디버깅 시작] 메뉴

// 시작을 위한 팁: 
//   1. [솔루션 탐색기] 창을 사용하여 파일을 추가/관리합니다.
//   2. [팀 탐색기] 창을 사용하여 소스 제어에 연결합니다.
//   3. [출력] 창을 사용하여 빌드 출력 및 기타 메시지를 확인합니다.
//   4. [오류 목록] 창을 사용하여 오류를 봅니다.
//   5. [프로젝트] > [새 항목 추가]로 이동하여 새 코드 파일을 만들거나, [프로젝트] > [기존 항목 추가]로 이동하여 기존 코드 파일을 프로젝트에 추가합니다.
//   6. 나중에 이 프로젝트를 다시 열려면 [파일] > [열기] > [프로젝트]로 이동하고 .sln 파일을 선택합니다.
