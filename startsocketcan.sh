#! /bin/bash


pid=$(pgrep -f test1)
if [ -n "$pid" ]; then
    echo "Killing test1 process with PID $pid"
    kill $pid
else
    echo "test1 process not found."
fi
pid2=$(pgrep -f can_node)
if [ -n "$pid2" ]; then
    echo "Killing can_node process with PID $pid2"
    kill $pid2
else
    echo "can_node process not found."
fi

source  /opt/ros/foxy/setup.bash
sleep 1

source install/setup.bash 

ros2 launch can can.launch.py
wait 

pid3=$(pgrep -f test1)
if [ -n "$pid3" ]; then
    echo "Killing test1 process with PID $pid3"
    kill $pid3
else
    echo "test1 process not found."
fi
pid4=$(pgrep -f can_node)
if [ -n "$pid4" ]; then
    echo "Killing can_node process with PID $pid4"
    kill $pid4
else
    echo "can_node process not found."
fi

