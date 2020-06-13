# Enter your code here. Read input from STDIN. Print output to STDOUT

import sys
import re

s = ""
for line in sys.stdin:
    s += line + " "

regex_pattern = r'question-summary-(\w+)">.*?class="question-hyperlink">(.+?)</a>.*?class="relativetime">(.+?)</span>'
match = re.findall(regex_pattern, s, re.DOTALL)

for obj in match:
    print(';'.join(obj))