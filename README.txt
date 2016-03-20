In the second part, you have to implement a linked list that maintains a list of integers in sorted order. Thus, if the list contains 2, 5 and 8, then 1 will be inserted at the start of the list, 3 will be inserted between 2 and 5 and 10 will be inserted at the end.

Input format: This program takes a file name as an argument from the command line. The file is either blank or contains successive lines of input. Each line contains a character, either ‘i’ or ‘d’, followed by a tab character and then an integer. For each of the lines that starts with ‘i’, your program should insert that number in the linked list in sorted order if it is not already there. Your program should not insert any duplicate values. If the line starts with a ‘d’, your program should delete the value if it is present in the linked list. Your program should silently ignore the line if the requested value is not present in the linked list.

Output format: At the end of the execution, your program should print all the values of the linked list in sorted order. The values should be in a single line separated by tabs. There should be no leading or trailing white spaces in the output. Your program should print “error” (and nothing else) if the file does not exist or it contains lines with improper structure. Your program should print a blank line if the input file is empty or the resulting linked list has no nodes.

Example Execution:
Lets assume we have 3 text files with the following contents: “file1.txt” is empty
file2.txt:
i 10
i 12 d 10 i5
file3.txt: d7
i 10 i5
i 10 d 10
Then the result will be:
$./second file1.txt
$./second file2.txt
5 12
$./second file3.txt
5
$./second file4.txt
error
