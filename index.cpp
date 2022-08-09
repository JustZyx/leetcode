#include <iostream>
#include <list>
#include <utility>

using namespace std;

int main()
{
    list<pair<int,int>> m_list;
    m_list.emplace_front(1,2);
    cout << m_list.begin()->second << endl;

    cout << isdigit('1') << endl;
    cout << isdigit('0') << endl;
    cout << isdigit('c') << endl;
    return 0;
}