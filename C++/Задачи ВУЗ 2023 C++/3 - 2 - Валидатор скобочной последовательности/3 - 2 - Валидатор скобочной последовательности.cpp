#include <iostream>
#include <stack>
#include <string>

int main() {
    std::string gl;
    std::stack<char> s;
    bool line = true;
    
    while (line) {
        std::getline(std::cin, gl);
        for (char c : gl) {
            line = c != '!';
            if (c == '(' || c == '{' || c == '[')
                s.push(c);
            else if (c == ')' || c == '}' || c == ']') {
                if (s.empty()) {
                    s.push(c);
                    line = false;
                    break;
                } else if ((c == ')' && s.top() == '(') ||
                           (c == '}' && s.top() == '{') ||
                           (c == ']' && s.top() == '[')) {
                    s.pop();
                } else {
                    s.push(c);
                    line = false;
                    break;
                }
            }
        }
    }

    std::cout << (s.empty() ? "YES" : "NO") << std::endl;

    return 0;
}

// ()[]{}([{()}])(())[[]]{{}}([])([{}])[()]{[]}!
// ( d f a) af[sdf] f{f\n}f(f[s{s(a)a}gf]g)g(g(sre)g)s[\ndfg[sg]  gs]s{{s}g}sg( [s])g(s\n[d{+ }+]-) +[(+)-]-+{-+[-``]`}!

// ( d f a) af[sdf] f{f\n}f(f[s{s(a)a}gf]g)g
// (g(sre)g)s[\ndfg[sg]  gs]s{{s}g}sg( [s])g
// (s\n[d{+ }+]-) +[(+)-]-+{-+[-``]`}!

// ()[] {}([{()}])(()) [[]] { {}}([])([{}])[()] { [] !}!
// // ()[] {}([{()}])(())
// [[]] { {}}([])([{}])[()] { [] !}!

// ([})!
// ([)]!
// (()!
// ())!