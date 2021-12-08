#!/bin/bash

# Get Absolute old path
OLD_PATH=$(pwd)

# Change to this directory
cd "$(dirname "$0")/.." || exit

# Install:
echo "Install for User:"

# Install Librarys:
echo "Install Librarys:"

# Moving the shared object to a standard location
sudo cp "./lib/libDS.so" "/usr/lib/DS/"
sudo cp "./lib/libDS.a" "/usr/lib/DS/"
sudo chmod 755 "/usr/lib/DS/libDS.so"
sudo chmod 755 "/usr/lib/DS/libDS.a"

# Install Binaries:
echo "Install Binaries:"

# Moving the shared object to a standard location
sudo cp "./bin/*" "/usr/bin/DS/"
sudo chmod 755 "/usr/bin/DS/*" # TODO: change only this files

# Install Includes:
echo "Install Includes:"

# Moving the shared object to a standard location
sudo cp "./include/*" "/usr/include/DS/"
sudo chmod 555 "/usr/include/DS/*" # TODO: change only this files

# Install Menuals:
echo "Install Menuals:"

sudo cp "./doc/*" "/usr/man/DS/"
sudo chmod 555 "/usr/man/DS/*" # TODO: change only this files

# Install Configurations:
echo "Install Configurations:"

sudo cp "./config/*" "/etc/DS/conf"
sudo chmod 555 "/etc/DS/conf/*" # TODO: change only this files

# Install Logs:
echo "Install Logs:"

sudo cp "./log/*" "/var/log/DS/"
sudo chmod 555 "/var/log/DS/*" # TODO: change only this files

# Install Runs:
echo "Install Runs:"

sudo cp "./run/*" "/var/run/DS/"
sudo chmod 555 "/var/log/DS/conf/*" # TODO: change only this files

# Install Modules:
echo "Install Modules:"

sudo cp "./modules/*" "/usr/lib/DS/modules"
sudo chmod 555 "/var/log/DS/conf/*" # TODO: change only this files

# Return to the old path
cd "$OLD_PATH" || exit
