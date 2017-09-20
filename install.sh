#!/bin/bash

make 

if [ $# = 0 ]
then
    echo "default ip address is www.baidu.com"
    sudo ./ping www.baidu.com
else
    sudo ./ping $1
fi
