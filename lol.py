f = open("ab.html", "r")
lund=""
stre = f.read().splitlines()
f.close()
g = open("nom.text","w")
for x in stre:
    lund+=x
lund=lund.replace("\"","'")
g.write(lund)
g.close()
