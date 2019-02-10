import sys
import functools
import cProfile


import re
cProfile.run('re.compile("foo|bar")')

