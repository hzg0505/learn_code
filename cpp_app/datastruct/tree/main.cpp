#include <iostream>
using namespace std;
#include <vector>
#include "tree.hpp"

int main()
{
    vector<int> vt = {1, 7, 5, 3, 6, 8, 4, 2};
    node* tree=nullptr;
    for(auto num: vt)
    {
        insert(tree, num);
    }

    PreOrder(tree);
    return 0;
}