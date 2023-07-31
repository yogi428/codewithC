#include <stdio.h>
#include <string.h>

// Function to check if a username already exists in the "users.txt" file
int isUsernameTaken(const char *username) {
    FILE *file = fopen("users.txt", "r");
    if (file == NULL) {
        return 0; // Assume username is not taken if the file doesn't exist
    }

    char storedUsername[50];
    char storedPassword[50];
    while (fscanf(file, "%s %s", storedUsername, storedPassword) == 2) {
        if (strcmp(username, storedUsername) == 0) {
            fclose(file);
            return 1; // Username already taken
        }
    }

    fclose(file);
    return 0; // Username available
}

// Function to save a new user's username and password to the "users.txt" file
int saveUser(const char *username, const char *password) {
    FILE *file = fopen("users.txt", "a");
    if (file == NULL) {
        printf("Error opening users file.\n");
        return 0;
    }

    fprintf(file, "%s %s\n", username, password);
    fclose(file);
    return 1; // User saved successfully
}

// Function to create a file for the new user and store additional information
int createUserFile(const char *username) {
    char filename[100];
    sprintf(filename, "%s.txt", username);

    FILE *file = fopen(filename, "w");
    if (file == NULL) {
        printf("Error creating user file.\n");
        return 0;
    }

    // Add additional information to the file if needed
    // For example: fprintf(file, "Email: user@example.com\n");

    fclose(file);
    return 1; // User file created successfully
}

int main() {
    char username[50];
    char password[50];

    printf("Welcome to the Signup Page!\n");

    // Get username from the user and check if it's available
    while (1) {
        printf("Choose a username: ");
        scanf("%s", username);

        if (isUsernameTaken(username)) {
            printf("Username already taken. Please choose a different username.\n");
        } else {
            break;
        }
    }

    // Get password from the user
    printf("Choose a password: ");
    scanf("%s", password);

    // Save the new user to the "users.txt" file
    if (saveUser(username, password)) {
        printf("Signup successful! Your account has been created.\n");
    } else {
        printf("Error saving user details. Please try again later.\n");
        return 1;
    }

    // Create a file for the new user to store additional information (if needed)
    if (createUserFile(username)) {
        printf("User file created successfully.\n");
    } else {
        printf("Error creating user file. Please try again later.\n");
        return 1;
    }

    return 0;
}
