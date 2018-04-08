#Program liczy stopnie wierzcholkow grafu
class Graph:
    def __init__(self, a, b):
        self.a = a
        self.b = b


def bigger_than_0(num):
    if num > 0:
        return num
    else:
        exit()

def edges(d_vert):
    edges_to_return = []
    for keys in d_vert.keys():
        for values in d_vert.values():
            edges_to_return.append((keys, values))
    return edges_to_return


vertices = bigger_than_0(int(raw_input("Podaj liczbe wierzcholkow:\n")))
v_dict = {}

i = 1
while vertices >= i:
    neighbors = raw_input("Podaj sasiadow wierzcholka nr. %i \n" % (i)) #Podaj numery sasiadow po przecinku
    neighbors = list(neighbors.split(","))
    v_dict.update({i:neighbors})
    i += 1

print v_dict
#for keys in v_dict.values():
 #   print keys

a = edges(v_dict)
print a

lolo = {2:"rr", 3:("tu","tam","siam")}

for values in lolo.values():
    for pair in values:
        print pair

