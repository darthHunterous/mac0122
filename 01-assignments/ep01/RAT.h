typedef struct {
  unsigned long num;
  unsigned long den;
} Rational;

Rational RATinit(unsigned long numerator, unsigned long denominator);
void RATshow(Rational r);
Rational RATadd(Rational r1, Rational r2);
Rational RATmul(Rational r1, Rational r2);
Rational RATdiv(Rational r1, Rational r2);
