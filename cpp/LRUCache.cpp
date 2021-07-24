/**
* Problem Link: https://leetcode.com/problems/lru-cache/
*/
#include <bits/stdc++.h>

using namespace std;

class LRUCache {
    int capacity;
    int visits;
    unordered_map<int, pair<int, int> > values;
    set<pair<int, int> > usages;
    
    void updateKey(int key, int value) {
        values[key].first = value;
        usages.erase(usages.find({values[key].second, key}));
        values[key].second = visits;
        usages.insert({values[key].second, key});
    }

    void addKey(int key, int value) {
        values[key].first = value;
        values[key].second = visits;
        usages.insert({values[key].second, key});
        capacity--;
    }

    void removeLRU() {
        auto leastRecentlyUsed = usages.begin();
        pair<int,int> leastRecentlyUsedPair = *leastRecentlyUsed;
        values.erase(leastRecentlyUsedPair.second);
        usages.erase(leastRecentlyUsed);
        capacity++;
    }

public:
    LRUCache(int capacity) {
        this->capacity = capacity;
        visits = 0;
    }

    int get(int key) {
        visits++;
        if(values.find(key) != values.end()) {
            updateKey(key, values[key].first);
            return values[key].first;
        }
        return -1;
    }

    void put(int key, int value) {
        visits++;
        if(values.find(key) != values.end()) {
            updateKey(key, value);
        }
        else {
            if(capacity == 0) {
                removeLRU();
            }
            addKey(key, value);
        }
    }
};

int main() {
    // freopen("in", "r", stdin), freopen("out", "w", stdout);
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    LRUCache cache(2);
    cache.put(1, 1);
    cache.put(2, 2);
    cout << cache.get(1) << "\n";       // returns 1
    cache.put(3, 3);                    // evicts key 2
    cout << cache.get(2) << "\n";       // returns -1 (not found)
    cache.put(4, 4);                    // evicts key 1
    cout << cache.get(1) << "\n";       // returns -1 (not found)
    cout << cache.get(3) << "\n";       // returns 3
    cout << cache.get(4) << "\n";       // returns 4
    return 0;
}
