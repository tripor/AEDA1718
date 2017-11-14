#ifndef HEADER_H_
#define HEADER_H_

#include <string>
#include <vector>
#include <utility>
#include <iostream>
#include <fstream>
#include <sstream>
#include "math.h"

typedef unsigned int u_int;

#ifdef _WIN32
#include <windows.h>
#define Chars() SetConsoleCP(1252); SetConsoleOutputCP(1252);
#else
#define Chars() void;
#endif

#ifdef _WIN32
#define ClearScreen() system("CLS");
#else
#define ClearScreen() system("Clear");
#endif

int x_aci = 0;
int y_aci = 0;



#endif /* HEADER_H_ */
