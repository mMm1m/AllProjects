#include <bits/stdc++.h>

struct cow_card
{
  int day;
  std::string cow_name;
  int gallons;
  int start_;
};

void insertionSort(int N, cow_card* arr)
{
  for(int i = 1; i < N; i++)
  {
    int constant = i;
    while(arr[i-1].day > arr[i].day && i > 0)
    {
      int temp = arr[i-1].day;
      arr[i-1].day = arr[i].day;
      arr[i].day = temp;
      i = i - 1;
    }
    i = constant;
  }
}

int main()
{
  //freopen("measurement.in", "r", stdin);
  //freopen("measurement.out", "w", stdout);
  int n;
  std::cin >> n;
  cow_card arr[n];
  for(int i = 0; i < n; i++) {
    std::cin >> arr[i].day >> arr[i].cow_name >> arr[i].gallons;
    arr[i].start_ = 7;
  }
  cow_card count[n];
  for(int i = 0;  i < n; i++)
    count[i].gallons = 7;
  int answer = 0, best = 0;
  for(int i = 0; i < n;i++)
  {
    count[arr[i].day].gallons += arr[i].gallons;
  }
  return 0;
}
