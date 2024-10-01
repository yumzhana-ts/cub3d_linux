Horizontal intersection

- If the Ray is Moving Upwards (i.e., the sine of the angle is positive):
Calculate the next vertical boundary line. This is the grid line immediately above the player's current position.
The distance from the current position to this boundary line is called the "opposite cathetus."
- If the Ray is Moving Downwards (i.e., the sine of the angle is negative or zero):
Calculate the previous vertical boundary line. This is the grid line immediately below the player's current position.
The distance from the current position to this boundary line is also called the "opposite cathetus."
- Calculate the Adjacent Cathetus
The adjacent cathetus is the horizontal distance from the player to the intersection point with the vertical grid line. This can be computed using the tangent of the angle.
- Calculate the Distance (Hypotenuse)
Use the Pythagorean theorem to find the distance from the player to the intersection point. This distance is the hypotenuse of the right triangle formed by the adjacent and opposite catheti.
Update Coordinates
- Calculate the coordinates of the intersection point on the vertical grid line. 
This involves adjusting the player's position by the calculated horizontal distance and setting the vertical coordinate to the boundary line.
- Return the Distance
The final step is to return the calculated distance from the player to the intersection point.

Vertical intersection

- If the Ray is Moving Upwards (i.e., the sine of the angle is positive):
Calculate the next vertical boundary line. This is the grid line immediately above the player's current position.
The distance from the current position to this boundary line is called the "opposite cathetus."
- If the Ray is Moving Downwards (i.e., the sine of the angle is negative or zero):
Calculate the previous vertical boundary line. This is the grid line immediately below the player's current position.
The distance from the current position to this boundary line is also called the "opposite cathetus."
- Calculate the Adjacent Cathetus
The adjacent cathetus is the horizontal distance from the player's position to the intersection point with the vertical grid line. This can be computed using the tangent of the angle:
- Calculate the Distance (Hypotenuse)
Use the Pythagorean theorem to find the distance from the player to the intersection point. This distance is the hypotenuse of the right triangle formed by the adjacent and opposite cathetenus.
- Update Coordinates
Calculate the coordinates of the intersection point on the vertical grid line:
Set the x-coordinate to the player's position plus the calculated adjacent cathetus.
Set the y-coordinate to the boundary line.
- Return the Distance
Return the calculated distance from the player to the intersection point.