// 输入描述：
// 输入数据包括多组。
// 每组数据一行,每行的第一个整数为整数的个数n(1 <= n <= 100), n为0的时候结束输入。
// 接下来n个正整数,即需要求和的每个正整数。
// 输出描述：
// 每组数据输出求和的结果
// 示例1
// 输入例子：
// 4 1 2 3 4
// 5 1 2 3 4 5
// 0
// 输出例子：
// 10
// 15

#include <iostream>
using namespace std;

int main() {
    int n;
    int a;
    while(cin>>n) { // 注意 while 处理多个 case
        if(n==0) return 0;
        int sum=0;
        while(n--){
            cin >> a;
            sum += a;
        }
        cout << sum << endl;
    }
}
// 64 位输出请用 printf("%lld")