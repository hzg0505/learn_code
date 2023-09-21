// 输入描述：
// 输入数据有多组, 每行表示一组输入数据。

// 每行不定有n个整数，空格隔开。(1 <= n <= 100)。
// 输出描述：
// 每组数据输出求和的结果
// 示例1
// 输入例子：
// 1 2 3
// 4 5
// 0 0 0 0 0
// 输出例子：
// 6
// 9
// 0

#include <bits/stdc++.h>
#include <sstream>
using namespace std;

int main() {
    string s;
    while(getline(cin, s)){
        istringstream iss(s);
        int sum=0;
        int a;
        while(iss >> a){
            sum += a;
        }
        cout << sum << endl;
    }
}
// 64 位输出请用 printf("%lld")