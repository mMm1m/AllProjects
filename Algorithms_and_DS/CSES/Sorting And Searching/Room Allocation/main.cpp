#include <bits/stdc++.h>
using ll = long long;

const ll MAX_N = 2e5;

ll N;
ll ans[MAX_N];
std::vector<std::pair<std::pair<ll, ll>, ll>> v(MAX_N);

int main() {
  std::cin >> N;
  v.resize(N);
  for (int i = 0; i < N; i++) {
    std::cin >> v[i].first.first >> v[i].first.second;
    v[i].second = i; // store the original index
  }
  sort(v.begin(), v.end());

  ll rooms = 0, last_room = 0;
  std::priority_queue<std::pair<int, int>> pq; // min heap to store departure times.
  for (int i = 0; i < N; i++) {
    if (pq.empty()) {
      last_room++;
      // make the departure time negative so that we create a min heap
      // (cleanest way to do a min heap... default is max in c++)
      pq.push(std::make_pair(-v[i].first.second, last_room));
      ans[v[i].second] = last_room;
    }
    else {
      // accessing the minimum departure time
      std::pair<ll, ll> minimum = pq.top();
      if (-minimum.first < v[i].first.first) {
        pq.pop();
        pq.push(std::make_pair(-v[i].first.second, minimum.second));
        ans[v[i].second] = minimum.second;
      }

      else {
        last_room++;
        pq.push(std::make_pair(-v[i].first.second, last_room));
        ans[v[i].second] = last_room;
      }
    }

    rooms = std::max(rooms, ll(pq.size()));
  }


  std::cout << rooms << "\n";
  for (int i = 0; i < N; i++) {
    std::cout << ans[i] << " ";
  }
}
