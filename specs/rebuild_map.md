# Pseudocode for Recreating the Map

## 1. Initialize Variables
✅ Set up necessary variables to store map metadata (such as height, width) and the map data itself.


## 2. Count the Number of Map Lines
- Start reading the file from the given starting index.
- For each line in the file:
  - Skip leading whitespace characters (spaces, tabs, etc.).
  - Check if the line starts with the character '1'.
  - If it does, count this line as a valid map line.
  - Continue until a line does not start with '1'.
- Store the number of valid map lines.

## 3. Determine Map Dimensions
- Find the width of the widest valid map line by checking the length of each line.
- This width will be the map's width.

## 4. Allocate Memory for the Map
- Allocate a two-dimensional array of characters (`char**`) for the map.
- The size of the array should be `(map height + 1)` by `(map width + 1)` to accommodate all map lines and a null terminator.

## 5. Fill the Map Data
- Loop through each valid map line:
  - Copy characters from the source file line to the corresponding position in the map array.
  - If the line is shorter than the map width, fill the remaining positions with the null character (`\0`).

## 6. Convert Spaces to Walls
- Loop through each line of the map:
  - For each character in the line, if it is a space surrounded by non-space characters, replace it with a `'1'`.

## 7. Final Adjustments and Output
- Ensure the map array ends with a null pointer (`map[height] = NULL`).
- Return the map or indicate success/failure of the map creation process.

