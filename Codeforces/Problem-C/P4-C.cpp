//
//  main.cpp
//  Acm
//
//  Created by 管君 on 16/3/14.
//  Copyright © 2016年 カンクン. All rights reserved.
//

#include <stdio.h>
#include <string>
#include <map>

using namespace std;

int main() {
    int n;
    scanf("%d",&n);
    map<string,int> m;
    string s;
    while (n--) {
        char tmp[33];
        scanf("%s",tmp);
        s = tmp;
        if(m.count(s) == 0)
        {
            m[s] = 1;
            printf("OK\n");
        }
        else
        {
            int i = m[s];
            m[s] = i + 1;
            printf("%s%d\n",tmp,i);
        }
    }
    return 0;
}

/*
This one is relatively easy,just use a map.
*/
