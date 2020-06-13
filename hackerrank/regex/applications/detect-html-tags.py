# Enter your code here. Read input from STDIN. Print output to STDOUT

import sys
import re

tags = []
isfirst = 1
for line in sys.stdin:
    if isfirst:
        isfirst = 0
        continue
    
    regex_pattern = r'<\s*(\w+)[\s*/]?.*?>'
    match = re.findall(regex_pattern, line)
    for obj in match:
        tags.append(obj)

tags_set = set(tags)
tags = sorted(list(tags_set))
print(";".join(tags))