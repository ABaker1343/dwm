#!/bin/sh
sinks=$(pacmd list-sinks | grep name: | awk '{print $2}' | tr -d '<>')

selection=$(echo "$sinks" | dmenu -i)

pacmd set-default-sink $selection
