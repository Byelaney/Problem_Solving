#include <iostream>
#include <string>
using namespace std;

int main(){
  int n,t;
  string bg;
  cin >> n >> t;
  cin >> bg;
  while(t--){
    for(int i = 0;i<n-1;){
      if(bg[i] == 'B' && bg[i+1] == 'G'){
        char tmp = bg[i];
        bg[i] = bg[i+1];
        bg[i+1] = tmp;
        i = i + 2;
      }else
        i++;

    }
  }

  for(int i = 0;i<n;i++)
    cout << bg[i];

  return 0;
}
