open_project mult_constant
set_top mult_constant
add_files mult_constant/mult_constant.cpp
open_solution "solution1" -flow_target vivado
set_part {xc7z020clg400-1}
create_clock -period 10 -name default
#source "./mult_constant/solution1/directives.tcl"
#csim_design
csynth_design
#cosim_design
export_design -format ip_catalog -description "Multiply the stream by a user-programmable constant" -vendor "Xilinx" -display_name "Constant Multiply"
exit 
