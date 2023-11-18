# Assignment 3B

string = input("Enter a string: ")

def longest_word():
        maxw = 0
        l = []
        temp = ""
        for i in string:
                if i == " ":
                    l.append(temp)
                    temp = ""
                else:
                        temp = temp+i
        l.append(temp)

        for i in l:
            countw = 0
            for k in i:
                countw = countw+1
            if countw >= maxw:
                maxw = countw
                maxwi = i
        print("Word with longest length is: ",maxwi," with length: ", maxw)

def occurrence():
        ch = input("Enter the character you want to count: ")
        occ = 0
        for i in string:
                if i == ch:
                        occ += 1
        print("The character",ch,"occurs",occ," times in given string")

def palindrome():
        rev_str = ""
        for i in string:
        	rev_str = i + rev_str
        print("Reverse of given string is: ", rev_str)
        if string == rev_str:
            print("String is palindrome.")
        else:
            print("String is not palindrome.")


longest_word()
occurrence()
palindrome()

            

