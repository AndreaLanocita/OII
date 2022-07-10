// Basicallly dp where we also eliminate part of the solution that we do not need
// We find a valid solution and save it as the best solution so far (we wanna find the optimal)
// We also save how we got to the solution
// For each first branch of the tree we calculate the minimum possible solution and 
// eliminate the whole branch if it is bigger than the best solution so far
// We also save each of the Lower Bounds we have just calculated in a pq and start
// working on the lowest one (top of the inverse pq)
// We check each branch of that part of the tree, calculate the lowest bound and 
// eliminate it if it is bigger than the best so far
// We repeat the problem till we find more solutions, and eventually replace the 
// best solution so far