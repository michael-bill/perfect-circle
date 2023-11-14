# Perfet Circle Exploit

A program to draw a perfect circle in the game "Perfect Circle". For MacOS.<br/>

demo.gif:<br/>
![demo.gif](https://github.com/michael-bill/perfect-circle/blob/main/demo.gif)

YouTube video demonstration: [Video](https://youtu.be/yiQiI4sCMZU?si=Xd2v83n2IgLJrpIG)<br/>
Link to the game: [Perfect Circle Game](https://neal.fun/perfect-circle/)

### Build:
```
gcc -o perfect.out main.c -framework ApplicationServices
```

### Execute:
```
./perfect.out
```
### Or execute with parameters:
```
./perfect.out -wait 5000 -steps 40 -sleep 60 -r 250
```
### Where:
``-wait <time in milliseconds>`` - First wait time for mouse hovering on the circle center.<br/>
``-steps <number of steps>`` - Number of steps to draw a circle (the more steps, the smoother the circle).<br/>
``-sleep <time in milliseconds>`` - Time in milliseconds expected after each step.<br/>
``-r <radius in pixels>`` - Radius of the circle to be drawn in pixels .<br/>
