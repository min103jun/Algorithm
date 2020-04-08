//n이커서 c로 scanf로 입력을 다 받음. 그리고 작업양이 많아 비트마스크로 처리했다.
#include <stdio.h>
#include <string.h>
#pragma warning(disable:4996)

int main()
{
    int i, n, num, bit = 0;
    char command[10];

    scanf("%d", &n);
    for(i = 0; i < n; i++) {
        scanf("%s", command);
        if (!strcmp(command, "add")) {
            scanf("%d", &num);
            bit |= (1 << num);
        }
        else if (!strcmp(command, "remove")) {
            scanf("%d", &num);
            bit &= ~(1 << num);
        }
        else if (!strcmp(command, "check")) {
            scanf("%d", &num);
            if (bit & (1 << num))
                printf("1\n");
            else
                printf("0\n");
        }
        else if (!strcmp(command, "toggle")) {
            scanf("%d", &num);
            bit ^= (1 << num);
        }
        else if (!strcmp(command, "all")) {
            bit = (1 << 21) - 1;
        }
        else if (!strcmp(command, "empty")) {
            bit = 0;
        }
    }

    return 0;
}
