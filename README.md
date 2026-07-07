# Network Traffic Analyzer

A from-scratch implementation of network packet sniffers designed to capture and dissect raw network traffic. This project bypasses high-level GUI tools like Wireshark to interact directly with network interfaces, providing a deep dive into OSI Layer 2 and Layer 3 encapsulation, raw socket programming, and low-level traffic analysis.

## 📌 Project Overview

This repository contains two distinct implementations of a packet sniffer, serving as a foundational exercise in network security and threat detection:

1. **Python Prototype (`sniffer.py`):** Utilizes Python's built-in `socket` and `struct` modules to read and unpack raw binary data directly from the OS network device driver (AF_PACKET). 
2. **C++ Engine (`sniffer.cpp`):** A high-performance implementation utilizing `libpcap` (the same industry-standard library that powers Wireshark and Nmap/tcpdump). 

## ⚙️ Features

* **Raw Ethernet Parsing:** Strips and parses the 14-byte Ethernet header.
* **MAC Address Extraction:** Identifies and formats Source and Destination MAC addresses (including OUI identification for multicast/broadcast traffic).
* **Protocol Identification:** Extracts the EtherType (e.g., `0x0800` for IPv4) to determine the encapsulated payload.
* **Promiscuous Mode Capture:** Configured to capture all traffic crossing the network interface, not just traffic destined for the host machine.

## 🚀 Prerequisites & Installation

These tools are built for Linux environments (tested on Kali Linux) and require elevated privileges to access raw sockets and network interfaces.

### Dependencies
For the C++ implementation, you must have the `libpcap` development headers installed:
```bash
sudo apt update
sudo apt install libpcap-dev -y