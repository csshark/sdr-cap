#!/bin/bash


SNIFF_DIR="sniff"


if [ ! -d "$SNIFF_DIR" ]; then
    echo "Directory $SNIFF_DIR does not exist."
    exit 1
fi


cd "$SNIFF_DIR"


echo "Starting the packet sniffer on the board... (iface:sdr0)"
sudo ./packet_sniffer sdr0 capture.pcap
