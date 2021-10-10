# compgeo_visualizer
This is a small project aimed at visualising computational geometry algorithms. The codes are in c++ and simplecpp graphics package is used. Here are short decriptions 
of the programs added currently to this repo:

Conv_hull- Here I used Modified Graham's Scan to find the convex hull of finite number of points taken as interactive input. To use the visualizer, first download 
and open conv_hull.exe file abvailable in exe_files folder. A white canvas will appear with a 'start' button at the top (wait, do not click on it right now!). Now,
you can mark points on the canvas using mouse clicks. Mark as many poiunts as you want and once you are done marking them, click on the start button to start the
real game! On doing so, the program will start constructing the convex hull of the marked points and will show each and evry edge creation and deletion during the 
evolution of algorithm step by step. The program ends after convex hull has been constructed. Click anywhere on the canvas to exit the program.

Triangulation- Here I used Ear-Cutting algorithm to triangulate a simple polygon whose points are taken as interactive input. To use the visualizer, first download 
and open the triangulation.exe file available in the exe_files folder. A white canvas similar to conv_hull.exe will appear on the screen. You can similarly mark 
vertices (in order) on the canvas (the program automatically connects vertices selected consecutively in time) and then click on start to let the program start the
visualization. Afetr doing so, the first and last vertices will be connected and the triangulation part will begin, the program will show all the 'ear-cuts' involved
in the algorithm one by one as they are discovered. After the whole polygon has been triangulated, the program will wait for the user response. Click anywhere on the 
canvas now to exit the program.
Note- While marking the vertices, ensure that no 2 non-adjacent edges intersect otherwise the prograim will give weird results as it is meant to handle simple polygons
only (a triangulation infact may not even exist for a non simple polygon!)
