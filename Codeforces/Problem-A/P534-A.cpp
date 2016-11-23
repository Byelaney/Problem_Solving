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

int main()
{
    ios::sync_with_stdio(0);
    string base = "3 1 4 2 ";
    int n;
    cin >> n;
    if(n == 1 || n == 2)
    {
        cout << 1 << endl;
        cout << 1 << endl;
    }
    else if(n == 3)
    {
        cout << 2 << endl;
        cout << 1 << " " << 3 << endl;
    }
    else if (n == 4)
    {
        cout << 4 << endl;
        cout << base << endl;
    }
    else
    {
        cout << n << endl;
        if(n%2 == 0)
        {
            int start = n;
            while(start >= 6)
            {
                // output left part
                cout << start << " ";
                start = start - 2;
            }
            cout << base;
            start = 5;
            while(start <= n-1)
            {
                // output right part
                cout << start << " ";
                start = start + 2;
            }
        }
        else
        {
            int start = n-1;
            while(start >= 6)
            {
                // output left part
                cout << start << " ";
                start = start - 2;
            }
            cout << base;
            start = 5;
            while(start <= n)
            {
                // output right part
                cout << start << " ";
                start = start + 2;
            }
        }
    }
    return 0;
}
