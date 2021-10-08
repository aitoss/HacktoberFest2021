def hash(n):
    return n%11

def insert(val,table):
    tem=hash(val)
    indx=tem
    comp=0
    while(1==1):
        if(table[indx][0]==-1):
            table[indx]=[val,-1]
            return comp
        if(hash(table[indx][0])==tem):
            while(table[indx][1]!=-1):
                indx=table[indx][1]
                comp+=1
            indx2=indx
            while(table[indx][0]!=-1):
                indx=int((indx+1)%11)
                comp+=1
            table[indx]=[val,-1]
            table[indx2][1]=indx
            return comp
        indx=int((indx+1)%11)
        comp+=1
def search(val,table):
    tem=hash(val)
    indx=tem
    comp=0
    while(comp!=11):
        if(table[indx][0]==-1):
            return False,comp
        elif(hash(table[indx][0])==tem):
            while(table[indx][0]!=val and table[indx][1]!=-1 ):
                indx=table[indx][1]
                comp+=1
            if(table[indx][0]==val):
                return True,comp
            else:
                return False,comp
        indx=int((indx+1)%11)
        comp+=1
    return False,comp
def delete():
    pass

def display(ht):
    print()
    count=0
    for i in ht:
        print(count, ".", i[0], " ", i[1])
        count += 1

def insert2(d, ht):
    h = hash(d)
    p = h
    if ht[p][0] == -1:
        ht[p][0] = d
        return 0
    elif hash(ht[p][0]) == h:
        i = p
        for k in range(11):
            if ht[i][1] == -1:
                break
            i = ht[i][1]
        ni = i
        for k in range(11):
            ni += 1
            ni %= 11
            if ht[ni][0] == -1:
                ht[ni][0] = d
                ht[i][1] = ni
                return 0
        return 0
    else:
        k = ht[p][0]
        m = hash(k)
        i = m

        for j in range(11):
            if ht[i][1] == p:
                break
            i = ht[i][1]

        ht[p][0] = d
        ht[p][1] = -1
        l=p
        for j in range(11):
            l += 1
            l %= 11
            if ht[l][0] == -1:
                ht[l][0] = k
                ht[i][1] = l
                return 0

def search2(d, ht):
    h = hash(d)
    p = h
    noc = 0
    for j in range(11):
        if ht[p][0] == d:
            noc += 1
            print("\nFound in , ", p,"Number of Comparisons : ",noc, "\n")
            return 0
        elif hash(ht[p][0]) == h:
            for i in range(11):
                p = ht[p][1]
                noc += 1
                if ht[p][0] == d:
                    noc+=1
                    print("\nFound in ",p,"Number of Comparisons : ",noc,"\n")
                    return 0
            print("\nNot found \n")
            return 0
        else:
            noc += 1
            p += 1
            p %= 11
    print("\nNot found\n")


def printChoice():
    print("1.Search")
    print("2.Insert")
    print("3.Display")

if __name__ == "__main__" :
    n=11
    hashTable=[] 
    hashTable2=[]
    for i in range(n):
        hashTable2.append([-1,-1])
        hashTable.append([-1,-1])
    cnt=0
    while(1==1):
        printChoice()
        ch=int(input("Enter choice:"))
        if(ch==1):
            val=int(input("Enter number to be searched : "))
            has,cnt=search(val,hashTable)
            if(has):
                print("without replacement ~~> Found in ",str(cnt+1)," comp")
            else:
                print("without replacement ~~> Not Found in ",str(cnt+1)," comp")
            search2(val,hashTable2)
        elif(ch==2):
            val=int(input("Enter number to insert : "))
            if(cnt==n):
                print("Table is full cannot insert")
                continue
            insert(val,hashTable)
            insert2(val,hashTable2)
        elif(ch==3):
            print("without replacement:")
            display(hashTable)
            print("with replacement:")
            display(hashTable2)