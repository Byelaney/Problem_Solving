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



struct student
{
    int id;
    int rating;
    int rank;
};

bool ratings (student* a,student* b) { return (a->rating > b->rating); }
bool ids (student* a,student* b) { return (a->id < b->id); }


using namespace std;

int main() {
    ios::sync_with_stdio(0);
    int n;
    cin >> n;
    int rating;
    vector<struct student*> students;
    rep(i, n)
    {
        student* s = (student*)malloc(sizeof(struct student) );
        cin >> rating;
        s->id = i+1;
        s->rating = rating;
        students.push_back(s);
    }

    sort(students.begin(),students.end(),&ratings);

    int current_rank = 1;
    for(int i = 0;i<n;)
    {
        int j;
        //s[i] to s[j-1]
        for(j = i+1;j<n;++j)
        {
            if(students[i]->rating != students[j]->rating)
                break;
        }

        for(int t = i;t<j;t++)
        {
            students[t]->rank = current_rank;
        }
        current_rank += j-i;
        i = j;
    }

    sort(students.begin(),students.end(),&ids);

    rep(i, n)
        cout << students[i]->rank << " ";
    cout << "\n";

    return 0;
}
