#! /bin/bash

pid5=$(pgrep -f test1)
if [ -n "$pid5" ]; then
    echo "Killing test1 process with PID $pid5"
    kill $pid5
else
    echo "test1 process not found."
fi

pid6=$(pgrep -f can_node)
if [ -n "$pid6" ]; then
    echo "Killing can_node process with PID $pid6"
    kill $pid6
else
    echo "can_node process not found."
fi

pid7=$(pgrep -f real_time_plot)
if [ -n "$pid7" ]; then
    echo "Killing real_time_plot process with PID $pid7"
    kill $pid7
else
    echo "real_time_plot process not found."
fi

source  /opt/ros/foxy/setup.bash
sleep 1
source install/setup.bash 

# ros2 launch gnss gnss.launch.py  &
# PID3=$!
# sleep 1

ros2 run hmi hmi ->log1.txt &
PID1=$!


rviz2 -d ~/longshan11_6/src/myrviz/default.rviz >/dev/null 2>&1  &
PID2=$!

# Optionally, you can wait for both commands to finish
wait
#Function to kill processes
kill_ros2_processes() {
    echo "Killing ROS 2 processes..."
    # Kill all ros2 related processes
    kill $(ps aux | grep '[r]os2' | awk '{print $2}')

    pid=$(pgrep -f Lidar_Processing_node)
    if [ -n "$pid" ]; then
        echo "Killing Lidar_Processing_node process with PID $pid"
        kill $pid
    else
        echo "Lidar_Processing_node process not found."
    fi
    pid2=$(pgrep -f points_and_lines_publisher)
    if [ -n "$pid2" ]; then
        echo "Killing points_and_lines_publisher process with PID $pid2"
        kill $pid2
    else
        echo "points_and_lines_publisher process not found."
    fi

    pid3=$(pgrep -f can_node)
    if [ -n "$pid3" ]; then
        echo "Killing can_node process with PID $pid3"
        kill $pid3
    else
        echo "can_node process not found."
    fi

    pid4=$(pgrep -f gnss_node)
    if [ -n "$pid4" ]; then
        echo "Killing gnss_node process with PID $pid4"
        kill $pid4
    else
        echo "gnss_node process not found."
    fi

    pid5=$(pgrep -f gnss_sync_node)
    if [ -n "$pid5" ]; then
        echo "Killing gnss_sync_node process with PID $pid5"
        kill $pid5
    else
        echo "gnss_sync_node process not found."
    fi

    pid8=$(pgrep -f real_time_plot)
    if [ -n "$pid8" ]; then
        echo "Killing real_time_plot process with PID $pid8"
        kill $pid8
    else
        echo "real_time_plot process not found."
    fi
}


# Trap function to ensure processes are killed on script exit
trap "kill_ros2_processes" EXIT
echo "Both commands started successfully. Waiting for processes to finish..."
sleep 1
echo "Exiting script."
