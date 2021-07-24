#include <bits/stdc++.h>

using namespace std;

class LRUCache {

  class LRUNode {
  public:
    int key, value;
    LRUNode *prev, *next;

    LRUNode(int key, int value): key(key), value(value), prev(NULL), next(NULL) {}
  };
  
  LRUNode *front, *back;
  unordered_map<int, LRUNode*> node_map;

  void update(int key, int value) {
    assert(node_map.find(key) != node_map.end());
    remove(node_map[key]);
    insert(key, value);
  }

  void remove(LRUNode *node) {
    if (!node) {
      return;
    }
    assert(node_map.find(node->key) != node_map.end());
    node_map.erase(node->key);
    size--;
    if (front == back) {
      front = NULL;
      back = NULL;
    } else if (node == front) {
      front = node->next;
      front->prev = NULL;
    } else if (node == back) {
      back = node->prev;
      back->next = NULL;
    } else {
      node->prev->next = node->next;
      node->next->prev = node->prev;
    }
    node = NULL;
    delete node;
  }

  void insert(int key, int value) {
    assert(node_map.find(key) == node_map.end());
    if (size == capacity) {
      remove(back);   
    }
    LRUNode *node = new LRUNode(key, value);
    node_map[key] = node;
    size++;
    if (!front && !back) {
      front = node;
      back = node;
    } else {
      node->next = front;
      front->prev = node;
      front = node;
    }
    node = NULL;
    delete node;
  }

public:
  int capacity, size;
  
  LRUCache(int capacity): capacity(capacity), size(0), front(NULL), back(NULL) {} 

  void put(int key, int value) {
    if (node_map.find(key) != node_map.end()) {
      update(key, value);
      return;
    }
    insert(key, value);
  }

  int get(int key) {
    int value = -1;
    if (node_map.find(key) != node_map.end()) {
      value = node_map[key]->value;
      update(key, value);
    }
    return value;
  }
};

int main() {
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
