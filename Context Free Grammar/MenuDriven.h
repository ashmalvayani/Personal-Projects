#ifndef MENUDRIVEN_H
#define MENUDRIVEN_H

#pragma once

#include <iostream>
#include <regex>
#include <conio.h>
#include <cstring>

using namespace std;

class MenuDriven{
private:

public:
    MenuDriven();
	void Intro();
    static bool Email_check(string);
    static string mask_password();
};

#endif
