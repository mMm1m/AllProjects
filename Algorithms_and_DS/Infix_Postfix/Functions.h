#ifndef INFIX_POSTFIX_FUNCTIONS_H
#define INFIX_POSTFIX_FUNCTIONS_H
#include "ExprPart.h"

namespace golchanskiy {
  std::queue< std::string > input(std::istream& i_stream);

  std::queue< std::queue< golchanskiy::ExprPart>> convert(std::queue< std::string >);

  std::queue<golchanskiy::ExprPart> stringToQueueExprType(std::string);

  void infixToPostfix(std::queue< golchanskiy::ExprPart >);

  long long calculation(std::queue< golchanskiy::ExprPart >);

  bool isNumber(std::string string);

  bool isOperation(char c);

  void output(std::ostream& o_stream, std::stack< long long >);
}

#endif //INFIX_POSTFIX_FUNCTIONS_H
