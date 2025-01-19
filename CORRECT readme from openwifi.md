<h1>Personal Discovery on <a href="https://github.com/open-sdr/openwifi-hw/?tab=readme-ov-file#build-fpga">Building FPGA</a> with OpenWifi</h1>

<p>This is my own discovery of how to perform actions from the <a href="https://github.com/open-sdr/openwifi-hw">open-sdr/openwifi-hw</a> README instructions for building FPGA. Many of the steps are in the wrong order, and the file structure is wrong/uncomplete. Corrections are made on the OpenWifi(main branch) directory structure current for: 19.01.2025. If the developers of the openwifi project have made changes to their project, I am not responsible for the undesired actions of my sh file. </p>
<h2>Instruction</h2>
<p>Clone all required repositories:</p>
<pre><code>git clone https://github.com/open-sdr/openwifi-hw.git && git clone https://github.com/open-sdr/openwifi.git && git clone && git clone https://github.com/open-sdr/openwifi-hw-img.git</code></pre>

<p>After cloning <code>openwifi</code>, <code>openwifi-hw</code>, and <code>openwifi-hw-img</code>, it is necessary to visit <a href="https://github.com/analogdevicesinc/hdl/tree/f61d9707eb0a62533efd6facab59ab2444da94c9">analogdevicesinc/hdl</a>, find the <code>hdl_2021_r1</code> branch, and clone it into <code>/openwifi-hw/adi-hdl</code> directory using:</p>

<pre><code>cd /openwifi-hw/adi-hdl/
git clone -b hdl_2021_r1 https://github.com/analogdevicesinc/hdl.git
# make sure to move all the subfolders and files into /adi-hdl directory  
</pre></code>

<h3>Example Structure:</h3>
<pre><code>openwifi-hw</code>
<code>|</code>
<code>|</code>
<code>L adi-hdl</code>
<code>      L docs</code>
<code>      L library</code>
<code>      L projects</code></pre>
  
<h2>Environment Variables</h2>

<pre><code>export XILINX_DIR=/tools/Xilinx
export BOARD_NAME=adrv9361z7035
</code></pre>

<b>NOTE:</b>If you want to migrate project to higher version afterwards, replace xilinx_dma.c with original xilinx_dma.c from <a href="https://github.com/Xilinx/linux-xlnx/tree/xlnx_rebase_v6.1_LTS/drivers/dma/xilinx">Xilinx</a> to openwifi/driver/xilinx_dma/. This method is provided in my <a href="https://github.com/csshark/sdr-cap/blob/main/build_openwifi.sh">automated building script</a>, so it's recommended to run it via .sh file.

<h2>Preparing Adi Libs</h2>

<p>Now prepare Analog Devices HDL library:</p>
<code>./prepare_adi_lib.sh $XILINX_DIR</code>

<h2>Building IP Cores</h2>

<p>Navigate to <code>/openwifi-hw</code> and build IP cores first with <code>./get_ip_openofdm_rx.sh</code>

<pre><code>./get_ip_openofdm_rx.sh</code></pre>
<h2>Preparing board</h2>

<p>It's required to move the "sdk" directory from <code>/openwifi-hw-img/boards/adrv9361z7035</code> to <code>/openwifi/kernel_boot/boards/adrv9361z7035</code></p>
<pre><code>./prepare_adi_board_ip.sh $XILINX_DIR $BOARD_NAME</code></pre>

<h2>Generating IPcores</h2>

<pre><code>cd openwifi-hw/boards/$BOARD_NAME/
../create_ip_repo.sh $XILINX_DIR
</code></pre>

<h2>Vivado Setup</h2>

<p>In Vivado 2021.1 in the Tcl console:</p>

<pre><code>source ./openwifi.tcl
# wait for Vivado to finish building and generate bitstream.
</code></pre>

<h3>Upgrading to a higher version:</h3>

<p>Build Project on Higher version of Vivado and do autoupgrading of IPcores. I highly recommend to check meta-adi repository before targeting <code>master</code> branch. You can additionally use <a href="https://github.com/csshark/sdr-cap/blob/main/VivadoComparer.sh">VivadoComparer.sh</a> to verify what changed in new relese and what should you rebuild manually.</p>
