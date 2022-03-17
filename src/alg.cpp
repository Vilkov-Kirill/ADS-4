// Copyright 2021 NNTU-CS
int cbinsearch(int *arr, int size, int value) {
    if (size == 1) {
        if (*arr == value) {
            return 1;
        } else {
            return 0;
        }
    } else {
        return cbinsearch(arr, size / 2, value) +
               cbinsearch(arr + size / 2, size / 2 + (size % 2), value);
    }
}

int countPairs1(int* arr, int len, int value) {
    int quan = 0;
    for (int i = 0; i < len-1; i++) {
        for (int k = i+1; k < len; k++) {
            if (*(arr + i) + *(arr + k) == value) {
                quan++;
            }
        }
    }
    return quan;
}

int countPairs2(int* arr, int len, int value) {
    int quan = 0;
    int i = 0;
    int k = 0;
    int s = 0;
    while (i < len) {
        k = 0;
        while (k < len - i - 1) {
            s = *(arr + i) + *(arr + len - k - 1);
            if (s == value) quan++;
            k++;
        }
        i++;
    }
    return quan;
}

int countPairs3(int* arr, int len, int value) {
    int i = 0;
    int quan = 0;
    while (i < len-1) {
        if (*(arr + i) * 2 > value) return quan;
        quan += cbinsearch(arr + i + 1, len - i - 1, value - *(arr + i));
        i++;
    }
    return quan;
}
