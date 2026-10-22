#include <stdio.h>
#include <windows.h>

int main() {
    HANDLE h;
    char msg[100];
    DWORD n;

    h = CreateNamedPipe("\\\\.\\pipe\\MyPipe",
        PIPE_ACCESS_DUPLEX, PIPE_TYPE_MESSAGE |
        PIPE_READMODE_MESSAGE | PIPE_WAIT,
        1, 100, 100, 0, NULL);

    ConnectNamedPipe(h, NULL);

    printf("Enter message: ");
    gets(msg);

    WriteFile(h, msg, sizeof(msg), &n, NULL);
    ReadFile(h, msg, sizeof(msg), &n, NULL);

    printf("Message received: %s\n", msg);

    CloseHandle(h);
    return 0;
}