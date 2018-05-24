#include <iostream>
#include <string>
#include <queue>

using namespace std;

int main (void)
{
    queue<string> Q;

    Q.push("red");
    Q.push("yellow");
    Q.push("blue");
    Q.push("yellow");

    cout << Q.front() << " ";
    Q.pop();

    cout << Q.front() << " ";
    Q.pop();

    cout << Q.front() << " ";
    Q.pop();

    Q.push("green");

    cout << Q.front() << " ";
    Q.pop();

    cout << Q.front() << endl;
    
    return 0;
}