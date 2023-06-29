#include <bits/stdc++.h>
using ll = long long;

int main()
{

  std::map<char, ll> values;
  values['2'] = 0; values['3'] = 1; values['4'] = 2; values['5'] = 3;
  values['6'] = 4; values['7'] = 5; values['8'] = 6; values['9'] = 7;
  values['T'] = 8; values['J'] = 9; values['Q'] = 10; values['K'] = 11;
  values['A'] = 12;

  std::vector<int> values_cards(13);
  //black
  for(int i = 0; i < 5; i++)
  {
    char card_, suit_;
    std::cin >> card_ >> suit_;
    ++values_cards[values[card_]];
  }
  int count_of_pairs = 0, count_of_threes = 0, count_of_four = 0;
  for(int i = 0; i < 13; i++)
  {
    if(values_cards[i]==2) ++count_of_pairs;
    else if(values_cards[i]==3) ++count_of_threes;
    else if(values_cards[i]==4) ++count_of_four;
  }
  if(count_of_pairs ==1 && count_of_threes==0 && count_of_four==0)
  {

  }
  else if(count_of_pairs ==2 && count_of_threes==0 && count_of_four==0)
  {

  }
  else if(count_of_pairs ==0 && count_of_threes==1 && count_of_four==0)
  {

  }
  else if(count_of_pairs ==0 && count_of_threes==0 && count_of_four==1)
  {

  }
  else if(count_of_pairs ==1 && count_of_threes==1 && count_of_four==0)
  {

  }
  // white
  /*for(int i = 0; i < 5; i++)
  {
    char card_, suit_;
    std::cin >> card_ >> suit_;
  }*/
}
