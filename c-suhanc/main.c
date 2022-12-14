#include <stdio.h>
#include <windows.h>
#include <stdlib.h>

void swap(int *, int *);

void bubbleSort(int[], int);

void merge(int a[], int start, int middle, int end);

void mergeSort(int a[], int start, int end);


// 배열 출력 함수
void printArr(int value[], int n) {
    for (int i = 0; i < n; i++)
        printf("%d ", value[i]);
    printf("\n");
}

// 선택 정렬 실행 함수
void selectionSort(int *value, int n) {
    int i, j;
    int min = 0;
    int temp1 = 0; // swap에 쓰기 위한 변수 (임시)

    // i for문 :
    for (i = 0; i < n - 1; i++) {
        min = i; // 인덱스
        for (j = i + 1; j < n; j++) {
            if (value[min] > value[j])
                min = j;
        }

        // 검사한 값중 가장 작은 값과 value[i]값 swap 과정.
        temp1 = value[i];
        value[i] = value[min];
        value[min] = temp1;
    }
}
// 선택정렬 여기까지


// 삽입 정렬
void insertion_sort(int list[], int n) {
    int i, j, key;

    // 인텍스 0은 이미 정렬된 것으로 볼 수 있다.
    for (i = 1; i < n; i++) {
        key = list[i]; // 현재 삽입될 숫자인 i번째 정수를 key 변수로 복사

        // 현재 정렬된 배열은 i-1까지이므로 i-1번째부터 역순으로 조사한다.
        // j 값은 음수가 아니어야 되고
        // key 값보다 정렬된 배열에 있는 값이 크면 j번째를 j+1번째로 이동
        for (j = i - 1; j >= 0 && list[j] > key; j--) {
            list[j + 1] = list[j]; // 레코드의 오른쪽으로 이동
        }

        list[j + 1] = key;
    }
}
//삽입정렬 여기까지

//버블정렬 실햄함수
void swap(int *num1, int *num2) {            // 서로 교환해주는 함수
    int temp;
    temp = *num2;
    *num2 = *num1;
    *num1 = temp;
}

void bubbleSort(int arr[], int size) {               // 버블정렬하는 함수
    int i, j;
    for (j = 0; j < size - 1; j++) {
//        printArr(arr, size);                       // 배열을 화면에 출력하는 함수
        for (i = 0; i < size - j - 1; i++) {
            if (arr[i] > arr[i + 1]) {
                swap(&arr[i], &arr[i + 1]);     // 서로 교환해주는 함수
            }
        }
    }
//    printf("\n");
}
//버블정렬 여기까지 ㅏㄴㅁㅁ

//퀵정렬 함수
void quick_sort(int *data, int start, int end) {
    if (start >= end) {
        // 원소가 1개인 경우
        return;
    }

    int pivot = start;
    int i = pivot + 1; // 왼쪽 출발 지점
    int j = end; // 오른쪽 출발 지점
    int temp;

    while (i <= j) {
        // 포인터가 엇갈릴때까지 반복
        while (i <= end && data[i] <= data[pivot]) {
            i++;
        }
        while (j > start && data[j] >= data[pivot]) {
            j--;
        }

        if (i > j) {
            // 엇갈림
            temp = data[j];
            data[j] = data[pivot];
            data[pivot] = temp;
        } else {
            // i번째와 j번째를 스왑
            temp = data[i];
            data[i] = data[j];
            data[j] = temp;
        }
    }

    // 분할 계산
    quick_sort(data, start, j - 1);
    quick_sort(data, j + 1, end);
}
//퀵정렬 여기까지

//합병정렬 함수
int sorted[25];

void merge(int a[], int start, int middle, int end) {

    int i, j, k; //각각 start middle middle+1 에 해당
    i = start;
    j = middle + 1;
    k = start;

    // 3가지의 경우중에 교차되는 경우먼저따져보자
    while (i <= middle && j <= end) {


        if (a[i] <= a[j]) {
            sorted[k] = a[i];
            i++;
        } else { //그 반대의 경우라면
            sorted[k] = a[j];
            j++;
        }
        k++;//정렬배열의 다음 칸에 담아야 하므로
    }

    //교차되는 경우가 아니라 특정 하나가 먼저 채워진다면?
    if (i > middle) {// i가 먼저채워졌기때문에 middle보다 커진것
        for (int t = j; t <= end; t++) {
            sorted[k] = a[t];
            k++;
        }
    } else { // j가 먼저채워졌기때문에
        for (int t = i; t <= middle; t++) {
            sorted[k] = a[t];
            k++;
        }
    }
    //정렬된 배열을 삽입

    for (int t = start; t <= end; t++) {
        a[t] = sorted[t];
    }
}

void mergeSort(int a[], int start, int end) {

    if (start < end) {
        int middle;
        middle = (start + end) / 2;
        mergeSort(a, start, middle);
        mergeSort(a, middle + 1, end);//계속 분할
        merge(a, start, middle, end);

    }
}
//합병정렬 여기까찌

//힙정렬 함수
//heapify, 힙 상태 만들기
void heapify(int *arr, int size){
    for(int i=1;i<size;++i){
        int child = i;
        do{
            //자식 노드가 부모 노드보다 크면 교환
            int root = (child-1)/2;
            if(arr[root]<arr[child]){
                int temp = arr[root];
                arr[root] = arr[child];
                arr[child] = temp;
            }
            child = root;
        }while(child!=0);	//최상단 노드까지 점검
    }
}

//최상단 노드와 최하단 노드 교체
void heap(int *arr, int *size){
    int temp = arr[0];
    arr[0] = arr[*size-1];
    arr[*size-1] = temp;
    --(*size);
}

int main() {
    system("mode con cols=150 lines=30");
    //cols = 칸/행 (가로)  lines = 줄/열 (세로)
    a:
    printf("□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□\n"
           "□□■■■■■■□■□□□■■■■■□□■□□□□■■■■■■■□□□□■■■■■■■□□□□■■■■■■■□□□■■■■□■□■□□\n"
           "□□□□■□□□□■□□□□□□□■■■■□□□□□□□□□□□□□□□□□□□□□■□□□□□□□□□□■□□□□□□■□■□■□□\n"
           "□□□□■■□■■■□□□■■■■■□□■□□□□□■□□□■□□□□□■■■■■■■□□□□□□□□□□■□□□■■■■□■■■□□\n"
           "□□□■□□■□□■□□□■□□□□■■■□□□□□■□□□■□□□□□■□□□□□□□□□□□□□□□□■□□□■□□□□■□■□□\n"
           "□□■□□□□■□■□□□■■■■■■□■□□□□□■□□□■□□□□□■□□□□□□□□□□□□□□□□■□□□■□□□□■□■□□\n"
           "□□□□□□□□□□□□□□□□□□□□■□□□□■■■■■■■□□□□■■■■■■■□□□□□□□□□□■□□□■■■■□■□■□□\n"
           "□□□□■■■■■□□□□□■■■■■■■□□□□□□□□□□□□□□□□□□■□□□□□□□□□□□□□■□□□□□□□□□□□□□\n"
           "□□□■□□□□□■□□□□□□□□■■■□□□□□□□□□□□□□□□□□□■□□□□□□□□□□□□■□□□□□■■■■■■■□□\n"
           "□□□■□□□□□■□□□□■■■□□□□□□□■■■■■■■■■□□■■■■■■■■■□□■■■■■■■■■□□□■□□□□□■□□\n"
           "□□□□■■■■■□□□□□■■■■■■■□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□■■■■■■■□□\n"
           "□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□\n");

    int input = 0;
    printf("    [] 1. 선택정렬\n"
           "    [] 2. 삽입정렬\n"
           "    [] 3. 버블정렬\n"
           "    [] 4. 퀵정렬\n"
           "    [] 5. 합병정렬\n"
           "    [] 6. 힙정렬\n"
           "    [] 7. 종료\n");
    rego:
    printf("\n");
    printf("숫자를 입력하세요\n");


    printf("번호 입력 : ");
    if (!scanf("%d", &input)) {
        printf("숫자가 아닌뎁쇼..??\n");
        Sleep(1000);
        printf("뿌뿌러쭐쪼ㅃ유ㅉㄴ쵸뿔[ㄴ뤄구ㅗ래ㅓㅈㅎㅇㅍ 오류 오류 오류 !!!\n예상치 못한 오류로 프로그램을 종료합니다...");
        Sleep(3000);
        return 0;
    }
    c:
    switch (input) {
        case 1:
            printf("\n선택정렬을 선택하셨습니다\n");
            int value[25];

            printf("\n");
            printf("생성된 랜덤값 : ");
            for (int i = 0; i < 25; i++) { // 25번 반복
                value[i] = rand() % 99 + 1; // 난수 생성

                printf("%d  ", value[i]); // 출력
            }
            // 정렬 출력하는 명령어 ㅎ히힣ㅅ
            printf("\n\n\n");
            printf("정렬 전 : ");
            printArr(value, 25);
            selectionSort(value, 25);
            printf("정렬 후 : ");
            printArr(value, 25);
            printf("\n\n");
            goto rego;
            break;

        case 2:
            printf("\n삽입정렬을 선택하셨습니다\n");
            int i;
            int list[25];

            printf("\n");
            printf("생성된 랜덤값 : ");
            for (int i = 0; i < 25; i++) { // 25번 반복
                list[i] = rand() % 99 + 1; // 난수 생성

                printf("%d  ", list[i]); // 출력
            }
            printf("\n\n\n\n");
            // 정렬 전 결과 출력
            printf("정렬 전 : ");
            for (i = 0; i < 25; i++) {
                printf("%d ", list[i]);
            }
            printf("\n");
            // 삽입 정렬 수행
            insertion_sort(list, 25);

            // 정렬 결과 출력
            printf("정렬 후 : ");
            for (i = 0; i < 25; i++) {
                printf("%d ", list[i]);
            }
            printf("\n\n");
            goto rego;
            break;

        case 3:
            printf("\n버블정렬을 선택하셨습니다\n");
            int array[25];
            printf("\n");
            printf("생성된 랜덤값 : ");
            for (int i = 0; i < 25; i++) { // 25번 반복
                array[i] = rand() % 99 + 1; // 난수 생성

                printf("%d  ", array[i]); // 출력
            }
            printf("\n\n\n\n");
            printf("정렬 전: ");
            for (i = 0; i < 25; i++) {
                printf("%d ", array[i]);
            }
            printf("\n");
            bubbleSort(array, 25); // 버블정렬 함수
            printf("정렬 후 : ");
            for (i = 0; i < 25; i++) {
                printf("%d ", array[i]);
            }
            printf("\n\n");
            goto rego;
            break;

        case 4:
            printf("\n퀵정렬을 선택하셨습니다\n");
            int data[25];
            printf("\n");
            printf("생성된 랜덤값 : ");
            for (int i = 0; i < 25; i++) { // 25번 반복
                data[i] = rand() % 99 + 1; // 난수 생성

                printf("%d  ", data[i]); // 출력
            }
            printf("\n\n\n\n");
            printf("정렬 전: ");
            // 정렬 전 결과 확인
            for (int i = 0; i < 25; i++) {
                printf("%d ", data[i]);
            }
            quick_sort(data, 0, 24);
            printf("\n");
            printf("정렬 후 : ");
            // 결과 확인
            for (int i = 0; i < 25; i++) {
                printf("%d ", data[i]);
            }
            printf("\n\n");
            goto rego;
            break;

        case 5:
            printf("\n합병정렬을 선택하셨습니다\n");
            printf("\n");
            int marray[25];
            printf("생성된 랜덤값 : ");
            for (int i = 0; i < 25; i++) { // 25번 반복
                marray[i] = rand() % 99 + 1; // 난수 생성

                printf("%d  ", marray[i]); // 출력
            }
            printf("\n\n\n\n");
            printf("정렬 전: ");
            // 정렬 전 결과 확인
            for (int i = 0; i < 25; i++) {
                printf("%d ", marray[i]);
            }
            mergeSort(marray, 0, 24);
            printf("\n");
            printf("정렬 전: ");
            for (int i = 0; i < 25; i++) {
                printf("%d ", marray[i]);
            }
            printf("\n\n");
            goto rego;
            break;

        case 6:
            printf("\n힙정렬을 선택하셨습니다\n");
            //무작위 배열
            int size = 25;
            printf("\n");
            int heaparr[25];
            printf("생성된 랜덤값 : ");
            for (int i = 0; i < 25; i++) { // 25번 반복
                heaparr[i] = rand() % 99 + 1; // 난수 생성

                printf("%d  ", heaparr[i]); // 출력
            }
            printf("\n\n\n\n");
            printf("정렬 전: ");
            for(int i=0;i<25;++i){
                printf("%d ", heaparr[i]);
            }
            //힙정렬
            for(int i=0;i<25;++i){
                heapify(heaparr, size);
                heap(heaparr, &size);
            }
            printf("\n");
            //출력
            printf("정렬 전: ");
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
            printf("잘못된 번호 입력...");
            Sleep(1000);
            system("cls");
            goto a;
            break;
    }

    Sleep(30000);
}

//
//    int value[] = { 4, 7, 9, 11, 3, 7, 6 };
//    int n = sizeof(value) / sizeof(int); // 배열의 길이