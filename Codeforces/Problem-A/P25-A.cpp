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
#include <unordered_map>
#include <unordered_set>
#include <string>
#include <math.h>
#include <set>
#include <queue>
#include <algorithm>
#include <stack>
#include <list>
#include <locale>


#define sf scanf
#define pf printf
#define rep(i,n) for(int i = 0;i<n;++i)
#define rep1(i,n) for(int i = 1;i<n;++i)
#define rep1e(i,n) for(int i = 1;i<=n;++i)
#define r_rep(i,n) for(int i = n-1;i>=0;--i)
#define FOR(i,s,e) for(int i = s;i<=e;++i)
#define LL long long
#define ULL unsigned long long

using namespace std;

class ListNode {
     public:
         int val;
         ListNode *next;
         ListNode(int val) {
                 this->val = val;
                 this->next = NULL;
             }
};

class TreeNode {
     public:
        int val;
         TreeNode *left, *right;
         TreeNode(int val) {
                 this->val = val;
                 this->left = this->right = NULL;
             }
};

class SegmentTreeNode {
     public:
         int start, end, max;
         SegmentTreeNode *left, *right;
         SegmentTreeNode(int start, int end, int max) {
                 this->start = start;
                 this->end = end;
                 this->max = max;
                 this->left = this->right = NULL;
             }
};

struct DirectedGraphNode {
         int label;
         vector<DirectedGraphNode *> neighbors;
         DirectedGraphNode(int x) : label(x) {};
};


int main()
{
    ios::sync_with_stdio(0);
    vector<int> even;
    vector<int> odd;
    int n = 0;
    cin >> n;
    int num = 0;
    rep(i, n)
    {
        cin >> num;
        if (num%2 == 0)
            even.push_back(i+1);
        else
            odd.push_back(i+1);
    }
    if (even.size() > odd.size())
        cout << odd[0] << endl;
    else
        cout << even[0] << endl;
    return 0;
}
