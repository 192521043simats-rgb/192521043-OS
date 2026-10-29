#include <stdio.h>
#include <windows.h>

int main() {
    HANDLE empty, full, mutex;
    int item = 0;

    empty = CreateSemaphore(NULL, 1, 1, NULL);
    full = CreateSemaphore(NULL, 0, 1, NULL);
    mutex = CreateMutex(NULL, FALSE, NULL);

    WaitForSingleObject(empty, INFINITE);
    WaitForSingleObject(mutex, INFINITE);
    item = 10;
    printf("Produced: %d\n", item);
    ReleaseMutex(mutex);
    ReleaseSemaphore(full, 1, NULL);

    WaitForSingleObject(full, INFINITE);
    WaitForSingleObject(mutex, INFINITE);
    printf("Consumed: %d\n", item);
    ReleaseMutex(mutex);
    ReleaseSemaphore(empty, 1, NULL);

    CloseHandle(empty);
    CloseHandle(full);
    CloseHandle(mutex);
    return 0;
}