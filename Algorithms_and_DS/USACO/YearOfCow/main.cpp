#include <bits/stdc++.h>
std::vector<std::string> animals = {"Ox", "Tiger", "Rabbit", "Dragon", "Snake", "Horse", "Goat", "Monkey", "Rooster", "Dog", "Pig", "Rat"};
std::map<std::string,int> when_born;

std::string get_animal(int year)
{
  int a = 0, y = 2021;
  while (y < year) { y++; a++; if (a == 12) a = 0; }
  while (y > year) { y--; a--; if (a == -1) a = 11; }
  return animals[a];
}

int main()
{
  int N;   std::cin >> N;
  when_born["Bessie"] = 2021;
  std::string cowa, born, in, relation, animal, year, from, cowb;
  for (int i=0; i<N; i++) {
    std::cin >> cowa >> born >> in >> relation >> animal >> year >> from >> cowb;
    when_born[cowa] = when_born[cowb];
    do {
      if (relation == "previous") when_born[cowa]--;
      else when_born[cowa]++;
    } while (get_animal(when_born[cowa]) != animal);
  }
  int diff = std::abs(when_born["Bessie"] - when_born["Elsie"]);
  std::cout << diff << "\n";
}
