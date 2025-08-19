#!/bin/bash

# Update packages
apt update

ls -al /

echo "Setup packages"
apt-get install python3 git-all make curl build-essential -y
