#include "stdafx.h"
#include "stdio.h"
#include "composite.h"
#include <locale.h>
#include <string>
#include <algorithm>
#include <list>
#include <iostream>

using namespace std;
int flag_disploy = 0;

snowPollute::snowPollute()
{

}

snowPollute::snowPollute(const string &name, const string &deskr)
{
	this->name = name;
	this->deskr = deskr;
}
void snowPollute:: Display(string s)
{
	cout << name << ", " << deskr << endl;
}
void snowPollute:: Composition()
{
}
void snowPollute:: Deskis()
{
}
snowComposite *(snowPollute::GetEffects())
{
	return 0;
}
    void snowComposite::Add(snowPollute *leaf)
	{
		children.push_back(leaf);
	}
	void snowComposite::Remove(snowPollute *leaf)
	{
		children.remove(leaf);
	}
	snowComposite *(snowComposite::GetEffects())
	{
		return this;
	}
	void snowComposite::Display(string s)
	{
		flag_disploy = 0;
		cout << "Pollution list: " << s << "\n" << endl;
		for (list <snowPollute *>::iterator iter = children.begin(); iter != children.end(); iter++)
		{
			flag_disploy = 1;
			(*iter)->Display(s);
		}
		if (flag_disploy == 0)
			printf("There is no special pollution for this object.\n");
		printf("\n");
	}
	void snowComposite::Composition()
	{
		for (list <snowPollute *>::iterator iter = children.begin(); iter != children.end(); iter++)
		{
			(*iter)->Composition();
			cout << endl;
		}
	}
	void snowComposite::Deskis()
	{
		for (list <snowPollute *>::iterator iter = children.begin(); iter != children.end(); iter++)
		{
			(*iter)->Deskis();
			cout << endl;
		}
	}
	/*
	snowComposite::snowComposite()
	{
		//printf("Участок снега\n");
	}*/

	void leafPollute::Display(string s)
	{
		cout << name << ", " << deskr << endl;
	}
	void leafPollute::Composition()
	{
		cout << "clear " << name;
	}

	void leafPollute::Deskis()
	{
		cout << "default " << deskr;
	}