# Basic lifetime of a shell
Let’s look at a shell from the top down. A shell does three main things in its lifetime.

**Initialize**: In this step, a typical shell would read and execute its configuration files. These change aspects of the shell’s behavior.

**Interpret**: Next, the shell reads commands from stdin (which could be interactive, or a file) and executes them.

**Terminate**: After its commands are executed, the shell executes any shutdown commands, frees up any memory, and terminates.

```c
int main(int argc, char **argv)
{
	// Load config files, if any.

	// Run command loop.
	read_and_execute_commands();

	// Perform any shutdown/cleanup.

	return EXIT_SUCCESS;
}
```

- **Read**: Read the command from standard input.

- **Parse**: Separate the command string into a program and arguments.

- **Execute**: Run the parsed command.

```c
void read_and_execute_commands(void)
{
	char	*line;
	char	**args;
	int		status;

	while (status)
	{
		printf("> ");
		line = read_user_input();
		args = split_input_into_tokens(line);
		status = execute_command_with_arguments(args);
		free(line);
		free(args);
	}

	// do {
	// printf("> ");
	// line = read_user_input();
	// args = split_input_into_tokens(line);
	// status = execute_command_with_arguments(args);

	// free(line);
	// free(args);
	// } while (status);
}
```

The `read_and_execute_commands()` function in your code is the main loop of a shell program. It does the following:

- Prints a prompt to the user.
- Reads a line of input from the user.
- Splits the line into a program name and arguments.
- Executes the program with the given arguments.
- Frees the memory allocated for the line and the arguments.
- Repeats these steps until `execute_command_with_arguments()` returns a non-true value.

This is a good structure for the main loop of a shell. It reads and executes commands in a loop until an exit condition is met, which is the basic functionality of a shell. The specific implementations of `read_user_input()`, `split_input_into_tokens()`, and `execute_command_with_arguments()` are not shown, but their purposes are clear from their names and usage.

# Reading a line

Reading a line from stdin sounds so simple, but in C it can be a hassle. The sad thing is that you don’t know ahead of time how much text a user will enter into their shell. You can’t simply allocate a block and hope they don’t exceed it. Instead, you need to start with a block, and if they do exceed it, reallocate with more space. This is a common strategy in C, and we’ll use it to implement `read_user_input()`.

The meat of the function is within the (apparently infinite) while (1) loop. In the loop, we read a character (and store it as an int, not a char, that’s important! EOF is an integer, not a character, and if you want to check for it, you need to use an int. This is a common beginner C mistake.). If it’s the newline, or EOF, we null terminate our current string and return it. Otherwise, we add the character to our existing string.

```c
#define INITIAL_BUFFER_SIZE 1024

char *read_user_input(void)
{
	int bufsize = INITIAL_BUFFER_SIZE;
	int position = 0;
	char *buffer = malloc(sizeof(char) * bufsize);
	int c;

	if (!buffer) {
		fprintf(stderr, "read_user_input: memory allocation error\n");
		exit(EXIT_FAILURE);
	}

	while (1) 
	{
		// Read a character
		c = getchar();

		// If we hit EOF, replace it with a null character and return.
		if (c == EOF || c == '\n') {
			buffer[position] = '\0';
			return buffer;
		} else {
			buffer[position] = c;
		}
		position++;

		// If we have exceeded the buffer, reallocate.
		if (position >= bufsize) {
			bufsize += INITIAL_BUFFER_SIZE;
			buffer = realloc(buffer, bufsize);
			if (!buffer) {
				fprintf(stderr, "read_user_input: memory allocation error\n");
				exit(EXIT_FAILURE);
			}
		}
	}
}
```
This function, `read_user_input`, is designed to read a line of input from the user. It does this by calling the `get_next_line` function, which is expected to read a line from standard input (`STDIN_FILENO`) and return it as a dynamically allocated string.

The `get_next_line` function should handle all the details of reading the input, including allocating enough memory for the string, reading the characters one by one until it encounters a newline character or end-of-file, and adding a null character at the end to terminate the string.

The returned string is stored in the `buffer` variable. If `get_next_line` fails to allocate memory for the string (which would cause it to return `NULL`), the `read_user_input` function prints an error message to standard error (`stderr`) and exits the program with a failure status (`EXIT_FAILURE`).

This is a simplified version of the original code, which manually allocated memory for the string and handled reading the characters one by one. By using `get_next_line`, the `read_user_input` function can be much simpler and easier to understand.
```c
char *read_user_input(void)
{
	char	*buffer = get_next_line(STDIN_FILENO);
	
	if (!buffer)
	{
		fprintf(stderr, "read_user_input: memory allocation error\n");
		exit(EXIT_FAILURE);
	}
	return buffer;
}

//char *read_user_input(void)
//{
//	char		*line = NULL;
//	ssize_t		bufsize = 0; // have getline allocate a buffer for us

//	if (getline(&line, &bufsize, stdin) == -1)
//	{
//		if (feof(stdin))
//		{
//			exit(EXIT_SUCCESS);	// We recieved an EOF
//		}
//		else
//		{
//			perror("readline");
//			exit(EXIT_FAILURE);
//		}
//	}
//	return line;
//}
```