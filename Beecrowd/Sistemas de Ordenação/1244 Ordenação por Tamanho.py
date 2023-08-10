n = int(input())

for i in range(n):
    palavras = input().split()
    palavras = sorted(palavras, key=len, reverse=True)
    saida = ' '.join(palavras)
    print(saida)
