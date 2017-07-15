/*
// BFS. 500 ms.
class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        bool flag = false;
        wordList.push_back(beginWord);
        int n = wordList.size();
        vector<vector<bool>> d(n, vector<bool> (n));
        for (int i = 0; i < n; ++i) {
            if (wordList[i] == endWord) {
                flag = true;
            }
            for (int j = i + 1; j < n; ++j) {
                int cnt = 0;
                for (int k = 0; k < wordList[i].length(); ++k) {
                    if (wordList[i][k] != wordList[j][k]) {
                        ++cnt;
                    }
                }
                if (cnt == 1) {
                    d[i][j] = d[j][i] = true;
                }
            }
        }
        if (!flag) {
            return 0;
        }
        queue<int> q;
        q.push(n - 1);
        vector<bool>inq(n, false);
        inq[n - 1] = true;
        int cnt = 1;
        while (!q.empty()) {
            int m = q.size();
            for (int i = 0; i < m; ++i) {
                int k = q.front();
                q.pop();
                if (wordList[k] == endWord) {
                    return cnt;
                }
                for (int j = 0; j < n; ++j) {
                    if (d[k][j] && !inq[j]) {
                        q.push(j);
                        inq[j] = true;
                    }
                }
            }
            ++cnt;
        }
        return 0;
    }
};
*/
/*
// BFS with unordered_set. 100 ms.
class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> wordDict(wordList.begin(), wordList.end());
        queue<string> toVisit;
        addNext(beginWord, wordDict, toVisit);
        int dist = 2;
        while (!toVisit.empty()) {
            int n = toVisit.size();
            for (int i = 0; i < n; ++i) {
                string word = toVisit.front();
                toVisit.pop();
                if (word == endWord) {
                    return dist;
                }
                addNext(word, wordDict, toVisit);
            }
            ++dist;
        }
        return 0;
    }
private:
    void addNext(string word, unordered_set<string>& wordDict, queue<string>& toVisit) {
        for (int i = 0; i < word.length(); ++i) {
            char c = word[i];
            for (int j = 0; j < 26; ++j) {
                word[i] = 'a' + j;
                if (wordDict.find(word) != wordDict.end()) {
                    toVisit.push(word);
                    wordDict.erase(word);
                }
            }
            word[i] = c;
        }
    }
};
*/
// BFS with unordered_set and two-end solution.
// Two-end search is used to decrease the changed words.
class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> wordDict(wordList.begin(), wordList.end());
        unordered_set<string> head, tail, *pstart, *pend;
        if (wordDict.find(endWord) == wordDict.end()) return 0;
        head.insert(beginWord);
        tail.insert(endWord);
        int dist = 2;
        while (!head.empty() && !tail.empty()) {
            if (head.size() < tail.size()) {
                pstart = &head;
                pend = &tail;
            } else {
                pstart = &tail;
                pend = &head;
            }
            unordered_set<string> temp;
            for (auto it = pstart->begin(); it != pstart->end(); ++it) {
                string word = *it;
                for (int i = 0; i < word.length(); ++i) {
                    char c = word[i];
                    for (int j = 0; j < 26; ++j) {
                        word[i] = 'a' + j;
                        if (pend->find(word) != pend->end()) {
                            return dist;
                        }
                        if (wordDict.find(word) != wordDict.end()) {
                            temp.insert(word);
                            wordDict.erase(word);
                        }
                    }
                    word[i] = c;
                }
            }
            ++dist;
            swap(*pstart, temp);
        }
        return 0;
    }
};
