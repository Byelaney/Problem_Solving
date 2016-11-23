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


#define sf scanf
#define pf printf
#define rep(i,n) for(int i = 0;i<n;++i)
#define FOR(i,s,e) for(int i = s;i<=e;++i)
#define LL long long
#define ULL unsigned long long

using namespace std;


int main()
{
    ios::sync_with_stdio(0);
    int n;
    cin >> n;
    map<string,int> currents;
    char symbol;
    string number;
    int minimum = 0;
    rep(i, n)
    {
        cin >> symbol;
        cin >> number;

        if(symbol == '+')
        {
            if(currents.size() + 1 > minimum)
                ++minimum;

            currents[number] = 1;
        }

        else
        {
            if(currents.count(number) != 0)
            {
                currents.erase(number);
            }
            else
            {
                ++minimum;
            }
        }
    }

    cout << minimum << endl;

    return 0;
}
