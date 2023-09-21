// 输入描述：
// 输入的第一行包括一个正整数t(1 <= t <= 100), 表示数据组数。
// 接下来t行, 每行一组数据。
// 每行的第一个整数为整数的个数n(1 <= n <= 100)。
// 接下来n个正整数, 即需要求和的每个正整数。
// 输出描述：
// 每组数据输出求和的结果
// 示例1
// 输入例子：
// 2
// 4 1 2 3 4
// 5 1 2 3 4 5
// 输出例子：
// 10
// 15

#include <iostream>
using namespace std;

int main() {
    int n;
    cin>>n;
    int a;
    while (n--) { // 注意 while 处理多个 case
        int sum = 0;
        int nn;
        cin>>nn;
        while(nn--){
            cin >> a;
            sum += a;
        }
        cout << sum << endl;
    }
}
// 64 位输出请用 printf("%lld")