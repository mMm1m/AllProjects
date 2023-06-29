#include <bits/stdc++.h>
#define ll long long

using namespace std;

int solve(){
  string s;cin>>s;
  map<char,ll>mp;
  for(auto x:s)mp[x]++;
  int cnt=mp.size();
  int i=0,j=s.size()-1;
  for(auto&x:mp){
    ll a=x.second/2;
    while(a--){
      s[i++]=x.first;
      s[j--]=x.first;
    }
    if(x.second%2){
      if(cnt>2){
        s[j--]=x.first;
        x.second=0;
        break;
      }
    }
    x.second%=2;
    cnt--;
  }
  for(auto x:mp){
    while(x.second--){
      s[i++]=x.first;
    }
  }
  string s1=s;
  reverse(s1.begin(),s1.end());
  if(s1<s)
    cout<<s<<'\n';
  else
    cout<<s1<<'\n';
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int t;cin>>t;
  while(t--){
    solve();
  }
}