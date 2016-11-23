#include <iostream>
using namespace std;

bool isPrime(int);

int main(){
  int n;
  cin >> n;
  int a,b;
  a = 4;
  b = n - a;
  while(isPrime(a) || isPrime(b)){
    a++;
    b = n - a;
  }

  cout << a << " " << b;
  return 0;
}

bool isPrime(int n)
{
    if(n < 2) return false;

    for(int i = 2; i < n; ++i)
        if(n%i == 0) return false;

    return true;
}
