#pragma once
#include <iostream>
#include <string>
#include "XuLy.h"
using namespace std;
class QInt
{
private:
	uint32_t mData[4];
public:
	QInt operator+(QInt const &t);
	QInt operator-(QInt const &t);
	QInt operator&(const QInt &a);
	QInt operator|(const QInt &a);
	QInt operator^(const QInt &a);
	QInt operator~();
	QInt operator*(const QInt &a);
	QInt operator /(QInt a);
	QInt operator %(QInt a);
	QInt operator >> (int y);
	QInt operator <<(int y);
	string addtwoStringBin(string a, string b);
	string subtwoStringBin(string a, string b);
	void ScanQInt(string temp, int req);
	void SetBitAm(string b);
	void SetBitDuong(string temp);
	static QInt XuLiTrenChuoi(string tmp);
	bool getBit_1(int i)const;
	void setBit(int bit, int i);
	QInt convertToTwosComplement()const;
	string getBit()const;
	void PrintQInt(int heso);
	QInt();
	QInt(const QInt &);
	~QInt();
};

