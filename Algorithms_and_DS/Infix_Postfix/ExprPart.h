#ifndef INFIX_POSTFIX_EXPRPART_H
#define INFIX_POSTFIX_EXPRPART_H

namespace golchanskiy {

  enum class ExprPartElement{
    OPERAND, OPERATOR
  };


  class ExprPart {
    public:
     ExprPart() = delete;
     ExprPart(char);
     ExprPart(long long);
     ~ExprPart();
     long long getOperand();
     char getOperator();
     ExprPartElement getElement();
    private:
     union
     {
       char c;
       long long l;
     };
     ExprPartElement element;
  };
}

#endif //INFIX_POSTFIX_EXPRPART_H
