class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if (nums.empty()) return 0;
        
        unordered_map<int, int> parent, size;
        
        for (int num : nums) {
            if (parent.find(num) == parent.end()) {
                parent[num] = num;
                size[num] = 1;
                
                if (parent.find(num - 1) != parent.end()) 
                    merge(parent, size, num, num - 1);
                if (parent.find(num + 1) != parent.end()) 
                    merge(parent, size, num, num + 1);
            }
        }
        
        int longest = 0;
        for (auto& p : size) {
            longest = max(longest, p.second);
        }
        
        return longest;
    }
    
private:
    int find(unordered_map<int, int>& parent, int x) {
        if (parent[x] != x) 
            parent[x] = find(parent, parent[x]);
        return parent[x];
    }
    
    void merge(unordered_map<int, int>& parent, unordered_map<int, int>& size, int x, int y) {
        int rootX = find(parent, x);
        int rootY = find(parent, y);
        
        if (rootX != rootY) {
            parent[rootX] = rootY;
            size[rootY] += size[rootX];
        }
    }
};
