def get_sum(strings):
    total=0
    for i in strings:
        total+=ord(i)
    return total

def insert_contact_linear(arr,name,contact_no,n):
    val=get_sum(name)
    cnt=0
    while(True):
        if(arr[(val+cnt)%n]==-1 or arr[(val+cnt)%n]==[name,contact_no] or arr[(val+cnt)%n]==-2):
            arr[(val+cnt)%n]=[name,contact_no]
            return True,cnt+1
        elif(cnt==n):
            return False,cnt+1
        else:
            cnt+=1

def deletion_linear(arr,name,n):
    val=get_sum(name)
    cnt=0
    while(True):
        if(arr[(val+cnt)%n]==-1 or cnt==n):
            return False,cnt+1
        elif(arr[(val+cnt)%n][0]==name):
            arr[(val+cnt)%n]=-2
            return True,cnt+1
        else:
            cnt+=1

def search_linear():
    val=get_sum(name)
    cnt=0
    while(True):
        if(arr[(val+cnt)%n]==-1 or cnt==n):
            return False,cnt+1
        elif(arr[(val+cnt)%n][0]==name):
            return True,cnt+1
        else:
            cnt+=1

def insert_contact_quad(arr,name,contact_no,n):
    val=get_sum(name)
    cnt=0
    while(True):
        if(arr[(val+cnt*cnt)%n]==-1 or arr[(val+cnt*cnt)%n]==[name,contact_no] or arr[(val+cnt*cnt)%n]==-2):
            arr[val%n+cnt*cnt]=[name,contact_no]
            return cnt+1
        else:
            cnt+=1
    
def search_quad(arr,name,n):
    val=get_sum(name)
    cnt=0
    while(True):
        if(arr[(val+cnt*cnt)%n]==-1):
            return False,cnt+1
        elif(arr[(val+cnt*cnt)%n][0]==name):
            return True,cnt+1
        else:
            cnt+=1

def deletion(arr,name,n):
    val=get_sum(name)
    cnt=0
    while(True):
        if(arr[(val+cnt*cnt)%n]==-1):
            return False,cnt+1
        elif(arr[(val+cnt*cnt)%n][0]==name):
            arr[(val+cnt*cnt)%n]=-2
            return True,cnt+1
        else:
            cnt+=1

if __name__ == "__main__":
    n=23
    arr=[-1]*n
    arr_linear=[-1]*n
    while(1):
        print("\n1.insert in quad\n2.search in quad\n3.display in quad\n4.deletion in quad\n5.insert in linear\n6.search in linear\n7.display in linear\n8.deletion in linear")
        ch=int(input("Enter choice:"))
        if(ch==1):
            name=input("Enter name:")
            contact_no=int(input("Enter contact no:"))
            times=insert_contact_quad(arr,name,contact_no,n)
            print("added in ",str(times)," comp")
            print(arr)
        elif(ch==2):
            name=input()
            has,cnt=search_quad(arr,name,n)
            if(has):
                print(name," is found ",str(cnt+1)," counts required to search")
            else:
                print(name," is not found ",str(cnt+1)," counts required to search")    
            print(arr)
        elif(ch==3):
            print(arr)
        elif(ch==4):
            name=input("Enter name:")
            has,cnt=deletion(arr,name,n)
            if(has):
                print(name," is found ",str(cnt+1)," counts required to delete")
            else:
                print(name," is not found ",str(cnt+1)," counts required to delete")    
            print(arr)
        elif(ch==5):
            name=input("Enter name:")
            contact_no=int(input("Enter contact no:"))
            done,cnt=insert_contact_linear(arr_linear,name,contact_no,n)
            if(done):
                print("Contact added ",str(cnt)," counts required to insert")
            else:
                print("Contact not added ",str(cnt)," counts required to insert")
            print(arr_linear)
        elif(ch==6):
            name=input()
            has,cnt=search_linear(arr_linear,name,n)
            if(has):
                print(name," is found ",str(cnt+1)," counts required to search")
            else:
                print(name," is not found ",str(cnt+1)," counts required to search")
            print(arr_linear)
        elif(ch==7):
            print(arr_linear)
        elif(ch==8):
            name=input()
            has,cnt=deletion_linear(arr_linear,name,n)
            if(has):
                print(name," is found ",str(cnt+1)," counts required to delete")
            else:
                print(name," is not found ",str(cnt+1)," counts required to delete")
            print(arr_linear)

