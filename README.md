# A* Pathfinder
![](res/preview.gif)

[A* Pathfinding Algorithm] allows users to find the shortest paths from point A to point B on a weighted graph.

This application visualizes how the algorithm would work on a 'weightless' grid: it checks the cells that are the closest to both start and goal cells and traverses further until it reaches the goal.

## How to build [for Windows]
1. Build the SFML library accroding to this tutorial: https://www.sfml-dev.org/tutorials/2.5/compile-with-cmake.php
2. Run "build.bat"
3. Run /res/AStarPathfinder.exe

## How to use:
- Firstly, enter the size of the grid you would like to have and hit 'Enter'. 
- Now you are able to place start/end cells and obstacles ['walls']: pressing Z and clicking on the grid allows you to place the starting node, pressing X and hovering over the screen with the left mouse button pressed enables you to draw obstacles and by pressing C and clicking on the grid you are able to set the finish cell. 
- After your obstacle course is set press 'Enter' and watch the algorithm work out how to get from the starting node to the ending node. Red nodes are the nodes that have already been traversed, green nodes mean that the algorithm may consider checking and the yellow nodes will show the shortest path.

[A* Pathfinding Algorithm]: <https://en.wikipedia.org/wiki/A*_search_algorithm>
