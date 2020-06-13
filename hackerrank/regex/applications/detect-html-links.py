# Enter your code here. Read input from STDIN. Print output to STDOUT

import sys
import re

isfirst = 1
s = ""
for line in sys.stdin:
    if isfirst:
        isfirst = 0
        continue
    s += line + ' '
    
regex_pattern = r'<a href="(.*?)".*?>([^<].*?)<'
match = re.findall(regex_pattern, s)
for obj in match:
    print(obj[0] + "," + obj[1].strip())