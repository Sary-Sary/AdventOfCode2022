{-# HLINT ignore "Use camelCase" #-}

return_larger::Int -> Int -> Int
return_larger a b
    |a > b = a
    |otherwise = b

elf_with_the_most_calories::Int -> Int -> [String] -> Int
elf_with_the_most_calories max _ [] = max
elf_with_the_most_calories current_max current_amount (calories_head:calories)
    |calories_head == "" = elf_with_the_most_calories (return_larger current_max current_amount) 0 calories
    |otherwise = elf_with_the_most_calories current_max (current_amount + read calories_head) calories

return_n_largest_numbers::Int -> Int -> [Int] -> [Int]
return_n_largest_numbers n number [] = [number]
return_n_largest_numbers 0 _ _ = []
return_n_largest_numbers n number (head:tail)
    |number >= head = [number] ++ [head] ++ take (n - 2) tail
    |otherwise = head : return_n_largest_numbers (n - 1) number tail

n_elves_with_the_most_calories::Int -> [Int] -> Int -> [String] -> [Int]
n_elves_with_the_most_calories _ max_calories _ [] = max_calories
n_elves_with_the_most_calories n current_max_calories current_amount (calories_head:tail)
    |calories_head == "" = 
        n_elves_with_the_most_calories n (return_n_largest_numbers n current_amount current_max_calories) 0 tail
    |otherwise = n_elves_with_the_most_calories n current_max_calories (current_amount + read calories_head) tail

main::IO()
main = do
    input <- readFile "input.txt" 
    let all_calories = lines input
    print (elf_with_the_most_calories 0 0 all_calories)
    print (sum (n_elves_with_the_most_calories 3 [] 0 all_calories))