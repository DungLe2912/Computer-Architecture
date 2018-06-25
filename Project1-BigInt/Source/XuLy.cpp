#include "XuLy.h"
/*
chuẩn hóa chuỗi bằng cách xóa các chữ số 0 ở đầu
vd: 00123->123
*/
void standardized(string &a)
{
	while (a[0] == '0')
		a.erase(a.begin() + 0);
}
/*
Chuyển một số nguyên ra dạng kí tự tương ứng
*/
char numTochar(int a)
{
	return a + '0';
}
/*
chuyển kí tự sang dạng số tương ứng
*/
int charTonum(char a)
{
	return a - '0';
}
/*
Hàm trả ra một chuỗi là kết quả của phép chia lấy nguyên cho 2
*/
string div_2(string a)
{
	string result;
	int temp;
	int du = 0;
	int length = a.length();
	for (int i = 0; i < length; i++)
	{
		temp = du * 10 + charTonum(a[i]);
		result += numTochar(temp / 2);
		du = temp % 2;
	}
	standardized(result);
	return result;
}
/*
chuyển số hệ 10 được đưa vào dạng chuỗi
trả ra 1 chuỗi là số nhị phân tương ứng
*/
string decToBi(string a)
{
	string bit;
	string tmp = a;
	if (a[0] == '-') tmp = a.erase(0, 1);
	if (a == "0") return bit = "0";
	else {
		while (tmp != "0"&&tmp != "")
		{

			int length = tmp.length();
			bit += numTochar(charTonum(tmp[length - 1]) % 2);
			tmp = div_2(tmp);
		}
		return bit;
	}
}
//chuẩn hóa 2 chuỗi có độ dài bằng nhau
void chuanHoa(string &a, string &b) // lam 2 xau co do dai bang nhau
{
	int l1 = a.length(), l2 = b.length();
	if (l1 >= l2)
	{
		b.insert(0, l1 - l2, '0');    // chen vao dau cua b cac ky tu '0'
	}
	else
	{
		a.insert(0, l2 - l1, '0');    // chen vao dau cua a cac ky tu '0'
	}
}
//tổng 2 số nguyên dưới dạng chuỗi
string sum(string a, string b)  // tong 2 so
{
	string s = "";
	chuanHoa(a, b);      // chuan hoa
	int l = a.length();

	int temp = 0;
	for (int i = l - 1; i >= 0; i--)   // duyet va cong
	{
		temp = charTonum(a[i]) + charTonum(b[i]) + temp;    // tinh tong tung doi mot
		s.insert(0, 1, numTochar(temp % 10));         // gan phan don vi vao
		temp = temp / 10;     // lay lai phan hang chuc
	}
	if (temp>0)  // neu hang chuc > 0 thi them vao KQ
	{
		s.insert(0, 1, numTochar(temp));
	}
	return s;
}
/*
Nhân số có 1 chữ số với 1 số có nhiều chữ số dưới dạng chuỗi
*/
string charMulStr(char a, string b)
{
	string s = "";
	int temp = 0;
	for (int i = b.length() - 1; i >= 0; i--)
	{
		temp = charTonum(a) * charTonum(b[i]) + temp;
		s.insert(0, 1, numTochar(temp % 10));
		temp = temp / 10;
	}

	if (temp>0)
	{
		s.insert(0, 1, numTochar(temp));
	}
	return s;
}
/*
Trừ 2 số nguyên dưới dạng chuỗi (số trừ >số bị trừ)
*/
string sub(string a, string b)// trừ a>b
{
	string result;
	unsigned int l = a.length();
	while (b.length() < l)
		b.insert(0, "0");
	int carry = 0;
	//int temp;
	for (int i = l - 1; i >= 0; i--)
	{
		if (a[i] < b[i] + carry)
		{

			result.insert(result.begin(), (a[i] - b[i] - carry + 10) + '0');
			carry = 1;
		}
		else
		{
			result.insert(result.begin(), (a[i] - b[i] - carry) + '0');
			carry = 0;
		}
	}
	return result;
}
/*
chuyển chuỗi nhị phân sang thập phân
*/
string biToDec(string bi)
{
	string temp = "170141183460469231731687303715884105728"; //2^127
	string mu = temp;
	int l = 126;
	string result = "0";
	l = bi.length();
	int i = 0;
	if (l == 128 && bi[0] == '1')
	{
		mu = div_2(mu);
		i = 1;
	}
	for (; i < l; i++)
	{
		if (bi[i] == '1')
		{
			result = sum(result, mu);
		}
		mu = div_2(mu);
	}
	while (result[0] == '0'&&result.length() > 1)
		result.erase(0, 1);
	if (l == 128 && bi[0] == '1')
	{
		result = sub(temp, result);
		while (result[0] == '0'&&result.length() > 1)
			result.erase(0, 1);
		result.insert(result.begin() + 0, '-');
	}
	return result;
}
/*
Chuyển hóa số hệ 16 sang hệ nhị phân, đầu vào và đầu ra là một chuỗi
*/
string hexToBi(string hex)
{
	string bi;
	int i = 0;
	string tmp = hex;
	if (hex[0] == '-') tmp = hex.erase(0, 1);

	while (tmp[i] != '\0')
	{
		switch (tmp[i++])
		{
		case '0': bi += "0000"; break;
		case '1': bi += "0001"; break;
		case '2': bi += "0010"; break;
		case '3': bi += "0011"; break;
		case '4': bi += "0100"; break;
		case '5': bi += "0101"; break;
		case '6': bi += "0110"; break;
		case '7': bi += "0111"; break;
		case '8': bi += "1000"; break;
		case '9': bi += "1001"; break;
		case 'A': bi += "1010"; break;
		case 'B': bi += "1011"; break;
		case 'C': bi += "1100"; break;
		case 'D': bi += "1101"; break;
		case 'E': bi += "1110"; break;
		case 'F': bi += "1111"; break;
		case 'a': bi += "1010"; break;
		case 'b': bi += "1011"; break;
		case 'c': bi += "1100"; break;
		case 'd': bi += "1101"; break;
		case 'e': bi += "1110"; break;
		case 'f': bi += "1111"; break;
		default:  break;
		}
	}
	return bi;
}
/*
chuyển 4 bit nhị phân đầu vào thành dạng thập lục phân, tương ứng
*/
string BinaryToHex(string bi)
{
	if (bi == "0000") return "0";
	else if (bi == "0001") return "1";
	else if (bi == "0010") return "2";
	else if (bi == "0011")return "3";
	else if (bi == "0100") return "4";
	else if (bi == "0101") return "5";
	else if (bi == "0110") return "6";
	else if (bi == "0111")return  "7";
	else if (bi == "1000") return "8";
	else if (bi == "1001")return "9";
	else if (bi == "1010")return "A";
	else if (bi == "1011")return "B";
	else if (bi == "1100")return "C";
	else if (bi == "1101")return "D";
	else if (bi == "1110")return "E";
	else if (bi == "1111")return "F";
	else return 0;
}
/*
chuyển chuỗi nhị phân đầu vào thành dạng thập lục phân, tương ứng
*/
string biToHex(string bi)
{
	string result;
	int l = bi.length();
	int x = 4 - l % 4;
	while (x-- != 0)
	{
		bi.insert(bi.begin(), '0');
	}
	l = bi.length();
	string temp;
	int k = 4;
	int i = l - 1;
	while (i >= 0)
	{
		if (k > 0)
		{
			//i--;
			temp.insert(temp.begin() + 0, bi[i]);
			k--;
			i--;

		}
		else
		{
			result.insert(0, BinaryToHex(temp));
			k = 4;
			temp = "";

		}
	}
	result.insert(0, BinaryToHex(temp));
	while (result[0] == '0')
		result.erase(0, 1);
	return result;
}
/*
chuyển chuỗi sang dạng số nguyên tương ứng
*/
int ConvertStrToNum(string tmp)
{
	int result = 0;
	int k = tmp.length();
	for (unsigned int i = 0; i < tmp.length(); i++)
	{
		result += (tmp[i] - '0')*pow(10, k - 1);
		k--;
	}
	return result;
}
/*
Cộng 2 bit
*/
int addBit(int a, int b, int &carry)
{
	int result = a + b + carry;
	switch (result) {
	case 0:
		carry = 0;
		return 0;
		break;
	case 1:
		carry = 0;
		return 1;
		break;
	case 2:
		carry = 1;
		return 0;
		break;
	case 3:
		carry = 1;
		return 1;
		break;
	default:
		return 0;
		break;
	}
	return 0;
}
string DichTrai(string &x)
{
	x.erase(x.begin() + 0);
	x += "0";
	return x;
}
char DichPhaiBit_DS(string &x, string&y)
{

	if (x[0] == '1')
		x.insert(x.begin() + 0, '1');
	else
		x.insert(x.begin() + 0, '0');
	char tmp = x[x.length() - 1];
	x.erase(x.length() - 1, 1);
	y.insert(y.begin(), tmp);
	char rs = y[y.length() - 1];
	y.erase(y.length() - 1, 1);
	return rs;
}
void daoChuoi(string &a)
{
	int length = a.length();
	for (int i = 0; i < length / 2; i++)
	{
		char t = a[i];
		a[i] = a[length - i - 1];
		a[length - i - 1] = t;
	}
}
int Check(string tmp)
{
	for (unsigned int i = 0; i < tmp.length(); i++)
	{
		if (tmp[i] == '+' || tmp[i] == '-' || tmp[i] == '*' || tmp[i] == '/' || tmp[i] == '&' || tmp[i] == '^' || tmp[i] == '|')
			return 1;
		if (tmp[i] == '<' || tmp[i] == '>')
			return 2;
		if (tmp[i] == '~')
			return 3;
	}
	return 0;
}
int Kiemtradau(string tmp)
{
	for (unsigned int i = 0; i < tmp.length(); i++)
	{
		if (tmp[i] == '+')return 1;
		if (tmp[i] == '-')return 2;
		if (tmp[i] == '*')return 3;
		if (tmp[i] == '/')return 4;
		if (tmp[i] == '<')return 5;
		if (tmp[i] == '>')return 6;
		if (tmp[i] == '&')return 7;
		if (tmp[i] == '|')return 8;
		if (tmp[i] == '^')return 9;
		if (tmp[i] == '~')return 10;
	}
	return 0;
}
int Kiemtraheso(string tmp)
{
	string hs = "";
	int k = 0;
	if (Check(tmp) == 0)
	{

		while (tmp[k] != ' ')
		{
			k++;
			if (tmp[k] == ' ')break;
		}
		k++;
		while (tmp[k] != ' ')
		{
			hs += tmp[k];
			k++;
			if (tmp[k] == ' ')break;
		}
	}
	else
	{
		while (tmp[k] != ' ')
		{
			hs += tmp[k];
			k++;
			if (tmp[k] == ' ')break;
		}
	}
	if (hs == "2")
		return 2;
	if (hs == "10")
		return 10;
	if (hs == "16")
		return 16;
}
