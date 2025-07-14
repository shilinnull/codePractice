import javax.swing.plaf.ProgressBarUI;

public class Sort {
    private static void swap(int[] array, int i, int j) {
        int tmp = array[i];
        array[i] = array[j];
        array[j] = tmp;
    }

    public static void insertSort(int[] array) {
        for (int i = 0; i < array.length; i++) {
            int tmp = array[i];
            int j = i - 1;
            while (j >= 0) {
                if (array[j] > tmp) {
                    array[j + 1] = array[j];
                } else {
                    array[j + 1] = tmp;
                    break;
                }
                j--;
            }
            array[j + 1] = tmp;
        }
    }

    public static void shellSort(int[] array) {
        int gap = array.length;
        while (gap > 1) {
            gap = gap / 3 + 1;
            shell(array, gap);
        }
    }

    private static void shell(int[] array, int gap) {
        for (int i = 0; i < array.length; i++) {
            int tmp = array[i];
            int j = i - gap;
            while (j >= 0) {
                if (array[j] > tmp) {
                    array[j + gap] = array[j];
                } else {
                    array[j + gap] = tmp;
                    break;
                }
                j -= gap;
            }
            array[j + gap] = tmp;
        }
    }

    public static void selectSort(int[] array) {
        int left = 0;
        int right = array.length - 1;
        while (left < right) {
            int minIndex = left;
            int maxIndex = left;
            for (int i = left + 1; i <= right; i++) { // 遍历找到小的和大的下标
                if (array[i] < array[minIndex])
                    minIndex = i;
                if (array[i] > array[maxIndex])
                    maxIndex = i;
            }
            swap(array, left, minIndex);
            if (maxIndex == left) {   // 最大的等于第一个
                maxIndex = minIndex;
            }
            swap(array, right, maxIndex);
            left++;
            right--;
        }
    }

    public static void heapSort(int[] array) {
        // 建堆
        for (int parent = (array.length - 1 - 1) / 2; parent >= 0; parent--) {
            siftDown(array, parent, array.length);
        }

        // 排序
        int end = array.length - 1;
        while (end > 0) {
            swap(array, 0, end);
            siftDown(array, 0, end);
            end--;
        }
    }

    private static void siftDown(int[] array, int parent, int length) {
        int child = parent * 2 + 1;
        while (child < length) {
            if (child + 1 < length && array[child + 1] > array[child])
                ++child;
            if (array[child] > array[parent]) { // 大堆
                swap(array, child, parent);
                parent = child;
                child = parent * 2 + 1;
            } else break;
        }
    }

    public static void bubbleSort(int[] array) {
        for (int i = 0; i < array.length - 1; i++) {
            boolean flg = false;
            for (int j = 0; j < array.length - 1 - i; j++) {
                if (array[j] > array[j + 1]) {
                    swap(array, j, j + 1);
                    flg = true;
                }
            }
            if (!flg) {
                break;
            }
        }
    }

    public static void quickSort(int[] array) {
        //quickNor(array,0,array.length-1);
        quick(array, 0, array.length - 1);
    }

    private static void quick(int[] array, int start, int end) {
        if (start >= end) return;

        if (end - start + 1 <= 7) {
            insertSortRange(array, start, end);
            return;
        }

        int midIndex = getMidNum(array, start, end); // 三数取中
        swap(array, start, midIndex);

//        int pivot = partition(array, start, end); // 排序
//        int pivot = partitionHoare(array, start, end);
        int pivot = partitionHoare(array, start, end);
        quick(array, start, pivot - 1);
        quick(array, pivot + 1, end);
    }

    private static int partition(int[] array, int left, int right) {
        int tmp = array[left];
        while (left < right) {
            while (left < right && array[right] >= tmp) {
                right--;
            }
            array[left] = array[right];
            while (left < right && array[left] <= tmp) {
                left++;
            }
            array[right] = array[left];
        }
        array[left] = tmp;
        return left;
    }

    private static int partitionHoare(int[] array, int left, int right) {
        int tmp = array[left];
        int tmpleft = left;
        while (left < right) {
            while (left < right && array[right] >= tmp) {
                right--;
            }
            while (left < right && array[left] <= tmp) {
                left++;
            }
            swap(array, left, right);
        }
        swap(array, left, tmpleft);
        return left;
    }

    public static void mergeSort(int[] array) {
        mergeSortTmp(array, 0, array.length - 1);
    }

    private static void mergeSortTmp(int[] array, int left, int right) {
        if (left >= right) return;
        int mid = (left + right) >>> 1;
        mergeSortTmp(array, left, mid);
        mergeSortTmp(array, mid + 1, right);
        merge(array, left, mid, right);
    }

    private static void merge(int[] array, int left, int mid, int right) {
        int[] tmp = new int[right - left + 1];
        int k = 0;
        int i = left;
        int j = mid + 1;
        while (i <= mid && j <= right) {
            if (array[i] <= array[j]) {
                tmp[k++] = array[i++];
            } else {
                tmp[k++] = array[j++];
            }
        }
        while (i <= mid) {
            tmp[k++] = array[i++];
        }
        while (j <= right) {
            tmp[k++] = array[j++];
        }
        for (int a = 0; a < k; a++) {
            array[a + left] = tmp[a];
        }
    }


    private static int getMidNum(int[] array, int left, int right) {
        int mid = (left + right) >>> 1;
        if (array[left] < array[right]) {
            if (array[mid] < array[left])
                return left;
            else if (array[mid] > array[right])
                return right;
            else return mid;
        } else {
            if (array[mid] > array[left]) {
                return left;
            } else if (array[mid] < array[right]) {
                return right;
            } else {
                return mid;
            }
        }
    }

    private static void insertSortRange(int[] array, int start, int end) {
        for (int i = start + 1; i <= end; i++) {
            int tmp = array[i];
            int j = i - 1;
            for (; j >= start; j--) {
                if (array[j] > tmp) {
                    array[j + 1] = array[j];
                } else {
                    array[j + 1] = tmp;
                    break;
                }
            }
            array[j + 1] = tmp;
        }
    }


}
