#include <iostream>
#include <vector>

int pivot(std::vector<int>& v, int l, int r)
{
  int tmp = v[l+(r-l)/2];
  int i = l, j = r;
  while(i <= j)
  {
    while(v[i] < tmp) ++i;
    while(v[j] > tmp) --j;
    if(i >= j) break;
    std::swap(v[i++], v[j--]);
  }
  return j;
}

int partition(std::vector<int>& arr, int low, int high)
{
  int temp;
  int pivot = arr[high];
  int i = (low - 1);
  for (int j = low; j <= high - 1; j++)
  {
    if (arr[j] <= pivot)
    {
      i++;
      temp = arr[i];
      arr[i] = arr[j];
      arr[j] = temp;
    }
  }

  temp = arr[i + 1];
  arr[i + 1] = arr[high];
  arr[high] = temp;

  return (i + 1);
}

static int kthSmallest(std::vector<int>& a, int left,
                       int right, int k)
{
  while (left <= right)
  {
    int pivotIndex = partition(a, left, right);
    if (pivotIndex == k - 1)
      return a[pivotIndex];
    else if (pivotIndex > k - 1)
      right = pivotIndex - 1;
    else
      left = pivotIndex + 1;
  }
  return -1;
}

void qsort(std::vector<int>& v, int l, int r)
{
  if(l < r)
  {
    int piv = pivot(v, l, r);
    qsort(v, l, piv);
    qsort(v, piv+1, r);
  }
}


int main()
{
  int n,a; std::cin >> n;
  std::vector<int> v;
  for(int i = 0; i < n; ++i)
  {
    std::cin >> a;
    v.push_back(a);
  }
  qsort(v,0,n-1);
  if(n % 2 != 0) {std::cout << v[n/2] << " " << kthSmallest(v,0,n-1,n/2+1);}
  else std::cout << (int)((v[n/2]+v[n/2-1])/2) << " " <<
  (int)((kthSmallest(v,0,n-1,n/2+1) + kthSmallest(v,0,n-1,n/2))/2);

}
