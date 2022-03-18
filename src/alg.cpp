// Copyright 2021 NNTU-CS
int binarySearch(int arr[], int b, int e, int num) {
    if (b <= e) {
        int mid = (b + e) / 2;
        if (arr[mid] == num) {
            int i = 1;
            int quan = 1;
            while (arr[mid - i] == num && mid - i >= 0) { i++; quan++; }
            i = 1;
            while (arr[mid + i] == num) { i++; quan++; }
            return quan;
        }
        if (arr[mid] > num)
            return binarySearch(arr, b, mid - 1, num);
        if (arr[mid] < num)
            return binarySearch(arr, mid + 1, e, num);
    }
    return 0;
}

int countPairs1(int* arr, int len, int value) {
    int quan = 0;
    for (int i = 0; i < len - 1; i++) {
        for (int k = i + 1; k < len; k++) {
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
        k = 1;
        while (k < len - 1) {
            s = *(arr + i) + *(arr + i + k);
            if (s > value) break;
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
    int s, s2;
    while (i < len) {
        if (*(arr + i) + *(arr + i + 1) > value) return quan;
        s = binarySearch(arr + i + 1, 0, len - i - 2, value - *(arr+i));
        quan += s;
        i++;
    }
    return quan;
}
