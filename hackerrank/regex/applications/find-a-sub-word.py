# Enter your code here. Read input from STDIN. Print output to STDOUT

import sys
import re

isfirst = 0
putinn = 0
n = ""
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
        n += line + " "
    else:
        t.append(s)
    
for word in t:
    regex_pattern = r'(?<=\w)' + word + r'(?=\w)'
    wordcount = len(re.findall(regex_pattern, n))
    print(wordcount)