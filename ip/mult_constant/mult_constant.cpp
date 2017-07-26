#include "ap_axi_sdata.h"
#include "ap_int.h"

typedef ap_axiu<32,1,1,1> stream_type;

void mult_constant(stream_type* in_data, stream_type* out_data, ap_int<32> constant) {
#pragma HLS INTERFACE s_axilite register port=constant
#pragma HLS INTERFACE ap_ctrl_none port=return
#pragma HLS INTERFACE axis port=in_data
#pragma HLS INTERFACE axis port=out_data
	out_data->data = in_data->data * constant;
	out_data->dest = in_data->dest;
	out_data->id = in_data->id;
	out_data->keep = in_data->keep;
	out_data->last = in_data->last;
	out_data->strb = in_data->strb;
	out_data->user = in_data->user;

}
