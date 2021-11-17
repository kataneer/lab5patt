#ifndef __ADAPTER
#define __ADAPTER

class Tributary
{
public:
	void flow();
	void waterlvl();
};

class sideRiver : public Tributary
{
private:
	float speed;
	float deep;
public:
	void flow();
	void waterlvl();
	void init(float a, float b);
};

class Waters {                          
public:
	void underFlows();
	void waterLvl();
};

class Lake: public Waters { 
private:
	float speed;
	float deep;
public:
	void underFlows();
	void waterLvl();
	virtual void init(float a, float b);
};

class Reservoir: public Waters {
private:
	float speed;
	float deep;
public:
	void underFlows();
	void waterLvl();
	void init(float a, float b);
};

class AdapterL : public Tributary 
{ 
private:
	Lake *newLake;
public:
	void flow() ;
	void waterlvl();
	void init(float a, float b);
	AdapterL(Lake *t);
};

class AdapterR : public Tributary
{
private:
	Reservoir *newReserv;
public:
	void flow();
	void waterlvl();	
	void init(float a, float b);
	AdapterR(Reservoir *t);
};

#endif
