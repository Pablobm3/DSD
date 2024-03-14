struct inputs{
float a;
float b;
float c;
};

program CALCULATE_PROG{
	version CALCULATE_VER{
	
	float sum(inputs)=1;
	float res(inputs)=2;
	float mult(inputs)=3;
	float div(inputs)=4;
	}=1;
}=0x2fffffff;
