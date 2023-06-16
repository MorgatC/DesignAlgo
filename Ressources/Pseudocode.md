# PSEUDO CODE
//Main program

Database named "contact.txt"

strings[] = array of sorted names of database "contact.txt"

searchName = string to search for

start clock;

result = PhoneSearch(strings, searchName, 0, length(strings) - 1)

get execution time clock;

print execution time;
print whole contact infomation of line n°[result]




function PhoneSearch(strings[], searchName, start, end)

while(start<= end) 

    mid=(start+end)/2;
    
    compareResult = compareStrings(strings[mid], searchName)

    if compareResult == 0
        flag=1
        return "String found at index " + mid
    else if compareResult < 0
        start = mid + 1;
    else
        end = mid - 1;

if flag==0

        print "String not found"
        
        leave program


**THIS PSEUCODE IS ONLY FOR THE PRIMARY FUNCTION OF THE ACTUAL CODE, IF YOU WANT TO SEE ALL THE PROGRAM
OPEN MAIN.C THERE ARE MANY FEATURES IN IT**
