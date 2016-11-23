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
#define FOR(i,s,e) for(int i = s;i<=e;++i)
#define LL long long
#define ULL unsigned long long



using namespace std;

vector<pair<LL,LL>> subArySum(vector<LL> v,LL k);

int main()
{
    ios::sync_with_stdio(0);
    vector<LL> v;
    int n;
    cin >> n;
    LL sum = 0;
    rep(i, n)
    {
        LL num;
        cin >> num;
        sum += num;
        v.push_back(num);
    }

    LL tri_sum = sum / 3;

    vector<pair<LL,LL>> vp = subArySum(v,tri_sum);

    vector<pair<LL,LL>> start_pair;
    vector<pair<LL,LL>> mid_pair;


    rep(i, vp.size())
    {
        pair<LL,LL> pr = vp[i];
        if(pr.first == 0)
        {
            start_pair.push_back(pr);
        }
    }

    rep(i, start_pair.size())
    {
        pair<LL,LL> pr = start_pair[i];
        rep(j, vp.size())
        {
            pair<LL,LL> pr2 = vp[j];
            if(pr2.first == pr.second + 1)
                    mid_pair.push_back(pr2);
        }
    }

    int sub_ways = 0;
    rep(i, mid_pair.size())
    {
        pair<LL,LL> pr = mid_pair[i];
        rep(j, vp.size())
        {
            pair<LL,LL> pr2 = vp[j];
            if(pr2.first == pr.second + 1)
            {
                if(pr2.second == n-1)
                    sub_ways++;
            }
        }
    }

    cout << sub_ways << endl;
    return 0;
}

vector<pair<LL,LL>> subArySum(vector<LL> v,LL k)
{
    vector<pair<LL,LL>> res;
    map<LL,LL> result;
    map<LL,vector<LL>> mp;
    vector<LL> initial;
    initial.push_back(-1);
    mp[0] = initial;
    LL preSum = 0;

    //loop across all elements of the array
    for(LL i = 0;i<v.size();++i)
    {
        preSum += v[i];
        // If point where sum = (preSum - k) is present, it means that between that
        // point and this, the sum has to equal k
        if(mp.count(preSum-k) > 0)
        {
            //subarray found
            vector<LL> startIndices = mp[preSum-k];
            if(startIndices.size() > 0)
            {
                for(LL z = 0;z < startIndices.size();++z)
                {
                    LL start = startIndices[z];
                    pair<LL, LL> p = make_pair(start+1,i);
                    res.push_back(p);
                }
            }
        }
        vector<LL> newStart;
        if(mp.count(preSum) > 0)
            newStart = mp[preSum];

        newStart.push_back(i);
        mp[preSum] = newStart;
    }

    return res;
}
