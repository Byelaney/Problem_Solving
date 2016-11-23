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
#define MAX 1000000001
#define MIN 0

int main() {
    int n;
    scanf("%d",&n);
    int num;
    int max,min;
    unsigned long long max_num,min_num;
    max = MIN;
    min = MAX;
    max_num = 1;
    min_num = 1;
    for(int i = 0;i<n;i++)
    {
        scanf("%d",&num);
        if(num < min)
        {
            min = num;
            min_num = 1;
        }
        else if(num == min)
            min_num++;


        if( num > max)
        {
            max = num;
            max_num = 1;
        }
        else if(num == max)
            max_num++;
    }

    if(max != min)
    {
        printf("%d %llu\n",max-min,max_num * min_num);
    }
    else
    {
        printf("%d %llu\n",max-min,min_num * (min_num-1)/2);
    }

    return 0;
}
