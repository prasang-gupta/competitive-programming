# Enter your code here. Read input from STDIN. Print output to STDOUT

import sys
import re

isfirst = 1
for line in sys.stdin:
    if isfirst:
        isfirst = 0
        continue
    
    regex_pattern = r'^\(([+-]?[1-9]\d*(?:\.\d+)?), ([+-]?[1-9]\d*(?:\.\d+)?)\)'
    match = re.findall(regex_pattern, line)
    if not len(match):
        print("Invalid")
        continue
    
    lat, lon = match[0]
    if float(lat) <= 90 and float(lat) >= -90:
        if float(lon) <= 180 and float(lon) >= -180:
            print("Valid")
            continue
    print("Invalid")