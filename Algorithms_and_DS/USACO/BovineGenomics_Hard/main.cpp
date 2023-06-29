#include <bits/stdc++.h>

const int low = 50;
const int high = 500;
const int r = 64;
int n, m;
std::string spotted[high],  plained[high];
int spotted_[high][low], plained_[high][low], random_[r];

bool check(int first, int second, int third )
{
  bool check_ = true;
  for(int i = 0; i < n; i++)
    random_[spotted_[i][first]*16 + spotted_[i][second]*4 +
    spotted_[i][third]] = 1;

  for(int i = 0; i < n; i++)
    if(random_[plained_[i][first]*16 + plained_[i][second]*4 +
            plained_[i][third]]) check_ = false;

  for(int i = 0; i < n; i++)
    random_[spotted_[i][first]*16 + spotted_[i][second]*4 +
            spotted_[i][third]] = 0;
  return check_;
}

int main()
{
  //freopen("cownomics.out","w",stdout);
  //freopen("cownomics.in", "r", stdin);
  std::cin >> n >> m;
  for(int i = 0; i < n; i++)
  {
    std::cin >> spotted[i];
    for(int j = 0; j < m; j++)
    {
      if(spotted[i][j] == 'A') spotted_[i][j] == 0;
      if(spotted[i][j] == 'C') spotted_[i][j] == 1;
      if(spotted[i][j] == 'G') spotted_[i][j] == 2;
      if(spotted[i][j] == 'T') spotted_[i][j] == 3;
    }
  }

  for(int i = 0; i < n; i++)
  {
    std::cin >> plained[i];
    for(int j = 0; j < m; j++)
    {
      if(plained[i][j] == 'A') plained_[i][j] == 0;
      if(plained[i][j] == 'C') plained_[i][j] == 1;
      if(plained[i][j] == 'G') plained_[i][j] == 2;
      if(plained[i][j] == 'T') plained_[i][j] == 3;
    }
  }

  int ans = 0;
  for(int i = 0; i < m; i++)
  {
    for(int j = i+1; j < m; j++)
    {
      for(int k = j+1; k < m; k++)
      {
        if(check(i, j, k)) ans++;
      }
    }
  }

  std::cout << ans;

}