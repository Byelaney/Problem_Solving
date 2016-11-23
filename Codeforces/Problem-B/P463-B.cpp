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
    int n;
    cin >> n;
    int * h = new int[n+1];
    h[0] = 0;
    rep1(i, n+1)
    cin >> h[i];
    LL energy = 0;
    rep(i,n)
    {
        if(h[i] - h[i+1] >= 0)
        {
            energy += h[i] - h[i+1];
        }
        else if(h[i] + energy - h[i+1] >= 0)
        {
            energy -= (h[i+1] - h[i]);
        }
        else
        {
            h[0] += h[i+1] - h[i] - energy;
            energy = 0;
        }
    }

    cout << h[0] << endl;

    return 0;
}
