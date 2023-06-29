#include <bits/stdc++.h>

std::string ltrim(const std::string &);
std::string rtrim(const std::string &);
std::vector<std::string> split(const std::string &);

/*
 * Complete the 'insertionSort1' function below.
 *
 * The function accepts following parameters:
 *  1. INTEGER n
 *  2. INTEGER_ARRAY arr
 */

/*void insertionSort1(int n, std::vector<int> arr)
{
  // проходимся по вектору в обратном порядке
  for(int i=n-1;i>=1;i--)
  {
    // переменная равна последнему элементу вектора
    int key=arr[i];
    int j=i-1;
    // если предыдущий элемент вектора больше последующего -
    // ставим на место последующего - предыдущий
    while(arr[j]>key && j>=0)
    {
      arr[j+1]=arr[j];
      for(int k=0;k<n;k++)
        std::cout<<arr[k]<<" ";
      std::cout<<"\n";
      j--;

    }
    arr[j+1]=key;
    for(int k=0;k<n;k++)
      std::cout<<arr[k]<<" ";
    break;
  }
}*/

void insertionSort2(int n, std::vector<int> arr)
{
  for(int i = 1; i < n; i++)
  {
    int constant = i;
    while(arr[i-1] > arr[i] && i > 0)
    {
      ++count;
      i = i - 1;
    }
    i = constant;
  }
}

int main()
{
  std::string n_temp;
  getline(std::cin, n_temp);

  int n = stoi(ltrim(rtrim(n_temp)));

  std::string arr_temp_temp;
  getline(std::cin, arr_temp_temp);

  std::vector<std::string> arr_temp = split(rtrim(arr_temp_temp));

  std::vector<int> arr(n);

  for (int i = 0; i < n; i++) {
    arr[i] = stoi(arr_temp[i]);
  }

  // insertionSort1(n, arr);
  insertionSort2(n, arr);

  return 0;
}

std::string ltrim(const std::string &str) {
  std::string s(str);

  s.erase(
    s.begin(),
    find_if(s.begin(), s.end(), not1(std::ptr_fun<int, int>(isspace)))
  );

  return s;
}

std::string rtrim(const std::string &str) {
  std::string s(str);

  s.erase(
    find_if(s.rbegin(), s.rend(), not1(std::ptr_fun<int, int>(isspace))).base(),
    s.end()
  );

  return s;
}

std::vector<std::string> split(const std::string &str) {
  std::vector<std::string> tokens;

  std::string::size_type start = 0;
  std::string::size_type end = 0;

  while ((end = str.find(" ", start)) != std::string::npos) {
    tokens.push_back(str.substr(start, end - start));

    start = end + 1;
  }

  tokens.push_back(str.substr(start));

  return tokens;
}
