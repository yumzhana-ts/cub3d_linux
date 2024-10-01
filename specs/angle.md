If your player_angle is set to 3π/2, this angle corresponds to 270 degrees in radians, which points directly downward in the standard mathematical coordinate system.

However, in many graphical systems (including libraries like MiniLibX, which you might be using in this case), the y-axis is inverted: positive y values increase downwards on the screen, not upwards as in a traditional Cartesian plane.

Let's break this down:

3π/2 means the player is facing downward.
Using cos(3π/2) gives 0 for the x-component (no movement horizontally).
sin(3π/2) gives -1, meaning movement downwards on a typical Cartesian plane.
But in your graphical system, if positive y values point downwards, this would move your "ray" upwards, which is not what you want.