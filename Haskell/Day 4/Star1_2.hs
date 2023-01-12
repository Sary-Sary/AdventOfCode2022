{-# ANN module "HLint: ignore Use camelCase" #-}

overlap::(Int, Int, Int, Int) -> Bool
overlap (start1, end1, start2, end2)
    |start1 <= end2 && start2 <= end1 = True
    |start2 <= end1 && start1 <= end2 = True
    |otherwise = False

fully_contains_range::(Int, Int, Int, Int) -> Bool
fully_contains_range (start1, end1, start2, end2)
    |start1 <= start2 && end1 >= end2 = True
    |start1 >= start2 && end1 <= end2 = True
    |otherwise = False

--CODE TAKEN FROM: https://stackoverflow.com/questions/4978578/how-to-split-a-string-in-haskell
wordsWhen     :: (Char -> Bool) -> String -> [String]
wordsWhen p s =  case dropWhile p s of
                      "" -> []
                      s' -> w : wordsWhen p s''
                            where (w, s'') = break p s'
--CODE END                        

--30-31,2-31
to_range::[Char] -> (Int, Int, Int, Int)
to_range ranges = (start1, end1, start2, end2)
    where
        separate_ranges = wordsWhen (==',') ranges
        separate_to_numbers = wordsWhen (=='-') (head separate_ranges) ++ wordsWhen (=='-') (head (tail separate_ranges))
        start1 = read $ head separate_to_numbers :: Int
        end1 = read $ head $ tail separate_to_numbers :: Int
        start2 = read $ head $ tail $ tail separate_to_numbers :: Int
        end2 = read $ head $ tail $ tail $ tail separate_to_numbers :: Int

amount_of_contained_ranges::[[Char]] -> Int
amount_of_contained_ranges [] = 0
amount_of_contained_ranges (head_range:ranges)
    |fully_contains_range head_range_ranges = 1 + amount_of_contained_ranges ranges
    |otherwise = amount_of_contained_ranges ranges
    where
        head_range_ranges = to_range head_range

amount_of_overlaps::[[Char]] -> Int
amount_of_overlaps [] = 0
amount_of_overlaps (head_range:ranges)
    |overlap head_range_ranges = 1 + amount_of_overlaps ranges
    |otherwise = amount_of_overlaps ranges
    where
        head_range_ranges = to_range head_range

main::IO()
main = do
    --let test <- "30-31,2-31"
    input <- readFile "input.txt"
    let ranges = lines input
    print(amount_of_overlaps ranges)