# Enter your code here. Read input from STDIN. Print output to STDOUT

import sys
import re

isfirst = 1
count = 0
for line in sys.stdin:
    if isfirst:
        isfirst = 0
        continue
    
    regex_pattern = r'hackerrank'
    match = len(re.findall(regex_pattern, line, re.IGNORECASE))
    if match:
        count += 1

print(count)