# Enter your code here. Read input from STDIN. Print output to STDOUT

import sys
import re

s = ":C:CPP:JAVA:PYTHON:PERL:PHP:RUBY:CSHARP:HASKELL:CLOJURE:BASH:SCALA:ERLANG:CLISP:LUA:BRAINFUCK:JAVASCRIPT:GO:D:OCAML:R:PASCAL:SBCL:DART:GROOVY:OBJECTIVEC:"
isfirst = 1
for line in sys.stdin:
    if isfirst:
        isfirst = 0
        continue
    regex_pattern = ":" + line.strip().split(" ")[-1] + ":"

    match = len(re.findall(regex_pattern, s))

    if (match):
        print("VALID")
    else:
        print("INVALID")