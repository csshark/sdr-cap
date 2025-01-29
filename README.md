<h1>SDR-CAP</h1>
<p align="center">
  <img src="https://i.ibb.co/5v97yzm/sdr-cap.jpg" width=300px; heigth=300px;>
</p>
<p> &ensp; SDR-CAP by csshark is a network sniffer solution built on the OpenWifi project. It leverages an SDR FPGA-based architecture to capture and analyze network packets. Project includes a custom driver that enables the representation of network packets for effective analysis. You can also find detailed instructions for building the openwifi project on which SDR-CAP is based in the project directory. An ISO/OSI model-compliant representation of network packets has been introduced, as well as the ability to explore the flow of network traffic capture, thanks to .pcap file support.</p>

<h2>Output products</h2>
<ul>
    <li>FPGA-based network packet sniffer</li>
    <li>Custom driver for packet representation</li>
    <li>Output .pcap file to analysis</li>
    <li>User-Friendly Build FPGA Guide for the OpenWifi project</li>
    <li>Automated building OpenWifi script</li>
    <li>Vivado IPcore comparison script</li>
    <li>Automated SDR-CAP build script</li>
</ul>

<h2>Getting Started</h2>

<h3>Prerequisites</h3>
<ul>
    <li>Ubuntu 20.04LTS/22.04LTS/24.04LTS</li>
    <li>Xilinx Vivado 2023.2</li>
    <li>Petalinux Tools 2023.2</li>
    <li>Xilinx SDK (if applicable)</li>
    <li>SDR ADRV9361-Z7035</li>
    <li>microSD card <=16GB</li>
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
<p>output should be written into "captured_packets.pcap" file</p>

<h2>Packet Capture</h2>
<img src="/Screenshots/sniff_standard.png" alt="Screenshot 1" />
<img src="/Screenshots/sniff_display.png" alt="Screenshot 2" />
<p>SDR-CAP aplha working.</p>
<img src="/Screenshots/pcap.png" alt="Screenshot 3" />

<h2>License</h2>
<p>This project is licensed under the MIT License. See the <a href="LICENSE">LICENSE</a> file for details.</p>

<h2>Acknowledgements</h2>
<ul>
    <li>OpenWifi project contributors</li>
    <li><a href="https://www.wireshark.org/">Wireshark</a> for inspiration</li>
    <li>AMD Xilinx and Analog Devices Inc.</li>
</ul>

<h2>Additional Information</h2>
<p>For any questions or issues, feel free to open an issue in the GitHub repository or contact the project maintainers.</p>
<p><b>Note:</b>This tool is going to be developed on its own. That means the OFDM and system structure is going to be created by me.</p>
<p>For now it is just fixed openwifi + migration tutorial with additional packet capture tool.</p>
