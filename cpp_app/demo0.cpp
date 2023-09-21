#include <iostream>
#include <vector>
using namespace std;
// using ll =long long;

int main()
{
    int n, m;
    cin >> n >> m;
    vector<char> s;
    vector<int > choose(26, 0);
    char token;
    for(int i=0; i<n; i++)
    {
        cin >> token;
        s.push_back(token);
        choose[token-'a']++;
    }
    vector<char> c;
    for(int i=0; i<m; i++)
    {
        cin >> token;
        c.push_back(token);
    }
    
    int ans = 0;
    for(int i=0; i<m; i++)
    {
        int flag = choose[c[i]-'a'];
        if(flag > 0){
            ans++;
            choose[c[i]-'a'] = -1;
        }
//         else if(flag==-1){
// //             break;
//         }
    }
    cout << ans << endl;
    // 先出现的后入，有商品，前面没人要，
}