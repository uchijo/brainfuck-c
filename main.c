#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "engine.h"

char* read_file(const char* filename) {
    FILE* file = fopen(filename, "rb");  // ファイルをバイナリモードで開く
    if (file == NULL) {
        perror("ファイルが開けません");
        return NULL;
    }

    // ファイルのサイズを取得
    fseek(file, 0, SEEK_END);
    long filesize = ftell(file);
    fseek(file, 0, SEEK_SET);

    // 必要なメモリを確保
    char* buffer = (char*)malloc(filesize + 1);
    if (buffer == NULL) {
        perror("メモリ確保に失敗しました");
        fclose(file);
        return NULL;
    }

    // ファイルの内容を読み取る
    fread(buffer, 1, filesize, file);
    buffer[filesize] = '\0';  // NULL文字を追加

    fclose(file);   // ファイルを閉じる
    return buffer;  // ファイルの内容を含むバッファを返す
}

char* parse(char* input) {
    size_t input_len = strlen(input);
    char* retval = malloc(input_len * sizeof(char));
    int current_index = 0;
    for (int i = 0; i < input_len; i++) {
        if (input[i] == '<' || input[i] == '>' || input[i] == '.' ||
            input[i] == ',' || input[i] == '+' || input[i] == '-' ||
            input[i] == '[' || input[i] == ']') {
            retval[current_index++] = input[i];
        }
    }
    retval[current_index] = '\0';
    return retval;
}

int main(int argc, char* argv[]) {
    if (argc < 2) {
        printf("expected to have 1 argument, but got %d\n", argc - 1);
        return 1;
    }
    char* file_content = read_file(argv[1]);
    char* parsed = parse(file_content);
    printf("parsed program: %s\n", parsed);
    Engine* engine = create_engine(parsed, 10000000000);
    eval(engine);
    return 0;
}
