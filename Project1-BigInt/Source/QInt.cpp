#include "QInt.h"
/*lấy giá trị của bit thứ i trong dãy 128 bit*/
bool QInt::getBit_1(int i)const
{
	i = abs(127 - i);
	int index = 3 - i / 32;
	int k = i % 32;
	return mData[index] >> k & 1;
}
/*gán giá trị bit 0/1 cho dãy 128bit tại vị trí i*/
void QInt::setBit(int bit, int i)
{
	i = abs(127 - i);
	int index = 3 - i / 32;
	int k = i % 32;
	mData[index] = bit << k | mData[index];
}
/*Hàm trả về dãy 128 bit được lưu dưới dạng chuỗi*/
string QInt::getBit()const
{
	QInt a = *this;
	string result;
	int index = 3;
	int pos = 0;
	while (index >= 0)
	{
		if (pos < 32)
		{
			int k = ((a.mData[index]) & 1);
			result.insert(result.begin() + 0, k + '0');
			pos++;
			a.mData[index] = a.mData[index] >> 1;
		}
		else {
			index--;
			pos = 0;
		}
	}
	return result;
}
/*Hàm tạo số bù 2*/
QInt QInt::convertToTwosComplement()const
{
	QInt a;
	QInt result = *this;
	//tạo QInt mang giá trị là 1
	a.mData[0] = a.mData[1] = a.mData[2] = 0;
	a.mData[3] = 1;
	~result;
	return result + a;
}
/*operator nhân 2 QInt*/
QInt QInt::operator*(const QInt &a)
{
	QInt result;
	string str1 = this->getBit();
	string str2 = a.getBit();
	char Q1 = '0';
	string A = "";

	for (unsigned int i = 0; i < 128; i++)
		A += '0';
	int i = 0;
Loop:
	if (((str1[str1.length() - 1] == '0'&&Q1 == '0') || (str1[str1.length() - 1] == '1'&&Q1 == '1')) && i < 128)
	{
		i++;
		Q1 = DichPhaiBit_DS(A, str1);
		goto Loop;
	}
	if ((str1[str1.length() - 1] == '0'&&Q1 == '1') && i < 128)
	{
		i++;
		A = addtwoStringBin(A, str2);
		Q1 = DichPhaiBit_DS(A, str1);
		goto Loop;
	}
	if ((str1[str1.length() - 1] == '1'&&Q1 == '0') && i < 128)
	{
		i++;
		A = subtwoStringBin(A, str2);
		Q1 = DichPhaiBit_DS(A, str1);
		goto Loop;
	}
	string kqtam = A + str1;
	kqtam = kqtam.erase(0, 128);
	result.ScanQInt(kqtam, 2);
	return result;
}
/*thực hiện phép chia lấy nguyên của 2 số QInt*/
QInt QInt::operator /(QInt a)
{
	QInt result, tam;
	tam.ScanQInt("1", 2);
	bool Check = true;
	if ((*this^a).getBit()[0] == '1')
		Check = false;
	if (a.getBit()[0] == '1') {
		a = ~a + tam;
	}
	if (this->getBit()[0] == '1') {
		*this = ~(*this) + tam;
	}
	string A = "", AQ = "";
	string Q = this->getBit();
	string M = a.getBit();
	for (int i = 0; i < 128; i++) {
		A += "0";
	}
	int k = 128;
	while (k > 0)
	{
		AQ = A + Q;
		DichTrai(AQ);
		A = AQ.substr(0, 128);
		Q = AQ.substr(128, 128);
		A = subtwoStringBin(A, M);
		if (A[0] == '1') {
			A = addtwoStringBin(A, M);
			Q.erase(Q.end() - 1);
			Q += "0";
		}
		else {
			Q.erase(Q.end() - 1);
			Q += "1";
		}
		k = k - 1;
	}
	result.ScanQInt(Q, 2);
	if (Check == false) {

		result = ~result + tam;
	}
	return result;
}
/*Thực hiện phép chia lấy dư của 2 số QInt*/
QInt QInt::operator %(QInt a)
{
	QInt result, tam;
	tam.ScanQInt("1", 2);
	bool Check = true;
	if ((*this^a).getBit()[0] == '1')
		Check = false;
	if (a.getBit()[0] == '1') {
		a = ~a + tam;
	}
	if (this->getBit()[0] == '1') {
		*this = ~(*this) + tam;
	}
	string A = "", AQ = "";
	string Q = this->getBit();
	string M = a.getBit();
	for (int i = 0; i < 128; i++) {
		A += "0";
	}
	int k = 128;
	while (k > 0)
	{
		AQ = A + Q;
		DichTrai(AQ);
		A = AQ.substr(0, 128);
		Q = AQ.substr(128, 128);
		A = subtwoStringBin(A, M);
		if (A[0] == '1') {
			A = addtwoStringBin(A, M);
			Q.erase(Q.end() - 1);
			Q += "0";
		}
		else {
			Q.erase(Q.end() - 1);
			Q += "1";
		}
		k = k - 1;
	}
	result.ScanQInt(A, 2);
	if (Check == false) {

		result = ~result + tam;
	}
	return result;

}
/*Hàm dịch phải y bit*/
QInt QInt::operator >> (int y)
{
	QInt result;
	string x = this->getBit();

	int len = x.length();
	while (len < 128)
	{
		x.insert(x.begin() + 0, '0');
		len++;
	}
	while (y != 0)
	{
		y--;
		x.erase(x.end() - 1);
		x.insert(x.begin() + 0, '0');
	}
	result.ScanQInt(x, 2);
	return result;
}
/*Hàm dịch trái y bit*/
QInt QInt::operator <<(int y)
{
	QInt result;
	string x = this->getBit();
	int len = x.length();
	while (len < 128)
	{
		x.insert(x.begin() + 0, '0');
		len++;
	}
	while (y != 0)
	{
		y--;
		x.erase(x.begin() + 0);
		x += "0";
	}
	result.ScanQInt(x, 2);
	return result;
}
/*Hàm trả về một QInt là tổng của 2 QInt*/
QInt QInt:: operator+(QInt const &t)
{
	QInt c;
	int carry = 0;
	for (int i = 0; i < 32 * 4; i++)
	{
		int index = 3 - i / 32;
		int k = i % 32;
		int a1, b1;
		a1 = mData[index] >> k & 1;
		b1 = t.mData[index] >> k & 1;
		c.mData[index] = addBit(a1, b1, carry) << k | c.mData[index];
	}
	return c;
}
/*Hàm trả về một số lưu dưới dạng QInt là hiệu của 2 QInt*/
QInt QInt::operator-(QInt const &t)
{
	return *this + t.convertToTwosComplement();
}
/*Hàm thực hiện phép toán AND*/
QInt QInt::operator&(const QInt &a)
{
	QInt result;
	for (int i = 0; i < 4; i++)
	{
		result.mData[i] = a.mData[i] & (this)->mData[i];
	}
	return result;
}
/*Hàm thực hiện phép roán OR*/
QInt QInt::operator|(const QInt &a)
{
	QInt result;
	for (int i = 0; i < 4; i++)
	{
		result.mData[i] = a.mData[i] | (this)->mData[i];
	}
	return result;
}
/*Hàm thực hiện phép XOR*/
QInt QInt::operator^(const QInt &a)
{
	QInt result;
	for (int i = 0; i < 4; i++)
	{
		result.mData[i] = (this)->mData[i] ^ a.mData[i];
	}
	return result;
}
/*Hàm thực hiện phép NOT*/
QInt QInt::operator~()
{
	for (int i = 0; i < 4; i++)
		mData[i] = ~mData[i];

	return (*this);
}
/*Hàm in ra màn hình dạng hiển thị dưới từng dạng hệ số tương ứng là 2,10 hoặc 16*/
void QInt::PrintQInt(int heso)
{
	string source = this->getBit();
	string result;
	switch (heso)
	{
	case 2:
		standardized(source);
		cout << "(" << source << ")" << "2"; break;
	case 10:
		result = biToDec(source);
		cout << "(" << result << ")" << "10"; break;
	case 16:
		result = biToHex(source);
		standardized(result);
		cout << "(" << result << ")" << "16"; break;
	default:
		break;
	}
}
/*Cộng 2 dãy số nhị phân trả ra kết quả dưới dạng chuỗi*/
string QInt::addtwoStringBin(string a, string b)
{
	QInt obja, objb;
	obja.ScanQInt(a, 2);
	objb.ScanQInt(b, 2);
	QInt result = obja + objb;
	string kq = result.getBit();
	return kq;
}
/*Hiệu 2 dãy số nhị phân trả ra kết quả dưới dạng chuỗi*/
string QInt::subtwoStringBin(string a, string b)
{
	QInt obja, objb;
	obja.ScanQInt(a, 2);
	objb.ScanQInt(b, 2);
	QInt result = obja - objb;
	string kq = result.getBit();
	return kq;
}
void QInt::SetBitAm(string b)
{
	unsigned int stringSize = b.length();
	unsigned int vt = 0; //lưu vị trí để bắt đầu đảo bit trong mData
	if (stringSize <= 32)
	{
		int pos = 3;
		int count = 0;
		for (unsigned int i = 0; i < stringSize; i++)
		{
			if (b[i] == '1') {
				mData[pos] = (1 << stringSize - i - 1) | mData[pos];
			}
		}
		vt = 32 - stringSize - 1;
		while (pos >= 0)
		{
			for (unsigned int i = 0; i <= vt; i++)
			{
				mData[pos] = (1 << 31 - i) | mData[pos];
			}
			vt = 31;
			pos--;
		}
	}
	else if (stringSize > 128)
	{
		perror("Vuot qua so bit co the luu");
		return;
	}
	else
	{
		string tam = "";
		int sizeCur = b.length();
		int pos = 3;
		while (b.length() > 32)
		{
			int sizeCur = b.length();
			tam = b.substr(sizeCur - 32);
			b = b.substr(0, sizeCur - 32);
			for (unsigned int i = 0; i < tam.length(); i++)
			{
				if (tam[i] == '1') {
					mData[pos] = (1 << tam.length() - i - 1) | mData[pos];
				}

			}
			pos--;
		}
		unsigned int vt = 0;
		for (unsigned int i = 0; i < b.length(); i++)
		{
			if (b[i] == '1') {
				mData[pos] = (1 << b.length() - i - 1) | mData[pos];
			}
		}
		vt = 32 - b.length() - 1;
		while (pos >= 0)
		{
			for (unsigned int i = 0; i <= vt; i++)
			{
				mData[pos] = (1 << 31 - i) | mData[pos];
			}
			vt = 31;
			pos--;
		}
	}
}
void QInt::SetBitDuong(string temp)
{
	unsigned int stringSize = temp.length();
	if (stringSize <= 32)
	{
		int pos = 3;
		int count = 0;
		for (unsigned int i = 0; i < stringSize; i++)
		{
			if (temp[i] == '1') {
				mData[pos] = (1 << stringSize - i - 1) | mData[pos];
			}
			count++;
			if (count > 32)pos--, count = 0;
		}
	}
	else if (stringSize > 128)
	{
		perror("Vuot qua so bit co the luu");
		return;
	}
	else
	{
		string tam = "";
		int sizeCur = temp.length();
		int pos = 3;
		while (temp.length() > 32)
		{
			int sizeCur = temp.length();
			tam = temp.substr(sizeCur - 32);
			temp = temp.substr(0, sizeCur - 32);
			for (unsigned int i = 0; i < tam.length(); i++)
			{
				if (tam[i] == '1') {
					mData[pos] = (1 << tam.length() - i - 1) | mData[pos];
				}
			}
			pos--;
		}
		for (unsigned int i = 0; i < temp.length(); i++)
		{
			if (temp[i] == '1') {
				mData[pos] = (1 << temp.length() - i - 1) | mData[pos];
			}
		}
	}
}
void QInt::ScanQInt(string temp, int req)
{
	mData[0] = mData[1] = mData[2] = mData[3] = 0;
	if (req == 2)
	{
		SetBitDuong(temp);
	}
	if (req == 10)
	{
		if (temp[0] == '-') //chuyển số âm lưu dưới dạng bù 2
		{
			unsigned int pos1 = 0;
			string b = decToBi(temp);
			daoChuoi(b);
			for (unsigned int i = b.length() - 1; i >= 0; i--) {
				if (b[i] == '1') {
					pos1 = i;
					break;
				}
			}
			for (unsigned int i = 0; i < pos1; i++)
			{
				if (i < pos1)
				{
					if (b[i] == '1')b[i] = '0';
					else b[i] = '1';
				}
			}
			SetBitAm(b);
		}
		else
		{
			string b = decToBi(temp);
			daoChuoi(b);
			SetBitDuong(b);
		}
	}
	if (req == 16)
	{
		if (temp[0] == '-') //chuyển số âm lưu dưới dạng bù 2
		{
			int pos1 = 0;
			string b = hexToBi(temp);
			//daoChuoi(b);
			for (unsigned int i = b.length() - 1; i >= 0; i--) {
				if (b[i] == '1') {
					pos1 = i;
					break;
				}
			}
			for (unsigned int i = 0; i < pos1; i++)
			{
				if (i < pos1)
				{
					if (b[i] == '1')b[i] = '0';
					else b[i] = '1';
				}
			}
			SetBitAm(b);
		}
		else
		{
			string b = hexToBi(temp);
			//daoChuoi(b);
			SetBitDuong(b);

		}
		//cout << "So vua nhap: " << mData[3] << "  " << mData[2] << "  " << mData[1] << "  " << mData[0] << endl;

	}
}
QInt QInt::XuLiTrenChuoi(string tmp)
{
	string sohang1 = "", sohang2 = "", toantu = "", hexuli1 = "", hexuli2 = "";
	if (Check(tmp) == 1)
	{
		unsigned int k = 0;
		while (tmp[k] != ' ')
		{
			hexuli1 += tmp[k];
			k++;
			if (tmp[k] == ' ')break;
		}
		k++;
		while (tmp[k] != ' ')
		{
			sohang1 += tmp[k];
			k++;
			if (tmp[k] == ' ')break;
		}
		k = k + 3;
		while (tmp[k] != '\0')
		{
			sohang2 += tmp[k];
			k++;
			if (tmp[k] == '\0')break;
		}
	}
	if (Check(tmp) == 2)
	{
		unsigned int k = 0;
		while (tmp[k] != ' ')
		{
			hexuli1 += tmp[k];
			k++;
			if (tmp[k] == ' ')break;
		}
		k++;
		while (tmp[k] != ' ')
		{
			sohang1 += tmp[k];
			k++;
			if (tmp[k] == ' ')break;
		}
		k = k + 4;
		while (tmp[k] != '\0')
		{
			sohang2 += tmp[k];
			k++;
			if (tmp[k] == '\0')break;
		}
	}
	if (Check(tmp) == 3)
	{
		unsigned int k = 0;
		while (tmp[k] != ' ')
		{
			hexuli1 += tmp[k];
			k++;
			if (tmp[k] == ' ')break;
		}
		k = k + 3;
		while (tmp[k] != '\0')
		{
			sohang1 += tmp[k];
			k++;
			if (tmp[k] == '\0')break;
		}
	}
	if (Check(tmp) == 0)
	{
		unsigned int k = 0;
		while (tmp[k] != ' ')
		{
			hexuli1 += tmp[k];
			k++;
			if (tmp[k] == ' ')break;
		}
		k++;
		while (tmp[k] != ' ')
		{
			hexuli2 += tmp[k];
			k++;
			if (tmp[k] == ' ')break;
		}
		k++;
		while (tmp[k] != '\0')
		{
			sohang1 += tmp[k];
			k++;
			if (tmp[k] == '\0')break;
		}
	}
	QInt a, b, result;
	int sobit = 0;
	int hs = 0;
	int kt = Kiemtradau(tmp);
	switch (kt)
	{
	case 1:
		a.ScanQInt(sohang1, ConvertStrToNum(hexuli1));
		b.ScanQInt(sohang2, ConvertStrToNum(hexuli1));
		result = a + b;
		return result;
		break;
	case 2:
		a.ScanQInt(sohang1, ConvertStrToNum(hexuli1));
		b.ScanQInt(sohang2, ConvertStrToNum(hexuli1));
		result = a - b;
		return result;
		break;
	case 3:
		a.ScanQInt(sohang1, ConvertStrToNum(hexuli1));
		b.ScanQInt(sohang2, ConvertStrToNum(hexuli1));
		result = a * b;
		return result;
		break;
	case 4:
		a.ScanQInt(sohang1, ConvertStrToNum(hexuli1));
		b.ScanQInt(sohang2, ConvertStrToNum(hexuli1));
		result = a / b;
		return result;
		break;
	case 5:
		sobit = ConvertStrToNum(sohang2);
		a.ScanQInt(sohang1, ConvertStrToNum(hexuli1));
		result = a >> sobit;
		return result;
		break;
	case 6:
		sobit = ConvertStrToNum(sohang2);
		a.ScanQInt(sohang1, ConvertStrToNum(hexuli1));
		result = a >> sobit;
		return result;
		break;
	case 7:
		a.ScanQInt(sohang1, ConvertStrToNum(hexuli1));
		b.ScanQInt(sohang2, ConvertStrToNum(hexuli1));
		result = a & b;
		return result;
		break;
	case 8:
		a.ScanQInt(sohang1, ConvertStrToNum(hexuli1));
		b.ScanQInt(sohang2, ConvertStrToNum(hexuli1));
		result = a | b;
		return result;
		break;
	case 9:
		a.ScanQInt(sohang1, ConvertStrToNum(hexuli1));
		b.ScanQInt(sohang2, ConvertStrToNum(hexuli1));
		result = a ^ b;
		return result;
		break;
	case 10:
		a.ScanQInt(sohang1, ConvertStrToNum(hexuli1));
		result = ~a;
		break;
	case 0:
		a.ScanQInt(sohang1, ConvertStrToNum(hexuli1));
		return a;
		break;
	}
	/*cout << "hexuli1= " << hexuli1 << endl;
	cout << "hexuli2= " << hexuli2 << endl;
	cout << "sohang1= " << sohang1 << endl;
	cout << "sohang2= " << sohang2 << endl;*/
}
QInt::QInt()
{
	mData[0] = mData[1] = mData[2] = mData[3] = 0;
}
QInt::QInt(const QInt&a)
{
	for (int i = 0; i < 4; i++)
		mData[i] = a.mData[i];
}
QInt::~QInt()
{
	mData[0] = mData[1] = mData[2] = mData[3] = 0;
}
