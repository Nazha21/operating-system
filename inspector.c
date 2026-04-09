#include <stdio.h>
#include <sys/stat.h>
#include <stdlib.h>

// Implemented function
void inspect_file(const char* filepath) {
    struct stat file_stat;

    printf("Inspecting: %s\n", filepath);

    // Call stat()
    if (stat(filepath, &file_stat) == -1) {
        printf("Error: File does not exist or cannot be accessed.\n\n");
        return;
    }

    // Print file size
    printf("Size: %lld bytes\n", (long long)file_stat.st_size);

    // Check file type
    if (S_ISDIR(file_stat.st_mode)) {
        printf("Type: Directory\n\n");
    } else if (S_ISREG(file_stat.st_mode)) {
        printf("Type: Regular file\n\n");
    } else {
        printf("Type: Other\n\n");
    }
}

int main() {
    // Create a dummy file for testing
    FILE *f = fopen("test.txt", "w");
    if (f) {
        fputs("Hello File System!", f);
        fclose(f);
    }

    inspect_file("test.txt");
    inspect_file(".");
    inspect_file("does_not_exist.bin");

    return 0;
}