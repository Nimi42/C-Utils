# Multiline print

A simple module that I wrote to learn something about C. It takes multiple paragraphs and prints them in parallel. The delimiter for the paragraphs does not have to be a newline character. Null checks for user inputs are missing.

## Usage

Use ```append_column(char *seq, char delim)``` to append a string. It will be tokenised using the delimiter. Each token will be placed in a new line. Using append again will append another string which will be printed next to. Once a line is full, you can use ```flush()``` to print your strings. Strings have to
be ```NULL``` terminated and each ```append_column()``` has to be followed by a ```flush()``` or the dynamically allocated memory won't be free'd.