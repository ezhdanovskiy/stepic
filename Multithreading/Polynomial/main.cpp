#include <cstdint>
#include <iostream>
#include <map>
#include <sstream>

#define LOG_END "\t[" << __LINE__ << "]" << std::endl;
#define LOG(chain) std::cout << chain << LOG_END
#define LOG1(el) std::cout << #el << "=" << (el) << LOG_END

struct Monomial;

std::ostream &operator<<(std::ostream &o, const Monomial &m);

//--------------------------------------------------------------
struct Monomial {
    char sign;
    int number;
    int power;
    bool hasX;

    Monomial() : sign('+'), number(0), power(0), hasX(false) {}

    void addX() {
        hasX = true;
    }

    void clear() {
        sign = '+';
        number = 0;
        power = 0;
        hasX = false;
    }

    bool empty() {
        return !hasX;
    }
};

class Polynomial {
    std::map<int, int> powerNumbers;
public:
    void add(Monomial &monomial) {
        if (!monomial.power) {
            monomial.power = 1;
        }
        if (!monomial.number) {
            monomial.number = 1;
        }
        if (monomial.sign == '-') {
            powerNumbers[monomial.power] -= monomial.number;
        } else {
            powerNumbers[monomial.power] += monomial.number;
        }
    }

    std::string computeDerivative() {
        std::stringstream out;
        bool first = true;
        for (auto it = powerNumbers.crbegin(); it != powerNumbers.crend(); ++it) {
            int power = it->first;
            int number = it->second;
            number *= power;
            power--;
            char sign;
            if (number < 0) {
                sign = '-';
                number = -number;
            } else {
                sign = '+';
            }

            if (!first || (first && sign == '-')) {
                out << sign;
            }
            first = false;

            if (number > 1 || power == 0) {
                out << number;
                if (power > 0) {
                    out << "*";
                }
            }
            if (power > 0) {
                out << "x";
            }
            if (power > 1) {
                out << "^" << power;
            }
        }
        return out.str();
    }
};

enum Token {
    operation, digit, multiplication, x, power, skip
};

Token getToken(char c) {
    switch (c) {
        case '+':
        case '-':
            return Token::operation;

        case '*':
            return Token::multiplication;

        case '^':
            return Token::power;

        case 'x':
        case 'X':
            return Token::x;

        default:
            if (c >= '0' && c <= '9') {
                return Token::digit;
            }
            return Token::skip;
    }
}

std::string derivative(std::string polynomial) {
    std::cout << std::endl;

    Monomial monomial;
    Polynomial polynom;
    Token token;
    Token prevToken = Token::skip;
    for (char c : polynomial) {
        token = getToken(c);

        switch (token) {
            case Token::operation: {
                if (!monomial.empty()) {
                    polynom.add(monomial);
                }
                monomial.clear();
                monomial.sign = c;
                prevToken = token;
                break;
            }

            case Token::digit: {
                if (prevToken == Token::power) {
                    monomial.power = monomial.power * 10 + (c - 0x30);
                } else {
                    monomial.number = monomial.number * 10 + (c - 0x30);
                }
                break;
            }

            case Token::multiplication: {
                break;
            }

            case Token::x: {
                monomial.addX();
                break;
            }

            case Token::power: {
                prevToken = token;
                break;
            }
        }
    }
    if (!monomial.empty()) {
        polynom.add(monomial);
    }

    return polynom.computeDerivative();
}
//--------------------------------------------------------------

int main(int argv, char **argc) {

    LOG1(derivative("x^2+x"));
    LOG1(derivative("2*x^100+100*x^2"));
    LOG1(derivative("x^10000+x+1"));
    LOG1(derivative("-x^2-x^3"));
    LOG1(derivative("x+x+x+x+x+x+x+x+x+x"));

    return 0;
}

std::ostream &operator<<(std::ostream &o, const Monomial &m) {
    if (m.sign == '-') {
        o << "-";
    }
    if (m.number) {
        o << m.number << "*";
    }
    o << "x";
    if (m.power >= 2) {
        o << "^" << m.power;
    }
    o << " (sign=" << m.sign << ", number=" << m.number << ", power=" << m.power << ")";
    return o;
}
