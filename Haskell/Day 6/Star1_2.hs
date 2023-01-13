import Data.List

valid_stream::[Char] -> Bool
valid_stream [] = True
valid_stream stream
    |tail stream == [] = True
    |head stream == head (tail stream) = False
    |otherwise = valid_stream (tail stream)

n_marker::Int -> [Char] -> Int -> Int
n_marker _ [] _ = 0
n_marker n buffer marker
    |valid_stream (sort (take n buffer)) = marker + n - 1
    |otherwise = n_marker n (tail buffer) (marker + 1)

main::IO()
main = do
    input <- readFile "input.txt"
    print(n_marker 4 input 1)
    print(n_marker 14 input 1)