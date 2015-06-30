from collections import defaultdict
n = int(raw_input("Enter total number of nodes"))
j = 0
f = open("1.txt")
for w in f:
    j = j + 1
f.close()
cn = raw_input("Enter the threshold")
rt = float(j / float((n * (n - 1)) / 2))
print rt
def admatrix():
    c = [[0 for x in range(n)] for x in range(n)]
    a = [0, 0, 0]
    f = open("1.txt")
    for w in f:
        l = 0
        for i in w.split(' '):
            a[l] = int(i)
            l = l + 1
        c[a[0] - 1][a[1] - 1] = (a[2])
        c[a[1] - 1][a[0] - 1] = (a[2])
    print c
    f.close()
    bfs(c)
    # dfs()
def adlist():
    dict1 = defaultdict(dict)
    dict2 = {}
    a = [0, 0, 0]
    f = open("1.txt")
    for w in f:
        l = 0
        for i in w.split(' '):
            a[l] = int(i)
            l = l + 1
        # dict2[a[1]]=a[2]
        dict1[a[0]][a[1]] = a[2]
        dict2 = {}
    print dict1
    # bfs()
    # dfs()
def bfs(c=[[0 for x in range(n)] for x in range(n)]):

if (rt < float(cn)):
        print "Using list"
        adlist()
elif (float(cn) <= rt):
        print "Using matrix"
        admatrix()
