#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

void input_grid(vector<string> &v, int row)
{
  string s;
  for (int i = 0;i < row;++i)
  {
    cin >> s;
    v.push_back(s);
  }
}

bool contains_grid(vector<string> &v, int start_row, int start_col, vector<string> &g)
{
  int row = g.size();
  int col = g[0].size();
  int t_col = start_col;
  for (int i = 0;i < row;++i)
  {
    for (int j = 0;j < col;++j)
      if (v[start_row][t_col++] != g[i][j]) return false;
    t_col = start_col;
    ++start_row;
  }
  return true;
}

int main()
{
  int T, R, C, r, c;
  vector<string> v, g;
  cin >> T;
  string s;
  while (T--)
  {
    v.clear();g.clear();
    cin >> R >> C;
    input_grid(v, R);
    cin >> r >> c;
    input_grid(g, r);
    bool flag = false;
    for (int i = 0;i < R-r+1;++i)
    {
      for (int j = 0;j < C-c+1;++j)
      {
        if (contains_grid(v, i, j, g))
        {
          flag = true;
          break;
        }
      }
      if (flag) break;
    }
    if (flag) cout << "YES" << endl;
    else cout << "NO" << endl;
  }
  return 0;
}

/**
1 2 3 3
2 1 3 4
4 3 2 1
2 3 1 1

1 3
3 2
3 1

r [0, 1] [0, R - r]
c [0, 2] [0, C - c]
*/
