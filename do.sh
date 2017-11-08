#!/bin/bash
 
spin=('\' '|' '/' '-')
cnt=6
for i in {1..6}; do
    echo -n "Ready to system...left $((cnt--)) second, please wait... ${spin[$((cnt % 4))]}"
    echo -n -e \\r
    sleep 0.3
done
echo "Welcom to Students Management System\n"
