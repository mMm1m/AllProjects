#include <bits/stdc++.h>

std::multiset<int> multiset;

std::vector<int> sol(int n, std::vector<int> v, int idx)
{
  for(auto& a : v)
    multiset.insert(a);
  std::vector<int> new_vector;
  for(int i = 0; i < n; i++) {
    auto end = --multiset.end();
    int k = idx - *end;
    multiset.erase(end);
    auto iterator = multiset.find(k);
    if (iterator == multiset.end()) return {};
    new_vector.push_back(k);
    new_vector.push_back(idx - k);
    idx = std::max(idx-k,k);
    multiset.erase(iterator);
  }
  return new_vector;
}

void solution()
{
  int n;
  std::cin >> n;
  std::vector<int> vector(2*n);
  for(int i = 0; i < 2*n; i++)
  {
    int val;
    std::cin >> val;
    vector.push_back(val);
  }
  std::sort(vector.begin(), vector.end());
  for(int i = 0; i < 2*n; i++)
  {
    int start_value = vector[i] + vector[2*n-1];
    std::vector<int> v = sol(n,vector,start_value);
    if(v.size())
    {
      std::cout << "YES" << '\n' << start_value << '\n';
      for(int k = 0; k < n; k++)
        std::cout << v[2*k] << " " << v[2*k+1] << '\n';
      return;
    }
  }
  std::cout << "NO" << '\n';
}

int main()
{
  int q;
  std::cin >> q;
  for(int i = 0; i < q; i++)
    solution();
}
