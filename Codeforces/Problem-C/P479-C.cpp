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

int MIN(int a,int b);
int MAX(int a,int b);

int main() {
    ios::sync_with_stdio(0);
    int n;
    cin >> n;
    vector<exam*> v;
    rep(i, n)
    {
        int a,b;
        cin >> a >> b;
        exam* e = (exam*)malloc(sizeof(struct exam));
        e->id = i+1;
        e->a = a;
        e->b = b;
        v.push_back(e);
    }

    sort(v.begin(),v.end(),&cmp1);

    vector<int> duplicateS,duplicateE;

    for(int i = 0;i<n;)
    {
        int j;
        for(j = i+1;j<n;++j)
        {
            if(v[i]->a != v[j]->a)
                break;
        }
        if(j != i+1)
        {
            //has duplicate v[i]
            duplicateS.push_back(i);
            duplicateE.push_back(j-1);
            i = j;
        }
        else
        {
            ++i;
        }
    }


    vector<exam*>::iterator it;
    rep(i, duplicateE.size())
    {
        it = v.begin();
        int start = duplicateS[i];
        int end = duplicateE[i];

        advance(it,start);
        sort(it,it+(end-start+1),&cmp2);
        //sort duplicate b
    }
    //now the vector is both sorted...

    int last_min = MIN(v[0]->a, v[0]->b);
    for(int i = 1;i<n;++i)
    {
        int min = MIN(v[i]->a, v[i]->b);
        if(min >= last_min)
            last_min = min;
        else
            last_min = MAX(v[i]->a, v[i]->b);
    }

    cout << last_min << "\n";

    return 0;
}

int MIN(int a,int b)
{
    return (a<b)?a:b;
}

int MAX(int a,int b)
{
    return (a>b)?a:b;
}


/*
This problem takes me several hours...I really suck.But finally I solved it.
First sort by schedule days,then check if there are some duplicate schedule
days and store them.Secondly iterate through them and sort by before days using
stored index.Finally iterate through and compare the (i)th MIN day with the
(i-1)th selected day.

*/
