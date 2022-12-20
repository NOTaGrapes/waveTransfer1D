//core.h
//
// writed by NOTaGrape. 

#ifndef coreH
#define coreH


class core//do u new da wey? (Lol, it's just a my class)
{
private:
	int    iterationClock_;// dumb timer, i know it, but i use it!
	double alfa_ [201];//this variable (alfa_ & beta_) only affects the Implict and Crank-Nikolson methods
	double beta_ [201];//keep it in mind while trying understand this pice of something soft and warm in .cpp
	double stepCord_;//at paper u can write this like dx
	double stepTime_;//the same thing, look like dt
	double a_;//a parametr
	double A_[201];//left   <--...
	double B_[201];//right  <----|===== Used in Methad pragonki GiGity GigiTy gyu!)                       (Who as not Quagmire?)
	double C_[201];//middle <--'''
	double lambda_;//lambda parametr (usage approved!)

public:
	double layerUpper_  [201];//layer of calculated value
	double layerMiddle_ [201];//layer of pre-calculated value
	double layerLower_  [201];//layer of pre-pre-calculated value
	
	// basic constructor
	core();

	//desstructor
	~core();

	//same to core();
	void makeReset();

	//change value for new value	
	void setValue(double,char*);

	//calculating of lambda to make equation simpliest. 
	//this method shoould be called after every chage of dx,dt,alfa
	//so, it needs alfa,dx and dt to be writed before it
	void computeLambda(char*);

	//method make compute for main layer 
	//use different cycles in different methods
	void computeAndMoveLayer(char*);

	//use this if u want to print somewhere private data
	double showValue(char*);
};
#endif