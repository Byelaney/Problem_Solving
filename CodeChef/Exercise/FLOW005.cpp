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

LL exp(LL base,LL n);

int main()
{
    ios::sync_with_stdio(0);
    int Rs[] = {1,2,5,10,50,100};
    int T,N;
    cin >> T;
    while(T--)
    {
        int notes = 0;
        cin >> N;
        while(N)
        {
            int id = 5;
            for(;id>=0;--id)
            {
                if(N >= Rs[id])
                    break;
            }
            notes += N/Rs[id];
            N = N%Rs[id];
        }

        cout << notes << endl;
    }
    return 0;
}


LL exp(LL base,LL n)
{
    if(n == 0)
        return 1;
    if(n == 1)
        return base;

    if(n%2 == 0)
    {
        LL half = exp(base, n/2);
        return half * half;
    }
    else
    {
        LL half = exp(base,(n-1)/2);
        return base * half * half;
    }
}
