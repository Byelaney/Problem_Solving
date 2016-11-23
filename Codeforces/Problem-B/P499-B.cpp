//
//  main.cpp
//  Acm
//
//  Created by 管君 on 16/3/14.
//  Copyright © 2016年 カンクン. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <map>

#define sf scanf
#define pf printf
#define rep(i,n) for(int i = 0;i<n;++i)
#define FOR(i,s,e) for(int i = s;i<=e;++i)

struct exam
{
    int id;
    int a;
    int b;
};


using namespace std;

bool cmp1(exam* e1,exam* e2){return e1->a < e2->a;}
bool cmp2(exam* e1,exam* e2){return e1->b < e2->b;}

string MIN(string a,string b);
int MAX(int a,int b);

int main() {
    ios::sync_with_stdio(0);
    int n,m;
    cin >> n >> m;
    map<string,string> mp;
    string a,b;
    rep(i, m)
    {
        cin >> a >> b;
        mp[a] = b;
        mp[b] = a + "A";
    }
    string s;
    string op;
    rep(i, n)
    {
        cin >> s;
        string a1 = mp[s];
        if(a1[a1.size()-1] == 'A')
        {
            op = MIN(a1.substr(0,a1.size()),s);
        }
        else
        {
            op = MIN(s,a1);
        }
        cout << op << " ";
    }

    cout << "\n";

    return 0;
}

string MIN(string a,string b)
{
    if(a.size() <= b.size())
        return a;
    else
        return b;
}
