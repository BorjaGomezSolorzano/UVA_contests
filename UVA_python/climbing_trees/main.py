import sys

def ancestor_list(dict_names, name):
    V_1 = name
    ancestors_1 = []
    while True:
        if V_1 in dict_names.keys():
            aux = dict_names[V_1]
            ancestors_1.append(aux)
            V_1 = aux
        else:
            return ancestors_1

def common_ancestor(smallest_ancestor, greatest_ancestor):
    n = 0
    for i in range(0, len(smallest_ancestor)):
        a1 = smallest_ancestor[i]
        if a1 in greatest_ancestor:
            return n, greatest_ancestor.index(a1)
        n += 1

    return -1, -1

def print_ancestor(ancestors, name, desc_relat):
    n = ancestors.index(name)
    if n == 0:
        print(desc_relat)
    elif n == 1:
        print('grand '+desc_relat)
    elif n > 1:
        result = ''
        for i in range(1, n):
            if i > 1:
                result += ' '
            result += 'great'
        result += ' grand '+desc_relat
        print(result)

def print_common_ancestor(ancestors_left, ancestors_right):
    n, m = common_ancestor(ancestors_left, ancestors_right)
    if n > 0 or m > 0:
        j = abs(m - n)
        if j > 0:
            print(str(min(m, n)) + ' cousin removed ' + str(j))
        else:
            print(str(min(m, n)) + ' cousin')
    elif n == 0 and m == 0:
        print('sibling')
    else:
        print('no relation')

if __name__ == '__main__':

    i = 0
    query = False
    dict_names = {}
    for line in sys.stdin:
        child_parent = line.split()
        for v in child_parent:
            if i % 2 == 0:
                v1 = v
            else:
                v2 = v

                if query:
                    ancestors_1 = ancestor_list(dict_names, v1)
                    ancestors_2 = ancestor_list(dict_names, v2)

                    if v2 in ancestors_1:
                        print_ancestor(ancestors_1, v2, 'child')
                    elif v1 in ancestors_2:
                        print_ancestor(ancestors_2, v1, 'parent')
                    elif len(ancestors_1) < len(ancestors_2):
                        print_common_ancestor(ancestors_1, ancestors_2)
                    else:
                        print_common_ancestor(ancestors_2, ancestors_1)
                elif v1 != 'no.child':
                    dict_names[v1] = v2

                if v1 == 'no.child':
                    query = True

            i += 1

    exit(0)