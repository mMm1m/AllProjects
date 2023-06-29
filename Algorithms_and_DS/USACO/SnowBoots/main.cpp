#include <bits/stdc++.h>

struct Boots
{
  int depth, step, index;
  Boots(int d, int s, int idx)
  {
    depth = d;
    step = s;
    index = idx;
  }
};

int main()
{
  int n,b;
  std::cin >> n >> b;

  std::vector<int> tiles, depth_tiles;
  std::vector<Boots> boots;
  bool answer[b];
  std::set<int> valid_tiles;

  for(int i = 0; i < n; i++)
  {
    int val;
    std::cin >> val;
    tiles.push_back(val);
  }
  for(int i = 0;  i < b; i++)
  {
    int depth, step;
    std::cin >> depth >> step;
    boots.push_back(Boots(depth, step, i));
  }
  std::sort(boots.begin(), boots.end(), [](const Boots& boot1, const Boots& boot2){
    if(boot1.step==boot2.step)
      return boot1.depth > boot2.depth;
    return boot1.depth > boot2.depth;
  });

  for(int i = 1;  i < n-1; i++)
    depth_tiles.push_back(i);
  std::sort(depth_tiles.begin(), depth_tiles.end(), [&](const int& a, const int& b){
    return tiles[a] > tiles[b];
  });

  for(int i = 0; i < n; i++)
    valid_tiles.insert(i);

  int current = 0, need_step = 1;
  for(int i = b-1; i >= 0; i--)
  {
    while(current < depth_tiles.size() && tiles[depth_tiles[current]] > boots[i].depth)
    {
      auto deleted_value = valid_tiles.find(depth_tiles[current]);
      need_step = std::max(need_step, *std::next(deleted_value) - *std::prev(deleted_value));
      valid_tiles.erase(deleted_value);
      current++;
    }
    answer[boots[i].index] = (boots[i].step >= need_step);
  }
  for(auto& a : answer)
    std::cout << a << '\n';

  /*for(auto& a : depth_tiles)
    std::cout << a << " ";
  std::cout << '\n';
  for(auto& a : valid_tiles)
    std::cout << a << " ";*/
}

