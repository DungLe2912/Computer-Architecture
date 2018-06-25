#include "Menu.h"
#include "Windows.h"
void menu()
{
	cout << "--------------------Menu------------------\n";
	cout << "1.Doi tu so thap phan sang nhi phan \n";
	cout << "2.Doi tu so thap phan sang thap luc phan \n";
	cout << "3.Doi tu so nhi phan sang thap phan \n";
	cout << "4.Doi tu so nhi phan sang thap luc phan \n";
	cout << "5.Phep cong hai so nguyen lon \n";
	cout << "6.Phep tru hai so nguyen lon \n";
	cout << "7.Phep nhan hai so nguyen lon \n";
	cout << "8.Phep chia hai so nguyen lon \n";
	cout << "9.Phep AND hai so nguyen lon \n";
	cout << "10.Phep OR hai so nguyen lon \n";
	cout << "11.Phep XOR hai so nguyen lon \n";
	cout << "12.Phep NOT so nguyen lon \n";
	cout << "13.Phep dich trai bit \n";
	cout << "14.Phep dich phai bit \n";
	cout << "0.Thoat khoi chuong trinh\n";
	cout << "----------------------	---------------------\n";
}
void Chuongtrinh()
{
	QInt A, B, C;
	string a, b, c;
	int luachon, heso, bit;
	bool k = true;
	while (k)
	{
		menu();
		cout << "Nhap lua chon: "; cin >> luachon;
		switch (luachon)
		{
		case 1:
			while (1)
			{
				cout << "Nhap so nguyen he thap phan: "; cin >> a;
				A.ScanQInt(a, 10);
				cout << "KQ: " << "(" << a << ")" << "10 = ";
				A.PrintQInt(2);
				int exit;
				cout << "\n1. Tiep tuc\n2. Tro ve Menu\n\nChon: ";
				cin >> exit;
				if (exit != 1)
					break;
			}
			break;
		case 2:
			while (1)
			{
				cout << "Nhap so nguyen he thap phan: "; cin >> a;
				A.ScanQInt(a, 10);
				cout << "KQ: " << "(" << a << ")" << "10 = ";
				A.PrintQInt(16);
				int exit;
				cout << "\n1. Tiep tuc\n2. Tro ve Menu\n\nChon: ";
				cin >> exit;
				if (exit != 1)
					break;
			}	break;
		case 3:
			while (1)
			{
				cout << "Nhap so nguyen he nhi phan: "; cin >> a;
				A.ScanQInt(a, 2);
				cout << "KQ: " << "(" << a << ")" << "2 = ";
				A.PrintQInt(10);
				int exit;
				cout << "\n1. Tiep tuc\n2. Tro ve Menu\n\nChon: ";
				cin >> exit;
				if (exit != 1)
					break;
			}	break;
		case 4:
			while (1)
			{
				cout << "Nhap so nguyen he nhi phan: "; cin >> a;
				A.ScanQInt(a, 2);
				cout << "KQ: " << "(" << a << ")" << "2 = ";
				A.PrintQInt(16);
				int exit;
				cout << "\n1. Tiep tuc\n2. Tro ve Menu\n\nChon: ";
				cin >> exit;
				if (exit != 1)
					break;
			}	break;
		case 5:
			while (1)
			{
				cout << "Nhap he so can tinh toan:"; cin >> heso;
				cout << "Nhap so nguyen thu nhat: "; cin >> a;
				cout << "Nhap so nguyen thu hai: "; cin >> b;
				A.ScanQInt(a, heso);
				B.ScanQInt(b, heso);
				C = A + B;
				cout << "Ket qua: " << "(" << a << ")" << heso << " + " << "(" << b << ")" << heso << " = "; C.PrintQInt(heso);
				int exit;
				cout << "\n1. Tiep tuc\n2. Tro ve Menu\n\nChon: ";
				cin >> exit;
				if (exit != 1)
					break;
			}	break;
		case 6:
			while (1)
			{
				cout << "Nhap he so can tinh toan: "; cin >> heso;
				cout << "Nhap so nguyen thu nhat: "; cin >> a;
				cout << "Nhap so nguyen thu hai: "; cin >> b;
				A.ScanQInt(a, heso);
				B.ScanQInt(b, heso);
				C = A - B;
				cout << "Ket qua: " << "(" << a << ")" << heso << " - " << "(" << b << ")" << heso << " = "; C.PrintQInt(heso);
				int exit;
				cout << "\n1. Tiep tuc\n2. Tro ve Menu\n\nChon: ";
				cin >> exit;
				if (exit != 1)
					break;
			}	break;
		case 7:
			while (1)
			{
				cout << "Nhap he so can tinh toan: "; cin >> heso;
				cout << "Nhap so nguyen thu nhat: "; cin >> a;
				cout << "Nhap so nguyen thu hai: "; cin >> b;
				A.ScanQInt(a, heso);
				B.ScanQInt(b, heso);
				C = A * B;
				cout << "Ket qua: " << "(" << a << ")" << heso << " * " << "(" << b << ")" << heso << " = "; C.PrintQInt(heso);
				int exit;
				cout << "\n1. Tiep tuc\n2. Tro ve Menu\n\nChon: ";
				cin >> exit;
				if (exit != 1)
					break;
			}	break;
		case 8:
			while (1)
			{
				cout << "Nhap he so can tinh toan: "; cin >> heso;
				cout << "Nhap so nguyen thu nhat: "; cin >> a;
				cout << "Nhap so nguyen thu hai: "; cin >> b;
				A.ScanQInt(a, heso);
				B.ScanQInt(b, heso);
				QInt E, F;
				E.ScanQInt(a, heso);
				F.ScanQInt(b, heso);
				C = A / B;
				QInt D = E%F;
				cout << "Ket qua: " << "(" << a << ")" << heso << " / " << "(" << b << ")" << heso << " = "; C.PrintQInt(heso);
				cout << " du ";
				D.PrintQInt(heso);
				int exit;
				cout << "\n1. Tiep tuc\n2. Tro ve Menu\n\nChon: ";
				cin >> exit;
				if (exit != 1)
					break;
			}	break;
		case 9:
			while (1)
			{
				cout << "Nhap he so can tinh toan: "; cin >> heso;
				cout << "Nhap so nguyen thu nhat: "; cin >> a;
				cout << "Nhap so nguyen thu hai: "; cin >> b;
				A.ScanQInt(a, heso);
				B.ScanQInt(b, heso);
				C = A&B;
				cout << "Ket qua: " << "(" << a << ")" << heso << " & " << "(" << b << ")" << heso << " = "; C.PrintQInt(heso);
				int exit;
				cout << "\n1. Tiep tuc\n2. Tro ve Menu\n\nChon: ";
				cin >> exit;
				if (exit != 1)
					break;
			}	break;
		case 10:
			while (1)
			{
				cout << "Nhap he so can tinh toan: "; cin >> heso;
				cout << "Nhap so nguyen thu nhat: "; cin >> a;
				cout << "Nhap so nguyen thu hai: "; cin >> b;
				A.ScanQInt(a, heso);
				B.ScanQInt(b, heso);
				C = A | B;
				cout << "Ket qua: " << "(" << a << ")" << heso << " | " << "(" << b << ")" << heso << " = "; C.PrintQInt(heso);
				int exit;
				cout << "\n1. Tiep tuc\n2. Tro ve Menu\n\nChon: ";
				cin >> exit;
				if (exit != 1)
					break;
			}	break;
		case 11:
			while (1)
			{
				cout << "Nhap he so can tinh toan: "; cin >> heso;
				cout << "Nhap so nguyen thu nhat: "; cin >> a;
				cout << "Nhap so nguyen thu hai: "; cin >> b;
				A.ScanQInt(a, heso);
				B.ScanQInt(b, heso);
				C = A^B;
				cout << "Ket qua: " << "(" << a << ")" << heso << " ^ " << "(" << b << ")" << heso << " = "; C.PrintQInt(heso);
				int exit;
				cout << "\n1. Tiep tuc\n2. Tro ve Menu\n\nChon: ";
				cin >> exit;
				if (exit != 1)
					break;
			}	break;
		case 12:
			while (1)
			{
				cout << "Nhap he so can tinh toan: "; cin >> heso;
				cout << "Nhap so nguyen thu nhat: "; cin >> a;
				A.ScanQInt(a, heso);
				C = ~A;
				cout << "Ket qua: " << "~" << "(" << a << ")" << heso << " = "; C.PrintQInt(heso);
				int exit;
				cout << "\n1. Tiep tuc\n2. Tro ve Menu\n\nChon: ";
				cin >> exit;
				if (exit != 1)
					break;
			}	break;
		case 13:
			while (1)
			{
				cout << "Nhap he so can tinh toan: "; cin >> heso;
				cout << "Nhap so bit muon dich: "; cin >> bit;
				cout << "Nhap so nguyen: "; cin >> a;
				A.ScanQInt(a, heso);
				C = A << bit;
				cout << "Ket qua: " << a << " << " << bit << " = "; C.PrintQInt(heso);
				int exit;
				cout << "\n1. Tiep tuc\n2. Tro ve Menu\n\nChon: ";
				cin >> exit;
				if (exit != 1)
					break;
			}	break;
		case 14:
			while (1)
			{
				cout << "Nhap he so can tinh toan: "; cin >> heso;
				cout << "Nhap so bit muon dich: "; cin >> bit;
				cout << "Nhap so nguyen: "; cin >> a;
				A.ScanQInt(a, heso);
				C = A << bit;
				cout << "Ket qua: " << a << " >> " << bit << " = "; C.PrintQInt(heso);
				int exit;
				cout << "\n1. Tiep tuc\n2. Tro ve Menu\n\nChon: ";
				cin >> exit;
				if (exit != 1)
					break;
			}	break;
		case 0:
			k = false;
			break;
		default:
			cout << "Nhap sai\n" << endl;
			break;
		}
		system("cls");
	}
}
