-- # Binary Search in Haskell
-- This is an implementation of simple Binary Search in Haskell on any type that can be ordered.
-- Binary Search is an effective searching algorithm, that can be used to find an element in a sorted list in O(lg(n)) time.

-- Binary search with index carry
bsWithIndex :: (Ord a) => [a] -> a -> Int -> Maybe Int
bsWithIndex list n i
    | n == head list        = Just i
    | len == 1              = Nothing   -- only candidate in list is not the right elem
    | n < head ys           = bsWithIndex xs n i
    | otherwise             = bsWithIndex ys n (i + half)
    where 
        len         = length list
        half        = len `div` 2 
        (xs, ys)    = splitAt half list

-- Binary search returning index, or -1 if element not in list
bs :: (Ord a) => [a] -> a -> Int
bs list n = case bsWithIndex list n 0 of
    Just x  -> x
    Nothing -> -1

main :: IO ()
main = do
    let intList = [1,4,7,10,25,30]
    print $ bs intList 29  -- 29 -> -1 as not in list
    print $ bs intList 7   --  7 ->  2 as in list
