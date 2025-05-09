#!/bin/bash
# Simple automayion bash script by csshark
# Tested script - successfully built project on Ubuntu 22.04LTS 
# It provides automated replacement of dma driver directly from Xilinx
echo "Please enter the path to the XILINX_DIR (example: /tools/Xilinx):"
read XILINX_DIR

echo "Please enter the BOARD_NAME (adrv9361z7035):"
read BOARD_NAME

echo "Please enter the path to the openwifi-hw directory (example: /home/frank/openwifi-hw):"
read OPENWIFI_HW_DIR

echo "Please enter the path to the openwifi directory:"
read OPENWIFI_DIR

echo "Please enter the path to the openwifi-hw-img directory:"
read OPENWIFI_HW_IMG_DIR

git clone https://github.com/open-sdr/openwifi-hw.git $OPENWIFI_HW_DIR
git clone https://github.com/open-sdr/openwifi.git $OPENWIFI_DIR
git clone https://github.com/open-sdr/openwifi-hw-img.git $OPENWIFI_HW_IMG_DIR
cd /home
cd $OPENWIFI_HW_DIR/adi-hdl/
git clone -b hdl_2021_r1 https://github.com/analogdevicesinc/hdl.git
mv hdl/* .

git clone -b xlnx_rebase_v6.1_LTS https://github.com/Xilinx/linux-xlnx.git

rm $OPENWIFI_DIR/driver/xilinx_dma/xilinx_dma.c
cp linux-xlnx/drivers/dma/xilinx_dma.c $OPENWIFI_DIR/driver/xilinx_dma/

cd $OPENWIFI_HW_DIR/
./prepare_adi_lib.sh $XILINX_DIR
./get_ip_openofdm_rx.sh


cd $OPENWIFI_HW_DIR/boards/$BOARD_NAME
../create_ip_repo.sh $XILINX_DIR

echo "Full project preparation is done. Now run Vivado 2021.1 and type \"source ./openwifi.tcl\""
