def addElement(Set, val) :
    if val not in Set:
        Set.append(val)

def removeElement(Set, ele) :
    if ele in Set :
        Set.remove(ele)
        print("Element removed")

def containElement(Set, ele) :
    if ele in Set:
        print("Element found.")
    else :
        print("Element not found.")
        
def size(Set) :
    print("Size of Set is : ", len(Set))

def display(Set, name="Set") :
    print(f"{name} : ", Set)

def intersection(Set1, Set2) :
    res = [i for i in Set1 if i in Set2]
    print("Intersection : ", res)
    
def union(Set1, Set2) :
    res = Set1.copy()
    for i in Set2 :
        if i not in res :
            res.append(i) 
    print("Union ",res)
    
def difference(Set1 , Set2) :
    res = [i for i in Set1 if i not in Set2]
    print("Difference (Set1-Set2) : ", res)
    
def subset(Set1, Set2) :
    if all(i in Set1 for i in Set2) :
        print("Set2 is Subset.")
    else :
        print("Set2 is not Subset.")
        
#Main Driver Code
Set1 = []
Set2 = []

while True:
    print("\n==== Set ADT Menu ====")
    print("1. Add Elememt to Sets")
    print("2. Remove element")
    print("3. Check if element exists")
    print("4. Get size of Set1")
    print("5. Intersection of Set1 and Set2")
    print("6. Union of Set1 and Set2")
    print("7. Difference (Set1 - Set2)")
    print("8. Check if Set2 is subset of Set1")
    print("9. Display sets")
    print("10. Exit")
    
    ch = int(input("Enter your choice (1-10) : "))
    
    if ch == 1:
        Set1.clear()
        Set2.clear()
        for i in range(int(input("Enter Number of Elements in Set1 : "))):
            addElement(Set1, int(input("Enter element for Set1 : ")))
        for i in range(int(input("Enter Number of Elements in Set2 : "))):
            addElement(Set2, int(input("Enter element for Set2 : ")))
            
    elif ch == 2:
        ele = int(input("Enter the element to remove : "))
        set_choice = int(input("Remove from:\n1. Set1 \n2. Set2\n Enter Your Choice : "))
        if set_choice == 1 :
            removeElement(Set1, ele)
        else :
            removeElement(Set2, ele)
            
    elif ch == 3:
        ele = int(input("Enter Element to check : "))
        set_choice = int(input("Check in:\n1. Set1 \n2. Set2\n Enter Your Choice : "))
        if set_choice == 1 :
            containElement(Set1, ele)
        else :
            containElement(Set2, ele)
    
    elif ch == 4:
        set_choice = int(input("Size of :\n1. Set1 \n2. Set2\n Enter Your Choice : "))
        if set_choice == 1 :
            size(Set1)
        else :
            size(Set2)
            
    elif ch == 5:
        intersection(Set1, Set2)
        
    elif ch == 6:
        union(Set1, Set2)

    elif ch == 7:
        difference(Set1, Set2)

    elif ch == 8:
        subset(Set1, Set2)

    elif ch == 9:
        display(Set1, "Set1")
        display(Set2, "Set2")
        
    elif ch == 10:
        print("Exiting")
        break
    else :
        print("Invalid choice. Try again.")