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

find_common_from_two_compartments ::([Char],[Char]) -> Char
find_common_from_two_compartments (head1:half1,head2:half2)
    |head1 == head2 = head1
    |head1 < head2 = find_common_from_two_compartments (half1,head2:half2)
    |otherwise = find_common_from_two_compartments (head1:half1,half2)

divide_rucksack_into_compartments::[Char] -> ([Char], [Char])
divide_rucksack_into_compartments rucksack = (compartment1, compartment2)
    where  
        compartment_length = length rucksack `div` 2
        compartment1 = take compartment_length rucksack
        compartment2 = drop compartment_length rucksack

sort_compartments::([Char], [Char]) -> ([Char], [Char])
sort_compartments (comp1, comp2) = (sort comp1, sort comp2)
        
priority_for_rucksack::[Char] -> Int
priority_for_rucksack rucksack = 
    get_value zipped_all_letters (find_common_from_two_compartments (sort_compartments (divide_rucksack_into_compartments rucksack)))

sum_priorities_all_rucksacks::[[Char]] -> Int
sum_priorities_all_rucksacks [] = 0
sum_priorities_all_rucksacks (rucksack:other_rucksacks) = priority_for_rucksack rucksack + sum_priorities_all_rucksacks other_rucksacks

main::IO()
main = do
    input <- readFile "input.txt"
    let rucksacks = lines input
    print (sum_priorities_all_rucksacks rucksacks)
    --print (priority_for_rucksack "vJrwpWtwJgWrhcsFMMfFFhFp")