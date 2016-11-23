/*
After the lessons n groups of schoolchildren went outside and decided to visit Polycarpus to celebrate his birthday. We know that the i-th group consists of si friends (1 ≤ si ≤ 4), and they want to go to Polycarpus together. They decided to get there by taxi. Each car can carry at most four passengers. What minimum number of cars will the children need if all members of each group should ride in the same taxi (but one taxi can take more than one group)?

Input
The first line contains integer n (1 ≤ n ≤ 105) — the number of groups of schoolchildren. The second line contains a sequence of integers s1, s2, ..., sn (1 ≤ si ≤ 4). The integers are separated by a space, si is the number of children in the i-th group.

Output
Print the single number — the minimum number of taxis necessary to drive all children to Polycarpus.
*/
#include<iostream>
#include<vector>
using namespace std;

int main(){
  int n,s_i;
  int cars = 0;
  vector<int> unmatched_1;
  vector<int> unmatched_2;
  vector<int> unmatched_3;

  cin >> n;
  while(n--){
    cin >> s_i;
    if(s_i == 4){
      cars++;
    }else if(s_i == 3){
      unmatched_3.push_back(s_i);
    }else if(s_i == 2){
      unmatched_2.push_back(s_i);
    }else if(s_i == 1){
      unmatched_1.push_back(s_i);
    }
  }
  //first do 3-1 match
  while(unmatched_1.size()!=0 && unmatched_3.size()!=0){
    cars++;
    unmatched_1.erase(unmatched_1.begin());
    unmatched_3.erase(unmatched_3.begin());
  }
  //second do 2-2 match
  if(unmatched_2.size()%2 == 0){
    cars += unmatched_2.size()/2;
    unmatched_2.clear();
  }else{
    cars += unmatched_2.size()/2;
    unmatched_2.clear();
    unmatched_2.push_back(2);
  }
  //third do 2-1 match
  if(unmatched_1.size() == 0){
    //do nothing
  }
  else{
    if(unmatched_2.size() != 0 && unmatched_1.size() >=2){
      cars += 1;
      unmatched_2.clear();
      unmatched_1.erase(unmatched_1.begin());
      unmatched_1.erase(unmatched_1.begin());
    }else if(unmatched_2.size() != 0 && unmatched_1.size() <2){
      for(int z = 0;z<unmatched_1.size();z++)
        unmatched_1.erase(unmatched_1.begin());
    }
  }
  //fourth do 1-1-1-1 match
  cars += unmatched_1.size()/4;
  int left = unmatched_1.size() % 4;
  if(left > 0)
    cars += 1;

  if(unmatched_2.size()!=0)
    cars +=1;
  cars += unmatched_3.size();
  cout << cars;
  return 0;
}
