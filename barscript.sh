#!/bin/sh

status () {
    echo -n "Battery: $(acpi | awk '{print $4}' | sed -n '2p') | Vol: $(pactl get-sink-volume @DEFAULT_SINK | awk '{print $5}') | Mem: $(( $(free | grep Mem | awk '{print $3}')/1024 ))MB | $(date)"
}

status_without_battery(){
    echo -n "Vol: $(pactl get-sink-volume @DEFAULT_SINK@ | awk '{print $5}') | Mem: $(( $(free | grep Mem | awk '{print $3}')/1024 ))MB | $(date)"
}

if ! command -v acpi
then
    while true
    do
        xsetroot -name "$(status_without_battery)"
        sleep 1
    done
else
    while true
    do
        xsetroot -name "$(status)"
        sleep 1
    done
fi
