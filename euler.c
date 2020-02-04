#include "tinyexpr.h"
#include <stdio.h>
#include <string.h>
#define MAX_SIZE 128
#define VALUE_SIZE 10
double replace_expr(const char c[], double x, double y)
{
	char x_value[VALUE_SIZE];
	char y_value[VALUE_SIZE];
	sprintf(x_value,"%lf",x);
	sprintf(y_value,"%lf",y);
	char c_value[MAX_SIZE];
	strcpy(c_value,c);
	int i = 0;
	while(i < sizeof(c_value))
	{
		if(c_value[i] == 'x')
		{
			char temp_c_value[MAX_SIZE];
			strcpy(temp_c_value,&(c_value[i+1]));
			strcpy(&(c_value[i+VALUE_SIZE-2]),temp_c_value);
			int j;
			for(j = 0; j < VALUE_SIZE-2; ++j)
				c_value[i+j] = x_value[j];
		}
		else if(c_value[i] == 'y')
		{
			char temp_c_value[MAX_SIZE];
			strcpy(temp_c_value,&(c_value[i+1]));
			strcpy(&(c_value[i+VALUE_SIZE-2]),temp_c_value);
			int j;
			for(j = 0; j < VALUE_SIZE-2; ++j)
				c_value[i+j] = y_value[j];
		}
		++i;
	}
	return te_interp(c_value,0);
}
int main(int argc, char *argv[])
{
    	char c[MAX_SIZE];
    	double x;
	double goal_x;
    	double y;
    	double h;
    	printf("y':");
    	scanf("%s",c);
    	printf("Initial x:");
    	scanf("%lf",&x);
    	printf("Initial y:");
    	scanf("%lf",&y);
    	printf("Target x:");
    	scanf("%lf",&goal_x);
    	printf("Size of the step:");
    	scanf("%lf",&h);
	if(goal_x < x)
	{
		h = -h;
		while(x > goal_x)
		{
			double y_predict_next = y + h*replace_expr(c,x,y);
			y = y + h*(replace_expr(c,x,y)+replace_expr(c,x+h,y_predict_next))/2;
			x = x + h;
		}
	}
	else
	{
		while(x < goal_x)
		{
			double y_predict_next = y + h*replace_expr(c,x,y);
			y = y + h*(replace_expr(c,x,y)+replace_expr(c,x+h,y_predict_next))/2;
			x = x + h;
		}
	}
	printf("Answer:%lf\n",y);
    	return 0;
}
