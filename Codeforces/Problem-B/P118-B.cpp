#include <iostream>
using namespace std;

int main(){
  int n;
  cin >> n;

  int center_num = 2*n + 1;
  int blank_num = 2*n;
  for(int i = 0;i<center_num/2;i++){
    int tk = blank_num;
    while(tk--)
      cout << " ";

    cout << 0;
    for(int j = 0;j<i;j++){
        cout << " " << j+1;
    }
    for(int j = i;j>0;j--){
        cout << " " << j-1;
    }
    cout << endl;
    blank_num = blank_num - 2;
  }

  cout << 0;
  for(int i = 1;i<=n;i++)
      cout <<" " << i;
  for(int i = n-1;i>=0;i--)
      cout <<" " << i;
  cout << endl;

  blank_num = 2;
  for(int i = 0;i<center_num/2;i++){
    int tk = 1;
    while(tk <= blank_num){
        cout << " ";
        tk++;
    }

    cout << 0;
    for(int j = 0;j<n-i-1;j++)
        cout << " " << j+1;
    for(int j = n-i-1;j>0;j--)
        cout << " " << j-1;

    blank_num = blank_num + 2;
    cout << endl;
  }
  return 0;
}
