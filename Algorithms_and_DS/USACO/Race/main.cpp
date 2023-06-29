#include <bits/stdc++.h>
int fastest_time(int dist, int max_speed) {
  int speed_up_dist = 0, slow_down_dist = 0,  time = 0;
  for (int curr_speed = 1;; curr_speed++) {
    speed_up_dist += curr_speed;
    time++;
    if (speed_up_dist + slow_down_dist >= dist) { return time;
    }
    if (curr_speed >= max_speed) {
      slow_down_dist += curr_speed;
      time++;
      if (speed_up_dist + slow_down_dist >= dist) { return time; }
    }
  }
}

int main() {
  std::ifstream read("race.in");
  int dist, query_num;
  read >> dist >> query_num;
  std::ofstream written("race.out");
  for (int q = 0; q < query_num; q++) {
    int max_speed;
    read >> max_speed;
    written << fastest_time(dist, max_speed) << '\n';
  }
}