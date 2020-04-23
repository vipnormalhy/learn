#include <iostream>
#include <memory>
#include <vector>

typedef std::vector<std::vector<bool>> matrix_type;

int total_solution = 0;

bool is_valid(std::shared_ptr<matrix_type> matrix, int row, int col)
{
  int length = static_cast<int>(matrix->size());
  int queen_row = 0, queen_col = 0;
  int queen_x = 0, queen_y = 0;
  for (int index = 0; index < length; index++)
  {
    // vertical
    if (matrix->at(row)[index])
    {
      queen_row += 1;
      if (queen_row > 1)
        return false;
    }
    // horizone
    if (matrix->at(index)[col])
    {
      queen_col += 1;
      if (queen_col > 1)
        return false;
    }
    if (row - index >= 0 && col - index >= 0)
    {
      if (matrix->at(row - index)[col - index])
      {
        queen_x += 1;
      }
    }

    if (row + index < length && col + index < length)
    {
      if (matrix->at(row + index)[col + index])
      {
        queen_x += 1;
      }
    }

    if (queen_x > 2)
      return false;

    if (row - index >= 0 && col + index < length)
    {
      if (matrix->at(row - index)[col + index])
      {
        queen_y += 1;
      }
    }

    if (row + index < length && col - index >= 0)
    {
      if (matrix->at(row + index)[col - index])
      {
        queen_y += 1;
      }
    }

    if (queen_y > 2)
      return false;
  }
  return true;
}

void output_matrix(std::shared_ptr<matrix_type> queen_matrix, bool silent_output=false)
{
  total_solution += 1;
  if (silent_output)
  {
    std::cout << "find one" << std::endl;
    return;
  }

  for (auto &v : *queen_matrix)
  {
    for (const bool &i : v)
    {
      if (!i)
      {
        std::cout << "0 ";
      }
      else
      {
        std::cout << "1 ";
      }
    }
    std::cout << std::endl;
  }
  std::cout << std::ends
            << std::endl;
}

void backtrace(std::shared_ptr<matrix_type> matrix, int row)
{
  if (row >= matrix->size())
  {
    bool silent_output = false;
    if (matrix->size() > 8)
    {
      silent_output = true;
    }
    output_matrix(matrix, silent_output);
    return;
  }

  for (int col = 0; col < matrix->size(); col++)
  {
    matrix->at(row)[col] = true;
    if (is_valid(matrix, row, col))
    {
      backtrace(matrix, row + 1);
    }
    matrix->at(row)[col] = false;
  }
}

void backtrace(std::shared_ptr<matrix_type> matrix, int row, int col)
{
  matrix->at(row)[col] = true;

  if (is_valid(matrix, row, col))
  {
    // find a solution
    if (row == matrix->size() - 1)
    {
      output_matrix(matrix);
    }
    else
    {
      backtrace(matrix, row + 1, 0);
    }
  }

  matrix->at(row)[col] = false;

  // the last column, failed
  if (col >= matrix->size() - 1)
  {
    return;
  }
  else
  {
    backtrace(matrix, row, col + 1);
  }
}

void n_queen_entry(int n)
{
  std::shared_ptr<matrix_type> queen_matrix = std::make_shared<matrix_type>(n);
  for (auto &v : *queen_matrix)
  {
    v.resize(n);
  }

  std::cout << "start " << n << " queen" << std::endl;

  backtrace(queen_matrix, 0);
  std::cout << "Total solution is " << total_solution << std::endl;
}