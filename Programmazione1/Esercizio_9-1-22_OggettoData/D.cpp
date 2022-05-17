#include "D.h"
#include <iostream>
using namespace std;

D::D(int gg, int mm, int aa)
{
	this->gg = gg;
	this->mm = mm;
	this->aa = aa;
}

void D::out()
{
	if(validate)
	{
		cout << gg << "/" << mm << "/" << aa << endl;
	}
	else
	{
		cout << "Errore nella data" << endl;
	}
}

void D::mod(int g, int m, int a)
{
	gg = g;
	mm = m;
	aa = a;
}

void D::val()
{
	if(gg <= 31 && mm <= 12)
	{
		validate = true;
	}
	else
	{
		validate = false;
	}
}