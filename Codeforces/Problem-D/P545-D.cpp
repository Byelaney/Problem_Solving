//
//  main.cpp
//  Acm
//
//  Created by 管君 on 16/3/14.
//  Copyright © 2016年 カンクン. All rights reserved.
//

#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(0);

    int n;
    cin >> n;
    int* a = new int[n];
    for(int i = 0;i<n;i++)
        cin >> a[i];

    sort(a,a+n);
    long long sum = a[0];
    int person = 1;
    for(int i = 1;i<n;i++)
    {
        if(sum <= a[i])
        {
            sum += a[i];
            person++;
        }
    }
    cout << person << "\n";
}

/*
Actually after the first sort,the first person could always be served.
Then we iterate the left sorted people,just compute the sum time of the
front people,and notice the '=' when current person equals the sum time
of the front people.
*/
