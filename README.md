# Get Next Line

## Description
**Get Next Line** is a project where I developed a function that reads and returns a single line from a file descriptor. The function can handle both files and standard input, and it returns each line one at a time when called repeatedly. This project helped me improve my understanding of memory management, file descriptors, and the efficient use of buffers.

I learned how to work with static variables in C, which made it possible to retain values across function calls without using global variables.

## Features
- A function `get_next_line()` that reads a line from a file descriptor.
- The function returns the line, including the newline character if it exists.
- If there is nothing else to read or an error occurs, the function returns `NULL`.
- The function is efficient, reading the file incrementally without storing the entire content in memory at once.

### Example Usage
1. In a loop, calling `get_next_line()` reads the text file pointed to by the file descriptor line by line.
2. When reading from standard input, it behaves like a prompt, returning each line of input.

```c
int fd;
char *line;

fd = open("file.txt", O_RDONLY);
line = get_next_line(fd);
while (line != NULL)
{
    printf("%s", line);
    free(line);
    line = get_next_line(fd);
}
close(fd);
```

## Bonus Features
I also added the following bonuses:
- Manage multiple file descriptors simultaneously, allowing the function to handle multiple files without losing the reading thread for each.
- The function uses only one static variable.

## Installation
1. Clone my repository:
   ```bash
   git clone git@github.com:Rui-Pedro-Pires/Get-Next-Line.git
   ```
2. Navigate to the project directory:
   ```bash
   cd Get Next Line
   ```
3. Compile the project using the provided `Makefile`:
   ```bash
   make
   ```

## Requirements
- C programming language.
- Must use the `read`, `malloc`, and `free` functions. No global variables or the `lseek()` function allowed.
  
## External Functions
The project uses the following external functions:
- `read`, `malloc`, `free`, and custom helper functions.
