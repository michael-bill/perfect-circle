# PerfetCircle exploit

A program to draw a perfect circle in the game "Perfect Circle".
For MacOS.

![demo](https://github.com/michael-bill/PerfectCircle/blob/main/demo.gif)

Build:
```
gcc -o perfcir.out main.c -framework ApplicationServices
```

Execute:
```
./perfcir.out
```
Or
```
./perfcir.out -wait 5000 -steps 40 -sleep 60 -r 250
```
Where:
``-wait <time in milliseconds>`` - First wait time for mouse hovering on the circle center.<br/>
``-steps <number of steps>`` - Number of steps to draw a circle (the more steps, the smoother the circle).``<br/>
``-sleep <time in milliseconds>`` - Time in milliseconds expected after each step.<br/>
``-r <radius in pixels>`` - Radius of the circle to be drawn in pixels .<br/>