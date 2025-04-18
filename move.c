#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <source_file> <destination_file>\n", argv[0]);
        return 1;
    }

    // Rename/move file
    if (rename(argv[1], argv[2]) != 0) {
        perror("Error moving file");
        return 1;
    }

    printf("File moved from %s to %s successfully.\n", argv[1], argv[2]);
    return 0;
}
