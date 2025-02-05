<h1>SDR-CAP</h1>
<p align="center">
  <img src="https://i.ibb.co/5v97yzm/sdr-cap.jpg" width=300px; heigth=300px;>
</p>
<p> &ensp; SDR-CAP by csshark is a network sniffer solution built on the OpenWifi project. It leverages an SDR FPGA-based architecture to capture and analyze network packets. Project includes a custom driver that enables the representation of network packets for effective analysis. You can also find detailed instructions for building the openwifi project on which SDR-CAP is based in the project directory. The ability to save captured traffic to a .pcap file for further analysis has also been introduced.</p>
<p>Project relies on version <b>2023.2</b> of the OpenWifi image. It is also possible to compile my driver for 2021.1. version.</p>

<h2>Output products</h2>
<ul>
    <li>FPGA-based network packet sniffer</li>
    <li>Custom driver for packet representation</li>
    <li>Output .pcap file to analysis</li>
    <li>User-Friendly Build FPGA Guide for the OpenWifi project</li>
    <li>Automated building OpenWifi script</li>
    <li>Vivado IPcore comparison script</li>
</ul>

<h2>Getting Started</h2>

<p>You are in the <code>openwifi_build_only_2021.1</code> branch. This branch supports building OpenWifi project in 2021.1 version <b>only</b>.</p>

<h3>Prerequisites</h3>
<ul>
    <li>Ubuntu 20.04LTS/22.04LTS/24.04LTS</li>
    <li>Xilinx Vivado 2021.1</li>
    <li>Petalinux Tools 2021.1</li>
    <li>AMD Vitis 2021.1</li>
    <li>SDR ADRV9361-Z7035</li>
    <li>microSD card <=16GB</li>
    <li>Valid Vivado License</li>
</ul>
<p><b>Note: </b>Ubuntu 24.04LTS might require manual installation of some packages from source, previous distributions are recommended.</p>
      
<h3>Build Sniffer-Chip Steps:</h3>
<ol>
    <li>Clone the repository:
        <pre><code>git clone https://github.com/csshark/sdr-cap.git
cd sdr-cap</code></pre>
      <li>Build OpenWifi image from my tutorial.</li>
      <li>Compile my sniffer after placing it into user space. (Check <a href="/openwifi2023-petalinux/README.md">driver installation</a>)</li>
    </li>
    <li>Run the script (current location is /root/openwifi/):
        <pre><code>./sniff.sh</code></pre>
    </li>
</ol>
<p>output should be written into "capture.pcap" file</p>

<h2>Packet Capture</h2>
<img src="/Screenshots/Sniffer-final.png" alt="Screenshot 2" />
<p>SDR-CAP represents user friendly frame design of captured packets, including source, destination, IP and protocol.</p>
<img src="/Screenshots/pcap.png" alt="Screenshot 3" />
<p>.pcap file is kept in openwifi dir (now it is in sniff dir!)</p>
<h2>License</h2>
<p>This project is licensed under the AGPL License. See the <a href="LICENSE">LICENSE</a> file for details.</p>

<h2>Acknowledgements</h2>
<ul>
    <li><a href="https://github.com/open-sdr/openwifi">OpenWifi</a> project contributors</li>
    <li><a href="https://www.wireshark.org/">Wireshark</a> for inspiration</li>
    <li><a href="https://www.amd.com/en/corporate/xilinx-acquisition.html">AMD Xilinx and Analog Devices Inc.</a></li>
</ul>

<h2>Additional Information</h2>
<p>For any questions or issues, feel free to open an issue in the GitHub repository or contact the project maintainers. When you got into any troubles while building OpenWifi reach <a href="https://github.com/open-sdr/openwifi"/>Openwifi</a> issues and common problems support.</p>
<p><b>Note:</b> SDR-CAP is going to be developed on its own. That means the OFDM and system structure is going to be created by me.</p>
<p>For now it is just fixed openwifi + migration tutorial with additional packet capture tool.</p>
