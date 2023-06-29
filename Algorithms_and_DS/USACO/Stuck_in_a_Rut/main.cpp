#include <bits/stdc++.h>
using ll = long long;

const ll thousand = 1e3+1;

struct Cow
{
  ll idx;
  std::pair<ll, ll> pair;
  Cow(int index,const std::pair<ll, ll>& coordinates)
  {
    idx = index;
    pair.first = coordinates.first;
    pair.second = coordinates.second;
  }
};

bool cmp(const Cow &o, const Cow &t){
  if(o.pair.first == t.pair.first)
    return o.pair.second < t.pair.second;
  return o.pair.first < t.pair.first;
}

bool cmp2(const Cow &o, const Cow &t){

  if(o.pair.second == t.pair.second)
    return o.pair.first < t.pair.first;
  return o.pair.second < t.pair.second;
}

int main()
{
  int n;
  std::cin >> n;
  std::vector<Cow> vector_E;
  std::vector<Cow> vector_N;
  for(int i = 0; i < n; i++)
  {
    char idx_;
    ll x_, y_;
    std::cin >> idx_ >> x_ >> y_;
    idx_ == 'E' ? vector_E.push_back(Cow(i, {x_, y_})) : vector_N.push_back(Cow(i, {x_, y_}));;
  }

  std::sort(vector_E.begin(), vector_E.end(), cmp);
  std::sort(vector_N.begin(), vector_N.end(), cmp2);

  for(auto& a : vector_E)
    std::cout << a.idx << " " << a.pair.first << " " <<  a.pair.second << "\n";
  std::cout << "\n";

  for(auto& a : vector_N)
    std::cout << a.idx << " " << a.pair.first << " " <<  a.pair.second << "\n";
  std::cout << "\n";

  std::array<bool, 2501> bool_answer;
  std::array<ll, 2501> answer;
  bool_answer.fill(false);
  answer.fill(0);

  for(auto& a : vector_E)
  {
    for(auto& b : vector_N)
    {

      if(!bool_answer[a.idx] && !bool_answer[b.idx] && a.pair.first < b.pair.first &&
      a.pair.second > b.pair.second)
      {
        ll horizontal = std::abs(a.pair.first-b.pair.first);
        ll vertical = std::abs(a.pair.second-b.pair.second);

        if(vertical > horizontal)
        {
          bool_answer[a.idx] = true;
          answer[b.idx] += (1+answer[a.idx]);
        }

        if(horizontal > vertical)
        {
          bool_answer[b.idx] = true;
          answer[a.idx] += (1+answer[b.idx]);
        }
      }

    }
  }

  for(int i = 0; i < n; i++)
    std::cout << answer[i] << "\n";

}
