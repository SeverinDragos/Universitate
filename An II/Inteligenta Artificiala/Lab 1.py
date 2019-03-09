#CTRL + / comenteaza liniile selectate CRTL + Q informatii despre functia highlighted
# x = 5
# print(x)
# print(type(x))
# x += 3
# print(x) # Nu merge print(x += 3)
# x **= 3
# print(x)
# x /= 3
# print(x)
# x *= 3
# x //= 3
# print(x)
'''Geani si'''
"""Burtocul lui"""
# lista = [3, 7, 2, 6, 13]
# print(lista[3])
# print(len(lista))
# print(lista[-1])
# print(lista[len(lista) - len(lista)])
# lista.append(10)
# print(lista)
# lista.append([20,30])
# print(lista)
# lista.pop()
# print(lista)
# lista.pop(1)
# print(lista)
# lista.extend([20, 30, 40])
# print(lista)
# lista.insert(1, 57)
# print(lista)
# print(lista[1:3:1])
# print(lista[1:-1:2]) # De la pozitia 1 la pozitia finala (exclusiv) din 2 in 2
# print(lista[1::2])
# print(lista[::2])
# print(lista[:4:2])
# a = b = c = 0 # a, b, c = 0, 0, 0
# for val in lista:
#     if val < 13:
#         a += 1
#     elif val > 13:
#         b += 1
#     else:
#         c += 1
#
# print('a = %d, b = %d, c = %d' %(a, b, c))
# listutica = []
# for val in lista:
#     for val2 in lista:
#         if val2 > 13:
#             listutica.append(val * val2)
#
# print(listutica)
#
# listoaie = [val * val2 for val in lista for val2 in lista if val2 > 13]
#
# for idx in range(len(lista)): #range(3) => 0, 1, 2 range(1, 4) => 1, 2 ,3 range(0, 5, 2) => 0, 2, 4
#     print(lista[idx])
#
# #functii
# print(lista)
# def extrage(L):
#     elem = L[-1]
#     L.pop()
#     return elem
# print(extrage(lista))
# print(lista)
#
# L = lista.copy()
# print(extrage(L))
# print(lista)
# print(L)

#1.a
ypred = [1, 1, 1, 0, 1, 0, 1, 1, 0, 0]
ytrue = [1, 0, 1, 0, 1, 0, 1, 0, 1, 0]
def acc(ytrue,ypred):
    se = 0
    for idx in range(len(ytrue)):
        if ytrue[idx] == ypred[idx]:
            se += 1
    return se/len(ytrue)
print(acc(ytrue, ypred))

def prec_rec(ytrue, ypred):
    tp = fp = fn = 0
    for idx in range(len(ytrue)):
        if ytrue[idx] == ypred[idx] == 1:
            tp += 1
        elif ytrue[idx] == 1 and ypred[idx] == 0:
            fn += 1
        elif ytrue[idx] == 0 and ypred[idx] == 1:
            fp += 1
    return tp / (tp + fp), tp / (tp + fn)
print(prec_rec(ytrue, ypred))

def mse(ytrue, ypred):
    mse = 0
    for index in range(len(ytrue)):
        mse += (ypred[index] - ytrue[index]) * (ypred[index] - ytrue[index])
    return mse / len(ytrue)
print(mse(ytrue, ypred))

def mae(ytrue, ypred):
    mae = 0
    for index in range(len(ytrue)):
        mae += abs(ypred[index] - ytrue[index])
    return mae / len(ytrue)
print(mae(ytrue, ypred))
