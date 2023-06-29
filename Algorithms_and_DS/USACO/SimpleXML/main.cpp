#include<bits/stdc++.h>
#define endl "\n"
#define ll long long
#define bismillah ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0)
#define khatam return 0
using namespace std;
int main()
{
 
  string s,s1,s2;
  queue<string> q;

  cin >> s;

  int len = s.length();
  for(int i=0; i<len; i++)
  {
    if(s[i]=='<')
      s1+=s[i];
    else if(s[i]>='a' && s[i]<='z')
      s1+=s[i];
    else if(s[i]=='/')
      s1+=s[i];
    else if(s[i]=='>')
    {
      s1+=s[i];
      q.push(s1);
      s1.clear();
    }
  }
  cout << q.front() << endl;
  q.pop();
  int sum = 0;
  while(!q.empty())
  {
    s2 = q.front();
    q.pop();
    int len1 = s2.length();
    bool flag = false;
    for(int i=0; i<len1; i++)
    {
      if(s2[i]=='/')
      {
        flag = true;
        break;
      }
    }
    if(!flag)
      sum++;

    for(int i=1; i<=2*sum; i++)
    {
      cout<<" ";
    }
    cout << s2 << endl;
    if(flag)
      sum--;
  }

}


