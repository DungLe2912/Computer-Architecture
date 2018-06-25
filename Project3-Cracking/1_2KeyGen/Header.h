#pragma once
#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <stdint.h>
#include <stdlib.h>
#include <map>
#include <vector>

using namespace std;

typedef int32_t myint;
typedef uint32_t myuint;
typedef int8_t mychar;
typedef uint8_t myuchar;

const string firstGen = "BDRQKPTVJI";
const string secondGen = "0123456789";
const myuint i_val[4] = { 0x10325476u, 0x98badcfeu, 0xefcdab89u, 0x67452301u };
const myuint R1[8] = { 0xd1310ba6u, 0x98dfb5acu, 0x2ffd72dbu, 0xd01adfb7u, 0xb8e1afedu, 0x6a267e96u, 0xba7c9045u, 0xf12c7f99u };
const myuint R2[8] = { 0x00000000u, 0x77073096u, 0xee0e612cu, 0x990951bau, 0x076dc419u, 0x706af48fu, 0xe963a535u, 0x9e6495a3u };

const myuint startR3 = 0x404020u;
map<string, myint> ps1_ps2;
myuint R3[256];
FILE*keyFILE;
unsigned int hexToInt(string s);
void writeData_Handling();
void readData_Handling();
myuint calculator(myuint eax);
myuint Handling_Key(myuint mem[]);
