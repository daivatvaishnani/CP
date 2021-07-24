#include <bits/stdc++.h>

using namespace std;

class LRUNode {
public:
  int key, value;
  LRUNode *next, *prev;

  LRUNode(int key, int value): key(key), value(value), next(NULL), prev(NULL) {}

  void print() {
    printf("{Node: {key: %d, value: %d, ptr: %p, prev: %p, next: %p}}\n", 
    this->key, this->value, (void *)this, (void *)this->prev, (void *)this->next);
  }
};

class LRUCache {
  int capacity, size;
  unordered_map<int, LRUNode*> node_map;
  LRUNode *front, *back;

  void insert(int key, int value) {
    if (node_map.find(key) == node_map.end()) {
      LRUNode *node = new LRUNode(key, value);
      if (!evict()) {
        size++;
      }
      if (front == NULL) {
        front = node;
        back = node;
        node_map[key] = front;
        return;
      }
      node->next = front;
      front->prev = node;
      front = node;
      node_map[key] = front;
      return;
    }
    update(key, value);
  }

  bool update(int key, int value) {
    LRUNode *node = node_map[key];
    node->value = value;
    if (front != node) {
      if (node->prev) {
        node->prev->next = node->next;
        if (back == node) {
          back = node->prev;
        }
      }
      if (node->next) {
        node->next->prev = node->prev;
      }
      node->next = front;
      node->prev = NULL;
      front->prev = node;
      front = node;
      node_map[key] = front;
      return true;
    }
    return false;
  }

  bool evict() {
    if (this->size == capacity) {
      LRUNode *temp = back;
      printf("evicting key: %d, prev: %p, next: %p\n", back->key, (void *)back->prev, (void *)back->next);
      if (back->prev) {
        back = back->prev;
        if (back) {
          back->next = NULL;
          node_map[back->key] = back;
        }
      }
      if (front == temp) {
        front = NULL;
      }
      node_map.erase(temp->key);
      delete temp;
      return true;
    }
    return false;
  }

  void print() {
    LRUNode *temp = front;
    printf("size: %d, front: %p, back: %p\n", this->size, (void *)this->front, (void *)this->back);
    while (temp) {
      temp->print();
      temp = temp->next;
    }
    for(auto p : this->node_map) {
      printf("{key: %d, value: %p}\n", p.first, (void *)p.second);
    }
  }

public:
  LRUCache(int capacity) {
    this->capacity = capacity;
    this->size = 0;
    this->front = NULL;
    this->back = NULL;
  }

  int get(int key) {
    if (node_map.find(key) != node_map.end()) {
      update(key, node_map[key]->value);
      printf("GET: %d\n", key);
      this->print();
      return node_map[key]->value;	
    }
    return -1;
  }

  void put(int key, int value) {
    insert(key, value);
    printf("PUT: (%d, %d)\n", key, value);
    this->print();
    return;
  }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */

int main() {
    ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
    LRUCache cache(2);
    cache.put(2, 1);
    cache.put(2, 2);
    cout << cache.get(2) << "\n";
    cache.put(1, 1);
    cache.put(4, 1);
    cout << cache.get(2) << "\n";
    return 0;
}
