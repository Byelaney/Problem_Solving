//
//  main.cpp
//  Acm
//
//  Created by 管君 on 16/3/14.
//  Copyright © 2016年 カンクン. All rights reserved.
//

#include <stdio.h>
#include <algorithm>

using namespace std;

int main() {
    int n;
    scanf("%d",&n);
    int* fs = new int[n];
    for(int i = 0;i<n;i++)
    {
        scanf("%d",&fs[i]);
    }
    sort(fs,fs+n);

    int min = fs[0];
    unsigned long long min_num = 1;
    unsigned long long max_num = 1;
    int max = fs[n-1];

    for(int i = 1;i<n;i++)
    {
        if(fs[i] > min)
            break;
        else
            min_num++;
    }
    for(int i = n-2;i>=0;i--)
    {
        if(fs[i] < max)
            break;
        else
            max_num++;
    }

    if(fs[0] == fs[n-1])
    {
        printf("%d %llu\n",max-min,min_num * (min_num-1)/2);
    }
    else
        printf("%d %llu\n",max-min,min_num * max_num);
    return 0;
}
