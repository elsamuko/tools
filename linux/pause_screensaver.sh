#!/usr/bin/env bash
# pause xcreensaver while script is running

while true; do
    xscreensaver-command -deactivate
    sleep 300
done
