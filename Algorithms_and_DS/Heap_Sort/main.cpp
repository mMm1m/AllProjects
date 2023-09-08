#include <bits/stdc++.h>

  class Heap
  {
    public:
     std::vector<int> v;
     Heap(const std::vector<int>& vector);
     int l_child(int root);
     int r_child(int root);
     int parent(int child);
     void insert(int key);
     int extract();
     void sift_up(std::vector<int>& vector, int idx);
     void sift_down(std::vector<int>& vector, int idx);
  };

  Heap::Heap(const std::vector<int>& vector) : v(vector) {};
  int Heap::l_child(int root)
  {
    return 2*root+1;
  }
  int Heap::r_child(int root)
  {
    return 2*root+2;
  }
  int Heap::parent(int child)
  {
    return (child-1)/2;
  }
  void Heap::insert(int key)
  {
    v.push_back(key);
    if(v.size() > 1) {sift_up(v, v.size()-1);};
  }
  void Heap::sift_up(std::vector<int>& vector, int idx)
  {
    while (idx != 0 && vector[parent(idx)] < vector[idx])
    {
      std::swap(vector[idx], vector[parent(idx)]);
      idx = parent(idx);
    }
  }
  int Heap::extract()
  {
    int ans = v[0];
    v[0] = v[v.size()-1];
    v.pop_back();
    sift_down(v, 0);
    return ans;
  }
  void Heap::sift_down(std::vector<int>& vector, int index)
  {
    int largest = index;
    int left_ = l_child(index);
    int right_ = r_child(index);
    if(vector[left_] > vector[index] && left_ < v.size()) largest = left_;
    if(vector[right_] > vector[largest] && right_ < v.size()) largest = right_;
    if(largest != index)
    {
      std::swap(vector[index], vector[largest]);
      sift_down(vector, largest);
    }
  }

int main()
{
  int n, a, b; std::cin >> n;
  std::vector<int> vector;
  Heap heap(vector);
  for(int i = 0; i < n; ++i)
  {
    std::cin >> a;
    if(a == 0) {
      std::cin >> b;
      heap.insert(b);
    }
    else std::cout << heap.extract() << " " << '\n';
  }
}
