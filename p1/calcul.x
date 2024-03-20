struct inputs{
float a;
float b;
float c;
};

program CALCULATE_PROG1{
	version CALCULATE_VER1{
	
	float sum(inputs)=1;
	float res(inputs)=2;
	float mult(inputs)=3;
	float div(inputs)=4;
	float pot(inputs)=5;
	}=1;
}=0x2ffffffff;
