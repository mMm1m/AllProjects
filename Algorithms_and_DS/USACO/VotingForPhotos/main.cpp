#include <bits/stdc++.h>

struct Photo
{
  int id, likes, time;
  Photo(int id_, int likes_, int time_)
  {
    id = id_;
    likes = likes_;
    time = time_;
  }
};

void find_update(std::vector<Photo>& v,int id_, int curr_time)
{
  for(int i = 0; i < v.size(); i++)
  {
    if(v[i].id == id_)
    {
      ++v[i].likes;
      v[i].time = curr_time;
      return;
    }
  }
  v.push_back(Photo(id_, 1, curr_time));
}

bool cmp(const Photo& p1,const Photo& p2)
{
  if(p1.likes==p2.likes)
    return p1.time<p2.time;
  return p1.likes>p2.likes;
}

int main()
{
  int n;
  std::cin >> n;
  std::vector<Photo> photos;
  for(int i = 0; i < n; i++)
  {
    int val;
    std::cin >> val;
    find_update(photos, val, i+1);
  }
  std::sort(photos.begin(), photos.end(), cmp);
  std::cout << photos[0].id;
}
