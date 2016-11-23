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
#define rep1(i,n) for(int i = 1;i<n;++i)
#define r_rep(i,n) for(int i = n-1;i>=0;--i)
#define FOR(i,s,e) for(int i = s;i<=e;++i)
#define LL long long
#define ULL unsigned long long

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    string s;
    cin >> s;

    vector<int> eight_base;
    for(int i=0;i<1000;++i)
    {
        if(i%8 == 0)
            eight_base.push_back(i);
    }

    int res = 0;
    bool found = false;
    for(int i = 0;i<eight_base.size();++i)
    {
        int num = eight_base[i];
        int hstart = (int)s.size()-1;
        int k = 0;
        int docu = 0;

        while(num > 0)
        {
            int digit = num % 10;
            num /= 10;
            docu++;
            for(int j = hstart;j>=0;--j)
            {
                if(digit == (s[j] - '0'))
                {
                    //cout << "a";
                    hstart = j-1;
                    k++;
                    break;
                }
            }
        }

        if(k == docu && k > 0)
        {
            found = true;
            res = eight_base[i];
            break;
        }
    }

    if(found)
    {
        cout << "YES" << endl;
        cout << res << endl;
    }
    else
    {
        size_t pos = s.find("0");
        if(string::npos == pos)
            cout << "NO" << endl;
        else
        {
            cout << "YES" << endl;
            cout << 0 << endl;
        }
    }
    return 0;
}
