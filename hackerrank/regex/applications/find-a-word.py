# Enter your code here. Read input from STDIN. Print output to STDOUT

import sys
import re

isfirst = 0
putinn = 0
n = []
t = []

for line in sys.stdin:
    if not isfirst:
        isfirst = int(line.strip())
        if putinn == 0:
            putinn = 1
        else:
            putinn = 0
        continue
    isfirst -= 1
    s = line.strip()
    if putinn:
        n.append(s)
    else:
        t.append(s)
    
for word in t:
    wordcount = 0
    regex_pattern = '((?<=[\W])|^)' + word + '((?=[\W])|$)'
    for sentence in n:
        wordcount += len(re.findall(regex_pattern, sentence))
    print(wordcount)