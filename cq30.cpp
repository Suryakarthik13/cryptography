#include <stdio.h>

int main() {
    char message[] = "X"; // One block message
    char new_message[3];  // Message X || XT
    sprintf(new_message, "%s%s", message, message); // X || XT

    printf("Original message: %s\n", message);
    printf("New message: %s\n", new_message);

    printf("An adversary can calculate the CBC-MAC for the two-block message.\n");

    return 0;
}

