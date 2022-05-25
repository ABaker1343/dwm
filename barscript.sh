#!/bin/bash

status () {
    echo -n "Battery: $(acpi | awk '{print $4}' | sed -n '2p') Vol: $(pactl get-sink-volume 0 | awk '{print $5}') $(date)"
}

while true
do
xsetroot -name "$(status)"
sleep 1
done
