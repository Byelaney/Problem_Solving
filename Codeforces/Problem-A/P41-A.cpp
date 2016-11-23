//
//  main.cpp
//  Acm
//
//  Created by 管君 on 16/3/14.
//  Copyright © 2016年 カンクン. All rights reserved.
//

#include <iostream>
#include <string>

using namespace std;

int main() {
    string t,s;
    cin >> t;
    cin >> s;
    bool flag = true;
    for(int i = 0;i<t.length();i++)
    {
        if (t[i] != s[s.length()-i-1])
        {
            flag = false;
            break;
        }
    }
    if(flag)
        cout << "YES";
    else
        cout << "NO";
    return 0;
}
