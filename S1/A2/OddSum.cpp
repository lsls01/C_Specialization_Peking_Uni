#include <iostream>
using namespace std;
int main() {
    int m, n, result = 0;
    cin >> m >> n;
    if(m % 2 == 0) m += 1;
    while (m <= n) {
        //����m��n֮���ÿһ������ ���������������ô�ͼ��뵽���ǵĽ���������Ǿ�������
        result += m;
        m += 2;
    }
    //������
    cout << result << endl;
    return 0;
}