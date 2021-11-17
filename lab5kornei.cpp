// lab5kornei.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "stdio.h"
#include "conio.h"
#include "adapter.h"
#include "decorator.h"
#include "composite.h"
#include "iterator.h"
#include <string>
#include <algorithm>
#include <iostream>
#include <list>

using namespace std;

int flag_display = 0;


int _tmain(int argc, _TCHAR* argv[])
{
	setlocale(LC_ALL, "Russian");
	printf("Adapter\n\n");
	sideRiver *Barnaulka = new sideRiver();
	Barnaulka->init(100, 15);
	Barnaulka->flow();
	Barnaulka->waterlvl();
	Lake *Altaika = new Lake();
	Reservoir *ObSea = new Reservoir();
	HighAmplitude *amp = new HighAmplitude(Altaika);
	GroundWaters *amp2 = new GroundWaters(ObSea);
	AdapterL *adp1 = new AdapterL(Altaika);
	AdapterR *adp2 = new AdapterR(ObSea);
	printf("\n");
	adp1->init(100, 15);
	adp1->flow();
	adp1->waterlvl();
	printf("\n");
	adp2->init(100, 15);
	adp2->flow();
	adp2->waterlvl();
	printf("\n\n");
	printf("Decorator\n\n");
	amp->underFlows();
	amp->waterLvl();
	printf("\n");
	amp2->underFlows();
	amp2->waterLvl();
	printf("\n\n");
	printf("Composite\n\n");
	leafPollute *chem = new leafPollute("chemical", "chemical pollution");
	leafPollute *acid = new leafPollute("acid", "acid pollution");
	leafPollute *radio = new leafPollute("radio", "radioactive pollution");
	snowComposite Belaya;
	snowComposite Orlovka;
	snowComposite Shahi;
	string names1 = "Belaya";
	string names2 = "Orlovka";
	string names3 = "Shahi";
	Orlovka.Add(acid);
	Orlovka.Add(chem);
	Belaya.Add(radio);
	Belaya.Display(names1);
	Shahi.Display(names3);
	Orlovka.Display(names2);
	printf("\n");
	printf("Iterator\n\n");
	int x = 5;
	typedef aggregate <string> myContainer;
	myContainer data;
	printf("List:\n");
	data.push(names1);
	data.push(names2);
	data.push(names3);
	printf("\n");
	for (myContainer::myIterator it = data.begin(); it != data.end(); ++it)
	{
		*(it.next());
	}
	_getch();
	return 0;
}

