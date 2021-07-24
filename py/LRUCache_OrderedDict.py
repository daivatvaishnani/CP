import re
from collections import OrderedDict
class LRUCache(OrderedDict):

    def __init__(self, capacity):
        """
        :type capacity: int
        """
        self.capacity = capacity

    def get(self, key):
        """
        :type key: int
        :rtype: int
        """
        if key not in self:
            return - 1
        
        self.move_to_end(key)
        return self[key]

    def put(self, key, value):
        """
        :type key: int
        :type value: int
        :rtype: void
        """
        if key in self:
            self.move_to_end(key)
        self[key] = value
        if len(self) > self.capacity:
            self.popitem(last = False)


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
            
Tester(open("input", "r"), open("output2", "w")).run()