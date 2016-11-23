//
//  main.cpp
//  Acm
//
//  Created by 管君 on 16/3/14.
//  Copyright © 2016年 カンクン. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <cstring>
#include <vector>
#include <sstream>
#include <map>
#include <string>
#include <math.h>
#include <set>
#include <queue>
#include <algorithm>
#include <stack>


#define sf scanf
#define pf printf
#define rep(i,n) for(int i = 0;i<n;++i)
#define FOR(i,s,e) for(int i = s;i<=e;++i)
#define LL long long
#define ULL unsigned long long

using namespace std;

vector<int> twoSum(vector<int>& nums, int target);

bool isZero(int a[],int n);

int findStart(int a[],int n);

int main()
{
    ios::sync_with_stdio(0);
    string s;
    cin >> s;
    int digits = (int) s.size();
    int a[digits];
    for(int i = 0;i<digits;++i)
    {
        a[i] = s[i] - '0';
    }

    int nums = 0;
    vector<string> vv;
    while(!isZero(a, digits))
    {
        string st = "";
        int starter = findStart(a, digits);
        for(int i = starter;i<digits;++i)
        {
            if(a[i] > 0)
            {
                st.append("1");
                a[i]--;
            }

            else if (a[i] == 0)
            {
                st.append("0");
            }
        }
        vv.push_back(st);
        nums++;
    }

    cout << nums << endl;
    rep(i, vv.size())
    cout << vv[i] << " " ;
    cout << endl;


    return 0;
}

bool isZero(int a[],int n)
{
    for(int i = 0;i<n;++i)
        if(a[i] != 0)
            return false;

    return true;
}

int findStart(int a[],int n)
{
    for(int i = 0;i<n;++i)
    {
        if(a[i] != 0)
            return i;
    }
    return -1;
}

vector<int> twoSum(vector<int>& nums, int target) {
    vector<int> myvector(nums.begin(),nums.end());
    vector<int> v;
    sort(nums.begin(),nums.end());
    int i = 0;
    int j = (int)nums.size()-1;
    int v1,v2;
    v1 = 0;
    v2 = 0;
    while(i <= j)
    {
        if(nums[i] + nums[j] == target)
        {
            v1 = nums[i];
            v2 = nums[j];
            break;
        }

        if(nums[i] + nums[j] > target)
            j--;

        if(nums[i] + nums[j] < target)
            ++i;
    }

    for(int i = 0;i<myvector.size();++i)
    {
        if(myvector[i] == v1)
            v.push_back(i);

        if(myvector[i] == v2)
            v.push_back(i);
    }
    return v;
}
