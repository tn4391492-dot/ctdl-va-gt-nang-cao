#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

struct SinhVien
{
    int maSV;
    string tenSV;
    string lop;
    float tongKet;
    string hanhKiem;
};

struct Node
{
    SinhVien data;
    Node* left;
    Node* right;
};

typedef Node* Tree;

void KhoiTaoCay(Tree &T)
{
    T = NULL;
}

Node* TaoNode(SinhVien sv)
{
    Node* p = new Node;

    p->data = sv;
    p->left = NULL;
    p->right = NULL;

    return p;
}

void ChenNode(Tree &T, SinhVien sv)
{
    if (T == NULL)
    {
        T = TaoNode(sv);
        return;
    }

    if (sv.maSV < T->data.maSV)
    {
        ChenNode(T->left, sv);
    }

    else if (sv.maSV > T->data.maSV)
    {
        ChenNode(T->right, sv);
    }

    else
    {
        cout << "Ma sinh vien " << sv.maSV
             << " da ton tai trong cay!\n";
    }
}

Node* TimKiem(Tree T, int maSV)
{
    // Không tìm th?y
    if (T == NULL)
    {
        return NULL;
    }

    if (maSV == T->data.maSV)
    {
        return T;
    }

    if (maSV < T->data.maSV)
    {
        return TimKiem(T->left, maSV);
    }

    return TimKiem(T->right, maSV);
}

void DuyetCay(Tree T)
{
    if (T != NULL)
    {
        cout << left
             << setw(12) << T->data.maSV
             << setw(25) << T->data.tenSV
             << setw(15) << T->data.lop
             << setw(12) << T->data.tongKet
             << setw(15) << T->data.hanhKiem
             << endl;

        DuyetCay(T->left);
        DuyetCay(T->right);
    }
}

SinhVien NhapSinhVien()
{
    SinhVien sv;

    cout << "\nNhap ma sinh vien: ";
    cin >> sv.maSV;

    cin.ignore();

    cout << "Nhap ten sinh vien: ";
    getline(cin, sv.tenSV);

    cout << "Nhap lop: ";
    getline(cin, sv.lop);

    cout << "Nhap tong ket: ";
    cin >> sv.tongKet;

    cin.ignore();

    cout << "Nhap hanh kiem (Tot/Khá/Trung binh/Yeu): ";
    getline(cin, sv.hanhKiem);

    return sv;
}

void HienThiSinhVien(SinhVien sv)
{
    cout << "\n========================================\n";
    cout << "THONG TIN SINH VIEN\n";
    cout << "========================================\n";

    cout << "Ma sinh vien : " << sv.maSV << endl;
    cout << "Ten sinh vien: " << sv.tenSV << endl;
    cout << "Lop          : " << sv.lop << endl;
    cout << "Tong ket     : " << sv.tongKet << endl;
    cout << "Hanh kiem    : " << sv.hanhKiem << endl;
}

int main()
{
    Tree T;

    KhoiTaoCay(T);

    int n;

    cout << "============================================\n";
    cout << "     QUAN LY SINH VIEN BANG CAY BST\n";
    cout << "============================================\n";

    cout << "\nNhap so luong sinh vien n = ";
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cout << "\n----------- SINH VIEN " << i + 1 << " -----------\n";

        SinhVien sv = NhapSinhVien();

        ChenNode(T, sv);
    }

    cout << "\n\n============================================\n";
    cout << "       DANH SACH TAT CA SINH VIEN\n";
    cout << "============================================\n";

    cout << left
         << setw(12) << "Ma SV"
         << setw(25) << "Ten sinh vien"
         << setw(15) << "Lop"
         << setw(12) << "Tong ket"
         << setw(15) << "Hanh kiem"
         << endl;

    cout << "---------------------------------------------------------------------\n";

    DuyetCay(T);

    int maCanTim;

    cout << "\n\n============================================\n";
    cout << "           TIM KIEM SINH VIEN\n";
    cout << "============================================\n";

    cout << "Nhap ma sinh vien can tim: ";
    cin >> maCanTim;

    Node* ketQua = TimKiem(T, maCanTim);

    if (ketQua != NULL)
    {
        cout << "\nTim thay sinh vien!";
        HienThiSinhVien(ketQua->data);
    }
    else
    {
        cout << "\nKhong co sinh vien co ma "
             << maCanTim << " trong cay!\n";
    }

    return 0;
}
