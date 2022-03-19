#!/usr/bin/env bash
# set random MAC addresses for en0 and en1
# https://www.howtogeek.com/220462/how-to-find-and-change-your-mac-address-on-os-x/

MAC0="$(openssl rand -hex 6 | sed 's/\(..\)/\1:/g; s/.$//')"
MAC1="$(openssl rand -hex 6 | sed 's/\(..\)/\1:/g; s/.$//')"

echo "Setting en0 MAC address to $MAC0"
sudo ifconfig en0 ether "$MAC0"

echo "Setting en1 MAC address to $MAC1"
sudo ifconfig en1 ether "$MAC1"
