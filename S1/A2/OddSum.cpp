#include <iostream>
using namespace std;
int main() {
    int m, n, result = 0;
    cin >> m >> n;
    if(m % 2 == 0) m += 1;
    while (m <= n) {
        //对于m和n之间的每一个数， 如果它是奇数，那么就加入到我们的结果里。如果不是就跳过。
        result += m;
        m += 2;
    }
    //最后输出
    cout << result << endl;
    return 0;
}