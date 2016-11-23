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
    string ch;
    cin >> ch;
    int sum = 0;
    int i = 0;
    unsigned long n = ch.size();
    for(;i<n;)
    {
        if(ch[i++] == 'h')
        {
            sum++;
            break;
        }
    }
    for(;i<n;)
    {
        if(ch[i++] == 'e')
        {
            sum++;
            break;
        }
    }
    for(;i<n;)
    {
        if(ch[i++] == 'l')
        {
            sum++;
            break;
        }
    }
    for(;i<n;)
    {
        if(ch[i++] == 'l')
        {
            sum++;
            break;
        }
    }
    for(;i<n;)
    {
        if(ch[i++] == 'o')
        {
            sum++;
            break;
        }
    }
    if(sum == 5)
        cout << "YES";
    else
        cout << "NO";
    return 0;
}
