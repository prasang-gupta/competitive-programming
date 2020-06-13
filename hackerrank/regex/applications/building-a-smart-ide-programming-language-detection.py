# Enter your code here. Read input from STDIN. Print output to STDOUT

import sys
import re

def get_lang(s):
    regex_pattern = r'import java'
    if (len(re.findall(regex_pattern, s))):
        return "Java"
    regex_pattern = r'import .*'
    if (len(re.findall(regex_pattern, s))):
        return "Python"
    regex_pattern = r'#include.*'
    if (len(re.findall(regex_pattern, s))):
        return "C"
    
    regex_pattern = r';\s+$'
    if (len(re.findall(regex_pattern, s))):
        regex_pattern = r'^\s*((private)|(public))'
        if (len(re.findall(regex_pattern, s))):
            return "Java"
        else:
            return "C"
    else:
        return "Python"

s = ""
for line in sys.stdin:
    s += line + " "

print(get_lang(s))