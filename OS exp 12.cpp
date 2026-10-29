#include <stdio.h>
#include <windows.h>

int main() {
    HANDLE f[5];
    int i, left, right;

    for(i = 0; i < 5; i++)
        f[i] = CreateMutex(NULL, FALSE, NULL);

    for(i = 0; i < 5; i++) {
        left = i;
        right = (i + 1) % 5;

        WaitForSingleObject(f[left], INFINITE);
        WaitForSingleObject(f[right], INFINITE);

        printf("Philosopher %d is eating\n", i + 1);

        ReleaseMutex(f[right]);
        ReleaseMutex(f[left]);
    }

    for(i = 0; i < 5; i++)
        CloseHandle(f[i]);

    return 0;
}
