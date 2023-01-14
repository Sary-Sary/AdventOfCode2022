cycle_add::Int -> Int -> Int
cycle_add cycle amount = cycle + amount

nth_cycle::[(String, Int)] -> Int -> Int -> Int -> Int
nth_cycle [] _ _ x_value = x_value
nth_cycle (current_cycle:tail) n cycle x_value
    |n == cycle = x_value
    |fst current_cycle == "noop" = nth_cycle tail n (cycle_add cycle 1) x_value
    |fst current_cycle == "addx" && (cycle_add cycle 2) <= n = nth_cycle tail n (cycle_add cycle 2) (x_value + (snd current_cycle))
    |otherwise = x_value

sum_20_60_100_140_180_220::[(String, Int)] -> Int
sum_20_60_100_140_180_220 program = 20 * (nth_cycle program 20 1 1) + 60 * (nth_cycle program 60 1 1) + 100 * (nth_cycle program 100 1 1) +
                                    140 * (nth_cycle program 140 1 1) + 180 * (nth_cycle program 180 1 1) + 220 * (nth_cycle program 220 1 1)

draw_pixels::[(String, Int)] -> Int -> [Char]
draw_pixels program current_cycle
    |current_cycle > 240 = ""
    |cycle_mod_40 < cycle_amount + 3 && cycle_mod_40 >= cycle_amount && cycle_mod_40 `mod` 40 == 0 = "\n#" ++ draw_pixels program (current_cycle + 1)
    |cycle_mod_40 < cycle_amount + 3 && cycle_mod_40 >= cycle_amount = "#" ++ draw_pixels program (current_cycle + 1)
    |cycle_mod_40 `mod` 40 == 0 = "\n." ++ draw_pixels program (current_cycle + 1)
    |otherwise = "." ++ draw_pixels program (current_cycle + 1)
    where
        cycle_amount = nth_cycle program current_cycle 1 1
        cycle_mod_40 = current_cycle `mod` 40

read_input::[[Char]] -> [(String, Int)]
read_input [] = []
read_input (input_head:input_tail)
    |input_head == "noop" = [("noop", 0)] ++ read_input input_tail
    |otherwise = [("addx", read (drop 4 input_head) :: Int)] ++ read_input input_tail



main::IO()
main = do
    input <- readFile "input.txt"
    let input_lines = lines input 
    let program = read_input input_lines
    print (sum_20_60_100_140_180_220 program)
    putStr (draw_pixels program 0)
    --print(sum_20_60_100_140_180_220 [("noop", 0), ("addx",5)])
    