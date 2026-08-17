'''def squares(n):
    for i in range(1, n + 1):
        yield i ** 2
#for n in squares(5):
    #print(n)'''






'''def even_seq(n):
    for i in range(1, n+1):
        yield i * 2
#for n in even_seq(5):
#    print(n)'''






'''def three_and_four(n):
    for i in range(0, n+1):
        if i%4 == 0 and i %3 == 0:
            yield i
# for n in three_and_four(12):
#     print(n)'''








'''def squares(a, b):
    for i in range(a, b+1):
        yield i ** 2
#for n in squares(1, 5):
    #print(n)'''






def seq(n):
    for i in reversed(range(0, n+1)):
        yield i
for n in seq(int(input())):
    print(n)