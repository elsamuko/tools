#!/usr/bin/env bash
# set random MAC addresses for en0 and en1
# https://www.howtogeek.com/220462/how-to-find-and-change-your-mac-address-on-os-x/
# https://djangocas.dev/blog/mac/how-to-change-mac-network-mac-address/

# exit on error
set -e

MAC0="02:$(openssl rand -hex 5 | sed 's/\(..\)/\1:/g; s/.$//')"
MAC1="02:$(openssl rand -hex 5 | sed 's/\(..\)/\1:/g; s/.$//')"

# -z "Disassociate from any network"
sudo networksetup  -setairportpower en0 off
sudo networksetup  -setairportpower en0 on

echo "Setting en0 MAC address to $MAC0"
sudo ifconfig en0 ether
echo "======================="
sudo ifconfig en0 ether "$MAC0"
sudo ifconfig en0 ether
echo "======================="

sudo networksetup  -detectnewhardware
