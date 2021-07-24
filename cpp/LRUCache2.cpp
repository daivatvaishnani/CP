/**
* Problem Link: https://leetcode.com/problems/lru-cache/
*/
#include <bits/stdc++.h>

using namespace std;

class LRUCache {
    int capacity;
    unordered_map<int, list<pair<int, int> >::iterator > values;
    list<pair<int, int> > cache;
    
    void update(int key, int value) {
        auto data = values[key];
        cache.erase(data);
        cache.push_front({key, value});
        values[key] = cache.begin();
    }

    void add(int key, int value) {
        cache.push_front({key, value});
        values[key] = cache.begin();
    }

    void removeLRU() {
        pair<int, int> lru = cache.back();
        values.erase(lru.first);
        cache.pop_back();
    }

public:
    LRUCache(int capacity): capacity(capacity) {}

    int get(int key) {
        if(values.find(key) != values.end()) {
            int value = (*values[key]).second;
            update(key, value);
            return value;
        }
        return -1;
    }

    void put(int key, int value) {
        if(values.find(key) != values.end()) {
            update(key, value);
        }
        else {
            if(cache.size() == capacity) {
                removeLRU();
            }
            add(key, value);
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
