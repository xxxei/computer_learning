/*************************************************************************
	> File Name: 2.quicl_sort.cpp
	> Author:tweixxx
	> Mail:954025688@qq.com 
	> Created Time: Sun 12 May 2024 09:04:15 PM CST
 ************************************************************************/

#include <iostream>
#include <set>
using namespace std;

int main() {
    typedef pair<int, int> PII;
    set<PII> s;
    int tot = 0, n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int val = 0;
        cin >> val;
        s.insert(PII(val, tot++));
    }
    int count = 0;
    for (auto x : s) {
        cout << x.first << "  ";
        count++;
        if (count % 10 == 0) {
            cout << endl;
        }
    }
    cout << endl;
    return 0;
}
