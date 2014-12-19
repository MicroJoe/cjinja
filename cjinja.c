#include <stdio.h>
#include <stdlib.h>

#include <string.h>

#define IDENT_SIZE     50
#define DELIM_LEFT  '{'
#define DELIM_RIGHT '}'

void parse(char *buf) {
	int i;
	int s1;
	int length;
	char identifier[IDENT_SIZE];

	i = 0;

	while (buf[i] != '\0' && buf[i] != '\n') {

retry:
		/* We find the first delim or EOL/EOF */
		while (buf[i] != DELIM_LEFT && buf[i] != '\n' && buf[i] != '\0') i++;

		/* We try to match the double-delim symbol */
		if (buf[i] != DELIM_LEFT) continue;
		if (buf[++i] != DELIM_LEFT) goto retry;

		/* Parsed `{{`, we remember start position */
		s1 = i + 1;

		/* We find the corresponding delim or EOL/EOF */
		while (buf[i] != DELIM_RIGHT && buf[i] != '\n' && buf[i] != '\0') i++;

		/* We try to match the double-delim ending symbol */
		if (buf[i] != DELIM_RIGHT) continue;
		if (buf[++i] != DELIM_RIGHT) goto retry;

		/* Parsed `{{ident}}`, we save end of identifier position */
		i -= 2;

		/* We are now going to try to strip left whitespaces */
		while (buf[s1] == ' ') s1++;

		/* And then try to strip right whitespaces */
		while (buf[i] == ' ') i--;

		/* We can now compute the length out of the two positions */
		length = i - s1 + 1;

		if (length > IDENT_SIZE) {
			fprintf(stderr,
				"identifier found but its name is too long (max %d).",
				IDENT_SIZE);
			continue;
		}

		/* Extract ident from the buffer */
		strncpy(identifier, buf + s1, length);
		identifier[length] = '\0';

		printf("identifier `%s`\n", identifier);
	}
}

int main(int argc, char **argv) {
	char *line;
	size_t n;

	line = NULL;
	n = 0;

	while (getline(&line, &n, stdin) != -1) {
		parse(line);
	}

	free(line);

	return 0;
}
