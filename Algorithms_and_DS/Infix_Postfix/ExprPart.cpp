#include "ExprPart.h"
namespace golchanskiy
{
ExprPart::ExprPart(char element) : c(element), element(ExprPartElement::OPERATOR){}
ExprPart::ExprPart(long long digit) : l(digit), element(ExprPartElement::OPERATOR){}

long long ExprPart::getOperand()
{
  return l;
}

char ExprPart::getOperator()
{
  return c;
}

ExprPartElement golchanskiy::ExprPart::getElement()
{
  return element;
}
}