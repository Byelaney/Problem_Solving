/*
After the lessons n groups of schoolchildren went outside and decided to visit Polycarpus to celebrate his birthday. We know that the i-th group consists of si friends (1 ≤ si ≤ 4), and they want to go to Polycarpus together. They decided to get there by taxi. Each car can carry at most four passengers. What minimum number of cars will the children need if all members of each group should ride in the same taxi (but one taxi can take more than one group)?

Input
The first line contains integer n (1 ≤ n ≤ 105) — the number of groups of schoolchildren. The second line contains a sequence of integers s1, s2, ..., sn (1 ≤ si ≤ 4). The integers are separated by a space, si is the number of children in the i-th group.

Output
Print the single number — the minimum number of taxis necessary to drive all children to Polycarpus.
*/
#include<iostream>
using namespace std;

int main(){
  int n ;
  cin >> n;
  int cars = 0;
  int num1=0,num2=0,num3=0;
  int s_i;
  while(n--){
    cin >> s_i;
    if(s_i == 4)
      cars++;
    else if(s_i == 1)
      num1++;
    else if(s_i ==2)
      num2++;
    else
      num3++;
  }

  if(num3>=num1){
    cars += num1;
    num3 -= num1;
    cars += (num2%2==0)?num2/2:num2/2+1;
    cars += num3;
  }
  else{
    cars += num3;
    num1 -= num3;
    cars += num2/2;
    if(num2%2 == 1){
      if(num1 >= 2){
        cars += 1;
        num1 -= 2;
        cars += (num1%4==0)?num1/4:num1/4+1;
      }
      else{
        cars += 1;
      }
    }else{
      cars += (num1%4==0)?num1/4:num1/4+1;
    }

  }
  cout << cars;
  return 0;
}
