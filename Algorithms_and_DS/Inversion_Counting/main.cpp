#include <bits/stdc++.h>

int merge(std::vector<int>& temp, std::vector<int>& src, int start, int mid, int end)
{
  int count = 0, i = start, j = mid+1, k = start;
  while(i <= mid && j <= end)
  {
    if(src[i] <= src[j]) {temp[k++] = src[i++];}
    else
    {
      temp[k++] = src[j++];
      count += (mid-i+1);
    }
  }
  while(i <= mid) temp[k++] = src[i++];
  std::copy(temp.begin(), temp.end(), src.begin());
  return count;

}

int merge_sort(std::vector<int>& temp, std::vector<int>& src, int start, int end)
{
  int count = 0, mid = (start + ((end-start)/2));
  if(end > start) {
    count += merge_sort(temp, src, start, mid);
    count += merge_sort(temp, src, mid + 1, end);
    count += merge(temp, src, start, mid, end);
  }
  return count;
}

int main()
{
  int n, tmp; std::cin >> n;
  std::vector<int> vector(n), temporary(n);
  for(int i = 0; i < n; ++i) {std::cin >> tmp; vector[i] = tmp;}
  std::copy(vector.begin(), vector.end(), temporary.begin());
  std::cout << merge_sort(temporary, vector, 0, n-1);
}



