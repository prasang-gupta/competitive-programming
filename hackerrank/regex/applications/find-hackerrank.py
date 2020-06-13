# Enter your code here. Read input from STDIN. Print output to STDOUT

import sys
import re

isfirst = 1
for line in sys.stdin:
    if isfirst:
        isfirst = 0
        continue
    s = line.strip()
    rstart = r'^hackerrank'
    rend = r'hackerrank$'

    ifstart = len(re.findall(rstart, s))
    ifend = len(re.findall(rend, s))

    if ifstart and ifend:
        print(0)
    elif ifstart:
        print(1)
    elif ifend:
        print(2)
    else:
        print(-1)