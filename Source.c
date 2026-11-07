#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <locale.h>

int main(void)
{
    setlocale(LC_CTYPE, "RUS");
    char s[500], last1, last2 = 0;
    int i = 0, count = 0, twobyte = 0;
    printf("введите строку: ");
    fgets(s, sizeof(s), stdin);

    while (s[i] != ' ' && s[i] != '\n' && s[i] != '\0') {
        i++;
    }
    if (i == 0) {
        printf("количество слов: 0\n");
        return 0;
    }

    if (i > 1 && strchr(",.;:!?", s[i - 1])) { // strchr это поиск первого символа в строке
        i--;
    }

    if ((unsigned char)s[i - 1] >= 0x80) { // 0x80 это самый первый байт многобайтового (2) символа или число 128 в десятичной системе
        last1 = s[i - 2];
        last2 = s[i - 1];
        twobyte = 1;
    } else {
        last1 = s[i - 1];
    }

    for (i = 0; s[i]; i++) {
        if (i == 0 || s[i - 1] == ' ') {
            if (s[i] == last1 && (!twobyte || s[i + 1] == last2))
                count++;
        }
    }

    printf("количество слов: %d\n", count);
    return 0;
}