#include"QInt.h"
#include "Menu.h"
#include "XuLy.h"
int main(int argc, char *argv[])
{
	if (argc >= 3)
	{
		string tmp;
		int i = 0;
		QInt a;
		freopen(argv[1], "rt", stdin);
		freopen(argv[2], "wt", stdout);
		while (!cin.eof())
		{
			getline(cin, tmp);
			a = QInt::XuLiTrenChuoi(tmp);

			if (Kiemtraheso(tmp) == 2)
			{
				string kq = a.getBit();
				standardized(kq);
				cout << kq << endl;
			}
			if (Kiemtraheso(tmp) == 10)
			{
				cout << biToDec(a.getBit()) << endl;
			}
			if (Kiemtraheso(tmp) == 16)
			{
				cout << biToHex(a.getBit()) << endl;
			}
		}
	}
	else
	{
		Chuongtrinh();
	}

	return 0;
}