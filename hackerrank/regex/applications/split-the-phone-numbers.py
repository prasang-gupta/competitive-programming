# Enter your code here. Read input from STDIN. Print output to STDOUT

import sys
import re

isfirst = 1
for line in sys.stdin:
    if isfirst:
        isfirst = 0
        continue
    
    regex_pattern = r'^(\d{1,3})[- ](\d{1,3})[- ](\d{4,10})$'
    match = re.findall(regex_pattern, line)
    print("CountryCode=" + match[0][0] + ",LocalAreaCode=" + match[0][1] + ",Number=" + match[0][2])