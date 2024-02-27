      int mid = (left + right) / 2;
            merge_sort(arr, temp, left, mid, k);
            merge_sort(arr, temp, mid + 1, right, k);
            merge(arr, temp, left, mid, right);