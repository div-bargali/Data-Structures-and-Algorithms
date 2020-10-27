-- # Insertion Sort in Haskell
-- This is an implementation of simple Insertion Sort in Haskell on any type that can be ordered.
-- Insertion Sort is a slow, but simple sorting algorithm that has time complexity O(n^2)

-- Insert element into list in order, returning sorted list
insert :: (Ord a) => a -> [a] -> [a]
insert e []             = [e]
insert e (x:xs)
    | e < x             = e : x : xs
    | otherwise         = x : insert e xs

-- Insertion sort on list, returning the list sorted
insertionSort :: (Ord a) => [a] -> [a]
insertionSort []        = []
insertionSort (x:xs)    = insert x (insertionSort xs)

main :: IO ()
main = do
    let intList = [1, 30, 7, 10, 4, 25]
    print $ insertionSort intList -- Returning [1,4,7,10,25,30]