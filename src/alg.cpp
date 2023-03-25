int cbinsearch(int* arr, int size, int value) {
    int left = 0;
    int right = size;
    int count = 0;
    while (left <= right) {
        int middle = (left + right) / 2;
        if (arr[middle] == value) {
            count++;
            while (arr[--middle] == value) count++;
            middle += count;
            while (arr[++middle] == value) count++;
            return count;
        }
        else if (arr[middle] < value) {
            left = middle + 1;
        }
        else {
            right = middle - 1;
        }
    }
    return 0;
}
int countPairs1(int* arr, int len, int value) {
    int count = 0;
    for (int i = 0; i < len - 1; i++) {
        for (int j = i + 1; j < len; j++) {
            if (arr[i] + arr[j] == value) {
                count++;
            }
        }
    }
    return count;
}
int countPairs2(int* arr, int len, int value) {
    int count = 0;
    int end = len - 1;
    while (arr[end] > value) {
        end--;
    }
    for (int i = 0; i < end; i++) {
        for (int j = end; i < j; j--) {
            if (arr[i] + arr[j] == value) {
                count++;
            }
        }
    }
    return count;
}
int countPairs3(int* arr, int len, int value) {
    int count = 0;
    for (int i = 0; i < len - 1 && arr[i] <= value; i++) {
		count += cbinsearch(arr + i + 1, len - i - 1, value - arr[i]);
	}
    return count;
}
