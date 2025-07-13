public class Sort {
    private static void swap(int[] array,int i,int j) {
        int tmp = array[i];
        array[i] = array[j];
        array[j] = tmp;
    }
    public static void insertSort(int[] array){
        for (int i = 0; i < array.length; i++) {
            int tmp = array[i];
            int j = i - 1;
            while (j >= 0) {
                if(array[j] > tmp){
                    array[j + 1] = array[j];
                }else {
                    array[j + 1] = tmp;
                    break;
                }
                j--;
            }
            array[j + 1] = tmp;
        }
    }
    public static void shellSort(int[] array){
        int gap = array.length;
        while(gap > 1){
            gap = gap / 3 + 1;
            shell(array, gap);
        }
    }
    private static void shell(int[] array, int gap) {
        for (int i = 0; i < array.length; i++) {
            int tmp = array[i];
            int j = i - gap;
            while(j >= 0){
                if(array[j] > tmp){
                    array[j + gap] = array[j];
                } else{
                    array[j + gap] = tmp;
                    break;
                }
                j -= gap;
            }
            array[j + gap] = tmp;
        }
    }

}
