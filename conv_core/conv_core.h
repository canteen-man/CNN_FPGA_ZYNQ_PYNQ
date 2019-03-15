#ifndef __CONV_CORE_H__
#define __CONV_CORE_H__

#include <ap_int.h>
#include <iostream>

using namespace std;

//typedef ap_int<8> Dtype_f;
//typedef ap_int<8> Dtype_w;
//typedef ap_int<15> Dtype_mul;
//typedef ap_int<32> Dtype_acc;

typedef float Dtype_f;
typedef float Dtype_w;
typedef float Dtype_mul;
typedef float Dtype_acc;

void Conv(ap_uint<16> CHin,ap_uint<16> Hin,ap_uint<16> Win,ap_uint<16> CHout,
		ap_uint<8> Kx,ap_uint<8> Ky,ap_uint<8> Sx,ap_uint<8> Sy,ap_uint<1> mode,ap_uint<1> relu_en,
		Dtype_f feature_in[],Dtype_w W[],Dtype_w bias[],Dtype_f feature_out[]
	);//mode: 0:VALID, 1:SAME


#endif
