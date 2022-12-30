rock_player::String
rock_player = "X"
paper_player::String
paper_player = "Y"
scissors_player::String
scissors_player = "Z"

rock::String
rock = "A"
paper::String
paper = "B"
scissors::String
scissors = "C"

draw::String
draw = "Y"
lose::String
lose = "X"
win::String
win = "Z"

return_shape_score::String -> Int
return_shape_score shape
    |shape == rock_player = 1
    |shape == paper_player = 2
    |shape == scissors_player = 3
    |otherwise = 0

player_action_to_opponent_action::String -> String
player_action_to_opponent_action player_action
    |player_action == rock_player = rock
    |player_action == paper_player = paper
    |player_action == scissors_player = scissors

is_draw::String -> String -> Bool
is_draw opponent player
    |opponent == (player_action_to_opponent_action player) = True
    |otherwise = False

is_win::String -> String -> Bool
is_win opponent player
    |opponent == rock && player == paper_player = True
    |opponent == paper && player == scissors_player = True
    |opponent == scissors && player == rock_player = True
    |otherwise = False

return_round_score::String -> String -> Int
return_round_score opponent player
    |is_draw opponent player == True = 3
    |is_win opponent player == True = 6
    |otherwise = 0

return_score::[[String]] -> Int
return_score [] = 0
return_score (current_round:rounds) = 
    return_shape_score (head (tail current_round)) + return_round_score (head current_round) (head (tail current_round)) 
    + return_score rounds

rock_strategy::String -> Int
rock_strategy how_to_end
    |how_to_end == draw = 1 --play rock
    |how_to_end == win = 2 --play paper
    |how_to_end == lose = 3
    |otherwise = 0

paper_strategy::String -> Int
paper_strategy how_to_end
    |how_to_end == lose = 1 --play rock
    |how_to_end == draw = 2 --play paper
    |how_to_end == win = 3 --play scissors

scissors_strategy::String -> Int
scissors_strategy how_to_end 
    |how_to_end == win = 1 --play rock
    |how_to_end == lose = 2 --play paper
    |how_to_end == draw = 3 --play scissors

return_shape_score2::String -> String -> Int
return_shape_score2 opponent_action how_to_end
    |opponent_action == rock = rock_strategy how_to_end
    |opponent_action == paper = paper_strategy how_to_end
    |opponent_action == scissors = scissors_strategy how_to_end
    |otherwise = 0

return_round_score2::String -> Int
return_round_score2 how_to_end
    |how_to_end == draw = 3
    |how_to_end == win = 6
    |otherwise = 0

return_score2::[[String]] -> Int
return_score2 [] = 0
return_score2 (current_round:rounds) = 
    return_shape_score2 (head current_round) (head (tail current_round)) + return_round_score2 (head (tail current_round))
    + return_score2 rounds

main::IO()
main = do
    input <- readFile "input.txt"
    let rounds = map words (lines input)
    print (return_score rounds)
    print (return_score2 rounds)