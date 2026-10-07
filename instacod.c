#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct Account {
    char name[50];
    char username[50];
    char password[50];
};

struct Account currentAccount;
int isLoggedIn = 0;

void showLogin();
void showSignup();
void openApp();
void showHome();

void showSignup() {
    char name[50], username[50], password[50];
    printf("\n=== Create Demo Account ===\n");
    printf("Your name: ");
    scanf("%49s", name);
    printf("Choose username: ");
    scanf("%49s", username);
    printf("Choose password: ");
    scanf("%49s", password);

    strcpy(currentAccount.name, name);
    strcpy(currentAccount.username, username);
    strcpy(currentAccount.password, password);

    printf("Demo account created successfully!\n");
    showLogin();
}

void showLogin() {
    char username[50], password[50];
    printf("\n=== Demo Login ===\n");
    printf("Username: ");
    scanf("%49s", username);
    printf("Password: ");
    scanf("%49s", password);

    if (strcmp(username, currentAccount.username) == 0 && 
        strcmp(password, currentAccount.password) == 0) {
        isLoggedIn = 1;
        openApp();
    } else {
        printf("Wrong demo username or password. Try again.\n");
        showLogin();
    }
}

void showHome() {
    int choice;
    while (isLoggedIn) {
        printf("\n--- PhotoShare Home ---\n");
        printf("1. View Stories (Rahul, Priya, Aman)\n");
        printf("2. View Posts (rahul_demo, priya_demo)\n");
        printf("3. Profile (%s - %s)\n", currentAccount.username, currentAccount.name);\n");
        printf("4. Messages\n");
        printf("5. Log Out\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("\nStories: [😊 Your Story] [😎 Rahul] [🌸 Priya] [🔥 Aman]\n");
                break;
            case 2:
                printf("\nPost 1 by rahul_demo: 🌄 'Beautiful day!'(0 likes)\n");
                printf("Post 2 by priya_demo: 🌆 'City vibes ✨' (0 likes)\n");
                break;
            case 3:
                printf("\nProfile: %s (%s) | Posts: 2 | Followers: 250 | Following: 180\n", 
                       currentAccount.username, currentAccount.name);
                break;
            case 4:
                printf("\n💬 This is a demo messaging section.\n");
                break;
            case 5:
                isLoggedIn = 0;
                printf("Logged out.\n");
                showLogin();
                return;
            default:
                printf("Invalid choice.\n");
        }
    }
}

void openApp() {
    printf("\nWelcome to PhotoShare, %s!\n", currentAccount.name);
    showHome();
}

int main() {
    // Default demo account setup
    strcpy(currentAccount.name, "Student Demo");
    strcpy(currentAccount.username, "student_demo");
    strcpy(currentAccount.password, "1234");

    printf("Default demo credentials -> Username: student_demo | Password: 1234\n");
    
    int option;
    printf("1. Log In\n2. Create Demo Account\nChoose option: ");
    scanf("%d", &option);

    if (option == 2) {
        showSignup();
    } else {
        showLogin();
    }

    return 0;
}
    