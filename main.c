#include <stdio.h>
#include <stdlib.h>

char* readConsoleLine();
extern int count_spaces(char* str);
extern int * count_words(char * str, int * wordsLength);
extern int * test(char * str, int * wordsLength);

int main() {
    char* input = readConsoleLine();
    int number = count_spaces(input);
    int* wordsLength = (int *) malloc( (number + 1) * sizeof(int));
    //wordsLength[0] = 14;
    int* wd = count_words(input, wordsLength);
    printf("Spaces count in string is %d", wd[0]);

    // Используйте введенные данные по вашему усмотрению

    // Освобождение динамически выделенной памяти после использования
    free(input);

    return 0;
}

char* readConsoleLine() {
    //printf("Input string length:");
    int lengthLen = 6;
    int counter = 0;
    char *strLen = malloc(lengthLen * sizeof(char));
    char c;

    if (strLen == NULL) {
        printf("Memory allocation error\n");
        exit(EXIT_FAILURE);
    }

    printf("Enter string length:");
    while ((c = getchar()) != '\n' && counter < lengthLen - 1) {
        strLen[counter] = c;
        counter++;
    }

    int maxLength = atoi(strLen);
    if (maxLength == 0){
        printf("Unable to read string length\n");
        exit(EXIT_FAILURE);
    }

    free(strLen);
    maxLength++;
    char *str = malloc(maxLength * sizeof(char));
    int length = 0;

    if (str == NULL) {
        printf("Memory allocation error\n");
        exit(EXIT_FAILURE);
    }

    printf("Enter string:");
    while ((c = getchar()) != '\n' && length < maxLength - 1) {
        str[length] = c;
        length++;
    }
    str[length] = '\0';

    printf("Length: %d\nString: %s\n", length, str);

    return str;
}