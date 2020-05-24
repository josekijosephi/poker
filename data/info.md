## Outline of the folder --


### Preliminary information

I didn't commit my output file since it has too many lines -> you'll need to do that yourself

### input

The directory containing all inputs for test cases

### output#

The output from corresponding input file.

### Hand counts folder

Containing the total number of counts of each hand in the games played..

Some key things to note here however are as follows:
+ Each number is the tally of **Folder Title** number of games
    - *./data/hand_counts/3-players/ten-hands* is the number of each winning hands from a table with 3 players of ten-thousand hands,
    - the file *./data/hand_counts/total-players/ten-hands* is the tally from all ten (number of players in a full table) games of 10,000 hands,

### hist.py

The python responsible for turning the data from the csv into a histogram for the number of winner hands.

### starting_hands.py

Python which calculates the winning percentages for the starting hand -> to be represented as a matrix with different colours to 
represent different percentages.
