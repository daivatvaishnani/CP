import re
import sys

class LRUCache:
  class LRUNode:
    def __init__(self, key, value):
      self.key = key
      self.value = value
      self.prev = None
      self.next = None

  def __init__(self, capacity):
    self.capacity = capacity
    self.front = None
    self.back = None
    self.node_map = {}

  def update(self, key, value):
    assert key in self.node_map
    self.delete(self.node_map[key])
    self.insert(key, value)

  def delete(self, node):
    if node != None:
      assert node.key in self.node_map
      del self.node_map[node.key]
      if self.front == self.back:
        self.front = None
        self.back = None
      elif node == self.front:
        self.front = node.next
        self.front.prev = None
      elif node == self.back:
        self.back = node.prev
        self.back.next = None
      else:
        node.prev.next = node.next
        node.next.prev = node.prev
      node = None

  def insert(self, key, value, evict):
    if evict:
      self.delete(self.back)
    node = LRUNode(key, value)
    self.node_map[key] = node
    if self.front == None and self.back == None:
      self.front = node
      self.back = node
      return
    node.next = self.front
    self.front.prev = node
    self.front = node

  def put(self, key, value, evict):
    if key in self.node_map:
      self.update(key, value)
    else:
      self.insert(key, value, evict)

  def get(self, key):
    value = -1
    if key in self.node_map:
      value = self.node_map[key].value
      self.update(key, value)
    return value

