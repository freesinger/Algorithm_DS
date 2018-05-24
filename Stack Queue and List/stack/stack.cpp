#include <iostream>
#include <cstdlib>
#include <stack>

using namespace std;

int main (void)
{
    stack<int> S;
    string s;
    int a, b;

    while (cin >> s) {
        if (s[0] == '+') {
            a = S.top(); S.pop();
            b = S.top(); S.pop();
            S.push(a + b);            
        } else if (s[0] == '-') {
            a = S.top(); S.pop();
            b = S.top(); S.pop();
            S.push(a - b);
        } else if (s[0] == '*') {
            a = S.top(); S.pop();
            b = S.top(); S.pop();
            S.push(a * b);
        } else {
            S.push(atoi(s.c_str()));
        }
    }

    std::cout << S.top() << '\n';

    return 0;
}