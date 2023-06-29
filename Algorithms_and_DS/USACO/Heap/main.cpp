#include <iostream>
#include <vector>

std::vector<int> v;

void heapify(int arr[], int n, int i)
{
  int largest = i; // Initialize largest as root
  int l = 2 * i + 1; // left = 2*i + 1
  int r = 2 * i + 2; // right = 2*i + 2
  if (l < n && arr[l] > arr[largest])
    largest = l;
  if (r < n && arr[r] > arr[largest])
    largest = r;

  if (largest != i) {
    std::swap(arr[i], arr[largest]);
    heapify(arr, n, largest);
  }
}

// Function to delete the root from Heap
void deleteRoot(int arr[], int& n)
{
  v.push_back(arr[0]);
  int lastElement = arr[n - 1];
  arr[0] = lastElement;
  n = n - 1;
  heapify(arr, n, 0);
}

int insertNode(int arr[], int n, int Key)
{
  n = n + 1;
  arr[n - 1] = Key;
  heapify(arr, n, n - 1);
  return n;
}

int main()
{
  int curr_size = 0, n;
  std::cin >> n;
  int heap[100000];
  for(int i = 0; i < n; i++)
  {
    int index, value;
    std::cin >> index;
    if(index==0)
    {
      std::cin >> value;
      insertNode(heap, curr_size, value);
    }
    if(index == 1)
    {
      deleteRoot(heap, curr_size);
    }
  }
  for(int i = 0; i < 8; i++)
    std::cout << heap[i] << " ";
  for(auto& a : v)
    std::cout << a << '\n';
  return 0;
}