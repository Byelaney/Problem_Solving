//
//  main.cpp
//  Acm
//
//  Created by 管君 on 16/3/14.
//  Copyright © 2016年 カンクン. All rights reserved.
//

#include <stdio.h>

int main() {
    int n;
    scanf("%d",&n);
    double num;
    double percent = 0;
    for(int i = 0;i<n;i++)
    {
        scanf("%lf",&num);
        percent += num;
    }

    printf("%.13lf",percent/n);
    return 0;
}
