* This algorithm uses Iteratively deepening depth first search (IDDFS)
    * not a great option for this kind of problem, its inefficient

* start and end positions are initialized as arrays holding base 0 indices
* returns -1 if the start or end are invalid
* non terminating for loop for (i = 0; ; ++i)
    * bool result = impl(start, end, i = 0)
        * impl checks if valid, then if its at the end
        * initializes static array for dx and dy
        * for i = 0 -> i = 7
            * 

