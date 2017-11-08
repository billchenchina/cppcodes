o=open("hack.txt","wb")
T=100000
o.write(str(T))
o.write("\n")
for i in range(T):
    o.write(str(65535))
    o.write("\n")
o.close()