#include "multiline.h"

struct Lines {
	unsigned count;
	struct Column *head;
	struct Column *toe;
};

struct Column {
	unsigned count;
	unsigned lines;
	char **content;
	struct Column *next;
};

static struct Lines *lines = NULL;

static const char ARROW_BLANK[8] = "       ";
static const char ARROW[8] = "  -->  ";

static struct Column * new_column(unsigned num_lines, unsigned num_chars) {
	struct Column *col = malloc(sizeof(struct Column));
	char **content = malloc(num_lines * sizeof(char *));
	col->content = content;
	col->count = num_chars;
	col->next = NULL;

	return col;
}

static void free_lines(void) {
	struct Column *head = lines->head;
	struct Column *tmp;
	while (head != NULL) {
		tmp = head;
		head = head->next;
		for (int i = 0; i < tmp->lines; ++i) {
			free(tmp->content[i]);
		}
		free(tmp->content);
		free(tmp);
	}
	free(lines);
	lines = NULL;
}

static struct Column * to_column(char *block, char delim) {
	char c;
	int i, j;
	unsigned num_chars = 0, num_lines = 0;

	j = 0;
	
	c = 1;
	for (i = 0; c; ++i) {
		c = block[i];
		if (c == delim || c == '\0') {
			if (j > num_chars)
				num_chars = j;
			j = 0;
			++num_lines;
		} else {
			++j;
		} 
	}

	struct Column *col = new_column(num_lines, num_chars);
	char *seq;

	col->lines = num_lines;	

	c = *block++;
	for (i = 0; i < num_lines; ++i) {
		seq = malloc((num_chars + 1) * sizeof(char));
		for (j = 0; j < num_chars; ++j) {
			if (c == delim || c == '\0') {
				seq[j] = ' ';
			} else {
				seq[j] = c;
				c = *block++;
			}
		}
		c = *block++;
		seq[j] = '\0';
		col->content[i] = seq;
	}

	return col;
}

void append_column(char *seq, char delim) {
	if (lines == NULL) {
		lines = malloc(sizeof(struct Lines));

		struct Column *col =to_column(seq, delim);
		lines->count = col->lines;
		lines->head = col;
		lines->toe = lines->head;
	} else {
		struct Column *col = to_column(seq, delim);
		if (lines->count < col->lines) {
			lines->count = col->lines;
		}
		lines->toe->next = col;
		lines->toe = col;
	}
}

void flush(void) {
	if (lines != NULL) {
		struct Column *head;
		unsigned half = (lines->count / 2) + ((lines->count % 2) - 1);


		for (unsigned i = 0; i < lines->count; ++i) {
			head = lines->head;
			if (head->lines > i) {
				printf("%s", head->content[i]);
			} else {
				char tmp[head->count + 1];
				memset(tmp, ' ', head->count);
				tmp[head->count] = '\0';
				printf("%s", tmp);
			}
			head = head->next;

			while(head != NULL) {
				if (i == half) {
					printf("%s", ARROW);
				} else {
					printf("%s", ARROW_BLANK);
				}

				if (head->lines > i) {
					printf("%s", head->content[i]);
				} else {
					char tmp[head->count + 1];
					memset(tmp, ' ', head->count);
					tmp[head->count] = '\0';
					printf("%s", tmp);
				}
				head = head->next;
			}

			printf("\n");
		}

		free_lines();
	}	
}