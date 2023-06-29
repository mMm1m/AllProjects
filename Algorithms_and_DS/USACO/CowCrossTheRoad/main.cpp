#include <bits/stdc++.h>

int main()
{
  freopen("helpcross.in", "r", stdin);
  freopen("helpcross.out", "w", stdout);
  int c,n;
  std::cin >> c >> n;
  std::vector<int> chicken(c);
  std::vector<std::pair<int,int>> cow(n);
  // ввод элементов в массив цыплят и коров, а также
  // отсортировать их в порядке неубывания
  for(int i = 0; i < c; i++)
    std::cin >> chicken[i];
  for(int i = 0; i < n; i++)
    std::cin >> cow[i].first >> cow[i].second;

  std::sort(chicken.begin(), chicken.end());
  std::sort(cow.begin(), cow.end());

  // создаём минимальную приоритетную очередь и ,проходя по массиву из цыплят,
  // если начальное время конкретной коровы не больше чем элемент из массива цыплят
  // кладём в очередь конечное время конкретной коровы и изменяем индекс
  int index = 0, answer = 0;
  std::priority_queue<int> pq;
  for(int i = 0; i < c; i++)
  {
    while(index < cow.size() && cow[index].first <= chicken[i])
    {
      pq.push(-cow[index].second);
      index++;
    }
    // беря верний элемент полученной очереди, если он меньше элемента из
    // массива цыплят под конкретным индексом, удаляем этот элемент и затем
    // очищаем очередь, одновременно с этим увеличивая ответ
    while(!pq.empty() && -pq.top() < chicken[i]) pq.pop();
    if(!pq.empty())
    {
      answer++;
      pq.pop();
    }
  }

  std::cout << answer;
}
