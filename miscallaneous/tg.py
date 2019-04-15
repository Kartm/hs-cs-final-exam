import math
y = -1.0145

#!result = 2x
#x - radians
# convert to deg

# we know the tg, we don't know the x
left = math.pi / -0.5
right = 0
for x in range(200):
    middle = (left+right)/2
    val = math.tan(middle)
    print('left ', left, ', right ', right, 'val: ', val)
    if(val <= y):
        left = middle
    else:
        right = middle

result = left/2
print(math.degrees(result + math.pi))

result = math.degrees(result)
# print(result)
