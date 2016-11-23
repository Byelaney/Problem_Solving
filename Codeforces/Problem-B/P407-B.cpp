//
//  main.cpp
//  Acm
//
//  Created by 管君 on 16/3/14.
//  Copyright © 2016年 カンクン. All rights reserved.
//

#include <stdio.h>

bool friends(int a,int b,int limit);

int main() {
    int n,m,k;
    int* x_i = new int[m+1];
    scanf("%d",&n);
    scanf("%d",&m);
    scanf("%d",&k);


    int tmp;
    for(int i = 0;i<m+1;i++)
    {
        scanf("%d",&tmp);
        x_i[i] = tmp;
    }

    int f = 0;
    int fedor = x_i[m];
    for(int i = 0;i<m;i++)
    {
        if (friends(fedor,x_i[i],k))
            f++;
    }

    printf("%d",f);
    return 0;
}

bool friends(int a,int b,int limit)
{
    int diff = 0;
    int CHART[21] ={1048576,524288,262144,131072,
                    65536,32768,16384,8192,4096,
                    2048,1024,512,256,128,64,32,16,
                    8,4,2,1};

    for(int i = 0;i<21;i++)
    {
        if(a-CHART[i] >= 0 && b-CHART[i] >= 0)
        {
            a -= CHART[i];
            b -= CHART[i];
        }
        if(a-CHART[i] >= 0 && b-CHART[i] < 0)
        {
            diff++;
            a -= CHART[i];
        }
        else if(a-CHART[i] < 0 && b-CHART[i] >= 0)
        {
            diff++;
            b -= CHART[i];
        }
    }
    if(diff > limit)
        return false;
    else
        return true;
}
