#include <iostream>
using namespace std;

int main(){
  __int64 n,m,target;
  cin >> n >> m;
  __int64 start = 1;
  __int64 time = 0;
  while(m--)
  {
    cin >> target;
    while(start!=target)
    {
      if(start > target)
      {
        time += n - start + target;  
      }else
      {
        time += target - start;
      }
      start = target;
    }

  }
  cout << time;
  return 0;
}
