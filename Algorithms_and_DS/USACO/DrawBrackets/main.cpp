#include <bits/stdc++.h>

int main()
{
  int n;
  std::cin >> n;
  std::string str;
  std::cin >> str;
  int open = 0, close = 0, max = 0;
  for(int i = 0; i < n; i++)
  {
    if(str[i]=='[') open++;
    else if(str[i]==']') close++;
    max = std::max(max, std::abs(open-close));
  }
  int high = 2;
  for(int i = 0; i < n-1; i++)
  {
    if(str[i]=='['&&str[i+1]=='[') high += 1;
    if(str[i]=='['&&str[i+1]==']') high+=3;
    if(str[i]==']'&&str[i+1]==']') high += 1;
    if(str[i]==']'&&str[i+1]=='[') high += 2;
  }
  max = 2*max+1;
  std::vector<std::vector<char>> v(max, std::vector<char>(high, ' '));
  v[0][0] = '+'; v[0][1] = '-'; v[max-1][0] = '+'; v[max-1][1] = '-';
  int k = 0, j = 1, low_k = max-1;
  for(int i = 0; i < n-1; i++)
  {
    if(str[i]=='['&&str[i+1]=='['){
      v[k+1][j] = '+'; v[k+1][j+1] = '-';
      v[low_k-1][j] = '+'; v[low_k-1][j+1] = '-';
      ++k; ++j; --low_k;
    }
    if(str[i]=='['&&str[i+1]==']')
    {
      v[k][j+1] = ' '; v[k][j+2] = '-'; v[k][j+3] = '+';
      v[low_k][j+1] = ' '; v[low_k][j+2] = '-'; v[low_k][j+3] = '+';
      j +=3;
    }
    if(str[i]==']'&&str[i+1]==']')
    {
      v[k-1][j] = '-'; v[k-1][j+1] = '+';
      v[low_k+1][j] = '-'; v[low_k+1][j+1] = '+';
      --k; ++j; ++low_k;
    }
    if(str[i]==']'&&str[i+1]=='[')
    {
      v[k][j+1] = '+'; v[k][j+2] = '-';
      v[low_k][j+1] = '+'; v[low_k][j+2] = '-';
      j +=2;
    }
  }
  for(int i = 0; i < high; i++)
  {
    int count = 0;
    for(int j = 0; j < max; j++)
    {
      if(v[j][i]=='+') ++count;
      if(count ==1 && v[j][i]==' ') v[j][i] = '|';
    }
  }


  for(int i = 0; i < max; i++)
  {
    for(int j = 0; j < high; j++)
    {
      std::cout << v[i][j];
    }
    std::cout << '\n';
  }
}
