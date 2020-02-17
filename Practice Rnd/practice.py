import sys
from itertools import combinations


filename = sys.argv[1]

file = open(filename, "r")

with file:
    content = file.readlines()
content = [x.strip() for x in content] 

content[0] = content[0].split()
content[1] = content[1].split()

for index, item in enumerate(content[0]):
    content[0][index] = int(item)
for index, item in enumerate(content[1]):
    content[1][index] = int(item)


maxslices = content[0][0] #max slices to order
ntypes = content[0][1]
types = content[1]



orders = [0, 0, 0, 0]

print(content)
print(types)


#as many pizza slices as possible, but not more than the maximum number.

finalmax = 0

combos = []

for L in range(0, len(types)+1):
    for subset in combinations(types, L):
        combos.append(list(subset))

combos = filter(lambda x: sum(x) < maxslices, combos)

print(combos)

def maximumSum(list1): 
    return(max(list1, key = sum))

maxlst = maximumSum(combos) #list with types
ammounts = []
for i in range(ntypes):
    if types[i] in maxlst:
        ammounts.append(1)
    else:
        ammounts.append(0)

print(max)
print(ammounts)

outfile = open("result.out","w") 
outfile.write(str(len(maxlst)) + '\n')

templst = []
for i in range(len(ammounts)):
    if ammounts[i] == 1:
        templst.append(i)

outbuffer = ' '.join(map(str, templst)) 

print(templst)
outfile.write(outbuffer)
