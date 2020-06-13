# Enter your code here. Read input from STDIN. Print output to STDOUT

import sys
import re

multiline = 0
for line in sys.stdin:
    regex_single = r'//.*$'
    regex_multi_start = r'/\*.*$'
    regex_multi_end = r'.*\*/'

    newstart = 0
    if len(re.findall(regex_multi_start, line)):
        multiline = 1
        newstart = 1
        print(line.strip())

    if len(re.findall(regex_multi_end, line)):
        multiline = 0
        if not newstart:
            print(line.strip())
        continue
            
    if multiline and not newstart:
        print(line.strip())
        continue
    
    match = re.findall(regex_single, line)
    if len(match):
        print(match[0])
        continue