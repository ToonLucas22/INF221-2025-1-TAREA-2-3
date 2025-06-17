from random import randint

def getRandCharFromSet(set):
    randPos = randint(0, len(set)-1)
    randChar = set[randPos]
    return randChar

D = [100, 10000, 100000, 1000000]
E = [20, 50, 80]
charsets = ["ABCDEFGHIJKLMNOPQRSTUVWXYZ", "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz"]
nCasesPerCombo = 20

outputFormat = "{}_{}_{}.dat"
lineFormat = "{} {}\n"
for d in D:
    for e in E:
        setPos = 0
        while setPos < len(charsets):
            try:
                output = open(outputFormat.format(d, e, setPos), "x")
            except FileExistsError:
                output = open(outputFormat.format(d, e, setPos), "w")
            finally:
                output.write(str(nCasesPerCombo)+"\n")
            
            i = 0
            while i < nCasesPerCombo:
                s1 = ""
                while (len(s1) < d):
                    charTo = getRandCharFromSet(charsets[setPos])
                    s1 += charTo
                s2 = str(s1)
                j = 0
                while (j < len(s2)):
                    roll = randint(1, 100)
                    if (roll <= e):
                        stalin = randint(1, 20)
                        if stalin == 10:
                            s2 = s2[:j]+s2[j+1:]
                        else:
                            charTo = getRandCharFromSet(charsets[setPos])
                            while charTo[0] == s2[j]:
                                charTo = getRandCharFromSet(charsets[setPos])
                            s2 =s2[:j]+charTo+s2[j+1:]
                            j += 1
                    else:
                        j += 1
                output.write(lineFormat.format(len(s1), s1))
                output.write(lineFormat.format(len(s2), s2))
                i += 1
            output.close()
            setPos += 1
