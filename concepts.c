// Run this code first. You'll understand what it does.
#include <stdio.h>

int main()
{
    char *concepts[] = {
        "Conditionals", "Loops", "Functions", "Arrays",
        "Pointers", "Strings", "Structures", "Files"
    };
    char response;
    int i;
    for (i = 0; i < 8; i++) {
        printf("Do you understand this concept: %s? y/n?\n", concepts[i]);
        scanf(" %c", &response);
        if (response == 'n') {
            printf("Alright then, study %s\n", concepts[i]);
            break;
        }
    }
	return 0;
}

