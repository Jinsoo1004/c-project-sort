#include <stdio.h>
#include <windows.h>
#include <stdlib.h>

void swap(int *, int *);

void bubbleSort(int[], int);

void merge(int a[], int start, int middle, int end);

void mergeSort(int a[], int start, int end);


// ¹è¿­ Ãâ·Â ÇÔ¼ö
void printArr(int value[], int n) {
    for (int i = 0; i < n; i++)
        printf("%d ", value[i]);
    printf("\n");
}

// ¼±ÅÃ Á¤·Ä ½ÇÇà ÇÔ¼ö
void selectionSort(int *value, int n) {
    int i, j;
    int min = 0;
    int temp1 = 0; // swap¿¡ ¾²±â À§ÇÑ º¯¼ö (ÀÓ½Ã)

    // i for¹® :
    for (i = 0; i < n - 1; i++) {
        min = i; // ÀÎµ¦½º
        for (j = i + 1; j < n; j++) {
            if (value[min] > value[j])
                min = j;
        }

        // °Ë»çÇÑ °ªÁß °¡Àå ÀÛÀº °ª°ú value[i]°ª swap °úÁ¤.
        temp1 = value[i];
        value[i] = value[min];
        value[min] = temp1;
    }
}
// ¼±ÅÃÁ¤·Ä ¿©±â±îÁö


// »ğÀÔ Á¤·Ä
void insertion_sort(int list[], int n) {
    int i, j, key;

    // ÀÎÅØ½º 0Àº ÀÌ¹Ì Á¤·ÄµÈ °ÍÀ¸·Î º¼ ¼ö ÀÖ´Ù.
    for (i = 1; i < n; i++) {
        key = list[i]; // ÇöÀç »ğÀÔµÉ ¼ıÀÚÀÎ i¹øÂ° Á¤¼ö¸¦ key º¯¼ö·Î º¹»ç

        // ÇöÀç Á¤·ÄµÈ ¹è¿­Àº i-1±îÁöÀÌ¹Ç·Î i-1¹øÂ°ºÎÅÍ ¿ª¼øÀ¸·Î Á¶»çÇÑ´Ù.
        // j °ªÀº À½¼ö°¡ ¾Æ´Ï¾î¾ß µÇ°í
        // key °ªº¸´Ù Á¤·ÄµÈ ¹è¿­¿¡ ÀÖ´Â °ªÀÌ Å©¸é j¹øÂ°¸¦ j+1¹øÂ°·Î ÀÌµ¿
        for (j = i - 1; j >= 0 && list[j] > key; j--) {
            list[j + 1] = list[j]; // ·¹ÄÚµåÀÇ ¿À¸¥ÂÊÀ¸·Î ÀÌµ¿
        }

        list[j + 1] = key;
    }
}
//»ğÀÔÁ¤·Ä ¿©±â±îÁö

//¹öºíÁ¤·Ä ½ÇÇÜÇÔ¼ö
void swap(int *num1, int *num2) {            // ¼­·Î ±³È¯ÇØÁÖ´Â ÇÔ¼ö
    int temp;
    temp = *num2;
    *num2 = *num1;
    *num1 = temp;
}

void bubbleSort(int arr[], int size) {               // ¹öºíÁ¤·ÄÇÏ´Â ÇÔ¼ö
    int i, j;
    for (j = 0; j < size - 1; j++) {
//        printArr(arr, size);                       // ¹è¿­À» È­¸é¿¡ Ãâ·ÂÇÏ´Â ÇÔ¼ö
        for (i = 0; i < size - j - 1; i++) {
            if (arr[i] > arr[i + 1]) {
                swap(&arr[i], &arr[i + 1]);     // ¼­·Î ±³È¯ÇØÁÖ´Â ÇÔ¼ö
            }
        }
    }
//    printf("\n");
}
//¹öºíÁ¤·Ä ¿©±â±îÁö ¤¿¤¤¤±¤±

//ÄüÁ¤·Ä ÇÔ¼ö
void quick_sort(int *data, int start, int end) {
    if (start >= end) {
        // ¿ø¼Ò°¡ 1°³ÀÎ °æ¿ì
        return;
    }

    int pivot = start;
    int i = pivot + 1; // ¿ŞÂÊ Ãâ¹ß ÁöÁ¡
    int j = end; // ¿À¸¥ÂÊ Ãâ¹ß ÁöÁ¡
    int temp;

    while (i <= j) {
        // Æ÷ÀÎÅÍ°¡ ¾ù°¥¸±¶§±îÁö ¹İº¹
        while (i <= end && data[i] <= data[pivot]) {
            i++;
        }
        while (j > start && data[j] >= data[pivot]) {
            j--;
        }

        if (i > j) {
            // ¾ù°¥¸²
            temp = data[j];
            data[j] = data[pivot];
            data[pivot] = temp;
        } else {
            // i¹øÂ°¿Í j¹øÂ°¸¦ ½º¿Ò
            temp = data[i];
            data[i] = data[j];
            data[j] = temp;
        }
    }

    // ºĞÇÒ °è»ê
    quick_sort(data, start, j - 1);
    quick_sort(data, j + 1, end);
}
//ÄüÁ¤·Ä ¿©±â±îÁö

//ÇÕº´Á¤·Ä ÇÔ¼ö
int sorted[25];

void merge(int a[], int start, int middle, int end) {

    int i, j, k; //°¢°¢ start middle middle+1 ¿¡ ÇØ´ç
    i = start;
    j = middle + 1;
    k = start;

    // 3°¡ÁöÀÇ °æ¿ìÁß¿¡ ±³Â÷µÇ´Â °æ¿ì¸ÕÀúµûÁ®º¸ÀÚ
    while (i <= middle && j <= end) {


        if (a[i] <= a[j]) {
            sorted[k] = a[i];
            i++;
        } else { //±× ¹İ´ëÀÇ °æ¿ì¶ó¸é
            sorted[k] = a[j];
            j++;
        }
        k++;//Á¤·Ä¹è¿­ÀÇ ´ÙÀ½ Ä­¿¡ ´ã¾Æ¾ß ÇÏ¹Ç·Î
    }

    //±³Â÷µÇ´Â °æ¿ì°¡ ¾Æ´Ï¶ó Æ¯Á¤ ÇÏ³ª°¡ ¸ÕÀú Ã¤¿öÁø´Ù¸é?
    if (i > middle) {// i°¡ ¸ÕÀúÃ¤¿öÁ³±â¶§¹®¿¡ middleº¸´Ù Ä¿Áø°Í
        for (int t = j; t <= end; t++) {
            sorted[k] = a[t];
            k++;
        }
    } else { // j°¡ ¸ÕÀúÃ¤¿öÁ³±â¶§¹®¿¡
        for (int t = i; t <= middle; t++) {
            sorted[k] = a[t];
            k++;
        }
    }
    //Á¤·ÄµÈ ¹è¿­À» »ğÀÔ

    for (int t = start; t <= end; t++) {
        a[t] = sorted[t];
    }
}

void mergeSort(int a[], int start, int end) {

    if (start < end) {
        int middle;
        middle = (start + end) / 2;
        mergeSort(a, start, middle);
        mergeSort(a, middle + 1, end);//°è¼Ó ºĞÇÒ
        merge(a, start, middle, end);

    }
}
//ÇÕº´Á¤·Ä ¿©±â±îÂî

//ÈüÁ¤·Ä ÇÔ¼ö
//heapify, Èü »óÅÂ ¸¸µé±â
void heapify(int *arr, int size){
    for(int i=1;i<size;++i){
        int child = i;
        do{
            //ÀÚ½Ä ³ëµå°¡ ºÎ¸ğ ³ëµåº¸´Ù Å©¸é ±³È¯
            int root = (child-1)/2;
            if(arr[root]<arr[child]){
                int temp = arr[root];
                arr[root] = arr[child];
                arr[child] = temp;
            }
            child = root;
        }while(child!=0);	//ÃÖ»ó´Ü ³ëµå±îÁö Á¡°Ë
    }
}

//ÃÖ»ó´Ü ³ëµå¿Í ÃÖÇÏ´Ü ³ëµå ±³Ã¼
void heap(int *arr, int *size){
    int temp = arr[0];
    arr[0] = arr[*size-1];
    arr[*size-1] = temp;
    --(*size);
}

int main() {
    system("mode con cols=150 lines=30");
    //cols = Ä­/Çà (°¡·Î)  lines = ÁÙ/¿­ (¼¼·Î)
    a:
    printf("¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à\n"
           "¡à¡à¡á¡á¡á¡á¡á¡á¡à¡á¡à¡à¡à¡á¡á¡á¡á¡á¡à¡à¡á¡à¡à¡à¡à¡á¡á¡á¡á¡á¡á¡á¡à¡à¡à¡à¡á¡á¡á¡á¡á¡á¡á¡à¡à¡à¡à¡á¡á¡á¡á¡á¡á¡á¡à¡à¡à¡á¡á¡á¡á¡à¡á¡à¡á¡à¡à\n"
           "¡à¡à¡à¡à¡á¡à¡à¡à¡à¡á¡à¡à¡à¡à¡à¡à¡à¡á¡á¡á¡á¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡á¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡á¡à¡à¡à¡à¡à¡à¡á¡à¡á¡à¡á¡à¡à\n"
           "¡à¡à¡à¡à¡á¡á¡à¡á¡á¡á¡à¡à¡à¡á¡á¡á¡á¡á¡à¡à¡á¡à¡à¡à¡à¡à¡á¡à¡à¡à¡á¡à¡à¡à¡à¡à¡á¡á¡á¡á¡á¡á¡á¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡á¡à¡à¡à¡á¡á¡á¡á¡à¡á¡á¡á¡à¡à\n"
           "¡à¡à¡à¡á¡à¡à¡á¡à¡à¡á¡à¡à¡à¡á¡à¡à¡à¡à¡á¡á¡á¡à¡à¡à¡à¡à¡á¡à¡à¡à¡á¡à¡à¡à¡à¡à¡á¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡á¡à¡à¡à¡á¡à¡à¡à¡à¡á¡à¡á¡à¡à\n"
           "¡à¡à¡á¡à¡à¡à¡à¡á¡à¡á¡à¡à¡à¡á¡á¡á¡á¡á¡á¡à¡á¡à¡à¡à¡à¡à¡á¡à¡à¡à¡á¡à¡à¡à¡à¡à¡á¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡á¡à¡à¡à¡á¡à¡à¡à¡à¡á¡à¡á¡à¡à\n"
           "¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡á¡à¡à¡à¡à¡á¡á¡á¡á¡á¡á¡á¡à¡à¡à¡à¡á¡á¡á¡á¡á¡á¡á¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡á¡à¡à¡à¡á¡á¡á¡á¡à¡á¡à¡á¡à¡à\n"
           "¡à¡à¡à¡à¡á¡á¡á¡á¡á¡à¡à¡à¡à¡à¡á¡á¡á¡á¡á¡á¡á¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡á¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡á¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à\n"
           "¡à¡à¡à¡á¡à¡à¡à¡à¡à¡á¡à¡à¡à¡à¡à¡à¡à¡à¡á¡á¡á¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡á¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡á¡à¡à¡à¡à¡à¡á¡á¡á¡á¡á¡á¡á¡à¡à\n"
           "¡à¡à¡à¡á¡à¡à¡à¡à¡à¡á¡à¡à¡à¡à¡á¡á¡á¡à¡à¡à¡à¡à¡à¡à¡á¡á¡á¡á¡á¡á¡á¡á¡á¡à¡à¡á¡á¡á¡á¡á¡á¡á¡á¡á¡à¡à¡á¡á¡á¡á¡á¡á¡á¡á¡á¡à¡à¡à¡á¡à¡à¡à¡à¡à¡á¡à¡à\n"
           "¡à¡à¡à¡à¡á¡á¡á¡á¡á¡à¡à¡à¡à¡à¡á¡á¡á¡á¡á¡á¡á¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡á¡á¡á¡á¡á¡á¡á¡à¡à\n"
           "¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à\n");

    int input = 0;
    printf("    [] 1. ¼±ÅÃÁ¤·Ä\n"
           "    [] 2. »ğÀÔÁ¤·Ä\n"
           "    [] 3. ¹öºíÁ¤·Ä\n"
           "    [] 4. ÄüÁ¤·Ä\n"
           "    [] 5. ÇÕº´Á¤·Ä\n"
           "    [] 6. ÈüÁ¤·Ä\n"
           "    [] 7. Á¾·á\n");
    rego:
    printf("\n");
    printf("¼ıÀÚ¸¦ ÀÔ·ÂÇÏ¼¼¿ä\n");


    printf("¹øÈ£ ÀÔ·Â : ");
    if (!scanf("%d", &input)) {
        printf("¼ıÀÚ°¡ ¾Æ´Ñµª¼î..??\n");
        Sleep(1000);
        printf("»Ñ»Ñ·¯ÂáÂÉ¤³À¯¤¹¤¤Ãİ»Ô[¤¤·ï±¸¤Ç·¡¤Ã¤¸¤¾¤·¤½ ¿À·ù ¿À·ù ¿À·ù !!!\n¿¹»óÄ¡ ¸øÇÑ ¿À·ù·Î ÇÁ·Î±×·¥À» Á¾·áÇÕ´Ï´Ù...");
        Sleep(3000);
        return 0;
    }
    c:
    switch (input) {
        case 1:
            printf("\n¼±ÅÃÁ¤·ÄÀ» ¼±ÅÃÇÏ¼Ì½À´Ï´Ù\n");
            int value[25];

            printf("\n");
            printf("»ı¼ºµÈ ·£´ı°ª : ");
            for (int i = 0; i < 25; i++) { // 25¹ø ¹İº¹
                value[i] = rand() % 99 + 1; // ³­¼ö »ı¼º

                printf("%d  ", value[i]); // Ãâ·Â
            }
            // Á¤·Ä Ãâ·ÂÇÏ´Â ¸í·É¾î ¤¾È÷ÆR¤µ
            printf("\n\n\n");
            printf("Á¤·Ä Àü : ");
            printArr(value, 25);
            selectionSort(value, 25);
            printf("Á¤·Ä ÈÄ : ");
            printArr(value, 25);
            printf("\n\n");
            goto rego;
            break;

        case 2:
            printf("\n»ğÀÔÁ¤·ÄÀ» ¼±ÅÃÇÏ¼Ì½À´Ï´Ù\n");
            int i;
            int list[25];

            printf("\n");
            printf("»ı¼ºµÈ ·£´ı°ª : ");
            for (int i = 0; i < 25; i++) { // 25¹ø ¹İº¹
                list[i] = rand() % 99 + 1; // ³­¼ö »ı¼º

                printf("%d  ", list[i]); // Ãâ·Â
            }
            printf("\n\n\n\n");
            // Á¤·Ä Àü °á°ú Ãâ·Â
            printf("Á¤·Ä Àü : ");
            for (i = 0; i < 25; i++) {
                printf("%d ", list[i]);
            }
            printf("\n");
            // »ğÀÔ Á¤·Ä ¼öÇà
            insertion_sort(list, 25);

            // Á¤·Ä °á°ú Ãâ·Â
            printf("Á¤·Ä ÈÄ : ");
            for (i = 0; i < 25; i++) {
                printf("%d ", list[i]);
            }
            printf("\n\n");
            goto rego;
            break;

        case 3:
            printf("\n¹öºíÁ¤·ÄÀ» ¼±ÅÃÇÏ¼Ì½À´Ï´Ù\n");
            int array[25];
            printf("\n");
            printf("»ı¼ºµÈ ·£´ı°ª : ");
            for (int i = 0; i < 25; i++) { // 25¹ø ¹İº¹
                array[i] = rand() % 99 + 1; // ³­¼ö »ı¼º

                printf("%d  ", array[i]); // Ãâ·Â
            }
            printf("\n\n\n\n");
            printf("Á¤·Ä Àü: ");
            for (i = 0; i < 25; i++) {
                printf("%d ", array[i]);
            }
            printf("\n");
            bubbleSort(array, 25); // ¹öºíÁ¤·Ä ÇÔ¼ö
            printf("Á¤·Ä ÈÄ : ");
            for (i = 0; i < 25; i++) {
                printf("%d ", array[i]);
            }
            printf("\n\n");
            goto rego;
            break;

        case 4:
            printf("\nÄüÁ¤·ÄÀ» ¼±ÅÃÇÏ¼Ì½À´Ï´Ù\n");
            int data[25];
            printf("\n");
            printf("»ı¼ºµÈ ·£´ı°ª : ");
            for (int i = 0; i < 25; i++) { // 25¹ø ¹İº¹
                data[i] = rand() % 99 + 1; // ³­¼ö »ı¼º

                printf("%d  ", data[i]); // Ãâ·Â
            }
            printf("\n\n\n\n");
            printf("Á¤·Ä Àü: ");
            // Á¤·Ä Àü °á°ú È®ÀÎ
            for (int i = 0; i < 25; i++) {
                printf("%d ", data[i]);
            }
            quick_sort(data, 0, 24);
            printf("\n");
            printf("Á¤·Ä ÈÄ : ");
            // °á°ú È®ÀÎ
            for (int i = 0; i < 25; i++) {
                printf("%d ", data[i]);
            }
            printf("\n\n");
            goto rego;
            break;

        case 5:
            printf("\nÇÕº´Á¤·ÄÀ» ¼±ÅÃÇÏ¼Ì½À´Ï´Ù\n");
            printf("\n");
            int marray[25];
            printf("»ı¼ºµÈ ·£´ı°ª : ");
            for (int i = 0; i < 25; i++) { // 25¹ø ¹İº¹
                marray[i] = rand() % 99 + 1; // ³­¼ö »ı¼º

                printf("%d  ", marray[i]); // Ãâ·Â
            }
            printf("\n\n\n\n");
            printf("Á¤·Ä Àü: ");
            // Á¤·Ä Àü °á°ú È®ÀÎ
            for (int i = 0; i < 25; i++) {
                printf("%d ", marray[i]);
            }
            mergeSort(marray, 0, 24);
            printf("\n");
            printf("Á¤·Ä Àü: ");
            for (int i = 0; i < 25; i++) {
                printf("%d ", marray[i]);
            }
            printf("\n\n");
            goto rego;
            break;

        case 6:
            printf("\nÈüÁ¤·ÄÀ» ¼±ÅÃÇÏ¼Ì½À´Ï´Ù\n");
            //¹«ÀÛÀ§ ¹è¿­
            int size = 25;
            printf("\n");
            int heaparr[25];
            printf("»ı¼ºµÈ ·£´ı°ª : ");
            for (int i = 0; i < 25; i++) { // 25¹ø ¹İº¹
                heaparr[i] = rand() % 99 + 1; // ³­¼ö »ı¼º

                printf("%d  ", heaparr[i]); // Ãâ·Â
            }
            printf("\n\n\n\n");
            printf("Á¤·Ä Àü: ");
            for(int i=0;i<25;++i){
                printf("%d ", heaparr[i]);
            }
            //ÈüÁ¤·Ä
            for(int i=0;i<25;++i){
                heapify(heaparr, size);
                heap(heaparr, &size);
            }
            printf("\n");
            //Ãâ·Â
            printf("Á¤·Ä Àü: ");
            for(int i=0;i<25;++i){
                printf("%d ", heaparr[i]);
            }
            printf("\n\n");
            goto rego;
            break;
        case 7:
            return 0;
            break;

        default: //else
            printf("Àß¸øµÈ ¹øÈ£ ÀÔ·Â...");
            Sleep(1000);
            system("cls");
            goto a;
            break;
    }

    Sleep(30000);
}

//
//    int value[] = { 4, 7, 9, 11, 3, 7, 6 };
//    int n = sizeof(value) / sizeof(int); // ¹è¿­ÀÇ ±æÀÌ