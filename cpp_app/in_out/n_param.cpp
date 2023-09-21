#include<iostream>
using namespace std;


// 需要n个相同类别的参数
// 每个数据一行
int main()
{
	int n;
	while (cin >> n) {
		if (n == 0) break;
		int a;
		int sum = 0;
		for (int i = 0; i < n; ++i) {
			cin >> a;
			sum += a;
		}
		cout << sum << endl;
	}

	return 0;
}
