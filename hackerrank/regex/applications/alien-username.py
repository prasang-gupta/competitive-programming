# Enter your code here. Read input from STDIN. Print output to STDOUT

import sys
import re

isfirst = 1
for line in sys.stdin:
    if isfirst:
        isfirst = 0
        continue
    
    regex_pattern = r'^[_\.][0-9]+[a-zA-Z]*_?$'
    match = len(re.findall(regex_pattern, line))
    if match:
        print("VALID")
    else:
        print("INVALID")