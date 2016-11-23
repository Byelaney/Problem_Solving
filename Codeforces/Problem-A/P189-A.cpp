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

int MaxChoice(int* dp,int i,int a,int b,int c);
int MAX(int a,int b);
int MIN(int a,int b);
int MINTri(int a,int b,int c);

int main()
{
    ios::sync_with_stdio(0);
    int n,a,b,c;
    cin >> n >> a >> b >> c;

    int dp[4002];
    rep(i, n+1)
    dp[i] = -1;

    dp[0] = 0;

    for(int i = 1;i<=n;++i)
    {
        int result = MaxChoice(dp,i,a,b,c);
        if(result >= 0)
            dp[i] = result + 1;
    }

    cout << dp[n] << endl;
    return 0;
}


int MaxChoice(int* dp,int i,int a,int b,int c)
{
    int p1 = -1;
    int p2 = -1;
    int p3 = -1;

    if(i-a >= 0)
        p1 = dp[i-a];
    if(i-b >= 0)
        p2 = dp[i-b];
    if(i-c >= 0)
        p3 = dp[i-c];

    return MAX(MAX(p1,p2),p3);
}

int MAX(int a,int b)
{
    if(a>b)
        return a;
    else
        return b;
}

int MIN(int a,int b)
{
    if(a>b)
        return b;
    else
        return a;
}



int MINTri(int a,int b,int c)
{
    return MIN(MIN(a,b),c);
}
