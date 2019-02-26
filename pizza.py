import numpy as np
import math

# map ingredients to numbers
def mapIngredients(ingredient):
    if ingredient == "T":
        return 2
    elif ingredient == "M":
        return 1
    return 0

# read file and return width, height minimum amount of tomatos/mushrooms per slice, maximal slice size and the pizza
def readFile(path):
    with open(path) as file:
        line = file.readline().split(" ")

        # decode metadata
        rows = int(line[0])
        cols = int(line[1])
        min_ingr_per_slice = int(line[2])
        max_cells_per_slice = int(line[3])

        # read pizza
        pizza = np.zeros((rows, cols))
        for row in range(rows):
            current_row = file.readline()
            for col in range(cols):
                pizza[row][col] = mapIngredients(current_row[col])

        # return result
        return (rows, cols, min_ingr_per_slice, max_cells_per_slice, pizza)

# return all possible shapes for slices
def getPossibleSlices(rows, cols, min_ingr_per_slice, max_cells_per_slice):
    min_cells_per_slice = min_ingr_per_slice * 2
    shapes = set()
    
    # iterate over all valid slice sizes
    for slice_size in range(min_cells_per_slice, max_cells_per_slice + 1):
        
        # iterate over all valid slice lengths
        for slice_length in range(1, int(math.ceil(math.sqrt(slice_size))) + 1):

            # add combinations if the slice length is valid
            if float(slice_size) / slice_length == math.floor(float(slice_size) / slice_length):
                a = slice_length
                b = int(slice_size / slice_length)
                if a <= rows and b <= cols:
                    shapes.add((a, b))
                if b <= rows and a <= cols:
                    shapes.add((b, a))

    return shapes

rows, cols, min_ingr_per_slice, max_cells_per_slice, pizza = readFile("./pizza.txt")
print(getPossibleSlices(rows, cols, min_ingr_per_slice, max_cells_per_slice))
