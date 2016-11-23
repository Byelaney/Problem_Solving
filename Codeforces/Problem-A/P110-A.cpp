/**
Petya loves lucky numbers. We all know that lucky numbers are the positive integers whose decimal representations contain only the lucky digits 4 and 7. For example, numbers 47, 744, 4 are lucky and 5, 17, 467 are not.

Unfortunately, not all numbers are lucky. Petya calls a number nearly lucky if the number of lucky digits in it is a lucky number. He wonders whether number n is a nearly lucky number.

Input
The only line contains an integer n (1 ≤ n ≤ 10^18).

Please do not use the %lld specificator to read or write 64-bit numbers in С++. It is preferred to use the cin, cout streams or the %I64d specificator.

Output
Print on the single line "YES" if n is a nearly lucky number. Otherwise, print "NO" (without the quotes).
**/
#include <iostream>

using namespace std;

int main(){
  __int64 num,tmp;
  cin >> num;
  tmp = num;
  __int64 factor = 1;
  __int64 digits = 0;
  while(tmp > 0){
    tmp /= 10;
    factor *= 10;
    digits++;
  }
  factor /= 10;

  __int64 lucky_num = 0;

  for(__int64 i = 0;i<digits;i++){
    __int64 digit = num / factor;
    if(digit == 7 || digit == 4)
      lucky_num++;

    num %= factor;
    factor /= 10;
  }

  factor = 1;
  digits = 0;
  __int64 lucky_tmp;
  lucky_tmp = lucky_num;

  while(lucky_tmp > 0){
    lucky_tmp /= 10;
    factor *= 10;
    digits++;
  }
  factor /= 10;

  bool flag = false;
  for(__int64 i = 0;i<digits;i++){
    flag = true;
    __int64 digit2 = lucky_num / factor;
    if(digit2 != 7 && digit2 != 4){
      flag = false;
      break;
    }

    lucky_num %= factor;
    factor /= 10;

  }

  if(flag == true)
    cout << "YES";
  else
    cout << "NO";

  return 0;
}
