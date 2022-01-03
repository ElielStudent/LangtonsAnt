# LangtonsAnt
A simulation of the cellular automata Langton's Ant written in c++ using SFML. 
The rules of the ant are as follows:
At a white square, turn 90° clockwise, flip the color of the square, move forward one unit
At a black square, turn 90° counter-clockwise, flip the color of the square, move forward one unit
Simple rules lead to complex, unexpected behavior.


## Program in action

### First ~200 steps of the simulation.

https://user-images.githubusercontent.com/47519297/147928001-bc60a128-180c-45e4-9a35-ab2201bbda80.mp4

### At around 10,000 steps, the and goes into a loop known as "the highway".

<img src="https://user-images.githubusercontent.com/47519297/147925682-cf9b38da-2fa2-40aa-a356-b0844c84b622.png" width="400" height="400"> 

### The simulation can be tweaked to contain multiplecolors, different rules,  or more ants.

https://user-images.githubusercontent.com/47519297/147928006-e9db3938-ccab-408d-a9cb-25cfda2dbb38.mp4
