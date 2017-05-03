## My Thought Process
We need to continuously loop the function the entire time. Both the *readin* and *write* functions should be right at the beginning, inside the big while loop. You can call *write* inside of the *read* function. On start (assuming there's no file present) we should write a new file. If there is a file present, we need to read in the data(separated by commas) and store them in the appropriate array. My *parser* function inside the *write* function is just a tester, and it can be deleted. We need a parser/store function we can both use during the read and write functions.

After the file is created, or read from, we need to ask if the user wants a *new entry* or *lookup*. If *new entry*, we can start the printf/scanf cylce to add the data to our struct, then store that data in the appropriate array and increment (and so on). If *lookup* we need to ask for an *IDN* create a function that zips through the stored data and/or the read-in file and returns a matching *IDN*.

What my program does as of Wednesday @ 12:04 AM is this:
 - Asks what user wants (if "exit" it quits, if "anything else" it goes into printf/scanf cycle)
 - stores data in appropriate variables in struct
 - moves into the parser
 - seg faults like a mother fucker
 
Tomorrow we need to finish the read and write functions and work on a universal parsing system so we can start messing with our triple array. We also need to get the big while loop (while (1) etc.) functioning. Then on Thursday we can implement the search algorithm.

I hope you see this before I get to the lab.
<3 u.

ballz

### Chores List
# - Read In
  - If no file, create new
# - Parsing
  - Adding Data
    - Removing Data
  - Search Algorithm
    - Displaying Data
    - UI
# - Write
  - "Seek" Functions
  - Write to file
  
  
  
## Salim
- Create read-in function
- Parsing

## Joe
- Create Library
- Create Write function?
- Parsing



## Data Structure
### IDN, Name, Gender, Fav Color

 - IDN = 4 digit number (0001, 2357)
 - Name = 26 character string (25 for name 1 for null)
 - Gender = 3 character string(M, F, NA)
 - Fav Color = It can either be a string or we can have it be a Hex code and then display their info in that color upon search
