for (int i = 0; i < precise_count - 1; i++) {
    for (int j = 0; j < precise_count - i - 1; j++) {
        if (strcmp(words[j].str, words[j + 1].str) > 0) {
            word tmp = words[j];
            words[j] = words[j + 1];
            words[j + 1] = tmp;
        }
    }
}
