# list: mutable
# string, tuple: immutable

# tuple can only use 'sort', 'count' functions
# (x, y) = (4, 'fred'), print(y) >>> fred

# (0, 1, 2) < (5, 0, 1) = True
# 0 < 5 is true, so python will stop comparing immediatly
# ('joe', 'sally') > ('joe', 'sam') = False
# the 2 tuples are the same until 'l' and 'm', l < m so false

# sort by values instead of keys
dct = {'a':1, 'b':100, 'c':22}
lst = list()

for k, v in dct.items():
    lst.append((v, k))

lst = sorted(lst, reverse=True)

print(lst)
for v, k in lst:
    print(k, v)