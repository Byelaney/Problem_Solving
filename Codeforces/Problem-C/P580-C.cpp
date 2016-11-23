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
void dfs(int v,int anc,int c);

const int N = 100005;
vector<int> e[N];
int cats[N];
int choices;
int n,m;

// v is current vertice
void dfs(int v,int anc,int c)
{
    if(cats[v]) ++c;
    else c = 0;
    if(c > m) return;//too many cats!

    bool currentLeaf = true;//assume current is a leaf
    rep(i, e[v].size())
    {
        int adjancent = e[v][i];
        if(adjancent != anc)
        {
            currentLeaf = false;
            dfs(adjancent, v, c);
        }
    }

    if(currentLeaf) ++choices;
}

int main()
{
    ios::sync_with_stdio(0);
    cin >> n >> m;
    rep1(i, n+1)
    {
        cin >> cats[i];
    }

    rep1(i, n)
    {
        int v1,v2;
        cin >> v1 >> v2;
        e[v1].push_back(v2);
        e[v2].push_back(v1);
    }

    dfs(1, -1, 0);
    cout << choices << endl;

    return 0;
}
