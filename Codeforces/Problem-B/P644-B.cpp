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


#define sf scanf
#define pf printf
#define rep(i,n) for(int i = 0;i<n;++i)
#define FOR(i,s,e) for(int i = s;i<=e;++i)
#define LL long long
#define ULL unsigned long long

const int MAXN = 2*1e5 + 1;

using namespace std;

struct Node {
    LL t, d;
    int id;
};




int main()
{
    ios::sync_with_stdio(0);
    int n, b; cin >> n >> b;
    queue<Node*> Q;
    LL last = 0;

    vector<Node*> num;
    LL* ans = new LL[n];

    for(int i = 0; i < n; i++)
    {
        LL tt,dd;
        cin >> tt >> dd;
        Node* node = (Node*)malloc(sizeof(struct Node));
        node->id = i;
        node->t = tt;
        node->d = dd;
        num.push_back(node);
        if(last <= num[i]->t) {
            while(!Q.empty()) {
                Node* p = Q.front(); Q.pop();
                last = max(p->t, last) + p->d;
                ans[p->id] = last;
                if(last > num[i]->t) break;
            }
        }
        if(last > num[i]->t){
            if(Q.size() < b) {
                Q.push(num[i]);
            }
            else {
                ans[num[i]->id] = -1;
            }
        }
        else {
            last = max(last, num[i]->t) + num[i]->d;
            ans[num[i]->id] = last;
        }
        //cout << last << endl;
    }

    while(!Q.empty())
    {
        Node* p = Q.front(); Q.pop();
        last = max(p->t, last) + p->d;
        ans[p->id] = last;
    }

    for(int i = 0; i < n; i++)
    {
        if(i) cout << ' ';
        cout << ans[i];
    }
    cout << endl;
    return 0;
}
