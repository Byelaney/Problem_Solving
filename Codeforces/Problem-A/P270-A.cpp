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

    int t;
    cin >> t;
    int a;
    while(t--)
    {
        cin >> a;
        if(360 % (180-a) == 0)
            cout << "YES\n" ;
        else
        {
            cout << "NO\n";
        }

    }
    
    return 0;
}
