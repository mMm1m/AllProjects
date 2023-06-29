#include <bits/stdc++.h>

struct Person
{
  int person_index, sort_of_milk=-1, time;
};


int main()
{
  freopen("badmilk.in", "r", stdin);
  freopen("badmilk.out", "w", stdout);
  int N,M,D,S; std::cin >> N >> M >> D >> S;
  bool count_of_ill[N];
  std::vector<Person> person(D+S);
  for(int i = 0; i < N; ++i) count_of_ill[i] = true;
  for(int i = 0; i < D+S; ++i)
  {
    if(i < D) std::cin >> person[i].person_index >> --person[i].sort_of_milk >> person[i].time;
    else std::cin >> person[i].person_index >> person[i].time;
    --person[i].person_index;
  }
  std::sort(person.begin(), person.end(),[](const Person& p1, const Person& p2){
    if(p1.time==p2.time)
      return p1.sort_of_milk<p2.sort_of_milk;
    return p1.time<p2.time;
  });
  int max = 0;
  for(int i =0; i < M; ++i)
  {
    std::vector<bool> ill_people(N);
    bool flag = true;
    for(auto& a : person)
    {
      if(i==a.sort_of_milk)
        ill_people[a.person_index]=true;
      else if(a.sort_of_milk==-1)
      {
        if(!ill_people[a.person_index])
        {flag=false; break;}
      }
    }
    if(flag) {
    int curr = 0;
    for(int j = 0; j < N; ++j)
    {curr += ill_people[i];}
    max = std::max(max, curr);
  }}
  std::cout << max;
}
