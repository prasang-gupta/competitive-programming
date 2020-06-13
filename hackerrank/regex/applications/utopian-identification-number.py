# Enter your code here. Read input from STDIN. Print output to STDOUT

import sys
import re

isfirst = 1
for line in sys.stdin:
    if isfirst:
        isfirst = 0
        continue
    
    regex_pattern = r'^[a-z]{,3}\d{2,8}[A-Z]{3,}$'
    match = len(re.findall(regex_pattern, line))
    if match:
        print("VALID")
    else:
        print("INVALID")