#include <bits/stdc++.h>

using namespace std;

class LRUCache {
  int _capacity;
  list<pair<int, int> > _cache;
  unordered_map<int, list<pair<int, int> >::iterator> _itmap;

public:
  LRUCache(int capacity): _capacity(capacity) {}  

  void put(int key, int value) {
    auto it = _itmap.find(key);
    if (it != _itmap.end()) {
      _cache.splice(_cache.begin(), _cache, it->second);
      it->second->second = value;
      return;
    }
    if (_cache.size() == _capacity) {
      _itmap.erase(_cache.back().first);
      _cache.pop_back();
    }
    _cache.emplace_front(key, value);
    _itmap[key] = _cache.begin();
  }

  int get(int key) {
    auto it = _itmap.find(key);
    if (it != _itmap.end()) {
      _cache.splice(_cache.begin(), _cache, it->second);
      return it->second->second;
    } 
    return -1;
  }    
};


int main() {
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
