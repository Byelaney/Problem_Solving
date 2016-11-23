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
#define r_rep(i,n) for(int i = n-1;i>=0;--i)
#define FOR(i,s,e) for(int i = s;i<=e;++i)
#define LL long long
#define ULL unsigned long long

using namespace std;

//before cnt[i],how many idx that S[i] == Sn/3
static int cnt[1000010];

int main()
{
    ios::sync_with_stdio(0);
    vector<LL> v;
    int n;
    cin >> n;
    v.push_back(0);
    LL sum = 0;
    rep(i, n)
    {
        LL num;
        cin >> num;
        sum += num;
        v.push_back(num);
    }

    if(sum % 3)
        cout << 0 << endl;
    else
    {
        sum /= 3;
        LL t_sum = v[0];
        cnt[0] = 0;
        for(int i = 1;i<=n;++i)
        {
            t_sum += v[i];
            cnt[i] += cnt[i-1];
            if(t_sum == sum)
            {
                cnt[i]++;
            }

        }

        LL ans = 0;
        t_sum = 0;
        for(int i = n;i>=1;--i)
        {
            t_sum += v[i];
            if(t_sum == sum)
            {
                int j = i - 2;
                if(j >= 0)
                {
                    ans += cnt[j];
                }
            }
        }

        cout << ans << endl;

//        rep(i, n)
//        cout << cnt[i] << endl;

    }
    return 0;
}

/*
  The main strategy is below:
  (1) first add all nums up denoted by Sn
  (2) check if Sn % 3 == 0,if not output 0 directly
  (3) if we can find i that a[1] + a[2] +... a[i] = Sn/3
      if we can find j that a[n] + a[n-1] + ... a[j] = Sn/3
      remember i should be <= j - 2(to make num exist between i and j)
      then we can conclude
      Sn = (Sn/3) + (Sn/3) + (Sn/3),which means this [i,j] split
      the whole nums correctly

  (4) iterate through a[1] to a[n-1] to find such S[i] = Sn/3
      cnt[i] stores the max numbers
  (5) iterate through a[n] to a[2] to find such S[j] = Sn/3
      if such j occurs, add cnt[j-2] to the final answer

*/
