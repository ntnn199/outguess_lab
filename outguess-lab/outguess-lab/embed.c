#include <stdio.h>
#include <stdlib.h>

int compare_files(const char *file1, const char *file2) {
    FILE *fp1 = fopen(file1, "rb");
    FILE *fp2 = fopen(file2, "rb");

    if (fp1 == NULL || fp2 == NULL) {
        printf("NO\n");  // Nếu không mở được file, coi như khác nhau
        return 1;
    }

    int ch1, ch2;
    while (1) {
        ch1 = fgetc(fp1);
        ch2 = fgetc(fp2);

        if (ch1 != ch2) {  // Nếu ký tự khác nhau, file không giống
            printf("NO\n");
            fclose(fp1);
            fclose(fp2);
            return 1;
        }

        if (ch1 == EOF && ch2 == EOF) {  // Nếu cả hai file đều kết thúc cùng lúc
            printf("YES\n");
            fclose(fp1);
            fclose(fp2);
            return 0;
        }

        if (ch1 == EOF || ch2 == EOF) {  // Nếu một file hết mà file kia chưa hết
            printf("NO\n");
            fclose(fp1);
            fclose(fp2);
            return 1;
        }
    }
}

int main() {
    return compare_files("mess.txt", "extracted.txt");
}
