BASIC specs

lines are of the form

| 1 | 2 | 3 | 4 | etc |
| - | - | - | - | - |
| lineno | lineno | len | cmd | args |

the interpreter fetches a line from program storage then sets the program counter to one more than the fetched line's number.
lines manipulating the program counter do so after the update.

commands:  
  
PRINT - display a message or variable's value on screen / terminal  
GOTO - calculates the value of the expression in the argument field, then sets the program counter to that value  
SET - takes the first argument as a target variable and applies the value of the subsequent expression to that variable  
