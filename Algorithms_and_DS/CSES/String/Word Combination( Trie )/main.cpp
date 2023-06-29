#include <bits/stdc++.h>
using ll = long long;
const ll MOD = 1e9+7;

struct TrieNode{
  struct TrieNode* child[26];
  bool isEnd;
  TrieNode(){
    isEnd = false;
    for(ll i=0;i<26;i++){
      child[i] = nullptr;
    }
  }
};

TrieNode *root;
bool searchString(std::string str){
  TrieNode *curr = root;
  ll n = str.length();
  for(ll i=0;i<n;i++){
    int idx = str[i] - 'a';
    if(curr->child[idx]== nullptr)
      return false;
    curr = curr->child[idx];
  }
  return curr->isEnd;
}

void insertString(std::string str){
  TrieNode *curr = root;
  ll n = str.length();
  for(ll i=0;i<n;i++){
    int idx = str[i] - 'a';
    if(curr->child[idx] == nullptr)
      curr->child[idx] = new TrieNode();
    curr = curr->child[idx];
  }
  curr->isEnd = true;
}

void solve(ll tc){
  std::string str;
  std::cin>>str;
  ll n;
  std::cin>>n;
  root = new TrieNode();
  for(ll i=0;i<n;i++){
    std::string st;
    std::cin>>st;
    insertString(st);
  }
  ll len = str.length();
  std::vector<int> dp(len+1);
  dp[len] = 1;

  for(ll i=len-1;i>=0;i--){
    TrieNode *test = root;
    for(ll j=i;j<len;j++){
      ll idx = str[j] - 'a';
      if(test->child[idx] == nullptr)
        break;
      test = test->child[idx];
      if(test->isEnd){
        dp[i] = dp[i]%MOD + dp[j+1]%MOD;
        dp[i] = dp[i]%MOD;
      }
    }
  }
  std::cout<<dp[0]<<'\n';
}

int main() {
  ll tt = 1;
  for(ll i=1;i<=tt;i++){
    solve(i);
  }
  return 0;
}
 