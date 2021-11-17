#include "stdafx.h"
#include "stdio.h"
#include "adapter.h"
#include "decorator.h"
#include <locale.h>
#include <iostream>

void NewParams::underFlows()
{
}
void NewParams::waterLvl()
{
}
	NewParams::NewParams(Waters *inItem)
	{ 
		item = inItem; 
	}
	void HighAmplitude::underFlows()
	{
		item->underFlows();
		printf("Amplitude hesitates - flows\n");
	}
	void HighAmplitude::waterLvl()
	{
		item->waterLvl();
		printf("Amplitude hesitates - water level\n");
	}

	void GroundWaters::underFlows()
	{
		item->underFlows();
		printf("Ground waters - flows\n");
	}
	void GroundWaters::waterLvl()
	{
		item->waterLvl();
		printf("Ground waters - water level\n");
	}