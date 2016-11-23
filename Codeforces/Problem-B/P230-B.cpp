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


#define sf scanf
#define pf printf
#define rep(i,n) for(int i = 0;i<n;++i)
#define FOR(i,s,e) for(int i = s;i<=e;++i)
#define LL long long
#define ULL unsigned long long

using namespace std;

static bool prime[1000001];

bool T_Prime(ULL num);
bool isPrime(ULL n);
void init();

int main()
{
    ios::sync_with_stdio(0);
    int n;
    cin >> n;
    ULL num;
    init();
    while(n--)
    {
        cin >> num;
        if(T_Prime(num))
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }

    return 0;
}


bool T_Prime(ULL num)
{
    ULL root = sqrt((double)num);
    if(prime[root] && root*root == num)
        return true;

    return false;
}

bool isPrime(ULL n)
{
    if (n <= 3) {
        return n > 1;
    } else if (n % 2 == 0 || n % 3 == 0) {
        return false;
    } else {
        for (unsigned short i = 5; i * i <= n; i += 6) {
            if (n % i == 0 || n % (i + 2) == 0) {
                return false;
            }
        }
        return true;
    }
}


void init()
{
    rep(i, 1000001)
        if(isPrime(i))
            prime[i] = true;
        else
            prime[i] = false;
}
