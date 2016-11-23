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

ULL MIN(const ULL a,const ULL b)
{
    if(a < b)
        return a;
    else
        return b;
}

int main()
{
    ios::sync_with_stdio(0);
    int n,s;
    cin >> n;
    vector<int> P,M,PE;
    for(int i = 1;i<=n;++i)
    {
        cin >> s;
        if(s == 1)
            P.push_back(i);
        else if(s == 2)
            M.push_back(i);
        else
            PE.push_back(i);
    }

    ULL min =MIN(MIN(P.size(),M.size()),PE.size());

    cout << min << endl;
    for(int i = 0;i<min;++i)
        cout << P[i] << " " << M[i] << " " << PE[i] << endl;

    return 0;
}
