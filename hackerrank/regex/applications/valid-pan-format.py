# Enter your code here. Read input from STDIN. Print output to STDOUT

import sys
import re

isfirst = 1
for line in sys.stdin:
    if isfirst:
        isfirst = 0
        continue
    s = line.strip()
    regex_pattern = r'^[A-Z]{5}\d{4}[A-Z]$'

    if len(re.findall(regex_pattern, s)):
        print ("YES")
    else:
        print ("NO")