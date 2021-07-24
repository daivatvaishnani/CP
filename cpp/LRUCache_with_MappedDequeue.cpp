#include <bits/stdc++.h>

using namespace std;

template <class K, class V>
class MappedDequeue {
  class Node {
  public:
    K key;
    V value;
    Node *prev, *next;

    Node(K key, V value): key(key), value(value), prev(NULL), next(NULL) {}
  };

  Node *front, *back;
  unordered_map<K, Node*> node_map;
  int _size;
  
  std::optional<V> remove(Node *node) {
    if (!node) {
      return std::nullopt;
    }
    assert(has_key(node->key));
    V node_value = node_map[node->key]->value;
    node_map.erase(node->key);
    _size--;
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
    return node_value;
  }

public: 
  int size() {
    return _size;
  }
  
  MappedDequeue(): _size(0), front(NULL), back(NULL) {} 

  bool has_key(K key) {
    return node_map.find(key) != node_map.end();
  }
  
  void push_front(K key, V value) {
    assert(!has_key(key));
    Node *node = new Node(key, value);
    node_map[key] = node;
    _size++;
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

  void push_back(K key, V value) {
    assert(!has_key(key));
    Node *node = new Node(key, value);
    node_map[key] = node;
    _size++;
    if (!front && !back) {
      front = node;
      back = node;
    } else {
      node->prev = back;
      back->next = node;
      back = node;
    }
    node = NULL;
    delete node;
  }
  
  void update(K key, V value) {
    assert(has_key(key));
    node_map[key]->value = value; 
  }

  std::optional<V> remove(K key) {
    return remove(node_map[key]);
  }

  std::optional<V> pop() {
    return remove(back);
  } 
  
  std::optional<V> get(K key) {
    if (has_key(key)) {
      return node_map[key]->value;
    }
    return std::nullopt;
  }
};


class LRUCache {
  MappedDequeue<int, int> mapped_dequeue;
public:
  int capacity;
  
  LRUCache(int capacity): capacity(capacity) {} 

  void put(int key, int value) {
    if (mapped_dequeue.has_key(key)) {
      mapped_dequeue.remove(key);
      mapped_dequeue.push_front(key, value);
      return;
    }
    if (mapped_dequeue.size() == capacity) {
      mapped_dequeue.pop();
    }
    mapped_dequeue.push_front(key, value);
  }

  int get(int key) {
    if (mapped_dequeue.has_key(key)) {
      int value = mapped_dequeue.get(key).value();
      mapped_dequeue.remove(key);
      mapped_dequeue.push_front(key, value);
    }
    return mapped_dequeue.get(key).value_or(-1);
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

