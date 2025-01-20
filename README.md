<h1>SDR-CAP</h1>
<p align="center">
  <img src="https://i.ibb.co/5v97yzm/sdr-cap.jpg" width=300px; heigth=300px;>
</p>
<p> &ensp; SDR-CAP by csshark is a network sniffer solution built on the OpenWifi project. It leverages an SDR FPGA-based architecture to capture and analyze network packets, providing functionality similar to Wireshark. Additionally, it includes a custom driver that enables the representation of network packets for effective analysis. You can also find detailed instructions for building the openwifi project on which SDR-CAP is based in the project directory.</p>

<h2>Output products</h2>
<ul>
    <li>FPGA-based network packet sniffer</li>
    <li>Custom driver for packet representation</li>
    <li>Output .pcap file to analysis.</li>
    <li>User-Friendly Build FPGA Guide for the OpenWifi project</li>
    <li>Automated building OpenWifi script</li>
    <li>Vivado IPcore comparison script</li>
    <li>Automated SDR-CAP build script</li>
</ul>

<h2>Getting Started</h2>

<h3>Prerequisites</h3>
<ul>
    <li>Ubuntu 22.04LTS(tested, but other OS might work too)</li>
    <li>Xilinx Vivado 2023.2</li>
    <li>Xilinx SDK (if applicable)</li>
    <li>SDR ADRV9361-Z7035</li>
    <li>microSD card <=16GB</li>
</ul>

<h3>Build Sniffer-Chip Steps:</h3>
<ol>
    <li>Clone the repository:
        <pre><code>git clone https://github.com/csshark/sdr-cap.git
cd sdr-cap</code></pre>
    </li>
    <li>Run the setup scripts:
        <pre><code>./prepare_hardware.sh</code></pre>
        <pre><code>./inc_tools.sh</code></pre>
    </li>
    <li>Configure your ADRV9361-Z7035 sniffer with net-tools.</li>
    <li>Start capturing network packets.</li>
    <li><code>./capture_start</code></li>
</ol>
<p>output should be written into "cap-current-date-and-time.pcap" file</p>

<h2>Usage</h2>
<p>Instructions on how to use the SDR-CAP tool will go here.</p>

<h2>Packet Capture</h2>
<img src="path/to/screenshot1.png" alt="Screenshot 1" />
<img src="path/to/screenshot2.png" alt="Screenshot 2" />
<img src="path/to/screenshot3.png" alt="Screenshot 3" />

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
