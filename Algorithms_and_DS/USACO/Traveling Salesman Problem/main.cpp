#include<bits/stdc++.h>
using namespace std;
int main()
{
  int t;
  cin>>t;
  while(t--)
  {
    int n;
    cin>>n;
    int x,y;
    int m=0,p=0,a=0,b=0;
    for(int i=0;i<n;i++){
      cin>>x;
      cin>>y;
      m=max(m,x);
      p=max(p,y);
      a=min(x,a);
      b=min(y,b);
    }
    cout<<2*(m+p-a-b)<<endl;
  }
  return 0;
}