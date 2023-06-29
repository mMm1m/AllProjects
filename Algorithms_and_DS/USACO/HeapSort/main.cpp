/*#include <iostream>
#include <vector>
int m;

void sift_down(std::vector<int>& arr, int n, int i)
{
  int largest = i;
  int left = 2*i+1;
  int right = 2*i+2;
  if (left < n && arr[left] > arr[largest])
    largest = left;
  if (right < n && arr[right] > arr[largest])
    largest = right;
  if (largest != i) {
    int swap = arr[i];
    arr[i] = arr[largest];
    arr[largest] = swap;
    sift_down(arr, n, largest);
  }
}

void sift_up(std::vector<int>& arr)
{
  for(int i = 0; i < arr.size(); i++) {
    while (arr[i] < arr[(i - 1) / 2]) {
      std::swap(arr[i], arr[(i - 1) / 2]);
      i = (i-1)/2;
    }
  }
}

void heapify(std::vector<int>& arr)
{
  for(int i = 0; i < m; i++)
  {
    sift_up(arr);
  }
}

void heap_sort(std::vector<int>& arr)
{
  heapify(arr);
  int heapsize = arr.size();
  for(int i = 0; i < m; i++)
  {
    std::swap(arr[0], arr[m-1-i]);
    heapsize--;
    sift_down(arr, 0, i);
  }
}

int main()
{
  std::cin >> m;
  std::vector<int> arr(m);
  for(auto& a : arr)
    std::cin >> a;
  heap_sort(arr);

  for(auto& a : arr)
    std::cout << a << " ";
}*/


#include <iostream>

void sift_up(int arr[], int N)
{
  for(int i = 0; i < N; i++)
  {
    while(arr[i] > arr[(i-1)/2])
    {
      std::swap(arr[i], arr[(i-1)/2]);
      i = (i-1)/2;
    }
  }

}
void sift_down(int arr[], int N, int i)
{
  int largest = i;
  int l = 2 * i + 1;
  int r = 2 * i + 2;
  if (l < N && arr[l] > arr[largest])
    largest = l;
  if (r < N && arr[r] > arr[largest])
    largest = r;
  if (largest != i) {
    std::swap(arr[i], arr[largest]);
    sift_down(arr, N, largest);
  }
}

void printArray(int arr[], int N)
{
  for (int i = 0; i < N; ++i)
    std::cout << arr[i] << " ";
  std::cout << "\n";
}

void heapSort(int arr[], int N)
{
  for (int i = N / 2 - 1; i >= 0; i--)
    sift_down(arr, N, i);
  for (int i = N - 1; i > 0; i--) {
    std::swap(arr[0], arr[i]);
    sift_down(arr, i, 0);
  }
}

int main()
{
  int n;
  std::cin >> n;
  int arr[n];
  for(auto& a : arr)
    std::cin >> a;
  heapSort(arr, n);
  printArray(arr, n);
}