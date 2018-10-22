#include <stdio.h>
#include <stdlib.h>
#include <memory.h>


typedef struct {
    char maSinhVien[10];
    char ten[10];
    char soDienThoai[10];
} Sinhvien;

Sinhvien mangSinhVien[10];

void removeStdChar(char array[]) {
    if (strchr(array, '\n') == NULL) {
        while (fgetc(stdin) != '\n');
    }
}

void taoMenu() {
    printf("Menu cho phep nguoi dung lua chon\n");
    printf("1. Them moi sinh vien\n");
    printf("2. Hien thi danh sach sinh vien\n");
    printf("3. Luu danh sach sinh vien\n");
    printf("4. Doc danh sach sinh vien tu file\n");
    printf("5. Thoat chuong trinh\n");
    printf("Nhap lua chon cua ban\n");
}

void themMoiSinhVien(Sinhvien mangSinhVien[], int i) {
    do {
        printf("Nhap ma sinh vien:\n");
        fgets(mangSinhVien[i].maSinhVien, sizeof(mangSinhVien[i].maSinhVien) * sizeof(char), stdin);
        removeStdChar(mangSinhVien[i].maSinhVien);
        mangSinhVien[i].maSinhVien[strlen(mangSinhVien[i].maSinhVien) - 1] = ' ';
        if (strlen(mangSinhVien[i].maSinhVien) != 6) {
            printf("Loi, Nhap lai ma sinh vien\n");
        }
    } while (strlen(mangSinhVien[i].maSinhVien) != 6);
    printf("Nhap ten sinh vien:\n");
    fgets(mangSinhVien[i].ten, sizeof(mangSinhVien[i].ten) * sizeof(char), stdin);
    removeStdChar(mangSinhVien[i].ten);
    mangSinhVien[i].ten[strlen(mangSinhVien[i].ten) - 1] = ' ';
    printf("Nhap so dien thoai sinh vien:\n");
    fgets(mangSinhVien[i].soDienThoai, sizeof(mangSinhVien[i].soDienThoai) * sizeof(char), stdin);
    removeStdChar(mangSinhVien[i].soDienThoai);
    mangSinhVien[i].soDienThoai[strlen(mangSinhVien[i].soDienThoai) - 1] = ' ';
}

void hienThiDanhSachSinhVien(Sinhvien mangSinhVien[], int i) {
    printf("\n%-20s| %-20s| %20s\n", "Ma Sinh Vien", "Ten", "So Dien Thoai");
    for (int j = 0; j < i; j++) {
        printf("\n%-20s| %-20s| %20s\n", mangSinhVien[j].maSinhVien, mangSinhVien[j].ten, mangSinhVien[j].soDienThoai);
    }
}

void luuThongTin(Sinhvien mangSinhVien[], int i) {
    FILE *fp;
    fp = fopen("danhsachsinhvien.txt", "w");
    if (fp != NULL) {
        fprintf(fp, "\n%-20s|%-20s|%-20s\n", "Ma Sinh Vien", "Ten", "So Dien Thoai");
        for (int j = 0; j < i; j++) {
            fprintf(fp, "\n%-20s|%-20s|%-20s\n", mangSinhVien[j].maSinhVien, mangSinhVien[j].ten,
                    mangSinhVien[j].soDienThoai);
        }
        fclose(fp);
    }
}

void docDanhSach(char array[]) {
    FILE *fp;
    fp = fopen("danhsachsinhvien.txt", "r");
    while (fgets(array, 255, fp) != NULL) {
        printf("%s", array);
    }
    fclose(fp);
}

int soLuong = 0;

int main() {
    int luachon;
    char danhsach[255];
    while (1) {
        taoMenu();
        scanf("%d", &luachon);
        getchar();
        switch (luachon) {
            case 1:
                if (soLuong <= 10) {
                    themMoiSinhVien(mangSinhVien, soLuong);
                    soLuong++;
                } else {
                    printf("Danh sach sinh vien da day \n");
                    break;
                }
                break;
            case 2:
                hienThiDanhSachSinhVien(mangSinhVien, soLuong);
                break;
            case 3:
                luuThongTin(mangSinhVien, soLuong);
                break;
            case 4:
                docDanhSach(danhsach);
                break;
            case 5:
                return 0;
            default:
                printf("Thong tin khong hop le\n");
                break;
        }
    }

}