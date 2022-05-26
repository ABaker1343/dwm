#!/bin/bash

status () {
    MEMTOTAL=$(cat /proc/meminfo | grep MemTotal | awk '{print $2}')
    MEMAVAILABLE=$(cat /proc/meminfo | grep MemAvailable | awk '{print $2}')
    echo -n "Battery: $(acpi | awk '{print $4}' | sed -n '2p') | Vol: $(pactl get-sink-volume 0 | awk '{print $5}') | Mem: $(( ($MEMTOTAL - $MEMAVAILABLE)/1000 ))MB | $(date)"
}
while true
do
xsetroot -name "$(status)"
sleep 1
done
