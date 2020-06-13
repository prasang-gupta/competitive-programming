# Enter your code here. Read input from STDIN. Print output to STDOUT

import sys
import re

isfirst = 1
for line in sys.stdin:
    if isfirst:
        isfirst = 0
        continue
    s = line.strip()
    regex_pattern = r'^[Hh][Ii]\s[^Dd]'

    match = len(re.findall(regex_pattern, s))

    if (match):
        print(s)