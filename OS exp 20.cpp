#include <stdio.h>
#include <windows.h>

int data = 0, readers = 0;
HANDLE mutex, wrt;

int main() {
    mutex = CreateSemaphore(NULL, 1, 1, NULL);
    wrt = CreateSemaphore(NULL, 1, 1, NULL);

    WaitForSingleObject(mutex, INFINITE);
    readers++;
    if(readers == 1)
        WaitForSingleObject(wrt, INFINITE);
    ReleaseSemaphore(mutex, 1, NULL);

    printf("Reader reads: %d\n", data);

    WaitForSingleObject(mutex, INFINITE);
    readers--;
    if(readers == 0)
        ReleaseSemaphore(wrt, 1, NULL);
    ReleaseSemaphore(mutex, 1, NULL);

    WaitForSingleObject(wrt, INFINITE);
    data = 100;
    printf("Writer writes: %d\n", data);
    ReleaseSemaphore(wrt, 1, NULL);

    CloseHandle(mutex);
    CloseHandle(wrt);
    return 0;
}