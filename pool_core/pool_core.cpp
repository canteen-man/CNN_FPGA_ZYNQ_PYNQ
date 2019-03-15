#include "pool_core.h"

#define max(a,b) ((a>b)?a:b)
#define min(a,b) ((a>b)?b:a)

void Pool(ap_uint<16> CHin,ap_uint<16> Hin,ap_uint<16> Win,
		ap_uint<8> Kx,ap_uint<8> Ky,ap_uint<2> mode,
		Dtype_f feature_in[],Dtype_f feature_out[]
	)//mode: 0:MEAN, 1:MIN, 2:MAX
{
	#pragma HLS INTERFACE m_axi depth=4294967295 port=feature_out offset=slave
	#pragma HLS INTERFACE m_axi depth=4294967295 port=feature_in offset=slave
	#pragma HLS INTERFACE s_axilite port=Win
	#pragma HLS INTERFACE s_axilite port=Kx
	#pragma HLS INTERFACE s_axilite port=Hin
	#pragma HLS INTERFACE s_axilite port=mode
	#pragma HLS INTERFACE s_axilite port=Ky
	#pragma HLS INTERFACE s_axilite port=CHin
	#pragma HLS INTERFACE s_axilite port=return
	ap_uint<16> Hout,Wout;
	Wout=Win/Kx;
	Hout=Hin/Ky;

	for(int c=0;c<CHin;c++)
		for(int i=0;i<Hout;i++)
			for(int j=0;j<Wout;j++)
			{
				Dtype_f sum;
				if(mode==0)
					sum=0;
				else
					if(mode==1)
						sum=99999999999999999;
					else
						sum=-99999999999999999;
				for(int ii=0;ii<Ky;ii++)
					for(int jj=0;jj<Kx;jj++)
					{
						ap_int<16> h=i*Ky+ii;
						ap_int<16> w=j*Kx+jj;
						switch(mode)
						{
							case 0:{sum+=feature_in[h*CHin*Win+w*CHin+c];break;}
							case 1:{sum=min(sum,feature_in[h*CHin*Win+w*CHin+c]);break;}
							case 2:{sum=max(sum,feature_in[h*CHin*Win+w*CHin+c]);break;}
							default:break;
						}
					}
				if(mode==0)
					sum=sum/(Kx*Ky);
				feature_out[i*Wout*CHin+j*CHin+c]=sum;
			}
}
