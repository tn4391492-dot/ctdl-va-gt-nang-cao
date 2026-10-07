#include <bits/stdc++.h>
using namespace std;

struct ngaythang{
	int ngay, thang, nam;
};

struct nhanvien{
	string manv;
	string hoten;
	ngaythang ngaysinh;
	float luong;
};

void nhap(nhanvien a[], int n){
	for(int i = 0; i < n; i++){
		cout << "\nnhap nhan vien thu " << i + 1 << endl;
		
		cout << "nhap ma nhan vien: ";
		getline(cin, a[i].manv);
		
		cout << "nhap ho ten: ";
		getline(cin, a[i].hoten);
		
		cout << "nhap ngay sinh (ngay thang nam): ";
		// Ð?c c? dòng ngày sinh d? x? lý d?u '/' n?u ngu?i dùng nh?p
		string s_ngay;
		getline(cin, s_ngay);
		for(int k = 0; k < s_ngay.length(); k++){
			if(s_ngay[k] == '/') s_ngay[k] = ' ';
		}
		stringstream ss(s_ngay);
		ss >> a[i].ngaysinh.ngay >> a[i].ngaysinh.thang >> a[i].ngaysinh.nam;
		
		cout << "nhap luong: ";
		cin >> a[i].luong;
		cin.ignore(); // Xóa d?u xu?ng dòng sau khi nh?p luong
	}
}

string formatNgay(ngaythang nt){
	stringstream ss;
	if(nt.ngay < 10) ss << "0";
	ss << nt.ngay << "/";
	if(nt.thang < 10) ss << "0";
	ss << nt.thang << "/" << nt.nam;
	return ss.str();
}

void xuat(nhanvien a[], int n){
	cout << left << setw(20) << "ma nhan vien"
		 << setw(20) << "ho ten"
		 << setw(20) << "ngay sinh"
		 << setw(20) << "luong" << endl;
	cout << "--------------------------------------------------------------------------------" << endl;
	for(int i = 0; i < n; i++){
		cout << left << setw(20) << a[i].manv
			 << setw(20) << a[i].hoten
			 << setw(20) << formatNgay(a[i].ngaysinh)
			 << setw(20) << fixed << setprecision(2) << a[i].luong << endl;
	}
}

void in1nv(nhanvien nv){
	cout << left << setw(20) << nv.manv
		 << setw(20) << nv.hoten
		 << setw(20) << formatNgay(nv.ngaysinh)
		 << setw(20) << fixed << setprecision(2) << nv.luong << endl;
}

void bubbleSort(nhanvien a[], int n){
	for(int i = 0; i < n - 1; i++){
		for(int j = 0; j < n - i - 1; j++){
			if(a[j].luong > a[j+1].luong){
				nhanvien temp = a[j];
				a[j] = a[j+1];
				a[j+1] = temp;
			}
		}
	}
}

void binarySearch(nhanvien a[], int n, float x){
	int left = 0;
	int right = n - 1;
	int index = -1;
	
	while(left <= right){
		int mid = left + (right - left) / 2;
		if(a[mid].luong == x){
			index = mid;
			break;
		}
		if(a[mid].luong < x){
			left = mid + 1;
		} else {
			right = mid - 1;
		}
	}
	
	if(index != -1){
		cout << "\nda tim thay nhan vien co luong " << x << endl;
		cout << left << setw(20) << "ma nhan vien"
			 << setw(20) << "ho ten"
			 << setw(20) << "ngay sinh"
			 << setw(20) << "luong" << endl;
		cout << "--------------------------------------------------------------------------------" << endl;
		
		int i = index;
		while(i >= 0 && a[i].luong == x){
			i--;
		}
		i++;
		
		while(i < n && a[i].luong == x){
			in1nv(a[i]);
			i++;
		}
	} else {
		cout << "\nko co nhan vien co luong la " << x << endl;
	}
}

int main(){
	int n;
	do{
		cout << "\nnhap so nhan vien: ";
		cin >> n;
		cin.ignore();
	} while(n <= 0);
	
	nhanvien* ds = new nhanvien[n];
	
	cout << "\nCAU 2" << endl;
	nhap(ds, n);
	
	cout << "\nCAU 3" << endl;
	xuat(ds, n);
	
	cout << "\nCAU 4" << endl;
	bubbleSort(ds, n);
	xuat(ds, n);
	
	cout << "\nCAU 5" << endl;
	float x;
	do{
		cout << "\nnhap luong can tim: ";
		cin >> x;
		cin.ignore();
	} while(x < 0);
	
	binarySearch(ds, n, x);
	
	delete[] ds;
	return 0;
}
