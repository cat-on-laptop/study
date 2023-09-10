import math, random, time

def DFT(P):
    n = len(P) # n is assumed to be 2^k
    if n == 1: return [complex(P[0])]

    even = P[::2]
    odd = P[1::2]

    L = DFT(even)
    R = DFT(odd)

    wn = complex(math.cos(2*math.pi/n), math.sin(2*math.pi/n))
    w = complex(1)
    Y = [complex(0)]*n
    for j in range(n//2):
        Y[j] = L[j] + w*R[j]
        Y[j+n//2] = L[j] - w*R[j]
        w = w * wn
    return Y

def Inverse_DFT(Y):
    n = len(Y) # n samples from (n-1)th polynomial
    if n == 1: return Y

    even = Y[::2]
    odd = Y[1::2]

    L = Inverse_DFT(even)
    R = Inverse_DFT(odd)

    # wn, w, P 모두 complex 수로 초기화 필요
    wn = complex(math.cos(2*math.pi/n), -math.sin(2*math.pi/n)) # 켤레 복소수!
    w = complex(1)
    P = [complex(0)]*n
    for j in range(n//2):
        P[j] = (L[j] + w*R[j])
        P[j+n//2] = (L[j] - w*R[j])
        w = w * wn
    
    return P

def multiply_polynomial(P, Q):
    n = len(P) # P: list of coeff. of (n-1)th polynomial
    m = len(Q) # Q: list of coeff. of (m-1)th polynomial

    power2 = 2**math.ceil(math.log2(n+m-1))
     
    for i in range(n, power2): # padding up to closest power of 2 to n+m-1
        P.append(0)
    for j in range(m, power2):
        Q.append(0)

    Yp = DFT(P)
    Yq = DFT(Q)

    Y = []
    for i in range(power2):
        Y.append(Yp[i]*Yq[i])
    
    PQ = Inverse_DFT(Y)
    PQ = [y/power2 for y in PQ]

    return [round(a.real) for a in PQ[:n+m-1]]

def generate_X(n):
    # generate n+1 x values for nth polynomial as roots of w^{n+1} = 1
    X = []
    wn = complex(math.cos(2*math.pi/n), math.sin(2*math.pi/n))
    w = complex(1)
    for k in range(n+1):
        X.append(w)
        w = w*wn
    return X

def Three_SUM(X, Y, Z):
    mx, my, mz = -min(0, min(X)), -min(0, min(Y)), -min(0, min(Z))
    # print(mx, my, mz)

    # find a triple (x, y, z) s.t. x+y+z = 3m_value
    PX = [0]*(max(0,max(X))+mx+1)
    PY = [0]*(max(0,max(Y))+my+1)
    PZ = [0]*(max(0,max(Z))+mz+1)
    for x in X:
        PX[x+mx] = 1
    for y in Y:
        PY[y+my] = 1
    for z in Z:
        PZ[z+mz] = 1

    # multiply X, Y, Z
    PXY = multiply_polynomial(PX, PY)
    PXYZ = multiply_polynomial(PXY, PZ)

    return PXYZ[mx+my+mz]

def Three_SUM_n2(X, Y, Z):
    #X.sort()
    Y.sort()
    Z.sort()

    count = 0
    for x in X:
        i = 0
        j = len(Z)-1
        while i < len(Y) and j >= 0:
            sum = x + Y[i] + Z[j]
            if sum == 0:
                #print(x, Y[i], Z[j])
                count += 1
                i += 1
                j -= 1
            elif sum < 0:
                i += 1
            else:
                j -= 1
    return count

def Needle(X, Y, Z):
    # points in X, Y, Z are at 0, 1, 2 y-coordinates, resp.
    # find a triple (x, y, z) s. t x + z = 2y, so x - 2y + z = 0

    Y = [-2*y for y in Y]

#    t1 = time.time()
    ans = Three_SUM(X, Y, Z)
#    print("FFT = ", ans)
#    t2 = time.time()
#    print(t2-t1)
#    ans = Three_SUM_n2(X, Y, Z)
    print(ans)    
#    t3 = time.time()
#    print(t3-t2)

def generate_XYZ(n, M):
    random.seed()
    X = random.sample(range(-M, M), n)
    Y = random.sample(range(-M, M), n)
    Z = random.sample(range(-M, M), n)
    return X, Y, Z


u = int(input())
X = [int(x) for x in input().split()]
m = int(input())
Y = [int(x) for x in input().split()]
l = int(input())
Z = [int(x) for x in input().split()]

Needle(X, Y, Z)