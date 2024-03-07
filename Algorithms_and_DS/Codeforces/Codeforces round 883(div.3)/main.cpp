#include <bits/stdc++.h>

// A

void A()
{
  int t; std::cin >> t;
  for(int i = 0; i < t; ++i)
  {
    int n, size = 0; std::cin >> n;
    std::priority_queue<int> pq;
    for(int j = 0; j < n; ++j)
    {
      int a, b; std::cin >> a >> b;
      pq.push(a-b);
    }
    while(pq.top() > 0)
    {
      ++size; pq.pop();
      if(size == n)
      {
        break;
      }
    }
    std::cout << size << '\n';
  }
}

void B()
{
  int t; std::cin >> t;
  for(int i = 0; i < t; ++i)
  {
    std::vector<std::string> v;
    std::set<std::set<char>> set;
    for(int j = 0; j < 3; ++j)
    {
      std::string str;
      std::cin >> str;
      v.push_back(str);
    }

    std::set<char> vert, hor;
    for(int j = 0; j < 3; ++j)
    {
      for(int k = 0; k < 3; ++k)
      {
        hor.insert(v[j][k]); vert.insert(v[k][j]);
      }
      set.insert(vert); set.insert(hor);
      vert.clear(); hor.clear();
    }
    vert.insert(v[0][0]); hor.insert(v[0][2]);
    vert.insert(v[1][1]); hor.insert(v[1][1]);
    vert.insert(v[2][2]); hor.insert(v[2][0]);
    set.insert(vert); set.insert(hor);
    vert.clear(); hor.clear();
    int counter = 0;
    for(const auto& a : set)
    {
      if(a.size() == 1 && *a.begin() != '.')
      {
        counter = 1;
        std::cout << *a.begin() << '\n';
        break;
      }
    }
    if(counter == 0) std::cout << "DRAW" << '\n';
  }
}

void C()
{
  int t; std::cin >> t;
  for(int i = 0; i < t; ++i)
  {
    int n,m,h, r_c = 0, r_t = 0, place = 1; std::cin >> n >> m >> h;
    for(int j = 0; j < n; ++j)
    {
      std::vector<int> vector;
        for(int k = 0; k < m; ++k)
        {
          int a; std::cin >> a;
          vector.push_back(a);
        }
        std::sort(vector.begin(), vector.end());
      int c_ = 0, t_= 0;
        if(j == 0)
        {
          if(!vector.empty()) {if(vector[0] <= h) {++r_c; r_t += vector[0];}}
            for (int k = 1; k < m; ++k)
            {
              vector[k] = vector[k]+vector[k-1];
              if(vector[k] <= h) {++r_c;  r_t += vector[k];}
              else break;
            }
        }
        else
        {
          if(!vector.empty()) {if(vector[0] <= h) {++c_; t_ += vector[0];} else break;}
            for (int k = 1; k < m; ++k)
            {
              vector[k] = vector[k]+vector[k-1];
              if(vector[k] <= h) {++c_; t_ += vector[k];}
              else break;
            }
        }
        if(r_c < c_) ++place;
        else if(r_c == c_)
        {
          if(r_t > t_) {++place;}
        }
    }
    std::cout << place << '\n';
  }
}

void D()
{
  int t; std::cin >> t;
  for(int i = 0; i < t; ++i)
  {
    double square = 0;
    int n,d,h; std::cin >> n >> d >> h;
    std::vector<int> a;
    for(int j = 0; j < n; ++j)
    {
      int a_; std::cin >> a_;
      a.push_back(a_);
    }
    square += (n*d*h/2.0);
    std::sort(a.begin(), a.end());
    double sum=n*1.0*d*h/2;
    for(int i=0;i<n-1;i++)
    {
      if(a[i+1]-a[i]<h)
      {
        int hh=h-a[i+1]+a[i];
        double dd=d*1.0*hh/2/h;
        sum-=dd*hh;
      }
    }
    printf("%.7lf\n",sum);
  }
}

int main()
{}
