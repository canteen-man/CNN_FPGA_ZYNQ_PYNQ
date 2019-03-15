# CNN_FPGA_ZYNQ_PYNQ
hls code zynq 7020 pynq z2 CNN


step 1：hls code can generate IP  core in vivado hls

step 2：use IP core to build block design in vivado,generate bitstream and tcl

step 3：copy the tcl and bitstream to pynq

step 4: use ARM to configure the FPGA by pynq overlay

this is vivado block design：


![Alt text](https://github.com/canteen-man/CNN_FPGA_ZYNQ_PYNQ/blob/master/vivado1.png)























something else：
zynqnet can't run in the zynq 7020 or pynq. Because  zynq 7020 or pynq don't have enough LUT,BRAM and DSP.
the zynqnet resource requirement：


![Alt text](https://github.com/canteen-man/CNN_FPGA_ZYNQ_PYNQ/blob/master/vivado2.png)











![Alt text](https://github.com/canteen-man/CNN_FPGA_ZYNQ_PYNQ/blob/master/vivado3.png)









the hls source of zynqnet :








![Alt text](https://github.com/canteen-man/CNN_FPGA_ZYNQ_PYNQ/blob/master/vivado5.png)









the block design of zynqnet :










![Alt text](https://github.com/canteen-man/CNN_FPGA_ZYNQ_PYNQ/blob/master/vivado6.png)





In order to compile zynqnet hls code success, I have to comment some hls optimization.Also it need add several include files.









