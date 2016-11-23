#include<iostream>
using namespace std;

int main(){
  int n;
  cin >> n;

  string str;
  for(int i = 0;i<n;i++){
    cin >> str;

    if(str.size()<=10)
      cout << str << endl;
      else{

        cout << str[0];
        cout << str.size() - 2;
        cout << str[str.size()-1] << endl;

      }

    }


    return 0;
  }
