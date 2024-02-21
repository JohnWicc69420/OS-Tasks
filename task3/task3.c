#include <stdio.h>
#include <stdlib.h>

int main (int argc, char *argv[]) {
if (argc < 2) {
printf("Error: No file name entered\n");
return 1;
}

char *filename = argv[1];
FILE *file = fopen(filename, "r");
if (file == NULL) {
printf("Error: Unable to open file %s\n", filename);
return 1;
}

// Reading the file
char line[100];
while (fgets(line, sizeof(line), file) != NULL){
printf("%s", line);
}
fclose(file);

//Open file for writing
file = fopen(filename, "a");
if (file == NULL) {
printf("Error: Unable to open file %s for writing\n", filename );
return 1;
}

fprintf(file, "Adding new line to file\n");
fclose(file);
return 0;
}
