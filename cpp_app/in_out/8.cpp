// 输入描述：
// 输入有两行，第一行n

// 第二行是n个字符串，字符串之间用空格隔开
// 输出描述：
// 输出一行排序后的字符串，空格隔开，无结尾空格
// 示例1
// 输入例子：
// 5
// c d a bb e
// 输出例子：
// a bb c d e

#include <bits/stdc++.h>
#include <sstream>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<string> vs;
    string input;
    string s;
    int a, b;
    while (getline(cin, input)) { // 注意 while 处理多个 case
        istringstream iss(input);
        while(iss>>s)
        {
            vs.push_back(s);
        }
        sort(vs.begin(), vs.end());
        for(auto os : vs){
            cout << os << " " ;
        }
        // cout << endl;
    }
}
// 64 位输出请用 printf("%lld")