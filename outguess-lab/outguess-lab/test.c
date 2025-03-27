#include <stdio.h>
#include <stdlib.h>

int main() {
    if (system("test -f /home/ubuntu/preprocessed.jpg") == 0) {
        printf("YES\n");
    } else {
        printf("Anh khong ton tai\n");
    }
    return 0;
}

