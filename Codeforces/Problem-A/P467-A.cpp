#include <iostream>
using namespace std;

int main(){
  int rooms;
  cin >> rooms;
  int pi,qi;
  int movein = 0;
  while(rooms--){
    cin >> pi >> qi;
    if(qi-pi >= 2)
      movein++;
  }
  cout << movein << endl;
  return 0;
}
