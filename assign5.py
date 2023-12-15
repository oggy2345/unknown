def bubble_sort(lst):
    N = len(lst)
    for k in range(N-1):
        j = 0
        while j < N-k-1:
            if lst[j] > lst[j+1]:
                lst[j], lst[j+1] = lst[j+1], lst[j]
            j += 1
    return lst

def selection_sort(lst):
    N = len(lst)
    for i in range(N-1):
        pos = i
        for j in range(i+1, N):
            if lst[j] < lst[pos]:
                pos = j
        lst[i], lst[pos] = lst[pos], lst[i]
    return lst

def accept():
    print("Enter the number of students")
    no_of_stds = int(input())
    print("Enter marks [Enter after each mark entered]")
    lst = []
    for i in range(no_of_stds):
        temp = float(input())
        lst.append(temp)
    return lst

def top_five(lst):
    print("Display top five marks? [y/n]")
    temp = input()
    if temp == 'y':
        print("Top five students marks:")
        for i in range(-1, -6, -1):
            print(lst[i])
        print("*****************************************************")

lst = []
while True:
    print('* * * * * * * MENU * * * * * * *')
    print('1. Enter students marks')
    print('2. Bubble sort')
    print('3. Selection sort')
    print('4. Exit')
    print("Enter your choice [1 to 4]")
    choice = int(input())
    
    if choice == 1:
        lst = accept()
    elif choice == 2:
        bubble_sort(lst)
        print(lst)
        top_five(lst)
    elif choice == 3:
        selection_sort(lst)
        print(lst)
        top_five(lst)
    elif choice == 4:
        exit(0)