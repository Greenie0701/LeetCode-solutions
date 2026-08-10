# DSA C++ Pattern Reference Sheet

Organized by **pattern**, not by day — each pattern's template is reusable across the specific problems listed under it. Adapt variable names / conditions per problem.

---

## 1. Two Pointers / Sorting-based Array Patterns

### 1.1 Fix one, two-pointer the rest → **3Sum**
```cpp
vector<vector<int>> threeSum(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    vector<vector<int>> res;
    int n = nums.size();
    for (int i = 0; i < n; i++) {
        if (i > 0 && nums[i] == nums[i-1]) continue;      // skip dup anchor
        int lo = i+1, hi = n-1;
        while (lo < hi) {
            long sum = (long)nums[i] + nums[lo] + nums[hi];
            if (sum < 0) lo++;
            else if (sum > 0) hi--;
            else {
                res.push_back({nums[i], nums[lo], nums[hi]});
                lo++; hi--;
                while (lo < hi && nums[lo] == nums[lo-1]) lo++;  // skip dups
                while (lo < hi && nums[hi] == nums[hi+1]) hi--;
            }
        }
    }
    return res;
}
```

### 1.2 Dutch National Flag → **Sort 0s, 1s, 2s**
```cpp
void sortColors(vector<int>& a) {
    int low = 0, mid = 0, high = a.size() - 1;
    while (mid <= high) {
        if (a[mid] == 0) swap(a[low++], a[mid++]);
        else if (a[mid] == 1) mid++;
        else swap(a[mid], a[high--]);   // don't advance mid, recheck swapped value
    }
}
```

### 1.3 Running sum reset → **Kadane's Algorithm** (Max Subarray Sum)
```cpp
int maxSubArray(vector<int>& a) {
    long curr = 0, best = LLONG_MIN;
    for (int x : a) {
        curr += x;
        best = max(best, curr);
        if (curr < 0) curr = 0;
    }
    return best;
}
```

### 1.4 Boyer-Moore voting generalized → **Majority Element II** (elements > n/3 times)
```cpp
vector<int> majorityElement(vector<int>& nums) {
    int cnt1 = 0, cnt2 = 0, cand1 = INT_MIN, cand2 = INT_MIN;
    for (int x : nums) {
        if (cand1 == x) cnt1++;
        else if (cand2 == x) cnt2++;
        else if (cnt1 == 0) { cand1 = x; cnt1 = 1; }
        else if (cnt2 == 0) { cand2 = x; cnt2 = 1; }
        else { cnt1--; cnt2--; }
    }
    cnt1 = cnt2 = 0;
    for (int x : nums) { if (x == cand1) cnt1++; else if (x == cand2) cnt2++; }
    vector<int> res;
    if (cnt1 > nums.size()/3) res.push_back(cand1);
    if (cnt2 > nums.size()/3) res.push_back(cand2);
    return res;
}
```

### 1.5 XOR trick → **Find the Repeating and Missing Number**
```cpp
pair<int,int> findRepeatingMissing(vector<int>& a) {
    int n = a.size();
    long sumN = (long)n*(n+1)/2, sumSqN = (long)n*(n+1)*(2*n+1)/6;
    long sum = 0, sumSq = 0;
    for (int x : a) { sum += x; sumSq += (long)x*x; }
    long diffSum = sum - sumN;                 // repeat - missing
    long diffSumSq = sumSq - sumSqN;           // repeat^2 - missing^2
    long sumRM = diffSumSq / diffSum;          // repeat + missing
    int repeat = (diffSum + sumRM) / 2;
    int missing = repeat - diffSum;
    return {repeat, missing};
}
```

### 1.6 Track max/min running product → **Maximum Product Subarray**
```cpp
int maxProduct(vector<int>& a) {
    int maxP = a[0], minP = a[0], res = a[0];
    for (int i = 1; i < a.size(); i++) {
        if (a[i] < 0) swap(maxP, minP);
        maxP = max(a[i], maxP * a[i]);
        minP = min(a[i], minP * a[i]);
        res = max(res, maxP);
    }
    return res;
}
```

### 1.7 Merge sort with counting → **Reverse Pairs** (i<j, a[i] > 2*a[j])
```cpp
int mergeCount(vector<int>& a, int l, int r) {
    if (l >= r) return 0;
    int m = (l + r) / 2;
    int cnt = mergeCount(a, l, m) + mergeCount(a, m+1, r);
    int j = m + 1;
    for (int i = l; i <= m; i++) {
        while (j <= r && a[i] > 2LL * a[j]) j++;
        cnt += j - (m + 1);
    }
    inplace_merge(a.begin()+l, a.begin()+m+1, a.begin()+r+1);
    return cnt;
}
```

---

## 2. Binary Search Patterns

### 2.1 Search with duplicates → **Search in Rotated Sorted Array II**
```cpp
bool search(vector<int>& a, int target) {
    int lo = 0, hi = a.size() - 1;
    while (lo <= hi) {
        int mid = (lo + hi) / 2;
        if (a[mid] == target) return true;
        if (a[lo] == a[mid] && a[mid] == a[hi]) { lo++; hi--; continue; }
        if (a[lo] <= a[mid]) {                       // left half sorted
            if (a[lo] <= target && target < a[mid]) hi = mid - 1;
            else lo = mid + 1;
        } else {                                      // right half sorted
            if (a[mid] < target && target <= a[hi]) lo = mid + 1;
            else hi = mid - 1;
        }
    }
    return false;
}
```

### 2.2 Binary search on the answer (minimize the max) → **Koko Eating Bananas**
```cpp
int minEatingSpeed(vector<int>& piles, int h) {
    auto hoursNeeded = [&](int speed) {
        long hrs = 0;
        for (int p : piles) hrs += (p + speed - 1) / speed;
        return hrs;
    };
    int lo = 1, hi = *max_element(piles.begin(), piles.end());
    while (lo < hi) {
        int mid = lo + (hi - lo) / 2;
        if (hoursNeeded(mid) <= h) hi = mid; else lo = mid + 1;
    }
    return lo;
}
```

### 2.3 Binary search on the answer (maximize the min) → **Aggressive Cows**
```cpp
bool canPlace(vector<int>& stalls, int cows, int dist) {
    int count = 1, last = stalls[0];
    for (int i = 1; i < stalls.size(); i++) {
        if (stalls[i] - last >= dist) { count++; last = stalls[i]; }
    }
    return count >= cows;
}
int aggressiveCows(vector<int>& stalls, int cows) {
    sort(stalls.begin(), stalls.end());
    int lo = 1, hi = stalls.back() - stalls.front(), ans = 0;
    while (lo <= hi) {
        int mid = (lo + hi) / 2;
        if (canPlace(stalls, cows, mid)) { ans = mid; lo = mid + 1; }
        else hi = mid - 1;
    }
    return ans;
}
```

### 2.4 Binary search on partition → **Median of Two Sorted Arrays**
```cpp
double findMedianSortedArrays(vector<int>& a, vector<int>& b) {
    if (a.size() > b.size()) swap(a, b);
    int n1 = a.size(), n2 = b.size(), lo = 0, hi = n1;
    while (lo <= hi) {
        int cut1 = (lo + hi) / 2;
        int cut2 = (n1 + n2 + 1) / 2 - cut1;
        int l1 = cut1 == 0 ? INT_MIN : a[cut1-1];
        int l2 = cut2 == 0 ? INT_MIN : b[cut2-1];
        int r1 = cut1 == n1 ? INT_MAX : a[cut1];
        int r2 = cut2 == n2 ? INT_MAX : b[cut2];
        if (l1 <= r2 && l2 <= r1) {
            if ((n1 + n2) % 2 == 0) return (max(l1,l2) + min(r1,r2)) / 2.0;
            return max(l1, l2);
        } else if (l1 > r2) hi = cut1 - 1;
        else lo = cut1 + 1;
    }
    return 0.0;
}
```

### 2.5 Prefix XOR + hashmap (not binary search, but paired with subarray counting) → **Count Subarrays with Given XOR K**
```cpp
int subarraysXor(vector<int>& a, int k) {
    unordered_map<int,int> freq;
    freq[0] = 1;
    int xorr = 0, cnt = 0;
    for (int x : a) {
        xorr ^= x;
        cnt += freq[xorr ^ k];
        freq[xorr]++;
    }
    return cnt;
}
```

### 2.6 Backtracking with dedup → **Combination Sum II**
```cpp
void backtrack(vector<int>& cand, int idx, int target, vector<int>& path, vector<vector<int>>& res) {
    if (target == 0) { res.push_back(path); return; }
    for (int i = idx; i < cand.size(); i++) {
        if (i > idx && cand[i] == cand[i-1]) continue;   // skip dup at same level
        if (cand[i] > target) break;
        path.push_back(cand[i]);
        backtrack(cand, i + 1, target - cand[i], path, res);
        path.pop_back();
    }
}
vector<vector<int>> combinationSum2(vector<int>& cand, int target) {
    sort(cand.begin(), cand.end());
    vector<vector<int>> res; vector<int> path;
    backtrack(cand, 0, target, path, res);
    return res;
}
```

### 2.7 Constraint-propagation backtracking → **N-Queens**
```cpp
bool isSafe(vector<string>& board, int row, int col, int n) {
    for (int i = 0; i < row; i++) if (board[i][col] == 'Q') return false;
    for (int i=row-1,j=col-1; i>=0 && j>=0; i--,j--) if (board[i][j]=='Q') return false;
    for (int i=row-1,j=col+1; i>=0 && j<n; i--,j++) if (board[i][j]=='Q') return false;
    return true;
}
void solve(int row, int n, vector<string>& board, vector<vector<string>>& res) {
    if (row == n) { res.push_back(board); return; }
    for (int col = 0; col < n; col++) {
        if (isSafe(board, row, col, n)) {
            board[row][col] = 'Q';
            solve(row + 1, n, board, res);
            board[row][col] = '.';
        }
    }
}
```

---

## 3. Bit Manipulation & Scheduling

### 3.1 XOR grouping → **Single Number III** (two numbers appear once, rest twice)
```cpp
vector<int> singleNumberIII(vector<int>& nums) {
    int xorAll = 0;
    for (int x : nums) xorAll ^= x;
    int diffBit = xorAll & (-xorAll);        // lowest set bit
    int a = 0, b = 0;
    for (int x : nums) {
        if (x & diffBit) a ^= x; else b ^= x;
    }
    return {a, b};
}
```

### 3.2 Sort by start time + min-heap of end times → **Minimum Platforms**
```cpp
int findPlatform(vector<int>& arr, vector<int>& dep) {
    sort(arr.begin(), arr.end());
    sort(dep.begin(), dep.end());
    int i = 1, j = 0, platforms = 1, maxP = 1, n = arr.size();
    while (i < n && j < n) {
        if (arr[i] <= dep[j]) { platforms++; i++; }
        else { platforms--; j++; }
        maxP = max(maxP, platforms);
    }
    return maxP;
}
```

### 3.3 Greedy interval scheduling → **N Meetings in One Room**
```cpp
int maxMeetings(vector<int>& start, vector<int>& end) {
    int n = start.size();
    vector<int> idx(n); iota(idx.begin(), idx.end(), 0);
    sort(idx.begin(), idx.end(), [&](int a, int b){ return end[a] < end[b]; });
    int count = 0, lastEnd = -1;
    for (int i : idx) {
        if (start[i] > lastEnd) { count++; lastEnd = end[i]; }
    }
    return count;
}
```

### 3.4 Greedy + Disjoint Set slot allocation → **Job Sequencing Problem**
```cpp
struct Job { int id, deadline, profit; };
pair<int,int> jobSequencing(vector<Job>& jobs) {
    sort(jobs.begin(), jobs.end(), [](Job&a, Job&b){ return a.profit > b.profit; });
    int maxDeadline = 0;
    for (auto& j : jobs) maxDeadline = max(maxDeadline, j.deadline);
    vector<int> slot(maxDeadline + 1, -1);
    int countJobs = 0, totalProfit = 0;
    for (auto& j : jobs) {
        for (int d = j.deadline; d > 0; d--) {          // find latest free slot <= deadline
            if (slot[d] == -1) { slot[d] = j.id; countJobs++; totalProfit += j.profit; break; }
        }
    }
    return {countJobs, totalProfit};
}
```

---

## 4. Sliding Window

### 4.1 Variable window with last-seen index → **Longest Substring Without Repeating Characters**
```cpp
int lengthOfLongestSubstring(string s) {
    vector<int> lastSeen(256, -1);
    int start = 0, best = 0;
    for (int end = 0; end < s.size(); end++) {
        if (lastSeen[s[end]] >= start) start = lastSeen[s[end]] + 1;
        lastSeen[s[end]] = end;
        best = max(best, end - start + 1);
    }
    return best;
}
```

### 4.2 Variable window with frequency map → **Longest Substring With At Most K Distinct Characters**
```cpp
int longestKDistinct(string s, int k) {
    unordered_map<char,int> freq;
    int start = 0, best = 0;
    for (int end = 0; end < s.size(); end++) {
        freq[s[end]]++;
        while (freq.size() > k) {
            freq[s[start]]--;
            if (freq[s[start]] == 0) freq.erase(s[start]);
            start++;
        }
        best = max(best, end - start + 1);
    }
    return best;
}
```

### 4.3 "at most K" trick (atMost(k) - atMost(k-1)) → **Count Number of Nice Subarrays** (exactly k odd numbers)
```cpp
int atMostKOdd(vector<int>& a, int k) {
    if (k < 0) return 0;
    int start = 0, oddCount = 0, res = 0;
    for (int end = 0; end < a.size(); end++) {
        if (a[end] % 2) oddCount++;
        while (oddCount > k) { if (a[start] % 2) oddCount--; start++; }
        res += end - start + 1;
    }
    return res;
}
int numberOfSubarrays(vector<int>& a, int k) {
    return atMostKOdd(a, k) - atMostKOdd(a, k - 1);
}
```

---

## 5. Linked List

### 5.1 Rearrange via 3 dummy heads → **Sort a Linked List of 0s, 1s, 2s**
```cpp
ListNode* sortList012(ListNode* head) {
    ListNode d0, d1, d2;
    ListNode *t0=&d0, *t1=&d1, *t2=&d2;
    for (ListNode* cur = head; cur; cur = cur->next) {
        if (cur->val == 0) { t0->next = cur; t0 = cur; }
        else if (cur->val == 1) { t1->next = cur; t1 = cur; }
        else { t2->next = cur; t2 = cur; }
    }
    t2->next = nullptr;
    t1->next = d2.next;
    t0->next = d1.next;
    return d0.next;
}
```

### 5.2 Slow/fast + reverse half → **Check if LL is Palindrome**
```cpp
ListNode* reverseLL(ListNode* head) {
    ListNode* prev = nullptr;
    while (head) { ListNode* nxt = head->next; head->next = prev; prev = head; head = nxt; }
    return prev;
}
bool isPalindrome(ListNode* head) {
    ListNode *slow = head, *fast = head;
    while (fast && fast->next) { slow = slow->next; fast = fast->next->next; }
    ListNode* secondHalf = reverseLL(slow);
    ListNode *p1 = head, *p2 = secondHalf;
    bool ok = true;
    while (p2) { if (p1->val != p2->val) { ok = false; break; } p1 = p1->next; p2 = p2->next; }
    return ok;
}
```

### 5.3 Floyd's cycle detection → **Find the Starting Point of a Loop in LL**
```cpp
ListNode* detectCycleStart(ListNode* head) {
    ListNode *slow = head, *fast = head;
    while (fast && fast->next) {
        slow = slow->next; fast = fast->next->next;
        if (slow == fast) {
            ListNode* ptr = head;
            while (ptr != slow) { ptr = ptr->next; slow = slow->next; }
            return ptr;
        }
    }
    return nullptr;
}
```

### 5.4 Reverse in groups (recursive/iterative) → **Reverse LL in Groups of Size K**
```cpp
ListNode* reverseKGroup(ListNode* head, int k) {
    ListNode* node = head;
    int count = 0;
    while (node && count < k) { node = node->next; count++; }
    if (count < k) return head;              // fewer than k nodes left
    ListNode* prev = reverseKGroup(node, k);  // recurse on remainder first
    ListNode* curr = head;
    while (count-- > 0) {
        ListNode* nxt = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nxt;
    }
    return prev;
}
```

### 5.5 Merge two sorted lists recursively (bottom-up) → **Flattening of LL** (each node also has `bottom` pointer)
```cpp
Node* mergeTwo(Node* a, Node* b) {
    if (!a) return b;
    if (!b) return a;
    Node* result;
    if (a->data < b->data) { result = a; result->bottom = mergeTwo(a->bottom, b); }
    else { result = b; result->bottom = mergeTwo(a, b->bottom); }
    result->next = nullptr;
    return result;
}
Node* flatten(Node* root) {
    if (!root || !root->next) return root;
    root->next = flatten(root->next);
    root = mergeTwo(root, root->next);
    return root;
}
```

### 5.6 Length-difference alignment → **Intersection Point of Y-shaped LL**
```cpp
int getLength(ListNode* head) { int len = 0; while (head) { len++; head = head->next; } return len; }
ListNode* getIntersectionNode(ListNode* a, ListNode* b) {
    int lenA = getLength(a), lenB = getLength(b);
    while (lenA > lenB) { a = a->next; lenA--; }
    while (lenB > lenA) { b = b->next; lenB--; }
    while (a != b) { a = a->next; b = b->next; }
    return a;
}
// Elegant alt: two pointers, each switches to the other list's head on reaching end; they meet in <= lenA+lenB steps.
```

### 5.7 Hashmap old→new node mapping → **Clone a LL with Random and Next Pointer**
```cpp
Node* copyRandomList(Node* head) {
    if (!head) return nullptr;
    unordered_map<Node*, Node*> mp;
    for (Node* cur = head; cur; cur = cur->next) mp[cur] = new Node(cur->val);
    for (Node* cur = head; cur; cur = cur->next) {
        mp[cur]->next = mp[cur->next];
        mp[cur]->random = mp[cur->random];
    }
    return mp[head];
}
// O(1) space variant: interleave cloned nodes into original list, wire randoms, then detach.
```

---

## 6. Monotonic Stack

### 6.1 Decreasing stack (index or value) → **Next Greater Element**
```cpp
vector<int> nextGreaterElement(vector<int>& a) {
    int n = a.size();
    vector<int> res(n, -1);
    stack<int> st;                     // stores indices
    for (int i = n - 1; i >= 0; i--) {
        while (!st.empty() && a[st.top()] <= a[i]) st.pop();
        if (!st.empty()) res[i] = a[st.top()];
        st.push(i);
    }
    return res;
}
```

### 6.2 Same monotonic stack idea → **Asteroid Collision**
```cpp
vector<int> asteroidCollision(vector<int>& a) {
    vector<int> st;
    for (int x : a) {
        bool alive = true;
        while (alive && x < 0 && !st.empty() && st.back() > 0) {
            if (st.back() < -x) { st.pop_back(); continue; }        // top explodes
            else if (st.back() == -x) { st.pop_back(); }            // both explode
            alive = false;                                          // x explodes
        }
        if (alive) st.push_back(x);
    }
    return st;
}
```

### 6.3 Next-smaller / prev-smaller via stack → **Sum of Subarray Ranges**
```cpp
long subArrayRanges(vector<int>& a) {
    int n = a.size();
    auto contribution = [&](bool wantMax) -> long {
        vector<int> left(n), right(n);
        stack<int> st;
        for (int i = 0; i < n; i++) {
            while (!st.empty() && (wantMax ? a[st.top()] < a[i] : a[st.top()] > a[i])) st.pop();
            left[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }
        while (!st.empty()) st.pop();
        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && (wantMax ? a[st.top()] <= a[i] : a[st.top()] >= a[i])) st.pop();
            right[i] = st.empty() ? n : st.top();
            st.push(i);
        }
        long sum = 0;
        for (int i = 0; i < n; i++) sum += (long)a[i] * (i - left[i]) * (right[i] - i);
        return sum;
    };
    return contribution(true) - contribution(false);   // sum(max) - sum(min)
}
```

### 6.4 Two pointers with prefix max → **Trapping Rain Water**
```cpp
int trap(vector<int>& h) {
    int lo = 0, hi = h.size() - 1, leftMax = 0, rightMax = 0, water = 0;
    while (lo < hi) {
        if (h[lo] <= h[hi]) {
            leftMax = max(leftMax, h[lo]);
            water += leftMax - h[lo];
            lo++;
        } else {
            rightMax = max(rightMax, h[hi]);
            water += rightMax - h[hi];
            hi--;
        }
    }
    return water;
}
```

### 6.5 Increasing stack, pop-and-compute-area → **Largest Rectangle in Histogram**
```cpp
int largestRectangleArea(vector<int>& h) {
    stack<int> st;                       // increasing heights, store indices
    int n = h.size(), maxArea = 0;
    for (int i = 0; i <= n; i++) {
        int cur = (i == n) ? 0 : h[i];
        while (!st.empty() && h[st.top()] >= cur) {
            int height = h[st.top()]; st.pop();
            int width = st.empty() ? i : i - st.top() - 1;
            maxArea = max(maxArea, height * width);
        }
        st.push(i);
    }
    return maxArea;
}
```

### 6.6 Doubly linked hashmap → **LRU Cache**
```cpp
class LRUCache {
    int cap;
    list<pair<int,int>> dll;                                // front = MRU, back = LRU
    unordered_map<int, list<pair<int,int>>::iterator> mp;
public:
    LRUCache(int capacity) : cap(capacity) {}
    int get(int key) {
        if (mp.find(key) == mp.end()) return -1;
        dll.splice(dll.begin(), dll, mp[key]);              // move to front
        return mp[key]->second;
    }
    void put(int key, int value) {
        if (mp.count(key)) { dll.erase(mp[key]); }
        else if (dll.size() == cap) { mp.erase(dll.back().first); dll.pop_back(); }
        dll.push_front({key, value});
        mp[key] = dll.begin();
    }
};
```

### 6.7 Monotonic stack, build digit-by-digit → **Remove K Digits**
```cpp
string removeKdigits(string num, int k) {
    string st;
    for (char c : num) {
        while (!st.empty() && k > 0 && st.back() > c) { st.pop_back(); k--; }
        st.push_back(c);
    }
    while (k-- > 0) st.pop_back();               // still remaining, remove from end
    int start = 0;
    while (start < st.size() - 1 && st[start] == '0') start++;   // strip leading zeros
    string res = st.substr(start);
    return res.empty() ? "0" : res;
}
```

---

## 7. Binary Tree / BST

### 7.1 Recursive LCA → **LCA in Binary Tree**
```cpp
TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    if (!root || root == p || root == q) return root;
    TreeNode* left = lowestCommonAncestor(root->left, p, q);
    TreeNode* right = lowestCommonAncestor(root->right, p, q);
    if (left && right) return root;
    return left ? left : right;
}
```

### 7.2 BST property narrows search → **LCA in BST**
```cpp
TreeNode* lcaBST(TreeNode* root, TreeNode* p, TreeNode* q) {
    while (root) {
        if (p->val < root->val && q->val < root->val) root = root->left;
        else if (p->val > root->val && q->val > root->val) root = root->right;
        else return root;
    }
    return nullptr;
}
```

### 7.3 Column index map + BFS → **Bottom View of Binary Tree**
```cpp
vector<int> bottomView(TreeNode* root) {
    map<int, int> colToVal;                      // last write per column wins (bottom-most)
    queue<pair<TreeNode*, int>> q;
    q.push({root, 0});
    while (!q.empty()) {
        auto [node, col] = q.front(); q.pop();
        colToVal[col] = node->val;
        if (node->left) q.push({node->left, col - 1});
        if (node->right) q.push({node->right, col + 1});
    }
    vector<int> res;
    for (auto& [c, v] : colToVal) res.push_back(v);
    return res;
}
```

### 7.4 Index tracking with hashmap → **Construct BT from Preorder and Inorder**
```cpp
TreeNode* buildHelper(vector<int>& pre, int& preIdx, int inStart, int inEnd,
                       unordered_map<int,int>& inIndex) {
    if (inStart > inEnd) return nullptr;
    int rootVal = pre[preIdx++];
    TreeNode* root = new TreeNode(rootVal);
    int mid = inIndex[rootVal];
    root->left = buildHelper(pre, preIdx, inStart, mid - 1, inIndex);
    root->right = buildHelper(pre, preIdx, mid + 1, inEnd, inIndex);
    return root;
}
TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
    unordered_map<int,int> inIndex;
    for (int i = 0; i < inorder.size(); i++) inIndex[inorder[i]] = i;
    int preIdx = 0;
    return buildHelper(preorder, preIdx, 0, inorder.size() - 1, inIndex);
}
```

### 7.5 Multi-source BFS from target node → **Minimum Time to Burn BT from a Node**
```cpp
void mapParents(TreeNode* root, TreeNode* parent, unordered_map<TreeNode*,TreeNode*>& par) {
    if (!root) return;
    if (parent) par[root] = parent;
    mapParents(root->left, root, par);
    mapParents(root->right, root, par);
}
TreeNode* findNode(TreeNode* root, int val) {
    if (!root || root->val == val) return root;
    TreeNode* l = findNode(root->left, val);
    return l ? l : findNode(root->right, val);
}
int minTimeToBurn(TreeNode* root, int startVal) {
    unordered_map<TreeNode*,TreeNode*> parent;
    mapParents(root, nullptr, parent);
    TreeNode* start = findNode(root, startVal);
    unordered_set<TreeNode*> visited;
    queue<TreeNode*> q; q.push(start); visited.insert(start);
    int time = 0;
    while (!q.empty()) {
        int sz = q.size(); bool burned = false;
        while (sz--) {
            TreeNode* node = q.front(); q.pop();
            for (TreeNode* nb : {node->left, node->right, parent[node]}) {
                if (nb && !visited.count(nb)) { visited.insert(nb); q.push(nb); burned = true; }
            }
        }
        if (burned) time++;
    }
    return time;
}
```

### 7.6 O(1) space traversal using threading → **Morris Inorder Traversal**
```cpp
vector<int> morrisInorder(TreeNode* root) {
    vector<int> res;
    TreeNode* cur = root;
    while (cur) {
        if (!cur->left) { res.push_back(cur->val); cur = cur->right; }
        else {
            TreeNode* pred = cur->left;
            while (pred->right && pred->right != cur) pred = pred->right;
            if (!pred->right) { pred->right = cur; cur = cur->left; }        // create thread
            else { pred->right = nullptr; res.push_back(cur->val); cur = cur->right; }  // remove thread
        }
    }
    return res;
}
```

### 7.7 Inorder traversal tracking prev → **Inorder Successor/Predecessor in BST**
```cpp
void inorderSuccPred(TreeNode* root, int key, TreeNode*& pred, TreeNode*& succ) {
    TreeNode* cur = root;
    while (cur) {
        if (cur->val == key) {
            if (cur->left) { TreeNode* t = cur->left; while (t->right) t = t->right; pred = t; }
            if (cur->right) { TreeNode* t = cur->right; while (t->left) t = t->left; succ = t; }
            break;
        } else if (key < cur->val) { succ = cur; cur = cur->left; }
        else { pred = cur; cur = cur->right; }
    }
}
```

### 7.8 Inorder traversal + swap detection → **Recover BST (Two Nodes Swapped)**
```cpp
void recoverTree(TreeNode* root) {
    TreeNode *first = nullptr, *second = nullptr, *prev = nullptr;
    function<void(TreeNode*)> inorder = [&](TreeNode* node) {
        if (!node) return;
        inorder(node->left);
        if (prev && prev->val > node->val) {
            if (!first) first = prev;
            second = node;
        }
        prev = node;
        inorder(node->right);
    };
    inorder(root);
    swap(first->val, second->val);
}
```

### 7.9 Return {size, min, max, isBST} bottom-up → **Largest BST in Binary Tree**
```cpp
struct Info { int size, mn, mx; bool isBST; };
Info largestBSTHelper(TreeNode* root, int& maxSize) {
    if (!root) return {0, INT_MAX, INT_MIN, true};
    Info l = largestBSTHelper(root->left, maxSize);
    Info r = largestBSTHelper(root->right, maxSize);
    Info cur;
    if (l.isBST && r.isBST && root->val > l.mx && root->val < r.mn) {
        cur = {l.size + r.size + 1, min(l.mn, root->val), max(r.mx, root->val), true};
        maxSize = max(maxSize, cur.size);
    } else {
        cur = {0, 0, 0, false};
    }
    return cur;
}
```

### 7.10 Inorder → sorted array → two pointer, or Morris + set → **Two Sum in BST**
```cpp
bool findTarget(TreeNode* root, int k) {
    unordered_set<int> seen;
    function<bool(TreeNode*)> dfs = [&](TreeNode* node) -> bool {
        if (!node) return false;
        if (seen.count(k - node->val)) return true;
        seen.insert(node->val);
        return dfs(node->left) || dfs(node->right);
    };
    return dfs(root);
}
```

---

## 8. Heaps

### 8.1 Sift-down from last internal node → **Heapify**
```cpp
void heapify(vector<int>& a, int n, int i) {
    int largest = i, l = 2*i+1, r = 2*i+2;
    if (l < n && a[l] > a[largest]) largest = l;
    if (r < n && a[r] > a[largest]) largest = r;
    if (largest != i) { swap(a[i], a[largest]); heapify(a, n, largest); }
}
```

### 8.2 Build heap + repeated extract-max → **Heap Sort**
```cpp
void heapSort(vector<int>& a) {
    int n = a.size();
    for (int i = n/2 - 1; i >= 0; i--) heapify(a, n, i);
    for (int i = n - 1; i > 0; i--) { swap(a[0], a[i]); heapify(a, i, 0); }
}
```

### 8.3 Fixed-size min-heap → **Kth Largest Element in a Stream**
```cpp
class KthLargest {
    priority_queue<int, vector<int>, greater<int>> minHeap;
    int k;
public:
    KthLargest(int k, vector<int>& nums) : k(k) {
        for (int x : nums) add(x);
    }
    int add(int val) {
        minHeap.push(val);
        if (minHeap.size() > k) minHeap.pop();
        return minHeap.top();
    }
};
```

---

## 9. String Matching

### 9.1 Hashing with rolling hash → **Rabin-Karp**
```cpp
vector<int> rabinKarp(string txt, string pat) {
    const long MOD = 1e9+7, BASE = 256;
    int n = txt.size(), m = pat.size();
    vector<int> res;
    if (m > n) return res;
    long patHash = 0, txtHash = 0, h = 1;
    for (int i = 0; i < m - 1; i++) h = (h * BASE) % MOD;
    for (int i = 0; i < m; i++) {
        patHash = (patHash * BASE + pat[i]) % MOD;
        txtHash = (txtHash * BASE + txt[i]) % MOD;
    }
    for (int i = 0; i <= n - m; i++) {
        if (patHash == txtHash && txt.substr(i, m) == pat) res.push_back(i);
        if (i < n - m) {
            txtHash = (BASE * (txtHash - txt[i]*h) + txt[i+m]) % MOD;
            if (txtHash < 0) txtHash += MOD;
        }
    }
    return res;
}
```

### 9.2 Z-array (match length with prefix) → **Z Function**
```cpp
vector<int> zFunction(string s) {
    int n = s.size();
    vector<int> z(n, 0);
    int l = 0, r = 0;
    for (int i = 1; i < n; i++) {
        if (i < r) z[i] = min(r - i, z[i - l]);
        while (i + z[i] < n && s[z[i]] == s[i + z[i]]) z[i]++;
        if (i + z[i] > r) { l = i; r = i + z[i]; }
    }
    return z;
}
// Pattern search: build s = pattern + '#' + text, positions with z[i] == pattern.size() are matches.
```

### 9.3 LPS array (failure function) → **KMP Algorithm**
```cpp
vector<int> computeLPS(string pat) {
    int m = pat.size();
    vector<int> lps(m, 0);
    int len = 0, i = 1;
    while (i < m) {
        if (pat[i] == pat[len]) { lps[i++] = ++len; }
        else if (len) len = lps[len - 1];
        else lps[i++] = 0;
    }
    return lps;
}
vector<int> kmpSearch(string txt, string pat) {
    vector<int> lps = computeLPS(pat), res;
    int i = 0, j = 0, n = txt.size(), m = pat.size();
    while (i < n) {
        if (txt[i] == pat[j]) { i++; j++; }
        if (j == m) { res.push_back(i - j); j = lps[j - 1]; }
        else if (i < n && txt[i] != pat[j]) { j ? j = lps[j-1] : i++; }
    }
    return res;
}
```

### 9.4 LPS of whole string → **Longest Happy Prefix**
```cpp
string longestPrefix(string s) {
    vector<int> lps = computeLPS(s);
    int len = lps.back();
    return s.substr(0, len);
}
```

---

## 10. Graphs

### 10.1 2-coloring via BFS/DFS → **Bipartite Graph Check**
```cpp
bool isBipartite(vector<vector<int>>& graph) {
    int n = graph.size();
    vector<int> color(n, -1);
    for (int start = 0; start < n; start++) {
        if (color[start] != -1) continue;
        queue<int> q; q.push(start); color[start] = 0;
        while (!q.empty()) {
            int u = q.front(); q.pop();
            for (int v : graph[u]) {
                if (color[v] == -1) { color[v] = 1 - color[u]; q.push(v); }
                else if (color[v] == color[u]) return false;
            }
        }
    }
    return true;
}
```

### 10.2 Multi-source BFS level by level → **Rotten Oranges**
```cpp
int orangesRotting(vector<vector<int>>& grid) {
    int rows = grid.size(), cols = grid[0].size(), fresh = 0, time = 0;
    queue<pair<int,int>> q;
    for (int i = 0; i < rows; i++) for (int j = 0; j < cols; j++) {
        if (grid[i][j] == 2) q.push({i, j});
        else if (grid[i][j] == 1) fresh++;
    }
    int dx[] = {-1,1,0,0}, dy[] = {0,0,-1,1};
    while (!q.empty() && fresh) {
        int sz = q.size();
        while (sz--) {
            auto [x, y] = q.front(); q.pop();
            for (int d = 0; d < 4; d++) {
                int nx = x+dx[d], ny = y+dy[d];
                if (nx>=0 && ny>=0 && nx<rows && ny<cols && grid[nx][ny]==1) {
                    grid[nx][ny] = 2; fresh--; q.push({nx, ny});
                }
            }
        }
        time++;
    }
    return fresh ? -1 : time;
}
```

### 10.3 In-degree BFS → **Topological Sort (Kahn's Algorithm)**
```cpp
vector<int> topoSortKahn(int n, vector<vector<int>>& adj) {
    vector<int> indeg(n, 0);
    for (int u = 0; u < n; u++) for (int v : adj[u]) indeg[v]++;
    queue<int> q;
    for (int i = 0; i < n; i++) if (indeg[i] == 0) q.push(i);
    vector<int> order;
    while (!q.empty()) {
        int u = q.front(); q.pop();
        order.push_back(u);
        for (int v : adj[u]) if (--indeg[v] == 0) q.push(v);
    }
    return order;                       // size < n => cycle exists
}
```

### 10.4 Topo sort → cycle check → **Course Schedule I**
```cpp
bool canFinish(int numCourses, vector<vector<int>>& prereq) {
    vector<vector<int>> adj(numCourses);
    for (auto& p : prereq) adj[p[1]].push_back(p[0]);
    vector<int> order = topoSortKahn(numCourses, adj);
    return order.size() == numCourses;
}
```

### 10.5 Topo sort on alphabet graph → **Alien Dictionary**
```cpp
string alienOrder(vector<string>& words) {
    vector<vector<int>> adj(26);
    vector<int> indeg(26, 0);
    vector<bool> seen(26, false);
    for (string& w : words) for (char c : w) seen[c-'a'] = true;
    for (int i = 0; i + 1 < words.size(); i++) {
        string& a = words[i]; string& b = words[i+1];
        int len = min(a.size(), b.size()), j = 0;
        for (; j < len; j++) {
            if (a[j] != b[j]) { adj[a[j]-'a'].push_back(b[j]-'a'); indeg[b[j]-'a']++; break; }
        }
        if (j == len && a.size() > b.size()) return "";     // invalid order
    }
    queue<int> q;
    for (int i = 0; i < 26; i++) if (seen[i] && indeg[i] == 0) q.push(i);
    string res;
    while (!q.empty()) {
        int u = q.front(); q.pop();
        res += char('a' + u);
        for (int v : adj[u]) if (--indeg[v] == 0) q.push(v);
    }
    for (int i = 0; i < 26; i++) if (seen[i]) --res.size();  // (see note)
    return res.size() == count(seen.begin(), seen.end(), true) ? res : "";
}
```

### 10.6 Min-heap relaxation → **Dijkstra's Algorithm**
```cpp
vector<int> dijkstra(int n, vector<vector<pair<int,int>>>& adj, int src) {  // adj[u] = {v, weight}
    vector<int> dist(n, INT_MAX);
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>> pq;    // {dist, node}
    dist[src] = 0; pq.push({0, src});
    while (!pq.empty()) {
        auto [d, u] = pq.top(); pq.pop();
        if (d > dist[u]) continue;
        for (auto [v, w] : adj[u]) {
            if (dist[u] + w < dist[v]) { dist[v] = dist[u] + w; pq.push({dist[v], v}); }
        }
    }
    return dist;
}
```

### 10.7 Modified Dijkstra with stop-count state → **Cheapest Flights Within K Stops**
```cpp
int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
    vector<vector<pair<int,int>>> adj(n);
    for (auto& f : flights) adj[f[0]].push_back({f[1], f[2]});
    // state: {cost, node, stopsUsed}, prune only by stopsUsed <= k
    priority_queue<array<int,3>, vector<array<int,3>>, greater<>> pq;      // {cost, node, stops}
    pq.push({0, src, 0});
    vector<int> minStops(n, INT_MAX);
    while (!pq.empty()) {
        auto [cost, u, stops] = pq.top(); pq.pop();
        if (u == dst) return cost;
        if (stops > k || stops >= minStops[u]) continue;
        minStops[u] = stops;
        for (auto [v, w] : adj[u]) pq.push({cost + w, v, stops + 1});
    }
    return -1;
}
```

### 10.8 DP over all-pairs → **Floyd-Warshall Algorithm**
```cpp
void floydWarshall(vector<vector<int>>& dist, int n) {     // dist[i][j] = INF if no edge, 0 if i==j
    for (int k = 0; k < n; k++)
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                if (dist[i][k] < INT_MAX && dist[k][j] < INT_MAX)
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
}
```

### 10.9 Union by rank/size + path compression → **Disjoint Set (Union-Find)**
```cpp
class DSU {
    vector<int> parent, rank_;
public:
    DSU(int n) : parent(n), rank_(n, 0) { iota(parent.begin(), parent.end(), 0); }
    int find(int x) { return parent[x] == x ? x : parent[x] = find(parent[x]); }
    bool unite(int x, int y) {
        int px = find(x), py = find(y);
        if (px == py) return false;
        if (rank_[px] < rank_[py]) swap(px, py);
        parent[py] = px;
        if (rank_[px] == rank_[py]) rank_[px]++;
        return true;
    }
};
```

### 10.10 DFS finish-order + reverse graph → **Kosaraju's Algorithm** (SCCs)
```cpp
void dfs1(int u, vector<vector<int>>& adj, vector<bool>& vis, stack<int>& order) {
    vis[u] = true;
    for (int v : adj[u]) if (!vis[v]) dfs1(v, adj, vis, order);
    order.push(u);
}
void dfs2(int u, vector<vector<int>>& radj, vector<bool>& vis, vector<int>& comp) {
    vis[u] = true; comp.push_back(u);
    for (int v : radj[u]) if (!vis[v]) dfs2(v, radj, vis, comp);
}
vector<vector<int>> kosaraju(int n, vector<vector<int>>& adj) {
    vector<bool> vis(n, false);
    stack<int> order;
    for (int i = 0; i < n; i++) if (!vis[i]) dfs1(i, adj, vis, order);
    vector<vector<int>> radj(n);
    for (int u = 0; u < n; u++) for (int v : adj[u]) radj[v].push_back(u);
    fill(vis.begin(), vis.end(), false);
    vector<vector<int>> sccs;
    while (!order.empty()) {
        int u = order.top(); order.pop();
        if (!vis[u]) { vector<int> comp; dfs2(u, radj, vis, comp); sccs.push_back(comp); }
    }
    return sccs;
}
```

---

## 11. Dynamic Programming

### 11.1 DP with state = (index, remaining distance choices) → **Frog Jump with K Distances**
```cpp
int frogJumpK(vector<int>& h, int k) {
    int n = h.size();
    vector<int> dp(n, INT_MAX);
    dp[0] = 0;
    for (int i = 1; i < n; i++) {
        for (int j = 1; j <= k && i - j >= 0; j++) {
            dp[i] = min(dp[i], dp[i-j] + abs(h[i] - h[i-j]));
        }
    }
    return dp[n-1];
}
```

### 11.2 Non-adjacent max-sum DP → **House Robber**
```cpp
int rob(vector<int>& nums) {
    int prev2 = 0, prev1 = 0;
    for (int x : nums) {
        int cur = max(prev1, prev2 + x);
        prev2 = prev1;
        prev1 = cur;
    }
    return prev1;
}
```

### 11.3 2D grid DP → **Minimum Falling Path Sum**
```cpp
int minFallingPathSum(vector<vector<int>>& matrix) {
    int n = matrix.size();
    vector<int> dp = matrix[0];
    for (int i = 1; i < n; i++) {
        vector<int> cur(n);
        for (int j = 0; j < n; j++) {
            int best = dp[j];
            if (j > 0) best = min(best, dp[j-1]);
            if (j < n-1) best = min(best, dp[j+1]);
            cur[j] = matrix[i][j] + best;
        }
        dp = cur;
    }
    return *min_element(dp.begin(), dp.end());
}
```

### 11.4 DP with buy/sell/transaction-count state → **Best Time to Buy and Sell Stock IV**
```cpp
int maxProfitK(int k, vector<int>& prices) {
    int n = prices.size();
    if (n == 0) return 0;
    vector<vector<int>> dp(k+1, vector<int>(2, 0));    // dp[t][holding]
    for (int t = 0; t <= k; t++) dp[t][1] = INT_MIN;
    for (int price : prices) {
        for (int t = k; t >= 1; t--) {
            dp[t][0] = max(dp[t][0], dp[t][1] + price);
            dp[t][1] = max(dp[t][1], dp[t-1][0] - price);
        }
    }
    return dp[k][0];
}
```

### 11.5 Subset-sum style DP → **0/1 Knapsack**
```cpp
int knapsack(vector<int>& wt, vector<int>& val, int W) {
    int n = wt.size();
    vector<int> dp(W + 1, 0);
    for (int i = 0; i < n; i++) {
        for (int w = W; w >= wt[i]; w--) {                 // reverse to keep 0/1 property
            dp[w] = max(dp[w], dp[w - wt[i]] + val[i]);
        }
    }
    return dp[W];
}
```

### 11.6 Subset-sum DP variant → **Minimum Subset Sum Difference**
```cpp
int minSubsetSumDiff(vector<int>& a) {
    int total = accumulate(a.begin(), a.end(), 0);
    vector<bool> dp(total + 1, false);
    dp[0] = true;
    for (int x : a) for (int s = total; s >= x; s--) dp[s] = dp[s] || dp[s-x];
    int best = INT_MAX;
    for (int s = 0; s <= total/2; s++) if (dp[s]) best = min(best, total - 2*s);
    return best;
}
```

### 11.7 1D DP with binary search optimization → **Longest Increasing Subsequence**
```cpp
int lengthOfLIS(vector<int>& nums) {
    vector<int> tails;                    // tails[i] = smallest tail of increasing subseq of len i+1
    for (int x : nums) {
        auto it = lower_bound(tails.begin(), tails.end(), x);
        if (it == tails.end()) tails.push_back(x);
        else *it = x;
    }
    return tails.size();
}
```

### 11.8 2D string DP → **Longest Common Subsequence**
```cpp
int longestCommonSubsequence(string a, string b) {
    int n = a.size(), m = b.size();
    vector<vector<int>> dp(n+1, vector<int>(m+1, 0));
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            dp[i][j] = (a[i-1] == b[j-1]) ? dp[i-1][j-1] + 1 : max(dp[i-1][j], dp[i][j-1]);
    return dp[n][m];
}
```

### 11.9 2D string DP with 3 operations → **Edit Distance**
```cpp
int minDistance(string a, string b) {
    int n = a.size(), m = b.size();
    vector<vector<int>> dp(n+1, vector<int>(m+1));
    for (int i = 0; i <= n; i++) dp[i][0] = i;
    for (int j = 0; j <= m; j++) dp[0][j] = j;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++) {
            if (a[i-1] == b[j-1]) dp[i][j] = dp[i-1][j-1];
            else dp[i][j] = 1 + min({dp[i-1][j-1], dp[i-1][j], dp[i][j-1]});  // replace, delete, insert
        }
    return dp[n][m];
}
```

### 11.10 Interval DP → **Matrix Chain Multiplication**
```cpp
int matrixChainOrder(vector<int>& p) {          // p.size() = n+1, matrix i is p[i-1] x p[i]
    int n = p.size() - 1;
    vector<vector<int>> dp(n+1, vector<int>(n+1, 0));
    for (int len = 2; len <= n; len++) {
        for (int i = 1; i <= n - len + 1; i++) {
            int j = i + len - 1;
            dp[i][j] = INT_MAX;
            for (int k = i; k < j; k++) {
                int cost = dp[i][k] + dp[k+1][j] + p[i-1]*p[k]*p[j];
                dp[i][j] = min(dp[i][j], cost);
            }
        }
    }
    return dp[1][n];
}
```

---

## 12. Number Theory & Tries

### 12.1 Sieve of Eratosthenes → **Print All Primes till N**
```cpp
vector<int> sieve(int n) {
    vector<bool> isComposite(n + 1, false);
    vector<int> primes;
    for (int i = 2; i <= n; i++) {
        if (!isComposite[i]) {
            primes.push_back(i);
            for (long j = (long)i * i; j <= n; j += i) isComposite[j] = true;
        }
    }
    return primes;
}
```

### 12.2 Trial division up to sqrt(n) → **Prime Factorisation of a Number**
```cpp
vector<int> primeFactors(int n) {
    vector<int> factors;
    for (int p = 2; (long)p * p <= n; p++) {
        while (n % p == 0) { factors.push_back(p); n /= p; }
    }
    if (n > 1) factors.push_back(n);
    return factors;
}
```

### 12.3 26-way (or 2-way for bits) branching node → **Trie Implementation (Insert/Search/StartsWith)**
```cpp
class TrieNode {
public:
    TrieNode* children[26] = {};
    bool isEnd = false;
};
class Trie {
    TrieNode* root;
public:
    Trie() { root = new TrieNode(); }
    void insert(string word) {
        TrieNode* node = root;
        for (char c : word) {
            if (!node->children[c-'a']) node->children[c-'a'] = new TrieNode();
            node = node->children[c-'a'];
        }
        node->isEnd = true;
    }
    bool search(string word) {
        TrieNode* node = root;
        for (char c : word) {
            if (!node->children[c-'a']) return false;
            node = node->children[c-'a'];
        }
        return node->isEnd;
    }
    bool startsWith(string prefix) {
        TrieNode* node = root;
        for (char c : prefix) {
            if (!node->children[c-'a']) return false;
            node = node->children[c-'a'];
        }
        return true;
    }
};
```

### 12.4 Trie with count fields for prefix counting/erase → **Trie: Advanced Operations**
```cpp
class TrieNodeAdv {
public:
    TrieNodeAdv* children[26] = {};
    int endCount = 0, prefixCount = 0;
};
class TrieAdvanced {
    TrieNodeAdv* root;
public:
    TrieAdvanced() { root = new TrieNodeAdv(); }
    void insert(string word) {
        TrieNodeAdv* node = root;
        for (char c : word) {
            if (!node->children[c-'a']) node->children[c-'a'] = new TrieNodeAdv();
            node = node->children[c-'a'];
            node->prefixCount++;
        }
        node->endCount++;
    }
    int countWordsEqualTo(string word) {
        TrieNodeAdv* node = root;
        for (char c : word) {
            if (!node->children[c-'a']) return 0;
            node = node->children[c-'a'];
        }
        return node->endCount;
    }
    int countWordsStartingWith(string prefix) {
        TrieNodeAdv* node = root;
        for (char c : prefix) {
            if (!node->children[c-'a']) return 0;
            node = node->children[c-'a'];
        }
        return node->prefixCount;
    }
    void erase(string word) {
        TrieNodeAdv* node = root;
        for (char c : word) {
            node = node->children[c-'a'];
            node->prefixCount--;
        }
        node->endCount--;
    }
};
```

### 12.5 Trie + DFS marking valid prefixes → **Longest Word With All Prefixes**
```cpp
string longestWordAllPrefixes(vector<string>& words) {
    Trie trie;
    for (string& w : words) trie.insert(w);
    string best = "";
    for (string& w : words) {
        bool valid = true;
        for (int len = 1; len <= w.size(); len++) {
            if (!trie.search(w.substr(0, len))) { valid = false; break; }   // every prefix must be a complete word
        }
        if (valid) {
            if (w.size() > best.size() || (w.size() == best.size() && w < best)) best = w;
        }
    }
    return best;
}
```

### 12.6 Trie node count minus root → **Number of Distinct Substrings in a String**
```cpp
int countDistinctSubstrings(string s) {
    TrieNode* root = new TrieNode();
    int count = 1;                          // count the empty substring / root
    for (int i = 0; i < s.size(); i++) {
        TrieNode* node = root;
        for (int j = i; j < s.size(); j++) {
            int idx = s[j] - 'a';
            if (!node->children[idx]) { node->children[idx] = new TrieNode(); count++; }
            node = node->children[idx];
        }
    }
    return count;
}
```

### 12.7 Binary trie (bit trie) over 32-bit numbers → **Maximum XOR of Two Numbers in an Array**
```cpp
class BitTrieNode { public: BitTrieNode* child[2] = {}; };
int findMaximumXOR(vector<int>& nums) {
    BitTrieNode* root = new BitTrieNode();
    auto insertNum = [&](int num) {
        BitTrieNode* node = root;
        for (int i = 31; i >= 0; i--) {
            int bit = (num >> i) & 1;
            if (!node->child[bit]) node->child[bit] = new BitTrieNode();
            node = node->child[bit];
        }
    };
    auto queryMax = [&](int num) {
        BitTrieNode* node = root;
        int result = 0;
        for (int i = 31; i >= 0; i--) {
            int bit = (num >> i) & 1;
            int want = 1 - bit;
            if (node->child[want]) { result |= (1 << i); node = node->child[want]; }
            else node = node->child[bit];
        }
        return result;
    };
    int maxXor = 0;
    for (int x : nums) insertNum(x);
    for (int x : nums) maxXor = max(maxXor, queryMax(x));
    return maxXor;
}
```

---

## Quick Pattern-Recognition Cheat Sheet

| Signal in problem statement | Pattern to reach for |
|---|---|
| "contiguous subarray", max/min sum or product | Kadane's / running-window DP |
| Sorted or rotated sorted array, "find X" | Binary search (possibly modified) |
| "minimize the maximum" / "maximize the minimum" | Binary search on the answer |
| Substring / subarray with a window constraint | Sliding window (fixed or variable) |
| "next greater/smaller", histogram, ranges | Monotonic stack |
| Linked list with cycle / middle / groups | Fast-slow pointers |
| Tree "view", "ancestor", "burn/spread" | BFS/DFS with parent map or column index |
| Shortest path, weighted graph | Dijkstra / Floyd-Warshall / BFS (unweighted) |
| Dependency order, "can finish", "order of X" | Topological sort (Kahn's) |
| Connectivity, cycles in undirected graph | Disjoint Set (Union-Find) |
| Count subarrays with exact property K | prefix-hashmap OR atMost(k)-atMost(k-1) |
| "minimum number of operations to convert" | 2D string DP (edit distance family) |
| Choose items under a capacity constraint | 0/1 Knapsack DP |
| Prefix-related string queries at scale | Trie (character or bit trie) |
| Pattern occurrence(s) inside text | KMP / Z-function / Rabin-Karp |
