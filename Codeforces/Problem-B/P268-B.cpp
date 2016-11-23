#include <iostream>
using namespace std;

int main(){
  int n;
  cin >> n;
  int sum = 0;
  int tmp = n-1;
  for(int i =1;i<=n;i++){
    sum = sum + tmp*i;
    tmp--;
  }

  cout << sum + n;
  return 0;
}
