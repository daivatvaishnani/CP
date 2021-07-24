import re

class LRUNode:
  def __init__(self, key, value):
    self.key = key
    self.value = value
    self.prev = None
    self.next = None

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
    if node != None:
      assert node.key in self.node_map
      del self.node_map[node.key]
      self.size -= 1
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

  def insert(self, key, value):
    if self.size == self.capacity:
      self.delete(self.back)
    node = LRUNode(key, value)
    self.node_map[key] = node
    self.size += 1
    if self.front == None and self.back == None:
      self.front = node
      self.back = node
      return
    node.next = self.front
    self.front.prev = node
    self.front = node

  def put(self, key, value):
    if key in self.node_map:
      self.update(key, value)
    else:
      self.insert(key, value)

  def get(self, key):
    value = -1
    if key in self.node_map:
      value = self.node_map[key].value
      self.update(key, value)
    return value


class Tester:
  def __init__(self, input_file, output_file):
    self.input_file = input_file
    self.output_file = output_file
    self.input_data = self.input_file.readlines()
    self.process()

  def process(self):
    self.operations = re.findall(r"\"(.*?)\"", self.input_data[0])
    data_tokens = re.findall(r"\[(.*?)\]", self.input_data[1].strip()[1:-1])
    self.data = [[int(token.strip()) for token in tokens.split(",")] for tokens in data_tokens]

  def run(self):
    for i in range(len(self.operations)):
      if self.operations[i] == "LRUCache":
        assert len(self.data[i]) == 1
        self.output_file.write("operation: {0}, capacity: {1}\n".format(self.operations[i], self.data[i][0]))
        self.cache = LRUCache(self.data[i][0])
      elif self.operations[i] == "put":
        assert len(self.data[i]) == 2
        self.output_file.write("operation: {0}, key: {1}, value: {2}\n".format(self.operations[i], self.data[i][0], self.data[i][1]))
        self.cache.put(self.data[i][0], self.data[i][1])
      elif self.operations[i] == "get":
        assert len(self.data[i]) == 1
        self.output_file.write("operation: {0}, key: {1}, answer: {2}\n".format(self.operations[i], self.data[i][0], self.cache.get(self.data[i][0])))

Tester(open("input", "r"), open("output", "w")).run()
