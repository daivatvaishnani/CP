def separator():
  print("==================================================")


class LRUNode:
  def __init__(self, key, value):
    self.key = key
    self.value = value
    self.prev = None
    self.next = None

  def print(self):
    if self is not None:
      print("key: {0}, value: {1}, node: {2}, prev: {3}, next: {4}".format(self.key, self.value, self, self.prev, self.next))


class LRUCache:
  def __init__(self, capacity):
    self.capacity = capacity
    self.size = 0
    self.front = None
    self.back = None
    self.node_map = {}
  
  def update(self, key, value):
    assert key in self.node_map
    self.delete(self.node_map[key])
    self.insert(key, value)

  def delete(self, node):
    if node is not None:
      assert node.key in self.node_map
      del self.node_map[node.key]
      self.size -= 1
      if self.front is self.back:
        self.front = None
        self.back = None        
      elif node is self.front:
        self.front = node.next
        self.front.prev = None
      elif node is self.back:
        self.back = node.prev
        self.back.next = None
      else:
        node.prev.next = node.next
        node.next.prev = node.prev
      node = None
  
  def insert(self, key, value):
    if self.size is self.capacity:
      self.delete(self.back)
    node = LRUNode(key, value)
    self.node_map[key] = node
    self.size += 1
    if self.front is None and self.back is None:
      self.front = node
      self.back = node
      return
    node.next = self.front
    self.front.prev = node
    self.front = node

  def put(self, key, value):
    separator()
    print("PUT: key: {0}, value: {1}".format(key, value))
    if key in self.node_map:
      self.update(key, value)
    else:
      self.insert(key, value)
    self.print()

  def get(self, key):
    separator()
    print("GET: key: {0}".format(key))
    value = -1
    if key in self.node_map:
      value = self.node_map[key].value
      self.update(key, value)
    self.print()
    return value

  def print(self):
    temp = self.front
    print("size: {0}, front: {1}, back: {2}".format(self.size, self.front, self.back))
    while temp != None:
      temp.print()
      temp = temp.next
    for key, value in self.node_map.items():
      print("node_map => key: {0}, value: {1}".format(key, value))
    

cache = LRUCache(2);
cache.put(1, 1);
cache.put(2, 2);
print(cache.get(1))       # returns 1
cache.put(3, 3);          # evicts key 2
print(cache.get(2))       # returns -1 (not found)
cache.put(4, 4);          # evicts key 1
print(cache.get(1))       # returns -1 (not found)
print(cache.get(3))       # returns 3
print(cache.get(4))       # returns 4