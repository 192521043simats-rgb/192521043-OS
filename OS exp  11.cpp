#include <stdio.h>
#include <windows.h>

DWORD WINAPI task(LPVOID x) {
    printf("Thread is running\n");
    return 0;
}

int main() {
    HANDLE t = CreateThread(NULL, 0, task, NULL, 0, NULL);
    WaitForSingleObject(t, INFINITE);
    CloseHandle(t);
    printf("Main thread completed\n");
    return 0;
}
