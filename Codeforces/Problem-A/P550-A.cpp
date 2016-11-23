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
#include <utility>


#define sf scanf
#define pf printf
#define rep(i,n) for(int i = 0;i<n;++i)
#define r_rep(i,n) for(int i = n-1;i>=0;--i)
#define FOR(i,s,e) for(int i = s;i<=e;++i)
#define LL long long
#define ULL unsigned long long

using namespace std;

int find_first(string s,string aim);
int find_last(string s,string aim);

int main()
{
    ios::sync_with_stdio(0);
    string s;
    cin >> s;

    size_t found1 = s.find("AB");
    size_t found2 = s.find("BA");

    if(found1 == string::npos || found2 == string::npos)
    {
        cout << "NO" << endl;
    }
    else
    {
        s[found1] = '#';
        s[found1+1] = '#';

        size_t found3 = s.find("BA");
        if(found3 != string::npos)
            cout << "YES" << endl;
        else
        {
            s[found1] = 'A';
            s[found1+1] = 'B';

            s[found2] = '#';
            s[found2+1] = '#';

            size_t found4 = s.find("AB");
            if(found4 != string::npos)
                cout << "YES" << endl;
            else
                cout << "NO" << endl;
        }
    }
    return 0;
}

int find_first(string s,string aim)
{
    if(s.size() == 1)
        return -1;

    rep(i, s.size()-1)
    {
        if(s[i] == aim[0] && s[i+1] == aim[1])
            return i;
    }

    return -1;
}

int find_last(string s,string aim)
{
    if(s.size() == 1)
        return -1;

    for(int i = (int)s.size() -1 ;i>=1;--i)
    {
        if(s[i] == aim[1] && s[i-1] == aim[0])
            return i-1;
    }

    return -1;
}
