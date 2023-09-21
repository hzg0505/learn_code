#include <iostream>
#include <cstdio>
#include <string>
#include <map>
#include <set>
#include <vector>
#include <math.h>
// #include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin >> n;
    int D,W;
    double t;
    while(n--)
    {
        cin >> D >> W >> t;   // 文章数   单词数   阈值
        vector<vector<string> > papers;
        map<string, int> word_times;
        map<string, int> word_in_paper_number;
        set<string> word; 
        string token;
        for(int i=0; i<D; i++)
        {   
            vector<string> paper;
            int last = -1;
            for(int j=0; j<W; j++)
            {
                cin >> token;
                paper.push_back(token);
                word.insert(token);
                if(word_times.find(token)!= word_times.end())
                {
                    word_times[token]++;
                }else{
                    word_times[token] = 1;
                }
                
                // 文章数量
                if(word_in_paper_number.find(token) == word_in_paper_number.end())
                {
                    word_in_paper_number[token] = 1;
                    last = i;
                }else{
                    if(last!=i)
                    {
                        word_in_paper_number[token]++;
                        last = i;
                    }
                }
            }
            papers.push_back(paper);
        }
        
        int ans = 0;
        for(auto w : word)
        {
            double tf = word_times[w]/word.size();
            double idf = log(D/(word_in_paper_number[w]+1));
            if(tf*idf>t){
                ans = 1;
                break;
            }
        }
        cout << ans << endl;
    }

    return 0;
}