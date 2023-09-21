// 输入描述：
// 多个测试用例，每个测试用例一行。
// 每行通过,隔开，有n个字符，n＜100
// 输出描述：
// 对于每组用例输出一行排序后的字符串，用','隔开，无结尾空格
// 示例1
// 输入例子：
// a,c,bb
// f,dddd
// nowcoder
// 输出例子：
// a,bb,c
// dddd,f
// nowcoder

#include <bits/stdc++.h>
#include <sstream>
#include <vector>
using namespace std;

int main() {
    vector<string> lines;  // 用于存储每行的字符串
    // 读取输入，并将每行的字符串存储到 lines 向量中
    string line;
    while (getline(cin, line)) {
        lines.push_back(line);
    }

    for(auto line: lines)
    {
        string s;
        istringstream iss_line(line);
        vector<string> vs;
        while(getline(iss_line, s, ','))
        {
            vs.push_back(s);
        }
        sort(vs.begin(), vs.end());
        for(int i=0; i<vs.size(); i++){
            cout << vs[i] ;
            if(i < vs.size()-1){
                cout << ",";
            }
        }
        cout << endl;
    }
    return 0;
}
// 64 位输出请用 printf("%lld")