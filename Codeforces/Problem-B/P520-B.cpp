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

using namespace std;

struct Node {
         int val;
         int height;
         Node(int x,int y) : val(x),height(y) {}
};

int solve(int n,int m);
int min(int a,int b)
{
    if(a<b)
        return a;
    else
        return b;
}

int main() {
    ios::sync_with_stdio(0);
    int n,m;
    cin >> n >> m;
    cout << solve(n,m) << "\n";
    return 0;
}

int solve(int n,int m)
{
    if(n >= m)
        return n-m;

    map<int,bool> mp;

    queue<Node*> queue;
    Node* root = new Node(n,0);
    queue.push(root);
    while(!queue.empty())
    {
        Node* tmp = queue.front();
        queue.pop();
        mp[tmp->val] = true;

        if(tmp->val == m)
            return tmp->height;

        if(mp.count(2*tmp->val) == 0)
        {
            if(tmp->val < 2*m)
            {
                Node* left = new Node(2*tmp->val,tmp->height + 1);
                queue.push(left);
            }
        }

        if(mp.count(tmp->val-1) == 0 && (tmp->val!= 0))
        {
            Node* right = new Node(tmp->val-1,tmp->height + 1);
            queue.push(right);
        }
    }

    return -1;
}
