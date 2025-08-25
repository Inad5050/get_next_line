<h1 align="center">School 42 Get Next Line</h1>

This repository contains my implementation of the get_next_line project from the 42 cursus. The goal is to create a function that returns a line read from a file descriptor.

<h2 align="center">
    <a href="#about">About</a>
    <span> · </span>
    <a href="#structure">Structure</a>
    <span> · </span>
<a href="#bonus">Bonus</a>
    <span> · </span>
    <a href="#requirements">Requirements</a>
    <span> · </span>
    <a href="#instructions">Instructions</a>
</h2>

## About

This project is about programming a function that returns a line ending with a newline character (\n) from a file descriptor. When called in a loop, get_next_line allows you to read the entire content of the file, one line at a time.

A key concept in this project is the use of static variables to keep track of the data read across multiple function calls.

You can find more details in the official project subject.

## Structure

The main challenge is to read from the file descriptor only when necessary and to store any "excess" data that belongs to the next line.

The program flow is as follows:

  * A static variable (line) is used to store data that has been read from the file but not yet returned. This variable persists between calls to get_next_line.

  * The function first checks if the static variable already contains a full line (i.e., a newline character).

  * If not, it enters a loop that calls read() to get more data from the file descriptor, appending it to the static variable until a newline is found or the end of the file is reached.

  * Once a line is complete, it is extracted from the static variable. The remaining data (the "excess") is kept in the static variable for the next function call.

  * The extracted line, including the newline character, is returned.
    
## Bonus

The bonus part of the project requires get_next_line to handle multiple file descriptors at the same time without losing the reading progress of any of them.

  * To achieve this, instead of a single static variable, an array of static character pointers is used (static char *line[4096]).

  * The file descriptor (fd) serves as the index for this array. This way, each file descriptor has its own persistent storage for leftover characters, allowing the function to switch between files seamlessly.

## Requirements

To compile and use this function, you will need:

  * A C compiler, such as gcc.

  * The standard libraries <unistd.h> (for read), <stdlib.h> (for malloc and free), and <fcntl.h> (for open).

## Instructions
#### 1. Compile the project

To compile the files, navigate to the project directory and run the following command. The -D BUFFER_SIZE=n flag sets the size of the reading buffer.

`$ gcc -Wall -Wextra -Werror -D BUFFER_SIZE=42 get_next_line.c get_next_line_utils.c main.c -o gnl`

To compile the bonus version:

`$ gcc -Wall -Wextra -Werror -D BUFFER_SIZE=42 get_next_line_bonus.c get_next_line_utils_bonus.c main_bonus.c -o gnl_bonus`

#### 2. Use in your code

To use get_next_line in your own project, include the get_next_line.h header. The function reads from a file descriptor line by line until it reaches the end.

```
#include "get_next_line.h"
#include <fcntl.h> // For open()
#include <stdio.h> // For printf()

int main(void)
{
    int     fd;
    char    *line;

    fd = open("your_file.txt", O_RDONLY);
    if (fd == -1)
        return (1);
    while ((line = get_next_line(fd)))
    {
        printf("%s", line);
        free(line);
    }
    close(fd);
    return (0);
}
```

