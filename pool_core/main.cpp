#include "stdio.h"
#include "pool_core.h"

#define MODE 	0	//mode: 0:MEAN, 1:MIN, 2:MAX
#define IN_WIDTH 6
#define IN_HEIGHT 6
#define IN_CH 1

#define KERNEL_WIDTH 3
#define KERNEL_HEIGHT 3

#define OUT_WIDTH (IN_WIDTH/KERNEL_WIDTH)
#define OUT_HEIGHT (IN_HEIGHT/KERNEL_HEIGHT)

int main(void)
{
	Dtype_f feature_in[IN_HEIGHT][IN_WIDTH][IN_CH];
	Dtype_f feature_out[OUT_HEIGHT][OUT_WIDTH][IN_CH];

	for(int i=0;i<IN_HEIGHT;i++)
		for(int j=0;j<IN_WIDTH;j++)
			for(int cin=0;cin<IN_CH;cin++)
				feature_in[i][j][cin]=i*IN_WIDTH+j;

	Pool(IN_CH,IN_HEIGHT,IN_WIDTH,
			KERNEL_WIDTH,KERNEL_HEIGHT,MODE,
			feature_in[0][0],feature_out[0][0]
		);//mode: 0:MEAN, 1:MIN, 2:MAX

	for(int i=0;i<OUT_HEIGHT;i++)
		for(int j=0;j<OUT_WIDTH;j++)
			for(int cout=0;cout<IN_CH;cout++)
			{
				printf("OUT[%d][%d][%d]=%f\n",i,j,cout,feature_out[i][j][cout]);
			}
}
