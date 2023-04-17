n = int(input)

for i in range(n):
    palavras = input().split()
    palavras = sorted(palavras, key=lambda x: (-len(x), palavras.index(x)))
    print(" ".join(palavras))
