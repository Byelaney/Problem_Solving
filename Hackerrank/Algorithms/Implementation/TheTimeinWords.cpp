#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;


string minute_in_words(int minute_num, vector<string> table)
{
    string minute = "";
    if (minute_num == 30) minute = "half";
    else if (minute_num < 21) minute = table[minute_num];
    else
    {
        minute += table[20 + minute_num/10 -2] + " ";
        minute += table[minute_num%10];
    }
    return minute;
}

string time_in_words(int hour_num, int minute_num, vector<string> table)
{
    string time_words = "";
    string hour = table[hour_num];
    string minute_right_part = " minutes past ";
    if (minute_num == 0)
        return hour + " o' clock";
    else if (minute_num == 1) minute_right_part = " minute past ";
    else if (minute_num == 15 || minute_num == 30) minute_right_part = " past ";
    else if (minute_num > 30)
    {
        hour = table[hour_num + 1];
        minute_num = 60 - minute_num;
        minute_right_part = " minutes to ";
        if (minute_num == 15) minute_right_part = " to ";
    }
    time_words += minute_in_words(minute_num, table) + minute_right_part + hour;
    return time_words;
}

int main() {
    ios::sync_with_stdio(0);
//    ifstream input("input.txt");
//    ifstream output("output.txt");
    vector<string> table {"", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine", "ten", "eleven", "twelve", "thirteen", "fourteen","quarter", "sixteen", "seventeen", "eighteen", "nineteen", "twenty", "thirty", "forty", "fifty"};
    int hour, minute;
    cin >> hour >> minute;
    cout << time_in_words(hour, minute, table) << endl;
    return 0;
}
