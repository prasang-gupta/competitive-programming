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

regex_pattern = r'\bhttp(?:s)?://(?:ww[2w]\.)?([-\w\.]+)[\w/]*\b'
match = re.findall(regex_pattern, s)

match_sorted = sorted(match)

last_mail = ""
firstprint = 1
for i in range(len(match_sorted)):
    if "." not in match_sorted[i]:
        continue

    if match_sorted[i] == last_mail:
        continue
    else:
        last_mail = match_sorted[i]
        
    if firstprint:
        print (match_sorted[i], end = '')
    else:
        print(";" + match_sorted[i], end = '')
    firstprint = 0