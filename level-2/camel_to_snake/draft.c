#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* camel_to_snake(const char* input) {
    if (input == NULL || strlen(input) == 0) {
        return NULL;
    }

    int input_length = strlen(input);
    int output_index = 0;

    for (int i = 0; i < input_length; i++) {
        if (i > 0 && input[i] >= 'A' && input[i] <= 'Z') {
            output[output_index++] = '_';
        }
        output[output_index++] = tolower(input[i]);
    }

    output[output_index] = '\0';
    return output;
}

int main(int argc, char* argv[]) {
    if (argc < 2) {
        printf("Usage: %s <input_string>\n", argv[0]);
        return 1;
    }

    char* input = argv[1];
    char* output = camel_to_snake(input);

    if (output != NULL) {
        printf("%s\n", output);
        free(output);
    }

    return 0;
}