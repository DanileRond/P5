infile = r"../../work/tblfile.log"

important = []
keep_phrases = ["test",
              "important",
              "keep me"]

with open(infile) as f:
    f = f.readlines()

for line in f:
    for phrase in keep_phrases:
        if phrase in line:
            important.append(line)
            break

print(important)
