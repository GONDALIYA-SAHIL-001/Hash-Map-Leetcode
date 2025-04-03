class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> frequencyMap;
        
        for (int i = 0; i < nums.size(); i++) {
            frequencyMap[nums[i]]++;
        }

        vector<pair<int, int>> freqPairs;
        for (auto it = frequencyMap.begin(); it != frequencyMap.end(); it++) {
            freqPairs.push_back({it->second, it->first});
        }

        vector<int> result;
        for (int i = 0; i < k; i++) {
            int maxFreq = 0;
            int maxFreqIndex = -1;

            for (int j = 0; j < freqPairs.size(); j++) {
                if (freqPairs[j].first > maxFreq) {
                    maxFreq = freqPairs[j].first;
                    maxFreqIndex = j;
                }
            }

            result.push_back(freqPairs[maxFreqIndex].second);
            freqPairs[maxFreqIndex].first = -1;
        }

        return result;
    }
};
