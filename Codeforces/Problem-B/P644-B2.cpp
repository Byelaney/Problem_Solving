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



using namespace std;

struct Node {
    int id;
    LL start_time;
    LL pro_time;
};

int best_fit(string s,vector<int> even_idx,int start,int end,int to_rep);


int main()
{
    ios::sync_with_stdio(0);
    int n,b;
    cin >> n >> b;
    vector<Node*> v;

    rep(i, n)
    {
        LL s_t,p_t;
        cin >> s_t >> p_t;
        Node* node = (Node*)malloc(sizeof(struct Node));
        node->id = i;
        node->start_time = s_t;
        node->pro_time = p_t;
        v.push_back(node);
    }

    queue<Node*> que;
    LL* ans = new LL[n];
    que.push(v[0]);
    int st = 1;
    LL cur_time = v[0]->start_time;
    while(1)
    {
        if(que.empty())
            break;
        Node* current = que.front();
        que.pop();
        ans[current->id] = cur_time + current->pro_time;
        int j;
        for(j = st;j<n;++j)
        {
            if(v[j]->start_time < cur_time + current->pro_time)
            {
                if(que.size() < b)
                    que.push(v[j]);
                else
                    ans[j] = -1;
            }
            else if(v[j]->start_time > cur_time + current->pro_time)
            {
                break;
            }
            else
            {
                if(que.size() <= b)
                    que.push(v[j]);
                else
                    ans[j] = -1;
            }
        }

        cur_time = ans[current->id];
        st = j;
        if(st >= n)
            break;

        if(que.empty() && st < n)
        {
            que.push(v[j]);
            cur_time = v[j]->start_time;
            st++;
        }
    }

    while(!que.empty())
    {
        Node* node = que.front();
        que.pop();
        ans[node->id] = cur_time + node->pro_time;
        cur_time = ans[node->id];
    }

    rep(i, n)
    cout << ans[i] << " ";

    cout << endl;
    return 0;
}
