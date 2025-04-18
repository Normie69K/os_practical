#!/bin/bash

echo "---------------------------------------------"
echo "i) OS Version, Release Number, and Kernel Version"
echo "---------------------------------------------"
# Display OS version and release info
cat /etc/os-release | grep -E '^NAME=|^VERSION='
# Display kernel version
uname -r

echo
echo "---------------------------------------------"
echo "ii) Top 10 Processes (by CPU usage)"
echo "---------------------------------------------"
ps -eo pid,ppid,cmd,%mem,%cpu --sort=-%cpu | head -n 11

echo
echo "---------------------------------------------"
echo "iii) Current Logged-in User and Logname"
echo "---------------------------------------------"
echo "User: $(whoami)"
echo "Logname: $LOGNAME"

echo
echo "---------------------------------------------"
echo "iv) Top 10 Processes (by Memory usage)"
echo "---------------------------------------------"
ps -eo pid,ppid,cmd,%mem,%cpu --sort=-%mem | head -n 11

echo
echo "---------------------------------------------"
echo "v) Current Shell, Home Directory, OS Type, and Current Path"
echo "---------------------------------------------"
echo "Current Shell: $SHELL"
echo "Home Directory: $HOME"
echo "OS Type: $(uname -o)"
echo "Current Path: $(pwd)"

echo
echo "✔️ Script execution complete!"
