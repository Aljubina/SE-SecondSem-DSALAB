# Linear Probing
def insert_linear(ht, n) :
    key = int(input("Enter the telephone no : "))
    loc = key % n;
    for i in range(n) :
        index = (loc + i) % n
        if ht[index] == -1 :
            ht[index] = key
            print(f"Key {key} inserted at location {index}.")
            return
    print("Hash Table is full. Cannot insert key.")
    
def search_linear(ht, n) :
    key = int(input("Enter the telephone no : "))
    loc = key % n;
    for i in range(n) :
        index = (loc + i) % n
        if ht[index] == key :
            print(f"Key {key} found at location {index}.")
            return
        if ht[index] == -1 :
            break
    print("Key not found")
    
def remove_linear(ht, n) :
    key = int(input("Enter the telephone no : "))
    loc = key % n;
    for i in range(n) :
        index = (loc + i) % n
        if ht[index] == key :
            ht[index] = -1
            print(f"Key {key} removes from location {index}.")
            return
        if ht[index] == -1 :
            break
    print("Key not found")
    
#  Quadratic  Probing
def insert_quadratic(ht, n) :
    key = int(input("Enter the telephone no : "))
    loc = key % n;
    for i in range(n) :
        index = (loc + i*i) % n
        if ht[index] == -1 :
            ht[index] = key
            print(f"Key {key} inserted at location {index}.")
            return
    print("Hash Table is full. Cannot insert key.")
    
def search_quadratic(ht, n) :
    key = int(input("Enter the telephone no : "))
    loc = key % n;
    for i in range(n) :
        index = (loc + i*i) % n
        if ht[index] == key :
            print(f"Key {key} found at location {index}.")
            return
        if ht[index] == -1 :
            break
    print("Key not found")
    
def remove_quadratic(ht, n) :
    key = int(input("Enter the telephone no : "))
    loc = key % n;
    for i in range(n) :
        index = (loc + i*i) % n
        if ht[index] == key :
            ht[index] = -1
            print(f"Key {key} removes from location {index}.")
            return
        if ht[index] == -1 :
            break
    print("Key not found")
    
def display(ht):
    print("Hash Table contents :")
    for i, val in enumerate(ht) :
        print(f"Index {i} : {val}")
        
def main() :
    n = int(input("Enter hash table size: "))
    ht = [-1] * n
    
    while True:
        print("\nMenu")
        print("1. Insert (Linear Probing)")
        print("2. Insert (Quadratic Probing)")
        print("3. Display")
        print("4. Search (Linear Probing)")
        print("5. Search (Quadratic Probing)")
        print("6. Remove (Linear Probing)")
        print("7. Remove (Quadratic Probing)")
        print("8. Exit")
        ch = int(input("Enter Choice: "))

        if ch == 1:
            insert_linear(ht, n)
        elif ch == 2:
            insert_quadratic(ht, n)
        elif ch == 3:
            display(ht)
        elif ch == 4:
            search_linear(ht, n)
        elif ch == 5:
            search_quadratic(ht, n)
        elif ch == 6:
            remove_linear(ht, n)
        elif ch == 7:
            remove_quadratic(ht, n)
        elif ch == 8:
            print("Exiting program.")
            break
        else:
            print("Invalid choice. Try again.")

main()

    