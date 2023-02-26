import math

t = int(input())
while(t):
    entrada = input()
    words = entrada.split()
    p = int(words[0])
    q = int(words[-1])
    _gcd =  math.gcd(p,q)
    print(str(p//_gcd),"/",str(q//_gcd))
    t-=1