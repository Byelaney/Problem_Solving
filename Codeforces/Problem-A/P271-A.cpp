#include <iostream>
using namespace std;

bool Unique(int y);

int main(){
  int y;
  cin >> y;
  y++;
  while(!Unique(y)){
    y++;
  }
  cout << y << endl;
  return 0;
}

bool Unique(int y){
  int num[10];
  for(int i = 0;i<10;i++){
    num[i] = -1;
  }
  int digit = 0;
  while(y > 0){
    num[y%10] = 1;
    y = y/10;
    digit++;
  }
  int rel = 0;
  for(int i = 0;i<10;i++){
    if(num[i] == 1)
      rel++;
  }
  if(rel == digit)
    return true;
  else
    return false;

}
