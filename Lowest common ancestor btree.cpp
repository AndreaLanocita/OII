// 1. We find the quickest route to get to a node from the src, save
// the "ancestors" and then confront the paths to the two nodes till we find a 
// a difference: the node before is the common ancestor.

// 2. Some weird type of recursion until we get to:
// - the end of the tree, thus we return null to the previous instances
// - one of the nodes we're interested in, we return that node's index
// The node whose instance receives all of the nodes we're interested in is the common
// ancestor, and it returns its index to the source node. If the source node receives all
// nulls but one index, that will be the lowest common ancestor

// Optimization, we can check if the index received by the source is not the nodes we're interested in.
// If it isn't, we can just print that.
