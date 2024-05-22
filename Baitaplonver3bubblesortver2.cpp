#include <iostream>
#include <string>

using namespace std;

// Ðinh nghia cau truc cho sinh vien 
struct SinhVien {
    string id;       // Ma so sinh vien 
    string ten;      // Ten sinh viên
    float diemH10;   // Diem cua sinh vien(He 10) 
    float diemH4;    // Diem cua sinh vien(He 4) 
    string diemChu;  // Diem cua sinh vien(He chu) 
    SinhVien* prev;  // Con tro chi den sinh vien truoc do trong danh sach lien ket kep 
    SinhVien* next;  // Con tro chi den sinh vien tiep theo trong danh sach lien ket kep
};

// Cac ham thao tac 
void themSinhVien(SinhVien* &head);
void suaThongTinSinhVien(SinhVien* head, string id);
void xoaSinhVien(SinhVien* &head, string id);
void timKiemSinhVien(SinhVien* head, string id);
void sapXepTheoMaSV(SinhVien* &head);
void sapXepTheoTen(SinhVien* &head);
void sapXepTheoDiem(SinhVien* &head);
void tinhDiemTrungBinh(SinhVien* head, float &diemTBH10, float &gpaTB,string &diemChuTB);
void inDanhSach(SinhVien* head);

int main() {
    SinhVien* head = NULL; // Khoi tao 1 danh sach lien ket kep

    char luaChon;
    do {
        cout << "1. Them sinh vien moi\n";
        cout << "2. Sua thong tin sinh vien\n";
        cout << "3. Xoa sinh vien\n";
        cout << "4. Tim kiem sinh vien\n";
        cout << "5. Sap xep theo ma sinh vien\n";
        cout << "6. Sap xep theo ten\n";
        cout << "7. Sap xep theo diem\n";
        cout << "8. Tinh va in diem trung binh\n";
        cout << "9. In danh sach sinh vien\n";
        cout << "0. Thoat\n";
        cout << "Nhap lua chon cua ban: ";
        cin >> luaChon;

        switch (luaChon) {
            case '1':
                themSinhVien(head);
                break;
            case '2': {
                string id;
                cout << "Nhap ma so sinh vien can sua: ";
                cin >> id;
                suaThongTinSinhVien(head, id);
                break;
            }
            case '3': {
                string id;
                cout << "Nhap ma so sinh vien can xoa: ";
                cin >> id;
                xoaSinhVien(head, id);
                break;
            }
            case '4': {
                string id;
                cout << "Nhap ma so sinh vien can tim kiem: ";
                cin >> id;
                timKiemSinhVien(head, id);
                break;
            }
            case '5':
                sapXepTheoMaSV(head);
                break;
            case '6':
                sapXepTheoTen(head);
                break;
            case '7':
                sapXepTheoDiem(head);
                break;
            case '8': {
                float diemTBH10, gpaTB;
                string diemChuTB;
                tinhDiemTrungBinh(head, diemTBH10, gpaTB, diemChuTB);
                cout << "Diem trung binh he 10 cua tat ca sinh vien: " << diemTBH10 << endl;
                cout << "Diem GPA trung binh cua tat ca sinh vien: " << gpaTB<< endl;
                cout << "Diem Chu trung binh cua tat ca sinh vien: " << diemChuTB << endl;
                break;
            }
            case '9':
                inDanhSach(head);
                break;
            case '0':
                cout << "Chuong trinh ket thuc.\n";
                break;
            default:
                cout << "Lua chon khong hop ly, vui long thu lai.\n";
        }
    } while (luaChon != '0');

    // Giai phong bo nho cua danh sach lien ket truoc khi ket thuc chuong trinh 
    SinhVien* hienTai = head;
    while (hienTai != NULL) {
        SinhVien* temp = hienTai;
        hienTai = hienTai->next;
        delete temp;
    }

    return 0;
}

// Ham them sinh vien moi vao danh sach lien ket kep 
void themSinhVien(SinhVien* &head) {
    SinhVien* sinhVienMoi = new SinhVien;
    cout << "Nhap ma so sinh vien: ";
    cin >> sinhVienMoi->id;
    cout << "Nhap ten sinh vien: ";
    cin.ignore();
    getline(cin, sinhVienMoi->ten);
    cout << "Nhap diem sinh vien (he 10): ";
    cin >> sinhVienMoi->diemH10;

    // Chuyen diem he 10 sang diem he 4 va diem he chu
    if (sinhVienMoi->diemH10 < 4.0) {
        sinhVienMoi->diemH4 = 0;
        sinhVienMoi->diemChu = "F";
    } else if (sinhVienMoi->diemH10 >= 4.0 && sinhVienMoi->diemH10 < 5.0) {
        sinhVienMoi->diemH4 = 1.0;
        sinhVienMoi->diemChu = "D";
    } else if (sinhVienMoi->diemH10 >= 5.0 && sinhVienMoi->diemH10 < 5.5) {
        sinhVienMoi->diemH4 = 1.5;
        sinhVienMoi->diemChu = "D+";
    } else if (sinhVienMoi->diemH10 >= 5.5 && sinhVienMoi->diemH10 < 6.5) {
        sinhVienMoi->diemH4 = 2.0;
        sinhVienMoi->diemChu = "C";
    } else if (sinhVienMoi->diemH10 >= 6.5 && sinhVienMoi->diemH10 < 7.0) {
        sinhVienMoi->diemH4 = 2.5;
        sinhVienMoi->diemChu = "C+";
    } else if (sinhVienMoi->diemH10 >= 7.0 && sinhVienMoi->diemH10 < 8.0) {
        sinhVienMoi->diemH4 = 3.0;
        sinhVienMoi->diemChu = "B";
    } else if (sinhVienMoi->diemH10 >= 8.0 && sinhVienMoi->diemH10 < 8.5) {
        sinhVienMoi->diemH4 = 3.5;
        sinhVienMoi->diemChu = "B+";
    } else if (sinhVienMoi->diemH10 >= 8.5 && sinhVienMoi->diemH10 <= 10) {
        sinhVienMoi->diemH4 = 4.0;
        sinhVienMoi->diemChu = "A";
    } else {
        cout << "Diem nhap khong hop le, moi nhap lai.\n";
        delete sinhVienMoi;
        return;
    }

    sinhVienMoi->prev = NULL;
    sinhVienMoi->next = head;
    if (head != NULL) {
        head->prev = sinhVienMoi;
    }
    head = sinhVienMoi;
    cout << "Them sinh vien thanh cong.\n";
}

// Ham sua thong tin cua 1 sinh vien
void suaThongTinSinhVien(SinhVien* head, string id) {
    SinhVien* hienTai = head;
    while (hienTai != NULL) {
        if (hienTai->id == id) {
            cout << "Nhap diem moi cho sinh vien (he 10): ";
            cin >> hienTai->diemH10;

            // Chhuyen diem he 10 sang diem he 4 va diem he chu
            if (hienTai->diemH10 < 4.0) {
                hienTai->diemH4 = 0.0;
                hienTai->diemChu = "F";
            } else if (hienTai->diemH10 >= 4.0 && hienTai->diemH10 < 5.0) {
                hienTai->diemH4 = 1.0;
                hienTai->diemChu = "D";
            } else if (hienTai->diemH10 >= 5.0 && hienTai->diemH10 < 5.5) {
                hienTai->diemH4 = 1.5;
                hienTai->diemChu = "D+";
            } else if (hienTai->diemH10 >= 5.5 && hienTai->diemH10 < 6.5) {
                hienTai->diemH4 = 2.0;
                hienTai->diemChu = "C";
            } else if (hienTai->diemH10 >= 6.5 && hienTai->diemH10 < 7.0) {
                hienTai->diemH4 = 2.5;
                hienTai->diemChu = "C+";
            } else if (hienTai->diemH10 >= 7.0 && hienTai->diemH10 < 8.0) {
                hienTai->diemH4 = 3.0;
                hienTai->diemChu = "B";
            } else if (hienTai->diemH10 >= 8.0 && hienTai->diemH10 < 8.5) {
                hienTai->diemH4 = 3.5;
                hienTai->diemChu = "B+";
            } else if (hienTai->diemH10 >= 8.5 && hienTai->diemH10 <= 10) {
                hienTai->diemH4 = 4.0;
                hienTai->diemChu = "A";
            } else {
                cout << "Diem nhap khong hop le, moi nhap lai.\n";
                return;
            }

            cout << "Thong tin sinh vien da duoc cap nhat.\n";
            return;
        }
        hienTai = hienTai->next;
    }
    cout << "Khong tim thay sinh vien co ma so " << id << ".\n";
}

// Ham xoa 1 sinh vien khoi danh sach
void xoaSinhVien(SinhVien* &head, string id) {
    SinhVien* hienTai = head;
    while (hienTai != NULL) {
        if (hienTai->id == id) {
            if (hienTai->prev != NULL) {
                hienTai->prev->next = hienTai->next;
            } else {
                head = hienTai->next;
            }
            if (hienTai->next != NULL) {
                hienTai->next->prev = hienTai->prev;
            }
            delete hienTai;
            cout << "Da xoa sinh vien co ma so " << id << ".\n";
            return;
        }
        hienTai = hienTai->next;
    }
    cout << "Khong tim thay sinh vien co ma so " << id << ".\n";
}

// Ham tim kiem thong tin cua sinh vien
void timKiemSinhVien(SinhVien* head, string id) {
    SinhVien* hienTai = head;
    while (hienTai != NULL) {
        if (hienTai->id == id) {
            cout << "Sinh vien duoc tim thay:\n";
            cout << "Ma so: " << hienTai->id << endl;
            cout << "Ten: " << hienTai->ten << endl;
            cout << "Diem: " << hienTai->diemH10 << " (GPA: " << hienTai->diemH4 << "; diem he Chu: " << hienTai->diemChu << ")" << endl;
            return;
        }
        hienTai = hienTai->next;
    }
    cout << "Khong tim thay sinh vien co ma so " << id << ".\n";
}

// Ham sap xep danh sach sinh vien theo ma so sinh vien dung sap xep noi bot 
void sapXepTheoMaSV(SinhVien* &head) {
    if (head == NULL || head->next == NULL) {
        cout << "Danh sach sinh vien rong hoac chi co 1 sinh vien, khong can sap xep.\n";
        return;
    }

    bool hoanDoi;
    do {
        hoanDoi = false;
        SinhVien* hienTai = head;
        while (hienTai->next != NULL) {
            if (hienTai->id > hienTai->next->id) {
                swap(hienTai->id, hienTai->next->id);
                swap(hienTai->ten, hienTai->next->ten);
                swap(hienTai->diemH10, hienTai->next->diemH10);
                swap(hienTai->diemH4, hienTai->next->diemH4);
                swap(hienTai->diemChu, hienTai->next->diemChu);
                hoanDoi = true;
            }
            hienTai = hienTai->next;
        }
    } while (hoanDoi);
    cout << "Da sap xep danh sach theo ma sinh vien.\n";
}

// Ham sap xep danh sach sinh vien theo ten dung sap xep noi bot 
void sapXepTheoTen(SinhVien* &head) {
    if (head == NULL || head->next == NULL) {
        cout << "Danh sach sinh vien rong hoac chi co 1 sinh vien, khong can sap xep.\n";
        return;
    }

    bool hoanDoi;
    do {
        hoanDoi = false;
        SinhVien* hienTai = head;
        while (hienTai->next != NULL) {
            if (hienTai->ten > hienTai->next->ten) {
                swap(hienTai->id, hienTai->next->id);
                swap(hienTai->ten, hienTai->next->ten);
                swap(hienTai->diemH10, hienTai->next->diemH10);
                swap(hienTai->diemH4, hienTai->next->diemH4);
                swap(hienTai->diemChu, hienTai->next->diemChu);
                hoanDoi = true;
            }
            hienTai = hienTai->next;
        }
    } while (hoanDoi);
    cout << "Da sap xep danh sach theo ten.\n";
}

// Ham sap xep danh sach sinh vien theo diem dung sap xep noi bot 
void sapXepTheoDiem(SinhVien* &head) {
    if (head == NULL || head->next == NULL) {
        cout << "Danh sach sinh vien rong hoac chi co 1 sinh vien, khong can sap xep.\n";
        return;
    }

    bool hoanDoi;
    do {
        hoanDoi = false;
        SinhVien* hienTai = head;
        while (hienTai->next != NULL) {
            if (hienTai->diemH10 < hienTai->next->diemH10) {
                swap(hienTai->id, hienTai->next->id);
                swap(hienTai->ten, hienTai->next->ten);
                swap(hienTai->diemH10, hienTai->next->diemH10);
                swap(hienTai->diemH4, hienTai->next->diemH4);
                swap(hienTai->diemChu, hienTai->next->diemChu);
                hoanDoi = true;
            }
            hienTai = hienTai->next;
        }
    } while (hoanDoi);
    cout << "Da sap xep danh sach theo diem.\n";
}

// Ham tinh diem trung binh he 10, gpa trung binh và diem chu trung binh cua tat ca sinh vien
void tinhDiemTrungBinh(SinhVien* head, float &diemTBH10, float &gpaTB, string &diemChuTB) {
    if (head == NULL) {
        cout << "Danh sach sinh vien rong.\n";
        diemTBH10 = 0.0;
        gpaTB = 0.0;
        diemChuTB = "F";
        return;
    }
    
    float tongDiemH10 = 0.0;
    float tongGPA = 0.0;
    int soLuongSinhVien = 0;

    SinhVien* hienTai = head;
    while (hienTai != NULL) {
        tongDiemH10 += hienTai->diemH10;
        tongGPA += hienTai->diemH4;
        soLuongSinhVien++;
        hienTai = hienTai->next;
    }

    // Tra ve diem trung binh la tong diem chia cho so luong sinh vien
    diemTBH10 =  tongDiemH10 / soLuongSinhVien;
    gpaTB =  tongGPA / soLuongSinhVien;
    
   // Tinh diem he chu trung binh
   if(gpaTB<1.0) {
   	diemChuTB = "F";
   	} else if(gpaTB>=1.0 && gpaTB<1.5) {
   		diemChuTB = "D";
   	} else if(gpaTB>=1.5 && gpaTB<2.0) {
   		diemChuTB = "D+";
   	} else if(gpaTB>=2.0 && gpaTB<2.5) {
   		diemChuTB = "C";
   	} else if(gpaTB>=2.5 && gpaTB<3.2) {
   		diemChuTB = "B";
   	} else if(gpaTB>=3.2 && gpaTB<3.6) {
   		diemChuTB = "A";
   	} else if(gpaTB>=3.6 && gpaTB<=4.0) {
   		diemChuTB = "A+";
    }
}
// Ham in danh sach sinh vien
void inDanhSach(SinhVien* head) {
    if (head == NULL) {
        cout << "Danh sach sinh vien rong.\n";
        
        return;
    }

    cout << "Danh sach sinh vien:\n";
    SinhVien* hienTai = head;
    while (hienTai != NULL) {
        cout << "Ma so: " << hienTai->id << endl;
        cout << "Ten: " << hienTai->ten << endl;
        cout << "Diem: " << hienTai->diemH10 << " (GPA: " << hienTai->diemH4 << "; diem he Chu: " << hienTai->diemChu << ")" << endl;
        hienTai = hienTai->next;
    }
}

