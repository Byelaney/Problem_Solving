//
//  main.cpp
//  Acm
//
//  Created by 管君 on 16/3/14.
//  Copyright © 2016年 カンクン. All rights reserved.
//
#define sf scanf
#define pf printf
#define rep(i,n) for(int i = 0;i<n;++i)
#define FOR(i,s,e) for(int i = s;i<=e;++i)
#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <fstream>
#include <cstring>
#include <vector>
#include <sstream>
#include <map>
#include <string>
#include <math.h>
#include <queue>
#include <map>
#include <algorithm>

using namespace std;

struct Node
{
    int val;
    int idx;
};

int min(int a,int b)
{
    if(a<b)
        return a;
    else
        return b;
}

bool cmp1(Node* n1,Node* n2){ return n1->val < n2->val;}

int main() {
    ios::sync_with_stdio(0);
    int n,k;
    cin >> n >> k;
    vector<Node*> v;
    rep(i, n)
    {
        int tmp;
        cin >> tmp;
        Node* node = (Node*)malloc(sizeof(struct Node));
        node->idx = i+1;
        node->val = tmp;
        v.push_back(node);
    }

    sort(v.begin(),v.end(),&cmp1);


    int i = 0;
    vector<int> v2;
    int sum = 0;
    while(i < v.size() && k-v[i]->val >= 0)
    {
        ++sum;
        v2.push_back(v[i]->idx);
        k -= v[i++]->val;
    }

    cout << sum << endl;
    rep(j, v2.size())
    cout << v2[j] << " ";
    cout << endl;

    return 0;
}
