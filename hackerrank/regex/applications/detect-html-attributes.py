# Enter your code here. Read input from STDIN. Print output to STDOUT

import sys
import re
from collections import defaultdict

isfirst = 1
s = ""

for line in sys.stdin:
    if isfirst:
        isfirst = 0
        continue
    s += line + " "

d = defaultdict(set)
regex_tag_attrb = r'<(\w+)(.*?)?>'
regex_attrb = r'\s(\w+)='
for tags, attrs in re.findall(regex_tag_attrb, s):
    d[tags].update(re.findall(regex_attrb, attrs))

for tag, attr in sorted(d.items()):
    print(tag + ":" + ",".join(sorted(attr)))