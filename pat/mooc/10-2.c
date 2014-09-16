#include <stdio.h>
#include <string.h>

int main() {
	char s1[85], s2[85], *p;
	fgets(s1, 85, stdin);
	fgets(s2, 85, stdin);
	int l1 = strlen(s1);
	int l2 = strlen(s2);
	s1[--l1] = '\0';
	s2[--l2] = '\0';
	while (p = strstr(s1, s2)) {
		char *s = p, *t = p + l2;
		while (*s++ = *t++);
	}
	printf("%s\n", s1);
	return 0;
}
