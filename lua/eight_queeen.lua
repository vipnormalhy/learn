-- Eight Queen
-- Eight rows and eight columes


MAX_BOARD = 8
QUEEN_CNT = 8


check_single_rule = function(position, cheet)
	-- row
	row = (position - 1) / MAX_BOARD
	queen = 1
	for i = row * MAX_BOARD + 1, (row + 1) * MAX_BOARD do
		if cheet[i] == 1 then
			queen = queen + 1
		end
	end
	if queen > 1 then
		print("check row false")
		return false
	end

	-- colume
	col = (position - 1) % MAX_BOARD + 1
	queen = 1
	for i = 0, MAX_BOARD - 1 do
		if cheet[i * MAX_BOARD + col] == 1 then
			queen = queen + 1
		end
	end
	if queen > 1 then
		print("check col false")
		return false
	end

	queen = 1
	pos = position
	while true do
		pos = pos - (MAX_BOARD - 1)
		if pos < 1 then
			break
		end
		if cheet[pos] == 1 then
			queen = queen + 1
		end
	end
	pos = position
	while true do
		pos = pos + (MAX_BOARD - 1)
		if pos > MAX_BOARD * MAX_BOARD then
			break
		end
		if cheet[pos] == 1 then
			queen = queen + 1
		end
	end
	if queen > 1 then
		print("check ... false")
		return false
	end
	return true
end


check_rule = function(cheet)
	for i = 0, MAX_BOARD - 1 do
		for j = 0, MAX_BOARD - 1 do
		end
	end
end


find_one_solution = function(first_position)
	cheet = {}
	queen_num = QUEEN_CNT - 1
	cheet[first_position] = 1
end


find_all_solutions = function()
	first_position = 0
	max_position = MAX_BOARD * MAX_BOARD
	while first_position < max_position do
		find_one_solution(first_position)
	end
end


main = function()
	print("Start to find all eight queen solution")

	-- find_all_solutions()
	--[[ test
	data = {
		1, 0, 0, 0, 0, 0, 0, 0, 
		0, 0, 0, 0, 1, 0, 0, 0, 
		0, 0, 0, 0, 0, 0, 0, 1,
		0, 0, 0, 0, 0, 1, 0, 0,
		0, 0, 1, 0, 0, 0, 0, 0,
		0, 0, 0, 0, 0, 0, 1, 0,
		0, 1, 0, 0, 0, 0, 0, 0,
		0, 0, 0, 1, 0, 0, 0, 0,
	}
	--]]
	--[[
	data = {
		0, 0, 0, 0, 0, 0, 0, 1, 
		0, 0, 0, 0, 0, 0, 0, 0, 
		0, 0, 0, 0, 0, 0, 0, 0,
		0, 0, 0, 0, 0, 0, 0, 0,
		0, 0, 0, 0, 0, 0, 0, 0,
		0, 0, 0, 0, 0, 0, 0, 0,
		0, 0, 0, 0, 0, 0, 0, 0,
		0, 0, 0, 0, 0, 0, 0, 0,
	}
	print(check_single_rule(1, data))
	--]]
end

main()
