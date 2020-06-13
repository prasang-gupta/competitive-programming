# Enter your code here. Read input from STDIN. Print output to STDOUT

import sys
import re

isfirst = 1
emails = []
s = ""

for line in sys.stdin:
    if isfirst:
        isfirst = 0
        continue
    s += line + " "

regex_pattern = r'\b[a-zA-Z][\w\.]*@[\w]+(?:\.[\w]+){1,}\b'
match = re.findall(regex_pattern, s)

match_sorted = sorted(match)

last_mail = ""
for i in range(len(match_sorted)):
    if match_sorted[i] == last_mail:
        continue
    else:
        last_mail = match_sorted[i]
        
    if i == len(match_sorted) - 1:
        print (match_sorted[i], end = '')
    else:
        print(match_sorted[i] + ";", end = '')