#include<iostream>

// prints a 2d array with dimensions rows, cols
int print_board(int **board, int rows, int cols)
{
	for(int i = 0; i < rows; i++)
	{
		for(int j = 0; j < cols; j++)
			std::cout << *(*(board + i) + j) << ", ";
		std::cout << std::endl;
	}
	return 0;
}

// initalizes an integer 2d array with dimensions rows, cols with 0's
int initialize_board(int **board, int rows, int cols)
{
	for(int i = 0; i < rows; i++)
		for(int j = 0; j < cols; j++)
			*(*(board + i) + j) = 0;
	return 0;
}

// populates a odd sized square 2d array of dimension N with a magic square
int populate_magic_square(int **board, int N)
{
	int current_row = 0;
	int current_col = N / 2;
	int counter = 2;
	*(*(board + current_row) + current_col) = 1;
	int next_val, next_row, next_col;
	while(counter <= N * N)
	{
		next_row = current_row + N - 1;
		next_row = next_row % N;
		next_col = current_col + 1;
		next_col = next_col % N;
		next_val = *(*(board + next_row) + next_col);
		if(next_val == 0)
		{
			current_row = next_row;
			current_col = next_col;
			*(*(board + current_row) + current_col) = counter;
		}
		else
		{
			current_row += 1;
			current_row = current_row % N;
			*(*(board + current_row) + current_col) = counter;
		}
		counter ++;
	}
	return 0;
}

	
// recieves the requested odd dimension from the user and prints a magic
// square of that size
int main()
{
	int N = 3;
	std::cout << "enter magic square dimension (odd number)" 
		<< std::endl;
	std::cin >> N;
	int** board = new int*[N];
	for(int i = 0; i < N; i++)
	{
		board[i] = new int[N];
	}
	initialize_board(board, N, N);
	populate_magic_square(board, N);
	print_board(board, N, N);

	// free array
	for(int i = 0; i < N; i++)
	{
	       delete [] board[i];
	}
	delete [] board;
	return 0;	
}

