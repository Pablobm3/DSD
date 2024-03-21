struct inputs{
float a;
float b;
float c;
};


struct vectores{
float float_array1<>;
float float_array2<>;
};







program CALCULATE_PROG1{
	version CALCULATE_VER1{
	
	float sum(inputs)=1;
	float res(inputs)=2;
	float mult(inputs)=3;
	float div(inputs)=4;
	float pot(inputs)=5;
	float vector_sum(vectores) = 6;
        float vector_res(vectores) = 7;
        float vector_mult(vectores) = 8;
	}=1;
}=0x2ffffffff;
