#include <bits/stdc++.h>
int count = 0;

void insertionSort(int N, int* arr)
{
  for(int i = 1; i < N; i++)
  {
    int constant = i;
    while(arr[i-1] > arr[i] && i > 0)
    {
      std::swap(arr[i], arr[i-1]);
      ++count;
      i = i - 1;
    }
    i = constant;
  }
}

int main(void) {

  int N;
  scanf("%d", &N);
  int arr[N], i;
  for(i = 0; i < N; i++) {
    scanf("%d", &arr[i]);
  }
  insertionSort(N, arr);
  std::cout << count;
  return 0;
}
