#include "stdafx.h"
#include "stdio.h"
#include "adapter.h"
#include <locale.h>
#include <iostream>

void Tributary::flow()
{
}
void Tributary::waterlvl()
{
}
void sideRiver:: flow()
	{
		printf("River flows with speed:  %f\n", speed);
	}
    void sideRiver::waterlvl()
	{
		printf("Water level: %f\n", deep);
	}
	void sideRiver::init(float a, float b)
	{
		speed = a;
		deep = b;
	}

	void Waters::underFlows()
	{
	}
	void Waters::waterLvl()
	{
	}
	void Lake::underFlows()
	{
		setlocale(LC_ALL, "Russian");
		printf("Deep flows - lake: %f\n", (speed + 3)/1.7);
	}
	void Lake::waterLvl()
	{
		setlocale(LC_ALL, "Russian");
		printf("Water level - lake: %f\n", deep + 1);
	}
	void Lake::init(float a, float b)
	{
		speed = a;
		deep = b;
	}

	void Reservoir::underFlows()
	{
		setlocale(LC_ALL, "Russian");
		printf("Deep flows - reservoir: %f\n", (speed + 3) / 3.7);
	}
	void Reservoir::waterLvl()
	{
		setlocale(LC_ALL, "Russian");
		printf("Water level - reservoir: %f\n", deep + 1);
	}
	void Reservoir::init(float a, float b)
	{
		speed = a;
		deep = b;
	}

	void AdapterL::flow() 
	{ 
		newLake->underFlows(); 
	}
	void AdapterL::waterlvl()
	{
		newLake->waterLvl();
	}
	void AdapterL::init(float a, float b)
	{
		newLake->init(a, b);
	}
	AdapterL::AdapterL(Lake *t)
	{
		newLake = t;
	}

	void AdapterR::flow()
	{
		newReserv->underFlows();
	}
	void AdapterR::waterlvl()
	{
		newReserv->waterLvl();
	}
	void AdapterR::init(float a, float b)
	{
		newReserv->init(a, b);
	}
	AdapterR::AdapterR(Reservoir *t)
	{
		newReserv = t;
	}