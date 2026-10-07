#include <bits/stdc++.h>
using namespace std;

struct khachhang{
	int makh;
	string tenkh, sdt;
	long long tongtien;
};

void nhap(khachhang a[], int n){
	for(int i = 0; i < n; i++){
		cout << "\nnhap khach hang thu " << i + 1 << endl;
		cout << "nhap ma khach hang: ";
		cin >> a[i].makh;
		cin.ignore();
		cout << "nhap ten khach hang: ";
		getline(cin, a[i].tenkh);
		cout << "nhap sdt: ";
		getline(cin, a[i].sdt);
		cout << "nhap tong tien: ";
		cin >> a[i].tongtien;
		cin.ignore();
	}
}

void xuat(khachhang a[], int n){
	cout << left << setw(20) << "ma khach hang"
		 << setw(20) << "ten khach hang"
		 << setw(20) << "sdt"
		 << setw(20) << "tong tien" << endl;
	cout << "----------------------------------------------------------------" << endl;
	for(int i = 0; i < n; i++){
		cout << left << setw(20) << a[i].makh
			 << setw(20) << a[i].tenkh
			 << setw(20) << a[i].sdt
			 << setw(20) << a[i].tongtien << endl;
	}
}

void inserttionSort(khachhang a[], int n){
	for(int i = 1; i < n; i++){
		khachhang key = a[i];
		int j = i - 1;
		while(j >= 0 && a[j].tongtien > key.tongtien){
			a[j + 1] = a[j];
			j = j - 1;
		}
		a[j + 1] = key;
	}
}

void binarySearch(khachhang a[], int n, long long x){
	int left = 0;
	int right = n - 1;
	int index = -1;
	
	while(left <= right){
		int mid = left + (right - left) / 2;
		if(a[mid].tongtien == x){
			index = mid;
			break;
		}
		if(a[mid].tongtien < x){
			left = mid + 1;
		}else{
			right = mid - 1;
		}
	}
	
	if(index != -1){
		cout << "\nda tim thay khach hang co tong tien " << x << endl;
		
		int start = index;
		while(start > 0 && a[start - 1].tongtien == x){
			start--;
		}
		
		int end = index;
		while(end < n - 1 && a[end + 1].tongtien == x){
			end++;
		}

		cout << left << setw(20) << "ma khach hang"
			 << setw(20) << "ten khach hang"
			 << setw(20) << "sdt"
			 << setw(20) << "tong tien" << endl;
		cout << "----------------------------------------------------------------" << endl;
		
		for(int i = start; i <= end; i++){
			cout << left << setw(20) << a[i].makh
				 << setw(20) << a[i].tenkh
				 << setw(20) << a[i].sdt
				 << setw(20) << a[i].tongtien << endl;
		}
	}else{
		cout << "\nko co khach hang co tong tien la " << x << endl;
	}
}

int main(){
	int n;
	do{
		cout << "\nnhap so khach hang: ";
		cin >> n;
		cin.ignore();
	}while(n <= 0);

	khachhang* ds = new khachhang[n];

	cout << "\nCAU 1 & 2: NHAP VA HIEN THI DANH SACH" << endl;
	nhap(ds, n);
	xuat(ds, n);

	cout << "\nCAU 3: SAP XEP TANG DAN THEO TONG TIEN" << endl;
	inserttionSort(ds, n);
	xuat(ds, n);

	cout << "\nCAU 4: TIM KIEM KHACH HANG" << endl;
	long long x;
	do{
		cout << "\nnhap tien can tim: ";
		cin >> x;
		cin.ignore();
	}while(x < 0);

	binarySearch(ds, n, x);

	delete[] ds; 
	return 0;
}
