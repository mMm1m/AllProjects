#include <iostream>
#include <fstream>
#include <queue>
#include <stack>
#include "Functions.h"
#include "ExprPart.h"


int main(int argc, char* argv[])
{
  using q_s = std::queue<std::string>;
  using q_e = std::queue<golchanskiy::ExprPart>;
  std::stack<long long> stack;
  std::ifstream fin;
  if (argc == 2)
  {
    fin.open(argv[1]);
    if (!fin.good())
    {
      std::cerr << "Unable to read the file" << std::endl;
      return 1;
    }
  }
  else if (argc > 2)
  {
    std::cerr << "Too many args" << std::endl;
    return 1;
  }
  std::istream& in = argc == 2 ? fin : std::cin;
  try {
    q_s queue_string = golchanskiy::input(in);
    std::queue<q_e> queue = golchanskiy::convert(queue_string);
    while(!queue.empty())
    {
      q_e qE = queue.front();
      queue.pop();
      long long value = calculation(qE);
      stack.push(value);
    }
  }
  catch (const std::exception& e)
  {
    std::cerr << e.what() << std::endl;
    return 2;
  }

  golchanskiy::output(std::cout, stack);
}
