#include <stdio.h>
#include <windows.h>
#include <stdlib.h>

void swap(int *, int *);

void bubbleSort(int[], int);

void merge(int a[], int start, int middle, int end);

void mergeSort(int a[], int start, int end);

// �迭 ��� �Լ�
void printArr(int value[], int n) {
    for (int i = 0; i < n; i++)
        printf("%3d", value[i]);
    printf("\n");
}

// ���� ���� ���� �Լ�
void selectionSort(int *value, int n) {
    int i, j;
    int min = 0;
    int temp1 = 0; // swap�� ���� ���� ���� (�ӽ�)

    // i for�� :
    for (i = 0; i < n - 1; i++) {
        min = i; // �ε���
        for (j = i + 1; j < n; j++) {
            if (value[min] > value[j])
                min = j;
        }

        // �˻��� ���� ���� ���� ���� value[i]�� swap ����.
        temp1 = value[i];
        value[i] = value[min];
        value[min] = temp1;
    }
}
// �������� �������


// ���� ����
void insertion_sort(int list[], int n) {
    int i, j, key;

    // ���ؽ� 0�� �̹� ���ĵ� ������ �� �� �ִ�.
    for (i = 1; i < n; i++) {
        key = list[i]; // ���� ���Ե� ������ i��° ������ key ������ ����

        // ���� ���ĵ� �迭�� i-1�����̹Ƿ� i-1��°���� �������� �����Ѵ�.
        // j ���� ������ �ƴϾ�� �ǰ�
        // key ������ ���ĵ� �迭�� �ִ� ���� ũ�� j��°�� j+1��°�� �̵�
        for (j = i - 1; j >= 0 && list[j] > key; j--) {
            list[j + 1] = list[j]; // ���ڵ��� ���������� �̵�
        }

        list[j + 1] = key;
    }
}
//�������� �������

//�������� �����Լ�
void swap(int *num1, int *num2) {            // ���� ��ȯ���ִ� �Լ�
    int temp;
    temp = *num2;
    *num2 = *num1;
    *num1 = temp;
}

void bubbleSort(int arr[], int size) {               // ���������ϴ� �Լ�
    int i, j;
    for (j = 0; j < size - 1; j++) {
//        printArr(arr, size);                       // �迭�� ȭ�鿡 ����ϴ� �Լ�
        for (i = 0; i < size - j - 1; i++) {
            if (arr[i] > arr[i + 1]) {
                swap(&arr[i], &arr[i + 1]);     // ���� ��ȯ���ִ� �Լ�
            }
        }
    }
//    printf("\n");
}
//�������� ������� ��������

//������ �Լ�
void quick_sort(int *data, int start, int end) {
    if (start >= end) {
        // ���Ұ� 1���� ���
        return;
    }

    int pivot = start;
    int i = pivot + 1; // ���� ��� ����
    int j = end; // ������ ��� ����
    int temp;

    while (i <= j) {
        // �����Ͱ� ������������ �ݺ�
        while (i <= end && data[i] <= data[pivot]) {
            i++;
        }
        while (j > start && data[j] >= data[pivot]) {
            j--;
        }

        if (i > j) {
            // ������
            temp = data[j];
            data[j] = data[pivot];
            data[pivot] = temp;
        } else {
            // i��°�� j��°�� ����
            temp = data[i];
            data[i] = data[j];
            data[j] = temp;
        }
    }

    // ���� ���
    quick_sort(data, start, j - 1);
    quick_sort(data, j + 1, end);
}
//������ �������

//�պ����� �Լ�
int sorted[25];

void merge(int a[], int start, int middle, int end) {

    int i, j, k; //���� start middle middle+1 �� �ش�
    i = start;
    j = middle + 1;
    k = start;

    // 3������ ����߿� �����Ǵ� ��������������
    while (i <= middle && j <= end) {


        if (a[i] <= a[j]) {
            sorted[k] = a[i];
            i++;
        } else { //�� �ݴ��� �����
            sorted[k] = a[j];
            j++;
        }
        k++;//���Ĺ迭�� ���� ĭ�� ��ƾ� �ϹǷ�
    }

    //�����Ǵ� ��찡 �ƴ϶� Ư�� �ϳ��� ���� ä�����ٸ�?
    if (i > middle) {// i�� ����ä�����⶧���� middle���� Ŀ����
        for (int t = j; t <= end; t++) {
            sorted[k] = a[t];
            k++;
        }
    } else { // j�� ����ä�����⶧����
        for (int t = i; t <= middle; t++) {
            sorted[k] = a[t];
            k++;
        }
    }
    //���ĵ� �迭�� ����

    for (int t = start; t <= end; t++) {
        a[t] = sorted[t];
    }
}

void mergeSort(int a[], int start, int end) {

    if (start < end) {
        int middle;
        middle = (start + end) / 2;
        mergeSort(a, start, middle);
        mergeSort(a, middle + 1, end);//��� ����
        merge(a, start, middle, end);

    }
}

int main() {
    system("mode con cols=230 lines=30");
    //cols = ĭ/�� (����)  lines = ��/�� (����)
    a:
    printf("�������������������������������������������������������������������������������������������������������������������\n"
           "�������������������������������������������������������������������������������������������������������������������\n"
           "�������������������������������������������������������������������������������������������������������������������\n"
           "�������������������������������������������������������������������������������������������������������������������\n"
           "�������������������������������������������������������������������������������������������������������������������\n"
           "�������������������������������������������������������������������������������������������������������������������\n"
           "�������������������������������������������������������������������������������������������������������������������\n"
           "�������������������������������������������������������������������������������������������������������������������\n"
           "�������������������������������������������������������������������������������������������������������������������\n"
           "�������������������������������������������������������������������������������������������������������������������\n"
           "�������������������������������������������������������������������������������������������������������������������\n"
           "�������������������������������������������������������������������������������������������������������������������");

    int input = 0;
    printf("      [] 1. ��������\n"
           "    [] 2. ��������\n"
           "    [] 3. ��������\n"
           "    [] 4. ������\n"
           "    [] 5. �պ�����\n"
           "    [] 6. ������\n"
           "    [] 7. ����\n");
    printf("��ȣ �Է� : ");
    scanf("%d", &input);

    switch (input) {
        case 1:
            printf("���������� �����ϼ̽��ϴ�\n");
            int value[25];

            printf("\n");
            printf("������ ������ : ");
            for (int i = 0; i < 25; i++) { // 25�� �ݺ�
                value[i] = rand() % 99 + 1; // ���� ����

                printf("%d  ", value[i]); // ���
            }
            // ���� ����ϴ� ���ɾ� �����R��
            printf("\n\n\n");
            printf("���� �� : ");
            printArr(value, 25);
            selectionSort(value, 25);
            printf("���� �� : ");
            printArr(value, 25);
            break;

        case 2:
            printf("���������� �����ϼ̽��ϴ�\n");
            int i;
            int list[25];

            printf("\n");
            printf("������ ������ : ");
            for (int i = 0; i < 25; i++) { // 25�� �ݺ�
                list[i] = rand() % 99 + 1; // ���� ����

                printf("%d  ", list[i]); // ���
            }
            printf("\n\n\n\n");
//            int n2 = MAX_SIZE;
//            int list[25] = {8, 5, 6, 2, 4, 5, 23, 3,32 ,35,235,235, 25,53,2,243, 5,62,3235, 523,2,23 ,5,8,5};
            // ���� �� ��� ���
            printf("���� �� : ");
            for (i = 0; i < 25; i++) {
                printf("%d ", list[i]);
            }
            printf("\n");
            // ���� ���� ����
            insertion_sort(list, 25);

            // ���� ��� ���
            printf("���� �� : ");
            for (i = 0; i < 25; i++) {
                printf("%d ", list[i]);
            }

            break;

        case 3:
            printf("���������� �����ϼ̽��ϴ�.");
            int array[25];
            printf("\n");
            printf("������ ������ : ");
            for (int i = 0; i < 25; i++) { // 25�� �ݺ�
                array[i] = rand() % 99 + 1; // ���� ����

                printf("%d  ", array[i]); // ���
            }
            printf("\n\n\n\n");
            printf("���� ��: ");
            printArr(array, 25);
            printf("\n");
            bubbleSort(array, 25); // �������� �Լ�
            printf("���� �� : ");
            printArr(array, 25);

            break;

        case 4:
            printf("�������� �����ϼ̽��ϴ�.");
            int data[25];
            printf("\n");
            printf("������ ������ : ");
            for (int i = 0; i < 25; i++) { // 25�� �ݺ�
                data[i] = rand() % 99 + 1; // ���� ����

                printf("%d  ", data[i]); // ���
            }
            printf("\n\n\n\n");
            printf("���� ��: ");
            // ���� �� ��� Ȯ��
            for (int i = 0; i < 25; i++) {
                printf("%d ", data[i]);
            }
            quick_sort(data, 0, 24);
            printf("\n");
            printf("���� �� : ");
            // ��� Ȯ��
            for (int i = 0; i < 25; i++) {
                printf("%d ", data[i]);
            }

            break;

        case 5:
            printf("�պ������� �����ϼ̽��ϴ�.");
            printf("\n");
            int marray[25];
            printf("������ ������ : ");
            for (int i = 0; i < 25; i++) { // 25�� �ݺ�
                marray[i] = rand() % 99 + 1; // ���� ����

                printf("%d  ", marray[i]); // ���
            }
            printf("\n\n\n\n");
            printf("���� ��: ");
            // ���� �� ��� Ȯ��
            for (int i = 0; i < 25; i++) {
                printf("%d ", marray[i]);
            }
            mergeSort(marray, 0, 24);
            printf("\n");
            printf("���� ��: ");
            for (int i = 0; i < 25; i++) {
                printf("%d ", marray[i]);
            }
            break;

        case 6:
            printf("6");
            break;

        case 7:
            printf("7");
            break;

        default: //else
            printf("�߸��� ��ȣ �Է�...");
            Sleep(1000);
            system("cls");
            goto a;
            break;
    }

    Sleep(30000);
}

//
//    int value[] = { 4, 7, 9, 11, 3, 7, 6 };
//    int n = sizeof(value) / sizeof(int); // �迭�� ����