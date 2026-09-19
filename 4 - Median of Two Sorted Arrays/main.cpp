#include <algorithm>
#include <chrono>
#include <iostream>
#include <limits>
#include <random>
#include <vector>
#include <string>

std::random_device rd;
std::mt19937 gen(rd());

std::ostream& operator<<(std::ostream& os, const std::vector<int>& vec)
{
  os << "{";
  for (std::size_t i {0}; i < vec.size(); ++i)
    os << vec[i] << ((i < vec.size()-1)? ",":"");
  os << "}";
  return os;
}

void generateRandomNumbers(std::vector<int>& vec, int min_n_numbers, int max_n_numbers, int min_range, int max_range)
{
  if (min_n_numbers < 0 ||
      min_n_numbers > max_n_numbers ||
      min_range < 0 ||
      min_range > max_range)
    return;
  std::uniform_int_distribution<int> n_numbers_distrib(min_n_numbers, max_n_numbers);
  std::uniform_int_distribution<int> range_distrib(min_range, max_range);
  int i {n_numbers_distrib(gen)};
  while (i > 0)
  {
    vec.push_back(range_distrib(gen));
    --i;
  }
  return;
}

double findMedianSortedArraysUsingMerge(std::vector<int>& nums1, std::vector<int>& nums2)
{
  std::vector<int> merged;

  int left_index {0};
  int right_index {0};

  while (left_index < nums1.size() && right_index < nums2.size())
  {
      if (nums1[left_index] < nums2[right_index])
      {
          merged.push_back(nums1[left_index]);
          ++left_index;
      }
      else
      {
          merged.push_back(nums2[right_index]);
          ++right_index;
      }
  }

  while (left_index < nums1.size())
  {
      merged.push_back(nums1[left_index]);
      ++left_index;
  }

  while (right_index < nums2.size())
  {
      merged.push_back(nums2[right_index]);
      ++right_index;
  }

  int length = merged.size();
  double median;

  if (length % 2 == 0)
  {
      double n1 = static_cast<double>(length) /2;
      double n2 = static_cast<double>(length) /2+1;
      median = (n2 + n1) / 2;
      return median;
  }
  else
  {
      median = static_cast<double>(length) / 2;
      return merged[median];
  }

  return median;
}

double findMedianSortedArrays(std::vector<int>& nums1, std::vector<int>& nums2)
{
  auto& a = nums1;
  auto& b = nums2;
  int total = a.size() + b.size(); 
  int half = total / 2;
  if (b.size() < a.size())
    a.swap(b);
  int a_size = nums1.size();
  int b_size = nums2.size();
  int l = -1, r = a.size() - 1;
  while (true)
  {
    int i = l + (r - l) / 2; // A
    int j = half - i - 2; // B

    double a_left = (i >= 0)? a[i]: -std::numeric_limits<double>::infinity();
    double a_right = (i + 1 < a_size)? a[i + 1]: std::numeric_limits<double>::infinity();
    double b_left = (j >= 0)? b[j]: -std::numeric_limits<double>::infinity();
    double b_right = (j + 1 < b_size)? b[j + 1]: std::numeric_limits<double>::infinity();

    if (a_left <= b_right && b_left <= a_right)
    {
      if (total % 2)
        return std::min(a_right, b_right);
      return (std::max(a_left, b_left) + std::min(a_right, b_right)) / 2;
    }
    else if (a_left > b_right)
      r = i-1;
    else
      l = i+1;
  }
}

// Main Entry Point of the Program
int main(int argc, const char* argv[])
{
  if (argc != 5)
  {
    std::cout << "Usage: " << argv[0] << " <min_n_numbers> <max_n_numbers> <min_range> <max_range>" << std::endl;
    return 1;
  }

  int min_n_numbers {std::stoi(argv[1])};
  int max_n_numbers {std::stoi(argv[2])};
  int min_range {std::stoi(argv[3])};
  int max_range {std::stoi(argv[4])};

  std::vector<int> nums1;
  generateRandomNumbers(nums1, min_n_numbers, max_n_numbers, min_range, max_range);

  std::vector<int> nums2;
  generateRandomNumbers(nums2, min_n_numbers, max_n_numbers, min_range, max_range);

  std::sort(nums1.begin(), nums1.end());
  std::sort(nums2.begin(), nums2.end());

  std::vector<int> merged (nums1.size() + nums2.size());

  std::merge(nums1.begin(), nums1.end(), nums2.begin() , nums2.end(), merged.begin());

  std::cout << "std::vector<int> nums1: " << nums1 << "\n"
            << "std::vector<int> nums2: " << nums2 << "\n"
            << "std::vector<int> merged: " << merged << std::endl;

  auto start = std::chrono::high_resolution_clock::now();
  std::cout << "findMedianSortedArrays(nums1, nums2) <- O(log(m+n)) [Fastest]" << std::endl;
  double result {findMedianSortedArrays(nums1, nums2)};
  auto end = std::chrono::high_resolution_clock::now();
  std::chrono::duration<double, std::milli> elapsed_ms = end - start;
  std::cout << "Elapsed Time: " << elapsed_ms.count() << " ms\n"
            << "Median: " << result << std::endl;

  start = std::chrono::high_resolution_clock::now();
  std::cout << "findMedianSortedArraysUsingMerge(nums1, nums2) <- O(m+n)" << std::endl;
  double result_old {findMedianSortedArraysUsingMerge(nums1, nums2)};
  end = std::chrono::high_resolution_clock::now();
  elapsed_ms = end - start;
  std::cout << "Elapsed Time: " << elapsed_ms.count() << " ms\n"
            << "Median: " << result << std::endl;

  return 0;
}
