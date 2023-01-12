import Data.List

{-# ANN module "HLint: ignore Use camelCase" #-}

zipped_lower::[(Char, Int)]
zipped_lower = zip ['a'..'z'] [1,2..26]

zipped_upper::[(Char, Int)]
zipped_upper = zip ['A'..'Z'] [27,28..52]

zipped_all_letters::[(Char, Int)]
zipped_all_letters = zipped_lower ++ zipped_upper

get_value::[(Char, Int)] -> Char -> Int
get_value [] _ = 0
get_value (potential:tail) seeked_char
    |fst potential == seeked_char = snd potential
    |otherwise = get_value tail seeked_char

intersection_three_lists::[Char] -> [Char] -> [Char] -> Char
intersection_three_lists l1 l2 l3 = head [x | x <- l1, x `elem` l2, x `elem` l3]

priority_for_three_rucksacks::[Char] -> [Char] -> [Char] -> Int
priority_for_three_rucksacks r1 r2 r3 = get_value zipped_all_letters (intersection_three_lists r1 r2 r3)

add_groups::[[Char]] -> Int
add_groups [] = 0
add_groups (head1:(head2:(head3:tail))) = priority_for_three_rucksacks head1 head2 head3 + add_groups tail

--print_head3::[Char] -> Char
--print_head3 (head1:(head2:(head3:tail))) = head3

main::IO()
main = do
    input <- readFile "input.txt"
    let rucksacks = lines input
    print (add_groups rucksacks)