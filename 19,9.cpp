#include <stdio.h>
#include <string.h>

typedef struct {
    int maHang;
    char tenHang[50];
    int ngay;
    int thang;
    int nam;
    float gia;
} HangHoa;

void nhap(HangHoa a[], int n) {
    int i;

    for (i = 0; i < n; i++) {
        printf("\nNhap hang hoa thu %d:\n", i + 1);

        printf("Ma hang hoa: ");
        scanf("%d", &a[i].maHang);

        getchar();
        printf("Ten hang hoa: ");
        fgets(a[i].tenHang, sizeof(a[i].tenHang), stdin);
        a[i].tenHang[strcspn(a[i].tenHang, "\n")] = '\0';

        printf("Ngay xuat hang: ");
        scanf("%d", &a[i].ngay);

        printf("Thang xuat hang: ");
        scanf("%d", &a[i].thang);

        printf("Nam xuat hang: ");
        scanf("%d", &a[i].nam);

        printf("Gia xuat hang (trieu dong): ");
        scanf("%f", &a[i].gia);
    }
}

void xuat(HangHoa a[], int n) {
    int i;

    printf("\n%-10s %-25s %-15s %-15s\n",
           "Ma", "Ten hang hoa", "Ngay xuat", "Gia (trieu)");

    for (i = 0; i < n; i++) {
        printf("%-10d %-25s %02d/%02d/%-8d %-15.2f\n",
               a[i].maHang,
               a[i].tenHang,
               a[i].ngay,
               a[i].thang,
               a[i].nam,
               a[i].gia);
    }
}

void selectionSort(HangHoa a[], int n) {
    int i, j, min;
    HangHoa temp;

    for (i = 0; i < n - 1; i++) {
        min = i;

        for (j = i + 1; j < n; j++) {
            if (a[j].gia < a[min].gia) {
                min = j;
            }
        }

        if (min != i) {
            temp = a[i];
            a[i] = a[min];
            a[min] = temp;
        }
    }
}

void timKiemNhiPhan(HangHoa a[], int n, float x) {
    int left = 0;
    int right = n - 1;
    int mid;
    int timThay = 0;

    while (left <= right) {
        mid = (left + right) / 2;

        if (a[mid].gia == x) {
            timThay = 1;

            printf("\nCac hang hoa co gia %.2f trieu dong:\n", x);

            // Tim cac phan tu trung gia ben trai
            int i = mid;
            while (i >= 0 && a[i].gia == x) {
                i--;
            }

            i++;

            // Hien thi tat ca phan tu trung gia
            while (i < n && a[i].gia == x) {
                printf("Ma hang: %d\n", a[i].maHang);
                printf("Ten hang: %s\n", a[i].tenHang);
                printf("Ngay xuat: %02d/%02d/%d\n",
                       a[i].ngay, a[i].thang, a[i].nam);
                printf("Gia: %.2f trieu dong\n\n", a[i].gia);
                i++;
            }

            break;
        }
        else if (a[mid].gia < x) {
            left = mid + 1;
        }
        else {
            right = mid - 1;
        }
    }

    if (timThay == 0) {
        printf("\nKhong tim thay hang hoa co gia %.2f trieu dong.\n", x);
    }
}

int main() {
    HangHoa a[100];
    int n;
    float x;

    printf("Nhap so luong hang hoa n = ");
    scanf("%d", &n);

    nhap(a, n);

    printf("\n===== DANH SACH HANG HOA VUA NHAP =====\n");
    xuat(a, n);

    selectionSort(a, n);

    printf("\n===== DANH SACH SAU KHI SAP XEP =====\n");
    xuat(a, n);

    printf("\nNhap gia can tim X (trieu dong): ");
    scanf("%f", &x);

    timKiemNhiPhan(a, n, x);

    return 0;
}
