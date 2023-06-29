#include <iostream>

void swap(int* a, int* b)
{
  int t = *a;
  *a = *b;
  *b = t;
}

int partition (int arr[], int low, int high)
{
  int pivot = arr[high];    // pivot
  int i = (low - 1);

  for (int j = low; j <= high- 1; j++)
  {
    if (arr[j] <= pivot)
    {
      i++;
      swap(&arr[i], &arr[j]);
    }
  }
  swap(&arr[i + 1], &arr[high]);
  return (i + 1);
}

void quickSort(int arr[], int low, int high)
{
  if (low < high)
  {
    int pivot = partition(arr, low, high);
    quickSort(arr, low, pivot - 1);
    quickSort(arr, pivot + 1, high);
  }
}

void displayArray(int arr[], int size)
{
  int i;
  for (i=0; i < size; i++)
    std::cout<<arr[i]<<"\t";
}

int main()
{
  int n;
  std::cin >> n;
  int arr[n];
  for(int i = 0; i < n; i++)
    std::cin >> arr[i];
  quickSort(arr, 0, n-1);
  displayArray(arr,n);
  return 0;
}