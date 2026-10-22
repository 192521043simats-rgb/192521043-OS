#include <stdio.h>
#include <windows.h>

int main() {
    HANDLE src, dest;
    char buffer[100];
    DWORD n;

    src = CreateFile("source.txt", GENERIC_READ, 0, NULL,
                     OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);

    dest = CreateFile("destination.txt", GENERIC_WRITE, 0, NULL,
                      CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL);

    ReadFile(src, buffer, sizeof(buffer), &n, NULL);
    WriteFile(dest, buffer, n, &n, NULL);

    CloseHandle(src);
    CloseHandle(dest);

    printf("File copied successfully.\n");
    return 0;
}
