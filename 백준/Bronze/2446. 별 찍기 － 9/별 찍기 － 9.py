print(*(lambda y: y+y[::-1][1:])((lambda x : [' '*i + '*'*(2*x-1-2*i) for i in range(x)])(int(input()))), sep='\n')