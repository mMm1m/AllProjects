#include <bits/stdc++.h>

class sum_query
{
  public:
   int left;
   int right;
   int sum;
   sum_query(int l, int r, int s)
   {
     left = l;
     right = r;
     sum = s;
   }
};

struct cmp
{
  bool operator()(const sum_query& s1, const sum_query& s2)
  {
    return s1.sum < s2.sum;
  }

};

int main()
{
  int n, k, tmp, ans; std::cin >> n >> k;
  std::vector<int> origin, prefix(n+1);
  for(int i = 0; i < n; ++i) {std::cin >> tmp; origin.push_back(tmp);}
  for(int i = 1; i <= n; ++i)
  {
    prefix[i] += prefix[i-1];
    prefix[i] += origin[i-1];
  }
  std::priority_queue<sum_query, std::vector<sum_query>, cmp> pq;
  pq.push(sum_query(0,n,prefix[n]-prefix[0]));
  if(k == 1) {ans = pq.top().sum;}
  else
  {
    int curr = 1;
    while(true) {
      int l = pq.top().left;
      int r = pq.top().right;
      int val = pq.top().sum;
      pq.pop();
      std::cout << pq.top().left << " " << pq.top().right
                << " " << pq.top().sum << '\n';
      int mid = l+(r-l)/2;
      pq.push(sum_query(l,mid, prefix[mid]-prefix[l]));
      pq.push(sum_query(mid,r, prefix[r]-prefix[mid]));
      ++curr;
      if(curr == k) {break;}
    }
    ans = pq.top().sum;
    std::cout << pq.top().left << " " << pq.top().right
              << " " << pq.top().sum << '\n';
  }
  std::cout << ans;
}
