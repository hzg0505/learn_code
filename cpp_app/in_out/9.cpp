// 输入描述：
// 多个测试用例，每个测试用例一行。

// 每行通过空格隔开，有n个字符，n＜100
// 输出描述：
// 对于每组测试用例，输出一行排序过的字符串，每个字符串通过空格隔开
// 示例1
// 输入例子：
// a c bb
// f dddd
// nowcoder
// 输出例子：
// a bb c
// dddd f
// nowcoder

#include <bits/stdc++.h>
#include <sstream>
#include <vector>
using namespace std;

int main() {
    string input;
    
    while(getline(cin, input)){
        istringstream iss(input);
        vector<string> vs;
        string s;
        while(iss>>s){
            vs.push_back(s);
        }
        sort(vs.begin(), vs.end());
        for(auto ou: vs){
            cout << ou << " ";
        }
        cout << endl;
    }

}
// 64 位输出请用 printf("%lld")