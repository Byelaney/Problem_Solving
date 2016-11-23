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

int best_fit(string s,vector<int> even_idx,int start,int end,int to_rep);

int main()
{
    ios::sync_with_stdio(0);
    string s;
    cin >> s;
    int n =(int)s.size();
    vector<int> even_idx;
    rep(i, n)
    {
        int digit = s[i] - '0';
        if(digit % 2 == 0)
        {
            even_idx.push_back(i);
        }
    }

    int even_size =(int) even_idx.size();
    if(even_size)
    {
        int to_rep = s[n-1] - '0';
        int best_pos = best_fit(s,even_idx,0,even_size-1,to_rep);
        for(int i = 0;i<best_pos;++i)
            cout << s[i];

        cout << s[n-1];

        for(int i = best_pos+1;i<n-1;++i)
            cout << s[i];

        cout << s[best_pos] << endl;
    }
    else
        cout << -1 << endl;

    return 0;
}



int best_fit(string s,vector<int> even_idx,int start,int end,int to_rep)
{
    if(start == end)
        return even_idx[start];
    else
    {
        while(start != end)
        {
            int d = s[even_idx[start]] - '0';
            if(to_rep > d)
                return even_idx[start];
            else
            {
                start++;
            }
        }
        return even_idx[start];
    }
}
