from random import randint

def getRandCharFromSet(set):
    randPos = randint(0, len(set)-1)
    randChar = set[randPos]
    return randChar

D = [10, 100, 10000, 100000, 1000000]
E = [20, 50, 80]
charsets = ["ABCDEFGHIJKLMNOPQRSTUVWXYZ", "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz"]
nCasesPerCombo = 20

fileFormat = "../data/brute_force_input/"
outputFormat = "{}_{}_{}.dat"
lineFormat = "{} {}\n"
for d in D:
    if d == 100000:
        nCasesPerCombo = 20
    elif d == 1000000:
        nCasesPerCombo = 5
    for e in E:
        setPos = 0
        while setPos < len(charsets):
            try:
                output = open(fileFormat+outputFormat.format(d, e, setPos), "x")
            except FileExistsError:
                output = open(fileFormat+outputFormat.format(d, e, setPos), "w")
            finally:
                output.write(str(nCasesPerCombo)+"\n")
            
            i = 0
            print(str(d)+" "+str(e)+" "+str(setPos))
            while i < nCasesPerCombo:
                s1 = []
                while (len(s1) < d):
                    charTo = getRandCharFromSet(charsets[setPos])
                    s1.append(charTo)
                s2 = []
                j = 0
                while (j < len(s1)):
                    roll = randint(1, 100)
                    if (roll <= e):
                        stalin = randint(1, 20)
                        if stalin == 10:
                            pass
                        else:
                            charTo = getRandCharFromSet(charsets[setPos])
                            while charTo == s1[j]:
                                charTo = getRandCharFromSet(charsets[setPos])
                            s2.append(charTo)
                    else:
                        s2.append(s1[j])
                    j += 1
                output.write(str(len(s1))+" ")
                for char in s1:
                    output.write(char)
                output.write("\n")
                output.write(str(len(s2))+" ")
                for char in s2:
                    output.write(char)
                output.write("\n")
                print(i)
                i += 1
            output.close()
            setPos += 1
