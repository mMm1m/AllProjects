#include <bits/stdc++.h>
using ll = long long;

int main()
{
  ll n;
  std::cin >> n;

  std::vector<std::pair<ll, ll>> origin(n);
  std::vector<ll> coordinate_compression, cnt(2*n), answer(n+1);

  // кладём координаты в оригинальный вектор пар и массив сжатых точек
  // где Li = first, Ri+1 = second+1;
  for(int i = 0; i < n; i++)
  {
    ll first, second;
    std::cin >> first >> second;
    origin[i].first = first;
    origin[i].second = second;
    coordinate_compression.push_back(origin[i].first);
    coordinate_compression.push_back(origin[i].second+1);
  }

  // сортируем массив сжатых точек по возрастанию и изменяем размер массива
  // на (std::unique(...)-std::begin()), где unique - возвращает указатель
  // на новый массив с уникальными значениями
  std::sort(coordinate_compression.begin(), coordinate_compression.end());
  coordinate_compression.resize(std::unique(coordinate_compression.begin(), coordinate_compression.end())-coordinate_compression.begin());

  // находим крайние точки для последующего заполнения префиксного массива
  for(int i = 0; i < origin.size(); i++)
  {
    ll left  = std::lower_bound(coordinate_compression.begin(), coordinate_compression.end(), origin[i].first) - coordinate_compression.begin();
    ll right = std::lower_bound(coordinate_compression.begin(), coordinate_compression.end(), origin[i].second+1) - coordinate_compression.begin();
    ++cnt[left];
    --cnt[right];
  }

  // получаем массив префиксов сжатых координат, т.е. нет таких значений что Ci-1 = Ci,
  // тем самым не нужно строить префиксный массив максимум из 1e18 чисел
  for(int i = 1; i < cnt.size(); i++)
    cnt[i] += cnt[i-1];

  // получаем ответ, увеличивая значение по индексу префиксного массива на
  // разность координат массива сжатых координат
  for(int i = 1; i < 2*n; i++)
    answer[cnt[i-1]] += (coordinate_compression[i]-coordinate_compression[i-1]);

  for(int i = 1; i<=n; i++)
    std::cout << answer[i] << ' ';
}
