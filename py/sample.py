in1_tokens = None
in2_tokens = None

with open("in1", "r") as in1:
  in1_tokens = in1.readline().strip('[').strip(']').split(',')
  with open("out1", "w") as out1:
    for token in in1_tokens:
      out1.write(token + "\n")

with open("in2", "r") as in2:
  in2_tokens = in2.readline().strip('[').strip(']').split(',')
  with open("out2", "w") as out2:
    for token in in2_tokens:
      out2.write(token + "\n")