# Enter your code here. Read input from STDIN. Print output to STDOUT

import sys
import re

isfirst = 1
for line in sys.stdin:
    if isfirst:
        isfirst = 0
        continue
    
    isv4 = 0
    regex_v4 = r'^([0-9]+)\.([0-9]+)\.([0-9]+)\.([0-9]+)$'
    match_v4 = re.findall(regex_v4, line)
    if len(match_v4):
        for obj in match_v4[0]:
            if int(obj) < 256:
                isv4 += 1
    if isv4 == 4:
        print("IPv4")
        continue
    
    regex_v6 = r'^([0-9a-f]+):([0-9a-f]+):([0-9a-f]+):([0-9a-f]+):([0-9a-f]+):([0-9a-f]+):([0-9a-f]+):([0-9a-f]+)$'
    match_v6 = re.findall(regex_v6, line)
    if len(match_v6):
        print("IPv6")
        continue
    print("Neither")