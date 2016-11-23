/*
Petya started to attend programming lessons. On the first lesson his task was to write a simple program. The program was supposed to do the following: in the given string, consisting if uppercase and lowercase Latin letters, it:

deletes all the vowels,
inserts a character "." before each consonant,
replaces all uppercase consonants with corresponding lowercase ones.
Vowels are letters "A", "O", "Y", "E", "U", "I", and the rest are consonants. The program's input is exactly one string, it should return the output as a single string, resulting after the program's processing the initial string.

Help Petya cope with this easy task.
*/
#include<iostream>
#include<string.h>
#include<stdio.h>
using namespace std;

int main(){
  char str[101];
  char enum_str[12] = {'A', 'O', 'Y', 'E', 'U', 'I','a', 'o', 'y', 'e', 'u', 'i'};
  scanf( "%[^\n]%*c" , str );
  int len = strlen(str);
  for(int i = 0;i<len;i++){
    bool is_vowel = false;
    for(int j = 0;j<12;j++){
      if(enum_str[j] == str[i]){
        is_vowel = true;
        break;
      }
    }
    if(is_vowel != true){
      cout << '.';
      if(str[i] > 90){
        cout << str[i];
      }
      else{
        char a = str[i] + 32;
        cout << a;
      }
    }

  }
  return 0;
}
