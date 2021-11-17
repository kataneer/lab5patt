#ifndef __COMPOSITE
#define __COMPOSITE
#include "stdafx.h"
#include "stdio.h"
#include "composite.h"
#include <locale.h>
#include <string>
#include <algorithm>
#include <list>
#include <iostream>

using namespace std;

class snowComposite;
class snowPollute
{
  protected:
	string name;
	string deskr;
  public:
	snowPollute();
	snowPollute(const string &name, const string &deskr);
	void Display(string s);
	void Composition();
	void Deskis();
	snowComposite *GetEffects();
};

class snowComposite : public snowPollute {
	list <snowPollute *> children;
public:
	void Add(snowPollute *leaf);
	void Remove(snowPollute *leaf);
    snowComposite *GetEffects();
	void Display(string s);
	void Composition();
	void Deskis();
	//snowComposite();
};

class leafPollute : public snowPollute {
public:
	leafPollute(const string &name, const string &deskr) :snowPollute(name, deskr){}
	void Display(string s);
	void Composition();
	void Deskis();
};

#endif