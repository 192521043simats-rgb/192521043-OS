#include <stdio.h>
#include <windows.h>

int main() {
    printf("Process ID: %lu\n", GetCurrentProcessId());
    printf("Parent Process ID: Not available directly in Windows\n");

    return 0;
}
