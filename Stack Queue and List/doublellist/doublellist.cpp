#include <iostream>
#include <list>
#include <algorithm>

using namespace std;

int main(void)
{
    int num, key;
    char  com[20];
    list<int> v;

    scanf("%d", &num);
    for (int i = 0; i < num; i++) {
        scanf("%s", com);
        if (com[0] == 'i') {
            scanf("%d", &key);
            v.push_front(key);
        } else if (com[0] == 'd') {
            scanf("%d", &key);
            for (list<int>::iterator it = v.begin(); it != v.end(); it++) {
                if (*it == key) {
                    v.erase(it);
                    break;
                }
            }
        }
    }

    for (list<int>::iterator it = v.begin(); it != v.end(); it++)
        printf("%d ", *it);
    cout << endl;

    return 0;
}