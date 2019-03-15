# CNN_FPGA_ZYNQ_PYNQ
hls code zynq 7020 pynq z2 CNN
step 1：hls code can generate IP  core in vivado hls
step 2：use IP core to build block design in vivado,generate bitstream and tcl
step 3：copy the tcl and bitstream to pynq
step 4: use ARM to configure the FPGA by pynq overlay

this is vivado block design：




















something else：
zynqnet can't run in the zynq 7020 or pynq. Because  zynq 7020 or pynq don't have enough LUT,BRAM and DSP.
the zynqnet resource requirement：
