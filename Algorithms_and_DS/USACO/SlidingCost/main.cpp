#include <iostream>
#include <set>
#include <algorithm>
using namespace std;
using ll = long long;
const ll mn = (ll) 2e5+5;

ll N, K;
ll arr[mn];
multiset<ll> up;
multiset<ll> low;
ll sLow, sUp;

void ins(ll val){
  ll a = *low.rbegin();
  if(a < val){
    up.insert(val); sUp += val;
    if(up.size() > K/2){
      ll moving = *up.begin();
      low.insert(moving); sLow += moving;
      up.erase(up.find(moving)); sUp -= moving;
    }
  }
  else{
    low.insert(val); sLow += val;
    if(low.size() > (K + 1)/2){
      ll moving = *low.rbegin();
      up.insert(*low.rbegin()); sUp += moving;
      low.erase(low.find(*low.rbegin())); sLow -= moving;
    }
  }
}

void er(ll val){
  if(up.find(val) != up.end()) up.erase(up.find(val)), sUp -= val;
  else low.erase(low.find(val)), sLow -= val;
  if(low.empty()){
    ll moving = *up.begin();
    low.insert(*up.begin()); sLow += moving;
    up.erase(up.find(*up.begin())); sUp -= moving;
  }
}

ll med(){ return (K%2 == 0) ? 0 : (*low.rbegin()); }

int main() {
  cin >> N >> K;
  for(ll i = 0; i < N; i++) cin >> arr[i];
  low.insert(arr[0]); sLow += arr[0];
  for(ll i = 1; i < K; i++) ins(arr[i]);
  cout << sUp - sLow + med(); if(N!=1) cout << " ";
  for(ll i = K; i < N; i++){
    if(K == 1){
      ins(arr[i]);
      er(arr[i - K]);
    }
    else{
      er(arr[i - K]);
      ins(arr[i]);
    }
    cout << sUp - sLow + med(); if(i != N -1) cout << " ";
  }
  cout << endl;
}



/*#include <bits/stdc++.h>
using ll = long long;

int main()
{
  ll n, k;
  std::cin >> n >> k;
  std::vector<ll> v(n);
  std::set<std::pair<ll,ll>> left, right;
  for(auto& a : v)
    std::cin >> a;
  ll leftSum = 0, rightSum = 0;

  if(k==1)
  {
    for(int i = 0; i < n; i++)
      std::cout << 0 << " ";
    return 0;
  }
  if(k==2)
  {
    for(int i = 1; i < n; i++)
      std::cout << std::abs(v[i]-v[i-1]) << " ";
    return 0;
   }
  std::vector<std::pair<ll,ll>> vp;
  for(int i = 0; i < k; i++)
  {
    vp.push_back({v[i],i});
  }
  std::sort(vp.begin(), vp.end());

  for(ll i = 0; i < k/2 + (k%2); i++)
  {
    left.insert(vp[i]);
    leftSum += vp[i].first;
  }
  for(ll i = k/2 + (k%2); i < k; i++)
  {
    right.insert(vp[i]);
    rightSum += vp[i].first;
  }
  ll mediana = left.rbegin()->first;
  std::cout << mediana*left.size()-leftSum+rightSum-mediana*right.size() << " ";

  for(int f = 1; f < n-k+1; f++)
  {
    if(left.count({v[f-1], f-1}))
    {
      leftSum -= v[f-1];
      left.erase({v[f-1],f-1});
    }
    else
    {
      rightSum -= v[f-1];
      right.erase({v[f-1], f-1});
    }
    if(*left.rbegin() > std::make_pair(v[f+k-1],f+k-1))
    {
      rightSum += v[f+k-1];
      right.insert({v[f+k-1],f+k-1});
    }
    else
    {
      leftSum += v[f+k-1];
      left.insert({v[f+k-1],f+k-1});
    }
    while(left.size()<k/2+(k%2))
    {
      std::pair<ll,ll> p = *right.begin();
      left.insert(p);
      leftSum += p.first;

      rightSum -= p.first;
      right.erase(p);
    }
    while(left.size()>k/2+(k%2))
    {
      std::pair<ll,ll> p = *left.begin();
      left.erase(p);
      leftSum -= p.first;

      rightSum += p.first;
      right.insert(p);
    }
    ll mediana = left.rbegin()->first;
    std::cout << mediana*(left.size()-right.size())-leftSum+rightSum << " ";
  }
}*/