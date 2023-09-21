// 本题为考试多行输入输出规范示例，无需提交，不计分。
#include <iostream>
#include <cstdio>

using namespace std;

int main(){
    //freopen("1.in","r",stdin);
    int N;
    cin >> N;
    while(N--)
    {
        int n, l, r;
        cin >> n >> l >> r;
        int ans = l;
        if(l == r) cout << int((n-1)/2+l) << endl;
        else if(l<r){
            if(n-1 < r-l) cout << -1 << endl;
            else{
                int temp = n-2 - (r-l);
                cout << int((temp+1)/2+r) << endl;
            }
        }else{
            int t = r;
            r = l;
            l = t;
            if(n-1 < r-l) cout << -1 << endl;
            else{
                int temp = n-2 - (r-l);
                cout << int((temp+1)/2+r) << endl;
            }
        }
    }
//     cout << ans << endl;
    return 0;
}