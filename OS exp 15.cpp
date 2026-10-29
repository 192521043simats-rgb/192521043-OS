#include <stdio.h>
#include <string.h>

int main() {
    char user[10][20], file[10][10][20];
    int count[10] = {0}, n = 0, i, u, ch;
    char uname[20], fname[20];

    do {
        printf("\n1.Create user 2.Create file 3.Display 0.Exit: ");
        scanf("%d", &ch);

        if(ch == 1 && n < 10) {
            printf("Username: ");
            scanf("%19s", user[n++]);
        } else if(ch == 2) {
            printf("Username and filename: ");
            scanf("%19s%19s", uname, fname);
            for(u = 0; u < n; u++)
                if(strcmp(user[u], uname) == 0) break;
            if(u < n && count[u] < 10)
                strcpy(file[u][count[u]++], fname);
            else printf("User not found or directory full\n");
        } else if(ch == 3) {
            for(i = 0; i < n; i++) {
                printf("%s:\n", user[i]);
                for(u = 0; u < count[i]; u++)
                    printf("  %s\n", file[i][u]);
            }
        }
    } while(ch != 0);

    return 0;
}