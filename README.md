# cub3D

[![cboutier's 42 cub3d Score](https://badge42.vercel.app/api/v2/cl1f9y1k8000609jsc4a29jay/project/2431470)](https://github.com/JaeSeoKim/badge42)

Validated on December 22nd, 2021

121/100 with bonuses

Project was implemented with the 42 Minilibx, and is **ONLY** working on Linux.

This project is inspired by the world-famous Wolfenstein 3D game, which was the first FPS ever.  
It will enable you to explore ray-casting. Your goal will be to make a dynamic view inside a maze, in which you'll have to find your way.

Bonuses implemented:  
- wall collisions
- minimap
- animated sprites
- POV rotation with the mouse

**Map Error Checking**  
The map must end with a .cub extension.  
The map contains information about:  
- the ceiling and floor color, represented by `C` and `F` respectively, followed by the wanted RGB colors (between 0 and 255).  
- 4 textures paths for each direction:  
    - `NO` for the North walls,  
    - `SO` for the South walls,  
    - `EA` for the East walls,  
    - `WE` for the West walls.  
- a map:
    - `1` represents walls,  
    - `0` represents empty spaces,  
    - `N/S/W/E` which represesents the player position, facing the given direction,  
    - `2` represents animated sprites (only for the bonus).  
If the map is not valid, the program will tell you so.  

**THE PROGRAM**  
- You can use the `W, A, S, D` as well as the `up and down arrows` to move inside the game.  
- You can use the `left and right arrows` to rotate the camera.  
- You can exit the program with the `ESC key` or the red cross.   

**HOW TO RUN THE PROGRAM**   
`make`  
`./cub3D maps/test.cub`  

**RUN THE BONUS VERSION**  
`make bonus`  
`./cub3D_bonus maps/map_bonus.cub`
