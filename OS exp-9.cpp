#include <stdio.h>
#include <windows.h>

int main() {
    HANDLE h;
    char *p;

    h = CreateFileMapping(INVALID_HANDLE_VALUE, NULL,
                          PAGE_READWRITE, 0, 100, "SharedMem");

    p = (char*)MapViewOfFile(h, FILE_MAP_ALL_ACCESS, 0, 0, 100);

    printf("Enter message: ");
    gets(p);

    printf("Shared Memory: %s\n", p);

    UnmapViewOfFile(p);
    CloseHandle(h);

    return 0;
}
