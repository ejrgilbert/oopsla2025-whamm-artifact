#!/bin/bash

# Update packages
apt update

ls -al /

echo "Setup packages"
apt-get install python3-full git-all make curl build-essential lsb-release sudo -y || exit 1
