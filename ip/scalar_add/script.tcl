open_project scalar_add
set_top add
add_files scalar_add/add.cpp
open_solution "solution1"
set_part {xc7z020clg484-1} -tool vivado
create_clock -period 10 -name default
#source "./scalar_add/solution1/directives.tcl"
#csim_design
csynth_design
#cosim_design
export_design -format ip_catalog
exit
