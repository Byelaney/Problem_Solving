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

#define MAX(a,b) a>b?a:b
#define MIN(a,b) a<b?a:b

int main() {
    ios::sync_with_stdio(0);

    int n,m;
    cin >> n;
    int* a = new int[n];
    for(int i = 0;i<n;++i)
    {
        cin >> a[i];
    }
    cin >> m;
    int* b = new int[m];
    for(int i = 0;i<m;++i)
    {
        cin >> b[i];
    }

    sort(a,a+n);
    sort(b,b+m);

    int i,j,diff;
    i = 0;
    j = 0;
    int pairs = 0;

    while(i < n && j < m)
    {
        diff = (a[i] > b[j])?(a[i]-b[j]):(b[j]-a[i]) ;
        if(diff <= 1)
        {
            ++pairs;
            ++i,++j;
        }
        else if(a[i] < b[j])
            ++i;
        else if(b[j] < a[i])
            ++j;
    }

    cout << pairs << "\n";
    return 0;
}
