#include <stdio.h>
#include <stdlib.h>

#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    FILE *srcFile, *destFile;
    char buffer[BUFFER_SIZE];
    size_t bytesRead;

    // Check for correct number of arguments
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <source_file> <destination_file>\n", argv[0]);
        return 1;
    }

    // Open source file in read mode
    srcFile = fopen(argv[1], "rb");
    if (srcFile == NULL) {
        perror("Error opening source file");
        return 1;
    }

    // Open destination file in write mode
    destFile = fopen(argv[2], "wb");
    if (destFile == NULL) {
        perror("Error opening destination file");
        fclose(srcFile);
        return 1;
    }

    // Copy contents from source to destination
    while ((bytesRead = fread(buffer, 1, BUFFER_SIZE, srcFile)) > 0) {
        fwrite(buffer, 1, bytesRead, destFile);
    }

    printf("File copied successfully!\n");

    // Close files
    fclose(srcFile);
    fclose(destFile);

    return 0;
}
