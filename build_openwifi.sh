#!/bin/bash
# Simple automated bash script by csshark
#Currently not tested, do not trust it 100%

echo "Please enter the path to the XILINX_DIR:"
read XILINX_DIR

echo "Please enter the BOARD_NAME:"
read BOARD_NAME

echo "Please enter the path to the openwifi-hw directory:"
read OPENWIFI_HW_DIR

echo "Please enter the path to the openwifi directory:"
read OPENWIFI_DIR

echo "Please enter the path to the openwifi-hw-img directory:"
read OPENWIFI_HW_IMG_DIR

git clone https://github.com/open-sdr/openwifi-hw.git $OPENWIFI_HW_DIR
git clone https://github.com/open-sdr/openwifi.git $OPENWIFI_DIR
git clone https://github.com/open-sdr/openwifi-hw-img.git $OPENWIFI_HW_IMG_DIR

cd $OPENWIFI_HW_DIR/adi-hdl/
git clone -b hdl_2021_r1 https://github.com/analogdevicesinc/hdl.git
mv hdl/* .

git clone -b xlnx_rebase_v6.1_LTS https://github.com/Xilinx/linux-xlnx.git

rm $OPENWIFI_DIR/driver/xilinx_dma/xilinx_dma.c
cp linux-xlnx/drivers/dma/xilinx_dma.c $OPENWIFI_DIR/driver/xilinx_dma/

cd $OPENWIFI_HW_DIR/
./prepare_adi_lib.sh $XILINX_DIR
./get_ip_openofdm_rx.sh

mv $OPENWIFI_HW_IMG_DIR/boards/$BOARD_NAME/sdk $OPENWIFI_DIR/kernel_boot/boards/$BOARD_NAME/

cd $OPENWIFI_HW_DIR/boards/$BOARD_NAME
../create_ip_repo.sh $XILINX_DIR

echo "Full project preparation is done. Now run Vivado 2021.1 and type \"source ./openwifi.tcl\""
