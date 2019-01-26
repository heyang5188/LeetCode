#include <iostream>
#include <string>
#include <unordered_set>
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList)
    {
        unordered_set<string> dict(wordList.begin(), wordList.end());
        if (!dict.count(endWord))
            return 0;
        queue<string> que;
        que.push(beginWord);
        int len = beginWord.length();
        int ans = 0;
        while (!que.empty()) {
            ++ans;
            //遍历本层节点
            for (int size = que.size(); size > 0; size--) {
                cout << size << endl;
                string word = que.front();
                que.pop();
                for (int i = 0; i < len; i++) {
                    char temp = word[i];
                    for (int j = 'a'; j <= 'z'; j++) {
                        word[i] = j;
                        if (word == endWord)
                            return ans + 1;
                        if (!dict.count(word))
                            continue;
                        dict.erase(word);
                        que.push(word);
                    }
                    word[i] = temp;
                }
            }
        }
        return 0;
    }
};