#include <iostream>
#include <stack>
using namespace std;

int main()
{
    stack<int> S;
    
    S.push(1);
    S.push(2);
    S.push(3);

    // size of stack is 3
    cout << S.size() << " ";

    // 3
    cout << S.top() << " ";
    S.pop();

    // 2
    cout << S.top() << " ";
    S.pop();

    // 1
    cout << S.top() << " ";

    S.push(4);

    // 4
    cout << S.top() << " ";
    S.pop();

    // 1
    cout << S.top() << endl;

    return 0;
}