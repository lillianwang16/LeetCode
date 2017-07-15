/*
class Solution {
public:
    vector<pair<int, int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        priority_queue<element, vector<element>, cmp> pq;
        int len1 = nums1.size(), len2 = nums2.size();
        vector<pair<int, int>> res;
        if (len1 == 0 || len2 == 0) return res;
        for (int j = 0; j < len2; ++j) pq.push(element(0, j, nums1[0] + nums2[j]));
        for (int i = 0; i < min(k, len1 * len2); ++i) {
            element cur = pq.top();
            pq.pop();
            res.push_back(make_pair(nums1[cur.x], nums2[cur.y]));
            if (cur.x == len1 - 1)  continue;
            pq.push(element(cur.x + 1, cur.y, nums1[cur.x + 1] + nums2[cur.y]));
        }
        return res;
    }
private:
    struct element {
        int x;
        int y;
        int sum;
        element(int a, int b, int c): x(a), y(b), sum(c){}
    };
    class cmp {
    public:
        bool operator() (element a, element b){
            return a.sum > b.sum;
        }
   };
};
*/
class Solution {
public:
    vector<pair<int, int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<pair<int, int>> res;
        int len1 = nums1.size(), len2 = nums2.size();
        if (len1 == 0 || len2 == 0) return res;
        vector<int> n2(len2, 0);
        priority_queue<pair<int, int>, vector<pair<int, int>>, mycmp> pq;
        for (int i = 0; i < len2; ++i) {
            pq.push(make_pair(i, nums1[0] + nums2[i]));
        }
        for (int i = 0; i < min(k, len1 * len2); ++i) {
            pair<int, int> cur = pq.top();
            pq.pop();
            res.push_back(make_pair(nums1[n2[cur.first]], nums2[cur.first])); 
            if (n2[cur.first] == len1 - 1)  continue;
            n2[cur.first]++;      
            pq.push(make_pair(cur.first, nums1[n2[cur.first]] + nums2[cur.first]));
        }
        return res;
    }
    class mycmp{
        public:
        bool operator() (pair<int, int> a, pair<int, int> b) {
            return a.second > b.second;
        }
    };
};