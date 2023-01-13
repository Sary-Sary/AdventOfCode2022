is_edge::Int -> Int -> Int -> Bool
is_edge 1 _ _ = True
is_edge _ 1 _ = True
is_edge row col length_tree 
    |row == length_tree = True
    |col == length_tree = True
    |otherwise = False

--     col
-- row    1 2 3
--        4 5 6
--        7 8 9

get_position::[[Int]] -> Int -> Int -> Int
--get_position tree 1 1 = head (head tree)
--get_position tree 1 col = head (drop (col - 1) (head tree))
--get_position tree row 1 = head (head (drop (row - 1) tree))
get_position tree row col = head ((drop (col - 1) (head (drop (row - 1) tree))))

is_visible_from_up::[[Int]] -> Int -> Int -> Int -> Bool
is_visible_from_up tree current_row current_col row_up 
    |is_edge row_up current_col (length (head tree)) && get_position tree current_row current_col > get_position tree row_up current_col = True
    |get_position tree current_row current_col > get_position tree row_up current_col = is_visible_from_up tree current_row current_col (row_up - 1) 
    |otherwise = False

is_visible_from_down::[[Int]] -> Int -> Int -> Int -> Bool
is_visible_from_down tree current_row current_col row_down 
    |is_edge row_down current_col (length (head tree)) && get_position tree current_row current_col > get_position tree row_down current_col = True
    |get_position tree current_row current_col > get_position tree row_down current_col = is_visible_from_down tree current_row current_col (row_down + 1) 
    |otherwise = False

is_visible_from_left::[[Int]] -> Int -> Int -> Int -> Bool
is_visible_from_left tree current_row current_col col_left 
    |is_edge current_row col_left (length (head tree)) && get_position tree current_row current_col > get_position tree current_row col_left = True
    |get_position tree current_row current_col > get_position tree current_row col_left = is_visible_from_left tree current_row current_col (col_left - 1) 
    |otherwise = False

is_visible_from_right::[[Int]] -> Int -> Int -> Int -> Bool
is_visible_from_right tree current_row current_col col_right 
    |is_edge current_row col_right (length (head tree)) &&  get_position tree current_row current_col > get_position tree current_row col_right = True
    |get_position tree current_row current_col > get_position tree current_row col_right = is_visible_from_right tree current_row current_col (col_right + 1) 
    |otherwise = False

is_visible::[[Int]] -> Int -> Int -> Bool
is_visible tree row col
    |is_edge row col (length (head tree)) = True
    |is_visible_from_up tree row col (row - 1) == True = True
    |is_visible_from_down tree row col (row + 1) == True = True
    |is_visible_from_left tree row col (col - 1) == True = True
    |is_visible_from_right tree row col (col + 1) == True = True
    |otherwise = False

scenic_score_up::[[Int]] -> Int -> Int -> Int -> Int
scenic_score_up tree current_row current_col row_up 
    |is_edge current_row current_col (length (head tree)) == True = 1
    |is_edge row_up current_col (length (head tree)) && get_position tree current_row current_col > get_position tree row_up current_col = 1
    |get_position tree current_row current_col > get_position tree row_up current_col = 1 + scenic_score_up tree current_row current_col (row_up - 1) 
    |otherwise = 1

scenic_score_down::[[Int]] -> Int -> Int -> Int -> Int
scenic_score_down tree current_row current_col row_down 
    |is_edge current_row current_col (length (head tree)) == True = 1
    |is_edge row_down current_col (length (head tree)) && get_position tree current_row current_col > get_position tree row_down current_col = 1
    |get_position tree current_row current_col > get_position tree row_down current_col = 1 + scenic_score_down tree current_row current_col (row_down + 1) 
    |otherwise = 1

scenic_score_left::[[Int]] -> Int -> Int -> Int -> Int
scenic_score_left tree current_row current_col col_left 
    |is_edge current_row current_col (length (head tree)) == True = 1
    |is_edge current_row col_left (length (head tree)) && get_position tree current_row current_col > get_position tree current_row col_left = 1
    |get_position tree current_row current_col > get_position tree current_row col_left = 1 + scenic_score_left tree current_row current_col (col_left - 1) 
    |otherwise = 1

scenic_score_right::[[Int]] -> Int -> Int -> Int -> Int
scenic_score_right tree current_row current_col col_right 
    |is_edge current_row current_col (length (head tree)) == True = 1
    |is_edge current_row col_right (length (head tree)) &&  get_position tree current_row current_col > get_position tree current_row col_right = 1
    |get_position tree current_row current_col > get_position tree current_row col_right = 1 + scenic_score_right tree current_row current_col (col_right + 1) 
    |otherwise = 1

count_visible::[[Int]] -> Int -> Int -> Int 
count_visible tree row col
    |row == (length (head tree)) && col == (length (head tree)) = 1
    |col == length (head tree) = 1 + count_visible tree (row + 1) col
    |row == length (head tree) = 1 + count_visible tree 1 (col + 1)
    |is_visible tree row col == True = 1 + count_visible tree (row + 1) col
    |otherwise = count_visible tree (row + 1) col

max_scenic::Int -> Int -> Int
max_scenic a b 
    |a > b = a
    |otherwise = b

scenic_score::[[Int]] -> Int -> Int -> Int
scenic_score trees row col = scenic_right * scenic_left * scenic_up * scenic_down
    where
        scenic_up = scenic_score_up trees row col (row - 1)
        scenic_down = scenic_score_down trees row col (row + 1)
        scenic_left = scenic_score_left trees row col (col - 1)
        scenic_right = scenic_score_right trees row col (col + 1)

find_max_scenic_score::[[Int]] -> Int -> Int -> Int -> Int
find_max_scenic_score tree row col current_max
    |row == (length (head tree)) && col == (length (head tree)) = max_scenic current_max (scenic_score tree row col)
    |row == length (head tree) = find_max_scenic_score tree 1 (col + 1) (max_scenic current_max (scenic_score tree row col))
    |otherwise = find_max_scenic_score tree (row + 1)  col (max_scenic current_max (scenic_score tree row col))

input_to_trees::[[Char]] -> [[Int]]
input_to_trees [] = []
input_to_trees input = (map (read . (:"")) (head input) :: [Int]) : (input_to_trees (tail input))

main::IO()
main = do
    input <- readFile "input.txt"
    let split_input = lines input
    let trees = input_to_trees split_input
    --print (trees)
    --print(get_position [[1,2,3],[4,5,6]] 1 2)
    --print(is_visible_from_right [[1,2,3],[1,5,3],[4,5,6]] 2 1 2)
    --print (is_visible [[1,6,3],[6,1,3],[4,5,6]] 2 2)
    --print (get_position [[3,0,3,7,3],[2,5,5,1,2],[6,5,3,3,2],[3,3,5,4,9],[3,5,3,9,0]] 4 3)
    --print (scenic_score [[3,0,3,7,3],[2,5,5,1,2],[6,5,3,3,2],[3,3,5,4,9],[3,5,3,9,0]] 4 3)
    --print (scenic_score_down [[3,0,3,7,3],[2,5,5,1,2],[6,5,3,3,2],[3,3,5,4,9],[3,5,3,9,0]] 4 3 5)
    --print (scenic_score_up [[3,0,3,7,3],[2,5,5,1,2],[6,5,3,3,2],[3,3,5,4,9],[3,5,3,9,0]] 4 3 3)
    --print (scenic_score_left [[3,0,3,7,3],[2,5,5,1,2],[6,5,3,3,2],[3,3,5,4,9],[3,5,3,9,0]] 4 3 2)
    --print (scenic_score_right [[3,0,3,7,3],[2,5,5,1,2],[6,5,3,3,2],[3,3,5,4,9],[3,5,3,9,0]] 4 3 4)
    --print (find_max_scenic_score [[3,0,3,7,3],[2,5,5,1,2],[6,5,3,3,2],[3,3,5,4,9],[3,5,3,9,0]] 1 1 0)
    print(find_max_scenic_score trees 1 1 0)
    --print(drop 1 (drop 1 [[1,2,3],[4,5,6]]))