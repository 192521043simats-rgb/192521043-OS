#include <stdio.h>
#include <windows.h>

HANDLE mutex;

DWORD WINAPI task(LPVOID x) {
    WaitForSingleObject(mutex, INFINITE);
    printf("Critical section: Thread %d\n", *(int*)x);
    ReleaseMutex(mutex);
    return 0;
}

int main() {
    HANDLE t[2];
    int a = 1, b = 2;

    mutex = CreateMutex(NULL, FALSE, NULL);

    t[0] = CreateThread(NULL, 0, task, &a, 0, NULL);
    t[1] = CreateThread(NULL, 0, task, &b, 0, NULL);

    WaitForMultipleObjects(2, t, TRUE, INFINITE);

    CloseHandle(t[0]);
    CloseHandle(t[1]);
    CloseHandle(mutex);
    return 0;
}