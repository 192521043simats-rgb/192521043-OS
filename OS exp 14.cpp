#include <stdio.h>
#include <string.h>

int main() {
    char files[20][20], name[20];
    int n = 0, ch, i, found;

    do {
        printf("\n1.Create 2.Search 3.Display 0.Exit: ");
        scanf("%d", &ch);

        if(ch == 1) {
            printf("Enter filename: ");
            scanf("%19s", files[n++]);
        } else if(ch == 2) {
            printf("Enter filename: ");
            scanf("%19s", name);
            found = 0;
            for(i = 0; i < n; i++)
                if(strcmp(files[i], name) == 0) found = 1;
            printf(found ? "Found\n" : "Not found\n");
        } else if(ch == 3) {
            for(i = 0; i < n; i++) printf("%s\n", files[i]);
        }
    } while(ch != 0 && n < 20);

    return 0;
}
