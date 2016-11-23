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

#define MAX 996

int main() {
    int n,m;
    cin >> n >> m;
    int* a = new int[m];
    for(int i = 0;i<m;i++)
        cin >> a[i];
    sort(a, a+m);
    int min = MAX;
    for(int i = 0;i<=m-n;i++)
    {
        if(i+n-1 < m)
        {
            min = ((a[i+n-1]-a[i]) < min)?(a[i+n-1]-a[i]):min;
        }
    }
    cout << min;
    return 0;
}
