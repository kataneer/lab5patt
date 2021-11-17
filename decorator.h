#ifndef __DECORATOR
#define __DECORATOR

class NewParams : public Waters {
protected:
	Waters *item;
public:
	void underFlows();
	void waterLvl();
	NewParams(Waters *inItem);
	~NewParams();
};

class HighAmplitude : public NewParams {
public:
	void underFlows();
	void waterLvl();
	HighAmplitude(Waters *inItem) : NewParams(inItem){};
};

class GroundWaters : public NewParams {
public:
	virtual void underFlows();
	virtual void waterLvl();
	GroundWaters(Waters *inItem) : NewParams(inItem){};
};

#endif