#include "stdio.h"
#include "conv_core.h"

#define IN_WIDTH 10
#define IN_HEIGHT 10
#define IN_CH 16

#define KERNEL_WIDTH 5
#define KERNEL_HEIGHT 5
#define X_STRIDE 1
#define Y_STRIDE 1

#define RELU_EN  0
#define MODE     0          //0:VALID, 1:SAME
#define X_PADDING (MODE?(KERNEL_WIDTH-1)/2:0)
#define Y_PADDING (MODE?(KERNEL_HEIGHT-1)/2:0)

#define OUT_CH 1
#define OUT_WIDTH ((IN_WIDTH+2*X_PADDING-KERNEL_WIDTH)/X_STRIDE+1)
#define OUT_HEIGHT ((IN_HEIGHT+2*Y_PADDING-KERNEL_HEIGHT)/Y_STRIDE+1)

int main(void)
{
	Dtype_f feature_in[IN_HEIGHT][IN_WIDTH][IN_CH];
	Dtype_w W[KERNEL_HEIGHT][KERNEL_WIDTH][IN_CH][OUT_CH];
	Dtype_w bias[OUT_CH];
	Dtype_f feature_out[OUT_HEIGHT][OUT_WIDTH][OUT_CH];

	for(int i=0;i<IN_HEIGHT;i++)
		for(int j=0;j<IN_WIDTH;j++)
			for(int cin=0;cin<IN_CH;cin++)
				feature_in[i][j][cin]=i*IN_WIDTH+j;

	for(int i=0;i<KERNEL_HEIGHT;i++)
		for(int j=0;j<KERNEL_WIDTH;j++)
			for(int cin=0;cin<IN_CH;cin++)
				for(int cout=0;cout<OUT_CH;cout++)
					W[i][j][cin][cout]=i*KERNEL_WIDTH+j;

	for(int cout=0;cout<OUT_CH;cout++)
		bias[cout]=0;

	printf("1234\n");

	Conv(IN_CH,IN_HEIGHT,IN_WIDTH,OUT_CH,
			KERNEL_WIDTH,KERNEL_HEIGHT,X_STRIDE,Y_STRIDE,MODE,RELU_EN,
			feature_in[0][0],W[0][0][0],bias,feature_out[0][0]
		);

	for(int i=0;i<OUT_HEIGHT;i++)
		for(int j=0;j<OUT_WIDTH;j++)
			for(int cout=0;cout<OUT_CH;cout++)
			{
				printf("OUT[%d][%d][%d]=%f\n",i,j,cout,feature_out[i][j][cout]);
			}

	return 0;
}
