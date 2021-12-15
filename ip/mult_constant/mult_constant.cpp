#include "ap_axi_sdata.h"
#include "hls_stream.h"

typedef ap_axis<32,1,1,1> stream_type;

void mult_constant(hls::stream< stream_type > &in_data, hls::stream< stream_type > &out_data, ap_int<32> constant_r ){
#pragma HLS INTERFACE s_axilite register port=constant_r
#pragma HLS INTERFACE ap_ctrl_none port=return
#pragma HLS INTERFACE axis port=in_data
#pragma HLS INTERFACE axis port=out_data

	stream_type temp;

	while(1)
	{
		in_data.read(temp);
		temp.data = temp.data.to_int() * constant_r;
		out_data.write(temp);
		if(temp.last)
		{
			break;
		}
	}

}
