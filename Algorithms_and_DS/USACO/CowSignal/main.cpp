#include<bits/stdc++.h>
using namespace std;
int main(){
  freopen("cowsignal.in", "r", stdin);
  freopen("cowsignal.out", "w", stdout);
  int m,n,k;
  cin>>m>>n>>k;
  string s;
  while(m--){
    cin>>s;
    string ans;
    for(int i=0;i<n;i++){
      if(s[i]=='X'){
        for(int x=0;x<k;x++)
          ans+="X";
      }
      else{
        for(int y=0;y<k;y++)
          ans+=".";
      }
    }
    for(int i=0;i<k;i++)
      cout<<ans<<endl;
  }
  return 0;
}