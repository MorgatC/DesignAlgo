# Phone Directory Program

This is a simple phone directory program written in C. It allows you to search for phone numbers by name, first name, or phone number itself. You can also search based on a specific function, such as "student," "administrator," or "professor." The program reads data from a file and displays the results based on the user's input.


## Usage
1. Clone the repository or download the source code files and the "database.txt" file

2. Compile the program using a C compiler. For example, using GCC:

```bash
gcc main.c -o phone_directory
```
3. Run the compiled executable:
```bash
./phone_directory
```
4. Follow the on-screen menu prompts to perform various operations.
   
*You could also download the "main.exe" + the "database.txt" files that is provided if you don't have a C compiler*


## Functionality
The program provides the following options in the menu:

1. Searching for a phone number by name: Enter a name and get the corresponding phone number(s) for matching contacts.

2. Search for a phone number by first name: Enter a first name and get the corresponding phone number(s) for matching contacts.

3. Searching for a name from a phone number: Enter a phone number (without the +66 country code) and get the corresponding contact's name.

4. Search based on a function: Choose a specific function (e.g., "student," "administrator") and display the contacts with that function.

5. Show the whole list: Display the entire phone directory with all contacts.

6. Leave the program: Exit the program.

## Customization
By default, the program reads contact data from a file named **"database.txt"**. You can customize this file by modifying the ***readContactsFromFile*** function in the code. The file should follow a specific format: each line should contain **comma-separated values** in the order of **"first name, last name, function, phone number"**.
You also need to change the **maxContacts** constant at the beginning of the function ***Menu()*** to match the max number of lines of your new .txt file

*Additionally, you can uncomment the lines in the code that define a predefined test database and comment out the readContactsFromFile function call to use the test data instead.*

## Contributing
Contributions are welcome! If you find any issues or have suggestions for improvements, please create an issue or submit a pull request.

## Author
Morgat Cochennec ES04094
Zoe Savi ES04034
Lea Fougera ES04032
Corentin Gigot ES
