print(*(lambda x: [x[i]*'=' for i in range(len(x))])([int(input()) for _ in range(int(input()))]), sep='\n')
