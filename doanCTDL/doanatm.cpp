/*
Nhom X: 4 Thanh vien
Gom co:
Ngo ngoc Dien
Cao Thanh Dat
Ho Khac Linh
Nguyen Van Thai
*/

#include<iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <ctime>
#include <stdio.h>
#include <conio.h>
#include <Windows.h>
#include <cctype>
#pragma warning(disable : 4996)
#define _CRT_SECURE_NO_WARNINGS
using namespace std;

//khai bao struct 
struct GiaoDich
{
	string sLoaiGD = " ", sNgThgNam = " ", sGiPhGiay = " ", 
		sSoTienThucHien = " ", sSoDuConLai = " ", sTuKhoa = " ",
		sTKGD = " ", sTenChuTheGD = " ";
};
struct BANKER
{
	GiaoDich gd;
	string sID = " ", sPin = " ";
	int nSotien = 0;
	string sTenChuThe = " ";
	string sTienTe = " ";
};
struct Node
{
	BANKER xData;
	Node *pNext;
};
struct LinkedList
{
	Node *pHead;
	Node *pTail;
	LinkedList()
	{
		pTail = pHead = NULL;
	}
};

//khai bao nguyen mau ham con:
Node * createNode(BANKER nX);
void addHead(LinkedList &L, Node *p);
void addTail(LinkedList &L, Node *p);

//Ma hoa ,Mau va lay ngay gioi he thong:
string passwordInput(unsigned maxLength);
string kiemTraTime(string sA, Node * p);
void Color(int nX);

//doc, ghi, xuat  thong tin va in hoa don: 
void ghiUser(LinkedList &L, Node *p);
void xuatThongTinUser(BANKER nX);
void xuatTT(LinkedList L);
void docuser(LinkedList &L);
void xuatThongTinUser(BANKER nX);
void xuatTTLichSuGD(LinkedList L);
void ghiLichSuChuyenTien(LinkedList L, Node * p, int nTienTru, Node *q);
void ghiLichSuNhanTien(LinkedList L, Node * p, int nTienTru, Node *q);
void ghiLichSuRutTien(LinkedList L, Node * p, int nTienTru);
void ghiLichSuNapTien(LinkedList L, Node * p, int nTienNap);
void inHoaDonChuyenTien(LinkedList L, Node *p, int nTienTru, Node *q);
void inHoaDonNhanTien(LinkedList L, Node *p, int nTienTru, Node *q);
void inHoaDonRutTien(LinkedList L, Node * p, int nTienTru);
void inHoaDonNapTien(LinkedList L, Node * p, int nTienNap);
void docLichSuGD(Node * p);
//dang nhap va Menu chinh:
void Menu(LinkedList L);
void dangnhap(LinkedList L);

//doi mat khau:
void doiMatKhau(LinkedList L, Node *p);

//Nap, chuyen va rut tien:
void MenuRutTien(LinkedList L, Node * p);
void MenuChuyenTien(LinkedList L, Node * p);
void napTienOnline(LinkedList L, Node * p);
void mangViettel(LinkedList L, Node * p);
void mangVinaphone(LinkedList L, Node * p);
void mangMobiPhone(LinkedList L, Node * p);
void mangVietnammobile(LinkedList L, Node * p);

//chuong trinh chinh:
string sUser = " ", sMapin = " ", sKey = " ", sSTKChuyenTien = " ";
int nTimes = 0, nDem = 0, nChon = 0;
void main()
{
	LinkedList L;
	BANKER nX;
	int nN = 0;
	docuser(L);
	dangnhap(L);
	system("pause");
}
//dinh nghia nguyen mau ham con:

//Nap, chuyen va rut tien:
void mangVietnammobile(LinkedList L, Node * p)
{
	do {
		system("cls"); Color(10);
		cout << "\n\t\t\t\t\t*********************************\n";
		Color(10); cout << "\n\t\t\t\t\t* "; Color(14);  cout << "       Mang Vietnammobile    \t"; Color(10); cout << "*\n";
		cout << "\n\t\t\t\t\t*********************************\n";
		Color(14);
		cout << "\t\t\t\t1.Nap 50000\n";
		cout << "\t\t\t\t2.Nap 100000\n";
		cout << "\t\t\t\t3.Nap 200000\n";
		cout << "\t\t\t\t4.Nap 500000\n";
		cout << "\t\t\t\t5.tro ve Menu Nap Tien!!\n";
		cout << "\t\t\t\t-----------------------------------------\n";
		cout << "\t\tBan chon So Tien 1-4: ";
		cin >> nChon;
		switch (nChon)
		{
		case 1:
		{
			for (Node *p = L.pHead; p != NULL; p = p->pNext)
			{
				if (sUser == p->xData.sID)
				{
					string sKiemTra = "";
					Color(10);
					cout << "\t\t\t\tXac Nhan Nap Tien\n";
					Color(3);
					cout << "\t\t\tSo TK Nap: " << p->xData.sID << endl;
					cout << "\t\t\tTen Chu The: " << p->xData.sTenChuThe << endl;
					cout << "\t\t\tSo Du Hien Tai: " << p->xData.nSotien << " " << p->xData.sTienTe << endl;
					cout << "\t\t\tSo Du sau khi Nap: " << p->xData.nSotien + 50000 << " " << p->xData.sTienTe << endl;
					cout << "\tNhap "; Color(10);
					cout << "Mat Khau"; Color(3);
					cout << " De Xac Nhan Lenh Nap Tien. Nhap "; Color(4);
					cout << "NO"; Color(3);
					cout << " De Huy Lenh Nap Tien: "; Color(7);
				aa:
					sKiemTra = passwordInput(6);
					if (sKiemTra == p->xData.sPin)
					{
						p->xData.nSotien = p->xData.nSotien + 50000;
						Color(10);
						cout << "\t\t\tBan da Nap Tien thanh cong !" << endl;
						cout << "\t\t\tSo Du sau khi Nap: " << p->xData.nSotien << " " << p->xData.sTienTe << endl;
						Color(7);
						//ghi du lieu da rut tien lai:
						ghiUser(L, p);
						ghiLichSuNapTien(L, p, 50000);
					ff:
						Color(9);
						cout << "Quy khach co muon in hoa don khong ? Muon thi nhap yes/YES con khong thi nhap no/NO: ";
						rewind(stdin);
						getline(cin, sKey);
						if (sKey == "yes" || sKey == "YES")
						{
							inHoaDonNapTien(L, p, 50000);
							cout << "In Hoa Don Thanh Cong!!"; Sleep(2000);
						}
						else if (sKey == "no" || sKey == "NO")
						{
							cout << "Cam on quy khach da su dung dich vu cua chung toi!!"; Sleep(2000);
						}
						else
						{
							cout << "Quy khach da nhap sai vui long nhap lai!!\n";
							goto ff;
						}
					}

					else if (sKiemTra == "no" || sKiemTra == "NO")
					{
						Color(11);
						cout << "\t\t\tLenh Nap Tien Da Huy\n";
						system("pause");
					}
					else
					{
						Color(14);
						cout << "\t\t\tNhap Sai!!. Vui long nhap lai: ";
						goto aa;
					}
				}
			}
			break;
		}
		case 2:
		{
			for (Node *p = L.pHead; p != NULL; p = p->pNext)
			{
				if (sUser == p->xData.sID)
				{
					string sKiemTra = "";
					Color(10);
					cout << "\t\t\t\tXac Nhan Nap Tien\n";
					Color(3);
					cout << "\t\t\tSo TK Nap: " << p->xData.sID << endl;
					cout << "\t\t\tTen Chu The: " << p->xData.sTenChuThe << endl;
					cout << "\t\t\tSo Du Hien Tai: " << p->xData.nSotien << " " << p->xData.sTienTe << endl;
					cout << "\t\t\tSo Du sau khi Nap: " << p->xData.nSotien + 100000 << " " << p->xData.sTienTe << endl;
					cout << "\tNhap "; Color(10);
					cout << "Mat Khau"; Color(3);
					cout << " De Xac Nhan Lenh Nap Tien. Nhap "; Color(4);
					cout << "NO"; Color(3);
					cout << " De Huy Lenh Nap Tien: "; Color(7);
				bb:
					sKiemTra = passwordInput(6);
					if (sKiemTra == p->xData.sPin)
					{
						p->xData.nSotien = p->xData.nSotien + 100000;
						Color(10);
						cout << "\t\t\tBan da Nap Tien thanh cong !" << endl;
						cout << "\t\t\tSo Du sau khi Nap: " << p->xData.nSotien << " " << p->xData.sTienTe << endl;
						Color(7);
						//ghi du lieu da rut tien lai:
						ghiUser(L, p);
						ghiLichSuNapTien(L, p, 100000);
					gg:
						Color(9);
						cout << "Quy khach co muon in hoa don khong ? Muon thi nhap yes/YES con khong thi nhap no/NO: ";
						rewind(stdin);
						getline(cin, sKey);
						if (sKey == "yes" || sKey == "YES")
						{
							inHoaDonNapTien(L, p, 100000);
							cout << "In Hoa Don Thanh Cong!!"; Sleep(2000);
						}
						else if (sKey == "no" || sKey == "NO")
						{
							cout << "Cam on quy khach da su dung dich vu cua chung toi!!"; Sleep(2000);
						}
						else
						{
							cout << "Quy khach da nhap sai vui long nhap lai!!\n";
							goto gg;
						}
					}

					else if (sKiemTra == "no" || sKiemTra == "NO")
					{
						Color(11);
						cout << "\t\t\tLenh Nap Tien Da Huy\n";
						system("pause");
					}
					else
					{
						Color(14);
						cout << "\t\t\tNhap Sai!!. Vui long nhap lai: ";
						goto bb;
					}
				}
			}
			break;
		}
		case 3:
		{
			for (Node *p = L.pHead; p != NULL; p = p->pNext)
			{
				if (sUser == p->xData.sID)
				{
					string sKiemTra = "";
					Color(10);
					cout << "\t\t\t\tXac Nhan Nap Tien\n";
					Color(3);
					cout << "\t\t\tSo TK Nap: " << p->xData.sID << endl;
					cout << "\t\t\tTen Chu The: " << p->xData.sTenChuThe << endl;
					cout << "\t\t\tSo Du Hien Tai: " << p->xData.nSotien << " " << p->xData.sTienTe << endl;
					cout << "\t\t\tSo Du sau khi Nap: " << p->xData.nSotien + 200000 << " " << p->xData.sTienTe << endl;
					cout << "\tNhap "; Color(10);
					cout << "Mat Khau"; Color(3);
					cout << " De Xac Nhan Lenh Nap Tien. Nhap "; Color(4);
					cout << "NO"; Color(3);
					cout << " De Huy Lenh Nap Tien: "; Color(7);
				cc:
					sKiemTra = passwordInput(6);
					if (sKiemTra == p->xData.sPin)
					{
						p->xData.nSotien = p->xData.nSotien + 200000;
						Color(10);
						cout << "\t\t\tBan da Nap Tien thanh cong !" << endl;
						cout << "\t\t\tSo Du sau khi Nap: " << p->xData.nSotien << " " << p->xData.sTienTe << endl;
						Color(7);
						//ghi du lieu da rut tien lai:
						ghiUser(L, p);
						ghiLichSuNapTien(L, p, 200000);
					hh:
						Color(9);
						cout << "Quy khach co muon in hoa don khong ? Muon thi nhap yes/YES con khong thi nhap no/NO: ";
						rewind(stdin);
						getline(cin, sKey);
						if (sKey == "yes" || sKey == "YES")
						{
							inHoaDonNapTien(L, p, 200000);
							cout << "In Hoa Don Thanh Cong!!"; Sleep(2000);
						}
						else if (sKey == "no" || sKey == "NO")
						{
							cout << "Cam on quy khach da su dung dich vu cua chung toi!!"; Sleep(2000);
						}
						else
						{
							cout << "Quy khach da nhap sai vui long nhap lai!!\n";
							goto hh;
						}
					}

					else if (sKiemTra == "no" || sKiemTra == "NO")
					{
						Color(11);
						cout << "\t\t\tLenh Nap Tien Da Huy\n";
						system("pause");
					}
					else
					{
						Color(14);
						cout << "\t\t\tNhap Sai!!. Vui long nhap lai: ";
						goto cc;
					}
				}
			}
			break;
		}
		case 4:
		{
			for (Node *p = L.pHead; p != NULL; p = p->pNext)
			{
				if (sUser == p->xData.sID)
				{
					string sKiemTra = "";
					Color(10);
					cout << "\t\t\t\tXac Nhan Nap Tien\n";
					Color(3);
					cout << "\t\t\tSo TK Nap: " << p->xData.sID << endl;
					cout << "\t\t\tTen Chu The: " << p->xData.sTenChuThe << endl;
					cout << "\t\t\tSo Du Hien Tai: " << p->xData.nSotien << " " << p->xData.sTienTe << endl;
					cout << "\t\t\tSo Du sau khi Nap: " << p->xData.nSotien + 500000 << " " << p->xData.sTienTe << endl;
					cout << "\tNhap "; Color(10);
					cout << "Mat Khau"; Color(3);
					cout << " De Xac Nhan Lenh Nap Tien. Nhap "; Color(4);
					cout << "NO"; Color(3);
					cout << " De Huy Lenh Nap Tien: "; Color(7);
				dd:
					sKiemTra = passwordInput(6);
					if (sKiemTra == p->xData.sPin)
					{
						p->xData.nSotien = p->xData.nSotien + 500000;
						Color(10);
						cout << "\t\t\tBan da Nap Tien thanh cong !" << endl;
						cout << "\t\t\tSo Du sau khi Nap: " << p->xData.nSotien << " " << p->xData.sTienTe << endl;
						Color(7);
						//ghi du lieu da rut tien lai:
						ghiUser(L, p);
						ghiLichSuNapTien(L, p, 500000);
					jj:
						Color(9);
						cout << "Quy khach co muon in hoa don khong ? Muon thi nhap yes/YES con khong thi nhap no/NO: ";
						rewind(stdin);
						getline(cin, sKey);
						if (sKey == "yes" || sKey == "YES")
						{
							inHoaDonNapTien(L, p, 500000);
							cout << "In Hoa Don Thanh Cong!!"; Sleep(2000);
						}
						else if (sKey == "no" || sKey == "NO")
						{
							cout << "Cam on quy khach da su dung dich vu cua chung toi!!"; Sleep(2000);
						}
						else
						{
							cout << "Quy khach da nhap sai vui long nhap lai!!\n";
							goto jj;
						}
					}

					else if (sKiemTra == "no" || sKiemTra == "NO")
					{
						Color(11);
						cout << "\t\t\tLenh Nap Tien Da Huy\n";
						system("pause");
					}
					else
					{
						Color(14);
						cout << "\t\t\tNhap Sai!!. Vui long nhap lai: ";
						goto dd;
					}
				}
			}
			break;
		}
		default:
		{
			cout << "Tro ve Menu Nap Tien!!"; Sleep(1000);
			return;
			break;
		}
		}
	} while (nChon >= 1 || nChon <= 4);
}
void mangMobiPhone(LinkedList L, Node * p)
{
	do {
		system("cls"); Color(10);
		cout << "\n\t\t\t\t\t*********************************\n";
		Color(10); cout << "\n\t\t\t\t\t* "; Color(14);  cout << "       Mang MobiPhone    \t"; Color(10); cout << "*\n";
		cout << "\n\t\t\t\t\t*********************************\n";
		Color(14);
		cout << "\t\t\t\t1.Nap 50000\n";
		cout << "\t\t\t\t2.Nap 100000\n";
		cout << "\t\t\t\t3.Nap 200000\n";
		cout << "\t\t\t\t4.Nap 500000\n";
		cout << "\t\t\t\t5.tro ve Menu Nap Tien!!\n";
		cout << "\t\t\t\t-----------------------------------------\n";
		cout << "\t\tBan chon So Tien 1-4: ";
		cin >> nChon;
		switch (nChon)
		{
		case 1:
		{
			for (Node *p = L.pHead; p != NULL; p = p->pNext)
			{
				if (sUser == p->xData.sID)
				{
					string sKiemTra = "";
					Color(10);
					cout << "\t\t\t\tXac Nhan Nap Tien\n";
					Color(3);
					cout << "\t\t\tSo TK Nap: " << p->xData.sID << endl;
					cout << "\t\t\tTen Chu The: " << p->xData.sTenChuThe << endl;
					cout << "\t\t\tSo Du Hien Tai: " << p->xData.nSotien << " " << p->xData.sTienTe << endl;
					cout << "\t\t\tSo Du sau khi Nap: " << p->xData.nSotien + 50000 << " " << p->xData.sTienTe << endl;
					cout << "\tNhap "; Color(10);
					cout << "Mat Khau"; Color(3);
					cout << " De Xac Nhan Lenh Nap Tien. Nhap "; Color(4);
					cout << "NO"; Color(3);
					cout << " De Huy Lenh Nap Tien: "; Color(7);
				aa:
					sKiemTra = passwordInput(6);
					if (sKiemTra == p->xData.sPin)
					{
						p->xData.nSotien = p->xData.nSotien + 50000;
						Color(10);
						cout << "\t\t\tBan da Nap Tien thanh cong !" << endl;
						cout << "\t\t\tSo Du sau khi Nap: " << p->xData.nSotien << " " << p->xData.sTienTe << endl;
						Color(7);
						//ghi du lieu da rut tien lai:
						ghiUser(L, p);
						ghiLichSuNapTien(L, p, 50000);
					ff:
						Color(9);
						cout << "Quy khach co muon in hoa don khong ? Muon thi nhap yes/YES con khong thi nhap no/NO: ";
						rewind(stdin);
						getline(cin, sKey);
						if (sKey == "yes" || sKey == "YES")
						{
							inHoaDonNapTien(L, p, 50000);
							cout << "In Hoa Don Thanh Cong!!"; Sleep(2000);
						}
						else if (sKey == "no" || sKey == "NO")
						{
							cout << "Cam on quy khach da su dung dich vu cua chung toi!!"; Sleep(2000);
						}
						else
						{
							cout << "Quy khach da nhap sai vui long nhap lai!!\n";
							goto ff;
						}
					}

					else if (sKiemTra == "no" || sKiemTra == "NO")
					{
						Color(11);
						cout << "\t\t\tLenh Nap Tien Da Huy\n";
						system("pause");
					}
					else
					{
						Color(14);
						cout << "\t\t\tNhap Sai!!. Vui long nhap lai: ";
						goto aa;
					}
				}
			}
			break;
		}
		case 2:
		{
			for (Node *p = L.pHead; p != NULL; p = p->pNext)
			{
				if (sUser == p->xData.sID)
				{
					string sKiemTra = "";
					Color(10);
					cout << "\t\t\t\tXac Nhan Nap Tien\n";
					Color(3);
					cout << "\t\t\tSo TK Nap: " << p->xData.sID << endl;
					cout << "\t\t\tTen Chu The: " << p->xData.sTenChuThe << endl;
					cout << "\t\t\tSo Du Hien Tai: " << p->xData.nSotien << " " << p->xData.sTienTe << endl;
					cout << "\t\t\tSo Du sau khi Nap: " << p->xData.nSotien + 100000 << " " << p->xData.sTienTe << endl;
					cout << "\tNhap "; Color(10);
					cout << "Mat Khau"; Color(3);
					cout << " De Xac Nhan Lenh Nap Tien. Nhap "; Color(4);
					cout << "NO"; Color(3);
					cout << " De Huy Lenh Nap Tien: "; Color(7);
				bb:
					sKiemTra = passwordInput(6);
					if (sKiemTra == p->xData.sPin)
					{
						p->xData.nSotien = p->xData.nSotien + 100000;
						Color(10);
						cout << "\t\t\tBan da Nap Tien thanh cong !" << endl;
						cout << "\t\t\tSo Du sau khi Nap: " << p->xData.nSotien << " " << p->xData.sTienTe << endl;
						Color(7);
						//ghi du lieu da rut tien lai:
						ghiUser(L, p);
						ghiLichSuNapTien(L, p, 100000);
					gg:
						Color(9);
						cout << "Quy khach co muon in hoa don khong ? Muon thi nhap yes/YES con khong thi nhap no/NO: ";
						rewind(stdin);
						getline(cin, sKey);
						if (sKey == "yes" || sKey == "YES")
						{
							inHoaDonNapTien(L, p, 100000);
							cout << "In Hoa Don Thanh Cong!!"; Sleep(2000);
						}
						else if (sKey == "no" || sKey == "NO")
						{
							cout << "Cam on quy khach da su dung dich vu cua chung toi!!"; Sleep(2000);
						}
						else
						{
							cout << "Quy khach da nhap sai vui long nhap lai!!\n";
							goto gg;
						}
					}

					else if (sKiemTra == "no" || sKiemTra == "NO")
					{
						Color(11);
						cout << "\t\t\tLenh Nap Tien Da Huy\n";
						system("pause");
					}
					else
					{
						Color(14);
						cout << "\t\t\tNhap Sai!!. Vui long nhap lai: ";
						goto bb;
					}
				}
			}
			break;
		}
		case 3:
		{
			for (Node *p = L.pHead; p != NULL; p = p->pNext)
			{
				if (sUser == p->xData.sID)
				{
					string sKiemTra = "";
					Color(10);
					cout << "\t\t\t\tXac Nhan Nap Tien\n";
					Color(3);
					cout << "\t\t\tSo TK Nap: " << p->xData.sID << endl;
					cout << "\t\t\tTen Chu The: " << p->xData.sTenChuThe << endl;
					cout << "\t\t\tSo Du Hien Tai: " << p->xData.nSotien << " " << p->xData.sTienTe << endl;
					cout << "\t\t\tSo Du sau khi Nap: " << p->xData.nSotien + 200000 << " " << p->xData.sTienTe << endl;
					cout << "\tNhap "; Color(10);
					cout << "Mat Khau"; Color(3);
					cout << " De Xac Nhan Lenh Nap Tien. Nhap "; Color(4);
					cout << "NO"; Color(3);
					cout << " De Huy Lenh Nap Tien: "; Color(7);
				cc:
					sKiemTra = passwordInput(6);
					if (sKiemTra == p->xData.sPin)
					{
						p->xData.nSotien = p->xData.nSotien + 200000;
						Color(10);
						cout << "\t\t\tBan da Nap Tien thanh cong !" << endl;
						cout << "\t\t\tSo Du sau khi Nap: " << p->xData.nSotien << " " << p->xData.sTienTe << endl;
						Color(7);
						//ghi du lieu da rut tien lai:
						ghiUser(L, p);
						ghiLichSuNapTien(L, p, 200000);
					hh:
						Color(9);
						cout << "Quy khach co muon in hoa don khong ? Muon thi nhap yes/YES con khong thi nhap no/NO: ";
						rewind(stdin);
						getline(cin, sKey);
						if (sKey == "yes" || sKey == "YES")
						{
							inHoaDonNapTien(L, p, 200000);
							cout << "In Hoa Don Thanh Cong!!"; Sleep(2000);
						}
						else if (sKey == "no" || sKey == "NO")
						{
							cout << "Cam on quy khach da su dung dich vu cua chung toi!!"; Sleep(2000);
						}
						else
						{
							cout << "Quy khach da nhap sai vui long nhap lai!!\n";
							goto hh;
						}
					}

					else if (sKiemTra == "no" || sKiemTra == "NO")
					{
						Color(11);
						cout << "\t\t\tLenh Nap Tien Da Huy\n";
						system("pause");
					}
					else
					{
						Color(14);
						cout << "\t\t\tNhap Sai!!. Vui long nhap lai: ";
						goto cc;
					}
				}
			}
			break;
		}
		case 4:
		{
			for (Node *p = L.pHead; p != NULL; p = p->pNext)
			{
				if (sUser == p->xData.sID)
				{
					string sKiemTra = "";
					Color(10);
					cout << "\t\t\t\tXac Nhan Nap Tien\n";
					Color(3);
					cout << "\t\t\tSo TK Nap: " << p->xData.sID << endl;
					cout << "\t\t\tTen Chu The: " << p->xData.sTenChuThe << endl;
					cout << "\t\t\tSo Du Hien Tai: " << p->xData.nSotien << " " << p->xData.sTienTe << endl;
					cout << "\t\t\tSo Du sau khi Nap: " << p->xData.nSotien + 500000 << " " << p->xData.sTienTe << endl;
					cout << "\tNhap "; Color(10);
					cout << "Mat Khau"; Color(3);
					cout << " De Xac Nhan Lenh Nap Tien. Nhap "; Color(4);
					cout << "NO"; Color(3);
					cout << " De Huy Lenh Nap Tien: "; Color(7);
				dd:
					sKiemTra = passwordInput(6);
					if (sKiemTra == p->xData.sPin)
					{
						p->xData.nSotien = p->xData.nSotien + 500000;
						Color(10);
						cout << "\t\t\tBan da Nap Tien thanh cong !" << endl;
						cout << "\t\t\tSo Du sau khi Nap: " << p->xData.nSotien << " " << p->xData.sTienTe << endl;
						Color(7);
						//ghi du lieu da rut tien lai:
						ghiUser(L, p);
						ghiLichSuNapTien(L, p, 500000);
					jj:
						Color(9);
						cout << "Quy khach co muon in hoa don khong ? Muon thi nhap yes/YES con khong thi nhap no/NO: ";
						rewind(stdin);
						getline(cin, sKey);
						if (sKey == "yes" || sKey == "YES")
						{
							inHoaDonNapTien(L, p, 500000);
							cout << "In Hoa Don Thanh Cong!!"; Sleep(2000);
						}
						else if (sKey == "no" || sKey == "NO")
						{
							cout << "Cam on quy khach da su dung dich vu cua chung toi!!"; Sleep(2000);
						}
						else
						{
							cout << "Quy khach da nhap sai vui long nhap lai!!\n";
							goto jj;
						}
					}

					else if (sKiemTra == "no" || sKiemTra == "NO")
					{
						Color(11);
						cout << "\t\t\tLenh Nap Tien Da Huy\n";
						system("pause");
					}
					else
					{
						Color(14);
						cout << "\t\t\tNhap Sai!!. Vui long nhap lai: ";
						goto dd;
					}
				}
			}
			break;
		}
		default:
		{
			cout << "Tro ve Menu Nap Tien!!"; Sleep(1000);
			return;
			break;
		}
		}
	} while (nChon >= 1 || nChon <= 4);
}
void mangViettel(LinkedList L, Node * p)
{
	do {
		system("cls"); Color(10);
		cout << "\n\t\t\t\t\t*********************************\n";
		Color(10); cout << "\n\t\t\t\t\t* "; Color(14);  cout << "       Mang Viettel    \t"; Color(10); cout << "*\n";
		cout << "\n\t\t\t\t\t*********************************\n";
		Color(14);
		cout << "\t\t\t\t1.Nap 50000\n";
		cout << "\t\t\t\t2.Nap 100000\n";
		cout << "\t\t\t\t3.Nap 200000\n";
		cout << "\t\t\t\t4.Nap 500000\n";
		cout << "\t\t\t\t5.tro ve Menu Nap Tien!!\n";
		cout << "\t\t\t\t-----------------------------------------\n";
		cout << "\t\tBan chon So Tien 1-4: ";
		cin >> nChon;
		switch (nChon)
		{
		case 1:
		{
			for (Node *p = L.pHead; p != NULL; p = p->pNext)
			{
				if (sUser == p->xData.sID)
				{
					string sKiemTra = "";
					Color(10);
					cout << "\t\t\t\tXac Nhan Nap Tien\n";
					Color(3);
					cout << "\t\t\tSo TK Nap: " << p->xData.sID << endl;
					cout << "\t\t\tTen Chu The: " << p->xData.sTenChuThe << endl;
					cout << "\t\t\tSo Du Hien Tai: " << p->xData.nSotien << " " << p->xData.sTienTe << endl;
					cout << "\t\t\tSo Du sau khi Nap: " << p->xData.nSotien + 50000 << " " << p->xData.sTienTe << endl;
					cout << "\tNhap "; Color(10);
					cout << "Mat Khau"; Color(3);
					cout << " De Xac Nhan Lenh Nap Tien. Nhap "; Color(4);
					cout << "NO"; Color(3);
					cout << " De Huy Lenh Nap Tien: "; Color(7);
				aa:
					sKiemTra = passwordInput(6);
					if (sKiemTra == p->xData.sPin)
					{
						p->xData.nSotien = p->xData.nSotien + 50000;
						Color(10);
						cout << "\t\t\tBan da Nap Tien thanh cong !" << endl;
						cout << "\t\t\tSo Du sau khi Nap: " << p->xData.nSotien << " " << p->xData.sTienTe << endl;
						Color(7);
						//ghi du lieu da rut tien lai:
						ghiUser(L, p);
						ghiLichSuNapTien(L, p, 50000);
					ff:
						Color(9);
						cout << "Quy khach co muon in hoa don khong ? Muon thi nhap yes/YES con khong thi nhap no/NO: ";
						rewind(stdin);
						getline(cin, sKey);
						if (sKey == "yes" || sKey == "YES")
						{
							inHoaDonNapTien(L, p, 50000);
							cout << "In Hoa Don Thanh Cong!!"; Sleep(2000);
						}
						else if (sKey == "no" || sKey == "NO")
						{
							cout << "Cam on quy khach da su dung dich vu cua chung toi!!"; Sleep(2000);
						}
						else
						{
							cout << "Quy khach da nhap sai vui long nhap lai!!\n";
							goto ff;
						}
					}

					else if (sKiemTra == "no" || sKiemTra == "NO")
					{
						Color(11);
						cout << "\t\t\tLenh Nap Tien Da Huy\n";
						system("pause");
					}
					else
					{
						Color(14);
						cout << "\t\t\tNhap Sai!!. Vui long nhap lai: ";
						goto aa;
					}
				}
			}
			break;
		}
		case 2:
		{
			for (Node *p = L.pHead; p != NULL; p = p->pNext)
			{
				if (sUser == p->xData.sID)
				{
					string sKiemTra = "";
					Color(10);
					cout << "\t\t\t\tXac Nhan Nap Tien\n";
					Color(3);
					cout << "\t\t\tSo TK Nap: " << p->xData.sID << endl;
					cout << "\t\t\tTen Chu The: " << p->xData.sTenChuThe << endl;
					cout << "\t\t\tSo Du Hien Tai: " << p->xData.nSotien << " " << p->xData.sTienTe << endl;
					cout << "\t\t\tSo Du sau khi Nap: " << p->xData.nSotien + 100000 << " " << p->xData.sTienTe << endl;
					cout << "\tNhap "; Color(10);
					cout << "Mat Khau"; Color(3);
					cout << " De Xac Nhan Lenh Nap Tien. Nhap "; Color(4);
					cout << "NO"; Color(3);
					cout << " De Huy Lenh Nap Tien: "; Color(7);
				bb:
					sKiemTra = passwordInput(6);
					if (sKiemTra == p->xData.sPin)
					{
						p->xData.nSotien = p->xData.nSotien + 100000;
						Color(10);
						cout << "\t\t\tBan da Nap Tien thanh cong !" << endl;
						cout << "\t\t\tSo Du sau khi Nap: " << p->xData.nSotien << " " << p->xData.sTienTe << endl;
						Color(7);
						//ghi du lieu da rut tien lai:
						ghiUser(L, p);
						ghiLichSuNapTien(L, p, 100000);
					gg:
						Color(9);
						cout << "Quy khach co muon in hoa don khong ? Muon thi nhap yes/YES con khong thi nhap no/NO: ";
						rewind(stdin);
						getline(cin, sKey);
						if (sKey == "yes" || sKey == "YES")
						{
							inHoaDonNapTien(L, p, 100000);
							cout << "In Hoa Don Thanh Cong!!"; Sleep(2000);
						}
						else if (sKey == "no" || sKey == "NO")
						{
							cout << "Cam on quy khach da su dung dich vu cua chung toi!!"; Sleep(2000);
						}
						else
						{
							cout << "Quy khach da nhap sai vui long nhap lai!!\n";
							goto gg;
						}
					}

					else if (sKiemTra == "no" || sKiemTra == "NO")
					{
						Color(11);
						cout << "\t\t\tLenh Nap Tien Da Huy\n";
						system("pause");
					}
					else
					{
						Color(14);
						cout << "\t\t\tNhap Sai!!. Vui long nhap lai: ";
						goto bb;
					}
				}
			}
			break;
		}
		case 3:
		{
			for (Node *p = L.pHead; p != NULL; p = p->pNext)
			{
				if (sUser == p->xData.sID)
				{
					string sKiemTra = "";
					Color(10);
					cout << "\t\t\t\tXac Nhan Nap Tien\n";
					Color(3);
					cout << "\t\t\tSo TK Nap: " << p->xData.sID << endl;
					cout << "\t\t\tTen Chu The: " << p->xData.sTenChuThe << endl;
					cout << "\t\t\tSo Du Hien Tai: " << p->xData.nSotien << " " << p->xData.sTienTe << endl;
					cout << "\t\t\tSo Du sau khi Nap: " << p->xData.nSotien + 200000 << " " << p->xData.sTienTe << endl;
					cout << "\tNhap "; Color(10);
					cout << "Mat Khau"; Color(3);
					cout << " De Xac Nhan Lenh Nap Tien. Nhap "; Color(4);
					cout << "NO"; Color(3);
					cout << " De Huy Lenh Nap Tien: "; Color(7);
				cc:
					sKiemTra = passwordInput(6);
					if (sKiemTra == p->xData.sPin)
					{
						p->xData.nSotien = p->xData.nSotien + 200000;
						Color(10);
						cout << "\t\t\tBan da Nap Tien thanh cong !" << endl;
						cout << "\t\t\tSo Du sau khi Nap: " << p->xData.nSotien << " " << p->xData.sTienTe << endl;
						Color(7);
						//ghi du lieu da rut tien lai:
						ghiUser(L, p);
						ghiLichSuNapTien(L, p, 200000);
					hh:
						Color(9);
						cout << "Quy khach co muon in hoa don khong ? Muon thi nhap yes/YES con khong thi nhap no/NO: ";
						rewind(stdin);
						getline(cin, sKey);
						if (sKey == "yes" || sKey == "YES")
						{
							inHoaDonNapTien(L, p, 200000);
							cout << "In Hoa Don Thanh Cong!!"; Sleep(2000);
						}
						else if (sKey == "no" || sKey == "NO")
						{
							cout << "Cam on quy khach da su dung dich vu cua chung toi!!"; Sleep(2000);
						}
						else
						{
							cout << "Quy khach da nhap sai vui long nhap lai!!\n";
							goto hh;
						}
					}

					else if (sKiemTra == "no" || sKiemTra == "NO")
					{
						Color(11);
						cout << "\t\t\tLenh Nap Tien Da Huy\n";
						system("pause");
					}
					else
					{
						Color(14);
						cout << "\t\t\tNhap Sai!!. Vui long nhap lai: ";
						goto cc;
					}
				}
			}
			break;
		}
		case 4:
		{
			for (Node *p = L.pHead; p != NULL; p = p->pNext)
			{
				if (sUser == p->xData.sID)
				{
					string sKiemTra = "";
					Color(10);
					cout << "\t\t\t\tXac Nhan Nap Tien\n";
					Color(3);
					cout << "\t\t\tSo TK Nap: " << p->xData.sID << endl;
					cout << "\t\t\tTen Chu The: " << p->xData.sTenChuThe << endl;
					cout << "\t\t\tSo Du Hien Tai: " << p->xData.nSotien << " " << p->xData.sTienTe << endl;
					cout << "\t\t\tSo Du sau khi Nap: " << p->xData.nSotien + 500000 << " " << p->xData.sTienTe << endl;
					cout << "\tNhap "; Color(10);
					cout << "Mat Khau"; Color(3);
					cout << " De Xac Nhan Lenh Nap Tien. Nhap "; Color(4);
					cout << "NO"; Color(3);
					cout << " De Huy Lenh Nap Tien: "; Color(7);
				dd:
					sKiemTra = passwordInput(6);
					if (sKiemTra == p->xData.sPin)
					{
						p->xData.nSotien = p->xData.nSotien + 500000;
						Color(10);
						cout << "\t\t\tBan da Nap Tien thanh cong !" << endl;
						cout << "\t\t\tSo Du sau khi Nap: " << p->xData.nSotien << " " << p->xData.sTienTe << endl;
						Color(7);
						//ghi du lieu da rut tien lai:
						ghiUser(L, p);
						ghiLichSuNapTien(L, p, 500000);
					jj:
						Color(9);
						cout << "Quy khach co muon in hoa don khong ? Muon thi nhap yes/YES con khong thi nhap no/NO: ";
						rewind(stdin);
						getline(cin, sKey);
						if (sKey == "yes" || sKey == "YES")
						{
							inHoaDonNapTien(L, p, 500000);
							cout << "In Hoa Don Thanh Cong!!"; Sleep(2000);
						}
						else if (sKey == "no" || sKey == "NO")
						{
							cout << "Cam on quy khach da su dung dich vu cua chung toi!!"; Sleep(2000);
						}
						else
						{
							cout << "Quy khach da nhap sai vui long nhap lai!!\n";
							goto jj;
						}
					}

					else if (sKiemTra == "no" || sKiemTra == "NO")
					{
						Color(11);
						cout << "\t\t\tLenh Nap Tien Da Huy\n";
						system("pause");
					}
					else
					{
						Color(14);
						cout << "\t\t\tNhap Sai!!. Vui long nhap lai: ";
						goto dd;
					}
				}
			}
			break;
		}
		default:
		{
			cout << "Tro ve Menu Nap Tien!!"; Sleep(1000);
			return;
			break;
		}
		}
	} while (nChon >= 1 || nChon <= 4);
}
void mangVinaphone(LinkedList L, Node * p)
{
	do {
		system("cls"); Color(10);
		cout << "\n\t\t\t\t\t*********************************\n";
		Color(10); cout << "\n\t\t\t\t\t* "; Color(14);  cout << "       Mang Vinaphone    \t"; Color(10); cout << "*\n";
		cout << "\n\t\t\t\t\t*********************************\n";
		Color(14);
		cout << "\t\t\t\t1.Nap 50000\n";
		cout << "\t\t\t\t2.Nap 100000\n";
		cout << "\t\t\t\t3.Nap 200000\n";
		cout << "\t\t\t\t4.Nap 500000\n";
		cout << "\t\t\t\t5.tro ve Menu Nap Tien!!\n";
		cout << "\t\t\t\t-----------------------------------------\n";
		cout << "\t\tBan chon So Tien 1-4: ";
		cin >> nChon;
		switch (nChon)
		{
		case 1:
		{
			for (Node *p = L.pHead; p != NULL; p = p->pNext)
			{
				if (sUser == p->xData.sID)
				{
					string sKiemTra = "";
					Color(10);
					cout << "\t\t\t\tXac Nhan Nap Tien\n";
					Color(3);
					cout << "\t\t\tSo TK Nap: " << p->xData.sID << endl;
					cout << "\t\t\tTen Chu The: " << p->xData.sTenChuThe << endl;
					cout << "\t\t\tSo Du Hien Tai: " << p->xData.nSotien << " " << p->xData.sTienTe << endl;
					cout << "\t\t\tSo Du sau khi Nap: " << p->xData.nSotien + 50000 << " " << p->xData.sTienTe << endl;
					cout << "\tNhap "; Color(10);
					cout << "Mat Khau"; Color(3);
					cout << " De Xac Nhan Lenh Nap Tien. Nhap "; Color(4);
					cout << "NO"; Color(3);
					cout << " De Huy Lenh Nap Tien: "; Color(7);
				aa:
					sKiemTra = passwordInput(6);
					if (sKiemTra == p->xData.sPin)
					{
						p->xData.nSotien = p->xData.nSotien + 50000;
						Color(10);
						cout << "\t\t\tBan da Nap Tien thanh cong !" << endl;
						cout << "\t\t\tSo Du sau khi Nap: " << p->xData.nSotien << " " << p->xData.sTienTe << endl;
						Color(7);
						//ghi du lieu da rut tien lai:
						ghiUser(L, p);
						ghiLichSuNapTien(L, p, 50000);
					ff:
						Color(9);
						cout << "Quy khach co muon in hoa don khong ? Muon thi nhap yes/YES con khong thi nhap no/NO: ";
						rewind(stdin);
						getline(cin, sKey);
						if (sKey == "yes" || sKey == "YES")
						{
							inHoaDonNapTien(L, p, 50000);
							cout << "In Hoa Don Thanh Cong!!"; Sleep(2000);
						}
						else if (sKey == "no" || sKey == "NO")
						{
							cout << "Cam on quy khach da su dung dich vu cua chung toi!!"; Sleep(2000);
						}
						else
						{
							cout << "Quy khach da nhap sai vui long nhap lai!!\n";
							goto ff;
						}
					}

					else if (sKiemTra == "no" || sKiemTra == "NO")
					{
						Color(11);
						cout << "\t\t\tLenh Nap Tien Da Huy\n";
						system("pause");
					}
					else
					{
						Color(14);
						cout << "\t\t\tNhap Sai!!. Vui long nhap lai: ";
						goto aa;
					}
				}
			}
			break;
		}
		case 2:
		{
			for (Node *p = L.pHead; p != NULL; p = p->pNext)
			{
				if (sUser == p->xData.sID)
				{
					string sKiemTra = "";
					Color(10);
					cout << "\t\t\t\tXac Nhan Nap Tien\n";
					Color(3);
					cout << "\t\t\tSo TK Nap: " << p->xData.sID << endl;
					cout << "\t\t\tTen Chu The: " << p->xData.sTenChuThe << endl;
					cout << "\t\t\tSo Du Hien Tai: " << p->xData.nSotien << " " << p->xData.sTienTe << endl;
					cout << "\t\t\tSo Du sau khi Nap: " << p->xData.nSotien + 100000 << " " << p->xData.sTienTe << endl;
					cout << "\tNhap "; Color(10);
					cout << "Mat Khau"; Color(3);
					cout << " De Xac Nhan Lenh Nap Tien. Nhap "; Color(4);
					cout << "NO"; Color(3);
					cout << " De Huy Lenh Nap Tien: "; Color(7);
				bb:
					sKiemTra = passwordInput(6);
					if (sKiemTra == p->xData.sPin)
					{
						p->xData.nSotien = p->xData.nSotien + 100000;
						Color(10);
						cout << "\t\t\tBan da Nap Tien thanh cong !" << endl;
						cout << "\t\t\tSo Du sau khi Nap: " << p->xData.nSotien << " " << p->xData.sTienTe << endl;
						Color(7);
						//ghi du lieu da rut tien lai:
						ghiUser(L, p);
						ghiLichSuNapTien(L, p, 100000);
					gg:
						Color(9);
						cout << "Quy khach co muon in hoa don khong ? Muon thi nhap yes/YES con khong thi nhap no/NO: ";
						rewind(stdin);
						getline(cin, sKey);
						if (sKey == "yes" || sKey == "YES")
						{
							inHoaDonNapTien(L, p, 100000);
							cout << "In Hoa Don Thanh Cong!!"; Sleep(2000);
						}
						else if (sKey == "no" || sKey == "NO")
						{
							cout << "Cam on quy khach da su dung dich vu cua chung toi!!"; Sleep(2000);
						}
						else
						{
							cout << "Quy khach da nhap sai vui long nhap lai!!\n";
							goto gg;
						}
					}

					else if (sKiemTra == "no" || sKiemTra == "NO")
					{
						Color(11);
						cout << "\t\t\tLenh Nap Tien Da Huy\n";
						system("pause");
					}
					else
					{
						Color(14);
						cout << "\t\t\tNhap Sai!!. Vui long nhap lai: ";
						goto bb;
					}
				}
			}
			break;
		}
		case 3:
		{
			for (Node *p = L.pHead; p != NULL; p = p->pNext)
			{
				if (sUser == p->xData.sID)
				{
					string sKiemTra = "";
					Color(10);
					cout << "\t\t\t\tXac Nhan Nap Tien\n";
					Color(3);
					cout << "\t\t\tSo TK Nap: " << p->xData.sID << endl;
					cout << "\t\t\tTen Chu The: " << p->xData.sTenChuThe << endl;
					cout << "\t\t\tSo Du Hien Tai: " << p->xData.nSotien << " " << p->xData.sTienTe << endl;
					cout << "\t\t\tSo Du sau khi Nap: " << p->xData.nSotien + 200000 << " " << p->xData.sTienTe << endl;
					cout << "\tNhap "; Color(10);
					cout << "Mat Khau"; Color(3);
					cout << " De Xac Nhan Lenh Nap Tien. Nhap "; Color(4);
					cout << "NO"; Color(3);
					cout << " De Huy Lenh Nap Tien: "; Color(7);
				cc:
					sKiemTra = passwordInput(6);
					if (sKiemTra == p->xData.sPin)
					{
						p->xData.nSotien = p->xData.nSotien + 200000;
						Color(10);
						cout << "\t\t\tBan da Nap Tien thanh cong !" << endl;
						cout << "\t\t\tSo Du sau khi Nap: " << p->xData.nSotien << " " << p->xData.sTienTe << endl;
						Color(7);
						//ghi du lieu da rut tien lai:
						ghiUser(L, p);
						ghiLichSuNapTien(L, p, 200000);
					hh:
						Color(9);
						cout << "Quy khach co muon in hoa don khong ? Muon thi nhap yes/YES con khong thi nhap no/NO: ";
						rewind(stdin);
						getline(cin, sKey);
						if (sKey == "yes" || sKey == "YES")
						{
							inHoaDonNapTien(L, p, 200000);
							cout << "In Hoa Don Thanh Cong!!"; Sleep(2000);
						}
						else if (sKey == "no" || sKey == "NO")
						{
							cout << "Cam on quy khach da su dung dich vu cua chung toi!!"; Sleep(2000);
						}
						else
						{
							cout << "Quy khach da nhap sai vui long nhap lai!!\n";
							goto hh;
						}
					}

					else if (sKiemTra == "no" || sKiemTra == "NO")
					{
						Color(11);
						cout << "\t\t\tLenh Nap Tien Da Huy\n";
						system("pause");
					}
					else
					{
						Color(14);
						cout << "\t\t\tNhap Sai!!. Vui long nhap lai: ";
						goto cc;
					}
				}
			}
			break;
		}
		case 4:
		{
			for (Node *p = L.pHead; p != NULL; p = p->pNext)
			{
				if (sUser == p->xData.sID)
				{
					string sKiemTra = "";
					Color(10);
					cout << "\t\t\t\tXac Nhan Nap Tien\n";
					Color(3);
					cout << "\t\t\tSo TK Nap: " << p->xData.sID << endl;
					cout << "\t\t\tTen Chu The: " << p->xData.sTenChuThe << endl;
					cout << "\t\t\tSo Du Hien Tai: " << p->xData.nSotien << " " << p->xData.sTienTe << endl;
					cout << "\t\t\tSo Du sau khi Nap: " << p->xData.nSotien + 500000 << " " << p->xData.sTienTe << endl;
					cout << "\tNhap "; Color(10);
					cout << "Mat Khau"; Color(3);
					cout << " De Xac Nhan Lenh Nap Tien. Nhap "; Color(4);
					cout << "NO"; Color(3);
					cout << " De Huy Lenh Nap Tien: "; Color(7);
				dd:
					sKiemTra = passwordInput(6);
					if (sKiemTra == p->xData.sPin)
					{
						p->xData.nSotien = p->xData.nSotien + 500000;
						Color(10);
						cout << "\t\t\tBan da Nap Tien thanh cong !" << endl;
						cout << "\t\t\tSo Du sau khi Nap: " << p->xData.nSotien << " " << p->xData.sTienTe << endl;
						Color(7);
						//ghi du lieu da rut tien lai:
						ghiUser(L, p);
						ghiLichSuNapTien(L, p, 500000);
					jj:
						Color(9);
						cout << "Quy khach co muon in hoa don khong ? Muon thi nhap yes/YES con khong thi nhap no/NO: ";
						rewind(stdin);
						getline(cin, sKey);
						if (sKey == "yes" || sKey == "YES")
						{
							inHoaDonNapTien(L, p, 500000);
							cout << "In Hoa Don Thanh Cong!!"; Sleep(2000);
						}
						else if (sKey == "no" || sKey == "NO")
						{
							cout << "Cam on quy khach da su dung dich vu cua chung toi!!"; Sleep(2000);
						}
						else
						{
							cout << "Quy khach da nhap sai vui long nhap lai!!\n";
							goto jj;
						}
					}

					else if (sKiemTra == "no" || sKiemTra == "NO")
					{
						Color(11);
						cout << "\t\t\tLenh Nap Tien Da Huy\n";
						system("pause");
					}
					else
					{
						Color(14);
						cout << "\t\t\tNhap Sai!!. Vui long nhap lai: ";
						goto dd;
					}
				}
			}
			break;
		}
		default:
		{
			cout << "Tro ve Menu Nap Tien!!"; Sleep(1000);
			return;
			break;
		}
		}
	} while (nChon >= 1 || nChon <= 4);
}
void napTienOnline(LinkedList L, Node * p)
{
	do {
		system("cls"); Color(10);
		cout << "\n\t\t\t\t\t*********************************\n";
		Color(10); cout << "\n\t\t\t\t\t* "; Color(14);  cout << "       Nap Tien Online    \t"; Color(10); cout << "*\n";
		cout << "\n\t\t\t\t\t*********************************\n";
		Color(14);
		cout << "\t\t\t\t1. Viettel\n";
		cout << "\t\t\t\t2. Vinaphone\n";
		cout << "\t\t\t\t3. Vietnammobile\n";
		cout << "\t\t\t\t4. Mobiphone\n";
		cout << "\t\t\t\t5. Tro ve Menu chinh!!\n";
		cout << "\t\t\t\t-----------------------------------------\n";
		cout << "\t\tBan chon Mang 1-5: ";
		cin >> nChon;
		switch (nChon)
		{
		case 1:
		{
			mangViettel(L, p);
			break;
		}
		case 2:
		{
			mangVinaphone(L, p);
			break;
		}
		case 3:
		{
			mangVietnammobile(L, p);
			break;
		}
		case 4:
		{
			mangMobiPhone(L, p);
			break;
		}
		default:
		{
			cout << "Dang tro ve Menu chinh!"; Sleep(1000);
			return Menu(L);
			break;
		}
		}
	} while (nChon >= 1 || nChon <= 4);
}
void MenuChuyenTien(LinkedList L, Node * p)
{
	int nSotienChuyen = 0;
	int nSoDuKhaDung = p->xData.nSotien - 50000;
	system("cls");
	Color(6);
	cout << "\t\t\t\t*************************" << endl;
	cout << "\t\t\t\t*  ";
	Color(10);
	cout << "   CHUYEN TIEN   \t"; Color(6);
	cout << "*" << endl;
	cout << "\t\t\t\t*************************" << endl;
NhapLai:
	Color(9);
	cout << "\t\tNhap STK Can Chuyen Tien: ";
	rewind(stdin);
	getline(cin, sSTKChuyenTien);

	if (sSTKChuyenTien == sUser)
	{
		Color(11); cout << "\tKhong the chuyen tien cho chinh minh!\n";
		goto NhapLai;
	}

	for (Node *q = L.pHead; q != NULL; q = q->pNext)
	{
		
		if (q->xData.sID == sSTKChuyenTien)
		{

			//kiem tra dieu kien cua so tien nhap vao:
			do
			{
				Color(13);
				cout << "Luu Y: So tien chuyen la boi so cua 50.000 VND va So tien chuyen toi thieu la 100.000 VND va toi da la 50.000.000 VND\n";
				cout << "Nhap so tien muon chuyen: ";
				cin >> nSotienChuyen;
				if (nSotienChuyen >= 100000)
				{

					if (nSotienChuyen <= nSoDuKhaDung)
					{
						for (p = L.pHead; p != NULL; p = p->pNext)
						{

							if (sUser == p->xData.sID)
							{
								Color(14);
								system("cls");
								cout << "\t\t\t\t*******Xac Nhan Chuyen Tien******\n";
								cout << "\t\t\t\tSTK nguoi gui: " << sUser << endl;
								cout << "\t\t\t\tSTK nguoi nhan: " << sSTKChuyenTien << endl;
								cout << "\t\t\t\tSo tien chuyen: " << nSotienChuyen << p->xData.sTienTe << endl;
								cout << "\t\t\t\tSo du hien tai: " << p->xData.nSotien << p->xData.sTienTe << endl;
								cout << "\t\t\t\tSo du con lai: " << p->xData.nSotien - nSotienChuyen << p->xData.sTienTe << endl;
								Color(3);
							}
						}
					nl:
						cout << "\tNhap "; Color(10);
						cout << "Mat Khau"; Color(3);
						cout << " De Xac Nhan Lenh Chuyen Tien. Nhap "; Color(4);
						cout << "NO"; Color(3);
						cout << " De Huy Lenh Chuyen Tien: "; Color(7);
						string sKiemTra = passwordInput(6);
						if (sKiemTra == sMapin)
						{
							for (p = L.pHead; p != NULL; p = p->pNext)
							{
								if (p->xData.sID == sUser && q->xData.sID == sSTKChuyenTien)
								{
									Color(10);
									p->xData.nSotien = p->xData.nSotien - nSotienChuyen;
									cout << "\t\t\t\tChuyen tien thanh cong!!\n";
									cout << "\t\t\t\tso du con lai: " << p->xData.nSotien << endl;
									q->xData.nSotien = q->xData.nSotien + nSotienChuyen;
								}
							}
							ghiUser(L, p);
							ghiLichSuChuyenTien(L, p, nSotienChuyen, q);
							ghiLichSuNhanTien(L, p, nSotienChuyen, q);
						ff:
							cout << "Quy khach co muon in hoa don khong ? Muon thi nhap yes/YES con khong thi nhap no/NO: ";
							rewind(stdin);
							getline(cin, sKey);
							if (sKey == "yes" || sKey == "YES")
							{
								inHoaDonChuyenTien(L, p, nSotienChuyen, q);
								inHoaDonNhanTien(L, p, nSotienChuyen, q);
								cout << "In Hoa Don Thanh Cong!!\n"; Sleep(2000);
							}
							else if (sKey == "no" || sKey == "NO")
							{
								cout << "Cam on quy khach da su dung dich vu cua chung toi!!\n"; Sleep(2000);
							}
							else
							{
								cout << "Quy khach da nhap sai vui long nhap lai!!\n";
								goto ff;
							}
						}
						else if (sKiemTra == "no" || sKiemTra == "NO")
						{
							Color(11);
							cout << "\t\t\tLenh Chuyen Tien Da Huy!!"; Sleep(2000);
						}
						else
						{
							cout << "Mat khau khong chinh xac!Vui long nhap lai mat khau!\n";
							goto nl;
						}
					}
					else if (nSotienChuyen > nSoDuKhaDung)
					{
						cout << "So du khong du de thuc hien giao dich! Vui long thu lai sau!\n";
					}
					
				}
			} while (nSotienChuyen < 100000 || nSotienChuyen > 50000000 || nSotienChuyen % 50 != 0);

		}	
	}

}
void MenuRutTien(LinkedList L, Node * p)
{
	int nNhapTienRut = 0;
	system("cls");
	Color(6);
	cout << "\t\t\t\t*************************" << endl;
	cout << "\t\t\t\t*  ";
	Color(10);
	cout << "\tRUT TIEN\t"; Color(6);
	cout << "*" << endl;
	cout << "\t\t\t\t*************************" << endl;
	Color(7);
	Color(9); cout << "\tSo tien nhap vao phai la boi cua 10.000vnd. Gioi han giao dich tu 50.000vnd den 50.000.000vnd\n";
	do {
	NhapLai:
		Color(9); cout << "\tNhap so tien ban can rut: ";
		Color(9); cin >> nNhapTienRut;

		if (nNhapTienRut % 10000 == 0)
		{
			for (Node *p = L.pHead; p != NULL; p = p->pNext)
			{
				int nSoDuKhaDung = 0;
				nSoDuKhaDung = p->xData.nSotien - 50000;
				if (nNhapTienRut > nSoDuKhaDung)
				{
					Color(6); cout << "\t\tSo du trong tai khoan khong du de thuc hien giao dich.\n";
					goto NhapLai;
				}
				else
				{

					if (sUser == p->xData.sID)
					{
						string sKiemTra = "";
						Color(10);
						cout << "\t\t\t\tXac Nhan Rut Tien\n";
						Color(3);
						cout << "\t\t\tRut Tien Tu STK: " << p->xData.sID << endl;
						cout << "\t\t\tTen Chu The: " << p->xData.sTenChuThe << endl;
						cout << "\t\t\tSo Tien Rut: " << nNhapTienRut << " " << p->xData.sTienTe << endl;
						cout << "\t\t\tSo Du Hien Tai: " << p->xData.nSotien << " " << p->xData.sTienTe << endl;
						cout << "\t\t\tSo Du Con Lai: " << p->xData.nSotien - nNhapTienRut << " " << p->xData.sTienTe << endl;
						cout << "\tNhap "; Color(10);
						cout << "Mat Khau"; Color(3);
						cout << " De Xac Nhan Lenh Rut Tien. Nhap "; Color(4);
						cout << "NO"; Color(3);
						cout << " De Huy Lenh Rut Tien: "; Color(7);
					cc:
						sKiemTra = passwordInput(6);
						if (sKiemTra == p->xData.sPin)
						{
							p->xData.nSotien = p->xData.nSotien - nNhapTienRut;
							Color(10);
							cout << "\t\t\tBan da rut thanh cong: " << nNhapTienRut << " " << p->xData.sTienTe << endl;
							cout << "\t\t\tSo du con lai: " << p->xData.nSotien << " " << p->xData.sTienTe << endl;
							Color(7);
							//ghi du lieu da rut tien lai:
							ghiUser(L, p);
							ghiLichSuRutTien(L, p, nNhapTienRut);
						ff:
							Color(9);
							cout << "Quy khach co muon in hoa don khong ? Muon thi nhap yes/YES con khong thi nhap no/NO: ";
							rewind(stdin);
							getline(cin, sKey);
							if (sKey == "yes" || sKey == "YES")
							{
								inHoaDonRutTien(L, p, nNhapTienRut);
								cout << "In Hoa Don Thanh Cong!!\n"; Sleep(2000);
							}
							else if (sKey == "no" || sKey == "NO")
							{
								cout << "Cam on quy khach da su dung dich vu cua chung toi!!\n"; Sleep(2000);
							}
							else
							{
								cout << "Quy khach da nhap sai vui long nhap lai!!\n";
								goto ff;
							}
						}

						else if (sKiemTra == "no" || sKiemTra == "NO")
						{
							Color(11);
							cout << "\t\t\tLenh Rut Tien Da Huy!!"; Sleep(2000);
						}
						else
						{
							Color(14);
							cout << "\t\t\tNhap Sai!!. Vui long nhap lai: ";
							goto cc;
						}
					}
				}
			}
		}
		else
		{
			Color(13);
			cout << "\tSo tien nhap vao khong phai la boi cua 10.000vnd hoac khong nam trong khoang giao dich tu 50.000vnd den 50.000.000vnd. Vui long nhap lai!!!!\n";
			goto NhapLai;
		}
	} while (nNhapTienRut < 50000 || nNhapTienRut > 50000000);
}

//dang nhap va Menu chinh:
void dangnhap(LinkedList L)
{
	Node *p = L.pHead;
	Color(10); cout << "\n\t\t\t\t\t*********************************\n";
	Color(10); cout << "\t\t\t\t\t* ";  Color(14); cout << "\tDANG NHAP HE THONG\t"; Color(10); cout << "*\n";
	Color(10); cout << "\t\t\t\t\t*********************************\n";
	do {
		Color(10); cout << "\t\t\tNhap ID: ";
		rewind(stdin);
		getline(cin, sUser);
		cout << "\t\t\tNhap Pin: ";
		sMapin = passwordInput(6); // ma hoa password chua toi da 6 ki tu
		nTimes++;

		for (Node * p = L.pHead; p != NULL; p = p->pNext)
		{
			if (sUser == p->xData.sID && sMapin == p->xData.sPin)
			{
				Color(12); cout << "Dang dang nhap! Vui long cho giay lat de dang nhap vao he thong!!!..."; Sleep(2000);
				Menu(L);
			}
		}
		if (nTimes >= 1)
		{
			Color(11); cout << "Sai ID hoac Pin . Vui long nhaplai!!.\n";
			Color(7); cout << "Nhap ESC hoac esc neu ban muon thoat khoi he thong. Neu khong muon thi ban nhan phim Enter de tiep tuc dang nhap: ";
			rewind(stdin);
			getline(cin, sKey);

			if (sKey == "esc" || sKey == "ESC")
			{
				Color(12); cout << "Dang thoat khoi he thong. Vui long cho trong giay lat!!!..."; Sleep(1000);
				system("cls");
				exit(1);
			}
			if (nTimes >= 3)
			{
				Color(14); cout << "Nhap sai 3 lan. Vui long thu lai sau!!\n";
				Color(12); cout << "Dang thoat khoi he thong. Vui long cho trong giay lat!!!..."; Sleep(1000);
				system("cls");
				exit(1);

			}
		}


	} while (sUser != p->xData.sID || sMapin != p->xData.sPin);
}
void Menu(LinkedList L)
{

	int nChon = 0;
	Node * p = L.pHead;
	Node *q = p;
	do {
		system("cls"); Color(10);
		cout << "\n\t\t\t\t\t*********************************\n";
		Color(10); cout << "\n\t\t\t\t\t* "; Color(14);  cout << "\t   ATM BANKING\t\t"; Color(10); cout << "*\n";
		cout << "\n\t\t\t\t\t*********************************\n";
		Color(14);
		cout << "\t\t\t\t1. Rut tien\n";
		cout << "\t\t\t\t2. Chuyen tien\n";
		cout << "\t\t\t\t3. Doi ma pin\n";
		cout << "\t\t\t\t4. Nap tien bang the cao\n";
		cout << "\t\t\t\t5. Xem thong tin cua nguoi dung\n";
		cout << "\t\t\t\t6. Xem tat ca giao dich\n";
		cout << "\t\t\t\t7. Thoat chuong trinh!!\n";
		cout << "\t\t\t\t-----------------------------------------\n";
		cout << "\t\tBan chon CHUC NANG 1-7: ";
		cin >> nChon;
		switch (nChon)
		{
		case 1:
		{
			MenuRutTien(L, p);
			break;
		}
		case 2:
		{
			MenuChuyenTien(L, p);
			break;
		}
		case 3:
		{
			doiMatKhau(L, p);
			break;
		}
		case 4:
		{
			napTienOnline(L, p);
			break;
		}
		case 5:
		{
			xuatTT(L);
			break;
		}
		case 6:
		{
			Color(12); cout << "Vui long cho trong giay lat!!"; Sleep(1000);
			system("cls"); Color(10);
			Color(10); cout << "\n\t\t\t\t\t*********************************\n";
			Color(10); cout << "\t\t\t\t\t* ";  Color(14); cout << "\tLICH SU GIAO DICH\t"; Color(10); cout << "*\n";
			Color(10); cout << "\t\t\t\t\t*********************************\n";
			xuatTTLichSuGD(L);
			break;
		}

		default:
			cout << "\t\t\t\tBan da chon thoat chuong trinh!. Vui long cho chut chuong trinh dang thoat.."; Sleep(2000);
			cout << "\n\t\t\t\tDa thoat thanh cong!!"; Sleep(1000);
			exit(1);
			break;
		}
		system("pause");
	} while (nChon >= 1 || nChon <= 6);
}

//doi mat khau:

void doiMatKhau(LinkedList L, Node *p)
{

	
		system("cls");
		string sPassHienTai = "";
	dd:
		Color(10);
		cout << "\t\t\tNhap Mat Khau Hien Tai: ";
		Color(7);
		sPassHienTai = passwordInput(6);

		if (sPassHienTai == sMapin)
		{
			string sPassMoi = "";
			string sNhapLai = "";
			Color(4);
			cout << "\t\t\tLuu y: mat khau gom 6 chu so\n";
			Color(7);
			Color(10);
			cout << "\t\t\tNhap mat khau moi: ";
			Color(7);
			sPassMoi = passwordInput(6);
			Color(10);
			if (sPassMoi == "ESC" || sPassMoi == "esc")
			{

				Color(10);
				cout << "\t\tBan da chon thoat khoi chuong trinh"; Sleep(1000);
				system("cls");
				exit(1);
				Color(7);
			}
		cc:
			cout << "\t\t\tNhap lai mat khau moi: ";
			Color(7);
			sNhapLai = passwordInput(6);
			if (sNhapLai == "ESC" || sNhapLai == "esc")
			{

				Color(10);
				cout << "\t\tBan da chon thoat khoi chuong trinh"; Sleep(1000);
				system("cls");
				exit(1);
				Color(7);
			}
			else if (sPassMoi == sNhapLai)
			{
				if (sPassMoi.length() == 6)
				{
					for (p = L.pHead; p != NULL; p = p->pNext)
					{
						if (p->xData.sID == sUser && p->xData.sPin == sMapin)

						{
							p->xData.sPin = sPassMoi;
							Color(10);

						}
					}
					ghiUser(L, p);
					cout << "\t\t\tBan da thay doi mat khau thanh cong !!!\n";
					system("pause");
					Color(7);
				}
			}
			else if (sPassMoi != sNhapLai)
			{
				Color(4);
				cout << "\t\tMat khau khong trung khop vui long nhap lai!!\n";
				Color(7);
				goto cc;
			}
		}
		else if (sPassHienTai == "esc" || sPassHienTai == "ESC")
		{
			Color(10);
			cout << "Ban da chon thoat khoi chuong trinh"; Sleep(1000);
			system("cls");
			exit(1);
			Color(7);
		}
		else
		{
			system("cls");
			Color(4);
			cout << "\t\tMat khau nhap vao sai, Vui long nhap lai.\n";
			cout << "\t\tNhap ESC de thoat khoi chuong trinh !\n";
			Color(7);
			goto dd;
		}
}

//doc,ghi,xuat thong tin:
void xuatTT(LinkedList L)
{
	for (Node *p = L.pHead; p != NULL; p = p->pNext)
	{
		if (sUser == p->xData.sID)
		{
			xuatThongTinUser(p->xData);
		}
	}
}
void xuatTTLichSuGD(LinkedList L)
{
	int nLan = 1;
	for (Node *p = L.pHead; p != NULL; p = p->pNext)
	{
		if (p->xData.sID == sUser)
		{
			docLichSuGD(p);
		}
	}
}
void xuatThongTinUser(BANKER nX)
{
	cout << "\t\t\tID : " << nX.sID << endl;
	cout << "\t\t\tPin : " << nX.sPin << endl;
	cout << "\t\t\tTen chu the : " << nX.sTenChuThe << endl;
	cout << "\t\t\tSo du : " << nX.nSotien << " " << nX.sTienTe << endl;
}
void ghiUser(LinkedList &L, Node *p)
{
	BANKER nX;
	int nN = 8;
	ofstream fcout;
	fcout.open("ID.dat");
	fcout << nN << endl;
	for (p = L.pHead; p != NULL; p = p->pNext)
	{
		fcout << p->xData.sID << ";" << p->xData.sPin << ";" << p->xData.sTenChuThe << ";" << p->xData.nSotien << ";" << p->xData.sTienTe << endl;
	}
	fcout.close();
}
void docuser(LinkedList &L)
{
	BANKER nX;
	int nN = 0;
	ifstream fcin;
	fcin.open("ID.dat");
	if (fcin.is_open() == false)
		exit(1);
	fcin >> nN;
	fcin.ignore(1);
	for (int i = 0; i < nN; i++)
	{
		rewind(stdin);
		getline(fcin, nX.sID, ';');
		rewind(stdin);
		getline(fcin, nX.sPin, ';');
		rewind(stdin);
		getline(fcin, nX.sTenChuThe, ';');
		fcin >> nX.nSotien;
		fcin.ignore(1);
		rewind(stdin);
		getline(fcin, nX.sTienTe, '\n');

		Node *p = createNode(nX);
		addTail(L, p);
	}
	fcin.close();
}
void ghiLichSuNapTien(LinkedList L, Node * p, int nTienNap)
{
	time_t now = time('\0');
	tm *t = localtime(&now);
	ofstream fcout;
	for (p = L.pHead; p != NULL; p = p->pNext)
	{
		if (p->xData.sID == sUser)
		{

			fcout.open("Lichsugiaodich\\" + p->xData.sID + ".txt", ios::app);
			fcout << "NapTien \n" << kiemTraTime("hh", p) << t->tm_hour << ":" << kiemTraTime("m", p) << t->tm_min << ":" << kiemTraTime("ss", p)
				<< t->tm_sec << " " << kiemTraTime("dd", p) << t->tm_mday << "/" << kiemTraTime("mm", p)
				<< 1 + t->tm_mon << "/" << 1900 + t->tm_year << " " << "SoTienNap:" << nTienNap << p->xData.sTienTe
				<< kiemTraTime("100", p) << " " << "SoDuConLai:" << p->xData.nSotien << p->xData.sTienTe << " NapTienTu" << " " << "STK:" << p->xData.sID << " " << "TenChuThe:" << p->xData.sTenChuThe << " " << endl;
		}
	}
	fcout.close();
}
void ghiLichSuRutTien(LinkedList L, Node * p, int nTienTru)
{
	time_t now = time('\0');
	tm *t = localtime(&now);
	ofstream fcout;
	for (p = L.pHead; p != NULL; p = p->pNext)
	{
		if (p->xData.sID == sUser)
		{

			fcout.open("Lichsugiaodich\\" + p->xData.sID + ".txt", ios::app);
			fcout << "RutTien \n" << kiemTraTime("hh", p) << t->tm_hour << ":" << kiemTraTime("m", p) << t->tm_min << ":" << kiemTraTime("ss", p)
				<< t->tm_sec << " " << kiemTraTime("dd", p) << t->tm_mday << "/" << kiemTraTime("mm", p)
				<< 1 + t->tm_mon << "/" << 1900 + t->tm_year << " " << "SoTienRut:" << nTienTru << p->xData.sTienTe
				<< kiemTraTime("100", p) << " " << "SoDuConLai:" << p->xData.nSotien << p->xData.sTienTe << " RutTienTu" << " " << "STK:" << p->xData.sID << " " << "TenChuThe:" << p->xData.sTenChuThe << " " << endl;
		}
	}
	fcout.close();
}
void ghiLichSuChuyenTien(LinkedList L, Node * p, int nTienTru, Node *q)
{

	time_t now = time('\0');
	tm *t = localtime(&now);
	ofstream fcout;
	for (p = L.pHead; p != NULL; p = p->pNext)
	{
		if (p->xData.sID == sUser && q->xData.sID == sSTKChuyenTien)
		{

			fcout.open("Lichsugiaodich\\" + p->xData.sID + ".txt", ios::app);
			fcout << "ChuyenTien \n" << kiemTraTime("hh", p) << t->tm_hour << ":" << kiemTraTime("m", p) << t->tm_min << ":"
				<< kiemTraTime("ss", p) << t->tm_sec << " " << kiemTraTime("dd", p) << t->tm_mday << "/"
				<< kiemTraTime("mm", p) << 1 + t->tm_mon << "/" << 1900 + t->tm_year << " " << "SoTienChuyen:" << nTienTru << p->xData.sTienTe
				<< kiemTraTime("100", p) << " " << "SoDuConLai:" << p->xData.nSotien << p->xData.sTienTe << " send"
				<< " " << "STK:" << q->xData.sID << " " << "TenChuThe:" << q->xData.sTenChuThe << " " << endl;
		}
	}
	fcout.close();
}
void ghiLichSuNhanTien(LinkedList L, Node * p, int nTienTru, Node *q)
{
	time_t now = time('\0');
	tm *t = localtime(&now);
	ofstream fcout;
	for (p = L.pHead; p != NULL; p = p->pNext)
	{
		if (p->xData.sID == sUser && q->xData.sID == sSTKChuyenTien)
		{
			fcout.open("Lichsugiaodich\\" + q->xData.sID + ".txt", ios::app);
			fcout << "NhanTien \n" << kiemTraTime("hh", p) << t->tm_hour << ":" << kiemTraTime("m", p) << t->tm_min << ":" << kiemTraTime("ss", p)
				<< t->tm_sec << " " << kiemTraTime("dd", p) << t->tm_mday << "/" << kiemTraTime("mm", p) << 1 + t->tm_mon
				<< "/" << 1900 + t->tm_year << " " << "SoTienNhan:" << nTienTru << q->xData.sTienTe << kiemTraTime("100", p) << " " << "SoDuHienTai:" << q->xData.nSotien
				<< q->xData.sTienTe << " NhanTu" << " " << "STK:" << p->xData.sID << " " << "TenChuThe:" << p->xData.sTenChuThe << " " << endl;
		}
	}
	fcout.close();
}
void inHoaDonChuyenTien(LinkedList L, Node *p, int nTienTru, Node *q)
{
	time_t now = time('\0');
	tm *t = localtime(&now);
	ofstream fcout;
	for (p = L.pHead; p != NULL; p = p->pNext)
	{
		if (p->xData.sID == sUser && q->xData.sID == sSTKChuyenTien)
		{
			fcout.open("HoaDon\\" + p->xData.sID + ".txt", ios::app);
			fcout << "\t\t\t\t*******HOA DON*******\n";
			fcout << "Loai GD: Chuyen Tien" << endl;
			fcout << "STK: " << p->xData.sID << endl;
			fcout << "Ten Chu The: " << p->xData.sTenChuThe << endl;
			fcout << "So Tien Chuyen: " << nTienTru << p->xData.sTienTe << endl;
			fcout << "So Du Con Lai: " << p->xData.nSotien << p->xData.sTienTe << endl;
			fcout << "STK Nhan: " << q->xData.sID << endl;
			fcout << "Ten Chu The Nhan: " << q->xData.sTenChuThe << endl;
			fcout << "\t\t\t\t\t\t" << kiemTraTime("hh", p) << t->tm_hour << ":" << kiemTraTime("m", p) << t->tm_min << ":" << kiemTraTime("ss", p)
				<< t->tm_sec << " " << kiemTraTime("dd", p) << t->tm_mday << "/" << kiemTraTime("mm", p) << 1 + t->tm_mon
				<< "/" << 1900 + t->tm_year << endl;
		}
	}
	fcout.close();
}
void inHoaDonNhanTien(LinkedList L, Node *p, int nTienTru, Node *q)
{
	time_t now = time('\0');
	tm *t = localtime(&now);
	ofstream fcout;
	for (p = L.pHead; p != NULL; p = p->pNext)
	{
		if (p->xData.sID == sUser && q->xData.sID == sSTKChuyenTien)
		{
			fcout.open("HoaDon\\" + q->xData.sID + ".txt", ios::app);
			fcout << "\t\t\t\t*******HOA DON*******\n";
			fcout << "Loai GD: Nhan Tien" << endl;
			fcout << "STK: " << q->xData.sID << endl;
			fcout << "Ten Chu The: " << q->xData.sTenChuThe << endl;
			fcout << "So Tien Nhan: " << nTienTru << q->xData.sTienTe << endl;
			fcout << "So Du Hien Tai: " << q->xData.nSotien << q->xData.sTienTe << endl;
			fcout << "STK Chuyen: " << p->xData.sID << endl;
			fcout << "Ten Chu The Chuyen: " << p->xData.sTenChuThe << endl;
			fcout << "\t\t\t\t\t\t" << kiemTraTime("hh", p) << t->tm_hour << ":" << kiemTraTime("m", p) << t->tm_min << ":" << kiemTraTime("ss", p)
				<< t->tm_sec << " " << kiemTraTime("dd", p) << t->tm_mday << "/" << kiemTraTime("mm", p) << 1 + t->tm_mon
				<< "/" << 1900 + t->tm_year << endl;
		}
	}
	fcout.close();
}
void inHoaDonRutTien(LinkedList L, Node * p, int nTienTru)
{
	time_t now = time('\0');
	tm *t = localtime(&now);
	ofstream fcout;
	for (p = L.pHead; p != NULL; p = p->pNext)
	{
		if (p->xData.sID == sUser )
		{
			fcout.open("HoaDon\\" + p->xData.sID + ".txt", ios::app);
			fcout << "\t\t\t\t*******HOA DON*******\n";
			fcout << "Loai GD: Rut Tien" << endl;
			fcout << "STK: " << p->xData.sID << endl;
			fcout << "Ten Chu The: " << p->xData.sTenChuThe << endl;
			fcout << "So Tien Rut: " << nTienTru << p->xData.sTienTe << endl;
			fcout << "So Du Con Lai: " << p->xData.nSotien << p->xData.sTienTe << endl;
			fcout << "\t\t\t\t\t\t" << kiemTraTime("hh", p) << t->tm_hour << ":" << kiemTraTime("m", p) << t->tm_min << ":" << kiemTraTime("ss", p)
				<< t->tm_sec << " " << kiemTraTime("dd", p) << t->tm_mday << "/" << kiemTraTime("mm", p) << 1 + t->tm_mon
				<< "/" << 1900 + t->tm_year << endl;
		}
	}
	fcout.close();
}
void inHoaDonNapTien(LinkedList L, Node * p, int nTienNap)
{
	time_t now = time('\0');
	tm *t = localtime(&now);
	ofstream fcout;
	for (p = L.pHead; p != NULL; p = p->pNext)
	{
		if (p->xData.sID == sUser)
		{
			fcout.open("HoaDon\\" + p->xData.sID + ".txt", ios::app);
			fcout << "\t\t\t\t*******HOA DON*******\n";
			fcout << "Loai GD: Nap Tien Online" << endl;
			fcout << "STK: " << p->xData.sID << endl;
			fcout << "Ten Chu The: " << p->xData.sTenChuThe << endl;
			fcout << "So Tien Nap: " << nTienNap << p->xData.sTienTe << endl;
			fcout << "So Du Hien Tai: " << p->xData.nSotien << p->xData.sTienTe << endl;
			fcout << "\t\t\t\t\t\t" << kiemTraTime("hh", p) << t->tm_hour << ":" << kiemTraTime("m", p) << t->tm_min << ":" << kiemTraTime("ss", p)
				<< t->tm_sec << " " << kiemTraTime("dd", p) << t->tm_mday << "/" << kiemTraTime("mm", p) << 1 + t->tm_mon
				<< "/" << 1900 + t->tm_year << endl;
		}
	}
	fcout.close();
}
void docLichSuGD(Node * p)
{
	string a = "";
	ifstream fcin; //Mở File Input đưa dữ liệu vào
	fcin.open("Lichsugiaodich\\" + p->xData.sID + ".txt");
	cout << "		          =================>>>LICH SU GIAO DICH<<<=================\n\n";
	while (fcin.eof() ==  false)
	{
		getline(fcin, a, '\n');
		cout << a << endl;
		Sleep(30);
	}
	fcin.close();
	cout << "\t\t___________________________________________________________________________\n";
}
//tao Node:
void addTail(LinkedList &L, Node *p)
{
	if (L.pHead == NULL)
	{
		L.pHead = L.pTail = p;
	}
	else
	{
		L.pTail->pNext = p;
		L.pTail = p;
	}
}
void addHead(LinkedList &L, Node *p)
{
	if (L.pHead == NULL)
	{
		L.pHead = L.pTail = p;
	}
	else
	{
		p->pNext = L.pHead;
		L.pHead = p;
	}
}
Node * createNode(BANKER nX)
{
	Node * p = new Node;
	if (p == NULL)
		exit(1);
	p->xData = nX;
	p->pNext = NULL;
	return p;
}

//ma hoa, mau va lay ngay thang he thong:
string passwordInput(unsigned maxLength)
{
	string password = "";
	for (char c; (c = _getch()); )
	{
		if (c == '\n' || c == '\r') { // \n là phím phím enter + \r là Nhảy về đầu hàng, không xuống hàng
			cout << "\n";
			break;
		}
		else if (c == '\b') { //phím backspace
			cout << "\b \b";
			if (!password.empty()) password.erase(password.size() - 1);
		}
		else if (c == -32) { //phím mũi tên
			_getch(); //bỏ qua kí tự tiếp theo (hướng mũi tên)
		}
		else if (isprint(c) && password.size() < maxLength) { //isprint tức là chỉ nhận những ký tự in ra được (có tính khoảng trắng)
			cout << '*';
			password += c;
		}
	}
	return password;
}
void Color(int nX)
{
	HANDLE hConsoleColor;
	hConsoleColor = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsoleColor, nX);
}
string kiemTraTime(string sA, Node * p)
{
	time_t now = time('\0');
	tm *t = localtime(&now);
	if (sA == "ss")
	{
		if (t->tm_sec < 10)
		{
			return "0";
		}
	}
	if (sA == "m")
	{
		if ((t->tm_min) < 10)
		{
			return "0";
		}
	}
	if (sA == "hh")
	{
		if (t->tm_hour < 10)
		{
			return "0";
		}
	}
	if (sA == "dd")
	{
		if (t->tm_mday < 10)
		{
			return "0";
		}
	}
	if (sA == "mm")
	{
		if (t->tm_mon + 1 < 10)
		{
			return "0";
		}
	}
	//if (sX == "100")
	//{
	//	if (p->xData.nSotien < 100000)
	//	{
	//		return " ";
	//	}
	//}
	return "";
}