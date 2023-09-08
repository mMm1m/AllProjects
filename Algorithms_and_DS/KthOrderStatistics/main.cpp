#include <bits/stdc++.h>

int partition(std::vector<int>& arr, int l, int r)
{
  int x = arr[r], i = l;
  for (int j = l; j <= r - 1; j++) {
    if (arr[j] <= x) {
      std::swap(arr[i], arr[j]);
      i++;
    }
  }
  std::swap(arr[i], arr[r]);
  return i;
}

int randomPartition(std::vector<int>& arr, int l, int r)
{
  int n = r - l + 1;
  int pivot = (rand() % 100 + 1) % n;
  std::swap(arr[l + pivot], arr[r]);
  return partition(arr, l, r);
}

int k_th_ordered_statistics(std::vector<int>& arr,int l, int r, int k)
{
  if (k > 0 && k <= r - l + 1) {
    while(l <= r) {
      int pos = randomPartition(arr, l, r);
      if (pos == k - 1) return arr[pos];

      else if (pos > k - 1) r = pos-1;
      else l = pos+1;
    }
  }
  return INT_MAX;
}

int solution(int n, int a, int b, int c,int a1, int a2,int k)
{
  std::vector<int> vector(n);
  vector[0] = a1;
  if(n==1) {return a1;}
  else
  {
    vector[1] = a2;
    for(int i = 2; i < n; ++i)
    {
      vector[i] = a* vector[i-2]+b*vector[i-1]+c;
    }
  }
  for(auto& a : vector) std::cout << a << " ";
  std::cout << '\n';
  return k_th_ordered_statistics(vector, 0, n-1, k);
}

int main()
{
  int n, k, a,b,c,a1, a2;
  std::cin >> n >> k >> a >> b >> c >> a1 >> a2;
  std::cout << solution(n,a,b,c,a1,a2,k);
}
