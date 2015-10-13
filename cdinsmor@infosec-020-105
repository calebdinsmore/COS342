#include <stdio.h>
#include <string.h>
#include <unistd.h>

int nameInList(char name[10], char list[20][20]) {
  for (int i = 0; i < 20; i++) {
    if (strcmp(list[i], name) == 0) {
      return 1;
    }
  }
  return 0;
}

int main(int argc, char **argv) {
  char studentNames[20][20];
  char nameToRemove[10];
  int menuChoice;

  char username[10];
  char password[10];
  int authentic = 0;

  while (!authentic) {
    printf("%s", "Username: ");
    scanf("%s", username);
    printf("%s", "Password: ");
    scanf("%s", password);

    if (strcmp(username, "admin") != 0 || strcmp(password, "admin") != 0) {
      printf("%s\n", "Wrong admin credentials.");
    }
    else {
      authentic = 1;
    }
  }

  int lastNameIndex = -1;

  seteuid(0);

  FILE * in_file;

  in_file = fopen("students.txt", "r");

  int c;
  int listIdx = 0;

  while ((c =fgetc(in_file)) != EOF) {
    char name[20];
    int idx = 0;
    while (c != '\n' && c != EOF) {
      name[idx] = c;
      idx++;
      c = fgetc(in_file);
    }
    name[idx++] = '\0';
    printf("%s\n", name);
    strcpy(studentNames[listIdx], strcat(name, "\0"));
    lastNameIndex++;
    listIdx++;
  }

  while (menuChoice != '0') {

    printf("%s", "\n___DINSMORE SCHOLARSHIP - MANAGEMENT___ \nMenu:\n1: Add a student\n2: Remove a student\n3: Print students\n0: Exit\n\nChoice: ");
    menuChoice = getchar();

    if (menuChoice == '\n') menuChoice = getchar();

    if (menuChoice > '/' && menuChoice < '4') {
      if (menuChoice == '1') {
        printf("%s", "Student name: ");
        scanf("%s", studentNames[lastNameIndex + 1]);
        lastNameIndex++;
      }
      else if (menuChoice == '2') {
        printf("%s", "Enter name to remove: ");
        scanf("%s", nameToRemove);
        while (!nameInList(nameToRemove, studentNames)) {
          printf("%s\n", "Name not found. Try again (or q to quit): ");
          scanf("%s", nameToRemove);
          if (strcmp(nameToRemove, "q") == 0)
            break;
          else {
            if (nameInList(nameToRemove, studentNames)) {
              for (int i = 0; i < 20; i++) {
                if (strcmp(nameToRemove, studentNames[i]) == 0) {
                  strcpy(studentNames[i], "EMPTYSLOT");
                }
              }
            }
          }
        }
      }
      else if (menuChoice == '3') {
        printf("%s\n", "\nSTUDENTS IN LINE TO RECEIVE SCHOLARSHIP:");
        for (int i = 0; i <= lastNameIndex; i++) {
          printf(studentNames[i]);
          printf("\n");
        }
      }
    }
  }
  //menuChoice = 0 here
  fclose(in_file);
  FILE* out_file;

  out_file = fopen("students.txt", "w");

  for(int i = 0; i <= lastNameIndex; i++) {
    fprintf(out_file, "%s\n", studentNames[i]);
  }
  fclose(out_file);
}
