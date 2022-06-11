#include <iostream>
#include <cmath>

using namespace std;

//! define the Fraction class.
class Fraction
{
public:
    Fraction() : numerator_(0), denominator_(1){};
    Fraction(int numerator, int denominator);
    int numerator() const { return numerator_; };
    int denominator() const { return denominator_; };
    int gcd(int a, int b);
    void normalise();
    void write() const;
    Fraction sum(const Fraction &right);
    Fraction sub(const Fraction &right);
    Fraction mul(const Fraction &right);
    Fraction div(const Fraction &right);

private:
    int numerator_;
    int denominator_;
};

Fraction::Fraction(int numerator, int denominator)
{
    numerator_ = numerator;
    denominator_ = denominator;
    normalise();
}

//! Compute the gcd of two numbers.
int Fraction::gcd(int a, int b)
{
    while (b != 0)
    {
        int tmp = a;
        a = b;
        b = tmp % b;
    }
    return a;
}

//! Normalize a fraction.
void Fraction::normalise()
{
    int g = gcd(numerator_, denominator_);
    numerator_ /= g;
    denominator_ /= g;
    if (denominator_ < 0)
    {
        numerator_ = -numerator_;
        denominator_ = -denominator_;
    }
}

// shows fraction f on the screen
void Fraction::write() const
{
    cout << numerator() << '/' << denominator();
}

Fraction Fraction::sum(const Fraction &right)
{
    int resnum = numerator_ * right.denominator() + denominator_ * right.numerator();
    int resdem = denominator_* right.denominator();
    Fraction res = Fraction(resnum, resdem);
    res.normalise();
    return res;
}

Fraction Fraction::sub(const Fraction &right)
{
    int resnum = numerator_ * right.denominator() - denominator_ * right.numerator();
    int resdem = denominator_* right.denominator();
    Fraction res = Fraction(resnum, resdem);
    res.normalise();
    return res;
}

Fraction Fraction::mul(const Fraction &right)
{
    int resnum = numerator_ * right.numerator();
    int resdem = denominator_ * right.denominator();
    Fraction res = Fraction(resnum, resdem);
    res.normalise();
    return res;
}

Fraction Fraction::div(const Fraction &right)
{
    int resnum = numerator_ * right.denominator();
    int resdem = denominator_ * right.numerator();
    Fraction res=Fraction(resnum, resdem);
    res.normalise();
    return res;
}
