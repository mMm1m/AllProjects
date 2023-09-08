#include <bits/stdc++.h>

static long a,b, curr =  0;

const long long MOD = (long long)2e64;
unsigned int nextRand24()
{
  curr = (curr*a+b) & ((1ll << 32) - 1);
  return curr >> 8;
}

unsigned int nextRand32()
{
  unsigned int a_ = nextRand24(), b_ = nextRand24();
  return ((a_ << 8) ^ b_) & ((1ll << 32) - 1);
}

int maximum(const std::vector<int>& v)
{
  int max = -INT_MAX;
  for(auto& f : v) max = std::max(f, max);
  return max;
}

void countSort(std::vector<int>& v, int n, int index)
{
  std::vector<int> tmp(10), answer(n);
  for(int i = 0; i < n; ++i)
  {
    tmp[(v[i]/index)%10]++;
  }
  for(int i = 1; i < 10; ++i )
  {
    tmp[i] += tmp[i-1];
  }
  for(int i = n-1; i >= 0; --i)
  {
    answer[tmp[(v[i]/index)%10]-1] = v[i];
    tmp[(v[i]/index)%10]--;
  }
  std::copy(answer.begin(), answer.end(), v.begin());
}

void radixSort(std::vector<int>& v, int n)
{
  int max = maximum(v);
  for(int i = 1; max/i > 0; i*= 10)
  {
    countSort(v,n,i);
  }
}

int main()
{
  int t,n; std::cin >> t;
  std::vector<int> tests(t);
  for(int i = 0; i < t; ++i)
  {
    std::cin >> n; tests[i] = n;
  }
  for(int i = 0; i < t; ++i)
  {
    std::vector<int> v(tests[i]);
    std::cin >> a >> b;
    curr = 0;
    for(int k = 0; k < tests[i]; ++k) v[k] = nextRand32();
    radixSort(v,tests[i]);
    int ans = 0;
    for(int k = 0; k < tests[i]; ++k) { ans += (k+1)*v[k]; ans %= MOD;}
    std::cout << ans << '\n';
  }
}
